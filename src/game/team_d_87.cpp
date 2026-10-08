// team_d_87: BS member 0x74bec0: Subatomizers released at a point (effect, location remarks, marks the
// release grid, records per-map release turns, Optimus remark in the Exiles' Forge).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

int stringToInt(const string &s);
string intToString(int value);

struct Point
{
	int x;
	int y;
};

class OpS7_IntGrid2	// NOTE: placeholder layout
{
public:
	OpS7_IntGrid2(int width_, int height_, int fill);	// 0x9ced10
	int *atPoint(const Point &p);	// NOTE: folded (OpX5_Array2D<int>::atPoint)
	char pad[0xc];
};

class CellGrid87	// NOTE: placeholder name (0xcfd44c)
{
public:
	int getWidth();
	int getHeight();
};
extern CellGrid87 cells87_cfd44c;	// NOTE: placeholder name

class Entity;

class HEntity
{
public:
	int ID;
	bool isValid() const;
	bool isNull() const;
	Entity *operator->() const;
};

class Group87	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();		// NOTE: folded getter
	HEntity unknown45e250(int type);	// NOTE: placeholder name
};

class HGroup
{
	int ID;
public:
	Group87 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

class Entity
{
public:
	int getFaction();
	bool unknown5cb680(HGroup group);	// NOTE: placeholder name
};

struct Location87	// NOTE: placeholder name and layout
{
	int unknown00;
	int type;

	bool inRange();	// NOTE: placeholder name (Location_46ecb0::inRange)
};

class HLoc87	// NOTE: placeholder name
{
	int ID;
public:
	Location87 *operator->() const;
};
extern HLoc87 location87_d1e888;	// NOTE: placeholder name

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData87_d1e860;	// NOTE: placeholder name

class RNG
{
public:
	int rangeInt(float lo, float hi);
};
extern RNG rng;

class State87	// NOTE: placeholder name (object at 0xd25450)
{
public:
	bool unknown000;	// NOTE: placeholder name

	void unknown69e700(int id, int a, float b);	// NOTE: placeholder name
};
extern State87 state87_d25450;	// NOTE: placeholder name
extern bool flag87_d255b3;		// NOTE: placeholder name

bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)

class EffectObj87	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj87 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj87_cefc50;	// NOTE: placeholder name
extern Point point87_d2e20c;		// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	char			pad000[0x4c];
	vector<HGroup>	groups;		// +0x4c
	char			pad05c[0x3d4 - 0x5c];
	OpS7_IntGrid2	*grid3d4;	// +0x3d4
	vector<Point>	list3d8;	// +0x3d8
	char			pad3e8[0x66c - 0x3e8];
	HEntity			player;		// +0x66c

	int getTurn();
	bool unknown463400(HEntity e);	// NOTE: placeholder name
	void opw3_unknown72f6b0();		// NOTE: placeholder name
	void unknown7329f0();			// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);
	void unknown74bec0(const Point &pos);	// NOTE: placeholder name
};

void BS::unknown74bec0(const Point &pos)
{
	int fx;
	OpU8a_lookup2("Subatomizers_Start",&fx);
	if (fx)
		endObj87_cefc50->unknown508610()->init(endObj87_cefc50,fx,pos,point87_d2e20c,0,0,0,9,0);
	switch (location87_d1e888->type)
	{
	case 0xf:
		return;
	case 0x15:
		{
			vector<HEntity> *members = groups[4]->getMembers();
			for (unsigned int i = 0; i < members->size(); i++)
			{
				if ((*members)[i]->getFaction() == 0x59)
				{
					unknown6c65a0((*members)[i],"DAT_Subatomizer_Comment",0);
					break;
				}
			}
		}
		return;
	case 0x16:
		{
			vector<HEntity> *members = groups[4]->getMembers();
			for (unsigned int i = 0; i < members->size(); i++)
			{
				if ((*members)[i]->getFaction() == 0x56)
				{
					unknown6c65a0((*members)[i],"ZHI_Subatomizer_Comment",0);
					break;
				}
			}
		}
		return;
	}
	if (!grid3d4)
		grid3d4 = new OpS7_IntGrid2(cells87_cfd44c.getWidth(),cells87_cfd44c.getHeight(),0);
	*grid3d4->atPoint(pos) = 1;
	list3d8.push_back(pos);
	switch (location87_d1e888->type)
	{
	case 10:
		if (!stringToInt(gameData87_d1e860.getEntryText("recScraplabLockedDown_g")))
			opw3_unknown72f6b0();
		break;
	case 11:
		gameData87_d1e860.setEntryText("scrReleasedSubatomizers_g",intToString(getTurn() + rng.rangeInt(15.0f,30.0f)));
		break;
	case 20:
		gameData87_d1e860.setEntryText("zioReleasedSubatomizers_g",intToString(getTurn() + rng.rangeInt(15.0f,30.0f)));
		break;
	case 23:
		gameData87_d1e860.setEntryText("warReleasedSubatomizers_g",intToString(getTurn() + rng.rangeInt(15.0f,30.0f)));
		break;
	case 33:
		if (stringToInt(gameData87_d1e860.getEntryText("frgUfdAttacked_g")) && !player->unknown5cb680(groups[10]))
		{
			gameData87_d1e860.setEntryText("frgReleasedSubatomizers_g","1");
			bool seen = false;
			vector<HEntity> *members = groups[10]->getMembers();
			for (unsigned int j = 0; j < members->size(); j++)
			{
				if (unknown463400((*members)[j]))
				{
					seen = true;
					break;
				}
			}
			if (seen)
				unknown7329f0();
			else
			{
				HEntity e = groups[10]->unknown45e250(0x4d);
				if (e.isNull())
					e = groups[10]->unknown45e250(0x4e);
				if (e.isValid())
					unknown6c65a0(e,"FRG_Optimus_Subatomizer",0);
			}
		}
		break;
	}
	if (state87_d25450.unknown000 && location87_d1e888->inRange())
	{
		if (flag87_d255b3)
			flag87_d255b3 = false;
		else
			state87_d25450.unknown69e700(0x36,0,0.0f);
	}
}
