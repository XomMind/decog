// op_q2_ser: stream save/load routines in 0x516000-0x6c0000 matched against COGMIND.exe (Beta 17.1).
// NOTE: record layouts are partial; member and method names are placeholders.
#include <string>
#include <vector>
using namespace std;

class OpQ2_Stream;	// NOTE: placeholder name

// eh False size 0x46f
struct OpQ2_Obj55e0c0_120	// NOTE: placeholder name
{
	char data[8];
	void f40bf20(OpQ2_Stream *stream);
};
void opq2_f409650(OpQ2_Stream *stream, string value);
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d2130(OpQ2_Stream *stream, void *p1);
void opq2_f9da000(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec55e0c0	// NOTE: placeholder name
{
	char pad0[0x24 - 0x0];
	string unknown24;
	char pad40[0x44 - 0x40];
	int unknown44;
	char pad48[0x4c - 0x48];
	int unknown4C;
	int unknown50;
	char pad54[0x78 - 0x54];
	int unknown78;
	char pad7C[0xa4 - 0x7c];
	int unknownA4;
	int unknownA8;
	int unknownAC;
	int unknownB0;
	int unknownB4;
	int unknownB8;
	int unknownBC;
	int unknownC0;
	char padC4[0xc8 - 0xc4];
	int unknownC8;
	int unknownCC;
	int unknownD0;
	int unknownD4;
	int unknownD8;
	int unknownDC;
	int unknownE0;
	int unknownE4;
	int unknownE8;
	int unknownEC;
	int unknownF0;
	int unknownF4;
	int unknownF8;
	char padFC[0x100 - 0xfc];
	int unknown100;
	int unknown104;
	int unknown108;
	int unknown10C;
	int unknown110;
	int unknown114;
	int unknown118;
	int unknown11C;
	OpQ2_Obj55e0c0_120 unknown120;
	int unknown128;
	int unknown12C;
	int unknown130;
	int unknown134;
	int unknown138;
	vector<int> unknown13C;
	int unknown14C;
	int unknown150;
	int unknown154;
	int unknown158;
	int unknown15C;
	int unknown160;
	char pad164[0x174 - 0x164];
	string unknown174;
	void * unknown190;
	void * unknown194;
	char pad198[0x19c - 0x198];
	void * unknown19C;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec55e0c0::save(OpQ2_Stream *stream)
{
	opq2_f409650(stream,unknown24);
	opq2_f9d3b60(stream,&unknown44);
	opq2_f9d3b60(stream,&unknown4C);
	opq2_f9d3b60(stream,&unknown50);
	opq2_f9d3b60(stream,&unknown78);
	opq2_f9d3b60(stream,&unknownA4);
	opq2_f9d3b60(stream,&unknownA8);
	opq2_f9d3b60(stream,&unknownAC);
	opq2_f9d3b60(stream,&unknownB0);
	opq2_f9d3b60(stream,&unknownB4);
	opq2_f9d3b60(stream,&unknownB8);
	opq2_f9d3b60(stream,&unknownBC);
	opq2_f9d3b60(stream,&unknownC0);
	opq2_f9d3b60(stream,&unknownC8);
	opq2_f9d3b60(stream,&unknownCC);
	opq2_f9d3b60(stream,&unknownD0);
	opq2_f9d3b60(stream,&unknownD4);
	opq2_f9d3b60(stream,&unknownD8);
	opq2_f9d3b60(stream,&unknownDC);
	opq2_f9d3b60(stream,&unknownE0);
	opq2_f9d3b60(stream,&unknownE4);
	opq2_f9d3b60(stream,&unknownE8);
	opq2_f9d3b60(stream,&unknownEC);
	opq2_f9d3b60(stream,&unknownF0);
	opq2_f9d3b60(stream,&unknownF4);
	opq2_f9d3b60(stream,&unknownF8);
	opq2_f9d3b60(stream,&unknown100);
	opq2_f9d3b60(stream,&unknown104);
	opq2_f9d3b60(stream,&unknown108);
	opq2_f9d3b60(stream,&unknown10C);
	opq2_f9d3b60(stream,&unknown110);
	opq2_f9d3b60(stream,&unknown114);
	opq2_f9d3b60(stream,&unknown118);
	opq2_f9d3b60(stream,&unknown11C);
	unknown120.f40bf20(stream);
	opq2_f9d3b60(stream,&unknown128);
	opq2_f9d3b60(stream,&unknown12C);
	opq2_f9d3b60(stream,&unknown130);
	opq2_f9d3b60(stream,&unknown134);
	opq2_f9d3b60(stream,&unknown138);
	opq2_f9d2130(stream,&unknown13C);
	opq2_f9d3b60(stream,&unknown14C);
	opq2_f9d3b60(stream,&unknown150);
	opq2_f9d3b60(stream,&unknown154);
	opq2_f9d3b60(stream,&unknown158);
	opq2_f9d3b60(stream,&unknown15C);
	opq2_f9d3b60(stream,&unknown160);
	opq2_f409650(stream,unknown174);
	opq2_f9da000(stream,unknown190);
	opq2_f9da000(stream,unknown194);
	opq2_f9da000(stream,unknown19C);
}
// eh False size 0x482
struct OpQ2_Obj55e530_120	// NOTE: placeholder name
{
	char data[8];
	void f45f040(OpQ2_Stream *stream);
};
extern char opq2_gcf67c0[];
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9d6300(OpQ2_Stream *stream, void *p1, void *p2);
struct OpQ2_Rec55e530	// NOTE: placeholder name
{
	char pad0[0x24 - 0x0];
	string unknown24;
	char pad40[0x44 - 0x40];
	int unknown44;
	char pad48[0x4c - 0x48];
	int unknown4C;
	int unknown50;
	char pad54[0x78 - 0x54];
	int unknown78;
	char pad7C[0xa4 - 0x7c];
	int unknownA4;
	int unknownA8;
	int unknownAC;
	int unknownB0;
	int unknownB4;
	int unknownB8;
	int unknownBC;
	int unknownC0;
	char padC4[0xc8 - 0xc4];
	int unknownC8;
	int unknownCC;
	int unknownD0;
	int unknownD4;
	int unknownD8;
	int unknownDC;
	int unknownE0;
	int unknownE4;
	int unknownE8;
	int unknownEC;
	int unknownF0;
	int unknownF4;
	int unknownF8;
	char padFC[0x100 - 0xfc];
	int unknown100;
	int unknown104;
	int unknown108;
	int unknown10C;
	int unknown110;
	int unknown114;
	int unknown118;
	int unknown11C;
	OpQ2_Obj55e530_120 unknown120;
	int unknown128;
	int unknown12C;
	int unknown130;
	int unknown134;
	int unknown138;
	vector<int> unknown13C;
	int unknown14C;
	int unknown150;
	int unknown154;
	int unknown158;
	int unknown15C;
	int unknown160;
	char pad164[0x174 - 0x164];
	string unknown174;
	int unknown190;
	char unknown194[8];
	int unknown19C;
	void load(OpQ2_Stream *stream);
};

void OpQ2_Rec55e530::load(OpQ2_Stream *stream)
{
	unknown24.clear();
	opq2_f4096f0(stream,&unknown24);
	opq2_f9d8480(stream,&unknown44);
	opq2_f9d8480(stream,&unknown4C);
	opq2_f9d8480(stream,&unknown50);
	opq2_f9d8480(stream,&unknown78);
	opq2_f9d8480(stream,&unknownA4);
	opq2_f9d8480(stream,&unknownA8);
	opq2_f9d8480(stream,&unknownAC);
	opq2_f9d8480(stream,&unknownB0);
	opq2_f9d8480(stream,&unknownB4);
	opq2_f9d8480(stream,&unknownB8);
	opq2_f9d8480(stream,&unknownBC);
	opq2_f9d8480(stream,&unknownC0);
	opq2_f9d8480(stream,&unknownC8);
	opq2_f9d8480(stream,&unknownCC);
	opq2_f9d8480(stream,&unknownD0);
	opq2_f9d8480(stream,&unknownD4);
	opq2_f9d8480(stream,&unknownD8);
	opq2_f9d8480(stream,&unknownDC);
	opq2_f9d8480(stream,&unknownE0);
	opq2_f9d8480(stream,&unknownE4);
	opq2_f9d8480(stream,&unknownE8);
	opq2_f9d8480(stream,&unknownEC);
	opq2_f9d8480(stream,&unknownF0);
	opq2_f9d8480(stream,&unknownF4);
	opq2_f9d8480(stream,&unknownF8);
	opq2_f9d8480(stream,&unknown100);
	opq2_f9d8480(stream,&unknown104);
	opq2_f9d8480(stream,&unknown108);
	opq2_f9d8480(stream,&unknown10C);
	opq2_f9d8480(stream,&unknown110);
	opq2_f9d8480(stream,&unknown114);
	opq2_f9d8480(stream,&unknown118);
	opq2_f9d8480(stream,&unknown11C);
	unknown120.f45f040(stream);
	opq2_f9d8480(stream,&unknown128);
	opq2_f9d8480(stream,&unknown12C);
	opq2_f9d8480(stream,&unknown130);
	opq2_f9d8480(stream,&unknown134);
	opq2_f9d8480(stream,&unknown138);
	unknown13C.clear();
	opq2_f9cf5e0(stream,&unknown13C);
	opq2_f9d8480(stream,&unknown14C);
	opq2_f9d8480(stream,&unknown150);
	opq2_f9d8480(stream,&unknown154);
	opq2_f9d8480(stream,&unknown158);
	opq2_f9d8480(stream,&unknown15C);
	opq2_f9d8480(stream,&unknown160);
	unknown174.clear();
	opq2_f4096f0(stream,&unknown174);
	opq2_f9d6300(stream,&unknown190,opq2_gcf67c0);
	opq2_f9d6300(stream,&unknown194,opq2_gcf67c0);
	opq2_f9d6300(stream,&unknown19C,opq2_gcf67c0);
}
// eh False size 0x38
extern char opq2_gd2f0f8[];
void opq2_f9d6490(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec516650	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	OpQ2_Rec516650(OpQ2_Stream *stream);
};

OpQ2_Rec516650::OpQ2_Rec516650(OpQ2_Stream *stream)
{
	opq2_f9d6490(stream,&unknown0,opq2_gd2f0f8);
	opq2_f9d8480(stream,&unknown4);
}
// eh False size 0x32
void opq2_f9da000(OpQ2_Stream *stream, void *p1);
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec516690	// NOTE: placeholder name
{
	void * unknown0;
	int unknown4;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec516690::save(OpQ2_Stream *stream)
{
	opq2_f9da000(stream,unknown0);
	opq2_f9d3b60(stream,&unknown4);
}
// eh True size 0x193
// WARN ('rawmov', 'byte ptr [ebp - 0xd], 1')
extern char opq2_gcfd2ec[];
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
void opq2_f436980(OpQ2_Stream *stream, void *p1);
void opq2_f436960(OpQ2_Stream *stream, void *p1);
void opq2_f9d5880(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec5167c0	// NOTE: placeholder name
{
	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	int unknown28;
	vector<int> unknown2C;
	string unknown3C;
	int unknown58;
	int unknown5C;
	string unknown60;
	string unknown7C;
	bool unknown98;
	char pad99[0x9c - 0x99];
	int unknown9C;
	OpQ2_Rec5167c0(OpQ2_Stream *stream);
};

OpQ2_Rec5167c0::OpQ2_Rec5167c0(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	bool unused = true;
	opq2_f4096f0(stream,&unknown4);
	opq2_f9d8480(stream,&unknown20);
	opq2_f9d8480(stream,&unknown24);
	opq2_f9d8480(stream,&unknown28);
	opq2_f436980(stream,&unknown2C);
	opq2_f436960(stream,&unknown3C);
	opq2_f9d5880(stream,&unknown58,opq2_gcfd2ec);
	opq2_f9d8480(stream,&unknown5C);
	opq2_f4096f0(stream,&unknown60);
	opq2_f436960(stream,&unknown7C);
	opq2_f9cf520(stream,&unknown98);
	opq2_f9d8480(stream,&unknown9C);
}
// eh True size 0x364
struct OpQ2_Obj517370_28	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj517370_28();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj517370_5C	// NOTE: placeholder name
{
	char data[16];
	OpQ2_Obj517370_5C();
	void f40b450(OpQ2_Stream *stream);
};
struct OpQ2_Obj517370_AC	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj517370_AC();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj517370_D4	// NOTE: placeholder name
{
	char data[36];
	OpQ2_Obj517370_D4();
	~OpQ2_Obj517370_D4();
	void f9b6d70(OpQ2_Stream *stream);
};
extern char opq2_gd2c408[];
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f436960(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9d6aa0(OpQ2_Stream *stream, void *p1, void *p2);
struct OpQ2_Rec517370	// NOTE: placeholder name
{
	int unknown0;
	string unknown4;
	int unknown20;
	int unknown24;
	OpQ2_Obj517370_28 unknown28;
	int unknown30;
	bool unknown34;
	bool unknown35;
	char pad36[0x38 - 0x36];
	string unknown38;
	int unknown54;
	int unknown58;
	OpQ2_Obj517370_5C unknown5C;
	int unknown6C;
	int unknown70;
	int unknown74;
	int unknown78;
	int unknown7C;
	vector<int> unknown80;
	int unknown90;
	vector<int> unknown94;
	int unknownA4;
	int unknownA8;
	OpQ2_Obj517370_AC unknownAC;
	int unknownB4;
	bool unknownB8;
	bool unknownB9;
	char padBA[0xbc - 0xba];
	int unknownBC;
	bool unknownC0;
	bool unknownC1;
	char padC2[0xc4 - 0xc2];
	vector<int> unknownC4;
	OpQ2_Obj517370_D4 unknownD4;
	int unknownF8;
	int unknownFC;
	OpQ2_Rec517370(OpQ2_Stream *stream);
};

OpQ2_Rec517370::OpQ2_Rec517370(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f436960(stream,&unknown4);
	opq2_f9d8480(stream,&unknown20);
	opq2_f9d8480(stream,&unknown24);
	unknown28.f45f040(stream);
	opq2_f9d8480(stream,&unknown30);
	opq2_f9cf520(stream,&unknown34);
	opq2_f9cf520(stream,&unknown35);
	opq2_f436960(stream,&unknown38);
	opq2_f9d8480(stream,&unknown54);
	opq2_f9d8480(stream,&unknown58);
	unknown5C.f40b450(stream);
	opq2_f9d8480(stream,&unknown6C);
	opq2_f9d8480(stream,&unknown70);
	opq2_f9d8480(stream,&unknown74);
	opq2_f9d8480(stream,&unknown78);
	opq2_f9d8480(stream,&unknown7C);
	opq2_f9cf5e0(stream,&unknown80);
	opq2_f9d8480(stream,&unknown90);
	opq2_f9cf5e0(stream,&unknown94);
	opq2_f9d6aa0(stream,&unknownA4,opq2_gd2c408);
	opq2_f9d6aa0(stream,&unknownA8,opq2_gd2c408);
	unknownAC.f45f040(stream);
	opq2_f9d8480(stream,&unknownB4);
	opq2_f9cf520(stream,&unknownB8);
	opq2_f9cf520(stream,&unknownB9);
	opq2_f9d8480(stream,&unknownBC);
	opq2_f9cf520(stream,&unknownC0);
	opq2_f9cf520(stream,&unknownC1);
	opq2_f9cf5e0(stream,&unknownC4);
	unknownD4.f9b6d70(stream);
	opq2_f9d8480(stream,&unknownF8);
	opq2_f9d8480(stream,&unknownFC);
}
// eh True size 0x196
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f4097e0(OpQ2_Stream *stream, void *p1);
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9d6b90(OpQ2_Stream *stream, void *p1, int a2);
struct OpQ2_Rec5176e0	// NOTE: placeholder name
{
	bool unknown0;
	char pad1[0x4 - 0x1];
	vector<int> unknown4;
	int unknown14;
	bool unknown18;
	char pad19[0x1c - 0x19];
	string unknown1C;
	int unknown38;
	int unknown3C;
	string unknown40;
	vector<int> unknown5C;
	vector<int> unknown6C;
	vector<int> unknown7C;
	vector<int> unknown8C;
	OpQ2_Rec5176e0(OpQ2_Stream *stream);
};

OpQ2_Rec5176e0::OpQ2_Rec5176e0(OpQ2_Stream *stream)
{
	opq2_f9cf520(stream,&unknown0);
	opq2_f4097e0(stream,&unknown4);
	opq2_f9d8480(stream,&unknown14);
	opq2_f9cf520(stream,&unknown18);
	opq2_f4096f0(stream,&unknown1C);
	opq2_f9d8480(stream,&unknown38);
	opq2_f9d8480(stream,&unknown3C);
	opq2_f4096f0(stream,&unknown40);
	opq2_f9cf5e0(stream,&unknown5C);
	opq2_f4097e0(stream,&unknown6C);
	opq2_f4097e0(stream,&unknown7C);
	opq2_f9d6b90(stream,&unknown8C,0);
}
// eh True size 0x313
struct OpQ2_Obj518550_A0	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj518550_A0();
	void f45f040(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
void opq2_f9d70b0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9d7150(OpQ2_Stream *stream, void *p1, int a2);
struct OpQ2_Rec518550	// NOTE: placeholder name
{
	int unknown0;
	string unknown4;
	string unknown20;
	int unknown3C;
	vector<int> unknown40;
	vector<int> unknown50;
	bool unknown60;
	bool unknown61;
	bool unknown62;
	char pad63[0x64 - 0x63];
	int unknown64;
	int unknown68;
	int unknown6C;
	int unknown70;
	int unknown74;
	int unknown78;
	int unknown7C;
	int unknown80;
	int unknown84;
	int unknown88;
	int unknown8C;
	int unknown90;
	int unknown94;
	bool unknown98;
	char pad99[0x9c - 0x99];
	int unknown9C;
	OpQ2_Obj518550_A0 unknownA0;
	int unknownA8;
	int unknownAC;
	bool unknownB0;
	char padB1[0xb4 - 0xb1];
	int unknownB4;
	int unknownB8;
	int unknownBC;
	vector<int> unknownC0;
	OpQ2_Rec518550(OpQ2_Stream *stream);
};

OpQ2_Rec518550::OpQ2_Rec518550(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f4096f0(stream,&unknown4);
	opq2_f9d8480(stream,&unknown3C);
	opq2_f9d70b0(stream,&unknown40);
	opq2_f9cf5e0(stream,&unknown50);
	opq2_f9cf520(stream,&unknown60);
	opq2_f9cf520(stream,&unknown61);
	opq2_f9cf520(stream,&unknown62);
	opq2_f9d8480(stream,&unknown64);
	opq2_f9d8480(stream,&unknown68);
	opq2_f9d8480(stream,&unknown6C);
	opq2_f9d8480(stream,&unknown70);
	opq2_f9d8480(stream,&unknown74);
	opq2_f9d8480(stream,&unknown78);
	opq2_f9d8480(stream,&unknown7C);
	opq2_f9d8480(stream,&unknown80);
	opq2_f9d8480(stream,&unknown84);
	opq2_f9d8480(stream,&unknown88);
	opq2_f9d8480(stream,&unknown8C);
	opq2_f9d8480(stream,&unknown90);
	opq2_f9d8480(stream,&unknown94);
	opq2_f9cf520(stream,&unknown98);
	opq2_f9d8480(stream,&unknown9C);
	unknownA0.f45f040(stream);
	opq2_f9d8480(stream,&unknownA8);
	opq2_f9d8480(stream,&unknownAC);
	opq2_f9cf520(stream,&unknownB0);
	opq2_f9d8480(stream,&unknownB4);
	opq2_f9d8480(stream,&unknownB8);
	opq2_f9d8480(stream,&unknownBC);
	opq2_f9d7150(stream,&unknownC0,0);
}
// eh False size 0x17a
struct OpQ2_Obj5719b0_4	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj5719b0_10	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj5719b0_14	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9da000(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9d6770(OpQ2_Stream *stream, void *p1);
void opq2_f9d84d0(OpQ2_Stream *stream, void *p1);
void opq2_f409740(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec5719b0	// NOTE: placeholder name
{
	int unknown0;
	OpQ2_Obj5719b0_4 unknown4;
	void * unknown8;
	int unknownC;
	OpQ2_Obj5719b0_10 unknown10;
	OpQ2_Obj5719b0_14 unknown14;
	int unknown1C;
	bool unknown20;
	char pad21[0x24 - 0x21];
	int unknown24;
	int unknown28;
	int unknown2C;
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3C;
	bool unknown40;
	char pad41[0x44 - 0x41];
	int unknown44;
	char unknown48[16];
	int unknown58;
	int unknown5C;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec5719b0::save(OpQ2_Stream *stream)
{
	opq2_f9d3b60(stream,&unknown0);
	unknown4.f9cfa90(stream);
	opq2_f9da000(stream,unknown8);
	opq2_f9d3b60(stream,&unknownC);
	unknown10.f9cfa90(stream);
	unknown14.f40a370(stream);
	opq2_f9d3b60(stream,&unknown1C);
	opq2_f9cf540(stream,&unknown20);
	opq2_f9d3b60(stream,&unknown24);
	opq2_f9d3b60(stream,&unknown28);
	opq2_f9d3b60(stream,&unknown2C);
	opq2_f9d3b60(stream,&unknown30);
	opq2_f9d3b60(stream,&unknown34);
	opq2_f9d3b60(stream,&unknown38);
	opq2_f9d3b60(stream,&unknown3C);
	opq2_f9cf540(stream,&unknown40);
	opq2_f9d3b60(stream,&unknown44);
	opq2_f9d6770(stream,&unknown48);
	opq2_f9d84d0(stream,&unknown58);
	opq2_f409740(stream,&unknown5C);
}
// eh True size 0x235
struct OpQ2_Obj571b30_4	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj571b30_4();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj571b30_10	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj571b30_10();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj571b30_14	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj571b30_14();
	void f40a330(OpQ2_Stream *stream);
};
extern char opq2_gd2d1c4[];
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9d6fc0(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9d6580(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9d8510(OpQ2_Stream *stream, void *p1);
void opq2_f436960(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec571b30_Item	// NOTE: placeholder name
{
	char pad0[0x44];
	int unknown44;
	char pad48[0xa8 - 0x48];
	int unknownA8;
};
struct OpQ2_Rec571b30	// NOTE: placeholder name
{
	int unknown0;
	OpQ2_Obj571b30_4 unknown4;
	OpQ2_Rec571b30_Item *unknown8;
	int unknownC;
	OpQ2_Obj571b30_10 unknown10;
	OpQ2_Obj571b30_14 unknown14;
	int unknown1C;
	bool unknown20;
	char pad21[0x24 - 0x21];
	int unknown24;
	int unknown28;
	int unknown2C;
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3C;
	bool unknown40;
	char pad41[0x44 - 0x41];
	int unknown44;
	vector<int> unknown48;
	int unknown58;
	string unknown5C;
	OpQ2_Rec571b30(OpQ2_Stream *stream);
};

OpQ2_Rec571b30::OpQ2_Rec571b30(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	unknown4.f9cfaf0(stream);
	opq2_f9d6fc0(stream,&unknown8,opq2_gd2d1c4);
	opq2_f9d8480(stream,&unknownC);
	unknown10.f9cfaf0(stream);
	unknown14.f40a330(stream);
	opq2_f9d8480(stream,&unknown1C);
	if (unknown1C > unknown8->unknownA8 && unknown8->unknown44 != 0 && unknown8->unknown44 != 3)
		unknown1C = unknown8->unknownA8;
	opq2_f9cf520(stream,&unknown20);
	opq2_f9d8480(stream,&unknown24);
	opq2_f9d8480(stream,&unknown28);
	opq2_f9d8480(stream,&unknown2C);
	opq2_f9d8480(stream,&unknown30);
	opq2_f9d8480(stream,&unknown34);
	opq2_f9d8480(stream,&unknown38);
	opq2_f9d8480(stream,&unknown3C);
	opq2_f9cf520(stream,&unknown40);
	opq2_f9d8480(stream,&unknown44);
	opq2_f9d6580(stream,&unknown48,0);
	opq2_f9d8510(stream,&unknown58);
	opq2_f436960(stream,&unknown5C);
}
// eh True size 0xa3
struct OpQ2_Obj57efa0_18	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57efa0_18();
	void f9cfaf0(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9d8600(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec57efa0	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	vector<int> unknown8;
	OpQ2_Obj57efa0_18 unknown18;
	OpQ2_Rec57efa0(OpQ2_Stream *stream);
};

OpQ2_Rec57efa0::OpQ2_Rec57efa0(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8600(stream,&unknown8);
	unknown18.f9cfaf0(stream);
}
// eh True size 0x52d
struct OpQ2_Obj57ffb0_0	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_0();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_10	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj57ffb0_10();
	void f40a330(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_18	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj57ffb0_18();
	void f40a330(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_20	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_20();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_40	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_40();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_50	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_50();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_58	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_58();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_80	// NOTE: placeholder name
{
	char data[16];
	OpQ2_Obj57ffb0_80();
	void f40b450(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_A4	// NOTE: placeholder name
{
	char data[16];
	OpQ2_Obj57ffb0_A4();
	void f40b450(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_B4	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_B4();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_B8	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_B8();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj57ffb0_D4	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj57ffb0_D4();
	void f9cfaf0(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9d07e0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9da130(OpQ2_Stream *stream, void *p1);
void opq2_f9d8860(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9d89a0(OpQ2_Stream *stream, void *p1);
void opq2_f9d8a50(OpQ2_Stream *stream, void *p1);
void opq2_f9d8b00(OpQ2_Stream *stream, void *p1);
void opq2_f9d8bb0(OpQ2_Stream *stream, void *p1, int a2);
struct OpQ2_Rec57ffb0	// NOTE: placeholder name
{
	OpQ2_Obj57ffb0_0 unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	OpQ2_Obj57ffb0_10 unknown10;
	OpQ2_Obj57ffb0_18 unknown18;
	OpQ2_Obj57ffb0_20 unknown20;
	vector<int> unknown24;
	int unknown34;
	int unknown38;
	int unknown3C;
	OpQ2_Obj57ffb0_40 unknown40;
	int unknown44;
	int unknown48;
	int unknown4C;
	OpQ2_Obj57ffb0_50 unknown50;
	bool unknown54;
	bool unknown55;
	bool unknown56;
	char pad57[0x58 - 0x57];
	OpQ2_Obj57ffb0_58 unknown58;
	bool unknown5C;
	char pad5D[0x60 - 0x5d];
	int unknown60;
	int unknown64;
	int unknown68;
	vector<int> unknown6C;
	bool unknown7C;
	char pad7D[0x80 - 0x7d];
	OpQ2_Obj57ffb0_80 unknown80;
	vector<int> unknown90;
	int unknownA0;
	OpQ2_Obj57ffb0_A4 unknownA4;
	OpQ2_Obj57ffb0_B4 unknownB4;
	OpQ2_Obj57ffb0_B8 unknownB8;
	int unknownBC;
	int unknownC0;
	int unknownC4;
	int unknownC8;
	int unknownCC;
	int unknownD0;
	OpQ2_Obj57ffb0_D4 unknownD4;
	int unknownD8;
	vector<int> unknownDC;
	int unknownEC;
	vector<int> unknownF0;
	int unknown100;
	int unknown104;
	int unknown108;
	int unknown10C;
	bool unknown110;
	char pad111[0x114 - 0x111];
	int unknown114;
	int unknown118;
	int unknown11C;
	vector<int> unknown120;
	OpQ2_Rec57ffb0(OpQ2_Stream *stream);
};

OpQ2_Rec57ffb0::OpQ2_Rec57ffb0(OpQ2_Stream *stream)
{
	unknown0.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8480(stream,&unknown8);
	opq2_f9d8480(stream,&unknownC);
	unknown10.f40a330(stream);
	unknown18.f40a330(stream);
	unknown20.f9cfaf0(stream);
	opq2_f9d07e0(stream,&unknown24);
	opq2_f9d8480(stream,&unknown34);
	opq2_f9d8480(stream,&unknown38);
	opq2_f9d8480(stream,&unknown3C);
	unknown40.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknown44);
	opq2_f9d8480(stream,&unknown48);
	opq2_f9d8480(stream,&unknown4C);
	unknown50.f9cfaf0(stream);
	opq2_f9cf520(stream,&unknown54);
	opq2_f9cf520(stream,&unknown55);
	opq2_f9cf520(stream,&unknown56);
	unknown58.f9cfaf0(stream);
	opq2_f9cf520(stream,&unknown5C);
	opq2_f9d8480(stream,&unknown60);
	opq2_f9d8480(stream,&unknown64);
	opq2_f9d8480(stream,&unknown68);
	opq2_f9d07e0(stream,&unknown6C);
	opq2_f9cf520(stream,&unknown7C);
	unknown80.f40b450(stream);
	opq2_f9d07e0(stream,&unknown90);
	opq2_f9d8480(stream,&unknownA0);
	unknownA4.f40b450(stream);
	unknownB4.f9cfaf0(stream);
	unknownB8.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknownBC);
	opq2_f9d8480(stream,&unknownC0);
	opq2_f9d8480(stream,&unknownC4);
	opq2_f9d8480(stream,&unknownC8);
	opq2_f9d8480(stream,&unknownCC);
	opq2_f9d8480(stream,&unknownD0);
	unknownD4.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknownD8);
	opq2_f9da130(stream,&unknownDC);
	opq2_f9d8480(stream,&unknownEC);
	opq2_f9d8860(stream,&unknownF0,0);
	opq2_f9d8480(stream,&unknown100);
	opq2_f9d8480(stream,&unknown104);
	opq2_f9d8480(stream,&unknown108);
	opq2_f9d8480(stream,&unknown10C);
	opq2_f9cf520(stream,&unknown110);
	opq2_f9d89a0(stream,&unknown114);
	opq2_f9d8a50(stream,&unknown118);
	opq2_f9d8b00(stream,&unknown11C);
	opq2_f9d8bb0(stream,&unknown120,0);
}
// eh True size 0x742
struct OpQ2_Obj517e00_44	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj517e00_44();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj517e00_5C	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj517e00_5C();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj517e00_98	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj517e00_98();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj517e00_EC	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj517e00_EC();
	void f45f040(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9d70b0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec517e00	// NOTE: placeholder name
{
	int unknown0;
	vector<int> unknown4;
	vector<int> unknown14;
	int unknown24;
	int unknown28;
	int unknown2C;
	bool unknown30;
	char pad31[0x34 - 0x31];
	int unknown34;
	int unknown38;
	bool unknown3C;
	char pad3D[0x40 - 0x3d];
	int unknown40;
	OpQ2_Obj517e00_44 unknown44;
	bool unknown4C;
	char pad4D[0x50 - 0x4d];
	int unknown50;
	int unknown54;
	int unknown58;
	OpQ2_Obj517e00_5C unknown5C;
	bool unknown64;
	bool unknown65;
	char pad66[0x68 - 0x66];
	int unknown68;
	int unknown6C;
	int unknown70;
	int unknown74;
	int unknown78;
	int unknown7C;
	int unknown80;
	int unknown84;
	bool unknown88;
	char pad89[0x8c - 0x89];
	int unknown8C;
	int unknown90;
	int unknown94;
	OpQ2_Obj517e00_98 unknown98;
	int unknownA0;
	int unknownA4;
	bool unknownA8;
	char padA9[0xac - 0xa9];
	int unknownAC;
	int unknownB0;
	int unknownB4;
	int unknownB8;
	int unknownBC;
	int unknownC0;
	int unknownC4;
	int unknownC8;
	int unknownCC;
	int unknownD0;
	int unknownD4;
	int unknownD8;
	int unknownDC;
	int unknownE0;
	int unknownE4;
	bool unknownE8;
	bool unknownE9;
	bool unknownEA;
	char padEB[0xec - 0xeb];
	OpQ2_Obj517e00_EC unknownEC;
	int unknownF4;
	int unknownF8;
	int unknownFC;
	int unknown100;
	int unknown104;
	vector<int> unknown108;
	int unknown118;
	int unknown11C;
	int unknown120;
	int unknown124;
	vector<int> unknown128;
	bool unknown138;
	bool unknown139;
	bool unknown13A;
	char pad13B[0x13c - 0x13b];
	int unknown13C;
	int unknown140;
	string unknown144;
	string unknown160;
	int unknown17C;
	int unknown180;
	string unknown184;
	string unknown1A0;
	string unknown1BC;
	OpQ2_Rec517e00(OpQ2_Stream *stream);
};

OpQ2_Rec517e00::OpQ2_Rec517e00(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f9d70b0(stream,&unknown4);
	opq2_f9cf5e0(stream,&unknown14);
	opq2_f9d8480(stream,&unknown24);
	opq2_f9d8480(stream,&unknown28);
	opq2_f9d8480(stream,&unknown2C);
	opq2_f9cf520(stream,&unknown30);
	opq2_f9d8480(stream,&unknown34);
	opq2_f9d8480(stream,&unknown38);
	opq2_f9cf520(stream,&unknown3C);
	opq2_f9d8480(stream,&unknown40);
	unknown44.f45f040(stream);
	opq2_f9cf520(stream,&unknown4C);
	opq2_f9d8480(stream,&unknown50);
	opq2_f9d8480(stream,&unknown54);
	opq2_f9d8480(stream,&unknown58);
	unknown5C.f45f040(stream);
	opq2_f9cf520(stream,&unknown64);
	opq2_f9cf520(stream,&unknown65);
	opq2_f9d8480(stream,&unknown68);
	opq2_f9d8480(stream,&unknown6C);
	opq2_f9d8480(stream,&unknown70);
	opq2_f9d8480(stream,&unknown74);
	opq2_f9d8480(stream,&unknown78);
	opq2_f9d8480(stream,&unknown7C);
	opq2_f9d8480(stream,&unknown80);
	opq2_f9d8480(stream,&unknown84);
	opq2_f9cf520(stream,&unknown88);
	opq2_f9d8480(stream,&unknown8C);
	opq2_f9d8480(stream,&unknown90);
	opq2_f9d8480(stream,&unknown94);
	unknown98.f45f040(stream);
	opq2_f9d8480(stream,&unknownA0);
	opq2_f9d8480(stream,&unknownA4);
	opq2_f9cf520(stream,&unknownA8);
	opq2_f9d8480(stream,&unknownAC);
	opq2_f9d8480(stream,&unknownB0);
	opq2_f9d8480(stream,&unknownB4);
	opq2_f9d8480(stream,&unknownB8);
	opq2_f9d8480(stream,&unknownBC);
	opq2_f9d8480(stream,&unknownC0);
	opq2_f9d8480(stream,&unknownC4);
	opq2_f9d8480(stream,&unknownC8);
	opq2_f9d8480(stream,&unknownCC);
	opq2_f9d8480(stream,&unknownD0);
	opq2_f9d8480(stream,&unknownD4);
	opq2_f9d8480(stream,&unknownD8);
	opq2_f9d8480(stream,&unknownDC);
	opq2_f9d8480(stream,&unknownE0);
	opq2_f9d8480(stream,&unknownE4);
	opq2_f9cf520(stream,&unknownE8);
	opq2_f9cf520(stream,&unknownE9);
	opq2_f9cf520(stream,&unknownEA);
	unknownEC.f45f040(stream);
	opq2_f9d8480(stream,&unknownF4);
	opq2_f9d8480(stream,&unknownF8);
	opq2_f9d8480(stream,&unknownFC);
	opq2_f9d8480(stream,&unknown100);
	opq2_f9d8480(stream,&unknown104);
	opq2_f9cf5e0(stream,&unknown108);
	opq2_f9d8480(stream,&unknown118);
	opq2_f9d8480(stream,&unknown11C);
	opq2_f9d8480(stream,&unknown120);
	opq2_f9d8480(stream,&unknown124);
	opq2_f9cf5e0(stream,&unknown128);
	opq2_f9cf520(stream,&unknown138);
	opq2_f9cf520(stream,&unknown139);
	opq2_f9cf520(stream,&unknown13A);
	opq2_f9d8480(stream,&unknown13C);
	opq2_f9d8480(stream,&unknown140);
	opq2_f4096f0(stream,&unknown144);
	opq2_f4096f0(stream,&unknown160);
	opq2_f9d8480(stream,&unknown17C);
	opq2_f9d8480(stream,&unknown180);
	opq2_f4096f0(stream,&unknown184);
	opq2_f4096f0(stream,&unknown1A0);
	opq2_f4096f0(stream,&unknown1BC);
}
// eh True size 0xbf1
struct OpQ2_Obj55d4c0_7C	// NOTE: placeholder name
{
	char data[16];
	OpQ2_Obj55d4c0_7C();
	~OpQ2_Obj55d4c0_7C();
	void f437560(OpQ2_Stream *stream);
};
struct OpQ2_Obj55d4c0_120	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj55d4c0_120();
	void f45f040(OpQ2_Stream *stream);
};
extern char opq2_gcf67c0[];
extern char opq2_gcfd2cc[];
extern char opq2_gcfd2ec[];
extern char opq2_gd223b4[];
extern char opq2_gd2c408[];
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f465ea0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9d6300(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d8110(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d6580(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9d8200(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f4097e0(OpQ2_Stream *stream, void *p1);
void opq2_f9d8250(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9d8390(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d5880(OpQ2_Stream *stream, void *p1, void *p2);
struct OpQ2_Rec55d4c0	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	string unknown8;
	string unknown24;
	int unknown40;
	int unknown44;
	int unknown48;
	int unknown4C;
	int unknown50;
	int unknown54;
	int unknown58;
	int unknown5C;
	int unknown60;
	int unknown64;
	int unknown68;
	int unknown6C;
	int unknown70;
	bool unknown74;
	bool unknown75;
	bool unknown76;
	char pad77[0x78 - 0x77];
	int unknown78;
	OpQ2_Obj55d4c0_7C unknown7C;
	int unknown8C;
	bool unknown90;
	char pad91[0x94 - 0x91];
	int unknown94;
	int unknown98;
	int unknown9C;
	int unknownA0;
	int unknownA4;
	int unknownA8;
	int unknownAC;
	int unknownB0;
	int unknownB4;
	int unknownB8;
	int unknownBC;
	int unknownC0;
	int unknownC4;
	int unknownC8;
	int unknownCC;
	int unknownD0;
	int unknownD4;
	int unknownD8;
	int unknownDC;
	int unknownE0;
	int unknownE4;
	int unknownE8;
	int unknownEC;
	int unknownF0;
	int unknownF4;
	int unknownF8;
	bool unknownFC;
	char padFD[0x100 - 0xfd];
	int unknown100;
	int unknown104;
	int unknown108;
	int unknown10C;
	int unknown110;
	int unknown114;
	int unknown118;
	int unknown11C;
	OpQ2_Obj55d4c0_120 unknown120;
	int unknown128;
	int unknown12C;
	int unknown130;
	int unknown134;
	int unknown138;
	vector<int> unknown13C;
	int unknown14C;
	int unknown150;
	int unknown154;
	int unknown158;
	int unknown15C;
	int unknown160;
	bool unknown164;
	bool unknown165;
	char pad166[0x168 - 0x166];
	int unknown168;
	int unknown16C;
	int unknown170;
	string unknown174;
	int unknown190;
	int unknown194;
	int unknown198;
	int unknown19C;
	int unknown1A0;
	bool unknown1A4;
	char pad1A5[0x1a8 - 0x1a5];
	int unknown1A8;
	bool unknown1AC;
	bool unknown1AD;
	bool unknown1AE;
	bool unknown1AF;
	bool unknown1B0;
	char pad1B1[0x1b4 - 0x1b1];
	string unknown1B4;
	vector<int> unknown1D0;
	vector<int> unknown1E0;
	int unknown1F0;
	vector<int> unknown1F4;
	int unknown204;
	bool unknown208;
	bool unknown209;
	bool unknown20A;
	bool unknown20B;
	int unknown20C;
	vector<int> unknown210;
	int unknown220;
	int unknown224;
	int unknown228;
	bool unknown22C;
	char pad22D[0x230 - 0x22d];
	int unknown230;
	int unknown234;
	bool unknown238;
	bool unknown239;
	bool unknown23A;
	bool unknown23B;
	vector<int> unknown23C;
	bool unknown24C;
	char pad24D[0x250 - 0x24d];
	vector<int> unknown250;
	vector<int> unknown260;
	bool unknown270;
	bool unknown271;
	bool unknown272;
	bool unknown273;
	bool unknown274;
	bool unknown275;
	char pad276[0x278 - 0x276];
	int unknown278;
	int unknown27C;
	int unknown280;
	int unknown284;
	string unknown288;
	OpQ2_Rec55d4c0(OpQ2_Stream *stream);
};

OpQ2_Rec55d4c0::OpQ2_Rec55d4c0(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f9d8480(stream,&unknown4);
	opq2_f4096f0(stream,&unknown8);
	opq2_f4096f0(stream,&unknown24);
	opq2_f9d8480(stream,&unknown40);
	opq2_f9d8480(stream,&unknown44);
	opq2_f9d8480(stream,&unknown48);
	opq2_f9d8480(stream,&unknown4C);
	opq2_f9d8480(stream,&unknown50);
	opq2_f9d8480(stream,&unknown54);
	opq2_f9d8480(stream,&unknown58);
	opq2_f9d8480(stream,&unknown5C);
	opq2_f9d8480(stream,&unknown60);
	opq2_f9d8480(stream,&unknown64);
	opq2_f9d8480(stream,&unknown68);
	opq2_f9d8480(stream,&unknown6C);
	opq2_f9d8480(stream,&unknown70);
	opq2_f9cf520(stream,&unknown74);
	opq2_f9cf520(stream,&unknown75);
	opq2_f9cf520(stream,&unknown76);
	opq2_f9d8480(stream,&unknown78);
	unknown7C.f437560(stream);
	opq2_f9d8480(stream,&unknown8C);
	opq2_f9cf520(stream,&unknown90);
	opq2_f9d8480(stream,&unknown94);
	opq2_f9d8480(stream,&unknown98);
	opq2_f9d8480(stream,&unknown9C);
	opq2_f9d8480(stream,&unknownA0);
	opq2_f9d8480(stream,&unknownA4);
	opq2_f465ea0(stream,&unknownA8);
	opq2_f465ea0(stream,&unknownAC);
	opq2_f9d8480(stream,&unknownB0);
	opq2_f9d8480(stream,&unknownB4);
	opq2_f9d8480(stream,&unknownB8);
	opq2_f9d8480(stream,&unknownBC);
	opq2_f9d8480(stream,&unknownC0);
	opq2_f9d8480(stream,&unknownC4);
	opq2_f9d8480(stream,&unknownC8);
	opq2_f9d8480(stream,&unknownCC);
	opq2_f9d8480(stream,&unknownD0);
	opq2_f9d8480(stream,&unknownD4);
	opq2_f9d8480(stream,&unknownD8);
	opq2_f9d8480(stream,&unknownDC);
	opq2_f9d8480(stream,&unknownE0);
	opq2_f9d8480(stream,&unknownE4);
	opq2_f9d8480(stream,&unknownE8);
	opq2_f9d8480(stream,&unknownEC);
	opq2_f9d8480(stream,&unknownF0);
	opq2_f9d8480(stream,&unknownF4);
	opq2_f9d8480(stream,&unknownF8);
	opq2_f9cf520(stream,&unknownFC);
	opq2_f465ea0(stream,&unknown100);
	opq2_f9d8480(stream,&unknown104);
	opq2_f9d8480(stream,&unknown108);
	opq2_f9d8480(stream,&unknown10C);
	opq2_f9d8480(stream,&unknown110);
	opq2_f9d8480(stream,&unknown114);
	opq2_f9d8480(stream,&unknown118);
	opq2_f9d8480(stream,&unknown11C);
	unknown120.f45f040(stream);
	opq2_f9d8480(stream,&unknown128);
	opq2_f9d8480(stream,&unknown12C);
	opq2_f9d8480(stream,&unknown130);
	opq2_f9d8480(stream,&unknown134);
	opq2_f9d8480(stream,&unknown138);
	opq2_f9cf5e0(stream,&unknown13C);
	opq2_f9d8480(stream,&unknown14C);
	opq2_f9d8480(stream,&unknown150);
	opq2_f9d8480(stream,&unknown154);
	opq2_f9d8480(stream,&unknown158);
	opq2_f9d8480(stream,&unknown15C);
	opq2_f9d8480(stream,&unknown160);
	opq2_f9cf520(stream,&unknown164);
	opq2_f9cf520(stream,&unknown165);
	opq2_f9d8480(stream,&unknown168);
	opq2_f9d8480(stream,&unknown16C);
	opq2_f9d8480(stream,&unknown170);
	opq2_f4096f0(stream,&unknown174);
	opq2_f9d6300(stream,&unknown190,opq2_gcf67c0);
	opq2_f9d6300(stream,&unknown194,opq2_gcf67c0);
	opq2_f9d6300(stream,&unknown198,opq2_gcf67c0);
	opq2_f9d6300(stream,&unknown19C,opq2_gcf67c0);
	opq2_f9d8110(stream,&unknown1A0,opq2_gcfd2cc);
	opq2_f9cf520(stream,&unknown1A4);
	opq2_f9d8110(stream,&unknown1A8,opq2_gcfd2cc);
	opq2_f9cf520(stream,&unknown1AC);
	opq2_f9cf520(stream,&unknown1AD);
	opq2_f9cf520(stream,&unknown1AE);
	opq2_f9cf520(stream,&unknown1AF);
	opq2_f9cf520(stream,&unknown1B0);
	opq2_f4096f0(stream,&unknown1B4);
	opq2_f9d6580(stream,&unknown1D0,0);
	opq2_f9d8200(stream,&unknown1E0,opq2_gd2c408);
	opq2_f9d8480(stream,&unknown1F0);
	opq2_f9cf5e0(stream,&unknown1F4);
	opq2_f9d8480(stream,&unknown204);
	opq2_f9cf520(stream,&unknown208);
	opq2_f9cf520(stream,&unknown209);
	opq2_f9cf520(stream,&unknown20A);
	opq2_f9cf520(stream,&unknown20B);
	opq2_f9d8480(stream,&unknown20C);
	opq2_f9cf5e0(stream,&unknown210);
	opq2_f9d8480(stream,&unknown220);
	opq2_f9d8480(stream,&unknown224);
	opq2_f9d8480(stream,&unknown228);
	opq2_f9cf520(stream,&unknown22C);
	opq2_f9d8480(stream,&unknown230);
	opq2_f9d8480(stream,&unknown234);
	opq2_f9cf520(stream,&unknown238);
	opq2_f9cf520(stream,&unknown239);
	opq2_f9cf520(stream,&unknown23A);
	opq2_f9cf520(stream,&unknown23B);
	opq2_f4097e0(stream,&unknown23C);
	opq2_f9cf520(stream,&unknown24C);
	opq2_f9cf5e0(stream,&unknown250);
	opq2_f9d8250(stream,&unknown260,0);
	opq2_f9cf520(stream,&unknown270);
	opq2_f9cf520(stream,&unknown271);
	opq2_f9cf520(stream,&unknown272);
	opq2_f9cf520(stream,&unknown273);
	opq2_f9cf520(stream,&unknown274);
	opq2_f9cf520(stream,&unknown275);
	opq2_f9d8390(stream,&unknown278,opq2_gd223b4);
	opq2_f9d8480(stream,&unknown27C);
	opq2_f9d5880(stream,&unknown280,opq2_gcfd2ec);
	opq2_f9d8480(stream,&unknown284);
	opq2_f4096f0(stream,&unknown288);
}
// eh False size 0xf9
struct OpQ2_Obj659ff0_0	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj659ff0_2C	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9da000(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9d9600(OpQ2_Stream *stream, void *p1);
void opq2_f9d2130(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec659ff0	// NOTE: placeholder name
{
	OpQ2_Obj659ff0_0 unknown0;
	int unknown4;
	int unknown8;
	void * unknownC;
	void * unknown10;
	bool unknown14;
	bool unknown15;
	char pad16[0x18 - 0x16];
	char unknown18[16];
	int unknown28;
	OpQ2_Obj659ff0_2C unknown2C;
	vector<int> unknown34;
	bool unknown44;
	bool unknown45;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec659ff0::save(OpQ2_Stream *stream)
{
	unknown0.f9cfa90(stream);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknown8);
	opq2_f9da000(stream,unknownC);
	opq2_f9da000(stream,unknown10);
	opq2_f9cf540(stream,&unknown14);
	opq2_f9cf540(stream,&unknown15);
	opq2_f9d9600(stream,&unknown18);
	opq2_f9d3b60(stream,&unknown28);
	unknown2C.f40a370(stream);
	opq2_f9d2130(stream,&unknown34);
	opq2_f9cf540(stream,&unknown44);
	opq2_f9cf540(stream,&unknown45);
}
// eh True size 0x16b
struct OpQ2_Obj65a0f0_0	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj65a0f0_0();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj65a0f0_2C	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj65a0f0_2C();
	void f40a330(OpQ2_Stream *stream);
};
extern char opq2_gd25de0[];
extern char opq2_gd2d1c4[];
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9d6fc0(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d69b0(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9da130(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec65a0f0	// NOTE: placeholder name
{
	OpQ2_Obj65a0f0_0 unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	bool unknown14;
	bool unknown15;
	char pad16[0x18 - 0x16];
	vector<int> unknown18;
	int unknown28;
	OpQ2_Obj65a0f0_2C unknown2C;
	vector<int> unknown34;
	bool unknown44;
	bool unknown45;
	OpQ2_Rec65a0f0(OpQ2_Stream *stream);
};

OpQ2_Rec65a0f0::OpQ2_Rec65a0f0(OpQ2_Stream *stream)
{
	unknown0.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8480(stream,&unknown8);
	opq2_f9d6fc0(stream,&unknownC,opq2_gd2d1c4);
	opq2_f9d69b0(stream,&unknown10,opq2_gd25de0);
	opq2_f9cf520(stream,&unknown14);
	opq2_f9cf520(stream,&unknown15);
	opq2_f9da130(stream,&unknown18);
	opq2_f9d8480(stream,&unknown28);
	unknown2C.f40a330(stream);
	opq2_f9cf5e0(stream,&unknown34);
	opq2_f9cf520(stream,&unknown44);
	opq2_f9cf520(stream,&unknown45);
}
// eh False size 0x163
struct OpQ2_Obj65d680_0	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj65d680_8	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
struct OpQ2_Obj65d680_18	// NOTE: placeholder name
{
	char data[3];
	void f411ec0(OpQ2_Stream *stream);
};
struct OpQ2_Obj65d680_1B	// NOTE: placeholder name
{
	char data[3];
	void f411ec0(OpQ2_Stream *stream);
};
void opq2_f9da000(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d6770(OpQ2_Stream *stream, void *p1);
void opq2_f9d84d0(OpQ2_Stream *stream, void *p1);
void opq2_f9d9cb0(OpQ2_Stream *stream, void *p1);
void opq2_f9d9cf0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec65d680	// NOTE: placeholder name
{
	OpQ2_Obj65d680_0 unknown0;
	void * unknown4;
	OpQ2_Obj65d680_8 unknown8;
	bool unknown10;
	char pad11[0x14 - 0x11];
	int unknown14;
	OpQ2_Obj65d680_18 unknown18;
	OpQ2_Obj65d680_1B unknown1B;
	bool unknown1E;
	char pad1F[0x20 - 0x1f];
	char unknown20[16];
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3C;
	bool unknown40;
	bool unknown41;
	bool unknown42;
	char pad43[0x44 - 0x43];
	int unknown44;
	bool unknown48;
	char pad49[0x4c - 0x49];
	int unknown4C;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec65d680::save(OpQ2_Stream *stream)
{
	unknown0.f9cfa90(stream);
	opq2_f9da000(stream,unknown4);
	unknown8.f40a370(stream);
	opq2_f9cf540(stream,&unknown10);
	opq2_f9d3b60(stream,&unknown14);
	unknown18.f411ec0(stream);
	unknown1B.f411ec0(stream);
	opq2_f9cf540(stream,&unknown1E);
	opq2_f9d6770(stream,&unknown20);
	opq2_f9d84d0(stream,&unknown30);
	opq2_f9d3b60(stream,&unknown34);
	opq2_f9d3b60(stream,&unknown38);
	opq2_f9d3b60(stream,&unknown3C);
	opq2_f9cf540(stream,&unknown40);
	opq2_f9cf540(stream,&unknown41);
	opq2_f9cf540(stream,&unknown42);
	opq2_f9d9cb0(stream,&unknown44);
	opq2_f9cf540(stream,&unknown48);
	opq2_f9d9cf0(stream,&unknown4C);
}
// eh True size 0x1d9
struct OpQ2_Obj65d7f0_0	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj65d7f0_0();
	void f9cfaf0(OpQ2_Stream *stream);
};
struct OpQ2_Obj65d7f0_8	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj65d7f0_8();
	void f40a330(OpQ2_Stream *stream);
};
struct OpQ2_Obj65d7f0_18	// NOTE: placeholder name
{
	char data[3];
	OpQ2_Obj65d7f0_18();
	void f411e70(OpQ2_Stream *stream);
};
struct OpQ2_Obj65d7f0_1B	// NOTE: placeholder name
{
	char data[3];
	OpQ2_Obj65d7f0_1B();
	void f411e70(OpQ2_Stream *stream);
};
extern char opq2_gcf35b0[];
void opq2_f9d9d30(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9d6580(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9d8510(OpQ2_Stream *stream, void *p1);
void opq2_f9d9e20(OpQ2_Stream *stream, void *p1);
void opq2_f9d9ed0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec65d7f0	// NOTE: placeholder name
{
	OpQ2_Obj65d7f0_0 unknown0;
	int unknown4;
	OpQ2_Obj65d7f0_8 unknown8;
	bool unknown10;
	char pad11[0x14 - 0x11];
	int unknown14;
	OpQ2_Obj65d7f0_18 unknown18;
	OpQ2_Obj65d7f0_1B unknown1B;
	bool unknown1E;
	char pad1F[0x20 - 0x1f];
	vector<int> unknown20;
	int unknown30;
	int unknown34;
	int unknown38;
	int unknown3C;
	bool unknown40;
	bool unknown41;
	bool unknown42;
	char pad43[0x44 - 0x43];
	int unknown44;
	bool unknown48;
	char pad49[0x4c - 0x49];
	int unknown4C;
	OpQ2_Rec65d7f0(OpQ2_Stream *stream);
};

OpQ2_Rec65d7f0::OpQ2_Rec65d7f0(OpQ2_Stream *stream)
{
	unknown0.f9cfaf0(stream);
	opq2_f9d9d30(stream,&unknown4,opq2_gcf35b0);
	unknown8.f40a330(stream);
	opq2_f9cf520(stream,&unknown10);
	opq2_f9d8480(stream,&unknown14);
	unknown18.f411e70(stream);
	unknown1B.f411e70(stream);
	opq2_f9cf520(stream,&unknown1E);
	opq2_f9d6580(stream,&unknown20,0);
	opq2_f9d8510(stream,&unknown30);
	opq2_f9d8480(stream,&unknown34);
	opq2_f9d8480(stream,&unknown38);
	opq2_f9d8480(stream,&unknown3C);
	opq2_f9cf520(stream,&unknown40);
	opq2_f9cf520(stream,&unknown41);
	opq2_f9cf520(stream,&unknown42);
	opq2_f9d9e20(stream,&unknown44);
	opq2_f9cf520(stream,&unknown48);
	opq2_f9d9ed0(stream,&unknown4C);
}
// eh False size 0xb1
struct OpQ2_Obj6710b0_0	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d9600(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9d25c0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec6710b0	// NOTE: placeholder name
{
	OpQ2_Obj6710b0_0 unknown0;
	int unknown4;
	int unknown8;
	char unknownC[16];
	bool unknown1C;
	char pad1D[0x20 - 0x1d];
	int unknown20;
	int unknown24;
	bool unknown28;
	char pad29[0x2c - 0x29];
	int unknown2C;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec6710b0::save(OpQ2_Stream *stream)
{
	unknown0.f9cfa90(stream);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknown8);
	opq2_f9d9600(stream,&unknownC);
	opq2_f9cf540(stream,&unknown1C);
	opq2_f9d3b60(stream,&unknown20);
	opq2_f9d3b60(stream,&unknown24);
	opq2_f9cf540(stream,&unknown28);
	opq2_f9d25c0(stream,&unknown2C);
}
// eh True size 0x10e
struct OpQ2_Obj671170_0	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj671170_0();
	void f9cfaf0(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9da130(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9d2560(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec671170	// NOTE: placeholder name
{
	OpQ2_Obj671170_0 unknown0;
	int unknown4;
	int unknown8;
	vector<int> unknownC;
	bool unknown1C;
	char pad1D[0x20 - 0x1d];
	int unknown20;
	int unknown24;
	bool unknown28;
	char pad29[0x2c - 0x29];
	vector<int> unknown2C;
	OpQ2_Rec671170(OpQ2_Stream *stream);
};

OpQ2_Rec671170::OpQ2_Rec671170(OpQ2_Stream *stream)
{
	unknown0.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8480(stream,&unknown8);
	opq2_f9da130(stream,&unknownC);
	opq2_f9cf520(stream,&unknown1C);
	opq2_f9d8480(stream,&unknown20);
	opq2_f9d8480(stream,&unknown24);
	opq2_f9cf520(stream,&unknown28);
	opq2_f9d2560(stream,&unknown2C);
}
// eh True size 0xef
struct OpQ2_Obj673480_4	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj673480_4();
	void f9cfaf0(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec673480	// NOTE: placeholder name
{
	int unknown0;
	OpQ2_Obj673480_4 unknown4;
	int unknown8;
	bool unknownC;
	char padD[0x10 - 0xd];
	int unknown10;
	int unknown14;
	int unknown18;
	string unknown1C;
	OpQ2_Rec673480(OpQ2_Stream *stream);
};

OpQ2_Rec673480::OpQ2_Rec673480(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	unknown4.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknown8);
	opq2_f9cf520(stream,&unknownC);
	opq2_f9d8480(stream,&unknown10);
	opq2_f9d8480(stream,&unknown14);
	opq2_f9d8480(stream,&unknown18);
	opq2_f4096f0(stream,&unknown1C);
}
// eh False size 0xcb
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec6738d0	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	int unknown8;
	bool unknownC;
	bool unknownD;
	bool unknownE;
	bool unknownF;
	bool unknown10;
	bool unknown11;
	bool unknown12;
	OpQ2_Rec6738d0(OpQ2_Stream *stream);
};

OpQ2_Rec6738d0::OpQ2_Rec6738d0(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8480(stream,&unknown8);
	opq2_f9cf520(stream,&unknownC);
	opq2_f9cf520(stream,&unknownD);
	opq2_f9cf520(stream,&unknownE);
	opq2_f9cf520(stream,&unknownF);
	opq2_f9cf520(stream,&unknown10);
	opq2_f9cf520(stream,&unknown11);
	opq2_f9cf520(stream,&unknown12);
}
// eh False size 0xc8
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec6739a0	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	int unknown8;
	bool unknownC;
	bool unknownD;
	bool unknownE;
	bool unknownF;
	bool unknown10;
	bool unknown11;
	bool unknown12;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec6739a0::save(OpQ2_Stream *stream)
{
	opq2_f9d3b60(stream,&unknown0);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknown8);
	opq2_f9cf540(stream,&unknownC);
	opq2_f9cf540(stream,&unknownD);
	opq2_f9cf540(stream,&unknownE);
	opq2_f9cf540(stream,&unknownF);
	opq2_f9cf540(stream,&unknown10);
	opq2_f9cf540(stream,&unknown11);
	opq2_f9cf540(stream,&unknown12);
}
// eh False size 0x5b0
struct OpQ2_Obj6744d0_2C	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_60	// NOTE: placeholder name
{
	char data[12];
	void f9d26a0(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_C0	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_C8	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_D4	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_E8	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_F0	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_F8	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_12C	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
struct OpQ2_Obj6744d0_184	// NOTE: placeholder name
{
	char data[8];
	void f40a370(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d2130(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9da750(OpQ2_Stream *stream, void *p1);
void opq2_f9da7b0(OpQ2_Stream *stream, void *p1);
void opq2_f9d0840(OpQ2_Stream *stream, void *p1);
void opq2_f9d9600(OpQ2_Stream *stream, void *p1);
void opq2_f9da7f0(OpQ2_Stream *stream, void *p1);
void opq2_f9d2190(OpQ2_Stream *stream, void *p1);
void opq2_f9da850(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec6744d0	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	int unknown8;
	int unknownC;
	int unknown10;
	int unknown14;
	vector<int> unknown18;
	int unknown28;
	OpQ2_Obj6744d0_2C unknown2C;
	bool unknown30;
	bool unknown31;
	char pad32[0x34 - 0x32];
	int unknown34;
	int unknown38;
	int unknown3C;
	bool unknown40;
	bool unknown41;
	char pad42[0x44 - 0x42];
	int unknown44;
	bool unknown48;
	bool unknown49;
	bool unknown4A;
	char pad4B[0x4c - 0x4b];
	int unknown4C;
	char unknown50[16];
	OpQ2_Obj6744d0_60 unknown60;
	int unknown6C;
	int unknown70;
	int unknown74;
	bool unknown78;
	char pad79[0x7c - 0x79];
	int unknown7C;
	int unknown80;
	int unknown84;
	int unknown88;
	int unknown8C;
	int unknown90;
	int unknown94;
	char unknown98[16];
	vector<int> unknownA8;
	int unknownB8;
	int unknownBC;
	OpQ2_Obj6744d0_C0 unknownC0;
	OpQ2_Obj6744d0_C8 unknownC8;
	int unknownD0;
	OpQ2_Obj6744d0_D4 unknownD4;
	char unknownD8[16];
	OpQ2_Obj6744d0_E8 unknownE8;
	int unknownEC;
	OpQ2_Obj6744d0_F0 unknownF0;
	OpQ2_Obj6744d0_F8 unknownF8;
	bool unknown100;
	char pad101[0x104 - 0x101];
	int unknown104;
	char unknown108[16];
	char unknown118[16];
	int unknown128;
	OpQ2_Obj6744d0_12C unknown12C;
	int unknown134;
	int unknown138;
	int unknown13C;
	int unknown140;
	int unknown144;
	char unknown148[16];
	char unknown158[16];
	bool unknown168;
	char pad169[0x16c - 0x169];
	vector<int> unknown16C;
	int unknown17C;
	int unknown180;
	OpQ2_Obj6744d0_184 unknown184;
	int unknown18C;
	int unknown190;
	bool unknown194;
	bool unknown195;
	bool unknown196;
	bool unknown197;
	bool unknown198;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec6744d0::save(OpQ2_Stream *stream)
{
	opq2_f9d3b60(stream,&unknown0);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknown8);
	opq2_f9d3b60(stream,&unknownC);
	opq2_f9d3b60(stream,&unknown10);
	opq2_f9d3b60(stream,&unknown14);
	opq2_f9d2130(stream,&unknown18);
	opq2_f9d3b60(stream,&unknown28);
	unknown2C.f9cfa90(stream);
	opq2_f9cf540(stream,&unknown30);
	opq2_f9cf540(stream,&unknown31);
	opq2_f9d3b60(stream,&unknown34);
	opq2_f9d3b60(stream,&unknown38);
	opq2_f9d3b60(stream,&unknown3C);
	opq2_f9cf540(stream,&unknown40);
	opq2_f9cf540(stream,&unknown41);
	opq2_f9d3b60(stream,&unknown44);
	opq2_f9cf540(stream,&unknown48);
	opq2_f9cf540(stream,&unknown49);
	opq2_f9cf540(stream,&unknown4A);
	opq2_f9d3b60(stream,&unknown4C);
	opq2_f9da750(stream,&unknown50);
	unknown60.f9d26a0(stream);
	opq2_f9d3b60(stream,&unknown6C);
	opq2_f9d3b60(stream,&unknown70);
	opq2_f9d3b60(stream,&unknown74);
	opq2_f9cf540(stream,&unknown78);
	opq2_f9d3b60(stream,&unknown7C);
	opq2_f9d3b60(stream,&unknown80);
	opq2_f9d3b60(stream,&unknown84);
	opq2_f9d3b60(stream,&unknown88);
	opq2_f9d3b60(stream,&unknown8C);
	opq2_f9da7b0(stream,&unknown90);
	opq2_f9d3b60(stream,&unknown94);
	opq2_f9d0840(stream,&unknown98);
	opq2_f9d2130(stream,&unknownA8);
	opq2_f9d3b60(stream,&unknownEC);
	unknownF0.f40a370(stream);
	unknownF8.f40a370(stream);
	opq2_f9cf540(stream,&unknown100);
	opq2_f9d3b60(stream,&unknown104);
	opq2_f9d3b60(stream,&unknownB8);
	opq2_f9d3b60(stream,&unknownBC);
	unknownC0.f40a370(stream);
	unknownC8.f40a370(stream);
	opq2_f9d3b60(stream,&unknownD0);
	unknownD4.f9cfa90(stream);
	opq2_f9d9600(stream,&unknownD8);
	unknownE8.f9cfa90(stream);
	opq2_f9da7f0(stream,&unknown108);
	opq2_f9d0840(stream,&unknown118);
	opq2_f9d3b60(stream,&unknown128);
	unknown12C.f40a370(stream);
	opq2_f9d3b60(stream,&unknown134);
	opq2_f9d3b60(stream,&unknown138);
	opq2_f9d3b60(stream,&unknown13C);
	opq2_f9d3b60(stream,&unknown140);
	opq2_f9d3b60(stream,&unknown144);
	opq2_f9d2190(stream,&unknown148);
	opq2_f9da850(stream,&unknown158);
	opq2_f9cf540(stream,&unknown168);
	opq2_f9d2130(stream,&unknown16C);
	opq2_f9d3b60(stream,&unknown17C);
	opq2_f9d3b60(stream,&unknown180);
	unknown184.f40a370(stream);
	opq2_f9d3b60(stream,&unknown18C);
	opq2_f9d3b60(stream,&unknown190);
	opq2_f9cf540(stream,&unknown194);
	opq2_f9cf540(stream,&unknown195);
	opq2_f9cf540(stream,&unknown196);
	opq2_f9cf540(stream,&unknown197);
	opq2_f9cf540(stream,&unknown198);
}
// eh False size 0x67f
struct OpQ2_Obj69cbb0_C	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj69cbb0_18	// NOTE: placeholder name
{
	char data[8];
	void f40bf20(OpQ2_Stream *stream);
};
struct OpQ2_Obj69cbb0_144	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
struct OpQ2_Obj69cbb0_16C	// NOTE: placeholder name
{
	char data[16];
	void f40b420(OpQ2_Stream *stream);
};
struct OpQ2_Obj69cbb0_1B4	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d2130(OpQ2_Stream *stream, void *p1);
void opq2_f9d2190(OpQ2_Stream *stream, void *p1);
void opq2_f9d9600(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec69cbb0	// NOTE: placeholder name
{
	bool unknown0;
	char pad1[0x4 - 0x1];
	int unknown4;
	int unknown8;
	OpQ2_Obj69cbb0_C unknownC;
	int unknown10;
	int unknown14;
	OpQ2_Obj69cbb0_18 unknown18;
	vector<int> unknown20;
	vector<int> unknown30;
	vector<int> unknown40;
	vector<int> unknown50;
	vector<int> unknown60;
	int unknown70;
	char pad74[0x78 - 0x74];
	int unknown78;
	int unknown7C;
	int unknown80;
	int unknown84;
	int unknown88;
	int unknown8C;
	int unknown90;
	char pad94[0x9c - 0x94];
	int unknown9C;
	char padA0[0xb0 - 0xa0];
	int unknownB0;
	vector<int> unknownB4;
	int unknownC4;
	int unknownC8;
	bool unknownCC;
	char padCD[0xd0 - 0xcd];
	int unknownD0;
	int unknownD4;
	int unknownD8;
	int unknownDC;
	int unknownE0;
	int unknownE4;
	int unknownE8;
	int unknownEC;
	int unknownF0;
	int unknownF4;
	int unknownF8;
	int unknownFC;
	int unknown100;
	int unknown104;
	int unknown108;
	int unknown10C;
	int unknown110;
	int unknown114;
	int unknown118;
	int unknown11C;
	vector<int> unknown120;
	vector<int> unknown130;
	int unknown140;
	OpQ2_Obj69cbb0_144 unknown144;
	char unknown148[16];
	bool unknown158;
	bool unknown159;
	char pad15A[0x15c - 0x15a];
	int unknown15C;
	bool unknown160;
	bool unknown161;
	bool unknown162;
	bool unknown163;
	int unknown164;
	int unknown168;
	OpQ2_Obj69cbb0_16C unknown16C;
	int unknown17C;
	bool unknown180;
	char pad181[0x184 - 0x181];
	vector<int> unknown184;
	int unknown194;
	char unknown198[16];
	int unknown1A8;
	int unknown1AC;
	int unknown1B0;
	OpQ2_Obj69cbb0_1B4 unknown1B4;
	int unknown1B8;
	int unknown1BC;
	bool unknown1C0;
	bool unknown1C1;
	bool unknown1C2;
	char pad1C3[0x1c4 - 0x1c3];
	int unknown1C4;
	int unknown1C8;
	int unknown1CC;
	bool unknown1D0;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec69cbb0::save(OpQ2_Stream *stream)
{
	opq2_f9cf540(stream,&unknown0);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknown8);
	unknownC.f9cfa90(stream);
	opq2_f9d3b60(stream,&unknown10);
	opq2_f9d3b60(stream,&unknown14);
	unknown18.f40bf20(stream);
	opq2_f9d2130(stream,&unknown20);
	opq2_f9d2130(stream,&unknown30);
	opq2_f9d2130(stream,&unknown40);
	opq2_f9d2130(stream,&unknown50);
	opq2_f9d2130(stream,&unknown60);
	opq2_f9d3b60(stream,&unknown70);
	opq2_f9d3b60(stream,&unknown78);
	opq2_f9d3b60(stream,&unknown7C);
	opq2_f9d3b60(stream,&unknown80);
	opq2_f9d3b60(stream,&unknown84);
	opq2_f9d3b60(stream,&unknown88);
	opq2_f9d3b60(stream,&unknown8C);
	opq2_f9d3b60(stream,&unknown90);
	opq2_f9d3b60(stream,&unknown9C);
	opq2_f9d3b60(stream,&unknownB0);
	opq2_f9d2130(stream,&unknownB4);
	opq2_f9d3b60(stream,&unknownC4);
	opq2_f9d3b60(stream,&unknownC8);
	opq2_f9cf540(stream,&unknownCC);
	opq2_f9d3b60(stream,&unknownD0);
	opq2_f9d3b60(stream,&unknownD4);
	opq2_f9d3b60(stream,&unknownD8);
	opq2_f9d3b60(stream,&unknownDC);
	opq2_f9d3b60(stream,&unknownE0);
	opq2_f9d3b60(stream,&unknownE4);
	opq2_f9d3b60(stream,&unknownE8);
	opq2_f9d3b60(stream,&unknownEC);
	opq2_f9d3b60(stream,&unknownF0);
	opq2_f9d3b60(stream,&unknownF4);
	opq2_f9d3b60(stream,&unknownF8);
	opq2_f9d3b60(stream,&unknownFC);
	opq2_f9d3b60(stream,&unknown100);
	opq2_f9d3b60(stream,&unknown104);
	opq2_f9d3b60(stream,&unknown108);
	opq2_f9d3b60(stream,&unknown10C);
	opq2_f9d3b60(stream,&unknown110);
	opq2_f9d3b60(stream,&unknown114);
	opq2_f9d3b60(stream,&unknown118);
	opq2_f9d3b60(stream,&unknown11C);
	opq2_f9d2130(stream,&unknown120);
	opq2_f9d2130(stream,&unknown130);
	opq2_f9d3b60(stream,&unknown140);
	unknown144.f9cfa90(stream);
	opq2_f9d2190(stream,&unknown148);
	opq2_f9cf540(stream,&unknown158);
	opq2_f9cf540(stream,&unknown159);
	opq2_f9d3b60(stream,&unknown15C);
	opq2_f9cf540(stream,&unknown160);
	opq2_f9cf540(stream,&unknown161);
	opq2_f9cf540(stream,&unknown162);
	opq2_f9cf540(stream,&unknown163);
	opq2_f9d3b60(stream,&unknown164);
	opq2_f9d3b60(stream,&unknown168);
	unknown16C.f40b420(stream);
	opq2_f9d3b60(stream,&unknown17C);
	opq2_f9cf540(stream,&unknown180);
	opq2_f9d2130(stream,&unknown184);
	opq2_f9d3b60(stream,&unknown194);
	opq2_f9d9600(stream,&unknown198);
	opq2_f9d3b60(stream,&unknown1A8);
	opq2_f9d3b60(stream,&unknown1AC);
	opq2_f9d3b60(stream,&unknown1B0);
	unknown1B4.f9cfa90(stream);
	opq2_f9d3b60(stream,&unknown1B8);
	opq2_f9d3b60(stream,&unknown1BC);
	opq2_f9cf540(stream,&unknown1C0);
	opq2_f9cf540(stream,&unknown1C1);
	opq2_f9cf540(stream,&unknown1C2);
	opq2_f9d3b60(stream,&unknown1C4);
	opq2_f9d3b60(stream,&unknown1C8);
	opq2_f9d3b60(stream,&unknown1CC);
	opq2_f9cf540(stream,&unknown1D0);
}
// eh False size 0x166
struct OpQ2_Obj6be9d0_6C	// NOTE: placeholder name
{
	char data[4];
	void f9cfaf0(OpQ2_Stream *stream);
};
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9cf5e0(OpQ2_Stream *stream, void *p1);
void opq2_f9db0a0(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9db1e0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec6be9d0	// NOTE: placeholder name
{
	bool unknown0;
	char pad1[0x4 - 0x1];
	int unknown4;
	int unknown8;
	int unknownC;
	vector<int> unknown10;
	vector<int> unknown20;
	vector<int> unknown30;
	int unknown40;
	int unknown44;
	vector<int> unknown48;
	char unknown58[16];
	int unknown68;
	OpQ2_Obj6be9d0_6C unknown6C;
	vector<int> unknown70;
	int unknown80;
	vector<int> unknown84;
	void load(OpQ2_Stream *stream);
	void f6be920();
};

void OpQ2_Rec6be9d0::load(OpQ2_Stream *stream)
{
	f6be920();
	opq2_f9cf520(stream,&unknown0);
	opq2_f9d8480(stream,&unknown8);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8480(stream,&unknownC);
	unknown10.clear();
	opq2_f9cf5e0(stream,&unknown10);
	unknown20.clear();
	opq2_f9cf5e0(stream,&unknown20);
	unknown30.clear();
	opq2_f9cf5e0(stream,&unknown30);
	opq2_f9d8480(stream,&unknown40);
	opq2_f9d8480(stream,&unknown44);
	opq2_f9cf5e0(stream,&unknown48);
	opq2_f9db0a0(stream,&unknown58,0);
	opq2_f9db1e0(stream,&unknown68);
	unknown6C.f9cfaf0(stream);
	opq2_f9cf5e0(stream,&unknown70);
	opq2_f9d8480(stream,&unknown80);
	opq2_f9cf5e0(stream,&unknown84);
}
// eh False size 0x13b
struct OpQ2_Obj6beb40_6C	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d2130(OpQ2_Stream *stream, void *p1);
void opq2_f9db290(OpQ2_Stream *stream, void *p1);
void opq2_f9db2f0(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec6beb40	// NOTE: placeholder name
{
	bool unknown0;
	char pad1[0x4 - 0x1];
	int unknown4;
	int unknown8;
	int unknownC;
	vector<int> unknown10;
	vector<int> unknown20;
	vector<int> unknown30;
	int unknown40;
	int unknown44;
	vector<int> unknown48;
	char unknown58[16];
	int unknown68;
	OpQ2_Obj6beb40_6C unknown6C;
	vector<int> unknown70;
	int unknown80;
	vector<int> unknown84;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec6beb40::save(OpQ2_Stream *stream)
{
	opq2_f9cf540(stream,&unknown0);
	opq2_f9d3b60(stream,&unknown8);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknownC);
	opq2_f9d2130(stream,&unknown10);
	opq2_f9d2130(stream,&unknown20);
	opq2_f9d2130(stream,&unknown30);
	opq2_f9d3b60(stream,&unknown40);
	opq2_f9d3b60(stream,&unknown44);
	opq2_f9d2130(stream,&unknown48);
	opq2_f9db290(stream,&unknown58);
	opq2_f9db2f0(stream,&unknown68);
	unknown6C.f9cfa90(stream);
	opq2_f9d2130(stream,&unknown70);
	opq2_f9d3b60(stream,&unknown80);
	opq2_f9d2130(stream,&unknown84);
}
// eh False size 0x52
struct OpQ2_Obj57f050_18	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9d8660(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec57f050	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	char unknown8[16];
	OpQ2_Obj57f050_18 unknown18;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec57f050::save(OpQ2_Stream *stream)
{
	opq2_f9d3b60(stream,&unknown0);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d8660(stream,&unknown8);
	unknown18.f9cfa90(stream);
}
// eh False size 0x43
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec65c110	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	bool unknown8;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec65c110::save(OpQ2_Stream *stream)
{
	opq2_f9d3b60(stream,&unknown0);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9cf540(stream,&unknown8);
}
// eh False size 0x46
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec65c160	// NOTE: placeholder name
{
	int unknown0;
	int unknown4;
	bool unknown8;
	OpQ2_Rec65c160(OpQ2_Stream *stream);
};

OpQ2_Rec65c160::OpQ2_Rec65c160(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9cf520(stream,&unknown8);
}
// eh False size 0x4a
struct OpQ2_Obj673a70_0	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj673a70_0();
	void f9cfaf0(OpQ2_Stream *stream);
};
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec673a70	// NOTE: placeholder name
{
	OpQ2_Obj673a70_0 unknown0;
	int unknown4;
	int unknown8;
	OpQ2_Rec673a70(OpQ2_Stream *stream);
};

OpQ2_Rec673a70::OpQ2_Rec673a70(OpQ2_Stream *stream)
{
	unknown0.f9cfaf0(stream);
	opq2_f9d8480(stream,&unknown4);
	opq2_f9d8480(stream,&unknown8);
}
// eh False size 0x3f
struct OpQ2_Obj673ac0_0	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
struct OpQ2_Rec673ac0	// NOTE: placeholder name
{
	OpQ2_Obj673ac0_0 unknown0;
	int unknown4;
	int unknown8;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec673ac0::save(OpQ2_Stream *stream)
{
	unknown0.f9cfa90(stream);
	opq2_f9d3b60(stream,&unknown4);
	opq2_f9d3b60(stream,&unknown8);
}
// eh False size 0xb2
struct OpQ2_Obj673570_4	// NOTE: placeholder name
{
	char data[4];
	void f9cfa90(OpQ2_Stream *stream);
};
void opq2_f9d3b60(OpQ2_Stream *stream, void *p1);
void opq2_f9cf540(OpQ2_Stream *stream, void *p1);
void opq2_f409650(OpQ2_Stream *stream, string value);
struct OpQ2_Rec673570	// NOTE: placeholder name
{
	int unknown0;
	OpQ2_Obj673570_4 unknown4;
	int unknown8;
	bool unknownC;
	char padD[0x10 - 0xd];
	int unknown10;
	int unknown14;
	int unknown18;
	string unknown1C;
	void save(OpQ2_Stream *stream);
};

void OpQ2_Rec673570::save(OpQ2_Stream *stream)
{
	opq2_f9d3b60(stream,&unknown0);
	unknown4.f9cfa90(stream);
	opq2_f9d3b60(stream,&unknown8);
	opq2_f9cf540(stream,&unknownC);
	opq2_f9d3b60(stream,&unknown10);
	opq2_f9d3b60(stream,&unknown14);
	opq2_f9d3b60(stream,&unknown18);
	opq2_f409650(stream,unknown1C);
}
// eh True size 0x54c
// WARN ('rawmov', 'dword ptr [edx + 0x154], 0')
struct OpQ2_Obj6592b0_3C	// NOTE: placeholder name
{
	char data[16];
	OpQ2_Obj6592b0_3C();
	~OpQ2_Obj6592b0_3C();
	void f437560(OpQ2_Stream *stream);
};
struct OpQ2_Obj6592b0_4C	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj6592b0_4C();
	void f40a330(OpQ2_Stream *stream);
};
struct OpQ2_Obj6592b0_84	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj6592b0_84();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj6592b0_94	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj6592b0_94();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj6592b0_148	// NOTE: placeholder name
{
	char data[8];
	OpQ2_Obj6592b0_148();
	void f45f040(OpQ2_Stream *stream);
};
struct OpQ2_Obj6592b0_16C	// NOTE: placeholder name
{
	char data[4];
	OpQ2_Obj6592b0_16C();
	void f411e70(OpQ2_Stream *stream);
};
extern char opq2_gcf671c[];
extern char opq2_gcf67c0[];
extern char opq2_gcfd2cc[];
extern char opq2_gcfd2ec[];
extern char opq2_gd2c408[];
void opq2_f9d8480(OpQ2_Stream *stream, void *p1);
void opq2_f4096f0(OpQ2_Stream *stream, void *p1);
void opq2_f9cf520(OpQ2_Stream *stream, void *p1);
void opq2_f9d92d0(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f465ea0(OpQ2_Stream *stream, void *p1);
void opq2_f9d8110(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d6300(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f9d4ec0(OpQ2_Stream *stream, void *p1);
void opq2_f9d6580(OpQ2_Stream *stream, void *p1, int a2);
void opq2_f9d8200(OpQ2_Stream *stream, void *p1, void *p2);
void opq2_f436960(OpQ2_Stream *stream, void *p1);
void opq2_f9d5880(OpQ2_Stream *stream, void *p1, void *p2);
struct OpQ2_Rec6592b0	// NOTE: placeholder name
{
	int unknown0;
	string unknown4;
	string unknown20;
	OpQ2_Obj6592b0_3C unknown3C;
	OpQ2_Obj6592b0_4C unknown4C;
	bool unknown54;
	bool unknown55;
	char pad56[0x58 - 0x56];
	int unknown58;
	bool unknown5C;
	char pad5D[0x60 - 0x5d];
	int unknown60;
	int unknown64;
	int unknown68;
	int unknown6C;
	int unknown70;
	int unknown74;
	bool unknown78;
	char pad79[0x7c - 0x79];
	int unknown7C;
	int unknown80;
	OpQ2_Obj6592b0_84 unknown84;
	int unknown8C;
	int unknown90;
	OpQ2_Obj6592b0_94 unknown94;
	int unknown9C;
	int unknownA0;
	int unknownA4;
	char unknownA8[28];
	bool unknownC4;
	bool unknownC5;
	char padC6[0xc8 - 0xc6];
	int unknownC8;
	int unknownCC;
	bool unknownD0;
	bool unknownD1;
	char padD2[0xd4 - 0xd2];
	vector<int> unknownD4;
	vector<int> unknownE4;
	int unknownF4;
	int unknownF8;
	bool unknownFC;
	char padFD[0x100 - 0xfd];
	char unknown100[12];
	char unknown10C[12];
	int unknown118;
	int unknown11C;
	int unknown120;
	string unknown124;
	int unknown140;
	int unknown144;
	OpQ2_Obj6592b0_148 unknown148;
	int unknown150;
	int unknown154;	// NOTE: placeholder name
	bool unknown158;
	char pad159[0x15c - 0x159];
	int unknown15C;
	int unknown160;
	int unknown164;
	int unknown168;
	OpQ2_Obj6592b0_16C unknown16C;
	OpQ2_Rec6592b0(OpQ2_Stream *stream);
};

OpQ2_Rec6592b0::OpQ2_Rec6592b0(OpQ2_Stream *stream)
{
	opq2_f9d8480(stream,&unknown0);
	opq2_f4096f0(stream,&unknown4);
	opq2_f4096f0(stream,&unknown20);
	unknown3C.f437560(stream);
	unknown4C.f40a330(stream);
	opq2_f9cf520(stream,&unknown54);
	opq2_f9cf520(stream,&unknown55);
	opq2_f9d8480(stream,&unknown58);
	opq2_f9cf520(stream,&unknown5C);
	opq2_f9d92d0(stream,&unknown60,opq2_gcf671c);
	opq2_f9d8480(stream,&unknown64);
	opq2_f9d8480(stream,&unknown68);
	opq2_f9d8480(stream,&unknown6C);
	opq2_f465ea0(stream,&unknown70);
	opq2_f9d8480(stream,&unknown74);
	opq2_f9cf520(stream,&unknown78);
	opq2_f9d8480(stream,&unknown7C);
	opq2_f9d8480(stream,&unknown80);
	unknown84.f45f040(stream);
	opq2_f9d8110(stream,&unknown8C,opq2_gcfd2cc);
	opq2_f9d6300(stream,&unknown90,opq2_gcf67c0);
	unknown94.f45f040(stream);
	opq2_f9d8480(stream,&unknown9C);
	opq2_f9d8480(stream,&unknownA0);
	opq2_f9d8480(stream,&unknownA4);
	opq2_f9d4ec0(stream,&unknownA8);
	opq2_f9cf520(stream,&unknownC4);
	opq2_f9cf520(stream,&unknownC5);
	opq2_f9d8480(stream,&unknownC8);
	opq2_f9d8480(stream,&unknownCC);
	opq2_f9cf520(stream,&unknownD0);
	opq2_f9cf520(stream,&unknownD1);
	opq2_f9d6580(stream,&unknownD4,0);
	opq2_f9d8200(stream,&unknownE4,opq2_gd2c408);
	opq2_f9d8480(stream,&unknownF4);
	opq2_f9d8480(stream,&unknownF8);
	opq2_f9cf520(stream,&unknownFC);
	opq2_f9d4ec0(stream,&unknown100);
	opq2_f9d4ec0(stream,&unknown10C);
	opq2_f9d8480(stream,&unknown118);
	opq2_f9d8480(stream,&unknown11C);
	opq2_f9d8480(stream,&unknown120);
	opq2_f436960(stream,&unknown124);
	opq2_f9d8480(stream,&unknown140);
	opq2_f9d8480(stream,&unknown144);
	unknown148.f45f040(stream);
	opq2_f9d8480(stream,&unknown150);
	unknown154 = 0;
	opq2_f9cf520(stream,&unknown158);
	opq2_f9d5880(stream,&unknown15C,opq2_gcfd2ec);
	opq2_f9d5880(stream,&unknown160,opq2_gcfd2ec);
	opq2_f9d8480(stream,&unknown164);
	opq2_f9d8480(stream,&unknown168);
	unknown16C.f411e70(stream);
}
