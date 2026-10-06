// op_v3d_ascii: GM::unknown78d700 (toggle ascii/glyph mode), Beta 17.1.
#include "op_v3d.h"

bool OpU8a_lookup2(const string &name, int *value);	// NOTE: placeholder name (0x9d7980)

extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern int opv3d_tableGlyph[17];	// NOTE: placeholder name (0xba6a28)
extern int opv3d_tableAscii[17];	// NOTE: placeholder name (0xba69e0)

struct OpV3d_PropRec	// NOTE: placeholder name
{
	char pad00[0x4c];
	vector<int> glyphs;	// NOTE: placeholder name
};

class BS
{
public:
	void unknown7355a0();	// NOTE: placeholder name
};
extern BS *opv3d_world;	// NOTE: placeholder name (0xcefc4c)

class CAllies : public Console
{
public:
	void unknown48f310();	// NOTE: placeholder name
};
extern CAllies *opv3d_cec0c8;	// NOTE: placeholder name

class CInventory : public Console
{
public:
	void reopen(int mode, HItem item);	// NOTE: placeholder signature (0x8a2ce0)
};
extern CInventory *opv3d_cec08c;	// NOTE: placeholder name

class OpV3d_Colors	// NOTE: placeholder name
{
public:
	void setEarthColors();	// NOTE: placeholder name (0x7935b0)
};

struct OpV3d_GM	// NOTE: placeholder name (0xcefaa8)
{
	void unknown78d700(bool a, bool b);	// NOTE: placeholder name
	void setEarthColors();	// NOTE: placeholder name (0x7935b0)
};

void OpV3d_GM::unknown78d700(bool a, bool b)
{
	asciiEnabled = !asciiEnabled;
	vector<OpV3d_PropRec*> ids;
	{
		OpV3d_PropRec *id;
		if (OpU8a_lookup2("P_De_Debris_Basic",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_De_Debris_Matter",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_De_Debris_Static",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_Basic",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_NR",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_FM",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_QG",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_AR",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_AD",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_AC",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_IA",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_TC",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_AS",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Si_Debris_SI",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("Ro_Debris_Sml",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("Ro_Debris_Med",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("Ro_Debris_Lrg",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("Ro_Crushed_Debris",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("P_Machinery_Spill",(int*)&id))
			ids.push_back(id);
		if (OpU8a_lookup2("MA_Debris_WS",(int*)&id))
			ids.push_back(id);
	}
	for (unsigned int i = 0; i < ids.size(); i++)
	{
		if (ids[i])
		{
			ids[i]->glyphs.clear();
			for (int k = 0; k < 17; k++)
			{
				if (asciiEnabled)
					ids[i]->glyphs.push_back(opv3d_tableGlyph[k]);
				else
					ids[i]->glyphs.push_back(opv3d_tableAscii[k]);
			}
		}
	}
	if (opv3d_world)
	{
		opv3d_world->unknown7355a0();
		if (!b)
		{
			opv3d_cec0c8->unknown48f310();
			opv3d_cec08c->reopen(4,HItem());
		}
	}
	setEarthColors();
}
