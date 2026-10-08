// CTactical::render (exe 0x890ee0, vtable slot 7): tactical HUD readouts (core/heat, mode labels, stance).
// NOTE: class is declared here as D2Tactical (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor();
	XColor(const XColor &color) throw();
	XColor &operator=(XColor color);
	XColor operator*(float f);
};

class XConsole
{
public:
	virtual ~XConsole();
	virtual void resize(int width, int height);
	virtual bool mouseEnter();
	virtual void mouseLeave();
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);
	virtual void update();
	virtual void render();

	void setFore(XColor color);
	int getWidth_44b0d0();
	void setPos(int x, int y);
	void print(int x, int y, const string &text);
	void resetBack_418450() throw();
	void setFore_417f80(int x, int y, XColor color);
	void setBackRow(int x, int y, int width, XColor color);

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	virtual ~Console();
	virtual void render();
	virtual void open();
	virtual void close();
	virtual int getFrame();
	virtual void trigger(const string &command, int value);

	int unknown60;
	void *engine;
	void *title;
};

class D2tHandle	// NOTE: placeholder name (item/prop handle)
{
public:
	int ID;
	bool isValid() const;	// 0x9b7230
	bool isNull() const;	// 0x...
};

class D2tEntity
{
public:
	int unknown5c8cb0();
	int unknown5d1ee0();
	int unknown5d1390();
	int unknown5c8d40(int a, int b);
	D2tHandle unknown5d2380(int type);
	int unknown5c8e20(int type);
	int unknown5ca210();
};

class D2tHE	// NOTE: placeholder name (HEntity)
{
public:
	int ID;
	D2tEntity *operator->() const;	// 0x9b6570
};

class D2tMap { public: D2tHE getPlayer(); };
extern D2tMap *d2t_cefc4c;
class D2tGameData { public: const string &getEntryText(const string &key); };
extern D2tGameData d2t_d1e860;
class D2tHighlighter { public: void *get4ab670(); };
extern D2tHighlighter *d2t_cec090;
class D2tDrag { public: bool get4ab570(); };
extern D2tDrag *d2t_cec094;
class D2tParts { public: bool unknown894f70(); };
extern D2tParts *d2t_cec088;
class D2tPlayerData { public: bool isFlagActive(); };
extern D2tPlayerData d2t_cf45d8;
struct D2tBuilder	// NOTE: placeholder layout (0xd25450)
{
	bool active;
	char pad01[0x10 - 0x01];
	int type10;
	int count14;
};
extern D2tBuilder d2t_d25450;

extern XColor *d2t_d161d4, *d2t_cfe674, *d2t_d20438, *d2t_d2f34c, *d2t_d22fcc;
extern XColor d2t_cf6f2c;
extern XColor d2t_d395fc[];
extern vector<XColor> d2t_d2b4bc;
extern int opw6_bcca3c[], opw6_bcca5c[];
extern bool d2t_d28e18, d2t_cf4780, d2t_d28f66, d2t_cefacd;
extern int d2t_cf4b20, d2t_cf462c, d2t_d1eb70, d2t_d1eb68;
extern string d2t_cfb79c, d2t_d379d0, d2t_cf4acc;
extern string d2t_d2f660[], d2t_cfc230[], d2t_d2f798[], d2t_d31348[];
extern vector<int> d2t_cf4784, d2t_cf4794;
extern const float d2t_c36eb4;

string intToString(int value);
int stringToInt(const string &text);
string &padLeft_408090(string &s, unsigned int width, char c);
string &padRight_4080d0(string &s, unsigned int width, char c);
string floatToString(float value, int unknown1, int unknown2);
string OpR5f_toUpper_4083a0(const string &text);
int opR1f_45f9a0(int type);

#define D2T_PRINT(label) print(0, 0, "`b" + intToString(0) + "`" + label + "`x`")
#define D2T_FIT(i) if (getWidth_44b0d0() != opw6_bcca5c[i]) { setPos(opw6_bcca3c[i], 0); resize(opw6_bcca5c[i], 1); }
#define D2T_FITLABEL(label) if (getWidth_44b0d0() != label.size()) { setPos(opw6_bcca3c[2] + opw6_bcca5c[2] - label.size(), 0); resize(label.size(), 1); }

class D2Tactical : public Console
{
public:
	virtual void render();

	int type;
};

void D2Tactical::render()
{
	setFore(*d2t_d161d4);
	D2tHE player = d2t_cefc4c->getPlayer();
	if (!player.operator->())
		return;
	switch (type)
	{
	case 0:
	{
		int cur = player->unknown5c8cb0();
		int level = player->unknown5d1ee0();
		string text = "[";
		text += padLeft_408090(intToString(cur), 3, ' ');
		text += "/";
		text += padRight_4080d0(intToString(level), 3, ' ');
		text += "]";
		print(0, 0, text);
		break;
	}
	case 1:
	{
		int cur = player->unknown5c8cb0();
		int level = player->unknown5d1ee0();
		if (cur > level)
		{
			int kind = player->unknown5d1390();
			setFore(*d2t_cfe674);
			XColor color = kind == 4 || kind == 3 ? *d2t_d20438 : d2t_cf6f2c;
			d2t_d2b4bc[0] = color;
			int count = player->unknown5c8d40(cur, level);
			string text;
			if (!d2t_d28e18)
			{
				text = " Ox" + (count > 9 ? string("*") : intToString(count)) + " ";
				D2T_PRINT(text);
			}
			else
			{
				int pct = (count + 1) * level - cur;
				text = " " + (count > 9 ? string("*") : intToString(count)) + "%" + (pct > 99 ? string("**") : intToString(pct)) + " ";
				if (getWidth_44b0d0() != text.size())
					resize(text.size(), 1);
				D2T_PRINT(text);
				setFore_417f80(text.find('%'), 0, color * d2t_c36eb4);
			}
		}
		else
			resetBack_418450();
		break;
	}
	case 2:
		setFore(*d2t_cfe674);
		d2t_d2b4bc[0] = d2t_cf6f2c;
		if (d2t_cec090->get4ab670())
		{
			D2T_FIT(5);
			string label = " SWAP ";
			D2T_PRINT(label);
		}
		else if (d2t_cec094->get4ab570())
		{
			if (d2t_cec088->unknown894f70())
			{
				D2T_FIT(4);
				string label = " DROP ";
				D2T_PRINT(label);
			}
			else
			{
				D2T_FIT(3);
				string label = " REMOVE ";
				D2T_PRINT(label);
			}
		}
		else if (d2t_cec088->unknown894f70())
		{
			D2T_FIT(2);
			string label = " DIRECT ";
			D2T_PRINT(label);
		}
		else if (d2t_cf4780)
		{
			D2T_FIT(6);
			string label = " FORCE ";
			D2T_PRINT(label);
		}
		else if (d2t_d25450.active)
		{
			string label = "  " + (d2t_d25450.count14 == 0 ? d2t_cfb79c : (d2t_cefc4c->getPlayer()->unknown5d2380(0xda).isValid() ? d2t_d2f660[opR1f_45f9a0(d2t_d25450.type10)] : d2t_d379d0)) + "  ";
			D2T_FITLABEL(label);
			D2T_PRINT(label);
			XColor c;
			if (d2t_d25450.count14 == 0)
				c = *d2t_d2f34c;
			else if (d2t_cefc4c->getPlayer()->unknown5d2380(0xda).isNull())
				c = *d2t_d22fcc;
			else
				c = d2t_d395fc[opR1f_45f9a0(d2t_d25450.type10)];
			setBackRow(1, 0, getWidth_44b0d0() - 2, c);
		}
		else if (d2t_cf4b20 != 0 && d2t_cf462c != 11)
		{
			string label;
			if (stringToInt(d2t_d1e860.getEntryText("scrAttackedLocals_g")) || stringToInt(d2t_d1e860.getEntryText("scrOptimusDestroyed_g")) == 1)
				label = " UFD Traitor ";
			else
			{
				label = " \"";
				label += OpR5f_toUpper_4083a0(d2t_cf4acc);
				if (stringToInt(d2t_d1e860.getEntryText("scrUfdJoined0bPrime_g")))
					label += "+";
				label += "\" ";
			}
			D2T_FITLABEL(label);
			D2T_PRINT(label);
		}
		else if (d2t_d1eb70 == 1 && stringToInt(d2t_d1e860.getEntryText("garCommArraySupport_g")) && d2t_cf462c != 11)
		{
			string bonus = floatToString((float)(d2t_d1eb68 / 100.0), 2, 2);
			string label = " Warlord +" + bonus + " ";
			D2T_FITLABEL(label);
			D2T_PRINT(label);
		}
		else if ((d2t_d28f66 || d2t_cf462c == 5 || d2t_cf462c == 11 || d2t_cefacd || d2t_cf45d8.isFlagActive()) && !d2t_cf4784.empty())
		{
			string label = " ";
			if (d2t_cf4794.back() != 20)
				label += d2t_cfc230[d2t_cf4794.back()] + "-";
			label += d2t_cf462c == 11 ? d2t_d2f798[d2t_cf4784.back()] : d2t_d31348[d2t_cf4784.back()];
			label += " ";
			label = OpR5f_toUpper_4083a0(label);
			D2T_FITLABEL(label);
			D2T_PRINT(label);
		}
		else
			resetBack_418450();
	
		break;
	case 7:
	{
		string text = "[";
		text += padLeft_408090(intToString(player->unknown5c8e20(0)), 3, ' ');
		text += "/";
		text += padRight_4080d0(intToString(player->unknown5ca210()), 3, ' ');
		text += "]";
		print(0, 0, text);
		break;
	}
	}
}
