// op_x5_rd: record-vector readers, 0x9d5000-0x9d6000 (placeholder names)
// NOTE: placeholder names
#include <vector>
#include <istream>
using namespace std;

struct OpR2_Rec500f10
{
	int unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	int unknown14;
	int unknown18;
	int unknown1C;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2C;
	int unknown30;
	int unknown34;
	bool unknown38;

	OpR2_Rec500f10();	// NOTE: placeholder (0x9c0790)
	void read(istream &stream);	// 0x500f10
};

struct OpR2_Rec508930
{
	int unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	int unknown14;
	bool unknown18;
	int unknown1C;
	int unknown20;
	int unknown24;
	int unknown28;
	int unknown2C;
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3C;
	int unknown40;
	bool unknown44;

	OpR2_Rec508930();	// NOTE: placeholder (0x9c0790)
	void read(istream &stream);	// 0x508930
};

void OpX5_readRec500f10s(istream &stream, vector<OpR2_Rec500f10> &v)	// NOTE: placeholder name
{
	OpR2_Rec500f10 rec;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(rec);
		v.back().read(stream);
		count--;
	}
}

void OpX5_readRec508930s(istream &stream, vector<OpR2_Rec508930> &v)	// NOTE: placeholder name
{
	OpR2_Rec508930 rec;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(rec);
		v.back().read(stream);
		count--;
	}
}

struct OpY2_Rec449200	// NOTE: placeholder name (defined in op_y2.cpp)
{
	int m0;
	int m4;
	int m8;
	int mC;
	int m10;
	int m14;
	int m18;
	int m1C;
	int m20;
	int m24;
	int m28;
	int m2C;
	int m30;

	OpY2_Rec449200();	// NOTE: placeholder (0x4c9b00)
	void load(istream &stream);	// NOTE: placeholder name
};

void OpX5_readRec449200s(istream &stream, vector<OpY2_Rec449200> &v)	// NOTE: placeholder name
{
	OpY2_Rec449200 rec;
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		v.push_back(rec);
		v.back().load(stream);
		count--;
	}
}
