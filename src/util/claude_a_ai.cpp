// claude_a: EntityAI::~EntityAI 0x580900 (called from the scalar deleting dtor 0x45b5b0).
// NOTE: placeholder layout (only the members the destructor touches; offsets from the exe)
#include <vector>
using namespace std;

struct Pos { int x; int y; };

class HExplosive
{
	int ID;
public:
	HExplosive();
};

struct OpV4d_Trivial;
void OpV4d_deleteMapRecords(vector<OpV4d_Trivial *> &records);	// NOTE: placeholder name (op_v4d.cpp)

struct OpQ5_T9d8e70;
template <class T> void OpQ5_deleteObjects(vector<T*> &v);	// NOTE: placeholder name (op_q5_ser.cpp)

class AIOrder	// NOTE: placeholder name (scalar deleting dtor 0x580a40)
{
public:
	~AIOrder();
};

class EntityPart4588f0	// NOTE: placeholder name (scalar deleting dtor 0x459670)
{
public:
	~EntityPart4588f0();
};

class EntityAI
{
public:
	char pad0[0x24];
	vector<Pos> line;						// +0x24
	char pad34[0x6c - 0x34];
	vector<Pos> path;						// +0x6c
	char pad7c[0x90 - 0x7c];
	vector<Pos> candidates;					// +0x90
	char padA0[0xdc - 0xa0];
	vector<HExplosive> remembered;			// +0xdc
	int rememberedTurn;						// +0xec
	vector<OpV4d_Trivial *> targets;		// +0xf0
	char pad100[0x114 - 0x100];
	AIOrder *order;							// +0x114
	char *unknown118;						// +0x118 NOTE: placeholder name
	EntityPart4588f0 *part;					// +0x11c
	vector<OpQ5_T9d8e70 *> objects;			// +0x120 NOTE: placeholder name

	~EntityAI();
};

EntityAI::~EntityAI()
{
	OpV4d_deleteMapRecords(targets);
	delete order;
	delete unknown118;
	delete part;
	OpQ5_deleteObjects(objects);
}
