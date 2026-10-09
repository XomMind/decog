// showTransmission (exe 0x8f58f0, called from BS::turnUpdate): positions and opens a speaker transmission,
// including the A0-MCA build analysis for AUTO_SCR_DATA_CENTER.
// NOTE: placeholder names throughout (D2f* types are partial layouts); the function name comes from its log string.
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos &set_46ca50(const Pos &pos);	// NOTE: placeholder name (assignment, ICF-folded with the Point copy ctor 0x46ca50)
	Pos &operator+=(const Pos &pos);	// 0x409a30
	Pos add(const Pos &pos) const;	// NOTE: placeholder name
};

struct D2fRange { char pad[0x2c]; int type; int count30; };	// NOTE: placeholder layout
struct D2fItemData	// NOTE: placeholder layout
{
	char pad000[0x120];
	int unknown120;
	char pad124[4];
	int damageType;
	char pad12c[0x158 - 0x12c];
	int unknown158;
	char pad15c[0x1a0 - 0x15c];
	D2fRange *range;
};

class D2fItem
{
public:
	int getType();
	int slot4578a0();	// NOTE: placeholder name
	int kind457880();	// NOTE: placeholder name
	int unknown457b30();
	int unknown577790();
	int energy5788e0();	// NOTE: placeholder name
	int matter5789c0();	// NOTE: placeholder name
	D2fItemData *data();	// NOTE: placeholder name
	string getName(int a, int b);	// 0x571db0
	const string &name457860();	// NOTE: placeholder name
};

class HItem
{
public:
	int ID;
	HItem() throw();	// 0x9b6590
	bool isValid() const;
	bool isNull() const;
	D2fItem *operator->() const;	// 0x9b65b0
};

class D2fEntity
{
public:
	const Pos &getPosition();
	const string &name();	// NOTE: placeholder name (ICF'd getter)
	int getSize();
	Pos pos45a4c0();	// NOTE: placeholder name
	void unknown5cede0(int *a, int *b);
	int unknown5d1390();
	int unknown5c8cb0();
	int unknown5d1ee0();
	int unknown5d14d0(int type, int b);
	int unknown5d15a0(int a);
	HItem unknown5d2380(int slot);
	int unknown5d1070();
	float unknown5ca4f0();
	float unknown5d1e40();
	bool unknown5d26e0(int type);
	int unknown5ca960();
	int unknown5ca8d0();
	int unknown5d1da0();
	int unknown5cca00();
	vector<HItem> *getInventoryList();
	int unknown5ccb50(HItem item);
	int getRoomCount(int type);
	int unknown5cba50();
	int unknown5d7320(vector<HItem> *items, int b);
	int unknown5d6d80(vector<HItem> *items, class HEntity target);
	int unknown5ca670();
};

class HEntity
{
public:
	int ID;
	HEntity() throw();	// 0x9b6590
	D2fEntity *operator->() const;	// 0x9b6570
};

class XConsole
{
public:
	bool inBounds(const Pos &pos);
	int getHeight();
	Pos getPos();
};

class D2fCMap : public XConsole	// NOTE: placeholder name (CMap at 0xcec054)
{
public:
	const Pos &offset458ef0();	// NOTE: placeholder name
	void center8069e0(Pos pos, bool flag);	// NOTE: placeholder name
};
extern D2fCMap *d2f_cec054;

class D2fMap { public: HEntity getPlayer(); };
extern D2fMap *d2f_cefc4c;

struct D2fRecord { int unknown0; string name; int type; };	// NOTE: placeholder layout
extern vector<D2fRecord*> d2f_cf3a20;

class D2fPlayerData { public: bool field46dd90(); void unknown77fbc0(int id); };
extern D2fPlayerData d2f_cf45d8;
class D2fStats { public: void add472b90(unsigned int id, int value); int unknown472c70(int id); };
extern D2fStats d2f_d2c658;
class D2fLocation { public: int unknown0; int type; };
class HLocation { public: int ID; D2fLocation *operator->() const; };
extern HLocation d2f_d1e888;
class D2fGameData { public: void setEntryText(const string &key, const string &value); };
extern D2fGameData d2f_d1e860;

class D2fTransmission	// NOTE: placeholder name (CTransmission, size 0x9c)
{
public:
	D2fTransmission(XConsole *parent, const Pos &pos, HEntity speaker, int index, int side, const vector<string> &lines);
	char pad[0x9c];
};
extern XConsole *d2f_cec034;

extern vector<string> d2f_d257c0;
extern string d2f_d2d508[], d2f_cfc230[], d2f_d31348[], d2f_cf3668[];
extern int d2f_caf128, d2f_caf12c;

void OpX5_addUniqueString(vector<string> &v, string s);
string OpC_stringFunc_4082b0(const string &s);
int OpS8d_countNonNull_d210(vector<int> &v);
int OpS8b_Fn9d4500(vector<int> &v);
void logError(string location, string message);
bool opS2_logPhrase_5141b0(int id, const string *a, const string *b, const string *c, HEntity subject, const Pos *at);

void delta2_showTransmission_8f58f0(HEntity speaker, int index)	// NOTE: placeholder name
{
	if (d2f_cf3a20[index]->type != 0x70 && !d2f_cf45d8.field46dd90())
		OpX5_addUniqueString(d2f_d257c0, d2f_d2d508[d2f_cf3a20[index]->type]);
	Pos cell = d2f_cec054->offset458ef0().add(speaker->getPosition());
	if (!d2f_cec054->inBounds(cell))
	{
		d2f_cec054->center8069e0(d2f_cefc4c->getPlayer()->pos45a4c0(), false);
		cell.set_46ca50(d2f_cec054->offset458ef0().add(speaker->getPosition()));
		if (!d2f_cec054->inBounds(cell))
		{
			logError("showTransmission()", "Speaker \"" + speaker->name() + "\" outside map view even after centering");
			d2f_cec054->center8069e0(speaker->getPosition(), false);
			cell.set_46ca50(d2f_cec054->offset458ef0().add(speaker->getPosition()));
		}
	}
	bool right = cell.x * d2f_caf128 - 50 >= 0;
	bool edge = cell.y * d2f_caf12c + 9 < d2f_cec054->getHeight() * d2f_caf12c;
	Pos pos(right ? cell.x * d2f_caf128 - 50 : cell.x * d2f_caf128 + speaker->getSize() * d2f_caf128, edge ? cell.y * d2f_caf12c - 1 : cell.y * d2f_caf12c - 8);
	pos += d2f_cec054->getPos();
	int facing = right && edge ? 0 : (!right && edge ? 1 : (right && !edge ? 2 : 3));
	if (d2f_cf3a20[index]->name == "REVISION_17_RES")
	{
		d2f_d2c658.add472b90(0x42, -999999);
		d2f_cf45d8.unknown77fbc0(0x192);
		do
		{
			opS2_logPhrase_5141b0(0x1d1, 0, 0, 0, HEntity(), 0);
		} while (0);
	}
	else if ((d2f_cf3a20[index]->name == "WARLORD_RES" || d2f_cf3a20[index]->name == "WARLORD_RES_ENEMY" || (d2f_cf3a20[index]->name == "WARLORD_RES_SIGIX" && d2f_d1e888->type != 0x22)) && !d2f_d2c658.unknown472c70(0x43))
	{
		d2f_d2c658.add472b90(0x43, -999999);
		d2f_cf45d8.unknown77fbc0(0x193);
	}
	vector<string> len;
	if (d2f_cf3a20[index]->name == "AUTO_SCR_DATA_CENTER")
	{
		HEntity player = d2f_cefc4c->getPlayer();
		int a;
		int q;
		player->unknown5cede0(&a, &q);
		string output;
		if (q != 20)
			output += d2f_cfc230[q] + "-";
		output += d2f_d31348[a];
		output = OpC_stringFunc_4082b0(output);
		len.push_back("You strike me as a " + output + " sort of build. As for the details...");
		int cx = 0;
		int key = player->unknown5d1390();
		int v2 = player->unknown5c8cb0();
		int size = player->unknown5d1ee0();
		if (v2 > size)
		{
			len.push_back("Looking a little overweight there. That'll slow you down and ensure you trigger any traps you run across. Not good.");
			cx -= 1;
		}
		else if (v2 <= size / 2 && key != 6 && player->unknown5d14d0(key + 9, 0) > 1)
		{
			len.push_back("Impressive surplus mass support. Even if you were to lose some " + OpC_stringFunc_4082b0(d2f_cf3668[key + 9]) + " support to an unlucky hit, overheating, or some other anomaly, you'd still be able to limp away pretty effectively.");
			cx += 1;
		}
		else if (v2 < size - 3)
			len.push_back("Staying well enough underweight, I see. Good for your health.");
		else
		{
			len.push_back("Running really close to your mass support limit there. I can respect that level of optimization.");
			cx += 1;
		}
		int speed = player->unknown5d15a0(0);
		if (speed < 50)
		{
			len.push_back("Very respectable speed. You'll leave the average 0b10 patrol in the dust.");
			cx += 2;
		}
		else if (speed < 100)
		{
			len.push_back("Fairly fast " + OpC_stringFunc_4082b0(key == 6 ? string("movement") : d2f_cf3668[key + 9]) + " speed you've got there. More than enough to dodge or outrun Grunts and the like.");
			cx += 1;
		}
		else if (speed < 180)
		{
			len.push_back("Your speed leaves a bit to be desired, but I'm sure with the right intuition you can avoid any trouble you don't want.");
			if (player->unknown5d2380(10).isValid())
				len.back() += " Especially with that " + player->unknown5d2380(10)->getName(0, 0) + ".";
			else if (player->unknown5d2380(11).isValid())
				len.back() += " Especially with that " + player->unknown5d2380(11)->getName(0, 0) + ".";
		}
		else if (speed < 280)
		{
			len.push_back("A little on the slow side, eh? I suggest upgrading your propulsion or shedding some of that mass.");
			if (player->unknown5d2380(7).isValid() && player->unknown5d2380(7)->unknown457b30() >= 30)
				len.back() += " That " + player->unknown5d2380(7)->getName(0, 0) + " looks a bit greedy.";
			cx -= 1;
		}
		else
		{
			len.push_back("You do realize that with that speed you'll be forced to fight anything that looks at you funny.");
			cx -= 2;
		}
		float bonus = player->unknown5d1070();
		float tmp2 = player->unknown5ca4f0() + player->unknown5d1e40() * 100.0 / speed;
		int ty = (int)(bonus - tmp2);
		if (ty < 0)
		{
			len.push_back("Running an energy deficit while on the move... a bold strategy.");
			cx -= 1;
		}
		else if (ty < 5)
			len.push_back("Looks like you could use a somewhat better energy supply, just in case.");
		else if (ty < 30 && (player->unknown5d26e0(0x43) || player->unknown5d26e0(0x44) || player->unknown5d26e0(0x45) || player->unknown5d26e0(0x46) || player->unknown5d26e0(0x47)))
		{
			len.push_back("Nice energy supply you've got going there, but it won't be able to run those shields for any longer engagement.");
			cx -= 1;
		}
		else
		{
			len.push_back("Energy supply looking good...");
			cx += 1;
		}
		int factor = player->unknown5ca960();
		int xx = player->unknown5ca8d0() + player->unknown5d1da0() * 100 / speed;
		int level = factor - xx;
		if (level < -5)
		{
			len.push_back("I regret to inform you there's a good chance you will die to meltdown any cycle now. Get some cooling for Great Nut's sake.");
			cx -= 2;
		}
		else if (level < 0)
		{
			len.push_back("Trying to survive in the wild for long with a positive heat profile is just asking for trouble.");
			cx -= 1;
		}
		else if (level < 10)
		{
			len.push_back("You might want to consider adding some extra heat sinks. Heat situation's not bad though.");
			cx += 1;
		}
		else if (level > 80)
			len.push_back("Sheesh, you look like you're preparing for an 0b10 sterilization run.");
		else
		{
			len.push_back("Heat dissipation looks good...");
			cx += 2;
		}
		if (player->unknown5d26e0(2) || player->unknown5d26e0(4) || player->unknown5d26e0(5))
		{
			len.push_back("But I see you also have conditional cooling potential, bonus points for being able to survive unexpectedly severe heat issues, for a time.");
			cx += 1;
		}
		int base = player->unknown5cca00();
		if (base > 20)
		{
			len.push_back("Your core is quite exposed for someone who looks like a trouble magnet. Try to be less... naked.");
			cx -= 1;
		}
		else if (base < 10)
		{
			len.push_back("Nice job keeping your core covered. High core exposure is the leading cause of death among Derelicts.");
			cx += 1;
		}
		vector<HItem> *table = player->getInventoryList();
		HItem best;
		int maxScore;
		for (unsigned int i = 0; i < table->size(); i++)
		{
			if ((*table)[i]->getType() <= 3 && (*table)[i]->unknown577790())
			{
				int coverage = player->unknown5ccb50((*table)[i]);
				if (best.isNull() || coverage > maxScore)
				{
					best = (*table)[i];
					maxScore = coverage;
				}
			}
		}
		if (best.isValid() && best->kind457880() != 0x12)
		{
			len.push_back("Your component with the highest coverage is not armor, which is a little worrying. I hope you have spare parts and easy access to a good mechanic. I can recommend CR-KLE.");
			cx -= 1;
		}
		if (player->getRoomCount(0) > 2)
		{
			len.push_back("You sure have a lot of room for power sources. Might be overkill, but maybe that's just me.");
			cx -= 1;
		}
		else
		{
			int rooms = player->getRoomCount(3);
			if (rooms > 4)
			{
				len.push_back("I see you have room for quite a lot of weapons. Only a true master can handle that much firepower. Are you a true master?");
				cx -= 1;
			}
			else if (player->unknown5cba50() >= 3)
			{
				len.push_back("I see you have a good number of weapons. Easier to mow down all comers, extra coverage if needed... I like it.");
				cx += 1;
			}
		}
		vector<HItem> vec;
		vector<HItem> map;
		HItem other;
		for (unsigned int i = 0; i < table->size(); i++)
		{
			if ((*table)[i]->slot4578a0() == 3 && (*table)[i]->getType() != 4 && (((*table)[i]->data()->unknown120 > 0 && (*table)[i]->data()->damageType != 9) || ((*table)[i]->data()->range && (*table)[i]->data()->range->count30 && (*table)[i]->data()->range->type != 9)))
			{
				if ((*table)[i]->kind457880() >= 0x1a)
					map.push_back((*table)[i]);
				else
				{
					vec.push_back((*table)[i]);
					if ((*table)[i]->kind457880() == 0x18)
						other = (*table)[i];
				}
			}
		}
		if (!map.empty())
		{
			if (map.size() >= 3)
			{
				len.push_back("Nice melee stack, that's some deadly ambush potential right there.");
				cx += 1;
			}
			else
			{
				len.push_back("So you're a close-in fighter... Remember to use those bottlenecks! I'm something of a tactics expert myself.");
				len.push_back("But really melee weapons are great for creating shortcuts through all kinds of terrain, and low resource costs mean you can stay in the fight longer.");
			}
		}
		else if (vec.empty())
			len.push_back("No weapons, hm... A pacifist? A thinking bot? At least that makes you less of a target if you hang around other armed folk.");
		if (!vec.empty())
		{
			if (map.empty())
				len.push_back("Since you're armed, let's take a closer look at those weapons...");
			else
				len.push_back("You also have ranged capabilities, a rare combo!");
			int energy = 0;
			int matter = 0;
			for (unsigned int i = 0; i < vec.size(); i++)
			{
				energy += vec[i]->energy5788e0();
				matter += vec[i]->matter5789c0();
			}
			int heatVolley = player->unknown5d7320(&vec, 0);
			int volleyTime = player->unknown5d6d80(&vec, HEntity());
			float amount = volleyTime * bonus / 100.0;
			if (energy > amount)
			{
				if (energy > amount * 2)
				{
					len.push_back("Your volley eats a lot more energy than you generate, that's a bit dangerous and I can see you running from battles.");
					cx -= 1;
				}
				else
					len.push_back("Your volley energy consumption is not sustainable over the long term, but you should be okay for short skirmishes.");
			}
			else
			{
				len.push_back("Your volley energy consumption looks to be within sustainable parameters.");
				cx += 1;
			}
			heatVolley += player->unknown5ca8d0() * volleyTime / 100;
			factor = factor * volleyTime / 100;
			if (heatVolley > factor)
			{
				if (heatVolley > factor * 2)
				{
					len.push_back("And your attacks are likely to generate way too much heat. Imagine facing off against Grunts and their thermal transfer while trying to keep your own temp down.");
					cx -= 1;
				}
				else
					len.push_back("And your cooling doesn't look like it can quite keep up with the heat you generate during combat. I'd watch out for that.");
			}
			else
			{
				if (energy > amount * 2)
					len.push_back("But at least your weapon cooling seems sufficient.");
				else
					len.push_back("And your weapon cooling seems sufficient.");
				cx += 1;
			}
			if (matter > 0)
			{
				v2 = player->unknown5ca670();
				if (v2 < matter * 10)
				{
					len.push_back("Unfortunately even with full reserves you are going to run out of matter to fire before long. You might want to reconsider that loadout.");
					cx -= 1;
				}
				else if (v2 < matter * 20)
					len.push_back("Top up your matter reserves and it appears you can make it through a skirmish okay. I'd suggest carrying some Matter Pods, just in case.");
				else if (v2 >= matter * 30)
				{
					len.push_back("It appears that with full matter reserves you could sustain firing for quite a while.");
					cx += 1;
				}
			}
			if (vec.size() > 1)
			{
				vector<int> counts(10u, 0);
				for (unsigned int i = 0; i < vec.size(); i++)
				{
					if (vec[i]->data()->range)
						counts[vec[i]->data()->range->type]++;
					else
						counts[vec[i]->data()->damageType]++;
				}
				if (OpS8d_countNonNull_d210(counts) == 1)
				{
					int type = OpS8b_Fn9d4500(counts);
					switch (type)
					{
					case 1:
						if (vec[0]->data()->unknown158)
							len.push_back("I like the emphasis on thermal output. Melting Unaware means less scrap left at the end, but it's nice when you can compound a target's own heat buildup.");
						break;
					case 0:
						len.push_back("Rolling with the pure kinetic damage. Definitely keep those matter stores up!");
						break;
					case 3:
						len.push_back("Pure EM damage, scary like Programmer! But that also means you have to look out for Programmers yourself, careful out there.");
						break;
					}
				}
				else
					len.push_back("Mixed damage types, eh? Going for a jack-of-all-trades style, don't see that often, but it can work.");
			}
			if (other.isValid())
				len.push_back("I see that " + other->name457860() + ". Great for groups, and collateral damage is fine so long as it happens in 0b10... and you have an escape route hehe.");
		}
		vector<string> tags;
		tags.push_back("an F");
		tags.push_back("a D-");
		tags.push_back("a D");
		tags.push_back("a D+");
		tags.push_back("a C-");
		tags.push_back("a C");
		int rank = tags.size() - 1;
		tags.push_back("a C+");
		tags.push_back("a B-");
		tags.push_back("a B");
		tags.push_back("a B+");
		tags.push_back("an A-");
		tags.push_back("an A");
		tags.push_back("an A+");
		tags.push_back("an A+");
		tags.push_back("an S");
		if (cx > 0)
		{
			for (int i = 0; i < cx && rank < tags.size() - 1; i++)
				rank++;
		}
		else if (cx < 0)
		{
			for (int i = 0; i < abs(cx) && rank > 0; i++)
				rank--;
		}
		len.push_back("A0-MCA gives you " + tags[rank] + "!");
		do
		{
			opS2_logPhrase_5141b0(0x100, &tags[rank], 0, 0, HEntity(), 0);
		} while (0);
		if (rank == tags.size() - 1)
		{
			len.push_back("I rarely do this but you've got a sparkling quality that just screams awesome. You deserve a little something extra, have the Expert System over there.");
			d2f_d1e860.setEntryText("scrDataCenterRankS_g", "1");
		}
	}
	new D2fTransmission(d2f_cec034, pos, speaker, index, facing, len);
}
