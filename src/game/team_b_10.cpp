// team_b_10: Zionmind::spawnDispatchItems matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; TeamB_* classes and unknownXXXXXX members are placeholder names.
#include <vector>
#include <istream>
#include <algorithm>
#include <string>
using namespace std;
template <class T> void OpS3e_eraseAt(vector<T> &v, int index);	// NOTE: placeholder name (0x9da940)
template <class T> void OpS3e_moveElement(vector<T> &v, int from, int to);	// NOTE: placeholder name (0x9da1f0)
class OpS3e_TurnSlot;
class HTurnClock	// NOTE: placeholder name (same declaration as src/op/op_s3_e.cpp)
{
	int	ID;
public:
	HTurnClock() throw();
	OpS3e_TurnSlot *operator->() const;	// 0x9b73b0
};
class OpS3e_TurnSlot
{
public:
	HTurnClock	handle;
	int			time;
	int			type;
	void		*data;
	void setHandle(HTurnClock h);	// NOTE: placeholder name
};
bool OpS1e_isClockEarlier(const HTurnClock &a, const HTurnClock &b);	// NOTE: placeholder name (0x45e6c0)
struct OpS3e_ClockPool { HTurnClock add(OpS3e_TurnSlot *slot); };
extern OpS3e_ClockPool opS3e_clockPool;	// NOTE: placeholder name (0xd208d4)

// NOTE: the turn-queue functions (0x672310/0x672450/0x672580) are matched in src/op/op_s3_e.cpp.

//==================================================================
// Zionmind
//==================================================================

void logError(string location, string message);
struct Point { int x; int y; };	// NOTE: placeholder layout
class HItem { public: int ID; HItem(); bool isNull() const; };
struct ItemType { char pad[8]; string name; };	// NOTE: placeholder layout
struct TeamB_DispatchInfo { int type; char pad[0x1c]; int count; };	// NOTE: placeholder layout
extern string gameStrings_d29af8[];	// NOTE: placeholder name
class BS { public: HItem unknown6c5400(ItemType *type, const Point &p); };
extern BS *teamb_world;
class Zionmind
{
public:
	void spawnDispatchItems(const Point &pos, ItemType *type, TeamB_DispatchInfo *info, vector<HItem> &items);
};
void Zionmind::spawnDispatchItems(const Point &pos, ItemType *type, TeamB_DispatchInfo *info, vector<HItem> &items)
{
	HItem item;
	items.clear();
	for (int i = 0; i < info->count; i++)
	{
		item = teamb_world->unknown6c5400(type,pos);
		if (item.isNull())
		{
			logError("Zionmind::spawnDispatchItems()","Could not place " + type->name + " for " + gameStrings_d29af8[info->type]);
			return;
		}
		items.push_back(item);
	}
}
