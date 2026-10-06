// op_t3_c: STrapTrigger::update and Prop/Cell helpers.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Point2	// NOTE: placeholder name
{
	int x;
	int y;
};

class XBuffer;
class SoundData
{
public:
	char pad0[8];
	vector<XBuffer *> buffers;	// NOTE: placeholder name
};

class AudioMixer	// NOTE: placeholder name (0xcefa90)
{
public:
	int unknown419550(XBuffer *chunk);	// NOTE: placeholder name
};
extern AudioMixer *audioMixer;	// NOTE: placeholder name (0xcefa90)
extern vector<SoundData *> opr2b_sounds;	// NOTE: placeholder name (0xd2e9a0)
extern int opT3c_frameTime;				// NOTE: placeholder name (0xcefa78)

int opR1d_454260(const Point2 &pos, unsigned int sound);	// NOTE: placeholder name

class Map
{
public:
	char pad0[0x74];
	void setFlagA74(bool v);	// NOTE: placeholder name
};

class BS : public Map
{
public:
	bool isVisible(const Point &p);	// NOTE: placeholder name
};

class Push_465a70
{
public:
	char unknown0[0xc14];
	int fieldc14;
	void operate();
};

extern Map *world;	// 0xcefc4c

class BattleState	// NOTE: placeholder layout
{
public:
	virtual ~BattleState();
	virtual int getType();			// NOTE: placeholder name
	virtual bool update();			// NOTE: placeholder name
	virtual void unknown3() = 0;	// NOTE: placeholder name

	int unknown4;				// NOTE: placeholder name
};

class STrapTrigger : public BattleState
{
public:
	~STrapTrigger();
	virtual int getType();
	virtual bool update();

	void unknown665fd0(bool hidden);	// NOTE: placeholder name

	int state;
	unsigned int timer;
	char pad10[4];
	Point position;
	char pad1c[0x2c - 0x1c];
	unsigned int duration;
	bool playing;
};

bool STrapTrigger::update()
{
	if (state == 0)
	{
		state = 7;
	}
	timer = timer + opT3c_frameTime;

	switch (state)
	{
	case 7:
		world->setFlagA74(true);
		playing = opR1d_454260((const Point2 &)position,0x9c) != 0 ? true : false;
		if (playing)
		{
			if (opr2b_sounds[0x9c]->buffers.empty())
			{
				playing = false;
			}
			else
			{
				duration = audioMixer->unknown419550(opr2b_sounds[0x9c]->buffers.front());
			}
		}
		world->setFlagA74(false);
		state = 8;
	case 8:
		if (timer < duration)
		{
			break;
		}
		else
		{
			bool hidden = !playing && !((BS *)world)->isVisible(position);
			world->setFlagA74(true);
			unknown665fd0(hidden);
			if (hidden)
			{
				((Push_465a70 *)world)->operate();
			}
			world->setFlagA74(false);
			return true;
		}
	}

	return false;
}
