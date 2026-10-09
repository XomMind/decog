// Per-turn world update (0x774b70, called from CMap::update): expires dead entities, advances scripted prop
// movers, plays latent-energy links, ticks timers/drains, then runs the special-mode state machine (seed logging
// for exiles runs, debug quick-start setups, map screenshots, evolution/exit handling).
// NOTE: placeholder names and layouts throughout (C2X*, c2x_<address>).
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

class RNG { public: bool chance(int percent); };
extern RNG rng;
extern int TERRAIN_EARTH;
extern int TERRAIN_CAVE_WALL;
extern int *caveinThirdTerrain;
void gameOver();
string intToString(int v);

struct Point { int x, y; Point(const Point &o); void add409a30(const Point &d); bool test409bd0(const Point &o); };
struct C2XPos { int x, y; C2XPos(int nx, int ny); };
struct C2XBox { Point p1, p2; C2XBox(); C2XBox(int x1, int y1, int x2, int y2); C2XBox(const C2XPos &p, int w, int h); };
struct C2XPointTmp { int x, y; void init453b40(); };
struct C2XStrVec { int f0, f1, f2, f3; C2XStrVec(); ~C2XStrVec(); string &operator[](unsigned i); unsigned size() const; void push_back(const string &s); };

struct C2XDone { virtual void v0(); virtual void v1(); virtual bool expired(); };
struct C2XDoneHandle { int id; C2XDone *operator->(); };
struct C2XEntity;
struct C2XEntityHandle
{
	int id;
	C2XEntityHandle();
	bool isValid() const;
	C2XEntity *operator->() const;
	bool operator==(C2XEntityHandle o) const;
	void reset9b7270();
};
struct C2XPropInfo { char p00[0x68]; int f68; };
struct C2XProp { Point &pos4184d0(); C2XPropInfo *info(); void move45cc50(Point &p); };
struct C2XPropHandle { int id; C2XPropHandle(); bool isValid() const; bool isNull() const; C2XProp *operator->(); };
struct C2XRecord { char p00[0x24]; string name; };
struct C2XItem { void remove57dbe0(int a, int b, int c, int d); int getEffect(int type); C2XRecord *record(); int integrity(); void setIntegrity(int v); int drain457c80(); };
struct C2XWatched { void setState(int v); };
struct C2XWatchView { int id; C2XWatched *operator->(); };
struct C2XItemHandle { int id; C2XItemHandle(); bool isValid() const; C2XItem *operator->(); };
struct C2XItemVec { int f0, f1, f2, f3; C2XItemVec(); ~C2XItemVec(); C2XItemHandle &operator[](unsigned i); unsigned size() const; };
struct C2XEntity
{
	Point &getPosition();
	int getField490840();
	int f5cb8b0(C2XItemVec &items);
	void f5dea60(int v, int w);
	int getTarget();
	void changePos(Point &p, bool flag);
	void changePos(const C2XPos &p, bool flag);
};
struct C2XCell
{
	C2XPropHandle getProp();
	C2XEntityHandle getEntity();
	C2XItemHandle getItem();
	void clear45df70();
	bool place45df50(C2XPropHandle p);
	void f66d470(int a, int b, int c, int d);
	void f66a050(int a, int b, int c);
	int terrain();
};
struct C2XMap { C2XCell **atPoint(const Point &p); C2XCell **at(int x, int y); int getWidth(); int getHeight(); Point getRandom9cf050(); void getRect(const Point &p, int r, C2XBox &out); };
struct C2XPropList { int f0, f1, f2, f3; unsigned size() const; C2XPropHandle &operator[](unsigned i); };
struct C2XPropLists { C2XPropList &operator[](unsigned i); };
struct C2XMover	// NOTE: placeholder layout (scripted prop mover)
{
	int list;			// +0x00
	int count;			// +0x04
	vector<int> steps;	// +0x08
	int sound;			// +0x18
	Point pos;		// +0x1c
	int f24;			// +0x24
	unsigned last;		// +0x28
};
struct C2XMoverVec { int f0, f1, f2, f3; unsigned size() const; C2XMover *&operator[](unsigned i); bool empty() const; };
struct C2XHandleVec { int f0, f1, f2, f3; unsigned size() const; C2XDoneHandle &operator[](unsigned i); bool empty() const; };
struct C2XSound { char p00[8]; vector<int> channels; char p18[0x34 - 0x18]; int group; };
struct C2XSoundVec { C2XSound *&operator[](unsigned i); };
struct C2XLink { Point pos; int f8; unsigned fc; };
struct C2XLinkVec { int f0, f1, f2, f3; unsigned size() const; C2XLink *&operator[](unsigned i); bool empty() const; };
struct C2XEffect { void init503b20(); };
struct C2XEndObj { bool update(); C2XEffect *f508610(C2XEndObj *owner, void *type, Point &pos, void *data, int a, int b, int c, int d, int e); };
struct C2XMapView { void f49ad30(); bool f805190(C2XPointTmp &p); };
struct C2XPool { void remove(C2XEntityHandle h, bool flag); };
struct C2XMixer { void haltGroup(int g); void setSoundVolume(int channel, int volume); };
struct C2XSoundMgr { void f500010(); };
struct C2XStatus { void drawStatus(bool flag); };
struct C2XParts { C2XStatus *f894e70(C2XItemHandle item); };
struct C2XTimer { int ticks, f4, f8; C2XTimer(int t); };
struct C2XMission { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void start(const C2XTimer &t); void f988ad0(int v); };
struct C2XLocation { int f0; int location; int depth; vector<C2XEntityHandle> exits; int f46ed20(); };
struct C2XLocHandle { int id; C2XLocHandle(); C2XLocation *operator->(); };
struct C2XLocVec { int f0, f1, f2, f3; C2XLocVec(); ~C2XLocVec(); void push_back(const C2XLocHandle &h); };
struct C2XLocHandleVec { unsigned size() const; C2XLocHandle &operator[](unsigned i); };
struct C2XGameData { int f46f4e0(); bool f46f4b0(int v); int f789090(); };
struct C2XShooter { void saveMapScreenshot873ba0(string name); };
struct C2XEvolveList { unsigned size() const; C2XLocHandle &operator[](unsigned i); };
struct C2XRecVec { unsigned size() const; struct C2XWorldRec *&operator[](unsigned i); };
struct C2XWorldRec { int f0; string name; char p20[4]; int f24; int f28; char p2c[0x68 - 0x2c]; int f68; };
struct C2XPhrase { int f[10]; C2XPhrase(string text, string *a, string *b, string *c, C2XEntityHandle d, C2XEntityHandle e); };
struct C2XLog { int push5121f0(C2XPhrase *p); };
struct C2XBubble { void bubble(int v); };
struct C2XLogMsgs { void scrollToEnd(); };
struct C2XTurnQueue { void f672700(); };

class C2XBS	// NOTE: placeholder layout (BS)
{
public:
	char p000[0x658];
	int state;					// +0x658
	char p65c[0x66c - 0x65c];
	C2XEntityHandle player;		// +0x66c
	char p670[0xa30 - 0x670];
	C2XHandleVec expiring;		// +0xa30
	char pa40[0xa70 - 0xa40];
	unsigned timer;				// +0xa70
	char pa74[4];
	C2XEntityHandle watched;	// +0xa78
	C2XEntityHandle hacked;		// +0xa7c
	C2XMoverVec movers;			// +0xa80
	char pa90[0xb1c - 0xa90];
	unsigned drainTime;			// +0xb1c

	bool isVisible(Point &p);
	void f72e8e0(int v);
	void f732ce0(int v);
	bool f71bb50();
	void f734db0(C2XEntityHandle h);
	int getTurn();
	void f774390(int a, int b);
	void f726840(C2XBox &area, int v);
	void f777190(int v);
	void update774b70();
};

extern C2XEndObj *c2x_cefc50;
extern C2XMapView *c2x_cec054;
extern C2XPool c2x_d20404;
extern bool c2x_cefb3e, c2x_d28dfd, c2x_cefafc, c2x_cefaee, c2x_cefb09, c2x_cefaef;
extern int c2x_cec01c, c2x_d035d4, c2x_cefaf0, c2x_cefaf8, c2x_d1eac0, c2x_cefb00, c2x_cefb04, c2x_cefaf4, c2x_cec454,
	c2x_cf462c, c2x_caf134, c2x_d2a864;
extern unsigned c2x_caed20, c2x_cefa78, c2x_cef67c;
extern C2XMap c2x_cfd44c;
extern C2XPropLists c2x_d31640;
extern C2XMixer *c2x_cefa90;
extern Point c2x_d015d8[];
extern C2XSoundVec c2x_d2e9a0;
extern int c2x_d28c94[];
extern C2XLinkVec c2x_d2a86c;
extern Point c2x_d2a87c, c2x_d2a884;
extern char c2x_d2e20c[];
extern C2XSoundMgr c2x_d2d2a0;
extern C2XParts *c2x_cec088;
extern C2XMission *c2x_cec034;
extern C2XLocHandle c2x_d1e884, c2x_d1e888;
extern string c2x_d2d4d8, c2x_d1e864, c2x_d2d4ac, c2x_cfe140[];
extern C2XGameData c2x_d1e860;
extern C2XShooter c2x_d1d9c0;
extern C2XRecVec c2x_d25de0;
extern int c2x_bba058[];
extern C2XEvolveList c2x_d323c8;
extern unsigned char c2x_ba6650[][3];
extern C2XLog c2x_cf1080;
extern C2XBubble *c2x_cec058;
extern C2XLogMsgs *c2x_cec0b4;
extern C2XTurnQueue c2x_d225a0;

void c2x_eraseAt9da940(C2XHandleVec &v, int index);
void c2x_deleteAndStep9de820(C2XMoverVec &v, int &index);
bool c2x_containsEntity(C2XPropList &list, C2XPropHandle h);
void c2x_lookup2(const string &name, void *&out);
bool traceSubcellLine(const Point &a, const Point &b, vector<Point> &line, vector<int> &cells, int step);
void c2x_eraseAtLink(C2XLinkVec &v, unsigned &index);
int c2x_attenuation500500(C2XSound *s, Point &at, Point &listener);
void c2x_clampMin(int *v, int min);
bool c2x_showMessage5111e0(int id, const string *a, const string *b, const string *c, C2XEntityHandle d, C2XEntityHandle e, int f, int g);
void c2x_hackEnd954180(C2XEntityHandle h);
bool c2x_containsString(C2XStrVec &list, string s);
int c2x_findString(C2XStrVec &list, string s);
string &c2x_padRight4080d0(string &s, int width, char c);
void c2x_findNode470180(int type, int depth, C2XLocHandle from, C2XLocHandle *out);
void c2x_openEvolve(int a, C2XLocHandle loc, int b);
int c2x_findStringIndex(const string *list, unsigned n, string s);
C2XLocHandle c2x_randomRecord(C2XLocVec &list);
string c2x_randomString(C2XStrVec &list);
void opR4_spawnRandom(const string &name, int a, int b);
extern const char c2x_bf5884[], c2x_bf5898[], c2x_bf58ac[], c2x_bf58b4[], c2x_bf58c8[], c2x_bf58d0[], c2x_bf58d8[],
	c2x_bf58e4[], c2x_bf58e8[], c2x_bf58ec[], c2x_bf58f0[], c2x_bf58f4[], c2x_bf5908[], c2x_bf5920[], c2x_bf5924[],
	c2x_bf5928[], c2x_bf592c[];

void C2XBS::update774b70()
{
	if (c2x_cefc50->update())
		c2x_cec054->f49ad30();
	if (!expiring.empty())
	{
		for (int i = expiring.size() - 1; i >= 0; i--)
		{
			if (expiring[i]->expired())
			{
				if (watched == *(C2XEntityHandle *)&expiring[i])
					watched.reset9b7270();
				c2x_d20404.remove(*(C2XEntityHandle *)&expiring[i], true);
				c2x_eraseAt9da940(expiring, i);
			}
		}
	}
	if (c2x_cefb3e)
	{
		C2XPointTmp hover;
		hover.init453b40();
		if (c2x_cec054->f805190(hover))
			c2x_cec01c = c2x_cfd44c.getHeight() * hover.x + hover.y;
		else
			c2x_cec01c = -1;
	}
	if (!movers.empty())
	{
		for (unsigned m = 0; m < movers.size(); m++)
		{
			C2XMover *mover = movers[m];
			if (c2x_caed20 >= mover->last + mover->f24)
			{
				if (mover->count != c2x_d31640[mover->list].size())
				{
					c2x_cefa90->haltGroup(0x16);
				remove:
					c2x_deleteAndStep9de820(movers, (int &)m);
					break;
				}
				bool seen = false;
				C2XPropList &props = c2x_d31640[mover->list];
				int shift;
				vector<Point> targets;
				shift = mover->steps.front();
				mover->steps.erase(mover->steps.begin());
				for (unsigned j = 0; j < props.size(); j++)
				{
					targets.push_back(props[j]->pos4184d0());
					targets.back().add409a30(c2x_d015d8[shift]);
					if ((*c2x_cfd44c.atPoint(targets.back()))->getProp().isValid() && !c2x_containsEntity(props, (*c2x_cfd44c.atPoint(targets.back()))->getProp()))
						goto remove;
					if ((*c2x_cfd44c.atPoint(targets.back()))->getEntity().isValid())
						goto remove;
				}
				for (unsigned k = 0; k < props.size(); k++)
				{
					Point at = props[k]->pos4184d0();
					(*c2x_cfd44c.atPoint(at))->clear45df70();
					if (!seen && props[k]->info()->f68 != 0 && isVisible(at))
						seen = true;
				}
				for (unsigned n = 0; n < props.size(); n++)
				{
					if ((*c2x_cfd44c.atPoint(targets[n]))->getItem().isValid())
						(*c2x_cfd44c.atPoint(targets[n]))->getItem()->remove57dbe0(0, 0, 1, 1);
					(*c2x_cfd44c.atPoint(targets[n]))->place45df50(props[n]);
					props[n]->move45cc50(targets[n]);
					if (!seen && props[n]->info()->f68 != 0 && isVisible(targets[n]))
						seen = true;
				}
				if (seen)
					f72e8e0(0);
				if (mover->steps.empty())
					goto remove;
				if (mover->sound != 0x142)
				{
					mover->pos.add409a30(c2x_d015d8[shift]);
					C2XSound *sound = c2x_d2e9a0[mover->sound];
					if (!sound->channels.empty())
					{
						int v = c2x_attenuation500500(sound, mover->pos, player->getPosition());
						c2x_clampMin(&v, 1);
						int amount = c2x_d28dfd ? 100 : v;
						amount = amount * c2x_d28c94[sound->group] / 10;
						c2x_cefa90->setSoundVolume(sound->channels.front(), amount);
					}
				}
				mover->last = c2x_caed20;
			}
		}
	}
	if (!c2x_d2a86c.empty())
	{
		void *link;
		c2x_lookup2(c2x_bf5884, link);
		void *hl;
		c2x_lookup2(c2x_bf5898, hl);
		for (unsigned i = 0; i < c2x_d2a86c.size(); i++)
		{
			if (c2x_caed20 >= c2x_d2a86c[i]->fc)
			{
				if (c2x_d2a87c.test409bd0(*(Point *)c2x_d2a86c[i]))
				{
					vector<Point> path;
					vector<int> cells;
					traceSubcellLine(c2x_d2a87c, *(Point *)c2x_d2a86c[i], path, cells, 10);
					if (path.size() > 2)
					{
						for (unsigned j = 1; j < path.size() - 1; j++)
							c2x_cefc50->f508610(c2x_cefc50, link, path[j], c2x_d2e20c, 0, 0, 0, cells[j], 0)->init503b20();
					}
					path.clear();
					cells.clear();
					traceSubcellLine(*(Point *)c2x_d2a86c[i], c2x_d2a884, path, cells, 10);
					if (path.size() > 2)
					{
						for (unsigned k = 1; k < path.size() - 1; k++)
							c2x_cefc50->f508610(c2x_cefc50, link, path[k], c2x_d2e20c, 0, 0, 0, cells[k], 0)->init503b20();
					}
					c2x_cefc50->f508610(c2x_cefc50, hl, *(Point *)c2x_d2a86c[i], c2x_d2e20c, 0, 0, 0, 9, 0)->init503b20();
				}
				(*c2x_cfd44c.atPoint(*(Point *)c2x_d2a86c[i]))->f66d470(c2x_d2a864, c2x_d2a86c[i]->f8, 1, 0);
				c2x_eraseAtLink(c2x_d2a86c, i);
			}
		}
	}
	f732ce0(0);
	c2x_d2d2a0.f500010();
	if (timer > 0)
	{
		timer = c2x_cefa78 >= timer ? 0 : timer - c2x_cefa78;
		if (timer == 0 && watched.isValid())
		{
			(*(C2XWatchView *)&watched)->setState(2);
			watched.reset9b7270();
		}
	}
	switch (c2x_cf462c)
	{
	case 3:
	{
		const int base = 1200;
		const int cost = 2;
		if (drainTime == 0)
			drainTime = c2x_caed20;
		else
		{
			while (drainTime + base <= c2x_caed20)
			{
				drainTime += base;
				C2XItemVec parts;
				int prev;
				if (player->f5cb8b0(parts))
				{
					for (unsigned i = 0; i < parts.size(); i++)
					{
						prev = parts[i]->integrity();
						int ratio = parts[i]->drain457c80();
						int count = ratio / 100;
						if (ratio < 100)
						{
							if (rng.chance(ratio))
								count = 1;
						}
						else if (ratio % 100 != 0 && rng.chance(ratio % 100))
							count++;
						parts[i]->setIntegrity(parts[i]->integrity() - count);
						if (parts[i]->integrity() <= 0)
							parts[i]->setIntegrity(1);
						if (parts[i]->integrity() != prev)
						{
							C2XStatus *status = c2x_cec088->f894e70(parts[i]);
							if (status)
								status->drawStatus(false);
						}
					}
				}
				else if (player->getField490840() > cost)
					player->f5dea60(player->getField490840() - cost, 0);
			}
		}
		break;
	}
	}
	if (f71bb50())
		return;
	if (!player.operator->() || player->getField490840() == 0)
		state = 5;
	if (hacked.isValid())
	{
		if (hacked.operator->())
		{
			if (hacked->getTarget())
			{
				do
				{
					if (c2x_showMessage5111e0(0x1f2, 0, 0, 0, hacked, C2XEntityHandle(), 0, 0))
						c2x_cec058->bubble(1);
					c2x_cec0b4->scrollToEnd();
				} while (0);
			}
			else
			{
				do
				{
					if (c2x_showMessage5111e0(0x1f3, 0, 0, 0, hacked, C2XEntityHandle(), 0, 0))
						c2x_cec058->bubble(1);
					c2x_cec0b4->scrollToEnd();
				} while (0);
				c2x_hackEnd954180(hacked);
				state = 1;
			}
		}
		hacked.reset9b7270();
	}
	switch (state)
	{
	case 1:
		f734db0(C2XEntityHandle());
		if (c2x_cefaf0 != 0)
		{
			if (getTurn() >= c2x_cefaf0)
				c2x_cec034->start(C2XTimer(10));
			else
				f774390(0, -1);
		}
		else if (c2x_cefaf8 >= 1)
		{
			if (c2x_d1e888->location == 8)
			{
				if ((c2x_d1eac0 == 0 || c2x_d1eac0 == 1) && (c2x_d2d4d8.empty() || c2x_d2d4d8 != c2x_d1e864))
				{
					c2x_d2d4d8 = c2x_d1e864;
					C2XBox area(C2XPos(0x45, 1), 7, 4);
					C2XStrVec links;
					vector<int> cnt;
					for (int x = area.p1.x; x <= area.p2.x; x++)
					{
						for (int y = area.p1.y; y <= area.p2.y; y++)
						{
							if ((*c2x_cfd44c.at(x, y))->getItem().isValid() && (*c2x_cfd44c.at(x, y))->getItem()->getEffect(0x63))
							{
								if (c2x_containsString(links, (*c2x_cfd44c.at(x, y))->getItem()->record()->name))
									cnt[c2x_findString(links, (*c2x_cfd44c.at(x, y))->getItem()->record()->name)]++;
								else
								{
									links.push_back((*c2x_cfd44c.at(x, y))->getItem()->record()->name);
									cnt.push_back(1);
								}
							}
						}
					}
					int w = c2x_d035d4 + 2;
					int limit = string(c2x_bf58ac).size();
					string s;
					ofstream open((string() + c2x_bf58b4).c_str(), (c2x_cefafc ? 8 : 16) | 2);
					if (!c2x_cefafc)
					{
						s = c2x_bf58c8;
						open << c2x_padRight4080d0(s, w, ' ');
						open << c2x_bf58d0;
						open << c2x_bf58d8;
					}
					open << c2x_bf58e4;
					s = c2x_d1e864;
					open << c2x_padRight4080d0(s, w, ' ');
					s = c2x_bf58e8 + intToString(c2x_d1e888->depth);
					open << c2x_padRight4080d0(s, limit, ' ');
					for (unsigned i = 0; i < links.size(); i++)
					{
						if (i != 0)
							open << c2x_bf58ec;
						if (cnt[i] > 1)
							open << cnt[i] << c2x_bf58f0;
						open << links[i];
					}
					open.close();
					c2x_cefafc = true;
					if (--c2x_cefaf8 == 0)
					{
						c2x_cefafc = false;
						do
						{
							if (c2x_cf1080.push5121f0(new C2XPhrase(c2x_bf5908 + (string() + c2x_bf58f4), 0, 0, 0, C2XEntityHandle(), C2XEntityHandle())))
								c2x_cec058->bubble(1);
							c2x_cec0b4->scrollToEnd();
						} while (0);
						break;
					}
				}
				c2x_cec034->f988ad0(0);
			}
			else
			{
				C2XLocHandle node;
				c2x_findNode470180(8, -1, c2x_d1e884, &node);
				((C2XPropHandle *)&node)->isNull();
				if (0) {}
				c2x_openEvolve(0, node, 0);
			}
		}
		else if (c2x_cefb00 >= 1)
		{
		}
		else if (c2x_cefb04 >= 1)
		{
		}
		else if (c2x_cefaee || c2x_cefb09)
		{
			if (c2x_cefb09)
			{
				f726840(C2XBox(0, 0, c2x_cfd44c.getWidth() - 1, c2x_cfd44c.getHeight() - 1), 0);
				string name = c2x_d1e864 + c2x_bf5920;
				name += intToString(c2x_d1e860.f46f4e0());
				name += c2x_bf5924;
				name += c2x_cfe140[c2x_d1e888->location];
				name += c2x_d1e888->depth >= 10 ? string(c2x_bf5928) : intToString(c2x_d1e888->depth);
				int level = c2x_d1e860.f789090();
				if (level >= 2)
					name += c2x_bf592c + intToString(level);
				c2x_d1d9c0.saveMapScreenshot873ba0(name);
			}
			if (c2x_cefaef)
			{
				if (c2x_cefaf4 > 0 && c2x_d1e888->depth <= 5)
				{
					if (c2x_cec454 == 0)
					{
						if (c2x_cf462c != 6)
						{
							while (1)
							{
								Point start = c2x_cfd44c.getRandom9cf050();
								C2XBox around;
								c2x_cfd44c.getRect(start, 2, around);
								for (int x = around.p1.x; x <= around.p2.x; x++)
								{
									for (int y = around.p1.y; y <= around.p2.y; y++)
									{
										if ((*c2x_cfd44c.at(x, y))->terrain() != TERRAIN_EARTH && (*c2x_cfd44c.at(x, y))->terrain() != TERRAIN_CAVE_WALL)
											goto retry;
									}
								}
								player->changePos(start, true);
								break;
							retry:;
							}
							int traps = c2x_d1e860.f46f4b0(1) ? 30 : 100;
							int items = c2x_d1e860.f46f4b0(1) ? 100 : 30;
							C2XStrVec trapNames;
							C2XStrVec kind;
							for (unsigned r = 0; r < c2x_d25de0.size(); r++)
							{
								if (c2x_d25de0[r]->f68 <= c2x_d1e888->f46ed20() && c2x_bba058[c2x_d25de0[r]->f28] >= 6)
								{
									if ((c2x_d25de0[r]->f24 == 1 || c2x_d25de0[r]->f24 == 2) && (c2x_cf462c != 4 || (c2x_d25de0[r]->f28 != 0x48 && c2x_d25de0[r]->f28 != 0x47)))
										trapNames.push_back(c2x_d25de0[r]->name);
									else if (c2x_d25de0[r]->f24 == 3)
										kind.push_back(c2x_d25de0[r]->name);
								}
							}
							for (int t = 0; t < traps; t++)
								opR4_spawnRandom(c2x_randomString(trapNames), 1, 3);
							for (int u = 0; u < items; u++)
								opR4_spawnRandom(c2x_randomString(kind), 1, 5);
						}
						else
						{
							player->changePos(C2XPos(0x5d, 0x5d), true);
							for (int x = 0x5c; x <= 0x5e; x++)
								for (int y = 0x5c; y <= 0x5e; y++)
									if (x != 0x5d || y != 0x5d)
										(*c2x_cfd44c.at(x, y))->f66a050(*caveinThirdTerrain, 2, 0);
						}
					}
					if (c2x_cec454 < c2x_cefaf4)
					{
						c2x_cec454++;
						f774390(0, -1);
						break;
					}
					else
						c2x_cec454 = 0;
				}
				if (c2x_cef67c >= c2x_d323c8.size() || c2x_cf462c == 6)
					c2x_cec034->f988ad0(0);
				else
				{
					c2x_openEvolve(0, c2x_d323c8[c2x_cef67c], 0);
					c2x_cef67c++;
				}
			}
			else if (!c2x_d2d4ac.empty())
			{
				int index = c2x_findStringIndex(c2x_cfe140, 0x26, c2x_d2d4ac);
				if (index == c2x_d1e888->location && (c2x_caf134 == -1 || c2x_d1e888->depth == c2x_caf134))
					c2x_cec034->f988ad0(0);
				else
				{
					C2XLocHandle node;
					c2x_findNode470180(index, c2x_caf134, c2x_d1e884, &node);
					((C2XPropHandle *)&node)->isNull();
					if (0) {}
					c2x_openEvolve(0, node, 0);
				}
			}
			else if (c2x_d1e888->location == 5)
			{
				if (c2x_cefb09)
					exit(0);
				c2x_cec034->f988ad0(0);
			}
			else
			{
				C2XLocVec exits;
				for (unsigned e = 0; e < c2x_d1e888->exits.size(); e++)
				{
					if (!c2x_ba6650[((C2XLocHandle &)c2x_d1e888->exits[e])->location][0])
						exits.push_back((C2XLocHandle &)c2x_d1e888->exits[e]);
				}
				c2x_openEvolve(0, c2x_randomRecord(exits), 0);
			}
		}
		break;
	case 2:
		do
		{
			c2x_d225a0.f672700();
			if (!player.operator->() || player->getField490840() == 0)
				state = 5;
		} while (state == 2 && !f71bb50());
		break;
		break;
	case 4:
		f777190(0x1c);
		break;
	case 5:
		if (c2x_cefaef && c2x_cefaf4)
			c2x_cec034->f988ad0(0);
		else
			gameOver();
		break;
	}
}
