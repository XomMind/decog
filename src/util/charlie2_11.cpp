// Prelearned-data reveal (0x794da0; callers prelearnData and the BS turn updates): reveals machines, exits,
// entrances, layout blocks, traps, emergency access, stockpiles or a machine category on the current map,
// logs what was loaded and returns how many were revealed.
// NOTE: placeholder names and layouts throughout (C2R*, c2r_<address>).
#include <string>
using namespace std;

string intToString(int v);
void opU5_logWithShell(bool flag, const string &text);

struct C2RPoint { int x, y; C2RPoint(); C2RPoint(int nx, int ny); C2RPoint(const C2RPoint &o); void init453b40(); void add409a30(const C2RPoint &d); };
struct C2RBox
{
	C2RPoint p1, p2;
	C2RBox();
	C2RBox(int x1, int y1, int x2, int y2);
	bool contains40b750(const C2RPoint &p);
	bool contains40b8a0(const C2RBox &b);
	bool touches40baa0(const C2RBox &b);
	void unionWith40b940(const C2RBox &b, C2RBox &out);
	void randomPoint40be30(C2RPoint *p);
};
struct C2RLoc { int f0; int type; };
struct C2RLocH { int id; C2RLoc *operator->(); };
struct C2RPropH { int id; bool isNull() const; };
struct C2RRec { C2RPoint pos; C2RLocH loc; char fc; bool fd; char pe[6]; C2RPropH p14; C2RPropH p18; };
struct C2RRecVec { int f0, f1, f2, f3; C2RRecVec(); ~C2RRecVec(); unsigned size() const; C2RRec *&operator[](unsigned i); void push_back(C2RRec *const &r); };
struct C2RIntVec { int f0, f1, f2, f3; C2RIntVec(); ~C2RIntVec(); unsigned size() const; int &operator[](unsigned i); void push_back(const int &v); void push_back(int &&v); };
struct C2RUVec { int f0, f1, f2, f3; C2RUVec(); ~C2RUVec(); unsigned size() const; unsigned &operator[](unsigned i); void push_back(const unsigned &v); void push_back(unsigned &&v); };
struct C2RPtVec
{
	int f0, f1, f2, f3;
	C2RPtVec();
	~C2RPtVec();
	unsigned size() const;
	bool empty() const;
	C2RPoint &operator[](unsigned i);
	void push_back(const C2RPoint &p);
	void push_back(C2RPoint &&p);
};
struct C2RPtList { unsigned size() const; C2RPoint &operator[](unsigned i); };
struct C2RMarker { void set6c20b0(int kind, C2RPoint &p, int extra); int f14pad[5]; int type; };
struct C2RH { int id; C2RH(); bool isNull() const; C2RMarker *operator->() const; };
struct C2RHVec { int f0, f1, f2, f3; void clear(); unsigned size() const; C2RH &operator[](unsigned i); void push_back(const C2RH &h); const C2RH &back() const; };
struct C2RHVecVec { C2RHVec &operator[](unsigned i); };
struct C2RPtVecVec { C2RPtList &operator[](unsigned i); };
struct C2RIntRef { int &operator[](unsigned i); };
struct C2RPropInfo { char p00[0xf4]; int level; int category; };
struct C2RProp { void f65f170(); C2RPoint &pos4184d0(); C2RPropInfo *info(); };
struct C2RPropH2 { int id; C2RProp *operator->(); };
struct C2RPropList { unsigned size() const; bool empty() const; C2RPropH2 &operator[](unsigned i); };
struct C2RPropGrid { unsigned size() const; C2RPropList &operator[](unsigned i); };
struct C2RItemRec { char p00[0x94]; int f94; };
struct C2RItem { C2RItemRec *record(); int getNestedField(); };
struct C2RItemH { int id; C2RItemH(); bool isNull() const; C2RItem *operator->(); };
struct C2RCell { int terrain(); C2RItemH getItem(); bool f45dbb0(); void f670690(); void f670b20(); };
struct C2RMap { C2RCell **atPoint(const C2RPoint &p); C2RCell **at(int x, int y); int getWidth(); int getHeight(); };
struct C2REntity { C2RPoint f45a4c0(); };
struct C2REntityH { int id; C2REntity *operator->(); };
struct C2RSquad { int f0; C2REntityH leader; bool test45e820(); };
struct C2RSquadList { unsigned size() const; C2RSquad *&operator[](unsigned i); };
struct C2RBS
{
	C2RRecVec *getPos();
	C2RIntRef *known463ce0();
	void f726840(C2RBox &area, int v);
	void f4647d0(C2RPoint &p);
	void f734d60(const C2RPoint &p);
	void f4647a0(const C2RPoint &p, int v);
	C2RPtList *f463c20();
	C2RHVecVec *f463ec0();
	bool isVisible(C2RPoint &p);
	bool f463160(C2RPoint &p);
	C2RPtVecVec *f459070();
};
struct C2RView { void f8051f0(C2RPoint &a, C2RPoint &b); C2RPoint &f458ef0(); bool inBounds(C2RPoint &p); bool f8052f0(C2RPoint &p); void items8119c0(C2RItemH item, int a, int b, int c); };
struct C2RShell { void addPointDC(C2RPtVec &pts); void f4b0eb0(); };
struct C2REffect { void init50de10(); };
struct C2REngine { C2REffect *f50fb50(C2REngine *owner, void *type, C2RPoint &pos, void *data, int a, int b, int c); };
struct C2RMission { void f987de0(); };
struct C2RFactory { C2RH createC(); };

extern C2RBS *c2r_cefc4c;
extern C2RMap c2r_cfd44c;
extern C2RLocH c2r_d1e888;
extern string c2r_cfaca0[], c2r_cf3fb0[];
extern C2RView *c2r_cec054;
extern C2RShell *c2r_cec100;
extern C2REngine *c2r_cefc64;
extern char c2r_cfbec0[];
extern int c2r_cefb9c, c2r_cefba8;
extern C2RPropGrid c2r_d20248, c2r_d31640;
extern C2RMission *c2r_cec034;
extern C2RFactory *c2r_cefaa8;
extern C2RSquadList c2r_cf6478;
void c2r_revealRandomMachine(C2RRecVec &recs, int &count, C2RIntVec &cand, C2RPtVec &pts);
void c2r_showPointsA(C2RPtVec &pts);
void c2r_showPointsB(C2RPtVec &pts);
void c2r_markPropPoints(C2RPtVec &pts);
int c2r_minInt(int a, int b);
void c2r_shuffle(C2RPtVec &pts);
void c2r_lookup1(const string &name, void *&out);
string c2r_countString(int count, const string &noun);
bool c2r_logPhrase(int id, const string *a, const string *b, const string *c, C2RH subject, const void *at);
void c2r_eraseStepPt(C2RPtList &list, int &index);
void c2r_eraseStepH(C2RHVec &list, int &index);
bool c2r_containsRecord(C2RUVec &list, int v);
extern const char c2r_bf81b0[], c2r_bf81b4[], c2r_bf81bc[], c2r_bf81c4[], c2r_bf81c8[], c2r_bf81d4[], c2r_bf81d8[],
	c2r_bf81e4[], c2r_bf81f0[], c2r_bf81f4[], c2r_bf8200[], c2r_bf8204[], c2r_bf820c[], c2r_bf8214[], c2r_bf8218[],
	c2r_bf8224[], c2r_bf8230[], c2r_bf823c[], c2r_bf8248[], c2r_bf824c[], c2r_bf8258[], c2r_bf8270[], c2r_bf8278[],
	c2r_bf828c[], c2r_bf8298[], c2r_bf82a4[], c2r_bf82ac[], c2r_bf82c8[], c2r_bf82d4[], c2r_bf82dc[], c2r_bf82f0[],
	c2r_bf82fc[], c2r_bf8304[], c2r_bf8318[], c2r_bf8324[], c2r_bf832c[], c2r_bf8344[], c2r_bf8358[], c2r_bf8360[],
	c2r_bf836c[], c2r_bf8370[], c2r_bf837c[], c2r_bf8388[];

int c2p_reveal794da0(int kind, int count, bool flag, int max)
{
	int original = count;
	switch (kind)
	{
		break;
	case 1:
	{
		C2RRecVec *v = c2r_cefc4c->getPos();
		C2RIntVec options;
		C2RPtVec points;
		for (int i = 0; i < v->size(); i++)
		{
			if (!(*v)[i]->fd && (*v)[i]->p14.isNull() && (*v)[i]->p18.isNull() && (*v)[i]->loc->type != 0x16
				&& (*v)[i]->loc->type != 0xb && (*v)[i]->loc->type != 0x1d && (*v)[i]->loc->type != 0x23)
				options.push_back(i);
		}
		c2r_revealRandomMachine(*v, count, options, points);
		c2r_showPointsA(points);
		if (count != original)
		{
			string msg = c2r_bf81c8 + intToString(original - count) + c2r_bf81c4 + c2r_cfaca0[c2r_d1e888->type] + (original - count > 1 ? c2r_bf81b4 : c2r_bf81bc) + c2r_bf81b0;
			opU5_logWithShell(flag, msg);
		}
		return points.size();
	}
	case 2:
	{
		C2RRecVec *v = c2r_cefc4c->getPos();
		C2RIntVec options;
		C2RPtVec points;
		for (int i = 0; i < v->size(); i++)
		{
			if (!(*v)[i]->fd && (*v)[i]->p14.isNull() && (*v)[i]->p18.isNull() && (*v)[i]->loc->type == max)
				options.push_back(i);
		}
		c2r_revealRandomMachine(*v, count, options, points);
		c2r_showPointsA(points);
		if (count != original)
		{
			string msg = c2r_bf81f4 + intToString(original - count) + c2r_bf81f0 + c2r_cfaca0[max] + (original - count > 1 ? c2r_bf81d8 : c2r_bf81e4) + c2r_bf81d4;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
		}
		return points.size();
	}
	case 3:
	{
		C2RRecVec *v = c2r_cefc4c->getPos();
		C2RIntVec options;
		C2RPtVec points;
		for (int i = 0; i < v->size(); i++)
		{
			if (!(*v)[i]->fd && (*v)[i]->p14.isNull() && (*v)[i]->p18.isNull())
				options.push_back(i);
		}
		c2r_revealRandomMachine(*v, count, options, points);
		c2r_showPointsA(points);
		if (count != original)
		{
			string msg = c2r_bf8218 + intToString(original - count) + c2r_bf8214 + c2r_cfaca0[c2r_d1e888->type] + (original - count > 1 ? c2r_bf8204 : c2r_bf820c) + c2r_bf8200;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
		}
		return original - count;
	}
	case 4:
	{
		C2RPtVec result;
		int cols = c2r_cfd44c.getWidth() / 25 + (c2r_cfd44c.getWidth() % 25 ? 1 : 0);
		int tx = c2r_cfd44c.getHeight() / 25 + (c2r_cfd44c.getHeight() % 25 ? 1 : 0);
		if (count >= cols * tx && cols * tx * 25 >= c2r_cfd44c.getWidth() * c2r_cfd44c.getHeight())
		{
			string text = c2r_bf8230 + c2r_cfaca0[c2r_d1e888->type] + c2r_bf8224;
			opU5_logWithShell(flag, text);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
			C2RBox area(0, 0, c2r_cfd44c.getWidth() - 1, c2r_cfd44c.getHeight() - 1);
			c2r_cefc4c->f726840(area, 0);
			C2RBox first;
			c2r_cec054->f8051f0(first.p1, first.p2);
			for (int x = first.p1.x; x <= first.p2.x; x++)
				for (int y = first.p1.y; y <= first.p2.y; y++)
					result.push_back(C2RPoint(x, y));
			count -= cols * tx;
			C2RRecVec *base = c2r_cefc4c->getPos();
			C2RPtVec pos;
			for (unsigned i = 0; i < base->size(); i++)
			{
				if (area.contains40b750((*base)[i]->pos) && (*base)[i]->p14.isNull() && (*base)[i]->p18.isNull() && (*base)[i]->loc->type != 0x16 && (*base)[i]->loc->type != 0x1d)
				{
					C2RRecVec vv;
					vv.push_back((*base)[i]);
					int counter = 1;
					C2RIntVec idx;
					idx.push_back(0);
					c2r_revealRandomMachine(vv, counter, idx, pos);
					c2r_showPointsA(pos);
				}
			}
		}
		else
		{
			C2RPtVec blocks;
			for (int bx = 0; bx < cols; bx++)
			{
				for (int by = 0; by < tx; by++)
				{
					C2RPoint pt;
					int walls = 0;
					C2RBox cell(bx * 25, by * 25, c2r_minInt(c2r_cfd44c.getWidth(), bx * 25 + 25) - 1, c2r_minInt(c2r_cfd44c.getHeight(), by * 25 + 25) - 1);
					for (int t = 0; t < 100; t++)
					{
						cell.randomPoint40be30(&pt);
						if ((*c2r_cfd44c.atPoint(pt))->terrain() == c2r_cefb9c)
							walls++;
					}
					if (walls >= 10)
						blocks.push_back(C2RPoint(bx, by));
				}
			}
			if (!blocks.empty())
			{
				string msg = c2r_bf824c + intToString(count) + c2r_bf8248 + c2r_cfaca0[c2r_d1e888->type] + c2r_bf823c;
				opU5_logWithShell(flag, msg);
				(*c2r_cefc4c->known463ce0())[kind] = 1;
			}
			c2r_shuffle(blocks);
			for (unsigned i = 0; i < blocks.size() && count != 0; i++)
			{
				C2RBox area(blocks[i].x * 25, blocks[i].y * 25, c2r_minInt(c2r_cfd44c.getWidth(), blocks[i].x * 25 + 25) - 1, c2r_minInt(c2r_cfd44c.getHeight(), blocks[i].y * 25 + 25) - 1);
				c2r_cefc4c->f726840(area, 0);
				C2RBox temp;
				c2r_cec054->f8051f0(temp.p1, temp.p2);
				if (!temp.contains40b8a0(area) && !area.contains40b8a0(temp) && temp.touches40baa0(area))
				{
					C2RBox both;
					temp.unionWith40b940(area, both);
					for (int x = both.p1.x; x <= both.p2.x; x++)
						for (int y = both.p1.y; y <= both.p2.y; y++)
							result.push_back(C2RPoint(x, y));
				}
				count--;
				C2RRecVec *base = c2r_cefc4c->getPos();
				C2RPtVec pos;
				for (unsigned j = 0; j < base->size(); j++)
				{
					if (area.contains40b750((*base)[j]->pos) && (*base)[j]->p14.isNull() && (*base)[j]->p18.isNull() && (*base)[j]->loc->type != 0x16)
					{
						C2RRecVec vv;
						vv.push_back((*base)[j]);
						int counter = 1;
						C2RIntVec idx;
						idx.push_back(0);
						c2r_revealRandomMachine(vv, counter, idx, pos);
						c2r_showPointsA(pos);
					}
				}
			}
		}
		if (!result.empty())
		{
			if (c2r_cec100)
				c2r_cec100->addPointDC(result);
			else
			{
				void *effect = 0;
				c2r_lookup1(c2r_bf8258, effect);
				if (effect)
				{
					C2RPoint offset = c2r_cec054->f458ef0();
					for (unsigned i = 0; i < result.size(); i++)
					{
						result[i].add409a30(offset);
						if (c2r_cec054->inBounds(result[i]))
							c2r_cefc64->f50fb50(c2r_cefc64, effect, result[i], c2r_cfbec0, 0, 0, 9)->init50de10();
					}
				}
			}
		}
		return original - count;
	}
	case 5:
	{
		C2RPtVec pts;
		for (unsigned i = 0; i < c2r_d20248.size(); i++)
		{
			for (unsigned j = 0; j < c2r_d20248[i].size(); j++)
			{
				c2r_d20248[i][j]->f65f170();
				c2r_cefc4c->f4647d0(c2r_d20248[i][j]->pos4184d0());
				pts.push_back(c2r_d20248[i][j]->pos4184d0());
			}
		}
		c2r_markPropPoints(pts);
		if (!pts.empty())
		{
			string msg = c2r_bf828c + c2r_cfaca0[c2r_d1e888->type] + c2r_bf8278 + intToString(pts.size()) + c2r_bf8270;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
			string records = c2r_countString(pts.size(), c2r_bf8298);
			do
			{
				c2r_logPhrase(0x22, &records, 0, 0, C2RH(), 0);
			} while (0);
			return 1;
		}
		else
			return 0;
	}
	case 6:
	{
		C2RPtVec pts;
		for (int x = 0; x < c2r_cfd44c.getWidth(); x++)
		{
			for (int y = 0; y < c2r_cfd44c.getHeight(); y++)
			{
				if ((*c2r_cfd44c.at(x, y))->terrain() == c2r_cefba8)
				{
					c2r_cefc4c->f734d60(C2RPoint(x, y));
					bool opened = false;
					if ((*c2r_cfd44c.atPoint(C2RPoint(x, y)))->f45dbb0())
					{
						(*c2r_cfd44c.atPoint(C2RPoint(x, y)))->f670690();
						opened = true;
					}
					c2r_cefc4c->f4647a0(C2RPoint(x, y), 1);
					if (opened)
						(*c2r_cfd44c.atPoint(C2RPoint(x, y)))->f670b20();
					pts.push_back(C2RPoint(x, y));
				}
			}
		}
		c2r_showPointsB(pts);
		if (!pts.empty())
		{
			string msg = c2r_bf82c8 + c2r_cfaca0[c2r_d1e888->type] + c2r_bf82ac + intToString(pts.size()) + c2r_bf82a4;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
			return 1;
		}
		else
			return 0;
	}
	case 7:
	{
		C2RPtList *result = c2r_cefc4c->f463c20();
		C2RPtVec points;
		C2RItemH item;
		C2RHVec &array = (*c2r_cefc4c->f463ec0())[0xe];
		C2RHVec &center = (*c2r_cefc4c->f463ec0())[0xf];
		array.clear();
		center.clear();
		for (int i = 0; i < result->size(); i++)
		{
			item = (*c2r_cfd44c.atPoint((*result)[i]))->getItem();
			if (item.isNull())
				c2r_eraseStepPt(*result, i);
			else
			{
				c2r_cefc4c->f4647d0((*result)[i]);
				points.push_back((*result)[i]);
				int type = ((*c2r_cfd44c.atPoint((*result)[i]))->getItem()->record()->f94 != 0) + 0xe;
				C2RHVec &list = type == 0xe ? array : center;
				list.push_back(c2r_cefaa8->createC());
				list.back()->set6c20b0(type, (*result)[i], (*c2r_cfd44c.atPoint((*result)[i]))->getItem()->getNestedField());
			}
		}
		if (!points.empty())
		{
			string msg = c2r_bf82f0 + c2r_cfaca0[c2r_d1e888->type] + c2r_bf82dc + intToString(points.size()) + c2r_bf82d4;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
			if (!c2r_cec100)
			{
				c2r_cec034->f987de0();
				for (unsigned j = 0; j < points.size(); j++)
				{
					if (!c2r_cefc4c->isVisible(points[j]) && c2r_cec054->f8052f0(points[j]))
						c2r_cec054->items8119c0((*c2r_cfd44c.atPoint(points[j]))->getItem(), 0, 0, 0);
				}
			}
			else
				c2r_cec100->f4b0eb0();
			return 1;
		}
		else
			return 0;
	}
	case 8:
	{
		int found = 0;
		int flags = 0;
		int layer = 2;
		C2RHVec &list = (*c2r_cefc4c->f463ec0())[layer];
		list.clear();
		for (unsigned i = 0; i < c2r_cf6478.size(); i++)
		{
			if (c2r_cf6478[i]->f0 == flags && !c2r_cf6478[i]->test45e820())
			{
				found++;
				list.push_back(c2r_cefaa8->createC());
				list.back()->set6c20b0(layer, c2r_cf6478[i]->leader->f45a4c0(), -1);
			}
		}
		if (found)
		{
			string msg = c2r_bf8318 + c2r_cfaca0[c2r_d1e888->type] + c2r_bf8304 + intToString(found) + c2r_bf82fc;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
			if (!c2r_cec100)
				c2r_cec034->f987de0();
			else
				c2r_cec100->f4b0eb0();
			return 1;
		}
		else
			return 0;
	}
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	{
		C2RPtVec current;
		int machines = 0;
		for (unsigned i = 0; i < c2r_d31640.size(); i++)
		{
			if (!c2r_d31640[i].empty())
			{
				switch (kind)
				{
				case 9:
					break;
				case 10:
					if (c2r_d31640[i][0]->info()->level >= 2)
						break;
					continue;
				case 11:
					if (c2r_d31640[i][0]->info()->level == 1)
						break;
					continue;
				default:
					if (kind - 12 == c2r_d31640[i][0]->info()->category)
						break;
					continue;
				}
				for (unsigned j = 0; j < c2r_d31640[i].size(); j++)
				{
					if (!c2r_cefc4c->f463160(c2r_d31640[i][j]->pos4184d0()))
						c2r_cefc4c->f4647d0(c2r_d31640[i][j]->pos4184d0());
					if (c2r_cec054->f8052f0(c2r_d31640[i][j]->pos4184d0()))
						current.push_back(c2r_d31640[i][j]->pos4184d0());
				}
				machines++;
			}
		}
		if (machines)
		{
			C2RHVec &list = (*c2r_cefc4c->f463ec0())[0];
			if (kind != 10)
			{
				C2RUVec options;
				if (kind == 9 || kind == 11)
				{
					for (int t = 0; t < 9; t++)
						options.push_back(t);
				}
				else
					options.push_back(kind - 12);
				for (int m = 0; m < list.size(); m++)
				{
					if (c2r_containsRecord(options, list[m]->type))
						c2r_eraseStepH(list, m);
				}
				int total = 0;
				for (unsigned n = 0; n < options.size(); n++)
				{
					C2RPtList &spots = (*c2r_cefc4c->f459070())[options[n]];
					if (!((C2RPropList &)spots).empty())
					{
						for (unsigned s = 0; s < spots.size(); s++)
						{
							list.push_back(c2r_cefaa8->createC());
							list.back()->set6c20b0(0, spots[s], options[n]);
						}
						total += spots.size();
					}
				}
				if (total)
				{
					if (!c2r_cec100)
						c2r_cec034->f987de0();
					else
						c2r_cec100->f4b0eb0();
				}
			}
			string title;
			switch (kind)
			{
			case 9:
				title = c2r_bf8324;
				break;
			case 10:
				title = c2r_bf832c;
				break;
			case 11:
				title = c2r_bf8344;
				break;
			default:
				title = c2r_cf3fb0[kind - 12];
			}
			string msg = c2r_bf8370 + c2r_cfaca0[c2r_d1e888->type] + c2r_bf836c + title + c2r_bf8360 + intToString(machines) + c2r_bf8358;
			opU5_logWithShell(flag, msg);
			(*c2r_cefc4c->known463ce0())[kind] = 1;
			string text = c2r_countString(machines, title + c2r_bf837c);
			do
			{
				c2r_logPhrase(0x22, &text, 0, 0, C2RH(), 0);
			} while (0);
			if (!current.empty())
			{
				if (c2r_cec100)
					c2r_cec100->addPointDC(current);
				else
				{
					void *effect = 0;
					c2r_lookup1(c2r_bf8388, effect);
					if (effect)
					{
						C2RPoint offset = c2r_cec054->f458ef0();
						for (unsigned i = 0; i < current.size(); i++)
						{
							current[i].add409a30(offset);
							if (c2r_cec054->inBounds(current[i]))
								c2r_cefc64->f50fb50(c2r_cefc64, effect, current[i], c2r_cfbec0, 0, 0, 9)->init50de10();
						}
					}
				}
			}
			return 1;
		}
		else
			return 0;
	}
	}
	return 0;
}
