// WAR staging-area squad dispatch (0x73acc0; callers BS::unknown73a490 and BS::turnUpdate_74e750).
// NOTE: placeholder names and layouts throughout (C2W*).
#include <string>
#include <vector>
using namespace std;

class RNG { public: bool chance(int percent); };
extern RNG rng;

struct C2WPoint	// NOTE: placeholder (Point)
{
	int x, y;
	C2WPoint(int v);
	C2WPoint(const C2WPoint &o);
	C2WPoint &operator=(const C2WPoint &o);
	void set40a010(int nx, int ny);
};
struct C2WArea	// NOTE: placeholder (x, y, w, h)
{
	int x, y, w, h;
	C2WArea();
	void set40a840(int nx, int ny, int nw, int nh);
	int right40ac20();
	int bottom40ac40();
};
struct C2WBox	// NOTE: placeholder (two corners)
{
	C2WPoint p1, p2;
	C2WBox();
	C2WBox(int x1, int y1, int x2, int y2);
	void set40b300(int x1, int y1, int x2, int y2);
};
struct C2WAI { void setFollowEntity(struct C2WHandle leader, int flag); void bounds459410(C2WBox &box); };
struct C2WEntity { int getFaction(); C2WAI *ai45b590(); C2WPoint &getPosition(); bool check5cb680(struct C2WHandle other); };
struct C2WHandle	// NOTE: placeholder (HEntity)
{
	int id;
	C2WHandle();
	bool isValid() const;
	C2WEntity *operator->() const;
	void reset9b7270();
};
struct C2WProp { void f41a800(int x, int y); };
struct C2WPropHandle { int id; C2WPropHandle(); C2WProp *operator->(); };
struct C2WCell
{
	void f66a050(int a, int b, int c);
	bool f45df50(C2WPropHandle prop);
	C2WPropHandle getProp();
	C2WHandle getEntity();
};
struct C2WMap { C2WCell **at(int x, int y); int getWidth(); int getHeight(); };
struct C2WRec { int id; };
struct C2WEffect	// NOTE: placeholder (SExplosionExpand, 0x40 bytes)
{
	int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
	C2WEffect(C2WHandle source, C2WRec *rec, const C2WPoint &pos, C2WHandle target, const C2WPoint &a, const C2WPoint &b);
};
struct C2WFactory { C2WPropHandle createE(C2WRec *rec); C2WHandle createA(C2WEffect *effect); };
struct C2WWeighted	// NOTE: placeholder (weighted int list)
{
	int f0, f1, f2, f3, f4, f5, f6, f7, f8;
	C2WWeighted(vector<int> &weights);
	~C2WWeighted();
	int &pick();
};
struct C2WStats { void set451400(int v); };
struct C2WBubble { void bubble(int v); };
struct C2WLog { void scrollToEnd(); };

class C2WBS	// NOTE: placeholder layout (BS)
{
public:
	void f6c38a0(C2WArea &area, int a, float b, int c);
	C2WRec *selectRobotOfClass(int kind, int type, bool first, int d);
	C2WHandle placeEntity(C2WRec *rec, const C2WPoint &pos, int a, int b, int c, int d, int e);
	C2WHandle f463890(int v);
	bool isVisible(C2WPoint &pos);
	C2WHandle addRecord(C2WHandle effect);
	void warStaging73acc0(int param, C2WPoint *pos);
};

extern int c2w_d1ebd0, c2w_d2c46c;
extern bool c2w_d1ebd4;
extern int *c2w_cefb88;
extern C2WMap c2w_cfd44c;
extern C2WFactory *c2w_cefaa8;
extern vector<C2WRec *> c2w_cf35b0, c2w_cfd2cc;
extern C2WStats c2w_cf1080;
extern C2WBubble *c2w_cec058;
extern C2WLog *c2w_cec0b4;
bool c2w_find9d7710(vector<C2WRec *> &list, const string &name, C2WRec *&out);
bool c2w_find9d7be0(vector<C2WRec *> &list, const string &name, C2WRec *&out);
void c2w_message49c610(int id, C2WHandle source, const string &text, int flag);
void c2w_eraseAt(vector<int> &v, unsigned &index);
string intToString(int v);
void c2w_log4541b0(int a, int b, int c);
bool c2w_show5111e0(int id, string &text, int a, int b, C2WHandle c, C2WHandle d, int e, int f);
extern const char c2w_bf1760[], c2w_bf17dc[], c2w_bf17f4[], c2w_bf1814[], c2w_bf182c[], c2w_bf183c[], c2w_bf1838[],
	c2w_bf1830[], c2w_bf1840[], c2w_bf1844[], c2w_bf1860[];
extern const char c2w_bf1774[], c2w_bf1780[], c2w_bf1788[], c2w_bf1790[], c2w_bf1798[], c2w_bf17a4[], c2w_bf17ac[], c2w_bf17b4[], c2w_bf17bc[], c2w_bf17c4[], c2w_bf17d0[];

void C2WBS::warStaging73acc0(int param, C2WPoint *pos)
{
	C2WRec *owner;
	C2WArea wall;
	C2WBox room;
	switch (c2w_d1ebd0)
	{
	case 0:
		wall.set40a840(0x70, 0xf, 3, 2);
		room.set40b300(0x72, 0xf, 0x72, 0x10);
		break;
	case 1:
		wall.set40a840(0x6e, 0x21, 5, 2);
		room.set40b300(0x72, 0x21, 0x72, 0x22);
		break;
	case 2:
		wall.set40a840(0x6f, 0x33, 4, 2);
		room.set40b300(0x72, 0x33, 0x72, 0x34);
		break;
	}
	if (param == 1)
	{
		for (int x = wall.x; x <= wall.right40ac20(); x++)
			for (int y = wall.y; y <= wall.bottom40ac40(); y++)
				(*c2w_cfd44c.at(x, y))->f66a050(*c2w_cefb88, 2, 0);
		f6c38a0(wall, 0, 1, c2w_d2c46c);
		C2WRec *door;
		if (c2w_find9d7710(c2w_cf35b0, c2w_bf1760, door))
		{
			for (int x2 = room.p1.x; x2 <= room.p2.x; x2++)
				for (int y2 = room.p1.y; y2 <= room.p2.y; y2++)
					if ((*c2w_cfd44c.at(x2, y2))->f45df50(c2w_cefaa8->createE(door)))
						(*c2w_cfd44c.at(x2, y2))->getProp()->f41a800(x2, y2);
		}
	}
	vector<vector<int> > vec;
	vector<int> rank;
	vector<string> group;
	vec.push_back(vector<int>());
	vec.back().push_back(17);
	vec.back().push_back(22);
	vec.back().push_back(22);
	vec.back().push_back(19);
	rank.push_back(param == 1 ? 25 : param < 3 ? 0 : 5);
	group.push_back(c2w_bf1774);
	vec.push_back(vector<int>());
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(16);
	rank.push_back(20);
	group.push_back(c2w_bf1780);
	vec.push_back(vector<int>());
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(17);
	vec.back().push_back(18);
	vec.back().push_back(8);
	rank.push_back(5);
	group.push_back(c2w_bf1788);
	vec.push_back(vector<int>());
	vec.back().push_back(13);
	vec.back().push_back(13);
	vec.back().push_back(13);
	vec.back().push_back(13);
	vec.back().push_back(13);
	rank.push_back(5);
	group.push_back(c2w_bf1790);
	vec.push_back(vector<int>());
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(15);
	vec.back().push_back(15);
	vec.back().push_back(15);
	rank.push_back(10);
	group.push_back(c2w_bf1798);
	vec.push_back(vector<int>());
	vec.back().push_back(24);
	vec.back().push_back(24);
	vec.back().push_back(13);
	vec.back().push_back(13);
	rank.push_back(10);
	group.push_back(c2w_bf17a4);
	vec.push_back(vector<int>());
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(19);
	rank.push_back(10);
	group.push_back(c2w_bf17ac);
	vec.push_back(vector<int>());
	vec.back().push_back(17);
	vec.back().push_back(17);
	vec.back().push_back(18);
	vec.back().push_back(19);
	rank.push_back(10);
	group.push_back(c2w_bf17b4);
	vec.push_back(vector<int>());
	vec.back().push_back(23);
	vec.back().push_back(16);
	vec.back().push_back(16);
	vec.back().push_back(16);
	rank.push_back(10);
	group.push_back(c2w_bf17bc);
	vec.push_back(vector<int>());
	vec.back().push_back(25);
	vec.back().push_back(25);
	vec.back().push_back(25);
	rank.push_back(10);
	group.push_back(c2w_bf17c4);
	if (!pos)
	{
	vec.push_back(vector<int>());
	vec.back().push_back(28);
	vec.back().push_back(28);
	rank.push_back(5);
	group.push_back(c2w_bf17d0);
	}
	C2WWeighted pick(rank);
	bool armor = false;
	vector<int> chosen;
	int n = pos == 0 ? 4 : 2;
	C2WHandle elem;
	C2WHandle leader;
	bool visible = false;
	C2WBox edges(0, 0, 0x49, c2w_cfd44c.getHeight() - 1);
	C2WBox behaviour(0, 0, c2w_cfd44c.getWidth() - 1, c2w_cfd44c.getHeight() - 1);
	for (int i = 0; i < n; i++)
	{
		int index;
		if (c2w_d1ebd4 && !pos && i == 0)
			index = 0;
		else
			index = pick.pick();
		chosen.push_back(index);
		leader.reset9b7270();
		for (unsigned j = 0; j < vec[index].size(); j++)
		{
			owner = selectRobotOfClass(1, vec[index][j], j == 0, 1);
			if (owner)
			{
				elem = placeEntity(owner, pos ? *pos : room.p1, 3, 0, 3, 0xe, 0);
				if (elem.isValid())
				{
					visible = true;
					if (!pos)
						c2w_d1ebd4 = false;
					if (j == 0 && elem->getFaction() != 0x1c)
						leader = elem;
					else if (leader.isValid())
						elem->ai45b590()->setFollowEntity(leader, 0);
					elem->ai45b590()->bounds459410(behaviour);
				}
				else if (!visible)
				{
					C2WPoint target(-1);
					if (!pos)
					{
						for (int x3 = wall.x; x3 <= wall.right40ac20(); x3++)
						{
							for (int y3 = wall.y; y3 <= wall.bottom40ac40(); y3++)
							{
								if ((*c2w_cfd44c.at(x3, y3))->getEntity().isValid() && (*c2w_cfd44c.at(x3, y3))->getEntity()->check5cb680(f463890(3)))
								{
									target.set40a010(x3, y3);
									break;
								}
							}
						}
					}
					else
						target = *pos;
					if (target.x != -1)
					{
						C2WRec *missile;
						if (c2w_find9d7be0(c2w_cfd2cc, c2w_bf17dc, missile))
						{
							if (isVisible(target))
								c2w_message49c610(0x320, C2WHandle(), string(c2w_bf17f4), 0);
							addRecord(c2w_cefaa8->createA(new C2WEffect(C2WHandle(), missile, target, C2WHandle(), C2WPoint(-1), C2WPoint(-1))));
						}
					}
					if (!pos)
						c2w_d1ebd4 = true;
					return;
				}
			}
		}
		if (param > 3 && rng.chance(50) && leader.isValid())
		{
			owner = selectRobotOfClass(2, rng.chance(50) ? 30 : 31, 0, 1);
			if (owner)
			{
				elem = placeEntity(owner, leader->getPosition(), 3, 0, 3, 0xe, 0);
				if (elem.isValid())
				{
					elem->ai45b590()->setFollowEntity(leader, 0);
					elem->ai45b590()->bounds459410(edges);
					armor = true;
				}
			}
		}
	}
	if (param > 1 && !chosen.empty() && !pos)
	{
		string message = c2w_bf1814;
		for (unsigned k = 0; k < chosen.size(); k++)
		{
			int copies = 1;
			for (unsigned m = k + 1; m < chosen.size(); m++)
			{
				if (group[chosen[k]] == group[chosen[m]])
				{
					c2w_eraseAt(chosen, m);
					copies++;
				}
			}
			if (k != 0)
				message += c2w_bf182c;
			message += c2w_bf183c + intToString(copies) + c2w_bf1838 + group[chosen[k]] + c2w_bf1830;
			if (copies > 1)
				message += c2w_bf1840;
		}
		if (armor)
			message += c2w_bf1844;
		message += c2w_bf1860;
		do
		{
			c2w_cf1080.set451400(1);
			if (0)
				c2w_log4541b0(-1, 0, 0);
			do
			{
				if (c2w_show5111e0(0x324, message, 0, 0, C2WHandle(), C2WHandle(), 0, 0))
					c2w_cec058->bubble(1);
				c2w_cec0b4->scrollToEnd();
			} while (0);
			c2w_cec0b4->scrollToEnd();
		} while (0);
	}
}
