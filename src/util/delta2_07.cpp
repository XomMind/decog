// CWorldMap::unknown993fa0 (exe 0x993fa0, called from CWorldMap::open): builds the world map node/path pieces.
// NOTE: class is declared here as D2WorldMap (placeholder name); layouts are partial, names are placeholders.
#include <string>
#include <vector>
using namespace std;

struct Pos
{
	int x;
	int y;
	Pos(int v);	// 0x409990
	Pos(int x_, int y_);	// 0x46ca20
	Pos(const Pos &pos) throw();
	void set_40a010(int x_, int y_);	// NOTE: placeholder name
};

struct D2wLocation	// NOTE: placeholder layout (map node record)
{
	int unknown0;
	int type;
	int depth;
	char pad0c[0x20 - 0x0c];
	int unknown20;
	char pad24;
	bool known;
	char pad26[2];
	bool unknown28;
	bool unknown29;
	bool unknown2a;
	bool unknown2b;
	bool unknown2c;
	bool unknown2d;
	bool unknown2e;
	bool inRange();	// 0x46ecb0
};

class D2wH	// NOTE: placeholder name (HEntity-style handle to a map node)
{
public:
	int ID;
	D2wH() throw();	// 0x9b6590
	bool isValid() const;	// 0x9b7230
	void reset();	// 0x9b7270
	bool operator==(D2wH other) const;	// 0x9b78e0
	D2wLocation *operator->() const;	// 0x9b7910
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

	Pos getPos();
	int getWidth_44b0d0();
	int getHeight();
	void putChar_4180b0(int x, int y, int ch);
	Pos localToAbs(Pos pos);

	char pad04[0x60 - 0x04];
};

class D2wEffect { public: void init_50de10(); };
class D2wEngine
{
public:
	D2wEffect *unknown50fb50(D2wEngine *engine, int type, const Pos &a, Pos *b, Pos *c, Pos *d, int value);
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

	void animate(string name);
	void animate(string name, int a, int b);

	int unknown60;
	D2wEngine *engine;
	void *title;
};

class CWorldMapPiece : public Console
{
public:
	CWorldMapPiece(XConsole *parent, int width, int height, int x, int y, int node);
	D2wH getNode_4aeed0();	// NOTE: placeholder name
	char pad6c[0x74 - 0x6c];
};

class D2wMouse
{
public:
	bool unknown41a6e0();
	void setCellPoint_41a910(const Pos &pos);
};
extern D2wMouse *d2w_cefa94;

extern D2wH d2w_d1e888;
extern int d2w_d1e884;
extern int d2w_b90670[];
extern string d2w_cfe140[];
extern string d2w_d38e40[];
extern string d2w_cfe2ac, d2w_cfe2c8;
extern Pos d2w_cfbec0;

bool opr1c_hasPtr_cebd5c();
int halfDiff_437190(int a, int b);
void OpC_findNodes_470240(int a, int depth, vector<D2wH> &nodes, vector<D2wH> *found);
bool OpU8a_lookup1(const string &name, int *index);

class D2WorldMap : public Console
{
public:
	virtual bool input(void *event);
	virtual void update();
	virtual void open();
	virtual void close();

	void unknown993fa0();	// NOTE: placeholder name
	void unknown996500(int index, int a, int b);	// NOTE: placeholder name

	unsigned int unknown6c;
	vector<D2wH> nodes;
	vector<CWorldMapPiece*> pieces;
	unsigned int unknown90;
	int unknown94;
	vector<CWorldMapPiece*> unknown98;
	void *info;
	vector<vector<D2wH> > levels;
};

void D2WorldMap::unknown993fa0()
{
	int m = getWidth_44b0d0() / 2;
	int size = opr1c_hasPtr_cebd5c() ? 4 : 5;
	const int step = 5;
	Pos pos(-1);
	CWorldMapPiece *cell;
	for (int i = 1; ; i++)
	{
		if (i == 1)
		{
			int rows = 11 - nodes.back()->depth;
			levels.assign(10, vector<D2wH>());
			if (d2w_d1e888->depth != 0)
			{
				int n = 0;
				for (int j = d2w_d1e888->depth - 1; j >= 0; j--)
				{
					vector<D2wH> found;
					OpC_findNodes_470240(d2w_d1e884, j, levels[j], &found);
					n++;
					if (!levels[j].empty())
					{
						rows += n;
						n = 0;
					}
				}
			}
			int height = rows * size;
			pos.set_40a010(m - 1, halfDiff_437190(height, getHeight()) + height - size);
			cell = new CWorldMapPiece(this, 1, opr1c_hasPtr_cebd5c() ? 1 : 2, pos.x + 1, pos.y + 3, D2wH().ID);
			cell->animate("A_CWorldMap_Path_MAT_N", 0x32, 0);
			unknown98.push_back(cell);
		}
		D2wH elem = nodes[i];
		cell = new CWorldMapPiece(this, 3, 3, pos.x, pos.y, elem.ID);
		cell->animate("A_CWorldMap_Block_" + d2w_cfe140[elem->type]);
		cell->putChar_4180b0(1, 1, elem->known ? d2w_d38e40[elem->type][0] : 0x3f);
		cell->putChar_4180b0(0, 0, 0x88);
		cell->putChar_4180b0(1, 0, 0x81);
		cell->putChar_4180b0(2, 0, 0x89);
		cell->putChar_4180b0(0, 2, 0x87);
		int kind = 0x81;
		if (pieces.empty() || (cell->getPos().x == pieces.back()->getPos().x && !elem->unknown2b && !elem->unknown2c))
			kind = 0x86;
		cell->putChar_4180b0(1, 2, kind);
		cell->putChar_4180b0(2, 2, 0x8a);
		pieces.push_back(cell);
		unknown98.push_back(cell);
		int total = 0;
		for (unsigned int k = 0; k < nodes.size(); k++)
		{
			if (nodes[k]->type != 12 && nodes[k]->type != 13 && nodes[k]->type != 14)
				total++;
		}
		if (d2w_cefa94->unknown41a6e0() && unknown90 == -1)
		{
			if (d2w_d1e888 == pieces.back()->getNode_4aeed0() || pieces.size() == total - 1 || ((d2w_d1e888->type == 12 || d2w_d1e888->type == 13 || d2w_d1e888->type == 14) && nodes[i + 1] == d2w_d1e888) || (i == nodes.size() - 2 && (nodes[nodes.size() - 1]->type == 12 || nodes[nodes.size() - 1]->type == 13 || nodes[nodes.size() - 1]->type == 14)))
			{
				unknown90 = pieces.size() - 1;
				d2w_cefa94->setCellPoint_41a910(pieces.back()->localToAbs(Pos(1, 1)));
			}
		}
		D2wH next;
	restart:
		if (nodes.size() > i + 1)
			next = nodes[i + 1];
		if (next.isValid() && d2w_b90670[next->type] == 3)
		{
			i++;
			next.reset();
			goto restart;
		}
		if (next.isValid())
		{
			int dir = d2w_b90670[next->type];
			if (dir == unknown94 && unknown94 != 0)
				dir = (unknown94 != 2) + 1;
			if (next->type == 7 && nodes.size() > i + 2 && nodes[i + 2]->type == 15)
				dir = 2;
			if (elem->type == 8 || next->unknown20 == 2)
			{
				pos.y -= size;
				if (dir == 1)
					pos.x += 5;
				else
					pos.x -= 5;
			}
			else
			{
				switch (dir)
				{
				case 0:
					pos.x = m - 1;
					pos.y -= (elem->depth - next->depth) * size;
					break;
				case 1:
					pos.x -= 5;
					pos.y -= (elem->depth - next->depth) * size;
					if ((next->type == 20 || next->type == 21 || next->type == 23) && next->unknown2d && !elem->unknown2e)
						pos.x -= 5;
					break;
				case 2:
					pos.x += 5;
					pos.y -= (elem->depth - next->depth) * size;
					if ((next->type == 20 || next->type == 21 || next->type == 23) && next->unknown2d && !elem->unknown2e)
						pos.x += 5;
					break;
				}
			}
		}
		if (elem->unknown28)
		{
			pieces.back()->putChar_4180b0(0, 2, 0x93);
			pieces.back()->putChar_4180b0(1, 2, 0x8d);
			pieces.back()->putChar_4180b0(2, 2, 0x96);
			pieces.back()->animate("A_CWorldMap_Visited_WAS", 0x32, 0);
		}
		if (elem->unknown2a)
		{
			pieces.back()->putChar_4180b0(0, 0, 0x94);
			pieces.back()->putChar_4180b0(1, 0, 0x8d);
			pieces.back()->putChar_4180b0(2, 0, 0x95);
			pieces.back()->animate("A_CWorldMap_Visited_DSF", 0x30, 0);
		}
		else if (elem->unknown29)
		{
			pieces.back()->putChar_4180b0(0, 0, 0x94);
			pieces.back()->putChar_4180b0(1, 0, 0x8d);
			pieces.back()->putChar_4180b0(2, 0, 0x95);
			pieces.back()->animate("A_CWorldMap_Visited_GAR", 0x30, 0);
		}
		if (next.isValid())
		{
			bool linked = false;
			string suffix = next->unknown2c ? d2w_cfe2c8 : (next->unknown2b ? d2w_cfe2ac : d2w_cfe140[next->type]);
			if (next->unknown2d)
				suffix += "_S";
			if (pos.x == pieces.back()->getPos().x)
			{
				cell = new CWorldMapPiece(this, 1, opr1c_hasPtr_cebd5c() ? 1 : 2, pos.x + 1, pos.y + 3, D2wH().ID);
				cell->animate("A_CWorldMap_Path_" + suffix + "_N", 0x32, 0);
				unknown94 = 0;
				linked = true;
			}
			else if (pos.y == pieces.back()->getPos().y)
			{
				if (pos.x < pieces.back()->getPos().x)
				{
					cell = new CWorldMapPiece(this, pieces.back()->getPos().x - pos.x - 3, 1, pos.x + 3, pos.y + 1, D2wH().ID);
					cell->animate("A_CWorldMap_Path_" + suffix + "_W", 0x33, 0);
				}
				else
				{
					cell = new CWorldMapPiece(this, pos.x - pieces.back()->getPos().x - 3, 1, pieces.back()->getPos().x + 3, pos.y + 1, D2wH().ID);
					cell->animate("A_CWorldMap_Path_" + suffix + "_E", 0x32, 0);
				}
			}
			else
			{
				linked = true;
				if (next->unknown2d && !next->inRange())
				{
					if (pos.x < pieces.back()->getPos().x)
					{
						cell = new CWorldMapPiece(this, pieces.back()->getPos().x - pos.x - 1, pieces.back()->getPos().y - pos.y - 1, pos.x + 1, pos.y + 3, D2wH().ID);
						cell->animate("A_CWorldMap_Path_" + suffix + "_WN", 0x33, 0);
						unknown94 = 2;
					}
					else
					{
						cell = new CWorldMapPiece(this, pos.x - pieces.back()->getPos().x - 1, pieces.back()->getPos().y - pos.y - 1, pos.x - (pos.x - pieces.back()->getPos().x - 1) + 2, pos.y + 3, D2wH().ID);
						cell->animate("A_CWorldMap_Path_" + suffix + "_EN", 0x32, 0);
						unknown94 = 1;
					}
				}
				else
				{
					if (pos.x < pieces.back()->getPos().x)
					{
						cell = new CWorldMapPiece(this, pieces.back()->getPos().x - pos.x - 1, pieces.back()->getPos().y - pos.y - 1, pos.x + 3, pos.y + 1, D2wH().ID);
						cell->animate("A_CWorldMap_Path_" + suffix + "_NW", 0x33, 0);
						unknown94 = 2;
					}
					else
					{
						cell = new CWorldMapPiece(this, pos.x - pieces.back()->getPos().x - 1, pieces.back()->getPos().y - pos.y - 1, pos.x - (pos.x - pieces.back()->getPos().x - 1), pos.y + 1, D2wH().ID);
						cell->animate("A_CWorldMap_Path_" + suffix + "_NE", 0x32, 0);
						unknown94 = 1;
					}
				}
			}
			if (next->unknown2d)
				unknown98.push_back(cell);
			if (linked)
			{
				unknown996500(i, -1, -1);
				unknown98.clear();
			}
			if (!next->unknown2d || next->inRange())
				unknown98.push_back(cell);
		}
		else
		{
			pieces.back()->putChar_4180b0(0, 1, 0x3e);
			pieces.back()->putChar_4180b0(2, 1, 0x3c);
			pieces.back()->animate("A_CWorldMap_Cur_Glow_" + d2w_cfe140[elem->type]);
			unknown996500(i, -1, -1);
			if (d2w_d1e888->depth != 0)
			{
				int last = d2w_d1e888->depth;
				for (int j = last - 1; j >= 0; j--)
				{
					if (!levels[j].empty())
						last = j;
				}
				if (last < d2w_d1e888->depth)
				{
					int y = pieces.back()->getPos().y + 1;
					for (int level = d2w_d1e888->depth - 1; level >= last; level--)
					{
						y -= 2;
						int anim;
						OpU8a_lookup1("CWorldMap_Unvisited_Dot", &anim);
						if (anim != 0)
						{
							do
							{
								engine->unknown50fb50(engine, anim, Pos(m, y), &d2w_cfbec0, 0, 0, 9)->init_50de10();
							} while (0);
						}
						if (!opr1c_hasPtr_cebd5c())
						{
							y -= 1;
							if (anim != 0)
							{
								do
								{
									engine->unknown50fb50(engine, anim, Pos(m, y), &d2w_cfbec0, 0, 0, 9)->init_50de10();
								} while (0);
							}
						}
						y -= 2;
						if (levels[level].empty())
						{
							OpU8a_lookup1("CWorldMap_Unvisited_Unk", &anim);
							if (anim != 0)
							{
								do
								{
									engine->unknown50fb50(engine, anim, Pos(m, y), &d2w_cfbec0, 0, 0, 9)->init_50de10();
								} while (0);
							}
						}
						else
						{
							int left = m;
							int right = m;
							for (unsigned int k = 0; k < levels[level].size(); k++)
							{
								if (d2w_b90670[levels[level][k]->type] == 0)
								{
									pieces.push_back(new CWorldMapPiece(this, 1, 1, m, y, levels[level][k].ID));
									pieces.back()->putChar_4180b0(0, 0, d2w_d38e40[levels[level][k]->type][0]);
									pieces.back()->animate("CWorld_Block_" + d2w_cfe140[levels[level][k]->type] + "_Mid");
									left -= 2;
									right += 2;
									break;
								}
							}
							for (unsigned int k = 0; k < levels[level].size(); k++)
							{
								if (d2w_b90670[levels[level][k]->type] == 2)
								{
									pieces.push_back(new CWorldMapPiece(this, 1, 1, right, y, levels[level][k].ID));
									pieces.back()->putChar_4180b0(0, 0, d2w_d38e40[levels[level][k]->type][0]);
									pieces.back()->animate("CWorld_Block_" + d2w_cfe140[levels[level][k]->type] + "_Mid");
									if (left == m)
										left -= 2;
									right += 2;
								}
							}
							for (unsigned int k = 0; k < levels[level].size(); k++)
							{
								if (d2w_b90670[levels[level][k]->type] == 1)
								{
									pieces.push_back(new CWorldMapPiece(this, 1, 1, left, y, levels[level][k].ID));
									pieces.back()->putChar_4180b0(0, 0, d2w_d38e40[levels[level][k]->type][0]);
									pieces.back()->animate("CWorld_Block_" + d2w_cfe140[levels[level][k]->type] + "_Mid");
									if (right == m)
										right += 2;
									left -= 2;
								}
							}
							unknown996500(-1, left + 1, right);
						}
					}
				}
			}
			break;
		}
	}
}
