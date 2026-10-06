// op_x2: misc functions in [0x409000,0x581000) matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; member and method names are placeholders unless stated otherwise.
#include <algorithm>
using namespace std;

bool OpT8b_Fn9daf80(int a, int b, int c);	// NOTE: placeholder name (0x9daf80)
extern bool opS1d_flagd28e74;	// NOTE: placeholder name (0xd28e74)

struct OpX2_C4611c0	// NOTE: placeholder name
{
	int first;
	int second;

	void swapOrShift();	// NOTE: placeholder name
};

void OpX2_C4611c0::swapOrShift()
{
	if (OpT8b_Fn9daf80(0x80,first,0xae) && !opS1d_flagd28e74)
		first += 0x34;
	else if (OpT8b_Fn9daf80(0xb4,first,0xe2) && !opS1d_flagd28e74)
		first -= 0x34;
	else
		swap(first,second);
}

//==================================================================
// 0x461250
//==================================================================

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor(const XColor &color) throw();
	bool operator==(XColor color);
};

struct OpX2_Terrain	// NOTE: placeholder name
{
	char unknown0[0xd4];
	OpX2_Terrain *unknownD4;
	OpX2_Terrain *unknownD8;
};

extern bool asciiEnabled;	// NOTE: placeholder name (0xd28d30)
extern OpX2_Terrain *TERRAIN_CAVE_WALL;
extern OpX2_Terrain *caveinThirdTerrain;
extern OpX2_Terrain *opX2_terrainCefba8;	// NOTE: placeholder name
extern OpX2_Terrain *opX2_terrainCefbac;	// NOTE: placeholder name
extern OpX2_Terrain *opX2_terrainCefbb0;	// NOTE: placeholder name
extern XColor *opX2_colorCfe674;	// NOTE: placeholder name

struct OpX2_Cell461250	// NOTE: placeholder name
{
	OpX2_Terrain *terrain;
	char unknown4[7];
	XColor color;

	bool unknown461250();	// NOTE: placeholder name
};

bool OpX2_Cell461250::unknown461250()
{
	return (asciiEnabled
		? (terrain == TERRAIN_CAVE_WALL->unknownD8 || terrain == caveinThirdTerrain->unknownD8 || terrain == opX2_terrainCefba8->unknownD8 || terrain == opX2_terrainCefbac->unknownD8 || terrain == opX2_terrainCefbb0->unknownD8)
		: (terrain == TERRAIN_CAVE_WALL->unknownD4 || terrain == caveinThirdTerrain->unknownD4 || terrain == opX2_terrainCefba8->unknownD4 || terrain == opX2_terrainCefbac->unknownD4 || terrain == opX2_terrainCefbb0->unknownD4))
		&& color == *opX2_colorCfe674;
}

//==================================================================
// 0x455030
//==================================================================

#include <string>
#include <vector>
#include <fstream>

class Console;
template <class T> void deleteVector(vector<T*> &v) throw();	// NOTE: placeholder name (0x9d21f0 for Console)

extern ofstream opX2_fileCd28eb8;	// NOTE: placeholder name (0xd28eb8)

class OpX2_Holder455030	// NOTE: placeholder name
{
public:
	vector<Console*> consoles;
	string name;

	~OpX2_Holder455030();	// 0x455030
	void clear455010();	// NOTE: placeholder name
};

void OpX2_Holder455030::clear455010()
{
	deleteVector(consoles);
}

OpX2_Holder455030::~OpX2_Holder455030()
{
	clear455010();
	if (opX2_fileCd28eb8.is_open())
		opX2_fileCd28eb8.close();
}
