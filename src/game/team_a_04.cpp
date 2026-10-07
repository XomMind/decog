// team_a_04: small seeded-RNG wrapper classes (seed + rangeInt) at 0x407150-0x407480.
// NOTE: class and member names are placeholders.
typedef unsigned int u32;

u32 boundedRand_402ad0(u32 range, u32 (*gen)(void *), void *ctx);	// NOTE: placeholder name
u32 xoroshiro64Star_402aa0(u32 *s);		// NOTE: placeholder name
void lcgSeed_402bc0(u32 *s, u32 seed);	// NOTE: placeholder name
u32 lcgNext_402bd0(u32 *s);				// NOTE: placeholder name
void xorshift32Seed_402c00(u32 *s, u32 seed);	// NOTE: placeholder name
u32 xorshift32Next_402c40(u32 *s);		// NOTE: placeholder name
void sweepRng402e20(u32 *state, u32 first, u32 second);
u32 sweepRng402e40(u32 *state);
void sweepRng402c80(u32 *state, u32 first, u32 second);
u32 sweepRng402df0(u32 *state);
void sweepRng402e70(u32 *state, u32 first, u32 second, u32 third, u32 fourth);
u32 sweepRng402f60(u32 *state);
void sweepRng402fb0(u32 *state, u32 seed0, u32 seed1, u32 seed2, u32 seed3);
u32 sweepRng4031b0(u32 *state);
void sweepRng403200(u32 *state, u32 seed0, u32 seed1, u32 seed2);
u32 sweepRng403380(u32 *state);
unsigned int OpY1_rng4033c0(unsigned int *state);	// NOTE: placeholder name

typedef u32 (*RngGen)(void *);

class RngXoro64	// NOTE: placeholder name
{
public:
	u32 currentSeed;
	u32 state[2];
	void seed(u32 seed_);
	int rangeInt(int low, u32 count);
};

void RngXoro64::seed(u32 seed_)
{
	currentSeed = seed_;
	state[0] = currentSeed;
	state[1] = currentSeed + 1;
}

int RngXoro64::rangeInt(int low, u32 count)
{
	return boundedRand_402ad0(count,(RngGen)xoroshiro64Star_402aa0,state) + low;
}

#define RNG_ONE_WORD(Name, seedFn, nextFn) \
class Name \
{ \
public: \
	u32 state; \
	void seed(u32 seed_); \
	int rangeInt(int low, u32 count); \
}; \
int Name::rangeInt(int low, u32 count) \
{ \
	return boundedRand_402ad0(count,(RngGen)nextFn,&state) + low; \
}

RNG_ONE_WORD(RngLcg, lcgSeed_402bc0, lcgNext_402bd0)	// NOTE: placeholder name
void RngLcg::seed(u32 seed_) { lcgSeed_402bc0(&state,seed_); }

RNG_ONE_WORD(RngXorshift32, xorshift32Seed_402c00, xorshift32Next_402c40)	// NOTE: placeholder name
void RngXorshift32::seed(u32 seed_) { xorshift32Seed_402c00(&state,seed_); }

#define RNG_STATE(Name, n, nextFn) \
class Name \
{ \
public: \
	u32 state[n]; \
	void seed(u32 seed_); \
	int rangeInt(int low, u32 count); \
}; \
int Name::rangeInt(int low, u32 count) \
{ \
	return boundedRand_402ad0(count,(RngGen)nextFn,state) + low; \
}

RNG_STATE(Rng407250, 2, sweepRng402e40)	// NOTE: placeholder name
void Rng407250::seed(u32 seed_) { sweepRng402e20(state,seed_,seed_ + 1); }

RNG_STATE(Rng4072b0, 2, sweepRng402df0)	// NOTE: placeholder name
void Rng4072b0::seed(u32 seed_) { sweepRng402c80(state,seed_,seed_ + 1); }

RNG_STATE(Rng407310, 4, sweepRng402f60)	// NOTE: placeholder name
void Rng407310::seed(u32 seed_) { sweepRng402e70(state,seed_,seed_ + 1,seed_ + 2,seed_ + 3); }

RNG_STATE(Rng407380, 4, sweepRng4031b0)	// NOTE: placeholder name
void Rng407380::seed(u32 seed_) { sweepRng402fb0(state,seed_,seed_ + 1,seed_ + 2,seed_ + 3); }

RNG_STATE(Rng4073f0, 3, sweepRng403380)	// NOTE: placeholder name
void Rng4073f0::seed(u32 seed_) { sweepRng403200(state,seed_,seed_ + 1,seed_ + 2); }

RNG_STATE(Rng407450, 3, OpY1_rng4033c0)	// NOTE: placeholder name
void Rng407450::seed(u32 seed_)
{
	state[0] = seed_;
	state[1] = seed_ + 1;
	state[2] = seed_ + 2;
}
