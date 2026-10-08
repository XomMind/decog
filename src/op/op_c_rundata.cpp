// op_c_rundata: 0x48ae20, the thread that uploads per-turn run data to gridsagegames.com (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void logMessage(string location, string message);	// 0x404bf0
string intToString(int value);	// 0x4051f0
string opR1d_436e70(bool dateOnly, time_t t);	// NOTE: placeholder name

class Http
{
public:
	Http(const string &host, const string &path, int port);	// 0x4499c0
	~Http();	// 0x9f51f0
	bool upload(const string &name, const string &content);	// 0x4cfd20

	string host;	// NOTE: placeholder name
	string path;	// NOTE: placeholder name
	int port;	// NOTE: placeholder name
};

class Network
{
public:
	static void threadQuitting(int threadType);	// 0x449780
};

struct OpCRD_RunData	// NOTE: placeholder name
{
	int seed;	// NOTE: placeholder name
	string player;	// NOTE: placeholder name
	int version;	// NOTE: placeholder name
	vector<int> col1;	// NOTE: placeholder name
	vector<int> col0;	// NOTE: placeholder name
	vector<int> col2;	// NOTE: placeholder name
	vector<int> col3;	// NOTE: placeholder name
};

int opC_uploadRunData_48ae20(void *data)	// NOTE: placeholder name
{
	logMessage("CXLJEXZ","VC530SA...");
	vector<int> &elem = ((OpCRD_RunData *)data)->col1;
	vector<int> &other = ((OpCRD_RunData *)data)->col0;
	vector<int> &value = ((OpCRD_RunData *)data)->col2;
	vector<int> &line = ((OpCRD_RunData *)data)->col3;
	string *temp = new string;
	for (unsigned int i = 0; i < other.size(); i++)
	{
		*temp += intToString(other[i]);
		*temp += "\t";
		*temp += intToString(elem[i]);
		*temp += "\t";
		*temp += intToString(value[i]);
		*temp += "\t";
		*temp += intToString(line[i]);
		*temp += "\n";
	}
	logMessage("A98+>>","CVGLSAFDV...");
	string output = ((OpCRD_RunData *)data)->player + "-" + opR1d_436e70(false,0) + "-" + intToString(((OpCRD_RunData *)data)->seed) + "-" + intToString(((OpCRD_RunData *)data)->version) + string() + ".xi";
	string title = "/cogmind/temp/run_data_xi_17-260816/upload.php";
	Http base("www.gridsagegames.com",title,80);
	base.upload(output,*temp);
	delete data;
	Network::threadQuitting(5);
	return 0;
}
