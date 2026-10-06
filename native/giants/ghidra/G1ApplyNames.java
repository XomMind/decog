// Apply the repo's known names (mangled where available) to COGMIND.exe before auto-analysis,
// so Ghidra's Microsoft demangler can apply prototypes (thiscall, parameter types).
// usage (headless preScript): G1ApplyNames.java <names.tsv>   lines: <hex va>\t<name>
//@category Cogmind
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.*;
import java.io.*;

public class G1ApplyNames extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String path = getScriptArgs()[0];
		SymbolTable st = currentProgram.getSymbolTable();
		int n = 0, bad = 0;
		try (BufferedReader r = new BufferedReader(new FileReader(path))) {
			String line;
			while ((line = r.readLine()) != null) {
				String[] p = line.split("\t", 2);
				if (p.length < 2) continue;
				Address a = toAddr(Long.parseLong(p[0], 16));
				String name = p[1].replace(' ', '_');
				try {
					Symbol s = st.createLabel(a, name, SourceType.IMPORTED);
					s.setPrimary();
					n++;
				}
				catch (Exception e) {
					bad++;
				}
			}
		}
		println("G1ApplyNames: " + n + " labels, " + bad + " rejected");
	}
}
