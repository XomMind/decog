// team_d_25: animation pool constructor (0x4547c0).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
// The pooled element's constructor is defined here with a placeholder body so that LTCG can prove it
// cannot throw, as in the exe (no exception state for the new-expression; its temporaries remain).
#include <vector>
using namespace std;

class PoolAnim	// NOTE: placeholder name (Item454630, 0xb8 bytes)
{
public:
	PoolAnim();	// 0x454630
	int pad[0xb8 / 4];
};

PoolAnim::PoolAnim()	// NOTE: placeholder body
{
	pad[0] = 0;
}

class NoiseField	// NOTE: placeholder name (OpR1b_NoiseField)
{
public:
	NoiseField();	// 0x421650
	~NoiseField();
	void init(int dimensions_, float scale_, int seed_);
	int pad[8];
};

class OpD_AnimPool4547c0	// NOTE: placeholder name (built by GM::readyGame)
{
public:
	OpD_AnimPool4547c0();

	vector<int>			unknown00;	// NOTE: placeholder name
	vector<PoolAnim *>	pool;		// +0x10, NOTE: placeholder name
	int					unknown20;	// NOTE: placeholder name
	vector<int>			unknown24;	// NOTE: placeholder name
	vector<int>			unknown34;	// NOTE: placeholder name
	NoiseField			noise;		// +0x44, NOTE: placeholder name
	int					unknown64;	// NOTE: placeholder name
};

OpD_AnimPool4547c0::OpD_AnimPool4547c0()
{
	for (int i = 0; i < 20000; i++)
		pool.push_back(new PoolAnim);
	noise.init(2,0.01f,0x1e);
	unknown64 = 0;
}
