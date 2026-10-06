// Give every function without a demangled prototype a usable one, so the decompiler passes
// `this` and stack arguments at call sites of the repo's placeholder-named callees:
//   - plain "Class::method" labels (names.csv / unmangled csv rows) move into a class namespace;
//   - /Od member functions spill ECX in the prologue (mov [ebp-x], ecx before any write to ECX):
//     calling convention __thiscall;
//   - stack parameter count = callee purge / 4 (stdcall/thiscall), else the highest [ebp+8+4k]
//     the body reads (cdecl); parameters are created as undefined4.
// Functions whose signature came from the Microsoft demangler (SourceType.IMPORTED) are left alone.
// usage (headless postScript, project not read-only): G1FixConventions.java
//@category Cogmind
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.listing.Function.FunctionUpdateType;
import ghidra.program.model.symbol.*;
import ghidra.program.model.lang.Register;
import ghidra.program.model.scalar.Scalar;
import java.util.*;

public class G1FixConventions extends GhidraScript {
	@Override
	protected void run() throws Exception {
		SymbolTable st = currentProgram.getSymbolTable();
		Listing listing = currentProgram.getListing();
		int moved = 0, thiscalls = 0, sigs = 0;
		// 1. "A::B::name" labels -> namespaces (classes)
		for (Symbol s : st.getAllSymbols(false)) {
			String n = s.getName();
			if (s.getSource() != SourceType.IMPORTED || !n.contains("::") || n.startsWith("?")) continue;
			int k = n.lastIndexOf("::");
			String ns = n.substring(0, k), base = n.substring(k + 2);
			if (ns.isEmpty() || base.isEmpty() || ns.contains("<") || ns.contains(" ")) continue;
			try {
				Namespace parent = currentProgram.getGlobalNamespace();
				for (String part : ns.split("::")) {
					Namespace c = st.getNamespace(part, parent);
					if (c == null) c = st.createClass(parent, part, SourceType.IMPORTED);
					parent = c;
				}
				s.setNameAndNamespace(base, parent, SourceType.IMPORTED);
				moved++;
			}
			catch (Exception e) {
				// keep the flat label
			}
		}
		// 2. conventions and parameter counts
		DataType u4 = Undefined4DataType.dataType;
		for (Function f : listing.getFunctions(true)) {
			if (monitor.isCancelled()) break;
			if (f.isThunk() || f.isExternal()) continue;
			if (f.getSignatureSource() == SourceType.IMPORTED && f.getParameterCount() > 0) continue;
			if (f.getSignatureSource() == SourceType.USER_DEFINED) continue;
			boolean usesThis = false;
			int maxArg = -1;
			int count = 0;
			boolean ecxWritten = false;
			for (Instruction ins : listing.getInstructions(f.getBody(), true)) {
				String m = ins.getMnemonicString();
				if (count < 30) {
					// prologue: MOV dword ptr [EBP + -x], ECX
					if (m.equals("MOV") && ins.getNumOperands() == 2) {
						Object[] o1 = ins.getOpObjects(1);
						Object[] o0 = ins.getOpObjects(0);
						if (o1.length == 1 && o1[0] instanceof Register && ((Register) o1[0]).getName().equals("ECX") && !ecxWritten
							&& o0.length >= 1 && o0[0] instanceof Register && ((Register) o0[0]).getName().equals("EBP"))
							usesThis = true;
						if (o0.length == 1 && o0[0] instanceof Register && ((Register) o0[0]).getName().equals("ECX"))
							ecxWritten = true;
					}
				}
				count++;
				for (int i = 0; i < ins.getNumOperands(); i++) {
					Object[] objs = ins.getOpObjects(i);
					if (objs.length == 2 && objs[0] instanceof Register && ((Register) objs[0]).getName().equals("EBP")
						&& objs[1] instanceof Scalar) {
						long d = ((Scalar) objs[1]).getSignedValue();
						if (d >= 8 && d < 8 + 4 * 32) maxArg = Math.max(maxArg, (int) ((d - 8) / 4));
					}
				}
			}
			int purge = f.getStackPurgeSize();
			int nargs = purge > 0 && purge != Function.UNKNOWN_STACK_DEPTH_CHANGE && purge != Function.INVALID_STACK_DEPTH_CHANGE
				? purge / 4 : maxArg + 1;
			try {
				if (usesThis) {
					f.setCallingConvention("__thiscall");
					thiscalls++;
				}
				else if (purge > 0) f.setCallingConvention("__stdcall");
				else f.setCallingConvention("__cdecl");
				List<Variable> params = new ArrayList<>();
				for (int i = 0; i < nargs; i++)
					params.add(new ParameterImpl("a" + (i + 1), u4, currentProgram));
				f.replaceParameters(params, FunctionUpdateType.DYNAMIC_STORAGE_FORMAL_PARAMS, true, SourceType.ANALYSIS);
				sigs++;
			}
			catch (Exception e) {
				println("skip " + f.getEntryPoint() + ": " + e.getMessage());
			}
		}
		println("G1FixConventions: " + moved + " labels namespaced, " + thiscalls + " thiscall, " + sigs + " signatures");
	}
}
