// team_d_03: dynamic initializers and atexit destructors of container globals (vector, string arrays, Array2D)
// NOTE: all global names are placeholders carrying the exe data address; types come from the
// constructor/destructor callees.
#include <vector>
#include <string>
using namespace std;

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point();
	Point(int v);
	Point(int x_, int y_);
};

class HExplosive	// NOTE: placeholder layout
{
	int ID;
};

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	width;
	int	height;
	T	*data;

public:
	Array2D();
	~Array2D();
};

struct VE_E20_0 { int a; };	// NOTE: placeholder vector element type
struct VE_E24_0 { int a; };	// NOTE: placeholder vector element type
struct VE_E60_0 { int a; };	// NOTE: placeholder vector element type
struct VE_E8_1 { int a; };	// NOTE: placeholder vector element type
struct VE_OpR6_KA_16_0 { int a; };	// NOTE: placeholder vector element type
struct VE_OpR6_KA_36_1 { int a; };	// NOTE: placeholder vector element type
struct VE_OpR6_KA_84_0 { int a; };	// NOTE: placeholder vector element type
struct VE_OpR6_KC_36_0 { int a; };	// NOTE: placeholder vector element type

vector<unsigned int>	vec_d161a4;
Array2D<int>	array2d_d02cc4;
Array2D<int>	array2d_d21b28;
Array2D<int>	array2d_d396dc;
string	strs_d1e4b8[21];
string	strs_d2e840[6];
string	strs_cf1298[12];
vector<unsigned int>	vec_cfb678;
vector<unsigned int>	vec_d2e224;
string	strs_d162a0[4];
string	strs_cf2008[52];
Array2D<int>	array2d_cf1964;
Array2D<int>	array2d_cf447c;
vector<VE_E24_0>	vec_d1f31c;
vector<VE_E8_1>	vec_d222f0;
vector<VE_E20_0>	vec_cf65c4;
vector<VE_E60_0>	vec_cf124c;
vector<VE_OpR6_KA_16_0>	vec_d02b4c;
vector<string>	vec_d21768;
vector<string>	vec_cf123c;
vector<string>	vec_d1e30c;
vector<VE_E8_1>	vec_d39d30;
vector<unsigned int>	vec_cf4590;
vector<unsigned int>	vec_d1ecc0;
vector<unsigned int>	vec_d1defc;
vector<VE_OpR6_KA_84_0>	vec_cf126c;
vector<VE_E20_0>	vec_cf125c;
vector<unsigned int>	vec_d16178;
vector<unsigned int>	vec_d2c34c;
vector<unsigned int>	vec_d2e9a0;
string	strs_d024a0[4];
string	strs_d022d8[5];
string	strs_d02410[5];
string	strs_d020a8[20];
string	strs_d02510[20];
string	strs_d01d60[15];
string	strs_d1df10[9];
string	strs_d01f20[14];
string	strs_d226f0[3];
string	strs_d31918[11];
string	strs_d02368[6];
string	strs_d02ce0[7];
string	strs_d35180[4];
string	strs_d35398[5];
string	strs_d34d38[29];
string	strs_d35428[31];
string	strs_d34768[16];
string	strs_d35068[4];
string	strs_d350d8[6];
string	strs_d346c0[6];
string	strs_d34b78[15];
string	strs_d349f0[14];
string	strs_d35260[11];
string	strs_d351f0[3];
string	strs_d34928[7];
string	strs_d33ea8[69];
string	strs_d34650[3];
vector<unsigned int>	vec_d2ac98;
vector<HExplosive>	vec_d1d4c4;
vector<char>	vec_d21b10;
vector<string>	vec_cf45a0;
vector<string>	vec_cf08b4;
vector<unsigned int>	vec_d1e834;
vector<unsigned int>	vec_d1e7f4;
vector<string>	vec_d1e804;
vector<string>	vec_d1e7b4;
vector<unsigned int>	vec_d2a7b8;
vector<unsigned int>	vec_d1e764;
vector<VE_OpR6_KC_36_0>	vec_d20844;
vector<string>	vec_d1e794;
vector<string>	vec_d1e824;
vector<unsigned int>	vec_d32958;
vector<VE_OpR6_KA_36_1>	vec_d29798;
vector<VE_OpR6_KA_36_1>	vec_d29788;
vector<Point>	vec_d1e234;
