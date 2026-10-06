// lead_stl_a: explicit std::vector<T> instantiations over placeholder element types;
// used with tools/discover.py to match the exe's vector<T> member instantiations.
// NOTE: all element types are placeholders (size + which special members are user-provided).
#include <vector>
#include <string>
using namespace std;

struct E8_0
{
	char pad[8];
};

struct E8_1
{
	char pad[8];
	E8_1();
	E8_1(const E8_1 &e);
};

struct E8_2
{
	char pad[8];
	E8_2();
	E8_2(const E8_2 &e);
	E8_2 &operator=(const E8_2 &e);
};

struct E8_3
{
	char pad[8];
	E8_3();
	E8_3(const E8_3 &e);
	E8_3 &operator=(const E8_3 &e);
	~E8_3();
};

struct Ec_0
{
	char pad[12];
};

struct Ec_1
{
	char pad[12];
	Ec_1();
	Ec_1(const Ec_1 &e);
};

struct Ec_2
{
	char pad[12];
	Ec_2();
	Ec_2(const Ec_2 &e);
	Ec_2 &operator=(const Ec_2 &e);
};

struct Ec_3
{
	char pad[12];
	Ec_3();
	Ec_3(const Ec_3 &e);
	Ec_3 &operator=(const Ec_3 &e);
	~Ec_3();
};

struct E10_0
{
	char pad[16];
};

struct E10_1
{
	char pad[16];
	E10_1();
	E10_1(const E10_1 &e);
};

struct E10_2
{
	char pad[16];
	E10_2();
	E10_2(const E10_2 &e);
	E10_2 &operator=(const E10_2 &e);
};

struct E10_3
{
	char pad[16];
	E10_3();
	E10_3(const E10_3 &e);
	E10_3 &operator=(const E10_3 &e);
	~E10_3();
};

struct E14_0
{
	char pad[20];
};

struct E14_1
{
	char pad[20];
	E14_1();
	E14_1(const E14_1 &e);
};

struct E14_2
{
	char pad[20];
	E14_2();
	E14_2(const E14_2 &e);
	E14_2 &operator=(const E14_2 &e);
};

struct E14_3
{
	char pad[20];
	E14_3();
	E14_3(const E14_3 &e);
	E14_3 &operator=(const E14_3 &e);
	~E14_3();
};

struct E18_0
{
	char pad[24];
};

struct E18_1
{
	char pad[24];
	E18_1();
	E18_1(const E18_1 &e);
};

struct E18_2
{
	char pad[24];
	E18_2();
	E18_2(const E18_2 &e);
	E18_2 &operator=(const E18_2 &e);
};

struct E18_3
{
	char pad[24];
	E18_3();
	E18_3(const E18_3 &e);
	E18_3 &operator=(const E18_3 &e);
	~E18_3();
};

struct E1c_0
{
	char pad[28];
};

struct E1c_1
{
	char pad[28];
	E1c_1();
	E1c_1(const E1c_1 &e);
};

struct E1c_2
{
	char pad[28];
	E1c_2();
	E1c_2(const E1c_2 &e);
	E1c_2 &operator=(const E1c_2 &e);
};

struct E1c_3
{
	char pad[28];
	E1c_3();
	E1c_3(const E1c_3 &e);
	E1c_3 &operator=(const E1c_3 &e);
	~E1c_3();
};

struct E20_0
{
	char pad[32];
};

struct E20_1
{
	char pad[32];
	E20_1();
	E20_1(const E20_1 &e);
};

struct E20_2
{
	char pad[32];
	E20_2();
	E20_2(const E20_2 &e);
	E20_2 &operator=(const E20_2 &e);
};

struct E20_3
{
	char pad[32];
	E20_3();
	E20_3(const E20_3 &e);
	E20_3 &operator=(const E20_3 &e);
	~E20_3();
};

struct E24_0
{
	char pad[36];
};

struct E24_1
{
	char pad[36];
	E24_1();
	E24_1(const E24_1 &e);
};

struct E24_2
{
	char pad[36];
	E24_2();
	E24_2(const E24_2 &e);
	E24_2 &operator=(const E24_2 &e);
};

struct E24_3
{
	char pad[36];
	E24_3();
	E24_3(const E24_3 &e);
	E24_3 &operator=(const E24_3 &e);
	~E24_3();
};

struct E28_0
{
	char pad[40];
};

struct E28_1
{
	char pad[40];
	E28_1();
	E28_1(const E28_1 &e);
};

struct E28_2
{
	char pad[40];
	E28_2();
	E28_2(const E28_2 &e);
	E28_2 &operator=(const E28_2 &e);
};

struct E28_3
{
	char pad[40];
	E28_3();
	E28_3(const E28_3 &e);
	E28_3 &operator=(const E28_3 &e);
	~E28_3();
};

struct E2c_0
{
	char pad[44];
};

struct E2c_1
{
	char pad[44];
	E2c_1();
	E2c_1(const E2c_1 &e);
};

struct E2c_2
{
	char pad[44];
	E2c_2();
	E2c_2(const E2c_2 &e);
	E2c_2 &operator=(const E2c_2 &e);
};

struct E2c_3
{
	char pad[44];
	E2c_3();
	E2c_3(const E2c_3 &e);
	E2c_3 &operator=(const E2c_3 &e);
	~E2c_3();
};

struct E30_0
{
	char pad[48];
};

struct E30_1
{
	char pad[48];
	E30_1();
	E30_1(const E30_1 &e);
};

struct E30_2
{
	char pad[48];
	E30_2();
	E30_2(const E30_2 &e);
	E30_2 &operator=(const E30_2 &e);
};

struct E30_3
{
	char pad[48];
	E30_3();
	E30_3(const E30_3 &e);
	E30_3 &operator=(const E30_3 &e);
	~E30_3();
};

struct E34_0
{
	char pad[52];
};

struct E34_1
{
	char pad[52];
	E34_1();
	E34_1(const E34_1 &e);
};

struct E34_2
{
	char pad[52];
	E34_2();
	E34_2(const E34_2 &e);
	E34_2 &operator=(const E34_2 &e);
};

struct E34_3
{
	char pad[52];
	E34_3();
	E34_3(const E34_3 &e);
	E34_3 &operator=(const E34_3 &e);
	~E34_3();
};

struct E38_0
{
	char pad[56];
};

struct E38_1
{
	char pad[56];
	E38_1();
	E38_1(const E38_1 &e);
};

struct E38_2
{
	char pad[56];
	E38_2();
	E38_2(const E38_2 &e);
	E38_2 &operator=(const E38_2 &e);
};

struct E38_3
{
	char pad[56];
	E38_3();
	E38_3(const E38_3 &e);
	E38_3 &operator=(const E38_3 &e);
	~E38_3();
};

struct E3c_0
{
	char pad[60];
};

struct E3c_1
{
	char pad[60];
	E3c_1();
	E3c_1(const E3c_1 &e);
};

struct E3c_2
{
	char pad[60];
	E3c_2();
	E3c_2(const E3c_2 &e);
	E3c_2 &operator=(const E3c_2 &e);
};

struct E3c_3
{
	char pad[60];
	E3c_3();
	E3c_3(const E3c_3 &e);
	E3c_3 &operator=(const E3c_3 &e);
	~E3c_3();
};

struct E40_0
{
	char pad[64];
};

struct E40_1
{
	char pad[64];
	E40_1();
	E40_1(const E40_1 &e);
};

struct E40_2
{
	char pad[64];
	E40_2();
	E40_2(const E40_2 &e);
	E40_2 &operator=(const E40_2 &e);
};

struct E40_3
{
	char pad[64];
	E40_3();
	E40_3(const E40_3 &e);
	E40_3 &operator=(const E40_3 &e);
	~E40_3();
};

struct E48_0
{
	char pad[72];
};

struct E48_1
{
	char pad[72];
	E48_1();
	E48_1(const E48_1 &e);
};

struct E48_2
{
	char pad[72];
	E48_2();
	E48_2(const E48_2 &e);
	E48_2 &operator=(const E48_2 &e);
};

struct E48_3
{
	char pad[72];
	E48_3();
	E48_3(const E48_3 &e);
	E48_3 &operator=(const E48_3 &e);
	~E48_3();
};

struct E4c_0
{
	char pad[76];
};

struct E4c_1
{
	char pad[76];
	E4c_1();
	E4c_1(const E4c_1 &e);
};

struct E4c_2
{
	char pad[76];
	E4c_2();
	E4c_2(const E4c_2 &e);
	E4c_2 &operator=(const E4c_2 &e);
};

struct E4c_3
{
	char pad[76];
	E4c_3();
	E4c_3(const E4c_3 &e);
	E4c_3 &operator=(const E4c_3 &e);
	~E4c_3();
};

struct E50_0
{
	char pad[80];
};

struct E50_1
{
	char pad[80];
	E50_1();
	E50_1(const E50_1 &e);
};

struct E50_2
{
	char pad[80];
	E50_2();
	E50_2(const E50_2 &e);
	E50_2 &operator=(const E50_2 &e);
};

struct E50_3
{
	char pad[80];
	E50_3();
	E50_3(const E50_3 &e);
	E50_3 &operator=(const E50_3 &e);
	~E50_3();
};

struct E58_0
{
	char pad[88];
};

struct E58_1
{
	char pad[88];
	E58_1();
	E58_1(const E58_1 &e);
};

struct E58_2
{
	char pad[88];
	E58_2();
	E58_2(const E58_2 &e);
	E58_2 &operator=(const E58_2 &e);
};

struct E58_3
{
	char pad[88];
	E58_3();
	E58_3(const E58_3 &e);
	E58_3 &operator=(const E58_3 &e);
	~E58_3();
};

struct E60_0
{
	char pad[96];
};

struct E60_1
{
	char pad[96];
	E60_1();
	E60_1(const E60_1 &e);
};

struct E60_2
{
	char pad[96];
	E60_2();
	E60_2(const E60_2 &e);
	E60_2 &operator=(const E60_2 &e);
};

struct E60_3
{
	char pad[96];
	E60_3();
	E60_3(const E60_3 &e);
	E60_3 &operator=(const E60_3 &e);
	~E60_3();
};

struct E6c_0
{
	char pad[108];
};

struct E6c_1
{
	char pad[108];
	E6c_1();
	E6c_1(const E6c_1 &e);
};

struct E6c_2
{
	char pad[108];
	E6c_2();
	E6c_2(const E6c_2 &e);
	E6c_2 &operator=(const E6c_2 &e);
};

struct E6c_3
{
	char pad[108];
	E6c_3();
	E6c_3(const E6c_3 &e);
	E6c_3 &operator=(const E6c_3 &e);
	~E6c_3();
};

struct E70_0
{
	char pad[112];
};

struct E70_1
{
	char pad[112];
	E70_1();
	E70_1(const E70_1 &e);
};

struct E70_2
{
	char pad[112];
	E70_2();
	E70_2(const E70_2 &e);
	E70_2 &operator=(const E70_2 &e);
};

struct E70_3
{
	char pad[112];
	E70_3();
	E70_3(const E70_3 &e);
	E70_3 &operator=(const E70_3 &e);
	~E70_3();
};

struct E80_0
{
	char pad[128];
};

struct E80_1
{
	char pad[128];
	E80_1();
	E80_1(const E80_1 &e);
};

struct E80_2
{
	char pad[128];
	E80_2();
	E80_2(const E80_2 &e);
	E80_2 &operator=(const E80_2 &e);
};

struct E80_3
{
	char pad[128];
	E80_3();
	E80_3(const E80_3 &e);
	E80_3 &operator=(const E80_3 &e);
	~E80_3();
};

struct E84_0
{
	char pad[132];
};

struct E84_1
{
	char pad[132];
	E84_1();
	E84_1(const E84_1 &e);
};

struct E84_2
{
	char pad[132];
	E84_2();
	E84_2(const E84_2 &e);
	E84_2 &operator=(const E84_2 &e);
};

struct E84_3
{
	char pad[132];
	E84_3();
	E84_3(const E84_3 &e);
	E84_3 &operator=(const E84_3 &e);
	~E84_3();
};

struct Ea0_0
{
	char pad[160];
};

struct Ea0_1
{
	char pad[160];
	Ea0_1();
	Ea0_1(const Ea0_1 &e);
};

struct Ea0_2
{
	char pad[160];
	Ea0_2();
	Ea0_2(const Ea0_2 &e);
	Ea0_2 &operator=(const Ea0_2 &e);
};

struct Ea0_3
{
	char pad[160];
	Ea0_3();
	Ea0_3(const Ea0_3 &e);
	Ea0_3 &operator=(const Ea0_3 &e);
	~Ea0_3();
};

struct Eac_0
{
	char pad[172];
};

struct Eac_1
{
	char pad[172];
	Eac_1();
	Eac_1(const Eac_1 &e);
};

struct Eac_2
{
	char pad[172];
	Eac_2();
	Eac_2(const Eac_2 &e);
	Eac_2 &operator=(const Eac_2 &e);
};

struct Eac_3
{
	char pad[172];
	Eac_3();
	Eac_3(const Eac_3 &e);
	Eac_3 &operator=(const Eac_3 &e);
	~Eac_3();
};

struct Ec0_0
{
	char pad[192];
};

struct Ec0_1
{
	char pad[192];
	Ec0_1();
	Ec0_1(const Ec0_1 &e);
};

struct Ec0_2
{
	char pad[192];
	Ec0_2();
	Ec0_2(const Ec0_2 &e);
	Ec0_2 &operator=(const Ec0_2 &e);
};

struct Ec0_3
{
	char pad[192];
	Ec0_3();
	Ec0_3(const Ec0_3 &e);
	Ec0_3 &operator=(const Ec0_3 &e);
	~Ec0_3();
};

struct E100_0
{
	char pad[256];
};

struct E100_1
{
	char pad[256];
	E100_1();
	E100_1(const E100_1 &e);
};

struct E100_2
{
	char pad[256];
	E100_2();
	E100_2(const E100_2 &e);
	E100_2 &operator=(const E100_2 &e);
};

struct E100_3
{
	char pad[256];
	E100_3();
	E100_3(const E100_3 &e);
	E100_3 &operator=(const E100_3 &e);
	~E100_3();
};

template class std::vector<E8_0>;
template class std::vector<E8_1>;
template class std::vector<E8_2>;
template class std::vector<E8_3>;
template class std::vector<Ec_0>;
template class std::vector<Ec_1>;
template class std::vector<Ec_2>;
template class std::vector<Ec_3>;
template class std::vector<E10_0>;
template class std::vector<E10_1>;
template class std::vector<E10_2>;
template class std::vector<E10_3>;
template class std::vector<E14_0>;
template class std::vector<E14_1>;
template class std::vector<E14_2>;
template class std::vector<E14_3>;
template class std::vector<E18_0>;
template class std::vector<E18_1>;
template class std::vector<E18_2>;
template class std::vector<E18_3>;
template class std::vector<E1c_0>;
template class std::vector<E1c_1>;
template class std::vector<E1c_2>;
template class std::vector<E1c_3>;
template class std::vector<E20_0>;
template class std::vector<E20_1>;
template class std::vector<E20_2>;
template class std::vector<E20_3>;
template class std::vector<E24_0>;
template class std::vector<E24_1>;
template class std::vector<E24_2>;
template class std::vector<E24_3>;
template class std::vector<E28_0>;
template class std::vector<E28_1>;
template class std::vector<E28_2>;
template class std::vector<E28_3>;
template class std::vector<E2c_0>;
template class std::vector<E2c_1>;
template class std::vector<E2c_2>;
template class std::vector<E2c_3>;
template class std::vector<E30_0>;
template class std::vector<E30_1>;
template class std::vector<E30_2>;
template class std::vector<E30_3>;
template class std::vector<E34_0>;
template class std::vector<E34_1>;
template class std::vector<E34_2>;
template class std::vector<E34_3>;
template class std::vector<E38_0>;
template class std::vector<E38_1>;
template class std::vector<E38_2>;
template class std::vector<E38_3>;
template class std::vector<E3c_0>;
template class std::vector<E3c_1>;
template class std::vector<E3c_2>;
template class std::vector<E3c_3>;
template class std::vector<E40_0>;
template class std::vector<E40_1>;
template class std::vector<E40_2>;
template class std::vector<E40_3>;
template class std::vector<E48_0>;
template class std::vector<E48_1>;
template class std::vector<E48_2>;
template class std::vector<E48_3>;
template class std::vector<E4c_0>;
template class std::vector<E4c_1>;
template class std::vector<E4c_2>;
template class std::vector<E4c_3>;
template class std::vector<E50_0>;
template class std::vector<E50_1>;
template class std::vector<E50_2>;
template class std::vector<E50_3>;
template class std::vector<E58_0>;
template class std::vector<E58_1>;
template class std::vector<E58_2>;
template class std::vector<E58_3>;
template class std::vector<E60_0>;
template class std::vector<E60_1>;
template class std::vector<E60_2>;
template class std::vector<E60_3>;
template class std::vector<E6c_0>;
template class std::vector<E6c_1>;
template class std::vector<E6c_2>;
template class std::vector<E6c_3>;
template class std::vector<E70_0>;
template class std::vector<E70_1>;
template class std::vector<E70_2>;
template class std::vector<E70_3>;
template class std::vector<E80_0>;
template class std::vector<E80_1>;
template class std::vector<E80_2>;
template class std::vector<E80_3>;
template class std::vector<E84_0>;
template class std::vector<E84_1>;
template class std::vector<E84_2>;
template class std::vector<E84_3>;
template class std::vector<Ea0_0>;
template class std::vector<Ea0_1>;
template class std::vector<Ea0_2>;
template class std::vector<Ea0_3>;
template class std::vector<Eac_0>;
template class std::vector<Eac_1>;
template class std::vector<Eac_2>;
template class std::vector<Eac_3>;
template class std::vector<Ec0_0>;
template class std::vector<Ec0_1>;
template class std::vector<Ec0_2>;
template class std::vector<Ec0_3>;
template class std::vector<E100_0>;
template class std::vector<E100_1>;
template class std::vector<E100_2>;
template class std::vector<E100_3>;
template class std::vector<char>;
template class std::vector<short>;
template class std::vector<int>;
template class std::vector<unsigned int>;
template class std::vector<float>;
template class std::vector<double>;
template class std::vector<bool>;
template class std::vector<void *>;
template class std::vector<char *>;
template class std::vector<int *>;
template class std::vector<long long>;
template class std::vector<string>;
template class std::vector<vector<int>>;
template class std::vector<vector<string>>;
template class std::vector<vector<char>>;
template class std::vector<vector<void *>>;
