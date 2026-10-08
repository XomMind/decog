// team_c_65: CGameover::render (0x512ff0): writes the message or combat log to a .txt or color-coded .htm file
// NOTE: the name comes from the function's own error message; layouts are partial placeholders
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string intToString(int value);
void logError(string location, string message);
void OpC_replaceAll_407f00(string &text, string from, string to);	// NOTE: placeholder name

struct XColor { unsigned char r; unsigned char g; unsigned char b; XColor(const XColor &color); };
struct C65_Glyph { char pad0[0x64]; XColor f64; };	// NOTE: placeholder layout
struct C65_Font { char pad0[0xcc]; vector<C65_Glyph *> fcc; };	// NOTE: placeholder layout
struct C65_FontSet { char pad0[0xcc]; vector<C65_Font *> fcc; };	// NOTE: placeholder layout
struct C65_Style { int f0; char pad4[0x24 - 4]; int f24; };	// NOTE: placeholder layout
struct C65_MsgType { char pad0[0x24]; int f24; char pad28[0x44 - 0x28]; bool f44; };	// NOTE: placeholder layout
struct C65_Msg { C65_MsgType *type; string text; };	// NOTE: placeholder layout

extern int c65_d28d10;	// NOTE: placeholder names below
extern string c65_d21928;
extern vector<C65_Style *> c65_d35b48;
extern vector<C65_FontSet *> c65_cfe704;
extern C65_Style *c65_cefbcc;

class CGameover	// NOTE: placeholder layout
{
public:
	vector<C65_Msg *> messages;

	void render(string path, const string &suffix);
};

void CGameover::render(string path, const string &suffix)
{
	switch (c65_d28d10)
	{
			break;	// NOTE: an unreachable leading break reproduces the exe's duplicate jump after the case dispatch
		case 1:
		{
			path += suffix;
			path += ".txt";
			ofstream center(path.c_str());
			if (!center.is_open())
			{
				logError("CGameover::render()","Unable to open " + path + " for writing, no log output");
				break;
			}
			if (suffix == string() + "_log")
				center << "Cogmind Message Log - " << c65_d21928 << "\n";
			else
				center << "Cogmind Combat Log - " << c65_d21928 << "\n";
			center << "\n";
			for (unsigned int col = 0; col < messages.size(); col++)
			{
				if (messages[col]->type != 0 && messages[col]->type->f44 && messages[col]->text != " ")
					center << messages[col]->text << "\n";
			}
			center.close();
			break;
		}
		case 2:
		{
			path += suffix;
			path += ".htm";
			ofstream center(path.c_str());
			if (!center.is_open())
			{
				logError("CGameover::render()","Unable to open " + path + " for writing, no log output");
				break;
			}
			vector<string> adj;
			for (unsigned int col = 0; col < c65_d35b48.size(); col++)
			{
				XColor cols = c65_cfe704[c65_d35b48[col]->f24]->fcc.front()->fcc.front()->f64;
				adj.push_back("<span style=\"color:rgb(" + intToString(cols.r) + "," + intToString(cols.g) + "," + intToString(cols.b) + ")\">");
			}
			center << "<html>" << "\n";
			center << "<head>" << "\n";
			center << "<STYLE type=\"text/css\">\n";
			center << "body { color: #00CC00; background-color: #000000; font-size: 100%; font-family: 'Courier New', Courier, monospace }" << "\n";
			center << "</head>" << "\n";
			center << "</STYLE>" << "\n";
			center << "<body>" << "\n";
			if (suffix == string() + "_log")
				center << "Cogmind Message Log - " << c65_d21928 << "<br>\n";
			else
				center << "Cogmind Combat Log - " << c65_d21928 << "<br>\n";
			center << "<br>\n";
			for (unsigned int col = 0; col < messages.size(); col++)
			{
				if (messages[col]->type != 0 && messages[col]->type->f44 && messages[col]->text != " ")
				{
					string cols = messages[col]->text;
					OpC_replaceAll_407f00(cols,"<","&lt;");
					OpC_replaceAll_407f00(cols,">","&gt;");
					center << adj[messages[col]->type != 0 ? c65_d35b48[messages[col]->type->f24]->f0 : c65_cefbcc->f0] << cols << "</span><br>\n";
				}
			}
			center << "</body>" << "\n";
			center << "</html>" << "\n";
			center.close();
			break;
		}
	}
}
