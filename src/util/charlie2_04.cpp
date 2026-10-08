// Squad spawn (0x73e5c0, called from BS turn updates): builds the candidate squad table for the current
// level, drops squads already used (global name list at 0xd1eb78), then spawns up to min(level/10+1, 2)
// weighted picks near the player and returns how many names were appended to `used`.
// NOTE: placeholder names and layouts throughout (C2S*).
#include <string>
#include <vector>
using namespace std;

struct C2SPoint	// NOTE: placeholder (Point)
{
	int x, y;
	C2SPoint(int v);
	C2SPoint(const C2SPoint &o);
	C2SPoint &operator=(const C2SPoint &o);
	int distanceCeil();
};
struct C2SArea { int f0, f1, f2, f3; C2SArea(); C2SArea(const C2SArea &o); C2SPoint randomPoint40be90(); };
struct C2SRect { int f0, f1, f2, f3; };
struct C2SAI { void delegate459470(C2SRect &area); void setFollowEntity(int leader, int flag); };
struct C2SEntity { C2SPoint &getPosition(); C2SAI *ai45b590(); };
struct C2SHandle	// NOTE: placeholder (HEntity)
{
	int id;
	C2SHandle();
	bool isValid() const;
	C2SEntity *operator->() const;
};
struct C2SWeighted	// NOTE: placeholder (weighted int list)
{
	int f0, f1, f2, f3, f4, f5, f6, f7, f8;
	C2SWeighted(vector<int> &weights);
	~C2SWeighted();
	int &pick();
	void remove(int index);
};
struct C2SMap { void getArea(C2SRect *out); };
struct C2SCartographer { bool findPath(const C2SPoint &from, const C2SPoint &to, void *cost, void *data, vector<C2SPoint> &path); };

class C2BS	// NOTE: placeholder layout (BS)
{
public:
	char p000[0x66c];
	C2SHandle player;	// +0x66c
	char p670[0x8b4 - 0x670];
	char areas[0x10];	// +0x8b4
	C2SHandle spawn6c5dc0(const string &name, const C2SPoint &pos, int a, int b, int c, int d, int e);
	int spawnSquads73e5c0(C2SPoint *pos, vector<string> *used);
};

extern int c2s_d1eb68;
extern vector<string> c2s_d1eb78;
extern void *c2s_cefc30;
extern C2SMap c2s_cfd44c;
extern C2SCartographer c2s_cfe568;
int c2s_findString(vector<string> &list, string s);
void c2s_eraseSquad(vector<vector<string> > &v, int index);
void c2s_removeInt(vector<int> &v, int index);
void c2s_eraseName(vector<string> &v, int index);
C2SArea c2s_randomArea(void *areas);
int c2s_distanceCeil(const C2SPoint &a, const C2SPoint &b);
int c2s_minInt(int a, int b);
extern const char c2s_bf1b38[], c2s_bf1b44[], c2s_bf1b54[], c2s_bf1b60[], c2s_bf1b6c[], c2s_bf1b74[], c2s_bf1b7c[], c2s_bf1b90[], c2s_bf1b98[], c2s_bf1ba8[], c2s_bf1bb0[], c2s_bf1bbc[], c2s_bf1bc8[], c2s_bf1bdc[], c2s_bf1be8[], c2s_bf1bf4[], c2s_bf1c00[], c2s_bf1c0c[], c2s_bf1c18[], c2s_bf1c28[], c2s_bf1c34[], c2s_bf1c44[], c2s_bf1c50[], c2s_bf1c60[], c2s_bf1c6c[], c2s_bf1c78[], c2s_bf1c84[], c2s_bf1c9c[], c2s_bf1ca8[], c2s_bf1cb4[], c2s_bf1cbc[], c2s_bf1cdc[], c2s_bf1ce4[], c2s_bf1d00[], c2s_bf1d08[], c2s_bf1d18[], c2s_bf1d20[], c2s_bf1d30[], c2s_bf1d3c[], c2s_bf1d4c[], c2s_bf1d58[], c2s_bf1d60[], c2s_bf1d6c[], c2s_bf1d78[], c2s_bf1d8c[], c2s_bf1d94[], c2s_bf1d9c[], c2s_bf1da8[], c2s_bf1db4[];

int C2BS::spawnSquads73e5c0(C2SPoint *pos, vector<string> *used)
{
	if (c2s_d1eb68 <= 0)
		return 0;
	vector<vector<string> > events;
	vector<int> table;
	vector<string> label;
	int level = c2s_d1eb68;
	if (level >= 1)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 3, c2s_bf1b38);
		table.push_back(5);
		label.push_back(c2s_bf1b44);
		events.back().insert(events.back().end(), 3, c2s_bf1b54);
	}
	if (level >= 1)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 6, c2s_bf1b60);
		table.push_back(5);
		label.push_back(c2s_bf1b6c);
	}
	if (level >= 1)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 6, c2s_bf1b74);
		table.push_back(5);
		label.push_back(c2s_bf1b7c);
	}
	if (level >= 1)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 6, c2s_bf1b90);
		table.push_back(5);
		label.push_back(c2s_bf1b98);
	}
	if (level >= 5)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 10, c2s_bf1ba8);
		table.push_back(25);
		label.push_back(c2s_bf1bb0);
	}
	if (level >= 5)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 10, c2s_bf1bbc);
		table.push_back(25);
		label.push_back(c2s_bf1bc8);
	}
	if (level >= 5)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 5, c2s_bf1bdc);
		table.push_back(25);
		label.push_back(c2s_bf1be8);
	}
	if (level >= 5)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 5, c2s_bf1bf4);
		table.push_back(25);
		label.push_back(c2s_bf1c00);
	}
	if (level >= 5)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 4, c2s_bf1c0c);
		table.push_back(25);
		label.push_back(c2s_bf1c18);
	}
	if (level >= 10)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 7, c2s_bf1c28);
		table.push_back(50);
		label.push_back(c2s_bf1c34);
	}
	if (level >= 10)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 6, c2s_bf1c44);
		table.push_back(50);
		label.push_back(c2s_bf1c50);
	}
	if (level >= 10)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 5, c2s_bf1c60);
		table.push_back(50);
		label.push_back(c2s_bf1c6c);
	}
	if (level >= 10)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 5, c2s_bf1c78);
		table.push_back(50);
		label.push_back(c2s_bf1c84);
	}
	if (level >= 10)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 3, c2s_bf1c9c);
		table.push_back(50);
		label.push_back(c2s_bf1ca8);
	}
	if (level >= 20)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 5, c2s_bf1cb4);
		table.push_back(200);
		label.push_back(c2s_bf1cbc);
	}
	if (level >= 20)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 3, c2s_bf1cdc);
		table.push_back(200);
		label.push_back(c2s_bf1ce4);
	}
	if (level >= 20)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 3, c2s_bf1d00);
		table.push_back(200);
		label.push_back(c2s_bf1d08);
	}
	if (level >= 20)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 3, c2s_bf1d18);
		table.push_back(200);
		label.push_back(c2s_bf1d20);
	}
	if (level >= 30)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 2, c2s_bf1d30);
		table.push_back(300);
		label.push_back(c2s_bf1d3c);
		events.back().insert(events.back().end(), 4, c2s_bf1d4c);
		events.back().insert(events.back().end(), 4, c2s_bf1d58);
		events.back().insert(events.back().end(), 2, c2s_bf1d60);
	}
	if (level >= 30)
	{
		events.push_back(vector<string>());
		events.back().insert(events.back().end(), 1, c2s_bf1d6c);
		table.push_back(300);
		label.push_back(c2s_bf1d78);
		events.back().insert(events.back().end(), 2, c2s_bf1d8c);
		events.back().insert(events.back().end(), 2, c2s_bf1d94);
		events.back().insert(events.back().end(), 2, c2s_bf1d9c);
		events.back().insert(events.back().end(), 2, c2s_bf1da8);
		events.back().insert(events.back().end(), 1, c2s_bf1db4);
	}

	for (unsigned i = 0; i < c2s_d1eb78.size(); i++)
	{
		int index = c2s_findString(label, c2s_d1eb78[i]);
		if (index != -1)
		{
			c2s_eraseSquad(events, index);
			c2s_removeInt(table, index);
			c2s_eraseName(label, index);
		}
	}
	C2SPoint target(-1);
	if (pos)
		target = *pos;
	else
	{
		const int minDistance = 25;
		C2SPoint point = c2s_randomArea(areas).randomPoint40be90();
		C2SPoint origin = player->getPosition();
		if (c2s_distanceCeil(origin, point) > 30)
		{
			vector<C2SPoint> path;
			if (c2s_cfe568.findPath(origin, point, c2s_cefc30, 0, path))
			{
				for (unsigned k = 25; k < path.size(); k += 3)
				{
					if (c2s_distanceCeil(path[k], origin) >= 25)
					{
						target = path[k];
						break;
					}
				}
			}
		}
		if (target.x == -1)
			target = point;
	}
	if (table.empty())
		return 0;
	C2SWeighted chosen(table);
	int total = c2s_minInt(c2s_d1eb68 / 10 + 1, 2);
	C2SRect room;
	c2s_cfd44c.getArea(&room);
	C2SHandle entity;
	for (int i = 0; i < total; i++)
	{
		int index = chosen.pick();
		vector<string> &group = events[index];
		used->push_back(label[index]);
		c2s_d1eb78.push_back(label[index]);
		chosen.remove(index);
		for (unsigned j = 0; j < group.size(); j++)
		{
			entity = spawn6c5dc0(group[j], target, 9, 0, 0x22, 0xe, 0);
			if (entity.isValid())
			{
				entity->ai45b590()->delegate459470(room);
				entity->ai45b590()->setFollowEntity(player.id, 0);
			}
		}
	}
	return used->size();
}
