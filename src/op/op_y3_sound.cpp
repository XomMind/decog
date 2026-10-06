// op_y3: sound playback helpers and ambient sound source collection, 0x4fe000-0x501000.
// NOTE: SoundData/AmbientSoundSystem are named from embedded strings; field and helper names are placeholders.
#include <string>
#include <vector>
using namespace std;

void logError(string location, string message);

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);
	Point(const Point &p);	// 0x46ca50
	bool operator==(const Point &p) const;	// 0x409b90
	bool operator!=(const Point &p) const;	// 0x409bd0
};

class XBuffer;
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	Point unknown45a4c0();	// NOTE: placeholder name
};

class HEntity	// NOTE: placeholder layout
{
public:
	int ID;
	bool isNull() const;
	Entity *operator->() const;	// 0x9b6570
};

class SoundData;

struct OpY3_PropInfo	// NOTE: placeholder name
{
	char pad00[0x15c];
	SoundData *ambientSound;	// NOTE: placeholder name
};

class Prop
{
public:
	OpY3_PropInfo *getInfo() throw();	// NOTE: placeholder name (folded getter)
	int unknownGetter() throw();	// NOTE: placeholder name (folded getter)
	bool unknown45cad0();	// NOTE: placeholder name
	bool unknown45caf0();	// NOTE: placeholder name
};

class HProp	// NOTE: placeholder layout
{
public:
	int ID;
	bool isValid() const;
	Prop *operator->() const throw();	// 0x9b64f0
};

class Cell
{
public:
	HProp getProp() throw();	// 0x45d550
	int unknown45d430();	// NOTE: placeholder name
};

class OpY3_Cells	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell *&operator()(int x, int y) throw();	// 0x9ceda0
	Cell *&operator()(const Point &p);	// 0x9ced70
	void getRect(const Point &p, int radius, struct OpY3_Area &out) throw();	// NOTE: placeholder name (0x9b4430)
	void getBounds(const Point &center, int radius, Point &topLeft, Point &bottomRight);	// NOTE: placeholder name (0x9b7a40)
};
extern OpY3_Cells opY3_cells;	// NOTE: placeholder name

struct OpY3_Area	// NOTE: placeholder name
{
	int unknown[4];
};
extern OpY3_Area opY3_area_d35b84;	// NOTE: placeholder name

class Cartographer2DMoveCost;
class Cartographer2D
{
public:
	bool findPath(const Point &from, const Point &to, Cartographer2DMoveCost *moveCost, void *data, vector<Point> &path);	// NOTE: placeholder name
};
extern Cartographer2D opY3_cartographer;	// NOTE: placeholder name (0xcfe568)
extern Cartographer2DMoveCost *opY3_moveCost_cefc48;	// NOTE: placeholder name

class XConsole;
class CAudioLogs
{
public:
	void addLog(int ID, int number, const string &name);	// NOTE: placeholder name
};
class OpY3_CMap	// NOTE: placeholder name (0xcec054)
{
public:
	CAudioLogs *getAudioLog();
	void unknown819840(SoundData *sound, const Point &pos);	// NOTE: placeholder name
};
extern OpY3_CMap *opY3_cmap;	// NOTE: placeholder name

class OpY3_Map	// NOTE: placeholder name (0xcefc4c)
{
public:
	HEntity getPlayer();
	bool unknown4633c0(const Point &p);	// NOTE: placeholder name
	void raiseUnknownA70(unsigned int v);	// NOTE: placeholder name
};
extern OpY3_Map *opY3_world;	// NOTE: placeholder name

class OpY3_AudioMixer	// NOTE: placeholder name (0xcefa90)
{
public:
	XBuffer *loadSound(string file);	// NOTE: placeholder name (0x4195c0)
	int unknown419550(XBuffer *chunk);	// NOTE: placeholder name
	int unknown419680(XBuffer *chunk, int loops, double volume);	// NOTE: placeholder name
	void unknown419c10(XBuffer *chunk, int fade);	// NOTE: placeholder name
	int unknown41a230(int channel, XBuffer *chunk, int loops, int fade, double volume);	// NOTE: placeholder name
	bool unknown41a680(int channel);	// NOTE: placeholder name
};
extern OpY3_AudioMixer *opY3_audioMixer;	// NOTE: placeholder name

class XResourceMgr
{
public:
	bool fileExists(string file);
};
extern XResourceMgr *opY3_resourceMgr;	// NOTE: placeholder name (0xcefa88)

class SoundData
{
public:
	int falloff0(int distance);	// NOTE: placeholder name (0x453fe0)
	int falloff1(int distance);	// NOTE: placeholder name (0x454020)
	int falloff2(int distance);	// NOTE: placeholder name (0x454080)
	int falloff3(int distance);	// NOTE: placeholder name (0x4540f0)

	bool loaded;	// NOTE: placeholder name
	int ID;	// NOTE: placeholder name
	vector<XBuffer *> buffers;	// NOTE: placeholder name
	char pad18[0x1c];
	int group;	// NOTE: placeholder name
	int mapType;	// NOTE: placeholder name
	int logThreshold;	// NOTE: placeholder name
	string logName;	// NOTE: placeholder name
	double volume;	// NOTE: placeholder name
	int volumePercent;	// NOTE: placeholder name
	unsigned int fullVolumeRange;	// NOTE: placeholder name
	int range;	// NOTE: placeholder name
	int falloffType;	// NOTE: placeholder name
	bool unique;	// NOTE: placeholder name
	vector<string> files;	// NOTE: placeholder name
};

extern bool opY3_cefbc4;	// NOTE: placeholder name
extern bool audioDisabled;	// NOTE: placeholder name (0xd28cbc)
extern bool opY3_groupEnabled[];	// NOTE: placeholder name (0xd28c90)
extern int opY3_groupVolume[];	// NOTE: placeholder name (0xd28c94)
extern bool opY3_cefadc;	// NOTE: placeholder name
extern double opY3_cefae0;	// NOTE: placeholder name
extern bool opY3_d28dfd;	// NOTE: placeholder name
extern bool opY3_d28fa6;	// NOTE: placeholder name
extern bool opY3_d28fb1;	// NOTE: placeholder name
extern vector<Point> opY3_cefd04;	// NOTE: placeholder name

template <class T> void opY3_eraseAt(vector<T> &v, unsigned int &i);	// NOTE: placeholder name (0x9d3d90)
template <class T> T opY3_randomElement(vector<T> &v);	// NOTE: placeholder name (0x9d5d00)
template <class T> void opY3_removeAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9d5190)
template <class T> bool opY3_contains(vector<T> &v, T e);	// NOTE: placeholder name (0x9d0ce0)
int opY3_distance(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

class OpY3_Stream;
void opY3_readInt(OpY3_Stream *stream, void *value);	// NOTE: placeholder name (0x9d8480)
void opY3_readString(OpY3_Stream *stream, string *value);	// NOTE: placeholder name (0x436960)

struct OpY3_SoundGroup	// NOTE: placeholder name
{
	OpY3_SoundGroup(OpY3_Stream *stream);

	int ID;	// NOTE: placeholder name
	string name;	// NOTE: placeholder name
	int unknown20;	// NOTE: placeholder name
	int channelCount;	// NOTE: placeholder name
	int unknown28;	// NOTE: placeholder name
};

OpY3_SoundGroup::OpY3_SoundGroup(OpY3_Stream *stream)
{
	opY3_readInt(stream,this);
	opY3_readString(stream,&name);
	opY3_readInt(stream,&unknown20);
	opY3_readInt(stream,&channelCount);
	unknown28 = 0;
}

void opY3_loadDeferredSound(SoundData *sound)	// NOTE: placeholder name
{
	if (opY3_cefbc4 || sound->loaded || audioDisabled)
		return;

	for (unsigned int i = 0; i < sound->files.size(); i++)
	{
		if (!opY3_resourceMgr->fileExists(sound->files[i]+".ogg"))
		{
			logError("deferred audio fail","qoxrekyjtxgxdfw");
			opY3_eraseAt(sound->files,i);
		}
		else
			sound->buffers.push_back(opY3_audioMixer->loadSound(sound->files[i]+".ogg"));
	}
	sound->loaded = true;
}

int opY3_playChunk(XBuffer *chunk, int channel, int fade, int loopsB, int loops, double volume)	// NOTE: placeholder name
{
	int result = -1;
	if (audioDisabled)
		return result;
	if (fade != 0)
		opY3_audioMixer->unknown419c10(chunk,fade);
	result = channel == -1 ? opY3_audioMixer->unknown419680(chunk,loops,volume) : opY3_audioMixer->unknown41a230(channel,chunk,loops,loopsB,volume);
	if (opY3_world != NULL)
		opY3_world->raiseUnknownA70(opY3_audioMixer->unknown419550(chunk));
	return result;
}

int opY3_playSound(SoundData *sound, int channel, int fade, int loopsB, int loops)	// NOTE: placeholder name
{
	if (opY3_groupEnabled[sound->group])
	{
		if (fade == 0)
			fade = opY3_groupVolume[sound->group]*10;
		opY3_loadDeferredSound(sound);
		switch (sound->buffers.size())
		{
			case 1:
				return opY3_playChunk(sound->buffers.front(),channel,fade,loopsB,loops,opY3_cefadc && sound->group == 1 ? opY3_cefae0 : sound->volume);
			case 0:
				return -1;
			default:
				return opY3_playChunk(opY3_randomElement(sound->buffers),channel,fade,loopsB,loops,opY3_cefadc && sound->group == 1 ? opY3_cefae0 : sound->volume);
		}
	}
	return -1;
}

int opY3_volumeAt(SoundData *sound, const Point &pos, const Point &listener);	// NOTE: placeholder name

int soundPlayRelative(const Point &pos, SoundData *sound, int channel, bool noPlay)	// NOTE: name from log string
{
	if (sound == NULL)
	{
		logError("soundPlayRelative()","NULL SoundData!");
		return 0;
	}
	if (opY3_groupEnabled[sound->group])
	{
		if (sound->unique && channel != -1 && opY3_audioMixer->unknown41a680(channel))
			return 0;

		int distanceVolume = 0;
		int volume;
		if (sound->range == 0)
			volume = 100;
		else
		{
			distanceVolume = opY3_world->getPlayer().operator->() ? opY3_volumeAt(sound,pos,opY3_world->getPlayer()->unknown45a4c0()) : 0;
			if (distanceVolume == 0)
				return 0;
			volume = opY3_d28dfd ? 100 : distanceVolume;
		}

		if (!noPlay)
		{
			if (sound->mapType != 0 && !opY3_d28fa6 && distanceVolume >= 25 && (sound->mapType != 8 || !opY3_contains(opY3_cefd04,Point(pos))))
				opY3_cmap->unknown819840(sound,pos);
			if (sound->logThreshold >= 6 && distanceVolume >= 10 && (opY3_world->getPlayer().isNull() || pos != opY3_world->getPlayer()->getPosition()) &&
				(opY3_d28fb1 || !opY3_world->unknown4633c0(pos)) && opY3_cmap->getAudioLog() != NULL)
				opY3_cmap->getAudioLog()->addLog(sound->ID,volume,sound->logName);
			volume = volume*sound->volumePercent/100*opY3_groupVolume[sound->group]/10;
			opY3_playSound(sound,channel,volume,(int)(opY3_cefadc && sound->group == 1 ? opY3_cefae0 : sound->volume),0);
		}
		return volume;
	}
	else
		return 0;
}

class AmbientSource	// NOTE: placeholder name
{
public:
	AmbientSource(HProp prop_, int volume_);

	HProp prop;	// NOTE: placeholder name
	SoundData *sound;	// NOTE: placeholder name
	int volume;	// NOTE: placeholder name
};

AmbientSource::AmbientSource(HProp prop_, int volume_)
{
	prop = prop_;
	sound = prop->getInfo()->ambientSound;
	volume = volume_;
}

class AmbientSoundSystem
{
public:
	void collectSources(const Point &center, vector<AmbientSource *> *sources);	// NOTE: placeholder name
};

void AmbientSoundSystem::collectSources(const Point &center, vector<AmbientSource *> *sources)
{
	Point a;
	Point b;
	int volume;
	opY3_cells.getBounds(center,25,a,b);
	for (int y = a.y; y <= b.y; y++)
	{
		for (int x = a.x; x <= b.x; x++)
		{
			if (opY3_cells(x,y)->getProp().isValid() && opY3_cells(x,y)->getProp()->unknownGetter() == 0 &&
				opY3_cells(x,y)->getProp()->unknown45cad0() && !opY3_cells(x,y)->getProp()->unknown45caf0())
			{
				volume = opY3_volumeAt(opY3_cells(x,y)->getProp()->getInfo()->ambientSound,Point(x,y),center);
				if (volume != 0)
				{
					opY3_loadDeferredSound(opY3_cells(x,y)->getProp()->getInfo()->ambientSound);
					sources->push_back(new AmbientSource(opY3_cells(x,y)->getProp(),volume));
				}
			}
		}
	}
}

int opY3_volumeAt(SoundData *sound, const Point &pos, const Point &listener)
{
	if (listener == pos)
		return 100;

	vector<Point> path;
	if (opY3_distance(pos,listener) >= sound->range)
		return 0;
	opY3_cells.getRect(pos,sound->range,opY3_area_d35b84);
	if (opY3_cartographer.findPath(pos,listener,opY3_moveCost_cefc48,NULL,path))
	{
		opY3_removeAt(path,0);
		if (path.size() < sound->range)
		{
			float factor = 1.0f;
			for (unsigned int i = 0; i < path.size(); i++)
			{
				factor = (100 - opY3_cells(path[i])->unknown45d430())*factor/100.0;
				if (factor <= 0)
					return 0;
			}
			int (SoundData::*func)(int) = NULL;
			switch (sound->falloffType)
			{
				case 0: func = &SoundData::falloff0; break;
				case 1: func = &SoundData::falloff1; break;
				case 2: func = &SoundData::falloff2; break;
				case 3: func = &SoundData::falloff3; break;
			}
			return (int)((path.size() <= sound->fullVolumeRange ? 100 : (sound->*func)(path.size()))*factor);
		}
	}
	return 0;
}
