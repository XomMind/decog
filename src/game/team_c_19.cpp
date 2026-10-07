// team_c_19: GM::processSounds (0x78e2e0): registers the audio archives and preloads every sound list
// NOTE: global/member names are placeholders unless noted
#include <string>
#include <vector>
using namespace std;

void logMessage(string message);	// 0x404cb0
void logError(string location, string message);	// 0x404f10
void opY2_initPalette1();	// 0x453c60
void opY2_initPalette2();	// 0x453d50

class XResourceMgr
{
public:
	void setArchiveExt(string ext);
	bool archiveIsValid(string path, bool append);
	bool fileExists(string path);
	bool addSearchPath(string path, bool append);
	bool addResourcePath(string path, bool append);
};

class OpR1a_AudioMixer
{
public:
	unsigned char isReady_419540();	// NOTE: placeholder name (folded with Sweep_419540::getField)
	int loadSound(string file);
};

struct OpQ5_U9d3d90;	// NOTE: placeholder (folded element type)
struct OpQ5_T9df700	// NOTE: placeholder layout (sound list)
{
	bool loaded0;
	char pad1[7];
	vector<int> sounds8;
	string name18;
	char pad34[0x7c - 0x34];
	vector<string> files7c;
};
template <class T> void OpQ5_eraseStep(vector<T> &v, int &i);	// NOTE: placeholder name
template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, int &i);	// NOTE: placeholder name

extern bool audioDisabled_d28cbc;	// NOTE: placeholder name
extern bool skipPreload_d28cbd;	// NOTE: placeholder name
extern bool debugPrint_d28faf;	// NOTE: placeholder name
extern bool audioFailed_cefbc4;	// NOTE: placeholder name
extern XResourceMgr *resourceMgr_cefa88;	// NOTE: placeholder name
extern OpR1a_AudioMixer *audioMixer_cefa90;	// NOTE: placeholder name
extern vector<OpQ5_T9df700 *> soundLists_cfd2ec;	// NOTE: placeholder name

class GM	// NOTE: partial
{
public:
	void processSounds();
};

void GM::processSounds()
{
	opY2_initPalette1();
	opY2_initPalette2();
	if (audioDisabled_d28cbc || !audioMixer_cefa90->isReady_419540())
	{
		logMessage("Skipping sound file loading");
	}
	else if (!resourceMgr_cefa88->addSearchPath(string() + "data/audio",true))
	{
		logError("GM::processSounds()","Unable to add audio search path: " + (string() + "data/audio"));
		audioDisabled_d28cbc = true;
	}
	else
	{
		if (resourceMgr_cefa88->archiveIsValid(string() + "data/audio/ui",true) && !resourceMgr_cefa88->addResourcePath(string() + "data/audio/ui",true))
			logError("GM::processSounds()","Unable to access sound archive: " + (string() + "data/audio/ui"));
		if (resourceMgr_cefa88->archiveIsValid(string() + "data/audio/game",true) && !resourceMgr_cefa88->addResourcePath(string() + "data/audio/game",true))
			logError("GM::processSounds()","Unable to access sound archive: " + (string() + "data/audio/game"));
		if (resourceMgr_cefa88->archiveIsValid(string() + "data/audio/ambient",true) && !resourceMgr_cefa88->addResourcePath(string() + "data/audio/ambient",true))
			logError("GM::processSounds()","Unable to access sound archive: " + (string() + "data/audio/ambient"));
		resourceMgr_cefa88->setArchiveExt(".zip");
		if (resourceMgr_cefa88->archiveIsValid(string() + "data/audio/sounds_user",true) && !resourceMgr_cefa88->addResourcePath(string() + "data/audio/sounds_user",true))
			logError("GM::processSounds()","Unable to access sound archive: " + (string() + "data/audio/sounds_user"));
		resourceMgr_cefa88->setArchiveExt(".x");
		if (!skipPreload_d28cbd)
		{
			for (int i = 0; i < soundLists_cfd2ec.size(); i++)
			{
				for (int j = 0; j < soundLists_cfd2ec[i]->files7c.size(); j++)
				{
					if (!resourceMgr_cefa88->fileExists(soundLists_cfd2ec[i]->files7c[j] + ".ogg"))
					{
						logError("audio preload fail 1","sxfkjhedw rwlkc");
						OpQ5_eraseStep((vector<OpQ5_U9d3d90> &)soundLists_cfd2ec[i]->files7c,j);
					}
					else
						soundLists_cfd2ec[i]->sounds8.push_back(audioMixer_cefa90->loadSound(soundLists_cfd2ec[i]->files7c[j] + ".ogg"));
				}
				if (soundLists_cfd2ec[i]->sounds8.empty())
				{
					logError("audio preload fail 2","kgkzxdsafr sdvy");
					OpQ5_deleteObjectAndStep(soundLists_cfd2ec,i);
				}
				soundLists_cfd2ec[i]->loaded0 = true;
			}
		}
	}
	if (debugPrint_d28faf)
	{
		for (int k = 0; k < soundLists_cfd2ec.size(); k++)
		{
			if (soundLists_cfd2ec[k]->name18 == "PRINT_2")
			{
				soundLists_cfd2ec[k]->sounds8.clear();
				soundLists_cfd2ec[k]->loaded0 = true;
				break;
			}
		}
		for (int m = 0; m < soundLists_cfd2ec.size(); m++)
		{
			if (soundLists_cfd2ec[m]->name18 == "PRINT_3")
			{
				soundLists_cfd2ec[m]->sounds8.clear();
				soundLists_cfd2ec[m]->loaded0 = true;
				break;
			}
		}
	}
	if (skipPreload_d28cbd && !audioDisabled_d28cbc)
	{
	}
	else
		audioFailed_cefbc4 = true;
}
