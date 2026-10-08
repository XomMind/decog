// team_b_31: CMap entity info labels (0x81a340) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
#include <string>
#include <vector>
using namespace std;
string intToString(int value);
struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	XColor(const XColor &color);	// 0x411e30
};
struct Point
{
	int x;
	int y;
	Point(int x_, int y_);
	Point add_409b60(const Point &p) const;	// NOTE: placeholder name (PushCoord::add)
};
class XConsole
{
public:
	virtual ~XConsole();
	void setFore(XColor color);
	void setBgColor(XColor color);
	void print(int x, int y, const string &text);
};
class Console : public XConsole { public: Console(XConsole *parent, int x, int y, int width, int height, int font, bool hidden, int layer); char pad[0x6c - 4]; };
class TeamB_InfoItem { public: string getName_571db0(int a, int b); };	// NOTE: placeholder name (Item)
class HItem { public: int ID; TeamB_InfoItem *operator->() const; };
class TeamB_InfoEntity	// NOTE: placeholder name (Entity)
{
public:
	string &getName_416f40();	// NOTE: placeholder name
	int unknown5ca670();	// NOTE: placeholder name
	int unknown5ca400();	// NOTE: placeholder name
	void unknown5d6c30(vector<HItem> *items);	// NOTE: placeholder name
	const Point &getPosition();
};
class HEntity { public: int ID; TeamB_InfoEntity *operator->() const; };
extern unsigned int teamb_tickCount;	// NOTE: placeholder name (0xcaed20)
extern XColor *teamb_color_d35be0;	// NOTE: placeholder name
extern XColor *teamb_color_cf44c0;	// NOTE: placeholder name
class TeamB_CMapInfo : public XConsole	// NOTE: placeholder name (CMap)
{
public:
	char pad04[0x6c - 4];
	Point offset;
	char pad74[0x7b0 - 0x74];
	vector<XConsole *> labels;
	vector<Point> positions;
	vector<Point> offsets;
	vector<unsigned int> times;
	void showInfo81a340(HEntity entity);
};
void TeamB_CMapInfo::showInfo81a340(HEntity entity)	// 0x81a340 (local names follow docs/local-name-buckets.txt)
{
	vector<string> buffer;
	buffer.push_back(entity->getName_416f40());
	buffer.push_back("Matter: " + intToString(entity->unknown5ca670()));
	buffer.push_back("Energy: " + intToString(entity->unknown5ca400()));
	vector<HItem> items;
	entity->unknown5d6c30(&items);
	if (!items.empty())
	{
		for (unsigned int i = 0; i < items.size(); i++)
			buffer.push_back("+" + items[i]->getName_571db0(0,0));
	}
	for (unsigned int j = 0; j < buffer.size(); j++)
	{
		buffer[j].insert(buffer[j].begin(),' ');
		buffer[j] += " ";
	}
	for (unsigned int k = 0, y = 0; k < buffer.size(); k++, y++)
	{
		positions.push_back(entity->getPosition());
		offsets.push_back(Point(1,y));
		times.push_back(teamb_tickCount + 5000);
		Point pos = positions.back().add_409b60(offsets.back()).add_409b60(offset);
		labels.push_back(new Console(this,buffer[k].size(),1,pos.x,pos.y,0,false,0x14));
		labels.back()->setFore(*teamb_color_d35be0);
		labels.back()->print(0,0,buffer[k]);
		labels.back()->setBgColor(*teamb_color_cf44c0);
	}
}
