// op_cogshop_open: 0x8779a0, prices the Cogshop offers and opens the "\ C O G S H O P \" list
// (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_) throw();	// 0x46ca20
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &c) throw();	// 0x411e30
};

class XConsole
{
public:
	bool isHidden();	// 0x4175f0
	Pos getPos();	// 0x417480
	int getHeight();	// 0x4174c0
};

class CList
{
public:
	CList(XConsole *parent, const Pos &pos, string title, int unknown74_, const vector<string> &options_, int maxVisible, int font, void (*callback_)(int,const string&), int unknownC4_, int layer, bool unknown9c_, bool unknown9d_, vector<bool> *enabled_, vector<int> *unknownA4_, vector<int> *unknownA8_, bool noClose_);	// 0x48d9a0
	void setLayer_4514a0(int value);	// NOTE: placeholder name
	void scroll(int a, int b);	// 0x7b2e40
	void setUnknownC0(bool unknownC0_);	// 0x48e090
	void setDrawRow_4505b0(void (*draw)(void *row));	// NOTE: placeholder name
	char pad00[0xd4];
};
extern CList *activeList;	// 0xcec130

struct OpCS_Item	// NOTE: placeholder name (item record)
{
	char pad00[0x24];
	string name;	// +0x24
	char pad40[0x44 - 0x40];
	int type;	// +0x44
	char pad48[0x50 - 0x48];
	int rating;	// +0x50
	char pad54[0x5c - 0x54];
	int unknown5c;
	char pad60[0x94 - 0x60];
	int unknown94;
	void describe_5705b0(string &out, const XColor &color);	// NOTE: placeholder name
};

struct OpCS_Offer	// NOTE: placeholder name
{
	int kind;	// 0 = loot box, 1 = item
	OpCS_Item *item;
	int price;
};

class OpCS_Map	// NOTE: placeholder name (BS)
{
public:
	vector<OpCS_Offer *> *getOffers_463fc0();	// NOTE: placeholder name
	int unknown463fe0();	// NOTE: placeholder name
	int getTurn();	// 0x464270
};
extern OpCS_Map *opCS_map;	// NOTE: placeholder name (0xcefc4c)

struct OpCS_Glyph	// NOTE: placeholder name (8 bytes)
{
	int ch;
	int pad;
};
extern OpCS_Glyph opCS_glyphs_d01618[];	// NOTE: placeholder name
extern vector<float> opCS_priceByType_cf4634;	// NOTE: placeholder name
extern int opCS_saleType_cf466c;	// NOTE: placeholder name
extern int opCS_saleUntil_cf4668;	// NOTE: placeholder name
extern int opCS_credits_cf4630;	// NOTE: placeholder name
extern const float opCS_ratingStep_ba76c8;	// NOTE: placeholder name (0.1)
extern const float opCS_saleFactor_ba76d8;	// NOTE: placeholder name (0.5)

struct OpCS_Columns	// NOTE: placeholder name
{
	char pad00[0x6c];
	int priceWidth;	// +0x6c
	int nameWidth;	// +0x70
	int infoWidth;	// +0x74
};
extern OpCS_Columns *opCS_columns_cec05c;	// NOTE: placeholder name

extern XConsole *opCS_cec11c;	// NOTE: placeholder name
extern XConsole *opCS_cec118;	// NOTE: placeholder name
extern XConsole *opCS_cec054;	// NOTE: placeholder name
extern XConsole *opCS_parent_cec034;	// NOTE: placeholder name
extern XColor *opCS_color_cfe674;	// NOTE: placeholder name
extern int fontCellWidth;	// 0xcaf128
extern int fontCellScale;	// 0xcaf12c

string OpY1_intToStringGrouped(int value);	// NOTE: placeholder name
string &padLeft_408090(string &s, unsigned int width, char c);	// NOTE: placeholder name
string &padRight_4080d0(string &s, unsigned int width, char c);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name
void teamb_buy877150(void *source, const string &value);	// 0x877150
struct TeamB_SlotRow;
void teamb_drawSlotRow876f60(TeamB_SlotRow *row);	// 0x876f60

void opCS_openCogshop_8779a0()	// NOTE: placeholder name
{
	if (!opCS_cec11c->isHidden() || !opCS_cec118->isHidden() || activeList)
		return;
	vector<OpCS_Offer *> *slots = opCS_map->getOffers_463fc0();
	for (unsigned int i = 0; i < slots->size(); i++)
	{
		OpCS_Item *item = (*slots)[i]->item;
		if ((*slots)[i]->kind == 1)
		{
			float mult = 1.0f;
			if (item->unknown94 != 0)
				mult *= 4 - item->unknown5c;
			mult *= opCS_priceByType_cf4634[item->type];
			int price = mult * 1000.0;
			price = (1 + (item->rating - 5) * opCS_ratingStep_ba76c8) * price;
			if (item->type == opCS_saleType_cf466c && opCS_map->getTurn() <= opCS_saleUntil_cf4668)
				price = price * opCS_saleFactor_ba76d8;
			if (price < 1)
				price = 1;
			(*slots)[i]->price = price;
		}
	}
	vector<string> option;
	unsigned int size = 0;
	for (unsigned int i = 0; i < slots->size(); i++)
	{
		option.push_back(OpY1_intToStringGrouped((*slots)[i]->price));
		if (option.back().size() > size)
			size = option.back().size();
	}
	for (unsigned int i = 0; i < option.size(); i++)
		padLeft_408090(option[i],size,' ');
	opCS_columns_cec05c->priceWidth = size + 1;
	unsigned int temp = 0;
	for (unsigned int i = 0; i < slots->size(); i++)
	{
		option[i] += ' ';
		option[i] += (char)((*slots)[i]->kind == 0 ? '?' : opCS_glyphs_d01618[(*slots)[i]->item->type].ch);
		option[i] += ' ';
		option[i] += (*slots)[i]->kind == 0 ? string("Loot Box") : (*slots)[i]->item->name;
		if (option[i].size() > temp)
			temp = option[i].size();
	}
	temp += 2;
	for (unsigned int i = 0; i < option.size(); i++)
		padRight_4080d0(option[i],temp,' ');
	opCS_columns_cec05c->nameWidth = option.front().size() - 1;
	unsigned int cx = 0;
	vector<string> parts;
	for (unsigned int i = 0; i < slots->size(); i++)
	{
		parts.push_back(string());
		if ((*slots)[i]->kind == 0)
			parts.back() = "What's inside?";
		else
			(*slots)[i]->item->describe_5705b0(parts.back(),XColor(*opCS_color_cfe674));
		if (parts.back().size() > cx)
			cx = parts.back().size();
	}
	for (unsigned int i = 0; i < parts.size(); i++)
	{
		padLeft_408090(parts[i],cx,' ');
		option[i] += parts[i];
	}
	opCS_columns_cec05c->infoWidth = cx + 1;
	vector<bool> *valid = new vector<bool>(option.size(),true);
	for (unsigned int i = 0; i < option.size(); i++)
	{
		if ((*slots)[i]->price > opCS_credits_cf4630)
			valid->at(i) = false;
	}
	int count = OpX5_minInt(option.size(),26) + 4;
	int pt = opCS_cec054->getPos().y + opCS_cec054->getHeight() * fontCellScale - 3 - count - fontCellScale + 1;
	new CList(opCS_parent_cec034,Pos(fontCellWidth,pt),"\\ C O G S H O P \\",0x12,option,26,0,(void (*)(int,const string&))teamb_buy877150,0,0x16,false,false,valid,NULL,NULL,false);
	activeList->setLayer_4514a0(5);
	activeList->scroll(0,opCS_map->unknown463fe0());
	activeList->setUnknownC0(true);
	activeList->setDrawRow_4505b0((void (*)(void *))teamb_drawSlotRow876f60);
}
