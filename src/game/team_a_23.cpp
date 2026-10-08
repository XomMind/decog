// team_a_23: automated user-data backup (0x466a20) and Discord setup (0x4534b0) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names; local names follow docs/local-name-buckets.txt.
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct PhysfsDirectory	// NOTE: placeholder name
{
	string name;
	vector<string> files;
	vector<PhysfsDirectory*> subdirectories;
};

class XResourceMgr
{
public:
	bool fileExists(string path);	// NOTE: placeholder name (0x415590)
	void getFileList(string dir, vector<string> *files, string ext);	// NOTE: placeholder name (0x415610)
	void getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext);	// NOTE: placeholder name (0x4156c0)
};
extern XResourceMgr *resourceMgr;	// NOTE: placeholder name (0xcefa88)
extern string gameString_cfd42c;	// CUSTOM_FILE_PATH
extern bool teamA23_backupDisabled_d28faa;	// NOTE: placeholder name
void logMessage(string message);	// NOTE: placeholder name (0x404cb0)
void OpQ1_createDirectories(string path);	// NOTE: placeholder name (0x409240)
void OpQ1_copyPhysFile(string source, string dest);	// NOTE: placeholder name (0x4094a0)
string opR1d_436e70(bool dateOnly, __int64 t);	// NOTE: placeholder name (date string)
template <class T> void OpQ5_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name

// copies user/ into bak/<date>/ once per day, keeping at most ten daily backups (0x466a20)
void teamA23_backupUserData_466a20()	// NOTE: placeholder name
{
	if (teamA23_backupDisabled_d28faa)
	{
		logMessage("Automated backup system disabled");
		return;
	}
	if (!resourceMgr->fileExists(string() + "bak/"))
	{
		logMessage("Automated backup system unable to find " + (gameString_cfd42c + "bak/") + ", creating");
		OpQ1_createDirectories(gameString_cfd42c + "bak/");
	}
	string date = opR1d_436e70(true,0);
	if (!resourceMgr->fileExists(string() + "bak/" + date))
	{
		vector<string> entries;
		resourceMgr->getFileList(string() + "bak/",&entries,"");
		while (entries.size() > 9)
		{
			vector<string> items;
			resourceMgr->getFileList(string() + "bak/" + entries.front(),&items,"");
			for (unsigned int i = 0; i < items.size(); i++)
			{
				string path = gameString_cfd42c + "bak/" + entries.front() + "/" + items[i];
				remove(path.c_str());
			}
			string source = gameString_cfd42c + "bak/" + entries.front();
			RemoveDirectoryA(source.c_str());
			OpQ5_eraseAt(entries,0);
		}
		string dest = gameString_cfd42c + "bak/" + date + "/";
		logMessage("Automated backup system saving user data to " + dest);
		OpQ1_createDirectories(dest.c_str());
		vector<PhysfsDirectory*> branch;
		resourceMgr->getFileTree(string() + "user/",&branch,"");
		for (unsigned int i = 0; i < branch[0]->files.size(); i++)
			OpQ1_copyPhysFile(string() + "user/" + branch[0]->files[i],dest + branch[0]->files[i]);
	}
}


struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File * const file;
	public:
		base_fstream(PHYSFS_File *file);
		virtual ~base_fstream();
		bool isOpen_404af0();	// NOTE: placeholder name
	};

	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(string const &filename, std::ios_base::openmode mode = std::ios_base::in);
		virtual ~ifstream();
		void close_458f60();	// NOTE: placeholder name
	};
}


class C026_Rec453470	// NOTE: placeholder name (discord settings, 0x38 bytes)
{
public:
	C026_Rec453470(const string &s);
	~C026_Rec453470();

	string host;	// NOTE: placeholder name
	void *thread;	// NOTE: placeholder name
	HANDLE mutex;	// NOTE: placeholder name
	char pad24[0x34 - 0x24];
	bool history;	// NOTE: placeholder name
};
extern C026_Rec453470 *teamA23_discord_cefb5c;	// NOTE: placeholder name
extern bool teamA23_discordActive_cefb59;	// NOTE: placeholder name
extern string teamA23_playerName_d28ccc;	// NOTE: placeholder name
extern string teamA23_defaultName_d2f184;	// NOTE: placeholder name
extern string teamA23_discordUser_d28fdc;	// NOTE: placeholder name
void *opY2_startNetworkThread(void *id, bool force, int (*fn)(void*), void *data);	// NOTE: placeholder name
int teamA23_discordThread_4fa0c0(void *data);	// NOTE: placeholder name
bool OpY1_getEncodedLine(PhysFScpp::ifstream *file, string &line, int key);	// NOTE: placeholder name (0x4074b0)
void OpC_removeChar_408100(string &text, char c);	// NOTE: placeholder name

// reads discord.txt and starts the Discord status thread; returns a status message (0x4534b0)
string teamA23_initDiscord_4534b0()	// NOTE: placeholder name
{
	if (!resourceMgr->fileExists(string() + "discord.txt"))
		return "No relevant settings found";
	if (teamA23_playerName_d28ccc == teamA23_defaultName_d2f184)
		return "Must have non-anonymous player name on startup to activate";
	PhysFScpp::ifstream file((string() + "discord.txt").c_str());
	if (!file.isOpen_404af0())
		return "Unable to open " + (string() + "discord.txt");
	teamA23_discord_cefb5c = new C026_Rec453470(teamA23_discordUser_d28fdc);
	teamA23_discord_cefb5c->thread = opY2_startNetworkThread((void *)7,true,teamA23_discordThread_4fa0c0,NULL);
	if (teamA23_discord_cefb5c->thread == NULL)
	{
		delete teamA23_discord_cefb5c;
		teamA23_discord_cefb5c = NULL;
		return "Unable to start thread";
	}
	teamA23_discordActive_cefb59 = true;
	teamA23_discord_cefb5c->mutex = CreateMutexW(NULL,FALSE,NULL);
	string buf;
	string message = "Using default host target";
	while (OpY1_getEncodedLine(&file,buf,-1))
	{
		OpC_removeChar_408100(buf,'\n');
		if (buf == "history=0")
			teamA23_discord_cefb5c->history = false;
		else
		{
			string prefix = "https://discord.com";
			if (buf.size() < prefix.size() + 20)
				break;
			unsigned int pos = buf.find(prefix,0);
			if (pos == string::npos || pos != 0)
				break;
			teamA23_discord_cefb5c->host.assign(buf.begin() + pos + prefix.size(),buf.end());
			message = "Overriding host: " + teamA23_discord_cefb5c->host;
		}
		buf.clear();
	}
	file.close_458f60();
	return message;
}
