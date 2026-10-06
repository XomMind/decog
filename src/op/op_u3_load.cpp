// op_u3_load: serialization loader 0x673e70 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <istream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480 (int), 0x9cf520 (bool), NOTE: placeholder name
template <class T> void OpQ5_readPointer(istream &stream, T *&p);	// NOTE: placeholder name
template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip);	// NOTE: placeholder name
template <class T> void OpQ5_clearObjects(vector<T*> &v);	// NOTE: placeholder name
template <class T> void OpQ5_readVectors(istream &stream, vector< vector<T> > &v);	// NOTE: placeholder name
void OpT8a_readInts(istream &in, vector<int> &v);	// NOTE: placeholder name, defined in op_t8a.cpp
struct OpS8a_P8;
void OpS8a_readP8s(istream &stream, vector<OpS8a_P8> &v);	// NOTE: placeholder name, defined in op_s8a.cpp
void OpU3_read9da130(istream &stream, void *value);	// NOTE: placeholder name (0x9da130)

struct OpQ5_T9d1d80;
struct OpQ5_T9da380;
struct OpQ5_T9da4c0;
struct OpQ5_T9e2c40;
struct OpQ5_T9da570;
struct OpQ5_U9d2090
{
	int pad;
};

struct OpQ5_U9da6b0
{
	int pad;
};

class HEntity
{
	int	ID;
public:
	HEntity();
};

struct OpU1_Point	// NOTE: placeholder name (defined in op_u1.cpp)
{
	int x;
	int y;
	void read(istream &stream);	// 0x40a330
	void fill_409ff0(int value);	// NOTE: placeholder name
	void write(ostream &stream);	// 0x40a370
};

struct OpU3_Handle	// NOTE: placeholder name
{
	int ID;
	void read(istream &stream);	// NOTE: placeholder name (0x9cfaf0)
	void reset_9b7270();	// NOTE: placeholder name
};

struct OpS7_IntGrid2	// NOTE: placeholder name (defined in op_s7.cpp)
{
	int width;
	int height;
	int *cells;
	void read_9cee40(istream &stream);	// NOTE: placeholder name
	void init_9cf690(int width_, int height_, int fill);	// NOTE: placeholder name
};

struct OpU3_Location	// NOTE: placeholder name
{
	int unknown0;
	int type;
};

class OpU3_HLocation	// NOTE: placeholder name
{
	int	ID;
public:
	OpU3_Location *operator->() const;	// 0x9b7910
};

class OpU3_GameData	// NOTE: placeholder name (object at 0xd1e860)
{
public:
	bool unknown46f4b0(int a);	// NOTE: placeholder name
};

struct OpR1h_Stats
{
	bool add4729d0(unsigned int id, int value, string text, int extra) throw();	// NOTE: placeholder name
};

struct XCell;
class Cell;
template <class T> class Array2D
{
public:
	int getWidth();
	int getHeight();
};

extern OpU3_GameData opu3_gameData;	// NOTE: placeholder name (0xd1e860)
extern OpU3_HLocation opu3_location;	// NOTE: placeholder name (0xd1e888)
extern vector<OpU3_HLocation> opu3_locations;	// NOTE: placeholder name (0xd1e88c)
extern OpR1h_Stats opu3_stats;	// NOTE: placeholder name (0xd2c658)
extern Array2D<XCell> opu3_cellsX;	// NOTE: placeholder name (0xcfd44c)
extern Array2D<Cell *> opu3_cells;	// NOTE: placeholder name (0xcfd44c)
extern int opu3_cf4718;	// NOTE: placeholder name
extern int opu3_cf4724;	// NOTE: placeholder name
extern int opu3_cf4740;	// NOTE: placeholder name
extern int opu3_table_b90000[];	// NOTE: placeholder name
extern int opu3_table_b90098[];	// NOTE: placeholder name
extern int opu3_table_b90290[][2];	// NOTE: placeholder name
extern int opu3_table_b91a40[][2];	// NOTE: placeholder name
extern int opu3_table_ba6550[];	// NOTE: placeholder name
extern int opu3_table_ba655c[];	// NOTE: placeholder name
extern int opu3_b91b88;	// NOTE: placeholder name

int minInt(int a, int b);	// 0x9cdb30
void opu3_lowerToMax(int &value, int maxValue);	// NOTE: placeholder name (0x9cf5a0)
void raiseToMin(int &value, int minValue);	// NOTE: placeholder name (0x9cf5c0)

struct OpU3_Rec673e70	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	int unknown14;
	vector<int> unknown18;
	int unknown28;
	OpU3_Handle unknown2C;
	bool unknown30;
	bool unknown31;
	int unknown34;
	int unknown38;
	int unknown3C;
	bool unknown40;
	bool unknown41;
	int unknown44;
	bool unknown48;
	bool unknown49;
	bool unknown4A;
	int unknown4C;
	vector<OpQ5_T9d1d80 *> unknown50;
	OpS7_IntGrid2 unknown60;
	int unknown6C;
	int unknown70;
	int unknown74;
	bool unknown78;
	int unknown7C;
	int unknown80;
	int unknown84;
	int unknown88;
	int unknown8C;
	OpQ5_T9da4c0 *unknown90;
	int unknown94;
	vector<int> unknown98;
	vector<int> unknownA8;
	int unknownB8;
	int unknownBC;
	OpU1_Point unknownC0;
	OpU1_Point unknownC8;
	int unknownD0;
	OpU3_Handle unknownD4;
	vector<HEntity> unknownD8;
	OpU3_Handle unknownE8;
	int unknownEC;
	OpU1_Point unknownF0;
	OpU1_Point unknownF8;
	bool unknown100;
	int unknown104;
	vector<OpQ5_T9e2c40 *> unknown108;
	vector<int> unknown118;
	int unknown128;
	OpU1_Point unknown12C;
	int unknown134;
	int unknown138;
	int unknown13C;
	int unknown140;
	int unknown144;
	vector< vector<OpQ5_U9d2090> > unknown148;
	vector< vector<OpQ5_U9da6b0> > unknown158;
	bool unknown168;
	vector<int> unknown16C;
	int unknown17C;
	int unknown180;
	OpU1_Point unknown184;
	int unknown18C;
	int unknown190;
	bool unknown194;
	bool unknown195;
	bool unknown196;
	bool unknown197;
	bool unknown198;

	void load(istream &stream);	// 0x673e70
	void init(OpU3_HLocation from, OpU3_HLocation to);	// NOTE: placeholder name (0x674aa0)
};

void OpU3_Rec673e70::load(istream &stream)
{
	readBinary(stream,&unknown0);
	readBinary(stream,&unknown4);
	readBinary(stream,&unknown8);
	readBinary(stream,&unknownC);
	readBinary(stream,&unknown10);
	readBinary(stream,&unknown14);
	unknown18.clear();
	OpT8a_readInts(stream,unknown18);
	readBinary(stream,&unknown28);
	unknown2C.read(stream);
	readBinary(stream,&unknown30);
	readBinary(stream,&unknown31);
	readBinary(stream,&unknown34);
	readBinary(stream,&unknown38);
	readBinary(stream,&unknown3C);
	readBinary(stream,&unknown40);
	readBinary(stream,&unknown41);
	readBinary(stream,&unknown44);
	readBinary(stream,&unknown48);
	readBinary(stream,&unknown49);
	readBinary(stream,&unknown4A);
	readBinary(stream,&unknown4C);
	OpQ5_clearObjects(unknown50);
	OpQ5_readObjects(stream,(vector<OpQ5_T9da380*>&)unknown50,0);
	unknown60.read_9cee40(stream);
	readBinary(stream,&unknown6C);
	readBinary(stream,&unknown70);
	readBinary(stream,&unknown74);
	readBinary(stream,&unknown78);
	readBinary(stream,&unknown7C);
	readBinary(stream,&unknown80);
	readBinary(stream,&unknown84);
	readBinary(stream,&unknown88);
	readBinary(stream,&unknown8C);
	delete unknown90;
	OpQ5_readPointer(stream,unknown90);
	readBinary(stream,&unknown94);
	unknown98.clear();
	OpS8a_readP8s(stream,(vector<OpS8a_P8>&)unknown98);
	unknownA8.clear();
	OpT8a_readInts(stream,unknownA8);
	readBinary(stream,&unknownEC);
	unknownF0.read(stream);
	unknownF8.read(stream);
	readBinary(stream,&unknown100);
	readBinary(stream,&unknown104);
	readBinary(stream,&unknownB8);
	readBinary(stream,&unknownBC);
	unknownC0.read(stream);
	unknownC8.read(stream);
	readBinary(stream,&unknownD0);
	unknownD4.read(stream);
	unknownD8.clear();
	OpU3_read9da130(stream,&unknownD8);
	unknownE8.read(stream);
	OpQ5_clearObjects(unknown108);
	OpQ5_readObjects(stream,(vector<OpQ5_T9da570*>&)unknown108,0);
	unknown118.clear();
	OpS8a_readP8s(stream,(vector<OpS8a_P8>&)unknown118);
	readBinary(stream,&unknown128);
	unknown12C.read(stream);
	readBinary(stream,&unknown134);
	readBinary(stream,&unknown138);
	readBinary(stream,&unknown13C);
	readBinary(stream,&unknown140);
	readBinary(stream,&unknown144);
	unknown148.clear();
	OpQ5_readVectors(stream,unknown148);
	unknown158.clear();
	OpQ5_readVectors(stream,unknown158);
	readBinary(stream,&unknown168);
	unknown16C.clear();
	OpT8a_readInts(stream,unknown16C);
	readBinary(stream,&unknown17C);
	readBinary(stream,&unknown180);
	unknown184.read(stream);
	readBinary(stream,&unknown18C);
	readBinary(stream,&unknown190);
	readBinary(stream,&unknown194);
	readBinary(stream,&unknown195);
	readBinary(stream,&unknown196);
	readBinary(stream,&unknown197);
	readBinary(stream,&unknown198);
}

void OpU3_Rec673e70::init(OpU3_HLocation from, OpU3_HLocation to)
{
	int amount;
	int oldValue = unknown0;
	int divisor = unknown0;
	int bonus;

	amount = minInt(opu3_table_b91a40[from->type][0] + opu3_table_ba6550[opu3_cf4718],100);
	unknown0 = (100 - amount) * unknown0 / 100;
	unknown4 = divisor ? unknown4 * unknown0 / divisor : 0;
	divisor = unknown0;
	amount = minInt(opu3_table_b91a40[to->type][1] + opu3_table_ba655c[opu3_cf4718],100);
	unknown0 = (100 - amount) * unknown0 / 100;
	unknown4 = divisor ? unknown4 * unknown0 / divisor : 0;
	if (abs(oldValue - unknown0) != 0)
	{
		opu3_stats.add4729d0(0x229,abs(oldValue - unknown0),"",-1);
		opu3_stats.add4729d0(0x22a,abs(oldValue - unknown0),"",-1);
	}
	if (opu3_table_b90000[to->type] == 1)
	{
		bonus = minInt(unknown8,900);
		unknown0 += bonus;
		unknown4 += bonus;
		opu3_stats.add4729d0(0x219,bonus,"",-1);
		opu3_stats.add4729d0(0x224,bonus,"",-1);
	}
	opu3_lowerToMax(unknown4,unknown0);
	if (to->type == 0x22)
		unknown4 = 0;
	raiseToMin(unknown0,unknown34 && opu3_table_b90000[to->type] == 1 ? opu3_b91b88 : 0);
	unknown8 = 0;
	unknownC = 0;
	unknown10 = 0;
	unknown14 = 0;
	unknown30 = opu3_table_b90098[to->type] != 0 && opu3_cf4724 == 0 && opu3_cf4740 == 0;
	if (opu3_locations.size() > 3 && opu3_locations[opu3_locations.size() - 2]->type == 0xe)
		unknown30 = false;
	unknown34 = 0;
	unknown38 = 1;
	unknown3C = 100;
	unknown41 = unknown40;
	unknown44 = 0;
	unknown48 = false;
	unknown49 = false;
	unknown4A = false;
	unknown4C = 0;
	unknown40 = false;
	if (opu3_gameData.unknown46f4b0(1) && opu3_location->type != 0x23)
		opu3_stats.add4729d0(0x217,unknown0,"",-1);
	unknown60.init_9cf690(opu3_cells.getWidth() / opu3_table_b90290[opu3_location->type][0] + 1,opu3_cellsX.getHeight() / opu3_table_b90290[opu3_location->type][0] + 1,0);
	unknown6C = 0;
	unknown74 = 0;
	unknown78 = false;
	unknown7C = 0;
	unknown84 = 0;
	unknown8C = 0;
	unknown194 = to->type == 0x22;
	unknown195 = false;
	unknown196 = false;
	unknown197 = false;
	unknown198 = false;
	unknown98.clear();
	unknownA8.clear();
	unknownB8 = 0;
	unknownBC = 0;
	unknownC0.fill_409ff0(-1);
	unknownC8.fill_409ff0(-1);
	unknownD0 = 0;
	unknownD4.reset_9b7270();
	unknownD8.clear();
	unknownE8.reset_9b7270();
	unknownF0.fill_409ff0(-1);
	unknownF8.fill_409ff0(-1);
	unknown100 = false;
	OpQ5_clearObjects(unknown108);
	unknown118.clear();
	unknown128 = 0;
	unknown12C.fill_409ff0(-1);
	unknown138 = 0;
	unknown13C = 0;
	unknown140 = 0;
	unknown144 = 0;
	unknown148.clear();
	unknown158.clear();
	unknown168 = false;
	unknown16C.clear();
	unknown17C = 0;
	unknown180 = 0;
	unknown184.fill_409ff0(-1);
	unknown18C = 0;
	unknown190 = 0x4b0;
}
