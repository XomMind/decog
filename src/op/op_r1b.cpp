// op_r1b: misc functions in 0x41ae40-0x42a3c0 matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; invented names are placeholders.
#include <string>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../util/rng.h"

typedef void *TCOD_noise_t;

typedef enum {
	TCOD_NOISE_PERLIN = 1,
	TCOD_NOISE_SIMPLEX = 2,
	TCOD_NOISE_WAVELET = 4,
	TCOD_NOISE_DEFAULT = 0
} TCOD_noise_type_t;

#define TCOD_NOISE_MAX_OCTAVES			128
#define TCOD_NOISE_MAX_DIMENSIONS		4
#define CLAMP(a, b, x)		((x) < (a) ? (a) : ((x) > (b) ? (b) : (x)))

class TCODNoise
{
public:
	TCODNoise(int dimensions, TCOD_noise_type_t type) throw();
	virtual ~TCODNoise();
	float get(float *f, TCOD_noise_type_t type);
	float getFbm(float *f, float octaves, TCOD_noise_type_t type);
protected:
	TCOD_noise_t data;
};
using namespace std;

extern RNG rng;

void opX1GetClipboardText(unsigned int format, int *length, char **buffer);
int absmod(int x, int n);

struct OpR1b_Clip
{
	bool enabled;

	bool getClipboard_41ae40(string &text);	// NOTE: placeholder name
};

bool OpR1b_Clip::getClipboard_41ae40(string &text)
{
	if (!enabled)
	{
		return false;
	}
	int length;
	char *buffer = NULL;
	opX1GetClipboardText(0x54455854, &length, &buffer);
	if (length == 0)
	{
		return false;
	}
	else
	{
		text.assign(buffer);
		return true;
	}
}

//==================================================================
// libtcod wavelet noise helpers
//==================================================================

float OpR1b_acoeffs[32] = {
		0.000334f, -0.001528f, 0.000410f, 0.003545f, -0.000938f, -0.008233f, 0.002172f, 0.019120f,
		-0.005040f,-0.044412f, 0.011655f, 0.103311f, -0.025936f, -0.243780f, 0.033979f, 0.655340f,
		 0.655340f, 0.033979f,-0.243780f,-0.025936f,  0.103311f,  0.011655f,-0.044412f,-0.005040f,
		0.019120f,  0.002172f,-0.008233f,-0.000938f,  0.003546f,  0.000410f,-0.001528f, 0.000334f,
};
float *OpR1b_a = &OpR1b_acoeffs[16];
extern float *delta_wavelet_cea810; // NOTE: private placeholder alias of filter-pointer global 0xcea810.

void TCOD_noise_wavelet_downsample(float *from, float *to, int stride)
{
	int i;
	for (i=0; i < 32/2; i++) {
		int k;
		to[i*stride]=0;
		for (k=2*i-16; k <2*i+16; k++) {
			to[i*stride] += delta_wavelet_cea810[k-2*i]* from[ absmod(k,32) * stride ];
		}
	}
}

float OpR1b_pcoeffs[4] = { 0.25f, 0.75f, 0.75f, 0.25f };
float *OpR1b_p = &OpR1b_pcoeffs[2];
extern float *delta_wavelet_cea824; // NOTE: private placeholder alias of filter-pointer global 0xcea824.

void TCOD_noise_wavelet_upsample(float *from, float *to, int stride)
{
	int i;
	for (i=0; i < 32; i++) {
		int k;
		to[i*stride]=0;
		for (k=i/2; k <i/2+1; k++) {
			to[i*stride] += delta_wavelet_cea824[i-2*k]* from[ absmod(k,32/2) * stride ];
		}
	}
}

//==================================================================
// libtcod noise constructor
//==================================================================

struct perlin_data_t
{
	int ndim;
	unsigned char map[256];
	float buffer[256][TCOD_NOISE_MAX_DIMENSIONS];
	float H;
	float lacunarity;
	float exponent[TCOD_NOISE_MAX_OCTAVES];
	float *waveletTileData;
	TCOD_noise_type_t noise_type;
};

void normalize(perlin_data_t *data, float *f);

#define SWAP(a, b, t)		t = a; a = b; b = t

// NOTE: placeholder name (0x41b300 is TCOD_noise_new; that name is defined in noise_c.cpp)
TCOD_noise_t OpR1b_TCOD_noise_new(int ndim, float hurst, float lacunarity)
{
	perlin_data_t *data=(perlin_data_t *)calloc(sizeof(perlin_data_t),1);
	int i, j;
	unsigned char tmp;
	float f = 1;
	data->ndim = ndim;
	for(i=0; i<256; i++)
	{
		data->map[i] = (unsigned char)i;
		for(j=0; j<data->ndim; j++)
			data->buffer[i][j] = rng.rangeFloat(-0.5, 0.5);
		normalize(data,data->buffer[i]);
	}

	while(--i)
	{
		j = rng.rangeInt(0, 255);
		SWAP(data->map[i], data->map[j], tmp);
	}

	data->H = hurst;
	data->lacunarity = lacunarity;
	for(i=0; i<TCOD_NOISE_MAX_OCTAVES; i++)
	{
		data->exponent[i] = 1.0f / f;
		f *= lacunarity;
	}
	data->noise_type = TCOD_NOISE_DEFAULT;
	return (TCOD_noise_t)data;
}

//==================================================================
// libtcod noise: fbm and wavelet tile init
//==================================================================

typedef float (*OpR1b_noise_func_t)(TCOD_noise_t noise, float *f);

// NOTE: placeholder name (static TCOD_noise_fbm_int in libtcod)
float OpR1b_noise_fbm_int(TCOD_noise_t noise, float *f, float octaves, OpR1b_noise_func_t func)
{
	float tf[TCOD_NOISE_MAX_DIMENSIONS];
	perlin_data_t *data=(perlin_data_t *)noise;
	double value = 0;
	int i,j;
	memcpy(tf,f,sizeof(float)*data->ndim);

	for(i=0; i<(int)octaves; i++)
	{
		value += (double)(func(noise,tf)) * data->exponent[i];
		for (j=0; j < data->ndim; j++) tf[j] *= data->lacunarity;
	}

	octaves -= (int)octaves;
	if(octaves > 1e-6f)
		value += (double)(octaves * func(noise,tf)) * data->exponent[i];
	return CLAMP(-0.99999f, 0.99999f, (float)value);
}

// NOTE: placeholder name (static TCOD_noise_wavelet_init in libtcod)
void OpR1b_noise_wavelet_init(TCOD_noise_t pnoise)
{
	perlin_data_t *data=(perlin_data_t *)pnoise;
	int ix,iy,iz,i,sz=32*32*32*sizeof(float);
	float *temp1=(float *)malloc(sz);
	float *temp2=(float *)malloc(sz);
	float *noise=(float *)malloc(sz);
	int offset;
	for (i=0; i < 32*32*32; i++ ) {
		noise[i]=rng.rangeFloat(-1.0f,1.0f);
	}
	for (iy=0; iy < 32; iy++ ) {
		for (iz=0; iz < 32; iz++ ) {
			i = iy * 32 + iz * 32 * 32;
			TCOD_noise_wavelet_downsample(&noise[i], &temp1[i], 1);
			TCOD_noise_wavelet_upsample(&temp1[i], &temp2[i], 1);
		}
	}
	for (ix=0; ix < 32; ix++ ) {
		for (iz=0; iz < 32; iz++ ) {
			i = ix + iz * 32 * 32;
			TCOD_noise_wavelet_downsample(&temp2[i], &temp1[i], 32);
			TCOD_noise_wavelet_upsample(&temp1[i], &temp2[i], 32);
		}
	}
	for (ix=0; ix < 32; ix++ ) {
		for (iy=0; iy < 32; iy++ ) {
			i = ix + iy * 32;
			TCOD_noise_wavelet_downsample(&temp2[i], &temp1[i], 32 * 32);
			TCOD_noise_wavelet_upsample(&temp1[i], &temp2[i], 32 * 32);
		}
	}
	for (i=0; i < 32*32*32; i++ ) {
		noise[i] -= temp2[i];
	}
	offset = 32/2;
	if ( (offset & 1) == 0 ) offset++;
	for (i=0,ix=0; ix < 32; ix++ ) {
		for (iy=0; iy < 32; iy++ ) {
			for (iz=0; iz < 32; iz++ ) {
				temp1[i++]=noise[ absmod(ix+offset,32)
					+ absmod(iy+offset,32)*32
					+ absmod(iz+offset,32)*32*32
					];
			}
		}
	}
	for (i=0; i < 32*32*32; i++ ) {
		noise[i] += temp1[i];
	}
	data->waveletTileData=noise;
	free(temp1);
	free(temp2);
}

//==================================================================
// libtcod wavelet noise lookup
//==================================================================

// NOTE: placeholder name (TCOD_noise_wavelet in libtcod)
float OpR1b_noise_wavelet(TCOD_noise_t noise, float *f)
{
	perlin_data_t *data=(perlin_data_t *)noise;
	float pf[3];
	int i;
	int p[3],c[3],mid[3],n=32;
	float w[3][3],t,result=0.0f;
	if ( data->ndim > 3 ) return 0.0f;
	if (! data->waveletTileData ) OpR1b_noise_wavelet_init(noise);
	for (i=0; i < data->ndim; i++ ) pf[i]=f[i]*2.0f;
	for (i=data->ndim; i < 3; i++ ) pf[i]=0.0f;
	for (i=0; i < 3; i++ ) {
		mid[i]=(int)ceil(pf[i]-0.5f);
		t=mid[i] - (pf[i]-0.5f);
		w[i][0]=t*t*0.5f;
		w[i][2]=(1.0f-t)*(1.0f-t)*0.5f;
		w[i][1]=1.0f - w[i][0]-w[i][2];
	}
	for (p[2]=-1; p[2]<=1; p[2]++) {
		for (p[1]=-1; p[1]<=1; p[1]++) {
			for (p[0]=-1; p[0]<=1; p[0]++) {
				float weight=1.0f;
				for (i=0;i<3;i++) {
					c[i]=absmod(mid[i]+p[i],n);
					weight *= w[i][p[i]+1];
				}
				result += weight * data->waveletTileData[ c[2]*n*n + c[1]*n + c[0] ];
			}
		}
	}
	return CLAMP(-1.0f,1.0f,result);
}

//==================================================================
// libtcod noise dispatchers
//==================================================================

float TCOD_noise_perlin(TCOD_noise_t noise, float *f);
float TCOD_noise_simplex(TCOD_noise_t noise, float *f);
float TCOD_noise_fbm_perlin(TCOD_noise_t noise, float *f, float octaves);
float TCOD_noise_fbm_simplex(TCOD_noise_t noise, float *f, float octaves);
float TCOD_noise_fbm_wavelet(TCOD_noise_t noise, float *f, float octaves);

// NOTE: placeholder name (TCOD_noise_set_type in libtcod)
void OpR1b_noise_set_type(TCOD_noise_t noise, TCOD_noise_type_t type)
{
	((perlin_data_t *)noise)->noise_type = type;
}

// NOTE: placeholder name (TCOD_noise_get_ex in libtcod)
float OpR1b_noise_get_ex(TCOD_noise_t noise, float *f, TCOD_noise_type_t type)
{
	switch (type) {
		case (TCOD_NOISE_PERLIN): return TCOD_noise_perlin(noise,f); break;
		case (TCOD_NOISE_SIMPLEX): return TCOD_noise_simplex(noise,f); break;
		case (TCOD_NOISE_WAVELET): return OpR1b_noise_wavelet(noise,f); break;
		default:
			switch (((perlin_data_t *)noise)->noise_type) {
				case (TCOD_NOISE_PERLIN): return TCOD_noise_perlin(noise,f); break;
				case (TCOD_NOISE_SIMPLEX): return TCOD_noise_simplex(noise,f); break;
				case (TCOD_NOISE_WAVELET): return OpR1b_noise_wavelet(noise,f); break;
				default: return TCOD_noise_simplex(noise,f); break;
			}
			break;
	}
}

// NOTE: placeholder name (TCOD_noise_get_fbm_ex in libtcod)
float OpR1b_noise_get_fbm_ex(TCOD_noise_t noise, float *f, float octaves, TCOD_noise_type_t type)
{
	switch (type) {
		case (TCOD_NOISE_PERLIN): return TCOD_noise_fbm_perlin(noise,f,octaves); break;
		case (TCOD_NOISE_SIMPLEX): return TCOD_noise_fbm_simplex(noise,f,octaves); break;
		case (TCOD_NOISE_WAVELET): return TCOD_noise_fbm_wavelet(noise,f,octaves); break;
		default:
			switch (((perlin_data_t *)noise)->noise_type) {
				case (TCOD_NOISE_PERLIN): return TCOD_noise_fbm_perlin(noise,f,octaves); break;
				case (TCOD_NOISE_SIMPLEX): return TCOD_noise_fbm_simplex(noise,f,octaves); break;
				case (TCOD_NOISE_WAVELET): return TCOD_noise_fbm_wavelet(noise,f,octaves); break;
				default: return TCOD_noise_fbm_simplex(noise,f,octaves); break;
			}
			break;
	}
}

// NOTE: placeholder name (TCOD_noise_get in libtcod)
float OpR1b_noise_get(TCOD_noise_t noise, float *f)
{
	switch (((perlin_data_t *)noise)->noise_type) {
		case (TCOD_NOISE_PERLIN): return TCOD_noise_perlin(noise,f); break;
		case (TCOD_NOISE_SIMPLEX): return TCOD_noise_simplex(noise,f); break;
		case (TCOD_NOISE_WAVELET): return OpR1b_noise_wavelet(noise,f); break;
		default: return TCOD_noise_simplex(noise,f); break;
	}
}

// NOTE: placeholder name (TCOD_noise_get_fbm in libtcod)
float OpR1b_noise_get_fbm(TCOD_noise_t noise, float *f, float octaves)
{
	switch (((perlin_data_t *)noise)->noise_type) {
		case (TCOD_NOISE_PERLIN): return TCOD_noise_fbm_perlin(noise,f,octaves); break;
		case (TCOD_NOISE_SIMPLEX): return TCOD_noise_fbm_simplex(noise,f,octaves); break;
		case (TCOD_NOISE_WAVELET): return TCOD_noise_fbm_wavelet(noise,f,octaves); break;
		default: return TCOD_noise_fbm_simplex(noise,f,octaves); break;
	}
}

// NOTE: placeholder names (TCOD_noise_fbm_perlin/simplex/wavelet in libtcod)
float OpR1b_noise_fbm_perlin(TCOD_noise_t noise, float *f, float octaves)
{
	return OpR1b_noise_fbm_int(noise,f,octaves,TCOD_noise_perlin);
}

float OpR1b_noise_fbm_simplex(TCOD_noise_t noise, float *f, float octaves)
{
	return OpR1b_noise_fbm_int(noise,f,octaves,TCOD_noise_simplex);
}

float OpR1b_noise_fbm_wavelet(TCOD_noise_t noise, float *f, float octaves)
{
	return OpR1b_noise_fbm_int(noise,f,octaves,OpR1b_noise_wavelet);
}

//==================================================================
// noise sampler helper (partial layout)
//==================================================================

extern unsigned int opR1b_tickCount;	// NOTE: placeholder name (0xcaed20)
float opR1b_noiseResult_4012b0(float v);	// NOTE: placeholder name

struct OpR1b_Point
{
	int x;
	int y;
};

class OpR1b_NoiseField	// NOTE: placeholder name
{
public:
	void cleanup();	// 0x4215f0
	void init(int dimensions, float scale, int seed_);	// 0x421680
	float sample(OpR1b_Point *pos);	// 0x421770
	float sampleXY(int x, int y);	// 0x4217d0
	float sampleFbmXY(int x, int y);	// 0x421820
	float sampleFbm(OpR1b_Point *pos);	// 0x421880
	void update();	// 0x4218e0

	int				dimensions;
	TCODNoise		*noise;
	float			offset;
	float			scale;
	int				seed;
	unsigned int	startTick;
	float			*coords;
	int				octaves;
};

void OpR1b_NoiseField::cleanup()
{
	delete noise;
	delete [] coords;
}

void OpR1b_NoiseField::init(int dimensions_, float scale_, int seed_)
{
	TCODNoise *newNoise;
	cleanup();
	dimensions = dimensions_;
	newNoise = new TCODNoise(dimensions, TCOD_NOISE_DEFAULT);
	noise = newNoise;
	offset = rng.rangeFloat(0, 10.0f);
	scale = scale_;
	seed = seed_;
	startTick = opR1b_tickCount;
	coords = new float[dimensions];
}

float OpR1b_NoiseField::sample(OpR1b_Point *pos)
{
	coords[0] = pos->x + offset;
	coords[1] = pos->y + offset;
	return opR1b_noiseResult_4012b0(noise->get(coords, TCOD_NOISE_DEFAULT));
}

float OpR1b_NoiseField::sampleXY(int x, int y)
{
	coords[0] = x + offset;
	coords[1] = y + offset;
	return opR1b_noiseResult_4012b0(noise->get(coords, TCOD_NOISE_DEFAULT));
}

float OpR1b_NoiseField::sampleFbmXY(int x, int y)
{
	coords[0] = x + offset;
	coords[1] = y + offset;
	return opR1b_noiseResult_4012b0(noise->getFbm(coords, octaves, TCOD_NOISE_DEFAULT));
}

float OpR1b_NoiseField::sampleFbm(OpR1b_Point *pos)
{
	coords[0] = pos->x + offset;
	coords[1] = pos->y + offset;
	return opR1b_noiseResult_4012b0(noise->getFbm(coords, octaves, TCOD_NOISE_DEFAULT));
}

void OpR1b_NoiseField::update()
{
	if (opR1b_tickCount >= startTick)
	{
		offset += scale;
		startTick = opR1b_tickCount + seed;
	}
}

//==================================================================
// REX font set selection (partial layout)
//==================================================================

#include <vector>

class XFontData;
class XRoot;

struct OpR1b_VideoMode	// NOTE: placeholder name (XFont, 0x4c bytes)
{
	string name;
	int unknown1c;
	OpR1b_VideoMode *source;	// NOTE: placeholder name
	int unknown24;
	char pad28[0x4c - 0x28];
};

class OpR1b_FontSet	// NOTE: placeholder name
{
public:
	void generateAutoscaledAll();	// 0x431de0
	bool initAutoscaled(const string &name_, OpR1b_FontSet *base, int scale, int mode, int count);	// 0x4318d0

	string name;
	vector<OpR1b_VideoMode*> fonts;
	int unknown2c;	// NOTE: placeholder name
	int unknown30;	// NOTE: placeholder name
	bool unknown34;	// NOTE: placeholder name
	vector<int> unknown38;	// NOTE: placeholder name
	vector<int> unknown48;	// NOTE: placeholder name
	vector<int> unknown58;	// NOTE: placeholder name
	vector<int> unknown68;	// NOTE: placeholder name
	vector<int> unknown78;	// NOTE: placeholder name
};

extern void *screenSurface;	// NOTE: placeholder name (0xcefa80)
extern bool opR1b_flags[];	// NOTE: placeholder name (0xcefa74)

class REX
{
public:
	struct FontSetInfo	// NOTE: placeholder name (0x40 bytes)
	{
		int type;
		char data[0x3c];

		void unknown416960();	// NOTE: placeholder name
		void unknown416a60(int a, int b, int c, int d);	// NOTE: placeholder name
	};

	void setVideoMode();
	void unknown423f40(int index, bool flag);	// NOTE: placeholder name
	bool unknown424020(string *mode, bool flag);	// NOTE: placeholder name
	void unknown4240c0();	// NOTE: placeholder name
	void unknown424130();	// NOTE: placeholder name
	void unknown4241a0(int limit);	// NOTE: placeholder name
	void unknown425e10(int index, int a, int b, int c, int d);	// NOTE: placeholder name
	unsigned int unknown4272a0(int index);	// NOTE: placeholder name
	void unknown425bb0();	// NOTE: placeholder name
	OpR1b_VideoMode *unknown425d50(string *name, int a, int b);	// NOTE: placeholder name

	char pad0[0x20];
	int unknown20;	// NOTE: placeholder name
	char pad24[0x68 - 0x24];
	int unknown68;	// NOTE: placeholder name
	void *root;	// +0x6c, XRoot*
	char pad70[0x80 - 0x70];
	vector<unsigned int> unknown80;	// NOTE: placeholder name
	char pad90[0x9c - 0x90];
	vector<FontSetInfo> fontSets;	// +0x9c
	vector<OpR1b_VideoMode*> videoModes;	// +0xac, NOTE: placeholder name
	vector<OpR1b_FontSet*> fontSetList;	// +0xbc
	int currentFontSetIndex;	// +0xcc
	OpR1b_FontSet *currentFontSet;	// +0xd0
	char padd4[0xdc - 0xd4];
	void (*fontChangedCallback)(bool flag);	// +0xdc
	string modeA;	// +0xe0, NOTE: placeholder name
	int modeAIndex;	// +0xfc, NOTE: placeholder name
	string modeB;	// +0x100, NOTE: placeholder name
	int modeBIndex;	// +0x11c, NOTE: placeholder name
};

class XConsoleBlit	// NOTE: placeholder name
{
public:
	void blit(void *surface, int flag);	// 0x42a5b0
};

struct OpR1b_XFontNew	// NOTE: placeholder name (XFont constructor 0x416ad0)
{
	OpR1b_XFontNew(REX::FontSetInfo *info, OpR1b_VideoMode *font, OpR1b_VideoMode *source, int size);
	char pad[0x4c];
};
extern REX rex;	// 0xd223f0
void logMessage(string message);	// NOTE: placeholder name (0x404cb0)
void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
std::string intToString(int value);
bool opU1_checkFontSetFits(int cols, int rows, int mode, bool *removed);	// NOTE: placeholder name (0x42f530)

bool OpR1b_FontSet::initAutoscaled(const string &name_, OpR1b_FontSet *base, int scale, int mode, int count)
{
	name = name_;
	unknown34 = false;
	logMessage("[font set: " + name + "]");
	if (scale > 9)
	{
		logError("XFontSet::initAutoscaled()","Scaling beyond a factor of 9 not currently supported");
		return false;
	}
	unknown2c = base->unknown2c * scale;
	unknown30 = base->unknown30 * scale;
	if (!opU1_checkFontSetFits(unknown2c,unknown30,mode,&unknown34))
		return false;
	for (int i = 0; i < count; i++)
	{
		OpR1b_VideoMode *font = rex.unknown425d50(&base->fonts[i]->name,base->fonts[i]->unknown24 * scale,(int)&rex.fontSets[i]);
		if (font != NULL)
			fonts.push_back(font);
		else
		{
			rex.videoModes.push_back((OpR1b_VideoMode *)new OpR1b_XFontNew(&rex.fontSets[i],base->fonts[i],base->fonts[i]->source ? base->fonts[i]->source : base->fonts[i],base->fonts[i]->unknown24 * scale));
			fonts.push_back(rex.videoModes.back());
		}
		logMessage("..." + fonts.back()->name + " (*" + intToString(fonts.back()->unknown24) + ")");
	}
	unknown38 = base->unknown38;
	unknown48 = base->unknown48;
	unknown58 = base->unknown58;
	unknown68 = base->unknown68;
	unknown78 = base->unknown78;
	return true;
}

void REX::unknown423f40(int index, bool flag)
{
	if (index == currentFontSetIndex)
	{
		return;
	}
	currentFontSetIndex = index;
	currentFontSet = fontSetList[currentFontSetIndex];
	currentFontSet->generateAutoscaledAll();
	for (unsigned int i = 0; i < fontSets.size(); i++)
	{
		fontSets[i].unknown416960();
	}
	setVideoMode();
	((XConsoleBlit*)root)->blit(screenSurface,0);
	if (fontChangedCallback)
	{
		fontChangedCallback(flag);
	}
}

bool REX::unknown424020(string *mode, bool flag)
{
	for (unsigned int i = 0; i < fontSetList.size(); i++)
	{
		if (fontSetList[i]->name == *mode)
		{
			if (!fontSetList[i]->unknown34 || flag)
			{
				unknown423f40(i,flag);
				return true;
			}
		}
	}
	return false;
}

void REX::unknown4240c0()
{
	int index = currentFontSetIndex;
	do
	{
		if (index < fontSetList.size() - 1)
		{
			index++;
		}
		else
		{
			index = 0;
		}
	} while (fontSetList[index]->unknown34);
	unknown423f40(index,false);
}

void REX::unknown424130()
{
	int index = currentFontSetIndex;
	do
	{
		if (index != 0)
		{
			index--;
		}
		else
		{
			index = fontSetList.size() - 1;
		}
	} while (fontSetList[index]->unknown34);
	unknown423f40(index,false);
}

void REX::unknown4241a0(int limit)
{
	for (unsigned int i = 0; i < fontSetList.size(); i++)
	{
		if (fontSetList[i]->unknown30 < limit)
		{
			fontSetList[i]->unknown34 = true;
		}
	}
}

void REX::unknown425e10(int index, int a, int b, int c, int d)
{
	fontSets[index].unknown416a60(a,b,c,d);
}

unsigned int REX::unknown4272a0(int index)
{
	if (opR1b_flags[index])
	{
		if (opR1b_tickCount >= unknown80[index])
		{
			return opR1b_tickCount - unknown80[index];
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

//==================================================================
// string cleanup helper
//==================================================================

void OpR1b_stringUnknown_408ad0(string &text);	// NOTE: placeholder name (0x408ad0)
void opY3_replaceChar(string &text, char from, char to);	// NOTE: placeholder name (0x4081c0)
void OpR1b_stringUnknown_408100(string &text, char c);	// NOTE: placeholder name (0x408100)
void OpR1b_stringUnknown_408860(string &text, int a, int b, int c, int d);	// NOTE: placeholder name (0x408860)

void OpR1b_stringPrepare_424380(string &text, int c)	// NOTE: placeholder name
{
	if (text.empty())
	{
		return;
	}
	OpR1b_stringUnknown_408ad0(text);
	opY3_replaceChar(text,9,' ');
	OpR1b_stringUnknown_408100(text,'\n');
	OpR1b_stringUnknown_408860(text,' ','"',c,0);
}

void REX::unknown425bb0()
{
	for (unsigned int i = 0; i < fontSetList.size(); i++)
	{
		if (!fontSetList[i]->unknown34)
		{
			if (modeAIndex == -1 || (fontSetList[i]->unknown30 > fontSetList[modeAIndex]->unknown30 && fontSetList[i]->unknown30 * unknown68 < unknown20))
			{
				modeAIndex = i;
				modeA = fontSetList[modeAIndex]->name;
			}
			if ((modeBIndex == -1 || fontSetList[i]->unknown30 > fontSetList[modeBIndex]->unknown30) && fontSetList[i]->unknown30 * unknown68 <= unknown20)
			{
				modeBIndex = i;
				modeB = fontSetList[modeBIndex]->name;
			}
		}
	}
}

OpR1b_VideoMode *REX::unknown425d50(string *name, int a, int b)
{
	for (unsigned int i = 0; i < videoModes.size(); i++)
	{
		if (videoModes[i]->name == *name && videoModes[i]->unknown24 == a && videoModes[i]->unknown1c == b)
		{
			return videoModes[i];
		}
	}
	return NULL;
}

//==================================================================
// colored-string helpers (` toggles an escape span)
//==================================================================

// NOTE: placeholder name; counts characters outside of `...` spans
int OpR1b_countVisible(string &text, int pos, int end)
{
	int count = 0;
	while (pos < end)
	{
		if (text[pos] == '`')
		{
			pos++;
			while (pos < end && text[pos] != '`')
			{
				pos++;
			}
			pos++;
		}
		else
		{
			pos++;
			count++;
		}
	}
	return count;
}

// NOTE: placeholder name; advances past the given number of visible characters
int OpR1b_advanceVisible(string &text, int pos, int count)
{
	while (pos < text.size() && count > 0)
	{
		if (text[pos] == '`')
		{
			pos++;
			while (pos < text.size() && text[pos] != '`')
			{
				pos++;
			}
			pos++;
		}
		else
		{
			pos++;
			count--;
		}
	}
	return pos;
}

//==================================================================
// REX screenshot/resource name (partial)
//==================================================================

class XResourceMgr
{
public:
	bool fileExists(string path);	// NOTE: placeholder name
};
extern XResourceMgr *opR1b_resMgr;	// NOTE: placeholder name (0xcefa88)
void OpR1b_unknown_409240(string path);	// NOTE: placeholder name (0x409240)

class OpR1b_Screenshots	// NOTE: placeholder name
{
public:
	void setName(string name_);	// NOTE: placeholder name (0x4261f0)

	char pad0[0x150];
	string name;	// +0x150
};

void OpR1b_Screenshots::setName(string name_)
{
	if (name != name_ || !opR1b_resMgr->fileExists(name_))
	{
		name = name_;
		OpR1b_unknown_409240(name);
	}
}

//==================================================================
// screenshot capture
//==================================================================

std::string intToString(int value);
string &padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)
int OpR1a_savePngFile(void *target, string file, int arg);	// NOTE: placeholder name (0x414720)

struct OpR1b_SDL_Surface
{
	unsigned int flags;
	void *format;
	int w;
	int h;
};

struct OpR1b_SDL_Rect
{
	short x;
	short y;
	unsigned short w;
	unsigned short h;
};

extern "C" int SDL_UpperBlit(void *src, OpR1b_SDL_Rect *srcrect, void *dst, OpR1b_SDL_Rect *dstrect);
extern void *screenSurface;	// NOTE: placeholder name (0xcefa80)

class OpR1b_SurfaceWrapper	// NOTE: placeholder name (0x413d50 ctor, 0x413d80 dtor)
{
public:
	OpR1b_SDL_Surface *surface;

	OpR1b_SurfaceWrapper(int width, int height, bool flag);
	~OpR1b_SurfaceWrapper();
};

struct OpR1b_FontData	// NOTE: placeholder name
{
	char pad00[0x2c];
	int unknown2c;
	int unknown30;
};

class OpR1b_FontSetB	// NOTE: placeholder name
{
public:
	char pad00[0x1c];
	vector<OpR1b_FontData*> fonts;
};

class OpR1b_ScreenshotRex	// NOTE: placeholder name
{
public:
	void takeScreenshot();	// NOTE: placeholder name (0x425e50)

	int unknown00;
	int unknown04;
	char pad08[0x14 - 0x08];
	int unknown14;
	int unknown18;
	char pad1c[0x64 - 0x1c];
	int unknown64;
	int unknown68;
	char pad6c[0xd0 - 0x6c];
	OpR1b_FontSetB *fontSet;
	char padd4[0x144 - 0xd4];
	void (*nameCallback)(string *name);
	void (*savedCallback)(string *name);
	int unknown14c;
	string directory;	// +0x150
};

void OpR1b_ScreenshotRex::takeScreenshot()
{
	string filename;
	if (nameCallback)
	{
		nameCallback(&filename);
		filename += ".png";
	}
	else
	{
		int number = 0;
		do
		{
			string name = "screenshot";
			string numberString = intToString(number);
			padLeft(numberString,3,'0');
			name += numberString;
			name += ".png";
			if (opR1b_resMgr->fileExists(directory + name))
			{
				number++;
			}
			else
			{
				filename = name;
				break;
			}
		} while (filename.empty());
	}
	if (unknown00 == 0)
	{
		if (unknown04 == 1 && (unknown14 != 0 || unknown18 != 0))
		{
			OpR1b_SurfaceWrapper image(unknown64 * fontSet->fonts[0]->unknown2c,unknown68 * fontSet->fonts[0]->unknown30,false);
			OpR1b_SDL_Rect rect;
			rect.x = unknown14;
			rect.y = unknown18;
			rect.w = image.surface->w;
			rect.h = image.surface->h;
			SDL_UpperBlit(screenSurface,&rect,image.surface,NULL);
			OpR1a_savePngFile(image.surface,directory + filename,-1);
		}
		else
		{
			OpR1a_savePngFile(screenSurface,directory + filename,-1);
		}
	}
	if (savedCallback)
	{
		savedCallback(&(directory + filename));
	}
}

//==================================================================
// XConsole subconsole dispatch (placeholder class with XConsole's layout)
//==================================================================

struct OpR1b_Pos
{
	int x;
	int y;
};

struct OpR1b_Event	// NOTE: placeholder name
{
	int type;
	OpR1b_Pos mouse;
};

class OpR1b_Con	// NOTE: placeholder name
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual bool input(OpR1b_Event *event);
	virtual void v5();
	virtual void update();
	virtual void render();

	bool contains(const OpR1b_Pos &p);	// XConsole::contains
	void unknown_429f10(vector<OpR1b_Con*> *skip, bool flag);	// 0x429f10
	void unknown_429fe0(OpR1b_Con *parent, OpR1b_Pos *pos, bool flag);	// 0x429fe0
	bool unknown_input(OpR1b_Event *event);	// 0x429d00
	void unknown_update();	// 0x429e30
	void unknown_render();	// 0x429ea0

	OpR1b_Con *parent;	// +0x04
	char pad08[0x14 - 0x08];
	int font;	// +0x14
	char pad18[0x1c - 0x18];
	OpR1b_Pos pos;	// +0x1c
	char pad24[0x44 - 0x24];
	vector<OpR1b_Con*> subconsoles;
	char pad54[0x58 - 0x54];
	int layer;
};

bool OpR1b_vectorContains(vector<OpR1b_Con*> *v, OpR1b_Con *item);	// NOTE: placeholder name (0x9db330)

bool OpR1b_Con::unknown_input(OpR1b_Event *event)
{
	if (subconsoles.empty())
	{
		return false;
	}
	if (event->mouse.x == -10000)
	{
		for (int i = subconsoles.size() - 1; i >= 0; i--)
		{
			if (subconsoles[i]->input(event))
			{
				return true;
			}
		}
	}
	else
	{
		for (int j = subconsoles.size() - 1; j >= 0; j--)
		{
			if (subconsoles[j]->layer == 0 || subconsoles[j]->contains(event->mouse))
			{
				if (subconsoles[j]->input(event))
				{
					return true;
				}
			}
		}
	}
	return false;
}

void OpR1b_Con::unknown_update()
{
	if (subconsoles.empty())
	{
		return;
	}
	for (unsigned int i = 0; i < subconsoles.size(); i++)
	{
		subconsoles[i]->update();
	}
}

void OpR1b_Con::unknown_render()
{
	if (subconsoles.empty())
	{
		return;
	}
	for (unsigned int i = 0; i < subconsoles.size(); i++)
	{
		subconsoles[i]->render();
	}
}

void OpR1b_Con::unknown_429f10(vector<OpR1b_Con*> *skip, bool flag)
{
	if (!subconsoles.empty())
	{
		for (unsigned int i = 0; i < subconsoles.size(); i++)
		{
			if (subconsoles[i]->font == font)
			{
				if (skip == NULL || !OpR1b_vectorContains(skip,subconsoles[i]))
				{
					subconsoles[i]->unknown_429f10(skip,true);
				}
			}
		}
	}
	else if (flag)
	{
		unknown_429fe0(parent,&pos,false);
	}
}
