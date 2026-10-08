// op_v3e_lore: CLore::scroll (0x7eafe0), scrolls the lore list by delta rows (+-1 moves the selection to the
// next known entry) (COGMIND.exe Beta 17.1).
// NOTE: placeholder names and partial layouts.
#include <vector>
#include <stdlib.h>
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
};

struct OpVL_LoreInfo	// NOTE: placeholder name
{
	int index;
	bool known;	// NOTE: placeholder name
};

class OpVL_LoreLine : public XConsole	// NOTE: placeholder name (a list row console)
{
public:
	char pad00[0x6c];
	OpVL_LoreInfo *info;	// +0x6c
};

struct OpVL_LoreRecord	// NOTE: placeholder name
{
	int pad00;
	bool known;	// NOTE: placeholder name
};
extern vector<OpVL_LoreRecord *> opVL_loreRecords;	// NOTE: placeholder name (0xd02cb4)

class OpVL_Mouse	// NOTE: placeholder name (OpR1c_Mouse)
{
public:
	void setCellPoint_41a910(const Pos &pos);	// NOTE: placeholder name
};
extern OpVL_Mouse *opVL_mouse;	// NOTE: placeholder name (0xcefa94)

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

	char pad00[0x70];
	vector<OpVL_LoreLine *> lines;	// +0x70
	int selected;	// +0x80, NOTE: placeholder name
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
