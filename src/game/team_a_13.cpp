// team_a_13: engine particle item ctor/dtor (0x454a80/0x454b30) and Engine destructor (0x454ca0).
// NOTE: class layouts are partial; names are placeholders except Engine and Bresenham2DStepperSubcell (RTTI).
#include <vector>
#include "pathing/bresenham2d.h"
using namespace std;

class Push_453b40	// NOTE: placeholder name (8-byte value type, constructor 0x453b40)
{
public:
	int a;
	int b;
	Push_453b40() throw();
};

class EngineItem_454a80	// NOTE: placeholder name (allocated by Engine::unknown50fb50)
{
public:
	int unknown0;
	int unknown4;
	int unknown8;
	int padC;
	Push_453b40 unknown10;
	Push_453b40 unknown18;
	Push_453b40 unknown20;
	Push_453b40 unknown28;
	char pad30[0x38 - 0x30];
	Bresenham2DStepperSubcell stepper;
	Push_453b40 unknown68;
	Push_453b40 unknown70;
	char pad78[0x84 - 0x78];
	vector<Point> unknown84;
	vector<unsigned int> unknown94;
	vector<unsigned int> unknownA4;
	EngineItem_454a80();
	~EngineItem_454a80();
};

EngineItem_454a80::EngineItem_454a80()
	: unknown0(0), unknown4(0), unknown8(0)
{
}

EngineItem_454a80::~EngineItem_454a80()
{
}

struct OpQ5_T9cfb70;
template <class T> void OpQ5_deleteObjects(vector<T*> &v);	// NOTE: placeholder name

class OpR1b_NoiseField	// NOTE: placeholder name (layout as in op_r1b.cpp)
{
public:
	OpR1b_NoiseField() throw();	// 0x421650
	~OpR1b_NoiseField();	// 0x421750
	void init(int dimensions, float scale, int seed_);	// 0x421680

	int				dimensions;
	void			*noise;
	float			offset;
	float			scale;
	int				seed;
	unsigned int	startTick;
	float			*coords;
	int				octaves;
};

class Engine
{
public:
	char pad0[0x14];
	vector<OpQ5_T9cfb70 *> unknown14;
	vector<OpQ5_T9cfb70 *> unknown24;
	OpR1b_NoiseField noise;
	~Engine();
};

Engine::~Engine()
{
	OpQ5_deleteObjects(unknown14);
	OpQ5_deleteObjects(unknown24);
}
