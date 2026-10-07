// team_b_28: map screenshot export (0x873ba0) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
using namespace std;
struct Point { int x; int y; Point(const Point &p); };
struct Pos { int x; int y; Pos(int x_, int y_); };
struct Rect { int x; int y; int width; int height; Rect(int x_, int y_, int width_, int height_); };
class HProp { public: int ID; HProp(); };
class TeamB_ShotEntity { public: const Point &getPosition(); };	// NOTE: placeholder name (Entity)
class TeamB_HShotEntity { public: int ID; TeamB_ShotEntity *operator->() const; };	// NOTE: placeholder name (HEntity)
class TeamB_ShotWorld { public: TeamB_HShotEntity getPlayer(); };	// NOTE: placeholder name (Map)
extern TeamB_ShotWorld *teamb_shotWorld_cefc4c;	// NOTE: placeholder name
class XConsole
{
public:
	virtual ~XConsole();
	virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18();
	virtual void render_1c();	// NOTE: placeholder name
	int getHeight();
	int getWidth_44b0d0();	// NOTE: placeholder name
	void unknown429fe0(XConsole *console, const Pos &pos, const Rect &rect) throw();	// NOTE: placeholder name
};
class Console : public XConsole { public: Console(XConsole *parent, int x, int y, int width, int height, int font, bool hidden, int layer); char pad[0x6c - 4]; };
class XRoot : public XConsole { public: XRoot(int width, int height, bool flag); void composite(); void saveScreenshot(string filename); char pad[0x84 - 4]; };
class TeamB_ShotMapView : public XConsole { public: void unknown49ac30(const Pos &offset); void unknown8069e0(Point p, bool flag); };	// NOTE: placeholder name (CMap)
extern TeamB_ShotMapView *teamb_shotMapView_cec054;	// NOTE: placeholder name
class TeamB_ShotRex { public: XConsole *getRoot_4ab670(); void setRoot_418dc0(XConsole *root); };	// NOTE: placeholder name
extern TeamB_ShotRex teamb_shotRex_d223f0;	// NOTE: placeholder name
class TeamB_ShotGrid { public: int getWidth(); int getHeight(); };	// NOTE: placeholder name
extern TeamB_ShotGrid teamb_shotGrid_cfd44c;	// NOTE: placeholder name
class TeamB_ResourceMgr { public: bool fileExists(string path); };	// NOTE: placeholder name (XResourceMgr)
extern TeamB_ResourceMgr *teamb_resourceMgr_cefa88;	// NOTE: placeholder name
void OpQ1_createDirectories(string path);
void opX4e_toggleMapFont_7f46e0();
int OpX5_minInt(int a, int b);
extern string teamb_baseDir_cfd42c;	// NOTE: placeholder name
extern bool opx5b_asciiEnabled;	// NOTE: placeholder name (0xd28d15)
extern int teamb_cellWidth_caf128;	// NOTE: placeholder name
extern int teamb_cellHeight_caf12c;	// NOTE: placeholder name
extern bool teamb_deleting_cefa76;	// NOTE: placeholder name
void teamb_msg873_7b1750(int type, const string &a, const string *b, const string *c, HProp e, HProp p, int d);	// NOTE: placeholder name (0x7b1750)
class TeamB_MapShooter	// NOTE: placeholder name
{
public:
	char pad[0xb0];
	bool busy;
	void saveMapScreenshot873ba0(string filename);
};
void TeamB_MapShooter::saveMapScreenshot873ba0(string filename)	// 0x873ba0 (local names follow docs/local-name-buckets.txt)
{
	busy = true;
	string path = teamb_baseDir_cfd42c + "screenshots-maps/";
	if (!teamb_resourceMgr_cefa88->fileExists(path))
		OpQ1_createDirectories(path);
	path += filename;
	bool visible = opx5b_asciiEnabled;
	if (visible)
		opX4e_toggleMapFont_7f46e0();
	XRoot *root = new XRoot(teamb_shotGrid_cfd44c.getWidth() * teamb_cellWidth_caf128,teamb_shotGrid_cfd44c.getHeight() * teamb_cellHeight_caf12c,true);
	XConsole *source = teamb_shotRex_d223f0.getRoot_4ab670();
	teamb_shotRex_d223f0.setRoot_418dc0(root);
	Console *child = new Console(root,teamb_shotGrid_cfd44c.getWidth(),teamb_shotGrid_cfd44c.getHeight(),0,0,2,false,-1);
	Rect size(0,0,0,0);
	int w = teamb_shotMapView_cec054->getWidth_44b0d0();
	int h = teamb_shotMapView_cec054->getHeight();
	for (int x = 0; x < teamb_shotGrid_cfd44c.getWidth(); x += w)
	{
		size.width = OpX5_minInt(teamb_shotGrid_cfd44c.getWidth() - x,w);
		for (int y = 0; y < teamb_shotGrid_cfd44c.getHeight(); y += h)
		{
			teamb_shotMapView_cec054->unknown49ac30(Pos(-x,-y));
			teamb_shotMapView_cec054->render_1c();
			size.height = OpX5_minInt(teamb_shotGrid_cfd44c.getHeight() - y,h);
			teamb_shotMapView_cec054->unknown429fe0(child,Pos(x,y),size);
		}
	}
	root->composite();
	root->saveScreenshot(path);
	teamb_deleting_cefa76 = true;
	delete root;
	teamb_deleting_cefa76 = false;
	root = NULL;
	teamb_shotRex_d223f0.setRoot_418dc0(source);
	teamb_shotMapView_cec054->unknown8069e0(teamb_shotWorld_cefc4c->getPlayer()->getPosition(),false);
	if (visible)
		opX4e_toggleMapFont_7f46e0();
	teamb_msg873_7b1750(0xce,path,0,0,HProp(),HProp(),0);
	busy = false;
}
