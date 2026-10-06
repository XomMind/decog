// op_v3d_logmsg: 0x78f320 (log message fade timings and map colors), Beta 17.1.
#include "op_v3d.h"

bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)

extern int opv3d_d28f70;	// NOTE: placeholder name
extern int opv3d_d28f7c;	// NOTE: placeholder name
extern int opv3d_d28f84;	// NOTE: placeholder name
extern int opv3d_d28f88;	// NOTE: placeholder name
extern int opv3d_cebd5c;	// NOTE: placeholder name
extern XColor *opv3d_earthColor;	// NOTE: placeholder name (0xcfe674)
extern XColor opv3d_d29804;	// NOTE: placeholder name

struct OpV3d_Anim	// NOTE: placeholder name (animation record)
{
	char pad00[0x2c];
	int duration;	// NOTE: placeholder name
};

struct OpV3d_ColorRec	// NOTE: placeholder name
{
	char pad00[0x78];
	XColor color78;	// NOTE: placeholder name
	char pad7b[0xa0 - 0x7b];
	XColor colorA0;	// NOTE: placeholder name
	char padA3[0xc8 - 0xa3];
	XColor colorC8;	// NOTE: placeholder name
};
extern vector<OpV3d_ColorRec*> opv3d_cfe704;	// NOTE: placeholder name

void OpV3d_setLogMsgTimes()	// NOTE: placeholder name (0x78f320)
{
	OpV3d_Anim *a;
	OpV3d_Anim *b;
	OpV3d_Anim *c;
	OpU8a_lookup1("A_CLogMsg_Map_FCmb_Fa",(int*)&a);
	OpU8a_lookup1("CLogMsg_Map_FCmb_Fade",(int*)&b);
	a->duration = opv3d_d28f70 - b->duration;
	OpU8a_lookup1("A_CLogMsg_Map_Log_Fa",(int*)&a);
	OpU8a_lookup1("CLogMsg_Map_Log_Fade",(int*)&b);
	a->duration = opv3d_d28f7c - b->duration;
	OpU8a_lookup1("A_CLogMsg_Map_Combat_Fa",(int*)&a);
	OpU8a_lookup1("CLogMsg_Map_Combat_Fade",(int*)&b);
	a->duration = opv3d_d28f84 - b->duration;
	if (opv3d_cebd5c == 2)
	{
		OpU8a_lookup1("CLogMsg_Tutorial_Osc",(int*)&a);
		a->duration = 10000;
	}
	if (opv3d_d28f88)
	{
		OpU8a_lookup1("A_CLogMsg_Map_Al_Fa_Default",(int*)&a);
		OpU8a_lookup1("CLogMsg_Map_Al_Fade_Default",(int*)&b);
		OpU8a_lookup1("CLogMsg_Map_Alert_En_Default",(int*)&c);
		c->duration = a->duration = opv3d_d28f88 - b->duration;
		OpU8a_lookup1("A_CLogMsg_Map_Al_Fa_Glados",(int*)&a);
		OpU8a_lookup1("CLogMsg_Map_Al_Fade_Glados",(int*)&b);
		OpU8a_lookup1("CLogMsg_Map_Alert_En_Glados",(int*)&c);
		c->duration = a->duration = opv3d_d28f88 - b->duration;
		OpU8a_lookup1("A_CLogMsg_Map_Al_Fa_Forbidden_Lore",(int*)&a);
		OpU8a_lookup1("CLogMsg_Map_Al_Fade_Forbidden_Lore",(int*)&b);
		OpU8a_lookup1("CLogMsg_Map_Alert_En_Forbidden_Lore",(int*)&c);
		c->duration = a->duration = opv3d_d28f88 - b->duration;
	}
	if (opv3d_d29804 != *opv3d_earthColor)
	{
		for (unsigned int i = 0; i < opv3d_cfe704.size(); i++)
		{
			if (opv3d_cfe704[i]->color78 == *opv3d_earthColor)
				opv3d_cfe704[i]->color78 = opv3d_d29804;
			if (opv3d_cfe704[i]->colorA0 == *opv3d_earthColor)
				opv3d_cfe704[i]->colorA0 = opv3d_d29804;
			if (opv3d_cfe704[i]->colorC8 == *opv3d_earthColor)
				opv3d_cfe704[i]->colorC8 = opv3d_d29804;
		}
	}
}
