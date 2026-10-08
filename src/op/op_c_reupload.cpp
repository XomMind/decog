// op_c_reupload: checkScoreReupload() (0x489c20), the startup thread that re-sends score sheets left in
// scores/temp by an earlier failed upload (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts except where stated.
#include <string>
#include <vector>
#include <stdio.h>
#include "../thirdparty/zfstream.h"
using namespace std;

void logMessage(string message);	// 0x404cb0
string intToString(int value);	// 0x4051f0
void logInfo(string location, string message);	// 0x405090
void logError(string location, string message);	// 0x404f10

struct PhysfsDirectory	// NOTE: placeholder name
{
	string name;
	vector<string> files;
	vector<PhysfsDirectory*> subdirectories;
};

class XResourceMgr
{
public:
	void getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext);	// 0x4156c0
};
extern XResourceMgr *opCR_resMgr;	// NOTE: placeholder name (0xcefa88)
extern string gameString_cfd42c;	// CUSTOM_FILE_PATH

struct OpQ5_U9d3d90;	// NOTE: placeholder name
template <class T> void OpQ5_eraseStep(vector<T> &v, int &index);	// NOTE: placeholder name

namespace Protobuf
{
class Meta
{
public:
	const string &opCR_runId_44b0d0();	// NOTE: placeholder name (0x44b0d0, a string field getter)
};
class Scoresheet
{
public:
	Meta *mutable_meta();
};
class PostScoresheetRequest
{
public:
	Scoresheet *mutable_scoresheet();
};
}

class UploadScoreData
{
public:
	UploadScoreData(istream &in, bool flag_);	// 0x488fa0

	Protobuf::PostScoresheetRequest	*data;
	bool							flag;	// NOTE: placeholder name
};

bool OpU8a_containsString(vector<string> &v, string s);	// NOTE: placeholder name (0x9d3fe0)
extern vector<string> opCR_uploadedRuns;	// NOTE: placeholder name (0xd25780)
void opCR_uploadScores_4884c0(UploadScoreData *data);	// NOTE: placeholder name
extern bool opCR_uploadSucceeded;	// NOTE: placeholder name (0xcefc5e)

class JLog
{
public:
	void end(int type);	// 0x410e50
};
extern JLog *opCR_jlog;	// NOTE: placeholder name (0xcefa64)

class Network
{
public:
	static void threadQuitting(int threadType);	// 0x449780
};

int checkScoreReupload(void *data)	// NOTE: placeholder name (string: "checkScoreReupload()")
{
	logInfo("checkScoreReupload()","Checking for old scores to upload...");
	vector<PhysfsDirectory*> directories;
	opCR_resMgr->getFileTree(gameString_cfd42c + "scores/temp",&directories,"bin");
	if (!directories[0]->files.empty())
	{
		logMessage("Found " + intToString(directories[0]->files.size()) + " relevant files");
		for (unsigned int i = 0; i < directories[0]->files.size(); i++)
		{
			string path = gameString_cfd42c + "scores/temp";
			path += "/";
			path += directories[0]->files[i];
			gzifstream in(path.c_str(),ios::binary);
			if (!in.is_open())
			{
				logError("checkScoreReupload()","Unable to open \"" + directories[0]->files[i] + "\"");
			}
			else
			{
			UploadScoreData *upload = new UploadScoreData(in,false);
			in.close();
			if (OpU8a_containsString(opCR_uploadedRuns,upload->data->mutable_scoresheet()->mutable_meta()->opCR_runId_44b0d0()))
			{
				logMessage("Skipping already uploaded run: " + directories[0]->files[i]);
				remove((gameString_cfd42c + "scores/temp" + "/" + directories[0]->files[i]).c_str());
				OpQ5_eraseStep((vector<OpQ5_U9d3d90>&)directories[0]->files,(int&)i);
			}
			else
			{
				logMessage("Uploading " + directories[0]->files[i] + "...");
				opCR_uploadScores_4884c0(upload);
				if (opCR_uploadSucceeded)
				{
					remove((gameString_cfd42c + "scores/temp" + "/" + directories[0]->files[i]).c_str());
					OpQ5_eraseStep((vector<OpQ5_U9d3d90>&)directories[0]->files,(int&)i);
					logMessage("Upload succeeded");
				}
				else
				{
					logMessage("Upload failed, quitting");
					break;
				}
			}
			}
		}
	}
	opCR_jlog->end(2);
	Network::threadQuitting(2);
	return 0;
}
