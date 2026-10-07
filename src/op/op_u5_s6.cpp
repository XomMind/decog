// op_u5_s6: console constructors and data-output writers in 0x7d6000-0x7ea000, Beta 17.1.
// NOTE: class layouts are partial; names are placeholders unless stated otherwise.
#include <string>
#include <vector>
#include <ostream>
#include <algorithm>
using namespace std;


struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(int r_, int g_, int b_);
	XColor(const XColor &color) throw();
	XColor operator*(float value);
};

struct Point
{
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	void setOffset(const Point &base, int dx, int dy);	// NOTE: placeholder name (0x40a060)
	Point(const Point &p);
	Point(const Point &p, int dx, int dy);	// 0x4099c0
};

class XConsole
{
public:
	virtual ~XConsole();

	virtual void resize(int width, int height);	// NOTE: placeholder name
	virtual bool mouseEnter();	// NOTE: placeholder name
	virtual void mouseLeave();	// NOTE: placeholder name
	virtual bool input(void *event);
	virtual void inputMouse(int x, int y);	// NOTE: placeholder name
	virtual void update();
	virtual void render();	// NOTE: placeholder name

	bool isHidden();	// NOTE: placeholder name
	int getWidth();
	int getHeight();
	Point getPos();
	void setPos(const Point &pos);
	void print(int x, int y, const string &text);	// NOTE: placeholder name
	void setCharRow(int x, int y, int width, int ch, XColor fore);	// NOTE: placeholder name
	void setCharColumn(int x, int y, int height, int ch, XColor fore);	// NOTE: placeholder name
	void putChar_418110(int x, int y, int ch, XColor fore);	// NOTE: placeholder name
	XConsole *getParent();	// NOTE: placeholder name
	void setHidden(bool hidden_);	// NOTE: placeholder name
	void removeSubconsole(XConsole *console);
	void clearInterior();
	void deleteSubconsoles();
	void setFore(XColor color);
	void printAligned(int x, int y, int align, const string &text);	// NOTE: placeholder name
	bool input429d00(void *event);	// NOTE: placeholder name (XConsole::input body)

	char pad04[0x60 - 0x04];
};

class Console : public XConsole
{
public:
	Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);
	virtual ~Console();

	virtual void open();	// NOTE: placeholder name
	virtual void close();	// NOTE: placeholder name
	virtual int getFrame();	// NOTE: placeholder name
	virtual void trigger(const string &command, int value);

	void animate(string name);	// NOTE: placeholder name

	int unknown60;
	void *engine;
	void *title;
};

bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
extern bool opY6_consoleInputBlocked;	// NOTE: placeholder name (0xcefa5f)
int opR1d_4541b0(unsigned int sound, int loopsB, int loops);	// NOTE: placeholder name
extern XConsole *opR4b_commands;	// NOTE: placeholder name (0xcec03c)

extern int opR4b_rowSpacing_bcbdf4[2];	// NOTE: placeholder name
extern Point opU5_positions_d257f0[2];	// NOTE: placeholder name
int minInt(int a, int b);	// 0x9cdb30
int opU5_maxInt(int a, int b);	// NOTE: placeholder name (0x9cdb60)
struct OpQ5_U9e25a0;
template <class T> void OpQ5_eraseRange(vector<T> &v, int first, int last);	// 0x9e25a0
template <class T> void removeVectorElement(vector<T> &v, int index);	// 0x9de6f0

class Unknown_c34c68 : public Console	// CGalleryText (src/lead/c045.cpp)
{
public:
	Unknown_c34c68(XConsole *parent, int x, int y, int width, int height, int value);	// 0x496950
	void setColor();	// 0x4969a0

	int unknown6c;	// NOTE: placeholder name
};

extern const int opU5_widths_bcb494[];	// NOTE: placeholder name
extern const int opU5_heights_bcb934[];	// NOTE: placeholder name
extern XColor opU5_color_cf6f2c;	// NOTE: placeholder name
extern XColor *opU5_color_d2981c;	// NOTE: placeholder name
extern int opU5_unknown_d37d40;	// NOTE: placeholder name
extern int opU5_unknown_d37d44;	// NOTE: placeholder name
extern int opU5_unknown_d2284c;	// NOTE: placeholder name
extern int opU5_unknown_d22850;	// NOTE: placeholder name
extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)

class CCollectionPercent : public Console
{
public:
	CCollectionPercent(XConsole *parent, int x, int y, int value_);	// 0x7d7b10

	int value;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
	unsigned int unknown74;	// NOTE: placeholder name
};

CCollectionPercent::CCollectionPercent(XConsole *parent, int x, int y, int value_)
	: Console(parent,opU5_widths_bcb494[opr1c_hasPtr_cebd5c() != 0],opU5_heights_bcb934[opr1c_hasPtr_cebd5c() != 0],x,y,0,false,0xb)
{
	value = value_;
	unknown70 = 0;
	unknown74 = tickCount;
	if (opr1c_hasPtr_cebd5c())
	{
		XColor fore = opU5_color_cf6f2c * 0.5f;
		setCharRow(0,0,getWidth() - 1,0x81,fore);
		setCharColumn(getWidth() - 1,1,getHeight() - 1,0x80,fore);
		putChar_418110(getWidth() - 1,0,0x89,fore);
		putChar_418110(3,1,0x5f,*opU5_color_d2981c);
		setCharColumn(opU5_unknown_d37d40,opU5_unknown_d37d44,0x1e,0xb0,XColor(0,0x20,0));
		string text = "Collect";
		Unknown_c34c68 *label = new Unknown_c34c68(this,0,0x22,text.size(),1,0);
		label->print(0,0,text);
		label->setColor();
	}
	else
	{
		string text = "Collection Percent:";
		Unknown_c34c68 *label = new Unknown_c34c68(this,2,1,text.size(),1,0);
		label->print(0,0,text);
		label->setColor();
		setCharRow(opU5_unknown_d2284c,opU5_unknown_d22850,0x44,0xb2,XColor(0,0x20,0));
		animate("CCollectionPcnt_Border");
	}
}

class CCollectionCounts : public Console
{
public:
	CCollectionCounts(XConsole *parent, int x, int y);	// 0x496a30
};

class CCollectionExport : public Console
{
public:
	CCollectionExport(XConsole *parent, int x, int y);	// 0x496e90

	vector<void*> buttons;	// NOTE: placeholder name
};

extern const int opU5_offsets_bcbdfc[];	// NOTE: placeholder name

void OpU5_createCollectionConsoles(int percent, const Point &origin, CCollectionCounts **counts, CCollectionPercent **percentConsole, CCollectionExport **exportConsole);	// NOTE: placeholder name (0x7d89d0)

void OpU5_createCollectionConsoles(int percent, const Point &origin, CCollectionCounts **counts, CCollectionPercent **percentConsole, CCollectionExport **exportConsole)
{
	Point pos;
	if (opr1c_hasPtr_cebd5c())
		pos.setOffset(origin,2,0);
	else
		pos.setOffset(origin,0,opU5_offsets_bcbdfc[opr1c_hasPtr_cebd5c() ? 1 : 0]);
	*counts = new CCollectionCounts(opR4b_commands,pos.x,pos.y);
	if (opr1c_hasPtr_cebd5c())
		pos.setOffset(origin,0x98,1);
	else
		pos.setOffset(origin,0x15,opU5_offsets_bcbdfc[opr1c_hasPtr_cebd5c() ? 1 : 0]);
	*percentConsole = new CCollectionPercent(opR4b_commands,pos.x,pos.y,percent);
	if (opr1c_hasPtr_cebd5c())
		pos.setOffset(origin,0x98,0x25);
	else
		pos.setOffset(origin,0x7b,0x34);
	*exportConsole = new CCollectionExport(opR4b_commands,pos.x,pos.y);
}

class CManualX : public Console	// NOTE: placeholder name (0x7d9b60 is the CGallery close method)
{
public:
	void unknown7d9b60();	// NOTE: placeholder name
};

//==================================================================
// CGallery / CLore
//==================================================================

class CGalleryItem : public Console
{
public:
	int unknown6c;	// NOTE: placeholder name
	int pos;	// NOTE: placeholder name
	char pad74[0x7c - 0x74];
};

class CGallery : public Console
{
public:
	virtual bool input(void *event);	// 0x7d9c00

	void unknown7e83f0(int amount);	// NOTE: placeholder name
	void unknown7e8a50(int rows, int index, Point *pos, bool add);	// 0x7e8a50
	int unknown7e8c50();	// NOTE: placeholder name

	char pad6c[0x74 - 0x6c];
	vector<int> list;	// NOTE: placeholder name
	char pad84[0xa4 - 0x84];
	vector<CGalleryItem*> items;	// NOTE: placeholder name
};

class Calls_4968e0	// NOTE: placeholder name (object at 0xcec03c)
{
public:
	void delegate();
};

class OpS_Graph
{
public:
	void popFrame();
};
extern OpS_Graph *opU5_keys_cefa8c;	// NOTE: placeholder name

class CLore : public Console
{
public:
	void unknown7e91e0();	// NOTE: placeholder name

	char pad6c[0x84 - 0x6c];
	XConsole *unknown84;	// NOTE: placeholder name
	XConsole *unknown88;	// NOTE: placeholder name
	XConsole *unknown8c;	// NOTE: placeholder name
	XConsole *unknown90;	// NOTE: placeholder name
	XConsole *unknown94;	// NOTE: placeholder name
};

class Sweep_497f50	// NOTE: placeholder name (CLore pointer global at 0xcec044)
{
public:
	XConsole *getField();	// NOTE: placeholder name
};

extern CGallery *opU5_gallery_cec040;	// NOTE: placeholder name
extern Sweep_497f50 *opU5_lore_cec044;	// NOTE: placeholder name
extern Console *opU5_console_cec048;	// NOTE: placeholder name
extern XColor *opU5_color_d20438;	// NOTE: placeholder name

class OpU5_Unk7d8610 : public Console	// NOTE: placeholder name
{
public:
	Console *showMessage(string &text);	// NOTE: placeholder name (0x7d8610)

	int unknown6c;	// NOTE: placeholder name
	int unknown70;	// NOTE: placeholder name
};

Console *OpU5_Unk7d8610::showMessage(string &text)
{
	if (opr1c_hasPtr_cebd5c())
	{
		unsigned int maxLength = opU5_gallery_cec040 ? 0x90 : (opU5_lore_cec044 ? 0x5e : 0x6a);
		if (text.size() > maxLength)
			text = "Export successful!";
		text.insert(0,1,' ');
		text += " ";
		Point pos;
		if (opU5_gallery_cec040)
			pos.setOffset(opU5_gallery_cec040->getPos(),opU5_gallery_cec040->getWidth() - 4 - text.size(),opU5_gallery_cec040->getHeight() - 1);
		else if (opU5_lore_cec044)
			pos.setOffset(opU5_lore_cec044->getField()->getPos(),opU5_lore_cec044->getField()->getWidth() - 1 - text.size(),opU5_lore_cec044->getField()->getHeight() - 1);
		else
			pos.setOffset(opU5_console_cec048->getPos(),opU5_console_cec048->getWidth() - 4 - text.size(),opU5_console_cec048->getHeight() - 1);
		Console *message = new Console(opR4b_commands,text.size(),1,pos.x,pos.y,0,false,0xb);
		message->setFore(*opU5_color_d20438);
		message->print(0,0,text);
		return message;
	}
	else
	{
		unknown70 = unknown6c;
		clearInterior();
		deleteSubconsoles();
		if (text.size() > getWidth() - 4)
			text = "Export successful!";
		setFore(*opU5_color_d20438);
		printAligned(getWidth() / 2,1,1,text);
		return NULL;
	}
}

bool CGallery::input(void *event)
{
	if (isHidden() || opY6_consoleInputBlocked)
		return false;
	if (input429d00(event))
		return true;
	switch (*(int*)event)
	{
		case 0x27:
			unknown7e83f0(1);
			return true;
		case 0x28:
			unknown7e83f0(-1);
			return true;
		case 0x29:
			unknown7e83f0(3);
			return true;
		case 0x2a:
			unknown7e83f0(-3);
			return true;
		case 0x2b:
			unknown7e83f0(-10000);
			return true;
		case 0x2c:
			unknown7e83f0(10000);
			return true;
		case 0x2d:
			((CManualX*)this)->unknown7d9b60();
			return true;
	}
	return false;
}

void CGallery::unknown7e83f0(int amount)
{
	if (amount == 0)
		return;
	int start = items.front()->pos;
	if (amount < 0)
	{
		amount = -amount;
		if (start == 0)
			return;
		if (amount >= 3 || start - amount * 3 < 0)
		{
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i])
					removeSubconsole(items[i]);
			}
			items.clear();
			start = opU5_maxInt(0,start - amount * 3);
			unknown7e8a50(3,start,&opU5_positions_d257f0[opr1c_hasPtr_cebd5c() ? 1 : 0],true);
		}
		else
		{
			int keep = (3 - amount) * 3;
			for (unsigned int i = keep; i < items.size(); i++)
				removeSubconsole(items[i]);
			OpQ5_eraseRange((vector<OpQ5_U9e25a0>&)items,keep,items.size() - 1);
			int spacing = (opR4b_rowSpacing_bcbdf4[opr1c_hasPtr_cebd5c() ? 1 : 0] + 0xd) * amount;
			for (unsigned int j = 0; j < items.size(); j++)
				items[j]->setPos(Point(items[j]->getPos(),0,spacing));
			start -= amount * 3;
			unknown7e8a50(amount,start,&opU5_positions_d257f0[opr1c_hasPtr_cebd5c() ? 1 : 0],true);
		}
	}
	else
	{
		if (items.back()->pos == list.size() - 1)
			return;
		if (amount >= 3 || amount * 3 + start >= (int)list.size() - 9)
		{
			for (unsigned int i = 0; i < items.size(); i++)
			{
				if (items[i])
					removeSubconsole(items[i]);
			}
			items.clear();
			start = minInt(list.size() - 9,amount * 3 + start);
			unknown7e8a50(3,start,&opU5_positions_d257f0[opr1c_hasPtr_cebd5c() ? 1 : 0],false);
		}
		else
		{
			for (int i = 0; i < amount * 3; i++)
			{
				removeSubconsole(items.front());
				removeVectorElement((vector<int>&)items,0);
			}
			int spacing = (opR4b_rowSpacing_bcbdf4[opr1c_hasPtr_cebd5c() ? 1 : 0] + 0xd) * amount;
			for (unsigned int j = 0; j < items.size(); j++)
				items[j]->setPos(Point(items[j]->getPos(),0,-spacing));
			start += items.size() + amount * 3;
			unknown7e8a50(amount,start,&Point(items.front()->getPos().x,items.back()->getPos().y + 0xd + opR4b_rowSpacing_bcbdf4[opr1c_hasPtr_cebd5c() ? 1 : 0]),false);
		}
	}
}

int CGallery::unknown7e8c50()
{
	return list.size() - 1 - items.back()->pos;
}

void CLore::unknown7e91e0()
{
	opR4b_commands->removeSubconsole(unknown84);
	opR4b_commands->removeSubconsole(unknown88);
	opR4b_commands->removeSubconsole(unknown8c);
	opR4b_commands->removeSubconsole(unknown90);
	if (unknown94)
		opR4b_commands->removeSubconsole(unknown94);
	((Calls_4968e0*)opR4b_commands)->delegate();
	unknown60 = 0;
	opU5_keys_cefa8c->popFrame();
	getParent()->removeSubconsole(this);
}

string floatToString(float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x405760)

void OpU5_writeNameIntLine(ostream &out, string &name, int value, string text1, string text2);	// NOTE: placeholder name (0x7d9cf0)
void OpU5_writeQuotedFloat(ostream &out, float value, int unknown1, int unknown2);	// NOTE: placeholder name (0x7da260)
void OpU5_writeLabelLine(ostream &out, string &text);	// NOTE: placeholder name (0x7da330)

void OpU5_writeNameIntLine(ostream &out, string &name, int value, string text1, string text2)
{
	if (value == 0)
		return;
	out << name;
	for (int i = name.size(); i <= 15; i++)
		out << " ";
	out << text1 << value << text2 << "\n";
}

// NOTE: literal-pool follower of 0x7d9cf0 (same body as 0x7d9df0), not matched itself
void OpU5_followerNameFloatLine(ostream &out, string &name, float value, int unknown1, int unknown2, string text)
{
	if (value == 0)
		return;
	out << name;
	for (int i = name.size(); i <= 15; i++)
		out << " ";
	out << text << floatToString(value,unknown1,unknown2) << "\n";
}

void OpU5_writeQuotedFloat(ostream &out, float value, int unknown1, int unknown2)
{
	if (value != 0)
		out << "\"" << floatToString(value,unknown1,unknown2) << "\",";
	else
		out << "\"\",";
}

void OpU5_writeLabelLine(ostream &out, string &text)
{
	out << "\"" << text << "\",";
}

// NOTE: literal-pool follower of 0x7da330, not matched itself
string OpU5_followerExportName()
{
	return "gallery_export_";
}
