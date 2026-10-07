// Decompile functions of COGMIND.exe to C text files (raised limits for the giant /Od functions).
// usage (headless postScript): G1Decompile.java <outdir> <hex va> [<hex va> ...]
//@category Cogmind
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.*;

public class G1Decompile extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		File outdir = new File(args[0]);
		outdir.mkdirs();
		DecompileOptions opts = new DecompileOptions();
		opts.setMaxInstructions(400000);
		opts.setMaxPayloadMBytes(2000);
		opts.setMaxJumpTableEntries(4096);
		DecompInterface di = new DecompInterface();
		di.setOptions(opts);
		di.toggleCCode(true);
		di.toggleSyntaxTree(false);
		di.setSimplificationStyle("decompile");
		if (!di.openProgram(currentProgram)) throw new Exception("decompiler: " + di.getLastMessage());
		for (int i = 1; i < args.length; i++) {
			Address a = toAddr(Long.parseLong(args[i].replace("0x", ""), 16));
			Function f = getFunctionAt(a);
			if (f == null) f = createFunction(a, null);
			if (f == null) { println("no function at " + a); continue; }
			long t0 = System.currentTimeMillis();
			String tenv = System.getenv("G1_TIMEOUT");   // seconds; the largest giants need more than the 7200 default
			DecompileResults res = di.decompileFunction(f, tenv != null ? Integer.parseInt(tenv) : 7200, monitor);
			File out = new File(outdir, args[i].replace("0x", "") + ".c");
			try (PrintWriter w = new PrintWriter(new FileWriter(out))) {
				if (res.decompileCompleted()) w.print(res.getDecompiledFunction().getC());
				else w.println("// decompile failed: " + res.getErrorMessage());
			}
			println("G1Decompile " + args[i] + " " + (res.decompileCompleted() ? "ok" : "FAILED " + res.getErrorMessage())
				+ " " + (System.currentTimeMillis() - t0) + " ms");
		}
		di.dispose();
	}
}
