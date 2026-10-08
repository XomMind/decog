// op_bs_resistance: BS::unknown6efb90 (0x6efb90), reacts to the player attacking the resistance: flags the
// map, turns the locals hostile and (for the Warlord) carves a staging area at the map edge and spawns the
// Warlord, God Mode and their escorts (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
};
struct Pos : Point
{
	Pos(int x_, int y_) throw();	// 0x46ca20
};
struct Rect
{
	int x;
	int y;
	int w;
	int h;
	Rect(int x_, int y_, int w_, int h_) throw();	// 0x456940
};
struct OpQ1_Box	// NOTE: placeholder name
{
	int x1;
	int y1;
	int x2;
	int y2;
	OpQ1_Box(int x1_, int y1_, int x2_, int y2_) throw();	// 0x40b1e0
};

class OpBR_AI	// NOTE: placeholder name (EntityAI)
{
public:
	void setFollowEntity(class HEntity e, int flag);	// NOTE: placeholder name (0x5b2f80)
};
class Entity
{
public:
	const Point &getPosition();	// 0x45a4a0
	OpBR_AI *getAI_45b590();	// NOTE: placeholder name
	int getFaction();	// 0x45a2c0
	int unknown5c7d30();	// NOTE: placeholder name
	void unknown637bb0();	// NOTE: placeholder name
};
class HEntity
{
public:
	int ID;
	HEntity();	// 0x9b6590
	Entity *operator->() const;	// 0x9b6570
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x9b65d0
};

class Prop
{
public:
	bool isPassableFor(HEntity e);	// 0x65e1d0
	void setPos_41a800(int x, int y);	// NOTE: placeholder name
};
class HProp
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	Prop *get22c() const;	// NOTE: placeholder name (0x9b64f0)
};
class OpBR_PropHandle { public: int ID; };	// NOTE: placeholder name
class Cell
{
public:
	HEntity getEntity();	// 0x45d250
	HProp getProp();	// 0x45d550
	int getTerrain_41a6e0();	// NOTE: placeholder name (folded getter)
	bool setProp_45df50(OpBR_PropHandle prop);	// NOTE: placeholder name
};
class OpBR_Grid	// NOTE: placeholder name (0xcfd44c)
{
public:
	Cell **atPoint(Point &p);	// NOTE: placeholder name
	Cell **at(int x, int y);	// NOTE: placeholder name
	int getWidth();	// NOTE: placeholder name
	int getHeight();	// NOTE: placeholder name
};
extern OpBR_Grid opBR_cells_cfd44c;	// NOTE: placeholder name

struct OpBR_PropRecord;	// NOTE: placeholder name
class OpBR_Factory	// NOTE: placeholder name (0xcefaa8)
{
public:
	OpBR_PropHandle createE(OpBR_PropRecord *record);	// NOTE: placeholder name (0x793360)
};
extern OpBR_Factory *opBR_factory_cefaa8;	// NOTE: placeholder name
extern vector<OpBR_PropRecord *> opBR_propRecords_cf35b0;	// NOTE: placeholder name

class OpBR_GameData	// NOTE: placeholder name (GameData at 0xd1e860)
{
public:
	const string &getEntryText(const string &key);	// NOTE: placeholder name (0x46f6d0)
	void setEntryText(const string &key, const string &value);	// NOTE: placeholder name (0x46f700)
};
extern OpBR_GameData opBR_gameData;	// NOTE: placeholder name
extern int opBR_current_d1e888;	// NOTE: placeholder name
extern int opBR_revisionMap_d1ebe0;	// NOTE: placeholder name
extern int opBR_warlordMap_d1ebd8;	// NOTE: placeholder name

struct OpR6_KA_44_0	// NOTE: same declaration as src/op/op_r6_ka.cpp (shares vector<>::clear 0x9b7c50)
{
	int m0;
	int m4;
	int m8;
	int m12;
	int m16;
	int m20;
	int m24;
	int m28;
	int m32;
	int m36;
	int m40;
	OpR6_KA_44_0 &operator=(const OpR6_KA_44_0 &o);
};

class OpBR_Overmind	// NOTE: placeholder name (Overmind at 0xcf6428)
{
public:
	void unknown68d6d0(bool flag);	// NOTE: placeholder name
};
extern OpBR_Overmind opBR_overmind_cf6428;	// NOTE: placeholder name
extern bool opBR_hostile_cf65bc[4];	// NOTE: placeholder name

class RNG
{
public:
	int rangeInt(float a, float b);	// 0x406d70
};
extern RNG rng;

extern int opBR_wallTerrain_cefb9c;	// NOTE: placeholder name
extern int opBR_d2c46c;	// NOTE: placeholder name
extern bool opBR_cf4a00;	// NOTE: placeholder name
extern const float opBR_two_c36edc;	// NOTE: placeholder name (2.0)
extern const float opBR_tenth_c36f8c;	// NOTE: placeholder name (0.1)
extern const char opBR_one_bef658[];	// NOTE: placeholder name ("1")
extern const char opBR_one_bef674[];	// NOTE: placeholder name ("1")
extern const char opBR_machinesHF_bef740[];	// NOTE: placeholder name ("RES_Attack_Machines_HF")
extern const char opBR_machinesHF_bef7f8[];	// NOTE: placeholder name ("RES_Attack_Machines_HF")

int stringToInt(const string &s);	// 0x405610
int OpQ1_distanceCeil_40a3f0(const Point &a, const Point &b);	// NOTE: placeholder name
void opt4_setTerrain(int x, int y, int terrain);	// NOTE: placeholder name
void opBR_logPhrase_5141b0(int index, string *a, string *b, string *c, HEntity d, int e);	// NOTE: placeholder name
template <class T> bool OpQ5_findByName(vector<T *> &list, const string &name, T *&out);	// NOTE: placeholder name

class BS	// NOTE: placeholder layout
{
public:
	void unknown6efb90();	// NOTE: placeholder name
	bool unknown73cd10();	// NOTE: placeholder name
	bool unknown73cfb0();	// NOTE: placeholder name
	void unknown6c38a0(Rect *rect, const vector<Point> *points, float threshold, int value);	// NOTE: placeholder name
	HEntity unknown6c5dc0(const string &name, const Point &position, int groupIndex, bool unknown18, int aiMode1, int aiMode2, bool forced);	// NOTE: placeholder name
	void unknown6c65a0(HEntity e, const string &text, int value);	// NOTE: placeholder name
	HEntity unknown715230(int group, int faction);	// NOTE: placeholder name
	bool reinforce73d320(bool local, bool existing, bool limited, const Point *at);	// NOTE: placeholder name

	char pad000[0x584];
	vector<Point> locals;	// +0x584, NOTE: placeholder name
	vector<HEntity> unknown594;	// +0x594
	vector<OpR6_KA_44_0> unknown5a4;	// +0x5a4
	int unknown5b4;	// +0x5b4
	char pad5b8[0x66c - 0x5b8];
	HEntity player;	// +0x66c
	char pad670[0x8b4 - 0x670];
	vector<OpQ1_Box> stagingAreas;	// +0x8b4, NOTE: placeholder name
	int warlordGroup;	// +0x8c4, NOTE: placeholder name
};

void BS::unknown6efb90()
{
	if (unknown73cd10())
	{
		opBR_gameData.setEntryText("resRevisionAttacked_g",opBR_one_bef658);
		opBR_revisionMap_d1ebe0 = opBR_current_d1e888;
		for (unsigned int i = 0; i < locals.size(); i++)
		{
			if ((*opBR_cells_cfd44c.atPoint(locals[i]))->getEntity().isValid() && (*opBR_cells_cfd44c.atPoint(locals[i]))->getEntity()->getFaction() == 0x1a)
				(*opBR_cells_cfd44c.atPoint(locals[i]))->getEntity()->unknown637bb0();
		}
		locals.clear();
		unknown594.clear();
		unknown5a4.clear();
		unknown5b4 = -1;
	}
	else if (unknown73cfb0())
	{
		opBR_gameData.setEntryText("resWarlordAttacked_g",opBR_one_bef674);
		opBR_warlordMap_d1ebd8 = opBR_current_d1e888;
		do
		{
			opBR_logPhrase_5141b0(0x1c4,0,0,0,HEntity(),0);
		} while (0);
		opBR_hostile_cf65bc[0] = true;
		opBR_hostile_cf65bc[1] = true;
		opBR_hostile_cf65bc[2] = true;
		opBR_hostile_cf65bc[3] = true;
		opBR_overmind_cf6428.unknown68d6d0(false);
		for (unsigned int i = 0; i < locals.size(); i++)
		{
			if ((*opBR_cells_cfd44c.atPoint(locals[i]))->getEntity().isValid() && (*opBR_cells_cfd44c.atPoint(locals[i]))->getEntity()->getFaction() == 0x1a)
				(*opBR_cells_cfd44c.atPoint(locals[i]))->getEntity()->unknown637bb0();
		}
		locals.clear();
		unknown594.clear();
		unknown5a4.clear();
		unknown5b4 = -1;
		int minX = 10;
		int tile = 3;
		int height = 3;
		bool flag = false;
		for (int attempt = 0; attempt < 3; attempt++)
		{
			for (int tries = 0; tries < 2000; tries++)
			{
				Pos spot(-1,rng.rangeInt(opBR_two_c36edc,opBR_cells_cfd44c.getHeight() - 6));
				for (int x = 0; x < opBR_cells_cfd44c.getWidth(); x++)
				{
					for (int y = spot.y; y < spot.y + 3; y++)
					{
						if ((*opBR_cells_cfd44c.at(x,y))->getTerrain_41a6e0() == opBR_wallTerrain_cefb9c)
						{
							spot.x = x;
							goto found;
						}
					}
				}
found:
				if (OpQ1_distanceCeil_40a3f0(player->getPosition(),spot) <= player->unknown5c7d30() || OpQ1_distanceCeil_40a3f0(player->getPosition(),Pos(spot.x,spot.y + 2)) <= player->unknown5c7d30())
					spot.x = -1;
				if (spot.x < 10)
					spot.x = -1;
				if (spot.x != -1)
				{
					for (int y = spot.y; y < spot.y + 3; y++)
					{
						if (((*opBR_cells_cfd44c.at(spot.x,y))->getProp().isValid() && !(*opBR_cells_cfd44c.at(spot.x,y))->getProp().get22c()->isPassableFor(HEntity())) || (*opBR_cells_cfd44c.at(spot.x,y))->getEntity().isValid())
						{
							spot.x = -1;
							break;
						}
					}
					if (spot.x != -1)
					{
						stagingAreas.push_back(OpQ1_Box(0,spot.y,0,spot.y + 2));
						for (int x = 0; x <= spot.x; x++)
						{
							for (int y = spot.y; y < spot.y + 3; y++)
								opt4_setTerrain(x,y,opBR_wallTerrain_cefb9c);
						}
						unknown6c38a0(&Rect(0,spot.y,spot.x + 1,3),0,opBR_tenth_c36f8c,opBR_d2c46c);
						OpBR_PropRecord *p;
						if (OpQ5_findByName(opBR_propRecords_cf35b0,"RES_Staging_Area",p))
						{
							for (int x = stagingAreas.back().x1; x <= stagingAreas.back().x2; x++)
							{
								for (int y = stagingAreas.back().y1; y <= stagingAreas.back().y2; y++)
								{
									if ((*opBR_cells_cfd44c.at(x,y))->setProp_45df50(opBR_factory_cefaa8->createE(p)))
										(*opBR_cells_cfd44c.at(x,y))->getProp().get22c()->setPos_41a800(x,y);
								}
							}
						}
						warlordGroup = stringToInt(opBR_gameData.getEntryText("warAttackedLocals_g")) ? 5 : 9;
						HEntity borebot = unknown6c5dc0("Borebot",Pos(spot.x - 2,spot.y),warlordGroup,true,0x22,0xe,false);
						borebot.isNull();
						if (false) {}
						if (borebot.isValid())
						{
							for (int i = 0; i < 2; i++)
							{
								HEntity samaritan = unknown6c5dc0("Samaritan",Pos(spot.x - 3,spot.y),warlordGroup,true,0x22,0xe,false);
								if (samaritan.isValid())
									samaritan->getAI_45b590()->setFollowEntity(borebot,0);
							}
						}
						if (!flag)
						{
							HEntity first = unknown6c5dc0("Warlord",Pos(spot.x - 4,spot.y),warlordGroup,true,0x22,0xe,false);
							HEntity found = unknown6c5dc0("God_Mode",Pos(spot.x - 4,spot.y),warlordGroup,true,0x22,0xe,false);
							if (first.isNull() || found.isNull())
								goto reinforce;
							if (!opBR_cf4a00)
							{
								unknown6c65a0(first,warlordGroup == 9 ? "RES_Warlord_Dialogue" : "RES_Warlord_Dialogue2",0);
								unknown6c65a0(first,warlordGroup == 9 ? "RES_Warlord_Dialog_End" : "RES_Warlord_Dialog2_End",0);
							}
							unknown6c65a0(first,opBR_machinesHF_bef740,0);
							unknown6c65a0(first,"RES_Warlord_Kills",0);
							unknown6c65a0(first,"WAR_Warlord_Death",0);
							unknown6c65a0(first,"RES_Warlord_Reinforce",0);
							HEntity h = unknown715230(2,0x5e);
							if (h.isValid() || opBR_cf4a00)
								unknown6c65a0(first,"RES_Warlord_Sigix_Check",0);
							unknown6c65a0(found,stringToInt(opBR_gameData.getEntryText("enemiesWithArchitect_g")) ? "RES_God_Mode_Hack_Bad" : "RES_God_Mode_Hack_Good",0);
							unknown6c65a0(found,opBR_machinesHF_bef7f8,0);
							if (borebot.isValid())
								found->getAI_45b590()->setFollowEntity(borebot,0);
							first->getAI_45b590()->setFollowEntity(found,0);
							for (int i = 0; i < 2; i++)
							{
								HEntity knight = unknown6c5dc0("Knight",first->getPosition(),warlordGroup,true,0x22,0xe,false);
								if (knight.isValid())
									knight->getAI_45b590()->setFollowEntity(first,0);
							}
							flag = true;
						}
reinforce:
						reinforce73d320(true,true,false,NULL);
						break;
					}
				}
			}
		}
	}
}
