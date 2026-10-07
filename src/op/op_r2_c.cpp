// op_r2_c: assorted functions in 0x515000-0x570000 matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names
#include <vector>
#include <string>
#include <cstddef>
using namespace std;

struct OpR2c_PropInfo
{
	char pad00[8];
	int unknown8;
};

class OpR2c_Prop
{
public:
	OpR2c_PropInfo *unknown45cb30();	// NOTE: placeholder name (ICF'd trivial getter)
};

class OpR2c_HProp
{
public:
	int ID;
	OpR2c_Prop *operator->() const;	// 0x9b64f0
};

class OpR2c_Options
{
public:
	int unknown46f4e0();	// NOTE: placeholder name
};
extern OpR2c_Options opr2c_d1e860;	// NOTE: placeholder name

struct OpR2c_GameState
{
	char pad00[8];
	int unknown8;
};

class OpR2c_HGameState
{
public:
	int ID;
	OpR2c_GameState *operator->() const;	// 0x9b7910
};
extern OpR2c_HGameState opr2c_d1e888;	// NOTE: placeholder name

string intToString(int value);
int stringToInt(const string &s);	// NOTE: placeholder name (0x405610)
void opw1_split(const string &text, char separator, vector<string> &out);	// NOTE: placeholder name (0x408700)
bool opw8_extractParenthesized(string &s, string &out);	// NOTE: placeholder name (0x436d80)
int opW9_findString(string *strings, int count, string text);	// NOTE: placeholder name (0x9cda80)
void opr2c_addCopies(vector<int> &out, int value, unsigned int count);	// NOTE: placeholder name (0x9d84a0)
extern string opr2c_d30428[4];	// NOTE: placeholder name
extern string opr2c_d323f8[7];	// NOTE: placeholder name

class OpR2c_Entity	// NOTE: placeholder name
{
public:
	char pad00[0x44];
	int unknown44;
	int unknown48;
	char pad4c[4];
	int unknown50;
	int unknown54;
	char pad58[0x3c];
	int unknown94;
	char pad98[8];
	int unknownA0;
	char padA4[0x167];
	bool unknown20B;

	int unknown457330(int id);	// NOTE: placeholder name

	bool unknown56f3f0();	// NOTE: placeholder name
	bool unknown56f460();	// NOTE: placeholder name
	bool unknown56f4c0(OpR2c_HProp prop);	// NOTE: placeholder name
	bool unknown56f7e0(OpR2c_HProp prop);	// NOTE: placeholder name
	string unknown56f520();	// NOTE: placeholder name
	string unknown56f830();	// NOTE: placeholder name
	int unknown56fda0();	// NOTE: placeholder name
};

bool OpR2c_Entity::unknown56f3f0()
{
	return unknown44 >= 6 && (unknown50 <= 8 || unknown94 == 0) && unknown54 >= 1 && unknownA0 == 0 && unknown94 != 3 && unknown94 != 2;
}

int OpR2c_Entity::unknown56fda0()
{
	int item = unknown457330(0x4a);
	if (item != 0)
	{
		return item;
	}
	item = unknown457330(0x4b);
	if (item != 0)
	{
		return item;
	}
	return 0;
}

bool OpR2c_Entity::unknown56f460()
{
	return unknown44 >= 6 && unknown48 != 2 && (unknown54 == 1 || unknown54 == 2) && unknown94 == 0 && !unknown20B;
}

bool OpR2c_Entity::unknown56f4c0(OpR2c_HProp prop)
{
	if (unknown54 == 0)
	{
		return false;
	}
	return unknown50 + (unknown94 != 0) < opr2c_d1e860.unknown46f4e0() + prop->unknown45cb30()->unknown8;
}

bool OpR2c_Entity::unknown56f7e0(OpR2c_HProp prop)
{
	if (unknown54 == 0)
	{
		return false;
	}
	return unknown50 < opr2c_d1e860.unknown46f4e0() + prop->unknown45cb30()->unknown8;
}

string OpR2c_Entity::unknown56f520()
{
	int level = -(10 - (unknown50 + (unknown94 != 0))) - 3;
	if (-opr2c_d1e888->unknown8 < level)
	{
		return "Access unavailable below " + intToString(level) + ".";
	}
	else
	{
		return "At 0b10/" + intToString(-opr2c_d1e888->unknown8) + ", security level " + intToString(level + opr2c_d1e888->unknown8 + 3) + " required.";
	}
}

string OpR2c_Entity::unknown56f830()
{
	int level = -(10 - unknown50) - 3;
	if (-opr2c_d1e888->unknown8 < level)
	{
		return "Access unavailable below " + intToString(level) + ".";
	}
	else
	{
		return "At 0b10/" + intToString(-opr2c_d1e888->unknown8) + ", security level " + intToString(level + opr2c_d1e888->unknown8 + 3) + " required.";
	}
}

class OpR2c_Config	// NOTE: placeholder name
{
public:
	char pad00[0x1b4];
	string unknown1b4;

	bool unknown56fae0(vector<int> &out);	// NOTE: placeholder name
	bool unknown56fc30(vector<int> &out);	// NOTE: placeholder name
};

bool OpR2c_Config::unknown56fae0(vector<int> &out)
{
	vector<string> tokens;
	opw1_split(unknown1b4,'|',tokens);
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		string text;
		if (opw8_extractParenthesized(tokens[i],text))
		{
			int index = opW9_findString(opr2c_d30428,4,tokens[i]);
			if (index != -1)
			{
				opr2c_addCopies(out,index,stringToInt(text));
			}
		}
	}
	return !out.empty();
}

bool OpR2c_Config::unknown56fc30(vector<int> &out)
{
	out.assign(7u,100);
	vector<string> tokens;
	opw1_split(unknown1b4,'|',tokens);
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		string text;
		if (opw8_extractParenthesized(tokens[i],text))
		{
			int index = opW9_findString(opr2c_d323f8,7,tokens[i]);
			if (index != -1)
			{
				out[index] = stringToInt(text);
			}
		}
	}
	return !out.empty();
}

bool opr2c_between(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

class OpR2c_Item	// NOTE: placeholder name
{
public:
	char pad00[0x44];
	int unknown44;
	char pad48[0x58];
	int unknownA0;
	char padA4[4];
	int unknownA8;
	char padAC[0x44];
	int unknownF0;
	char padF4[0x6c];
	int unknown160;
	char pad164[0x48];
	bool unknown1AC;

	int unknown457330(int id);	// NOTE: placeholder name
	int unknown457740();		// NOTE: placeholder name
	string unknown56fde0();		// NOTE: placeholder name
};

string OpR2c_Item::unknown56fde0()
{
	string text;
	if (unknown1AC)
	{
		text += "Fragile";
	}
	if (unknown160 != 0)
	{
		if (!text.empty())
		{
			text += ", ";
		}
		text += "Unstable (" + intToString(unknown457740()) + ")";
	}
	else if (unknownA0 != 0)
	{
		if (!text.empty())
		{
			text += ", ";
		}
		text += "Deteriorating";
	}
	else if (unknown457330(0x44))
	{
		if (!text.empty())
		{
			text += ", ";
		}
		text += "Disposable (" + intToString(unknown457330(0x44)) + ")";
	}
	else if (opr2c_between(0x7e,unknownF0,0x93))
	{
		if (unknownF0 != 0x88 || unknown44 == 0x13)
		{
			if (!text.empty())
			{
				text += ", ";
			}
			text += "Consumable";
		}
	}
	return text;
}

struct OpR2c_M9b8b60	// NOTE: placeholder name
{
	~OpR2c_M9b8b60();	// 0x9b8b60
	char data[0x10];
};

class OpY5_WeightedStrings	// NOTE: placeholder name
{
public:
	~OpY5_WeightedStrings();	// 0x55c900

	vector<string> values;
	vector<unsigned int> weights;
};

OpY5_WeightedStrings::~OpY5_WeightedStrings()
{
}

class OpR2c_Rec55c990	// NOTE: placeholder name
{
public:
	~OpR2c_Rec55c990();	// 0x55c990

	char pad00[0x20];
	vector<unsigned int> unknown20;
	vector<unsigned int> unknown30;
	vector<string> unknown40;
	OpR2c_M9b8b60 unknown50;
};

OpR2c_Rec55c990::~OpR2c_Rec55c990()
{
}

struct Point
{
	int x;
	int y;

	Point();	// 0x453b40
	Point(int x_, int y_);	// 0x46ca20
	Point(const Point &p) throw();	// 0x46ca50
	Point &unknown4099f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x4099f0)
	Point unknown409b30(const Point &other);	// NOTE: placeholder name (0x409b30)
	Point operator+(const Point &other) const;	// 0x409b60
};

class OpR2c_Effect	// NOTE: placeholder name
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name (0x503b20)
};

class OpR2c_EffectMgr	// NOTE: placeholder name
{
public:
	OpR2c_Effect *create();	// NOTE: placeholder name (0x508610)
};

extern int opr2c_caf148;	// NOTE: placeholder name
extern vector<int> opr2c_cf67c0;	// NOTE: placeholder name
extern OpR2c_EffectMgr *opr2c_effectMgr;	// NOTE: placeholder name (0xcefc50)
extern Point opr2c_effectOrigin;	// NOTE: placeholder name (0xd2e20c)

void opr2c_playEffect_55ca10(int id, const Point &from, Point *p1)	// NOTE: placeholder name
{
	if (id != opr2c_caf148)
	{
		opr2c_effectMgr->create()->init(opr2c_effectMgr,opr2c_cf67c0[id],from,opr2c_effectOrigin,p1,&opr2c_effectOrigin,0,9,0);
	}
}

void opr2c_playEffectPath_55ca70(int id, vector<Point> &path, Point *origin)	// NOTE: placeholder name
{
	if (id != opr2c_caf148)
	{
		for (int i = path.size() - 1; i >= 0; i--)
		{
			Point offset;
			opr2c_playEffect_55ca10(id,path[i],origin != NULL ? &offset.unknown4099f0(*origin,path[i].unknown409b30(path[0])) : NULL);
		}
	}
}

class OpR2c_MapView	// NOTE: placeholder name (0xcec054)
{
public:
	Point &unknown458ef0();	// NOTE: placeholder name (folded getter)
	bool inBounds(const Point &pos);	// NOTE: placeholder name (XConsole::inBounds)
};

class OpR2c_Effect2	// NOTE: placeholder name
{
public:
	void unknown50de10();	// NOTE: placeholder name
};

class OpR2c_EffectMgr2	// NOTE: placeholder name (0xcefc64)
{
public:
	OpR2c_Effect2 *unknown50fb50(OpR2c_EffectMgr2 *mgr, int type, Point *a, Point *b, Point *c, Point *d, int value);	// NOTE: placeholder name
};

extern int opr2c_caf14c;	// NOTE: placeholder name
extern vector<int> opr2c_cfe704;	// NOTE: placeholder name
extern OpR2c_MapView *opr2c_mapView;	// NOTE: placeholder name (0xcec054)
extern OpR2c_EffectMgr2 *opr2c_effectMgr2;	// NOTE: placeholder name (0xcefc64)

void opr2c_playMapEffect_55cb10(int id, const Point &pos)	// NOTE: placeholder name
{
	if (id != opr2c_caf14c)
	{
		Point at = pos + opr2c_mapView->unknown458ef0();
		if (opr2c_mapView->inBounds(at))
		{
			opr2c_effectMgr2->unknown50fb50(opr2c_effectMgr2,opr2c_cfe704[id],&at,&opr2c_effectOrigin,NULL,NULL,9)->unknown50de10();
		}
	}
}

class SoundData;
int soundPlayRelative(const Point &pos, SoundData *sound, int channel, bool noPlay);	// NOTE: name from log string (0x4ff170)
int opY3_playSound(SoundData *sound, int channel, int fade, int loopsB, int loops);	// NOTE: placeholder name (0x4ff050)

struct OpR2c_SoundRef	// NOTE: placeholder name
{
	char pad00[0x38];
	int sound;
	bool relative;
};

extern int opr2c_caf144;	// NOTE: placeholder name
extern vector<SoundData *> opr2c_sounds;	// NOTE: placeholder name (0xcfd2ec)

bool opr2c_playSoundRef_55cb90(OpR2c_SoundRef *ref, const Point &pos)	// NOTE: placeholder name
{
	if (ref->sound != opr2c_caf144)
	{
		if (ref->relative)
		{
			soundPlayRelative(pos,opr2c_sounds[ref->sound],-1,false);
		}
		else
		{
			opY3_playSound(opr2c_sounds[ref->sound],-1,0,0,0);
		}
		return true;
	}
	return false;
}

class OpR2c_Group	// NOTE: placeholder name
{
public:
	int getType();	// NOTE: placeholder name (ICF'd trivial getter)
};

class OpR2c_HGroup	// NOTE: placeholder name
{
public:
	int ID;
	OpR2c_Group *operator->() const;	// 0x9b7250
};

class OpR2c_Entity2	// NOTE: placeholder name
{
public:
	const Point &getPosition();	// 0x45a4a0
	OpR2c_HGroup getGroup();	// 0x45a3f0
};

class OpR2c_HEntity	// NOTE: placeholder name
{
public:
	int ID;
	OpR2c_Entity2 *operator->() const;	// 0x9b6570
};

class OpR2c_Map	// NOTE: placeholder name (0xcefc4c)
{
public:
	OpR2c_HEntity getPlayer();
	bool isKnown(int x, int y);	// 0x463130
	bool isVisible(int x, int y);	// 0x463190
	bool unknown463790(OpR2c_HEntity e, int x, int y);	// NOTE: placeholder name
};
extern OpR2c_Map *opr2c_world;	// NOTE: placeholder name

int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name (0x40a3f0)

bool opr2c_playSoundNearest_55cc00(OpR2c_SoundRef *ref, vector<Point> &points)	// NOTE: placeholder name
{
	if (ref->sound == opr2c_caf144 || points.empty())
	{
		return false;
	}
	int best = 0;
	int bestDistance = OpQ1_distanceCeil_40a3f0(opr2c_world->getPlayer()->getPosition(),points[best]);
	for (unsigned int i = 1; i < points.size(); i++)
	{
		int distance = OpQ1_distanceCeil_40a3f0(opr2c_world->getPlayer()->getPosition(),points[i]);
		if (distance < bestDistance)
		{
			bestDistance = distance;
			best = i;
		}
	}
	return opr2c_playSoundRef_55cb90(ref,points[best]);
}

bool opr2c_checkMapState_55ccf0(int x, int y, OpR2c_HEntity e, int mode)	// NOTE: placeholder name
{
	switch (mode)
	{
		break;
		case 1:
			if (e->getGroup()->getType() == 0 && !opr2c_world->isKnown(x,y))
			{
				return false;
			}
			break;
		case 2:
			if (e->getGroup()->getType() == 0 && !opr2c_world->isVisible(x,y))
			{
				return false;
			}
			break;
		case 3:
			if (e->getGroup()->getType() == 0 && !opr2c_world->unknown463790(e,x,y))
			{
				return false;
			}
			break;
	}
	return true;
}

class OpR2c_HHandle	// NOTE: placeholder name
{
public:
	int ID;
	bool isNull() const;	// ICF'd with HProp::isNull
};

class OpR2c_HEnt3	// NOTE: placeholder name
{
public:
	int ID;
	bool isNull() const;	// ICF'd with HProp::isNull
	class OpR2c_Ent3 *operator->() const;	// 0x9b6570
};

class OpR2c_Ent3	// NOTE: placeholder name
{
public:
	vector<Point> *getFootprint();	// NOTE: placeholder name (0x45d1a0)
	int unknown5c7fc0(OpR2c_HEnt3 other);	// NOTE: placeholder name
};

class OpR2c_Cell	// NOTE: placeholder name
{
public:
	OpR2c_HEnt3 getEntity();	// 0x45d4c0?
	OpR2c_HHandle getProp();	// 0x45d550
	vector<int> *unknown463950();	// NOTE: placeholder name (Map::unknown463950)
};

template <class T>
class OpR2c_Array2D	// NOTE: placeholder name
{
public:
	T &operator()(int x, int y);	// 0x9ceda0
};
extern OpR2c_Array2D<OpR2c_Cell *> opr2c_cells;	// NOTE: placeholder name (0xcfd44c)

struct OpR2c_Rule	// NOTE: placeholder name
{
	char pad00[0x3c];
	int unknown3c;
	char pad40[0x70];
	bool unknownB0;
	char padB1[3];
	int unknownB4;
};

bool opr2c_containsPoint_9d0ce0(vector<Point> &v, Point p);	// NOTE: placeholder name (0x9d0ce0)

bool opr2c_checkCell_55ce00(int x, int y, OpR2c_HEnt3 e, OpR2c_Rule *rule)	// NOTE: placeholder name
{
	switch (rule->unknown3c)
	{
		case 0x3e:
		case 0x42:
		case 0x4e:
		case 0x53:
		case 0x58:
			if (opr2c_cells(x,y)->getEntity().isNull())
			{
				return false;
			}
			break;
		case 0x3f:
		case 0x43:
		case 0x4f:
		case 0x54:
		case 0x59:
			if (opr2c_cells(x,y)->getProp().isNull())
			{
				return false;
			}
			break;
		case 0x40:
		case 0x44:
		case 0x50:
		case 0x55:
		case 0x5a:
			if (opr2c_cells(x,y)->unknown463950()->empty())
			{
				return false;
			}
			break;
	}
	if (!rule->unknownB0 && e.operator->() != NULL && opr2c_containsPoint_9d0ce0(*e->getFootprint(),Point(x,y)))
	{
		return false;
	}
	switch (rule->unknownB4)
	{
		break;
		case 1:
			if (e.operator->() == NULL)
			{
				return false;
			}
			if (e->unknown5c7fc0(opr2c_cells(x,y)->getEntity()) != 0)
			{
				return false;
			}
			break;
		case 2:
			if (e.operator->() == NULL)
			{
				return false;
			}
			if (e->unknown5c7fc0(opr2c_cells(x,y)->getEntity()) != 1)
			{
				return false;
			}
			break;
		case 3:
			if (e.operator->() == NULL)
			{
				return false;
			}
			if (e->unknown5c7fc0(opr2c_cells(x,y)->getEntity()) != 2)
			{
				return false;
			}
			break;
		case 4:
			if (e.operator->() == NULL)
			{
				return false;
			}
			if (e->unknown5c7fc0(opr2c_cells(x,y)->getEntity()) == 0)
			{
				return false;
			}
			break;
		case 5:
			if (e.operator->() == NULL)
			{
				return false;
			}
			if (e->unknown5c7fc0(opr2c_cells(x,y)->getEntity()) == 1)
			{
				return false;
			}
			break;
		case 6:
			if (e.operator->() == NULL)
			{
				return false;
			}
			if (e->unknown5c7fc0(opr2c_cells(x,y)->getEntity()) == 2)
			{
				return false;
			}
			break;
	}
	return true;
}

class OpR2c_HEnt4	// NOTE: placeholder name
{
public:
	int ID;
	class OpR2c_Ent4 *operator->() const;	// 0x9b6570
	bool operator==(OpR2c_HEnt4 other) const;
};

class OpR2c_Ent4	// NOTE: placeholder name
{
public:
	int getSize();	// NOTE: placeholder name (0x45a360)
};

class OpR2c_Cell4	// NOTE: placeholder name
{
public:
	OpR2c_HEnt4 getEntity();	// 0x45d250
};

template <class T>
class OpR2c_Array2D4	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern OpR2c_Array2D4<OpR2c_Cell4 *> opr2c_cells4;	// NOTE: placeholder name (0xcfd44c)

void opr2c_eraseStep_9d7300(vector<Point> &v, int &index);	// NOTE: placeholder name

void opr2c_removeSharedCells_55d180(OpR2c_Rule *rule, vector<Point> &points)	// NOTE: placeholder name
{
	switch (rule->unknown3c)
	{
		case 0x3e:
		case 0x42:
		case 0x4e:
		case 0x53:
		case 0x58:
			for (unsigned int i = 0; i < points.size(); i++)
			{
				OpR2c_HEnt4 e = opr2c_cells4(points[i])->getEntity();
				if (e->getSize() > 1)
				{
					for (unsigned int j = 0; j < points.size(); j++)
					{
						if (i != j && opr2c_cells4(points[j])->getEntity() == e)
						{
							opr2c_eraseStep_9d7300(points,(int &)j);
						}
					}
				}
			}
			break;
	}
}

class OpR2c_HI	// NOTE: placeholder name (HItem)
{
public:
	int ID;
	OpR2c_HI();	// ICF'd with HProp::HProp
	bool isValid() const;
};

class OpR2c_HP	// NOTE: placeholder name (HProp)
{
public:
	int ID;
	OpR2c_HP();	// ICF'd with HProp::HProp
};


class OpR2c_Ent5	// NOTE: placeholder name
{
public:
	void unknown45b1e0(int value);	// NOTE: placeholder name
	void unknown45b1b0(int value);	// NOTE: placeholder name
};

class OpR2c_HEnt5	// NOTE: placeholder name
{
public:
	int ID;
	OpR2c_HEnt5();	// ICF'd with HProp::HProp
	OpR2c_Ent5 *operator->() const;	// 0x9b6570
};

class OpR2c_Cell5	// NOTE: placeholder name
{
public:
	OpR2c_HEnt5 getEntity();	// 0x45d250
	OpR2c_HP getProp();		// 0x45d550
	vector<OpR2c_HI> *unknown463950();	// NOTE: placeholder name
};

template <class T>
class OpR2c_Array2D5	// NOTE: placeholder name
{
public:
	T &operator()(const Point &p);	// 0x9ced70
};
extern OpR2c_Array2D5<OpR2c_Cell5 *> opr2c_cells5;	// NOTE: placeholder name (0xcfd44c)

struct OpR2c_MapEventRule	// NOTE: recovered event-bridge input; broader record semantics remain incomplete
{
	char pad00[0x3c];
	int eventType;
	char pad40[0x50];
	int unknown90;
	int unknown94;
};
static_assert(offsetof(OpR2c_MapEventRule, eventType) == 0x3c, "eventType offset");
static_assert(sizeof(OpR2c_MapEventRule) == 0x98, "event-rule size");

struct OpR2c_MapRecord;
bool opr2c_turnUpdate_51da30(vector<OpR2c_MapRecord *> *records, int eventType, OpR2c_HEnt5 entity, OpR2c_HP prop, OpR2c_HI item, const Point *directPosition, int flag);	// NOTE: placeholder name (BS::turnUpdate_51da30)

void opr2c_applyRule_55d2b0(OpR2c_MapEventRule *rule, OpR2c_HEnt5 e, vector<OpR2c_MapRecord *> *records, const Point &pos, int flag, OpR2c_HI item)	// NOTE: placeholder name
{
	if (flag == 0)
	{
		if (rule->unknown90 != 0)
		{
			e->unknown45b1e0(rule->unknown90);
		}
		if (rule->unknown94 != 0)
		{
			e->unknown45b1b0(rule->unknown94);
		}
	}
	switch (rule->eventType)
	{
		case 0x3e:
		case 0x42:
		case 0x4e:
		case 0x53:
		case 0x58:
			opr2c_turnUpdate_51da30(records,rule->eventType,opr2c_cells5(pos)->getEntity(),OpR2c_HP(),OpR2c_HI(),0,flag);
			break;
		case 0x3f:
		case 0x43:
		case 0x4f:
		case 0x54:
		case 0x59:
			opr2c_turnUpdate_51da30(records,rule->eventType,OpR2c_HEnt5(),opr2c_cells5(pos)->getProp(),OpR2c_HI(),0,flag);
			break;
		case 0x40:
		case 0x44:
		case 0x50:
		case 0x55:
		case 0x5a:
		{
			opr2c_turnUpdate_51da30(records,rule->eventType,OpR2c_HEnt5(),OpR2c_HP(),item.isValid() ? item : opr2c_cells5(pos)->unknown463950()->front(),0,flag);
			break;
		}
		case 0x41:
		case 0x45:
		case 0x51:
		case 0x56:
		case 0x5b:
			opr2c_turnUpdate_51da30(records,rule->eventType,OpR2c_HEnt5(),OpR2c_HP(),OpR2c_HI(),&pos,flag);
			break;
	}
}

extern string opr2c_d293c0[];	// NOTE: placeholder name
extern vector<int> opr2c_cf4830;	// NOTE: placeholder name

class OpR2c_ItemRec	// NOTE: placeholder name
{
public:
	string getPrefixedName(int *length);	// 0x456fd0 NOTE: placeholder name
	string unknown55e9c0(bool flag, int *length);	// NOTE: placeholder name

	int unknown0;
	char pad04[0x40];
	int unknown44;
	char pad48[0x4c];
	int unknown94;
};

string OpR2c_ItemRec::unknown55e9c0(bool flag, int *length)
{
	if (length != NULL)
	{
		*length = 0;
	}
	if (opr2c_cf4830[unknown0] == 0 && !flag)
	{
		switch (unknown94)
		{
			case 0:
				return "Unknown " + opr2c_d293c0[unknown44];
			case 1:
				return "Prototype " + opr2c_d293c0[unknown44];
			case 2:
				return "Construct " + opr2c_d293c0[unknown44];
			case 3:
				return "Alien " + opr2c_d293c0[unknown44];
		}
	}
	return getPrefixedName(length);
}
