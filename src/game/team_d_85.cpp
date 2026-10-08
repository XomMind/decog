// team_d_85: BS member 0x748a00: the Architect warps to the farthest exit area (dodge remarks when the
// attack source is known, subspace effect, re-placed with its data core and reconstructor).
// NOTE: class layouts are partial; member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

int stringToInt(const string &s);

struct Point
{
	int x;
	int y;
};

struct Area85	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;

	Point center_40b620();	// NOTE: placeholder name
};
extern vector<Area85> exits85_d1ec74;	// NOTE: placeholder name
extern vector<int> list85_d1ec84;		// NOTE: placeholder name
extern vector<int> list85_d1ec94;		// NOTE: placeholder name

class OpV4c_View
{
public:
	const int *getConst(Point *p);
};

class HProp
{
public:
	int ID;
	HProp();
};

struct EntityRec85;	// NOTE: placeholder name

class EntityAI
{
public:
	int unknown5b4710(class HEntity e, int a, int b, int c, int d);	// NOTE: placeholder name
};

class Entity
{
public:
	int getFaction();
	Point &getPosition();
	EntityRec85 *getRecord();		// NOTE: placeholder name (folded getter)
	const string &getName();		// NOTE: placeholder name (folded getter)
	void unknown637bb0();			// NOTE: placeholder name
	EntityAI *getAI();
};

class HEntity
{
public:
	int ID;
	HEntity();	// NOTE: folded with HProp::HProp
	bool isValid() const;
	Entity *operator->() const;
};

class Group85	// NOTE: placeholder name
{
public:
	vector<HEntity> *getMembers();	// NOTE: folded getter
};

class HGroup
{
	int ID;
public:
	Group85 *operator->() const;	// NOTE: folded (OpC_Handle::get230)
};

class OpV1_GameData
{
public:
	const string &getEntryText(const string &key);
	void setEntryText(const string &key, const string &text);
};
extern OpV1_GameData gameData85_d1e860;	// NOTE: placeholder name

void opW5_message(int type, HEntity entity, const string &text, int value);	// NOTE: placeholder name
void opW5_message(int type, HProp prop, const string &text, int value);	// NOTE: placeholder name
void message85_5141b0(int id, const string *a, const string *b, int c, HEntity d, int e);	// NOTE: placeholder name
bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);
int OpS8b_Fn9d4500(vector<int> &v);

class EffectObj85	// NOTE: placeholder name (object initialized by 0x503b20)
{
public:
	void init(void *owner, int type, const Point &from, const Point &to, Point *p1, Point *p2, void *data, int a, int b);	// NOTE: placeholder name
};

class EndObjB
{
public:
	EffectObj85 *unknown508610();	// NOTE: placeholder name
};
extern EndObjB *endObj85_cefc50;	// NOTE: placeholder name
extern Point point85_d2e20c;		// NOTE: placeholder name

struct Source85	// NOTE: placeholder name and layout (attack source)
{
	char	pad00[8];
	string	name;	// +0x08
};

class BS	// NOTE: placeholder layout
{
public:
	char	pad000[0x66c];
	HEntity	player;	// +0x66c

	HGroup unknown463890(int i);	// NOTE: placeholder name
	bool unknown4631f0(HEntity e);	// NOTE: placeholder name
	HEntity placeEntity(EntityRec85 *record, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);
	HProp giveItem(const string &itemName, HEntity entity, bool a, bool b);
	bool unknown748a00(OpV4c_View *view, Source85 *source);	// NOTE: placeholder name
};

bool BS::unknown748a00(OpV4c_View *view, Source85 *source)
{
	HEntity first;
	vector<HEntity> *v = unknown463890(0xc)->getMembers();
	for (unsigned int i = 0; i < v->size(); i++)
	{
		if ((*v)[i]->getFaction() == 0x60)
		{
			first = (*v)[i];
			break;
		}
	}
	if (first.isValid())
	{
		if (view && !*view->getConst(&first->getPosition()))
			return false;
		EntityRec85 *ok = first->getRecord();
		vector<int> x;
		for (unsigned int j = 0; j < exits85_d1ec74.size(); j++)
			x.push_back(OpQ1_distanceCeil_40a3f0(first->getPosition(),exits85_d1ec74[j].center_40b620()));
		if (!x.empty())
		{
			int id = OpS8b_Fn9d4500(x);
			if (unknown4631f0(first))
			{
				if (view && !stringToInt(gameData85_d1e860.getEntryText("ac0ArchitectDodgedTerminator_g")))
				{
					gameData85_d1e860.setEntryText("ac0ArchitectDodgedTerminator_g","1");
					string text = first->getName() + ": \"I'm all too familiar with what that does.\"";
					opW5_message(0x322,first,text,0);
				}
				if (source)
				{
					if (source->name == "L-Cannon")
					{
						if (!stringToInt(gameData85_d1e860.getEntryText("ac0ArchitectDodgedLCannon_g")))
						{
							gameData85_d1e860.setEntryText("ac0ArchitectDodgedLCannon_g","1");
							string text = first->getName() + ": \"I'm aware you stole the capacitor, you know...\"";
							opW5_message(0x322,first,text,0);
						}
					}
					else
					{
						if (!stringToInt(gameData85_d1e860.getEntryText("ac0ArchitectDrainedLCannon_g")))
						{
							gameData85_d1e860.setEntryText("ac0ArchitectDrainedLCannon_g","1");
							string text = first->getName() + ": \"You actually fired it without the capacitor?!\"";
							opW5_message(0x322,first,text,0);
						}
						return false;
					}
				}
				string w = first->getName() + " warps through subspace.";
				opW5_message(0x320,HProp(),w,0);
				do
				{
					message85_5141b0(0x228,0,0,0,first,0);
				} while (0);
				int h;
				if (OpU8a_lookup2("Teleport_Architect",&h))
					endObj85_cefc50->unknown508610()->init(endObj85_cefc50,h,first->getPosition(),point85_d2e20c,0,0,0,9,0);
			}
			first->unknown637bb0();
			Point vec = exits85_d1ec74[id].center_40b620();
			first = placeEntity(ok,vec,0xc,false,0x22,0xe,false);
			first->getAI()->unknown5b4710(player,-2,1,0,0);
			giveItem("Architect Data Core",first,false,false);
			giveItem("Hpw. Transdimensional Reconstructor",first,false,false);
			list85_d1ec84.clear();
			list85_d1ec94.clear();
			return true;
		}
	}
	return false;
}
