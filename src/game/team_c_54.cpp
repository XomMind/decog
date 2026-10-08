// team_c_54: GM::loadManual (0x78fb80): reads the manual text (sections start with "--", headers with " X"), then
//	appends user/notes.txt (creating it with a short explanation when missing) as the "Notes" section
// NOTE: names are placeholders
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void logMessage(string message);
void logError(string location, string message);
void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)
void OpC_removeChar_408100(string &text, char c);	// NOTE: placeholder name
bool opR4_isPrintableNoBacktick(char c);	// NOTE: placeholder name (0x78fb40)
bool opR4_startsWithDoubleDash(const string &s);	// NOTE: placeholder name (0x78fa80)
bool opR4_startsWithSpaceAlnum(const string &s);	// NOTE: placeholder name (0x78fad0)

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
		void close_9c05e0();	// NOTE: placeholder name (empty)
	};
}
bool OpY1_getEncodedLine(PhysFScpp::ifstream *file, string &line, int key);	// NOTE: placeholder name (0x4074b0)

struct C54_Section	// NOTE: placeholder (manual section, 0x40 bytes; ctor 0x7908a0)
{
	int f0;
	string f4;
	vector<string> f20;
	vector<int> f30;

	C54_Section();
};

C54_Section::C54_Section()
{
}

struct C54_JLog { void end(int level); };
extern C54_JLog *c54_cefa64;	// NOTE: placeholder names
extern vector<C54_Section *> c54_cf39dc;
extern string gameString_cfd42c;	// global_strings.cpp

class GM	// NOTE: placeholder layout
{
public:
	bool loadManual(string &path);
};

bool GM::loadManual(string &path)
{
	int base = 0;
	string allies;
	vector<string> center;
	vector<string> adj;
	string bottom;
	logMessage("Loading " + string("Manual Content") + "...");
	PhysFScpp::ifstream col(path.c_str());
	if (!col.isOpen_404af0())
	{
		c54_cefa64->end(2);
		return false;
	}
	else
		logMessage("[File: " + path + "] ");
	bool a1 = false;
	int bonus;
	C54_Section *branch = 0;
	while (OpY1_getEncodedLine(&col,allies,-1))
	{
		base++;
		OpC_removeChar_408100(allies,'\n');
		OpC_removeChar_408100(allies,'`');
		for (unsigned int cols = 0; cols < allies.size(); cols++)
		{
			if (!opR4_isPrintableNoBacktick(allies[cols]))
			{
				allies.erase(allies.begin() + cols);
				while (!allies.empty() && allies[cols] == ' ')
					allies.erase(allies.begin() + cols);
				cols--;
			}
		}
		if (!a1)
		{
			if (opR4_startsWithDoubleDash(allies))
				a1 = true;
			else
				continue;
		}
		if (opR4_startsWithSpaceAlnum(allies))
		{
			branch->f20.push_back(string());
			branch->f20.back().assign(allies.begin() + 1,allies.end());
			branch->f30.push_back(branch->f20.size() - 1);
			OpY1_getEncodedLine(&col,allies,-1);
			base++;
		}
		else if (opR4_startsWithDoubleDash(allies))
		{
			if (branch != 0)
			{
				c54_cf39dc.push_back(branch);
				for (int cols = c54_cf39dc.size() - 2; cols >= 0; cols--)
					c54_cf39dc[cols]->f4 == branch->f4;
			}
			if (0) {}
			branch = new C54_Section;
			branch->f0 = c54_cf39dc.size();
			OpY1_getEncodedLine(&col,allies,-1);
			base++;
			OpC_removeChar_408100(allies,'\n');
			allies.empty();
			if (0) {}
			branch->f4.assign(allies.begin() + 1,allies.end());
			OpY1_getEncodedLine(&col,allies,-1);
			base++;
		}
		else
			branch->f20.push_back(allies);
	}
	c54_cf39dc.push_back(branch);
	for (int cols = c54_cf39dc.size() - 2; cols >= 0; cols--)
		c54_cf39dc[cols]->f4 == branch->f4;
	col.close_9c05e0();
	if (c54_cf39dc.back()->f4.find("Notes",0) != string::npos)
	{
		if (0) {}
		branch = c54_cf39dc.back();
		branch->f20.clear();
		path = gameString_cfd42c + "user/" + "notes.txt";
		ifstream current;
		current.open(path.c_str(),ios::in,0x40);
		if (!current.is_open())
		{
			ofstream distanceSq;
			distanceSq.open(path,ios::out,0x40);
			if (!distanceSq.is_open())
				logError("GM::loadManual()","Unable to open " + path + " for writing, could create default");
			else
			{
				distanceSq << "Did you know Cogmind\'s manual contents appear both in game and as a text file \"manual.txt\"? You can read the manual outside the game, or even edit the file and have the changes appear in game as well. However, for convenience and because automated updating via Steam would overwrite your modified manual, in order to facilitate maintaining your notes across versions you should instead write them in the provided user/notes.txt file. (Only basic ASCII characters are accepted; foreign language characters are ignored because the engine cannot display them.)";
				distanceSq.close();
			}
			current.open(path.c_str(),ios::in,0x40);
			if (!current.is_open())
			{
				logFatal("GM::loadDataset()","Unable to open " + path);
				c54_cefa64->end(2);
				return false;
			}
		}
		base = 0;
		logMessage("Loading Manual Notes...");
		logMessage("[File: " + path + "] ");
		while (getline(current,allies))
		{
			base++;
			OpC_removeChar_408100(allies,'\n');
			OpC_removeChar_408100(allies,'`');
			for (unsigned int distanceSq = 0; distanceSq < allies.size(); distanceSq++)
			{
				if (!opR4_isPrintableNoBacktick(allies[distanceSq]))
				{
					allies.erase(allies.begin() + distanceSq);
					while (allies[distanceSq] == ' ')
						allies.erase(allies.begin() + distanceSq);
					distanceSq--;
				}
			}
			branch->f20.push_back(allies);
		}
		current.close();
	}
	return true;
}
