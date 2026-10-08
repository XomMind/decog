// team_b_62: pooled record stream constructor (0x7838a0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <istream>
#include <vector>
using namespace std;
template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480 (int), 0x9cf520 (bool), NOTE: placeholder name
void OpT8a_readInts(istream &stream, vector<int> &v);
struct TeamB_PoolPair { int a; int b; };	// NOTE: placeholder layout (OpU8_T9da130)
template <class T> void teamb_readStructs_9da130(istream &stream, vector<T> &v);	// NOTE: placeholder name (OpU8_readStructs)
class TeamB_PoolHandle { public: int ID; TeamB_PoolHandle(); void read(istream &stream); };	// NOTE: placeholder name (HProp / OpC_IntBox::read)
struct TeamB_PoolRec	// NOTE: placeholder name
{
	TeamB_PoolHandle prop;
	int value4;
	int value8;
	vector<TeamB_PoolPair> list0C;
	int value1C;
	int value20;
	bool flag24, flag25, flag26, flag27, flag28, flag29, flag2A, flag2B, flag2C, flag2D, flag2E, flag2F;
	vector<int> list30;
	vector<TeamB_PoolPair> list40;
	vector<TeamB_PoolPair> list50;
	bool flag60;
	bool flag61;
	TeamB_PoolRec(istream &stream);
};
TeamB_PoolRec::TeamB_PoolRec(istream &stream)	// 0x7838a0
{
	prop.read(stream);
	readBinary(stream,&value4);
	readBinary(stream,&value8);
	teamb_readStructs_9da130(stream,list0C);
	readBinary(stream,&value1C);
	readBinary(stream,&value20);
	readBinary(stream,&flag24);
	readBinary(stream,&flag25);
	readBinary(stream,&flag26);
	readBinary(stream,&flag27);
	readBinary(stream,&flag28);
	readBinary(stream,&flag29);
	readBinary(stream,&flag2A);
	readBinary(stream,&flag2B);
	readBinary(stream,&flag2C);
	readBinary(stream,&flag2D);
	readBinary(stream,&flag2E);
	readBinary(stream,&flag2F);
	OpT8a_readInts(stream,list30);
	teamb_readStructs_9da130(stream,list40);
	teamb_readStructs_9da130(stream,list50);
	readBinary(stream,&flag60);
	readBinary(stream,&flag61);
}
