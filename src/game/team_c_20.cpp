// team_c_20: opC_loadInfoAnims_4acbf0 (0x4acbf0): looks up the CInfo animation ids by name
// NOTE: function and global names are placeholders (globals carry the exe address)
#include <string>
using namespace std;

bool OpU8a_lookup1(const string &name, int *value);	// NOTE: placeholder name (0x9d45a0)

extern int anim_cebf0c;	// NOTE: placeholder name (A_CInfoTitle)
extern int anim_cebfd0;	// NOTE: placeholder name (A_CInfoGlyph)
extern int anim_cebfc0;	// NOTE: placeholder name (A_CInfoHeader)
extern int anim_cebf94;	// NOTE: placeholder name (A_CInfoGlow_Dialogue)
extern int anim_cebfb4;	// NOTE: placeholder name (A_CInfoGlow_DialogueOptional)
extern int anim_cebfc8;	// NOTE: placeholder name (A_CInfoGlow_DisintCounter)
extern int anim_cebfc4;	// NOTE: placeholder name (A_CInfoGlow_AlliedStats)
extern int anim_cebf8c;	// NOTE: placeholder name (A_CInfoText)
extern int anim_cebf1c;	// NOTE: placeholder name (A_CInfoText_Flash)
extern int anim_cebf98;	// NOTE: placeholder name (A_CInfoBar_Red)
extern int anim_cebf9c;	// NOTE: placeholder name (A_CInfoBar_Orange)
extern int anim_cebfa0;	// NOTE: placeholder name (A_CInfoBar_Yellow)
extern int anim_cebfa4;	// NOTE: placeholder name (A_CInfoBar_Green)
extern int anim_cebf18;	// NOTE: placeholder name (CInfoDefault_Value)
extern int anim_cebfac;	// NOTE: placeholder name (CInfoDefault_Bar)
extern int anim_cebf78;	// NOTE: placeholder name (A_CInfoWeight_Okay)
extern int anim_cebf7c;	// NOTE: placeholder name (A_CInfoWeight_Over1)
extern int anim_cebf80;	// NOTE: placeholder name (A_CInfoWeight_Over2)
extern int anim_cebf84;	// NOTE: placeholder name (A_CInfoWeight_Over3)
extern int anim_cebfdc;	// NOTE: placeholder name (A_CInfoHeat_Subzero)
extern int anim_cebed8;	// NOTE: placeholder name (A_CInfoHeat_Cool)
extern int anim_cebedc;	// NOTE: placeholder name (A_CInfoHeat_Warm)
extern int anim_cebee0;	// NOTE: placeholder name (A_CInfoHeat_Hot)
extern int anim_cebee4;	// NOTE: placeholder name (A_CInfoHeat_Warning)
extern int anim_cebee8;	// NOTE: placeholder name (A_CInfoHeat_Danger)
extern int anim_cebeec;	// NOTE: placeholder name (A_CInfoHeat_Critical)
extern int anim_cebf44;	// NOTE: placeholder name (A_CInfoPrototype_Okay)
extern int anim_cebf64;	// NOTE: placeholder name (A_CInfoPrototype_Faulty)
extern int anim_cebfe8;	// NOTE: placeholder name (A_CInfoProjectile_Count)
extern int anim_cebfd8;	// NOTE: placeholder name (A_CInfoActive_Normal)
extern int anim_cebf30;	// NOTE: placeholder name (A_CInfoActive_Integrated)
extern int anim_cebf5c;	// NOTE: placeholder name (A_CInfoActive_Fragile)
extern int anim_cebf24;	// NOTE: placeholder name (A_CInfoActive_SiegeStarting)
extern int anim_cebefc;	// NOTE: placeholder name (A_CInfoActive_SiegeActive)
extern int anim_cebfb0;	// NOTE: placeholder name (A_CInfoActive_SiegeEnding)
extern int anim_cebfa8;	// NOTE: placeholder name (A_CInfoActive_Overload)
extern int anim_cebf00;	// NOTE: placeholder name (A_CInfoActive_Collecting)
extern int anim_cebf34;	// NOTE: placeholder name (A_CInfoActive_Drop)
extern int anim_cebf6c;	// NOTE: placeholder name (A_CInfoActive_Entropic)
extern int anim_cebfcc;	// NOTE: placeholder name (A_CInfoActive_Deteriorating)
extern int anim_cebfd4;	// NOTE: placeholder name (A_CInfoActive_Disposable)
extern int anim_cebfbc;	// NOTE: placeholder name (A_CInfoActive_Throwable)
extern int anim_cebef4;	// NOTE: placeholder name (A_CInfoInactive_Normal)
extern int anim_cebf90;	// NOTE: placeholder name (A_CInfoInactive_Integrated)
extern int anim_cebf50;	// NOTE: placeholder name (A_CInfoInactive_Fragile)
extern int anim_cebf60;	// NOTE: placeholder name (A_CInfoInactive_GolemBuilding)
extern int anim_cebf2c;	// NOTE: placeholder name (A_CInfoInactive_Nonfunctional)
extern int anim_cebf58;	// NOTE: placeholder name (A_CInfoInactive_Rigged)
extern int anim_cebef8;	// NOTE: placeholder name (A_CInfoInactive_Corrupted)
extern int anim_cebf28;	// NOTE: placeholder name (A_CInfoInactive_Rebooting)
extern int anim_cebf70;	// NOTE: placeholder name (A_CInfoInactive_Disabled)
extern int anim_cebf88;	// NOTE: placeholder name (A_CInfoInactive_Charging)
extern int anim_cebff0;	// NOTE: placeholder name (A_CInfoID_Hostile)
extern int anim_cebff4;	// NOTE: placeholder name (A_CInfoID_Neutral)
extern int anim_cebff8;	// NOTE: placeholder name (A_CInfoID_Friendly)
extern int anim_cebfe4;	// NOTE: placeholder name (A_CInfoMachine_Active)
extern int anim_cebf04;	// NOTE: placeholder name (A_CInfoMachine_Disabled)
extern int anim_cebf20;	// NOTE: placeholder name (A_CInfoMachine_Compromised)
extern int anim_cebfb8;	// NOTE: placeholder name (A_CInfoMachine_Overload)
extern int anim_cebf14;	// NOTE: placeholder name (A_CInfoMachine_Unstable)
extern int anim_cebef0;	// NOTE: placeholder name (A_CInfoMachine_Tracing)
extern int anim_cebf54;	// NOTE: placeholder name (A_CInfoMachine_Locked)
extern int anim_cebfec;	// NOTE: placeholder name (A_CInfoMachine_Crashed)
extern int anim_cebf74;	// NOTE: placeholder name (A_CInfoMachine_Processing)
extern int anim_cebf48;	// NOTE: placeholder name (A_CInfoMachine_Fedlink)
extern int anim_cebf10;	// NOTE: placeholder name (A_CInfoMachine_Transmitting)
extern int anim_cebfe0;	// NOTE: placeholder name (A_CInfoMachine_Detonate)
extern int anim_cebf68;	// NOTE: placeholder name (CInfoButton_Bracket)
extern int anim_cebf08;	// NOTE: placeholder name (CInfoButton_Text)
extern int anim_cebf4c;	// NOTE: placeholder name (CInfoButton_Key)
extern int anim_cebf38;	// NOTE: placeholder name (A_CInfoCompare_Better)
extern int anim_cebf3c;	// NOTE: placeholder name (A_CInfoCompare_Worse)
extern int anim_cebf40;	// NOTE: placeholder name (A_CInfoCompare_Subj)

void opC_loadInfoAnims_4acbf0()	// NOTE: placeholder name
{
	OpU8a_lookup1("A_CInfoTitle",&anim_cebf0c);
	OpU8a_lookup1("A_CInfoGlyph",&anim_cebfd0);
	OpU8a_lookup1("A_CInfoHeader",&anim_cebfc0);
	OpU8a_lookup1("A_CInfoGlow_Dialogue",&anim_cebf94);
	OpU8a_lookup1("A_CInfoGlow_DialogueOptional",&anim_cebfb4);
	OpU8a_lookup1("A_CInfoGlow_DisintCounter",&anim_cebfc8);
	OpU8a_lookup1("A_CInfoGlow_AlliedStats",&anim_cebfc4);
	OpU8a_lookup1("A_CInfoText",&anim_cebf8c);
	OpU8a_lookup1("A_CInfoText_Flash",&anim_cebf1c);
	OpU8a_lookup1("A_CInfoBar_Red",&anim_cebf98);
	OpU8a_lookup1("A_CInfoBar_Orange",&anim_cebf9c);
	OpU8a_lookup1("A_CInfoBar_Yellow",&anim_cebfa0);
	OpU8a_lookup1("A_CInfoBar_Green",&anim_cebfa4);
	OpU8a_lookup1("CInfoDefault_Value",&anim_cebf18);
	OpU8a_lookup1("CInfoDefault_Bar",&anim_cebfac);
	OpU8a_lookup1("A_CInfoWeight_Okay",&anim_cebf78);
	OpU8a_lookup1("A_CInfoWeight_Over1",&anim_cebf7c);
	OpU8a_lookup1("A_CInfoWeight_Over2",&anim_cebf80);
	OpU8a_lookup1("A_CInfoWeight_Over3",&anim_cebf84);
	OpU8a_lookup1("A_CInfoHeat_Subzero",&anim_cebfdc);
	OpU8a_lookup1("A_CInfoHeat_Cool",&anim_cebed8);
	OpU8a_lookup1("A_CInfoHeat_Warm",&anim_cebedc);
	OpU8a_lookup1("A_CInfoHeat_Hot",&anim_cebee0);
	OpU8a_lookup1("A_CInfoHeat_Warning",&anim_cebee4);
	OpU8a_lookup1("A_CInfoHeat_Danger",&anim_cebee8);
	OpU8a_lookup1("A_CInfoHeat_Critical",&anim_cebeec);
	OpU8a_lookup1("A_CInfoPrototype_Okay",&anim_cebf44);
	OpU8a_lookup1("A_CInfoPrototype_Faulty",&anim_cebf64);
	OpU8a_lookup1("A_CInfoProjectile_Count",&anim_cebfe8);
	OpU8a_lookup1("A_CInfoActive_Normal",&anim_cebfd8);
	OpU8a_lookup1("A_CInfoActive_Integrated",&anim_cebf30);
	OpU8a_lookup1("A_CInfoActive_Fragile",&anim_cebf5c);
	OpU8a_lookup1("A_CInfoActive_SiegeStarting",&anim_cebf24);
	OpU8a_lookup1("A_CInfoActive_SiegeActive",&anim_cebefc);
	OpU8a_lookup1("A_CInfoActive_SiegeEnding",&anim_cebfb0);
	OpU8a_lookup1("A_CInfoActive_Overload",&anim_cebfa8);
	OpU8a_lookup1("A_CInfoActive_Collecting",&anim_cebf00);
	OpU8a_lookup1("A_CInfoActive_Drop",&anim_cebf34);
	OpU8a_lookup1("A_CInfoActive_Entropic",&anim_cebf6c);
	OpU8a_lookup1("A_CInfoActive_Deteriorating",&anim_cebfcc);
	OpU8a_lookup1("A_CInfoActive_Disposable",&anim_cebfd4);
	OpU8a_lookup1("A_CInfoActive_Throwable",&anim_cebfbc);
	OpU8a_lookup1("A_CInfoInactive_Normal",&anim_cebef4);
	OpU8a_lookup1("A_CInfoInactive_Integrated",&anim_cebf90);
	OpU8a_lookup1("A_CInfoInactive_Fragile",&anim_cebf50);
	OpU8a_lookup1("A_CInfoInactive_GolemBuilding",&anim_cebf60);
	OpU8a_lookup1("A_CInfoInactive_Nonfunctional",&anim_cebf2c);
	OpU8a_lookup1("A_CInfoInactive_Rigged",&anim_cebf58);
	OpU8a_lookup1("A_CInfoInactive_Corrupted",&anim_cebef8);
	OpU8a_lookup1("A_CInfoInactive_Rebooting",&anim_cebf28);
	OpU8a_lookup1("A_CInfoInactive_Disabled",&anim_cebf70);
	OpU8a_lookup1("A_CInfoInactive_Charging",&anim_cebf88);
	OpU8a_lookup1("A_CInfoID_Hostile",&anim_cebff0);
	OpU8a_lookup1("A_CInfoID_Neutral",&anim_cebff4);
	OpU8a_lookup1("A_CInfoID_Friendly",&anim_cebff8);
	OpU8a_lookup1("A_CInfoMachine_Active",&anim_cebfe4);
	OpU8a_lookup1("A_CInfoMachine_Disabled",&anim_cebf04);
	OpU8a_lookup1("A_CInfoMachine_Compromised",&anim_cebf20);
	OpU8a_lookup1("A_CInfoMachine_Overload",&anim_cebfb8);
	OpU8a_lookup1("A_CInfoMachine_Unstable",&anim_cebf14);
	OpU8a_lookup1("A_CInfoMachine_Tracing",&anim_cebef0);
	OpU8a_lookup1("A_CInfoMachine_Locked",&anim_cebf54);
	OpU8a_lookup1("A_CInfoMachine_Crashed",&anim_cebfec);
	OpU8a_lookup1("A_CInfoMachine_Processing",&anim_cebf74);
	OpU8a_lookup1("A_CInfoMachine_Fedlink",&anim_cebf48);
	OpU8a_lookup1("A_CInfoMachine_Transmitting",&anim_cebf10);
	OpU8a_lookup1("A_CInfoMachine_Detonate",&anim_cebfe0);
	OpU8a_lookup1("CInfoButton_Bracket",&anim_cebf68);
	OpU8a_lookup1("CInfoButton_Text",&anim_cebf08);
	OpU8a_lookup1("CInfoButton_Key",&anim_cebf4c);
	OpU8a_lookup1("A_CInfoCompare_Better",&anim_cebf38);
	OpU8a_lookup1("A_CInfoCompare_Worse",&anim_cebf3c);
	OpU8a_lookup1("A_CInfoCompare_Subj",&anim_cebf40);
}
