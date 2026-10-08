// team_c_61: UI theme color selection (0x793690): picks the interface tint from the run's story state, then recolors
//	the border/frame art (dimmed while the player is under a specific effect)
// NOTE: names are placeholders
#include <string>
#include <vector>
#include "../engine/xcolor.h"
using namespace std;

int stringToInt(const string &s);
struct C61_Art { char pad0[0x64]; XColor f64; char pad67[0x78 - 0x67]; XColor f78; char pad7b[0x8c - 0x7b]; XColor f8c; char pad8f[0xc0 - 0x8f]; XColor fc0; char padc3[0xc8 - 0xc3]; XColor fc8; };	// NOTE: placeholder layout
bool OpU8a_lookup1(const string &name, C61_Art *&result);	// NOTE: placeholder name
struct C61_Entity { class C61_HItem unknown5d2380(int type); int unknown5d2150(int a, int b); };
class C61_HItem { public: int ID; C61_HItem(); bool isValid() const; };	// NOTE: placeholder (HItem)
class C61_HEntity { public: int ID; C61_HEntity(); C61_Entity *operator->() const; bool isValid() const; };	// NOTE: placeholder (HEntity)
struct C61_Map { C61_HEntity getPlayer(); };
struct C61_GameData { const string &getEntryText(const string &key); };

extern int c61_cf4700, c61_cefc54;	// NOTE: placeholder names below
extern float c61_cf46f8;
extern C61_Map *c61_cefc4c;
extern C61_GameData c61_d1e860;
extern XColor c61_d2c35c[];
extern XColor c61_cf6f2c;
extern bool c61_cefbc7;
extern const float c61_ba09d0, c61_c36fa8;

class C61_Theme	// NOTE: placeholder
{
public:
	void unknown793690();
};

void C61_Theme::unknown793690()
{
	if (c61_cf4700 != 0 && c61_cf46f8 < 100.0)
		c61_cefc54 = 5;
	else if (c61_cefc4c != 0 && c61_cefc4c->getPlayer().isValid() && c61_cefc4c->getPlayer()->unknown5d2380(31).isValid())
		c61_cefc54 = 6;
	else if (stringToInt(c61_d1e860.getEntryText("usedCoreResetMatrix_g")))
		c61_cefc54 = 4;
	else if (stringToInt(c61_d1e860.getEntryText("scrUfdRegistered_g")) && !stringToInt(c61_d1e860.getEntryText("scrAttackedLocals_g")) && stringToInt(c61_d1e860.getEntryText("scrOptimusDestroyed_g")) != 1)
		c61_cefc54 = 3;
	else if (stringToInt(c61_d1e860.getEntryText("installedRif_g")))
		c61_cefc54 = 2;
	else if (stringToInt(c61_d1e860.getEntryText("zioWasImprinted_g")))
		c61_cefc54 = 1;
	else
		c61_cefc54 = 0;
	c61_cf6f2c = c61_d2c35c[c61_cefc54];
	c61_cefbc7 = c61_cefc4c != 0 && c61_cefc4c->getPlayer().isValid() && c61_cefc4c->getPlayer()->unknown5d2150(30,0);
	if (c61_cefbc7)
		c61_cf6f2c.scale(c61_ba09d0);
	C61_Art *center;
	if (OpU8a_lookup1("1_Border_Horz",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("1_Border_Vert",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("1_CornerTL",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("1_CornerTR",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("1_CornerBL",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("1_CornerBR",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_TL",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_TR",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_BL",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_BR",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_H",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_V",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("4_Border_Flash_TLBL_Art",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_Top",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_TopRgt",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_TopLft",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_Bot",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_BotRgt",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_BotLft",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("A_Comp_Border_Edge",center))
		center->f8c = center->fc0 = c61_cf6f2c;
	if (OpU8a_lookup1("CEffect_Core",center))
		center->f64 = c61_cf6f2c;
	if (OpU8a_lookup1("CEffect_Heat",center))
		center->f64 = c61_cf6f2c;
	if (OpU8a_lookup1("CEffect_StasisB",center))
		center->f64 = c61_cf6f2c;
	if (OpU8a_lookup1("CEffect_StasisP",center))
		center->f64 = c61_cf6f2c;
	if (OpU8a_lookup1("CPartsCycModal",center))
		center->f78 = center->fc8 = c61_cf6f2c;
	if (OpU8a_lookup1("CPartsCycModal_Bright",center))
		center->f78 = center->fc8 = c61_cf6f2c * c61_c36fa8;
}
