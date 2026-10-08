// team_c_44: run-data upload thread (0x48a3f0): encodes the scoresheet's per-depth number lists into a text blob
//	and posts it to gridsagegames.com (thread started by Scorekeeper::outputScoresheet, type 4)
// NOTE: names are placeholders; the data block layout is partial
#include <string>
#include <vector>
#include "../util/rng.h"
using namespace std;

extern RNG rng;	// 0xd30908
string intToString(int value);
string &padLeft_408090(string &text, int width, char fill);	// NOTE: placeholder name
string opR1d_436e70(int unknown1, int unknown2, int unknown3);	// NOTE: placeholder name (date/time string)
void logMessage(string location, string message);	// NOTE: placeholder name (0x404bf0)
void logError(string location, string message);

class Network
{
public:
	static void threadQuitting(int threadType);
};

struct C44_RunData	// NOTE: placeholder layout (allocated by outputScoresheet)
{
	vector<int> f0;
	vector< vector<int> > f10;
	vector< vector<int> > f20;
	vector< vector<int> > f30;
	int f40;
	string f44;
	int f60;
};

class C44_Http	// NOTE: placeholder (Http)
{
public:
	string host;
	string path;
	int port;

	C44_Http(const string &host_, const string &path_, int port_);
	~C44_Http();
	bool upload(const string &body, string *response);
};

int c44_uploadRunData_48a3f0(void *data)	// NOTE: placeholder name
{
	logMessage("KLJHASY","VAz53L6...");
	vector<int> &center = ((C44_RunData *)data)->f0;
	vector< vector<int> > &adj = ((C44_RunData *)data)->f10;
	vector< vector<int> > &allies = ((C44_RunData *)data)->f20;
	vector< vector<int> > &behaviour = ((C44_RunData *)data)->f30;
	string *clean = new string;
	if (allies.size() != behaviour.size() && allies.size() != behaviour.size() + 1)
		logError("ASDLKAC","ODD");
	for (unsigned int cols = 0; cols < center.size(); cols++)
	{
		*clean += padLeft_408090(intToString(1129 - center[cols]),4,'0');
		for (unsigned int current = 0; current < allies[cols].size(); current++)
			*clean += padLeft_408090(intToString(9999 - allies[cols][current]),4,'0');
		if (adj[cols].empty())
			*clean += intToString(rng.rangeInt(1000,9999));
		else
		{
			for (unsigned int distanceSq = 0; distanceSq < adj[cols].size(); distanceSq++)
				*clean += padLeft_408090(intToString(999 - adj[cols][distanceSq]),4,'0');
		}
		if (cols < behaviour.size())
		{
			*clean += "\n";
			*clean += padLeft_408090(intToString(1129 - center[cols]),4,'0');
			for (unsigned int distances = 0; distances < behaviour[cols].size(); distances++)
				*clean += padLeft_408090(intToString(9999 - behaviour[cols][distances]),4,'0');
			*clean += intToString(rng.rangeInt(1000,9999));
		}
		*clean += "\n";
	}
	logMessage("CVX+>>","XCZKJHASE...");
	string a1 = ((C44_RunData *)data)->f44 + "-" + opR1d_436e70(0,0,0) + "-" + intToString(((C44_RunData *)data)->f40) + "-" + intToString(((C44_RunData *)data)->f60) + string() + ".tex";
	string col("/cogmind/temp/run_data_171/upload.php");
	C44_Http attempt("www.gridsagegames.com",col,80);
	attempt.upload(a1,clean);
	delete data;
	Network::threadQuitting(4);
	return 0;
}
