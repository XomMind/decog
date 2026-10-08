#include <string>
#include <memory>
#include <stddef.h>
#include <ctype.h>
#include "rng.h"
using std::string;extern RNG rng;
// NOTE: private partial views and semantic names are placeholders.
// Collections are real 16-byte owners using retail lifecycle/insertion operations.
// Keep this TU late in the full link: the actual new-object helper bodies permit
// compiler-inferred nothrow while preserving retail new-expression result slots.
// Native release vector storage: three T* slots and empty allocator member;
// allocator has size1, with ordinary pointer alignment rounding the view to16B.
template<class T>struct LA24Vec{T*first;T*last;T*end;std::allocator<T>allocator;LA24Vec()throw();LA24Vec(const LA24Vec&);~LA24Vec()throw();unsigned size()const throw();bool empty()const throw();T&operator[](unsigned)throw();void push_back(T&&);};
static_assert(sizeof(std::allocator<int>)==1,"native empty allocator");
static_assert(offsetof(LA24Vec<int>,allocator)==12,"allocator follows three native pointers");
static_assert(sizeof(LA24Vec<int>)==16,"natural native release vector size");
struct LA24EffectType;struct LA24Effect{LA24EffectType*type;int value;LA24Effect(LA24EffectType*,int);LA24Effect(const LA24Effect&);};
LA24Effect::LA24Effect(LA24EffectType*type_,int value_){type=type_;value=value_;}
struct LA24RecordDef;struct LA24RecordNode;
struct LA24EC{LA24Vec<LA24RecordNode*>records;int turn;LA24EC();void update518b30()throw();void add4566c0(LA24Vec<LA24RecordDef*>);};
LA24Effect::LA24Effect(const LA24Effect&other){type=other.type;value=other.value;}
LA24EC::LA24EC(){update518b30();}
struct LA24P{int x,y;LA24P()throw();LA24P(int,int)throw();LA24P&fill409ff0(int)throw();};
struct LA24H{int id;LA24H()throw();void reset9b7270()throw();};struct LA24HG{int id;LA24HG()throw();void reset9b7270()throw();};struct LA24HI{int id;};
struct LA24Def{int id;string name;char p20[4];int unknown24,unknown28;char p2c[0x84-0x2c];int unknown84;char p88[0x9c-0x88];int footprintCount,pA0,unknownA4;char pA8[0xc4-0xa8];LA24Vec<LA24Effect*>unknownC4;LA24Vec<LA24RecordDef*>unknownD4;char pE4[0x1ac-0xe4];string unknown1AC;int p1c8;int unknown1CC[4];int unknown1DC,p1e0,unknown1E4,p1e8,unknown1EC;char p1f0[0x218-0x1f0];int unknown218;void code459d00(string&);};
struct LA24Weights{LA24Vec<int>values,weights;int total;LA24Weights();LA24Weights(const int*,int);~LA24Weights();void add(int,int);void remove(int);unsigned size()throw();int&pick()throw();};
struct LA24EntityPart;struct LA24Aux144;
struct LA24Entity{int unknown00;LA24H self;LA24Def*record;string name;LA24HG group;int unknown2c;LA24Vec<LA24P>positions;int unknown40;LA24P unknown44;int unknown4C,unknown50,unknown54,unknown58;float unknown5C;LA24Vec<int>unknown60;int unknown70,unknown74,slots[4],unknown88,unknown8C,unknown90,unknown94,unknown98;LA24Vec<int>unknown9C;bool unknownAC;int unknownB0,unknownB4;bool unknownB8;int unknownBC;bool unknownC0;int unknownC4,unknownC8,unknownCC,unknownD0,unknownD4;unsigned unknownD8;LA24Vec<LA24Effect*>unknownDC;LA24EC*unknownEC;LA24EntityPart*unknownF0;LA24Vec<int>unknownF4,unknown104;LA24H unknown114,unknown118;int unknown11C,unknown120;LA24Vec<int>unknown124;LA24Vec<LA24HI>parts;LA24Aux144*unknown144;LA24Entity(LA24Def*);void add45b340(LA24Effect*);};
struct LA24Player{int id46dec0()throw();};extern LA24Player la24_cf45d8;
struct LA24Level{int p0,unknown04,depth;};struct LA24HL{int id;LA24Level*get9b7910()const throw();LA24Level*operator->()const throw();};extern LA24HL la24_d1e888;
extern string la24_d38e40[],la24_d20260[];extern int la24_d1eb58,la24_d1eb5c,la24_caf2b8[],la24_caf43c,la24_ba773c[],la24_ba7704[],la24_cf471c,la24_b95a1c[],la24_cf4954,la24_cf462c;extern LA24Vec<LA24EffectType*>la24_d2f0f8;
string&la24_pad408090(string&,unsigned,char);char la24_char4085b0(string&)throw();string la24_int4051f0(int);void la24_copy9d9460(int*,int*,unsigned)throw();int la24_sum9d0ca0(int*,unsigned)throw();int la24_max(int,int)throw();
LA24Entity::LA24Entity(LA24Def *record_)
{
	unknown00 = la24_cf45d8.id46dec0();
	self.reset9b7270();
	record = record_;
	name = record->unknown1AC;
	if (record->unknown24 == 3)
	{
		if (record->unknown28 == 0x3b || record->unknown28 == 0x3c || record->unknown28 == 0x3d)
		{
			switch (record->unknown28)
			{
				case 0x3b:
					name = "AS-";
					break;
				case 0x3c:
					name = "as-";
					break;
				case 0x3d:
					name = "AG-";
					break;
			}
			name += la24_pad408090(la24_int4051f0(rng.rangeInt(0.0f,99999.0f)),5,'0');
		}
		else if (record->unknown28 == 0x2e || record->unknown28 == 0x2f)
		{
			name = la24_pad408090(la24_int4051f0(la24_d1e888->depth),2,'0');
			name += la24_d38e40[la24_d1e888->unknown04];
			int &counter = record->unknown28 == 0x2e ? la24_d1eb58 : la24_d1eb5c;
			counter++;
			if (counter <= 99)
				name += la24_pad408090(la24_int4051f0(counter),2,'0');
			else
			{
				int over = counter - 100;
				if (over > 0x2a4)
					name += "**";
				else
				{
					name += (char)(over / 26 + 'A');
					name += (char)(over % 26 + 'A');
				}
			}
			name += record->unknown28 == 0x2e ? "-D" : "-K";
		}
		else if (record->name[0] == 'L' && record->name[1] == 'u' && record->name[2] == 'g')
		{
			name += " ";
			for (int i = 0; i < 3; i++)
				name += la24_int4051f0(rng.rangeInt(0.0f,9.0f));
		}
		else
		{
			name.clear();
			record->code459d00(name);
		}
	}
	if (record->unknown28 == 0x1b)
	{
		name = "Q";
		for (int i = 0; i < 3; i++)
			name += la24_int4051f0(rng.rangeInt(0.0f,9.0f));
		name += "-";
		string letters("abcdefghijklmnopqrstuvwxyz");
		name += la24_char4085b0(letters);
	}
	else if (record->unknown28 == 0x22 && record->name != "V2")
	{
		name = "V";
		for (int i = 0; i < 3; i++)
			name += la24_int4051f0(rng.rangeInt(0.0f,9.0f));
		name += "-";
		string letters("abcdefghijklmnopqrstuvwxyz");
		name += la24_char4085b0(letters);
	}
	else if (record->name[0] == 'P' && record->name[1] == '_')
	{
		string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
		name = "P";
		name += (char)(isalpha(la24_caf2b8[record->unknown28]) ? toupper(la24_caf2b8[record->unknown28]) : (char)la24_caf2b8[record->unknown28]);
		name += "-";
		for (int i = 0; i < 10; i++)
			name += la24_char4085b0(chars);
	}
	else if (record->unknown28 == 0x48)
	{
		LA24Weights table;
		for (int i = 0; i < 0xe; i++)
		{
			if (la24_d1e888->depth <= la24_ba773c[i])
				table.add(i,la24_ba7704[i]);
		}
		if (la24_d1e888->unknown04 == 0x24)
			table.remove(8);
		if (table.size() != 0)
		{
			int choice = la24_caf43c != 0xe ? la24_caf43c : table.pick();
			la24_caf43c = 0xe;
			LA24Effect *location = new LA24Effect(la24_d2f0f8[0x28],choice);
			add45b340(location);
			name = la24_d20260[location->value] + " Anomaly";
		}
	}
	group.reset9b7270();
	unknown2c = 0;
	for (int i = 0; i < record->footprintCount; i++)
		positions.push_back(LA24P(-100,-100));
	unknown40 = 0;
	unknown44.fill409ff0(-1);
	unknown4C = -1;
	unknown50 = 0;
	unknown54 = 0;
	unknown58 = 5;
	unknown5C = 0;
	unknown70 = 0;
	unknown74 = 0;
	la24_copy9d9460(record->unknown1CC,slots,4);
	if (la24_cf471c != 0)
	{
		LA24Weights table(la24_b95a1c,4);
		for (int i = 20 - la24_sum9d0ca0(slots,4); i > 0; i--)
			slots[table.pick()]++;
	}
	unknown88 = record->unknownA4;
	unknown8C = record->unknown28 == 0 ? la24_cf4954 : record->unknown1DC;
	unknown90 = record->unknown1E4;
	unknown94 = record->unknown28 == 0 ? (la24_cf462c != 0xb ? 100 : 0) : la24_max(0,record->unknown1EC);
	unknown98 = 0;
	unknownAC = false;
	unknownB0 = 0;
	unknownB4 = record->unknown218;
	unknownB8 = record->unknown84 != 0 ? rng.chance(record->unknown84) : false;
	unknownBC = 0;
	unknownC0 = record->unknown28 == 10;
	unknownC4 = 0;
	unknownC8 = 0;
	unknownCC = 0;
	unknownD0 = 0;
	unknownD4 = 0;
	unknownD8 = 0;
	for (unsigned int i = 0; i < record->unknownC4.size(); i++)
		unknownDC.push_back(new LA24Effect(*record->unknownC4[i]));
	unknownEC = 0;
	if (!record->unknownD4.empty())
	{
		unknownEC = new LA24EC();
		unknownEC->add4566c0(record->unknownD4);
	}
	unknownF0 = 0;
	unknown11C = 0;
	unknown120 = 0;
	unknown144 = 0;
}
