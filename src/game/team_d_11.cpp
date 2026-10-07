// team_d_11: constructor of the object created by OpU5s2_Factory::createD (0x571590).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
#include <string>
using namespace std;

struct Point
{
	int x;
	int y;

	Point();
	Point(const Point &p) throw();
	void set(int v);	// 0x409ff0
};

class HProp
{
	int	ID;
public:
	HProp();
	void resetField();	// NOTE: placeholder name (0x9b7270)
};

class PlayerData	// NOTE: placeholder name (0xcf45d8)
{
public:
	int nextId();	// NOTE: placeholder name (0x46de70)
};
extern PlayerData playerData_cf45d8;	// NOTE: placeholder name

class GameData
{
public:
	int unknown789250(int value);	// NOTE: placeholder name
};
extern GameData gameData_d1e860;	// NOTE: placeholder name

class RNG
{
public:
	bool chance(int percent);
};
extern RNG rng;

extern int difficulty_cf4718;		// NOTE: placeholder name
extern float multipliers_ba65d8[];	// NOTE: placeholder name

struct ObjDDef	// NOTE: placeholder name
{
	char pad00[0x48];
	int unknown48;		// NOTE: placeholder name
	char pad4c[0x64 - 0x4c];
	int unknown64;		// NOTE: placeholder name
	char pad68[0x98 - 0x68];
	int unknown98;		// NOTE: placeholder name
	char pad9c[0xa8 - 0x9c];
	int unknowna8;		// NOTE: placeholder name
	char padac[0xf0 - 0xac];
	int unknownf0;		// NOTE: placeholder name
	int unknownf4;		// NOTE: placeholder name
	char padf8[0x1d0 - 0xf8];
	vector<Point *> points;	// +0x1d0, NOTE: placeholder name
};

struct OpD_ObjD	// NOTE: placeholder name (created by OpU5s2_Factory::createD)
{
	OpD_ObjD(ObjDDef *def_);

	int		id;				// NOTE: placeholder name
	HProp	unknown04;		// NOTE: placeholder name
	ObjDDef	*def;			// NOTE: placeholder name
	int		unknown0c;		// NOTE: placeholder name
	HProp	unknown10;		// NOTE: placeholder name
	Point	unknown14;		// NOTE: placeholder name
	int		unknown1c;		// NOTE: placeholder name
	bool	unknown20;		// NOTE: placeholder name
	int		unknown24;		// NOTE: placeholder name
	int		unknown28;		// NOTE: placeholder name
	int		unknown2c;		// NOTE: placeholder name
	int		unknown30;		// NOTE: placeholder name
	int		unknown34;		// NOTE: placeholder name
	int		unknown38;		// NOTE: placeholder name
	int		unknown3c;		// NOTE: placeholder name
	bool	unknown40;		// NOTE: placeholder name
	int		unknown44;		// NOTE: placeholder name
	vector<Point *> points;	// NOTE: placeholder name
	int		unknown58;		// NOTE: placeholder name
	string	unknown5c;		// NOTE: placeholder name
};

OpD_ObjD::OpD_ObjD(ObjDDef *def_)
{
	id = playerData_cf45d8.nextId();
	unknown04.resetField();
	def = def_;
	unknown0c = 10;
	unknown10.resetField();
	unknown14.set(0);
	unknown1c = def->unknowna8;
	unknown20 = def->unknown98 ? rng.chance(def->unknown98) : false;
	unknown24 = 0;
	unknown28 = -1;
	unknown2c = 0;
	unknown30 = 0;
	unknown34 = 0;
	unknown38 = 0;
	unknown3c = 0;
	unknown40 = false;
	unknown44 = 0;
	switch (def->unknownf0)
	{
		case 0xd0:
			unknown44 = -1;
			break;
		case 0xa7:
			unknown44 = def->unknownf4;
			break;
		case 0x7c:
			unknown44 = gameData_d1e860.unknown789250((int)(def->unknown64 * multipliers_ba65d8[difficulty_cf4718]));
			break;
	}
	for (unsigned int i = 0; i < def->points.size(); i++)
		points.push_back(new Point(*def->points[i]));
	if (def->unknown48 == 0)
		unknown44 = -1;
	unknown58 = 0;
}
