// cc_r2_29: atexit destructors of namespace-scope globals (0xb5f360-0xb5f66f)
// NOTE: global names and placeholder classes are placeholders; the address is in each name.
#include <vector>
#include <string>

using namespace std;

struct XCell;	// NOTE: placeholder layout

template <class T>
class Array2D	// NOTE: placeholder name
{
	int	pad[3];
public:
	Array2D();
	~Array2D();
};

struct RNG
{
	RNG();
	~RNG();
};

struct Unknown9b2e60	// NOTE: placeholder name
{
	Unknown9b2e60();
	~Unknown9b2e60();
};

struct Unknown9b8b60	// NOTE: placeholder name
{
	Unknown9b8b60();
	~Unknown9b8b60();
};

struct Unknown4664a0	// NOTE: placeholder name
{
	Unknown4664a0();
	~Unknown4664a0();
};

struct Unknown4664f0	// NOTE: placeholder name
{
	Unknown4664f0();
	~Unknown4664f0();
};

struct Unknown466540	// NOTE: placeholder name
{
	Unknown466540();
	~Unknown466540();
};

struct Unknown466590	// NOTE: placeholder name
{
	Unknown466590();
	~Unknown466590();
};

struct Unknown4665e0	// NOTE: placeholder name
{
	Unknown4665e0();
	~Unknown4665e0();
};

struct Unknown466630	// NOTE: placeholder name
{
	Unknown466630();
	~Unknown466630();
};

struct Unknown4666a0	// NOTE: placeholder name
{
	Unknown4666a0();
	~Unknown4666a0();
};

struct Unknown466710	// NOTE: placeholder name
{
	Unknown466710();
	~Unknown466710();
};

vector<string>	strvec_d30540;
vector<string>	strvec_d1d61c;
vector<string>	strvec_d29d7c;
Array2D<XCell>	arr_d201c8[7];
Array2D<XCell>	arr_d2ea30;
vector<unsigned int>	vec_cf1af8;
vector<unsigned int>	vec_d15d9c;
vector<string>	strvec_d1f394;
vector<unsigned int>	vec_d21afc;
vector<unsigned int>	vec_cf7560;
vector<string>	strvec_d388e0;
vector<string>	strvec_d2c42c;
Unknown9b2e60	obj_cfc184;
vector<unsigned int>	vec_d35b58;
vector<string>	strvec_d1d9b0;
vector<string>	strvec_d2283c;
vector<unsigned int>	vec_cf39dc;
vector<unsigned int>	vec_d02cb4;
vector<unsigned int>	vec_cf1a04;
vector<unsigned int>	vec_d161c4;
vector<string>	strvec_d29970;
vector<unsigned int>	vec_d379ec;
vector<unsigned int>	vec_d25860;
vector<unsigned int>	vec_d39458;
vector<unsigned int>	vec_d1d078;
vector<string>	strvec_cf25c8;
Unknown9b8b60	obj_d20454;
Unknown9b8b60	obj_cfb938;
vector<unsigned int>	vec_cfb908;
vector<unsigned int>	vec_cfb918;
Unknown9b8b60	obj_d29734;
vector<unsigned int>	vec_cfb928;
Unknown9b8b60	obj_cfb8f8;
vector<unsigned int>	vec_cf686c;
RNG	rng_d20d00;
vector<unsigned int>	vec_d22590;
Unknown4664a0	obj_d20404;
Unknown4664f0	obj_d33888;
Unknown466540	obj_d2f288;
Unknown466590	obj_d208d4;
Unknown4665e0	obj_d21720;
Unknown466630	obj_d2a298;
Unknown4666a0	obj_d1e720;
Unknown466710	obj_cfac14;
vector<unsigned int>	vec_d2f108;
vector<string>	strvec_d1ddcc;
vector<unsigned int>	vec_cf7550;
vector<string>	strvec_d33d28;
