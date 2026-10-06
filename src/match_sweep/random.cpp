// NOTE: placeholder names for recovered 32-bit random-number algorithms.
// Unsigned arithmetic deliberately wraps modulo 2^32.
typedef unsigned int SweepWord;
SweepWord mix1_402b40(SweepWord *state);
SweepWord mix2_402b60(SweepWord *state);
SweepWord mix3_402b80(SweepWord *state);

void sweepRng402cb0(SweepWord *state);
void sweepRng402d10(SweepWord *state);
void sweepRng402d70(SweepWord *state);
void sweepRng402c80(SweepWord *state, SweepWord first, SweepWord second);
void sweepRng402d90(SweepWord *state);
void sweepRng402dc0(SweepWord *state);
SweepWord sweepRng402df0(SweepWord *state);
void sweepRng402e20(SweepWord *state, SweepWord first, SweepWord second);
SweepWord sweepRng402e40(SweepWord *state);
void sweepRng402eb0(SweepWord *state);
void sweepRng402ed0(SweepWord *state);
void sweepRng402e70(SweepWord *state, SweepWord first, SweepWord second, SweepWord third, SweepWord fourth);
void sweepRng402f00(SweepWord *state);
void sweepRng402f20(SweepWord *state);
SweepWord sweepRng402f60(SweepWord *state);
void sweepRng402fb0(SweepWord *state, SweepWord seed0, SweepWord seed1, SweepWord seed2, SweepWord seed3);
void sweepRng403200(SweepWord *state, SweepWord seed0, SweepWord seed1, SweepWord seed2);
void sweepRng403090(SweepWord *state);
void sweepRng4030d0(SweepWord *state);
void sweepRng403110(SweepWord *state);
void sweepRng403150(SweepWord *state);
void sweepRng4032a0(SweepWord *state);
void sweepRng4032e0(SweepWord *state);
void sweepRng403320(SweepWord *state);
SweepWord sweepRng403190(SweepWord *state);
SweepWord sweepRng4031b0(SweepWord *state);
SweepWord sweepRng403360(SweepWord *state);
SweepWord sweepRng403380(SweepWord *state);
void sweepRng402cb0(SweepWord *state)
{
	SweepWord original = state[0];
	SweepWord value = original;
	if (value >= 0x9068ffff)
		value = value - 0x9068ffff;
	if (value == 0)
	{
		value = original ^ 0xffffffff;
		if (value >= 0x9068ffff)
			value = value - 0x9068ffff;
	}
	state[0] = value;
}

void sweepRng402d10(SweepWord *state)
{
	SweepWord original = state[1];
	SweepWord value = original;
	while (value >= 0x464fffff)
		value = value - 0x464fffff;
	if (value == 0)
	{
		value = original ^ 0xffffffff;
		while (value >= 0x464fffff)
			value = value - 0x464fffff;
	}
	state[1] = value;
}

void sweepRng402d70(SweepWord *state)
{
	sweepRng402cb0(state);
	sweepRng402d10(state);
}

void sweepRng402c80(SweepWord *state, SweepWord first, SweepWord second)
{
	state[0] = first;
	state[1] = second;
	sweepRng402d70(state);
}

void sweepRng402d90(SweepWord *state)
{
	state[0] = 36969 * (state[0] & 0xffff) + (state[0] >> 16);
}

void sweepRng402dc0(SweepWord *state)
{
	state[1] = 18000 * (state[1] & 0xffff) + (state[1] >> 16);
}

SweepWord sweepRng402df0(SweepWord *state)
{
	sweepRng402d90(state);
	sweepRng402dc0(state);
	return mix2_402b60(state);
}

void sweepRng402e20(SweepWord *state, SweepWord first, SweepWord second)
{
	sweepRng402c80(state,first,second);
}

SweepWord sweepRng402e40(SweepWord *state)
{
	sweepRng402d90(state);
	sweepRng402dc0(state);
	return mix1_402b40(state);
}

void sweepRng402eb0(SweepWord *state)
{
	if (state[3] == 0)
		state[3] = 0xffffffff;
}

void sweepRng402ed0(SweepWord *state)
{
	sweepRng402cb0(state);
	sweepRng402d10(state);
	sweepRng402eb0(state);
}

void sweepRng402e70(SweepWord *state, SweepWord first, SweepWord second, SweepWord third, SweepWord fourth)
{
	state[0] = first;
	state[1] = second;
	state[2] = third;
	state[3] = fourth;
	sweepRng402ed0(state);
}

void sweepRng402f00(SweepWord *state)
{
	state[2] = 69069 * state[2] + 12345;
}

void sweepRng402f20(SweepWord *state)
{
	SweepWord value = state[3];
	value = value ^ (value << 13);
	value = value ^ (value >> 17);
	value = value ^ (value << 5);
	state[3] = value;
}

SweepWord sweepRng402f60(SweepWord *state)
{
	sweepRng402d90(state);
	sweepRng402dc0(state);
	sweepRng402f00(state);
	sweepRng402f20(state);
	return mix3_402b80(state);
}

void sweepRng402fb0(SweepWord *state, SweepWord seed0, SweepWord seed1, SweepWord seed2, SweepWord seed3)
{
	SweepWord value;
	value = (seed0 << 16) ^ seed0;
	if (value < 2)
	{
		value = seed0 << 24;
		if (value < 2)
			value = ~value;
	}
	state[0] = value;
	value = (seed1 << 16) ^ seed1;
	if (value < 8)
	{
		value = seed1 << 24;
		if (value < 8)
			value = ~value;
	}
	state[1] = value;
	value = (seed2 << 16) ^ seed2;
	if (value < 16)
	{
		value = seed2 << 24;
		if (value < 16)
			value = ~value;
	}
	state[2] = value;
	value = (seed3 << 16) ^ seed3;
	if (value < 128)
	{
		value = seed3 << 24;
		if (value < 128)
			value = ~value;
	}
	state[3] = value;
}

void sweepRng403200(SweepWord *state, SweepWord seed0, SweepWord seed1, SweepWord seed2)
{
	SweepWord value;
	value = (seed0 << 16) ^ seed0;
	if (value < 2)
	{
		value = seed0 << 24;
		if (value < 2)
			value = ~value;
	}
	state[0] = value;
	value = (seed1 << 16) ^ seed1;
	if (value < 8)
	{
		value = seed1 << 24;
		if (value < 8)
			value = ~value;
	}
	state[1] = value;
	value = (seed2 << 16) ^ seed2;
	if (value < 16)
	{
		value = seed2 << 24;
		if (value < 16)
			value = ~value;
	}
	state[2] = value;
}

void sweepRng403090(SweepWord *state)
{
	SweepWord stateValue = state[0];
	SweepWord temp = ((stateValue << 6) ^ stateValue) >> 13;
	stateValue = ((stateValue & 0xfffffffe) << 18) ^ temp;
	state[0] = stateValue;
}

void sweepRng4030d0(SweepWord *state)
{
	SweepWord value = state[1];
	SweepWord shifted = ((value << 2) ^ value) >> 27;
	value = ((value & 0xfffffff8) << 2) ^ shifted;
	state[1] = value;
}

void sweepRng403110(SweepWord *state)
{
	SweepWord value = state[2];
	SweepWord shifted = ((value << 13) ^ value) >> 21;
	value = ((value & 0xfffffff0) << 7) ^ shifted;
	state[2] = value;
}

void sweepRng403150(SweepWord *state)
{
	SweepWord stateValue = state[3];
	SweepWord temp = ((stateValue << 3) ^ stateValue) >> 12;
	stateValue = ((stateValue & 0xffffff80) << 13) ^ temp;
	state[3] = stateValue;
}

void sweepRng4032a0(SweepWord *state)
{
	SweepWord stateValue = state[0];
	SweepWord temp = ((stateValue << 13) ^ stateValue) >> 19;
	stateValue = ((stateValue & 0xfffffffe) << 12) ^ temp;
	state[0] = stateValue;
}

void sweepRng4032e0(SweepWord *state)
{
	SweepWord value = state[1];
	SweepWord shifted = ((value << 2) ^ value) >> 25;
	value = ((value & 0xfffffff8) << 4) ^ shifted;
	state[1] = value;
}

void sweepRng403320(SweepWord *state)
{
	SweepWord value = state[2];
	SweepWord shifted = ((value << 3) ^ value) >> 11;
	value = ((value & 0xfffffff0) << 17) ^ shifted;
	state[2] = value;
}

SweepWord sweepRng403190(SweepWord *state)
{
	return state[0] ^ state[1] ^ state[2] ^ state[3];
}

SweepWord sweepRng4031b0(SweepWord *state)
{
	sweepRng403090(state);
	sweepRng4030d0(state);
	sweepRng403110(state);
	sweepRng403150(state);
	return sweepRng403190(state);
}

SweepWord sweepRng403360(SweepWord *state)
{
	return state[0] ^ state[1] ^ state[2];
}

SweepWord sweepRng403380(SweepWord *state)
{
	sweepRng4032a0(state);
	sweepRng4032e0(state);
	sweepRng403320(state);
	return sweepRng403360(state);
}
