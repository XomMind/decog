// op_v3e_lore: CLore::scroll (0x7eafe0), scrolls the lore list by delta rows (+-1 moves the selection to the
// next known entry) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <vector>
#include <stdlib.h>
#include <string>
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &c) throw();	// 0x411e30
};

struct OpVL_FxAnim	// NOTE: placeholder name
{
	void unknown50de10();	// NOTE: placeholder name
};
class Engine
{
public:
	OpVL_FxAnim *unknown50fb50(Engine *engine, int type, const void *a, const void *b, const void *c, const void *d, int value);	// NOTE: placeholder name
	void stopAll();	// NOTE: placeholder name (OpR2b_Engine::stopAll)
};
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int x_, int y_) throw();	// 0x46ca20
	Pos(const Pos &pos) throw();	// 0x46ca50
	Pos(const Pos &pos, int dx, int dy) throw();	// 0x4099c0
};

class XConsole
{
public:
	Pos getPos();	// 0x417480
	void setPos(const Pos &pos);	// 0x4289e0
	Pos localToAbs(Pos pos);	// 0x428650
	void removeSubconsole(XConsole *console);	// 0x428b20
	int height_44b0d0();	// NOTE: placeholder name (getter at 0x44b0d0)
	void clear();	// 0x417bc0
	void clearInterior();	// 0x417c70
	Pos getMaxCoord();	// 0x4174e0
	int getHeight();	// 0x4174c0
	void setFore(XColor color);	// 0x417b00
	void print(int x, int y, const std::string &text);	// 0x4181d0
	std::string getString(const Pos &pos, unsigned int length);	// 0x4177a0
	int printWrapped_418260(int x, int y, int width, int height, const std::string &text);	// NOTE: placeholder name
	char padx[0x64];
	Engine *engine;	// +0x64
};

class OpVL_Console : public XConsole	// NOTE: placeholder name (Console)
{
public:
	OpVL_Console(XConsole *parent, int width, int height, int x, int y, int font, bool hidden, int layer);	// 0x48c060
	char pad68[0x6c - 0x68];
};

struct OpVL_LoreInfo	// NOTE: placeholder name
{
	int index;
	bool known;	// NOTE: placeholder name
	const std::string &getText();	// NOTE: placeholder name (0x517130 getter)
};

class OpVL_LoreLine : public XConsole	// NOTE: placeholder name (a list row console)
{
public:
	char pad68[0x6c - 0x68];
	OpVL_LoreInfo *info;	// +0x6c
};

struct OpVL_LoreRecord	// NOTE: placeholder name
{
	int pad00;
	bool known;	// NOTE: placeholder name
	const std::string &getText();	// NOTE: placeholder name (0x517130 getter)
};
extern vector<OpVL_LoreRecord *> opVL_loreRecords;	// NOTE: placeholder name (0xd02cb4)

class OpVL_Mouse	// NOTE: placeholder name (OpR1c_Mouse)
{
public:
	void setCellPoint_41a910(const Pos &pos);	// NOTE: placeholder name
};
extern OpVL_Mouse *opVL_mouse;	// NOTE: placeholder name (0xcefa94)

extern XColor *opVL_textColor_d2981c;	// NOTE: placeholder name
extern XColor *opVL_otherColor_cfe674;	// NOTE: placeholder name
extern XColor opVL_fxColor_cfbec0;	// NOTE: placeholder name
void OpU8a_lookup1(const std::string &name, int *out);	// NOTE: placeholder name
extern int opV3e_rows_bcbe04[2];	// NOTE: placeholder name
extern int opV3e_unknown_caf16c;	// NOTE: placeholder name ("none" index)
extern bool opVL_keyboardMode_d28c8a;	// NOTE: placeholder name
bool opr1c_hasPtr_cebd5c();	// NOTE: placeholder name (0x4328a0)
int OpX5_maxInt(int a, int b);	// NOTE: placeholder name
int OpX5_minInt(int a, int b);	// NOTE: placeholder name
struct OpQ5_U9e25a0;	// NOTE: placeholder name
template <class T> void OpQ5_eraseRange(vector<T> &v, int first, int last);	// NOTE: placeholder name
template <class T> void removeVectorElement(vector<T> &v, T index);	// NOTE: placeholder name

class CLore : public XConsole
{
public:
	void unknown7ebba0(int rows, int index, int value, bool flag);	// NOTE: placeholder name
	void unknown7eafe0(int delta, int key);	// NOTE: placeholder name
	void unknown7ebd60(int index);	// NOTE: placeholder name

	char pad00[0x70 - 0x68];
	vector<OpVL_LoreLine *> lines;	// +0x70
	int selected;	// +0x80, NOTE: placeholder name
	XConsole *details;	// +0x84, NOTE: placeholder name
};

void CLore::unknown7eafe0(int delta, int key)
{
	if (delta == 0)
		return;
	bool found = false;
	int value = opV3e_unknown_caf16c;
	bool prev;
	if (abs(delta) == 1)
	{
		if (selected == opV3e_unknown_caf16c)
		{
			for (unsigned int i = 0; i < opVL_loreRecords.size(); i++)
			{
				if (opVL_loreRecords[i]->known)
				{
					value = i;
					break;
				}
			}
		}
		else if (delta == 1)
		{
			for (unsigned int i = selected + 1; i < opVL_loreRecords.size(); i++)
			{
				if (opVL_loreRecords[i]->known)
				{
					value = i;
					break;
				}
			}
		}
		else
		{
			for (int i = selected - 1; i >= 0; i--)
			{
				if (opVL_loreRecords[i]->known)
				{
					value = i;
					break;
				}
			}
		}
		if (value != opV3e_unknown_caf16c)
		{
			for (unsigned int i = 0; i < lines.size(); i++)
			{
				if (lines[i]->info->index == value)
					goto select;
			}
			if (value != lines.front()->info->index - 1 && value != lines.back()->info->index + 1)
			{
				found = true;
				prev = delta != 1;
			}
		}
	}
	int cur = lines.front()->info->index;
	if (delta < 0)
	{
		delta = -delta;
		if (cur == 0)
			return;
		if (delta >= opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0] || cur - delta < 0)
		{
			for (unsigned int i = 0; i < lines.size(); i++)
			{
				if (lines[i])
					removeSubconsole(lines[i]);
			}
			lines.clear();
			cur = OpX5_maxInt(0,cur - delta);
			unknown7ebba0(opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0],cur,2,true);
		}
		else
		{
			int idx = opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0] - delta;
			for (unsigned int i = idx; i < lines.size(); i++)
				removeSubconsole(lines[i]);
			OpQ5_eraseRange((vector<OpQ5_U9e25a0>&)lines,idx,lines.size() - 1);
			int count = delta;
			for (unsigned int i = 0; i < lines.size(); i++)
				lines[i]->setPos(Pos(lines[i]->getPos(),0,count));
			cur -= delta;
			unknown7ebba0(delta,cur,2,true);
		}
	}
	else
	{
		if (lines.back()->info->index == opVL_loreRecords.size() - 1)
			return;
		if (delta >= opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0] || cur + delta >= (int)(opVL_loreRecords.size() - opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0]))
		{
			for (unsigned int i = 0; i < lines.size(); i++)
			{
				if (lines[i])
					removeSubconsole(lines[i]);
			}
			lines.clear();
			cur = OpX5_minInt(opVL_loreRecords.size() - opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0],cur + delta);
			unknown7ebba0(opV3e_rows_bcbe04[opr1c_hasPtr_cebd5c() ? 1 : 0],cur,2,false);
		}
		else
		{
			for (int i = 0; i < delta; i++)
			{
				removeSubconsole(lines.front());
				removeVectorElement((vector<int>&)lines,0);
			}
			int count = delta;
			for (unsigned int i = 0; i < lines.size(); i++)
				lines[i]->setPos(Pos(lines[i]->getPos(),0,-count));
			cur = lines.size() + delta + cur;
			unknown7ebba0(delta,cur,lines.back()->getPos().y + 1,false);
		}
	}
	if (found)
	{
		if (prev)
		{
			for (unsigned int i = 0; i < lines.size(); i++)
			{
				if (lines[i]->info->known)
				{
					value = lines[i]->info->index;
					break;
				}
			}
		}
		else
		{
			for (int i = lines.size() - 1; i >= 0; i--)
			{
				if (lines[i]->info->known)
				{
					value = lines[i]->info->index;
					break;
				}
			}
		}
	}
select:
	if (value != opV3e_unknown_caf16c)
	{
		for (unsigned int i = 0; i < lines.size(); i++)
		{
			if (lines[i]->info->index == value)
			{
				opVL_mouse->setCellPoint_41a910(lines[i]->localToAbs(Pos(lines[i]->height_44b0d0() - 2,0)));
				unknown7ebd60(value);
				break;
			}
		}
	}
	else if (opVL_keyboardMode_d28c8a)
	{
		if (key == 0x29 || key == 0x2c)
		{
			for (int i = lines.size() - 1; i >= 0; i--)
			{
				if (lines[i]->info->known)
				{
					opVL_mouse->setCellPoint_41a910(lines[i]->localToAbs(Pos(lines[i]->height_44b0d0() - 2,0)));
					unknown7ebd60(lines[i]->info->index);
					break;
				}
			}
		}
		else if (key == 0x2a || key == 0x2b)
		{
			for (unsigned int i = 0; i < lines.size(); i++)
			{
				if (lines[i]->info->known)
				{
					opVL_mouse->setCellPoint_41a910(lines[i]->localToAbs(Pos(lines[i]->height_44b0d0() - 2,0)));
					unknown7ebd60(lines[i]->info->index);
					break;
				}
			}
		}
	}
}

// CLore::select (0x7ebd60): shows the selected entry's text in the details console, followed (below) and
// preceded (above) by as many neighbouring entries as fit, with "???" for unknown ones.
void CLore::unknown7ebd60(int index)
{
	if (selected == index)
		return;
	selected = index;
	OpVL_LoreLine *other = NULL;
	for (unsigned int num = 0; num < lines.size(); num++)
	{
		if (lines[num]->info->index == selected)
		{
			other = lines[num];
			break;
		}
	}
	details->clearInterior();
	details->engine->stopAll();
	XConsole *title = new OpVL_Console(details,0x5e,0x19,2,1,0,false,-1);
	int size = title->printWrapped_418260(0,0,0x5e,0x19,other->info->getText());
	int temp = other->getPos().y;
	if (temp + size >= details->getMaxCoord().y)
		temp -= temp + size - details->getHeight() + 1;
	details->setFore(*opVL_textColor_d2981c);
	for (int j = 0, y = temp; j < size; j++, y++)
	{
		string s = title->getString(Pos(0,j),0x5e);
		details->print(2,y,s);
	}
	int log;
	OpU8a_lookup1("CLore_Text_Discovered",&log);
	int mask;
	OpU8a_lookup1("CLore_Text_Unknown",&mask);
	details->setFore(*opVL_otherColor_cfe674);
	int open = 1;
	int ty = temp + size + 1;
	int num;
	num = other->info->index + 1;
	while (num < opVL_loreRecords.size() && ty < details->getMaxCoord().y)
	{
		if (!opVL_loreRecords[num]->known)
		{
			size = 1;
			details->print(2,ty,"???");
			do
			{
				for (int x = Pos(2,ty).x; x < Pos(2,ty).x + 3; x++)
					details->engine->unknown50fb50(details->engine,mask,&Pos(x,Pos(2,ty).y),&opVL_fxColor_cfbec0,0,0,9)->unknown50de10();
			}
			while (0);
		}
		else
		{
			title->clear();
			size = title->printWrapped_418260(0,0,0x5e,0x19,opVL_loreRecords[num]->getText());
			for (int j = 0, y = ty; j < size && y < details->getMaxCoord().y; j++, y++)
			{
				string s = title->getString(Pos(0,j),0x5e);
				details->print(2,y,s);
				do
				{
					for (unsigned int x = Pos(2,y).x; x < Pos(2,y).x + s.size(); x++)
						details->engine->unknown50fb50(details->engine,log,&Pos(x,Pos(2,y).y),&opVL_fxColor_cfbec0,0,0,9)->unknown50de10();
				}
				while (0);
			}
		}
		num++;
		ty = ty + size + 1;
	}
	ty = temp;
	num = other->info->index - 1;
	while (num >= 0)
	{
		if (!opVL_loreRecords[num]->known)
		{
			size = 1;
			ty -= size + 1;
			if (ty > 1)
			{
				details->print(2,ty,"???");
				do
				{
					for (int x = Pos(2,ty).x; x < Pos(2,ty).x + 3; x++)
						details->engine->unknown50fb50(details->engine,mask,&Pos(x,Pos(2,ty).y),&opVL_fxColor_cfbec0,0,0,9)->unknown50de10();
				}
				while (0);
			}
			else
				break;
		}
		else
		{
			title->clear();
			size = title->printWrapped_418260(0,0,0x5e,0x19,opVL_loreRecords[num]->getText());
			ty -= 2;
			for (int j = size - 1; j >= 0; j--, ty--)
			{
				if (ty < 1)
					goto done;
				string s = title->getString(Pos(0,j),0x5e);
				details->print(2,ty,s);
				do
				{
					for (unsigned int x = Pos(2,ty).x; x < Pos(2,ty).x + s.size(); x++)
						details->engine->unknown50fb50(details->engine,log,&Pos(x,Pos(2,ty).y),&opVL_fxColor_cfbec0,0,0,9)->unknown50de10();
				}
				while (0);
			}
			ty++;
		}
		num--;
	}
done:
	details->removeSubconsole(title);
}
