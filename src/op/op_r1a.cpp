// op_r1a: functions in 0x409000-0x41ae40 (SDL/PNG surface loading helpers and friends)
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../util/rng.h"
#include <vector>
using namespace std;

struct SDL_RWops
{
	void *seek;
	int (*read)(SDL_RWops *context, void *ptr, int size, int maxnum);	// +0x08
	void *write;
	int (*close)(SDL_RWops *context);	// +0x10
};
struct SDL_Surface;

extern "C" SDL_Surface *SDL_CreateRGBSurface(unsigned int flags, int width, int height, int depth, unsigned int Rmask, unsigned int Gmask, unsigned int Bmask, unsigned int Amask);
extern "C" int SDL_SetAlpha(SDL_Surface *surface, unsigned int flag, unsigned char alpha);
extern "C" SDL_RWops *SDL_RWFromFile(const char *file, const char *mode);

extern unsigned int alphaRmask;	// NOTE: placeholder name (0xcaecdc)
extern unsigned int alphaGmask;	// NOTE: placeholder name (0xcaece0)
extern unsigned int alphaBmask;	// NOTE: placeholder name (0xcaece4)
extern unsigned int alphaAmask;	// NOTE: placeholder name (0xcaece8)
extern unsigned int opaqueRmask;	// NOTE: placeholder name (0xcaecec)
extern unsigned int opaqueGmask;	// NOTE: placeholder name (0xcaecf0)
extern unsigned int opaqueBmask;	// NOTE: placeholder name (0xcaecf4)
extern unsigned int opaqueAmask;	// NOTE: placeholder name (0xcefa70)

struct OpR1a_SurfaceSaver	// NOTE: placeholder name
{
	void *target;	// +0x00

	void save(string file);	// 0x413e00
};

int OpR1a_savePng(void *target, SDL_RWops *io, int arg);	// NOTE: placeholder name (0x413f60)
int OpR1a_savePngFile(void *target, string file, int arg);	// NOTE: placeholder name (0x414720)

SDL_Surface *OpR1a_createSurface(int width, int height, bool alpha)	// NOTE: placeholder name (0x413e80)
{
	SDL_Surface *surface;
	if (alpha)
	{
		surface = SDL_CreateRGBSurface(0x10000,width,height,32,alphaRmask,alphaGmask,alphaBmask,alphaAmask);
		SDL_SetAlpha(surface,0x10000,255);
	}
	else
	{
		surface = SDL_CreateRGBSurface(0,width,height,24,opaqueRmask,opaqueGmask,opaqueBmask,opaqueAmask);
	}
	return surface;
}

int OpR1a_savePngFile(void *target, string file, int arg)
{
	int r;
	SDL_RWops *io = SDL_RWFromFile(file.c_str(),"wb");
	if (io == NULL)
		return -1;

	r = OpR1a_savePng(target,io,arg);
	io->close(io);
	return r;
}

void OpR1a_SurfaceSaver::save(string file)
{
	OpR1a_savePngFile(target,file,-1);
}

//==================================================================
// SDL_gfx-style surface zoom (0x4147e0-0x414dd0)
//==================================================================
struct SDL_Color
{
	unsigned char r, g, b, unused;
};
struct SDL_Palette
{
	int ncolors;
	SDL_Color *colors;
};
struct SDL_PixelFormat
{
	SDL_Palette *palette;	// +0x00
	unsigned char BitsPerPixel;	// +0x04
	unsigned char BytesPerPixel;
	unsigned char Rloss, Gloss, Bloss, Aloss;
	unsigned char Rshift, Gshift, Bshift, Ashift;
	unsigned int Rmask;	// +0x10
	unsigned int Gmask;
	unsigned int Bmask;
	unsigned int Amask;
	unsigned int colorkey;	// +0x20
	unsigned char alpha;
};
struct SDL_Surface
{
	unsigned int flags;	// +0x00
	SDL_PixelFormat *format;	// +0x04
	int w;	// +0x08
	int h;	// +0x0c
	unsigned short pitch;	// +0x10
	void *pixels;	// +0x14
};

extern "C" int SDL_UpperBlit(SDL_Surface *src, void *srcrect, SDL_Surface *dst, void *dstrect);
extern "C" int SDL_LockSurface(SDL_Surface *surface);
extern "C" void SDL_UnlockSurface(SDL_Surface *surface);
extern "C" void SDL_FreeSurface(SDL_Surface *surface);
extern "C" int SDL_SetColorKey(SDL_Surface *surface, unsigned int flag, unsigned int key);

void OpR1a_zoomSurfaceSize(int width, int height, double zoomx, double zoomy, int *dstwidth, int *dstheight)	// NOTE: placeholder name (0x414a80)
{
	const float VALUE_LIMIT = 0.001f;
	if (zoomx < VALUE_LIMIT)
		zoomx = VALUE_LIMIT;
	if (zoomy < VALUE_LIMIT)
		zoomy = VALUE_LIMIT;

	*dstwidth = (int)(width * zoomx);
	*dstheight = (int)(height * zoomy);
	if (*dstwidth < 1)
		*dstwidth = 1;
	if (*dstheight < 1)
		*dstheight = 1;
}

int OpR1a_zoomSurfaceRGBA(SDL_Surface *src, SDL_Surface *dst)	// NOTE: placeholder name (0x414dd0)
{
	int srcWidth = src->w;
	int dstWidth = dst->w;
	int heightRatio = dst->h / src->h;
	int scaleX = dstWidth / srcWidth;
	unsigned int *srcPixels = (unsigned int *)src->pixels;
	unsigned int *dstPixels = (unsigned int *)dst->pixels;
	for (int y = 0; y < src->h; y++)
	{
		for (int x = 0; x < srcWidth; x++)
		{
			for (int dy = y * heightRatio, j = 0; j < heightRatio; dy++, j++)
			{
				for (int dx = x * scaleX, i = 0; i < scaleX; dx++, i++)
					dstPixels[dy * dstWidth + dx] = srcPixels[y * srcWidth + x];
			}
		}
	}
	return 0;
}

int OpR1a_zoomSurfaceY(SDL_Surface *src, SDL_Surface *dst, int flipx, int flipy)	// NOTE: placeholder name (0x414b00)
{
	unsigned int x, y, sx, sy, *sax, *say, *csax, *csay, csx, csy;
	unsigned char *sp, *dp, *csp;
	int dgap;

	sx = (unsigned int)(src->w * 65536.0 / dst->w);
	sy = (unsigned int)(src->h * 65536.0 / dst->h);

	sax = (unsigned int *)malloc(dst->w * sizeof(unsigned int));
	if (sax == NULL)
		return -1;
	say = (unsigned int *)malloc(dst->h * sizeof(unsigned int));
	if (say == NULL)
	{
		if (sax)
			free(sax);
		return -1;
	}

	csx = 0;
	csax = sax;
	for (x = 0; x < (unsigned int)dst->w; x++)
	{
		csx += sx;
		*csax = (csx >> 16);
		csx &= 0xffff;
		csax++;
	}
	csy = 0;
	csay = say;
	for (y = 0; y < (unsigned int)dst->h; y++)
	{
		csy += sy;
		*csay = (csy >> 16);
		csy &= 0xffff;
		csay++;
	}

	csx = 0;
	csax = sax;
	for (x = 0; x < (unsigned int)dst->w; x++)
	{
		csx += (*csax);
		csax++;
	}
	csy = 0;
	csay = say;
	for (y = 0; y < (unsigned int)dst->h; y++)
	{
		csy += (*csay);
		csay++;
	}

	sp = csp = (unsigned char *)src->pixels;
	dp = (unsigned char *)dst->pixels;
	dgap = dst->pitch - dst->w;

	csay = say;
	for (y = 0; y < (unsigned int)dst->h; y++)
	{
		csax = sax;
		sp = csp;
		for (x = 0; x < (unsigned int)dst->w; x++)
		{
			*dp = *sp;
			sp += (*csax);
			csax++;
			dp++;
		}
		csp += src->pitch * (*csay);
		csay++;
		dp += dgap;
	}

	free(sax);
	free(say);
	return 0;
}

SDL_Surface *OpR1a_zoomSurface(SDL_Surface *src, double zoomx, double zoomy, int smooth)	// NOTE: placeholder name (0x4147e0)
{
	SDL_Surface *rz_src;
	SDL_Surface *rz_dst;
	int dstwidth, dstheight;
	int is32bit;
	int i, src_converted;
	int flipx, flipy;

	if (src == NULL)
		return NULL;

	is32bit = (src->format->BitsPerPixel == 32);
	if ((is32bit) || (src->format->BitsPerPixel == 8))
	{
		rz_src = src;
		src_converted = 0;
	}
	else
	{
		rz_src = SDL_CreateRGBSurface(0,src->w,src->h,32,0x000000ff,0x0000ff00,0x00ff0000,0xff000000);
		SDL_UpperBlit(src,NULL,rz_src,NULL);
		src_converted = 1;
		is32bit = 1;
	}

	flipx = (zoomx < 0.0);
	if (flipx)
		zoomx = -zoomx;
	flipy = (zoomy < 0.0);
	if (flipy)
		zoomy = -zoomy;

	OpR1a_zoomSurfaceSize(rz_src->w,rz_src->h,zoomx,zoomy,&dstwidth,&dstheight);

	rz_dst = NULL;
	if (is32bit)
		rz_dst = SDL_CreateRGBSurface(0,dstwidth,dstheight,32,rz_src->format->Rmask,rz_src->format->Gmask,rz_src->format->Bmask,rz_src->format->Amask);
	else
		rz_dst = SDL_CreateRGBSurface(0,dstwidth,dstheight,8,0,0,0,0);

	SDL_LockSurface(rz_src);

	if (is32bit)
	{
		OpR1a_zoomSurfaceRGBA(rz_src,rz_dst);
		SDL_SetAlpha(rz_dst,0x10000,255);
	}
	else
	{
		for (i = 0; i < rz_src->format->palette->ncolors; i++)
			rz_dst->format->palette->colors[i] = rz_src->format->palette->colors[i];
		rz_dst->format->palette->ncolors = rz_src->format->palette->ncolors;

		OpR1a_zoomSurfaceY(rz_src,rz_dst,flipx,flipy);
		SDL_SetColorKey(rz_dst,0x5000,rz_src->format->colorkey);
	}

	SDL_UnlockSurface(rz_src);

	if (src_converted)
		SDL_FreeSurface(rz_src);

	return rz_dst;
}

//==================================================================
// Color tables (0x413990)
//==================================================================
struct XColor	// NOTE: placeholder name
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	void setHSV(float h, float s, float v);	// 0x4xxxxx (src/engine/xcolor.cpp)
};

extern XColor xcolors_d2cf08[230];	// NOTE: placeholder name
extern string gameStrings_cfbef0[];	// NOTE: placeholder name
void opR1a_discard404be0(string message);	// NOTE: placeholder name (0x404be0)

void initColorTables()	// NOTE: placeholder name
{
	static const float saturation[10] = {1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,0.8f,0.6f,0.4f,0.2f};
	static const float value[10] = {0.25f,0.4f,0.55f,0.7f,0.85f,1.0f,1.0f,1.0f,1.0f,1.0f};
	static const float satScale = 1.0f;
	static const float hue[21] = {0.0f,15.0f,30.0f,45.0f,60.0f,75.0f,90.0f,120.0f,150.0f,165.0f,180.0f,195.0f,210.0f,240.0f,255.0f,270.0f,285.0f,300.0f,315.0f,330.0f,345.0f};

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			((XColor (*)[10])xcolors_d2cf08)[i][j].setHSV(hue[i],saturation[j] * satScale,value[j]);
		}
		opR1a_discard404be0("..." + gameStrings_cfbef0[i]);
	}

	xcolors_d2cf08[210].setHSV(0.0f,0.0f,0.0f);
	xcolors_d2cf08[211].setHSV(0.0f,0.0f,0.1f);
	xcolors_d2cf08[212].setHSV(0.0f,0.0f,0.2f);
	xcolors_d2cf08[213].setHSV(0.0f,0.0f,0.3f);
	xcolors_d2cf08[214].setHSV(0.0f,0.0f,0.4f);
	xcolors_d2cf08[215].setHSV(0.0f,0.0f,0.5f);
	xcolors_d2cf08[216].setHSV(0.0f,0.0f,0.62f);
	xcolors_d2cf08[217].setHSV(0.0f,0.0f,0.75f);
	xcolors_d2cf08[218].setHSV(0.0f,0.0f,0.87f);
	xcolors_d2cf08[219].setHSV(0.0f,0.0f,1.0f);
	opR1a_discard404be0("..." + gameStrings_cfbef0[21]);

	xcolors_d2cf08[220].setHSV(0.0f,0.0f,0.0f);
	xcolors_d2cf08[221].setHSV(36.0f,0.5f,0.1f);
	xcolors_d2cf08[222].setHSV(36.0f,0.5f,0.2f);
	xcolors_d2cf08[223].setHSV(36.0f,0.5f,0.3f);
	xcolors_d2cf08[224].setHSV(36.0f,0.5f,0.4f);
	xcolors_d2cf08[225].setHSV(36.0f,0.5f,0.5f);
	xcolors_d2cf08[226].setHSV(35.0f,0.37f,0.62f);
	xcolors_d2cf08[227].setHSV(35.0f,0.25f,0.75f);
	xcolors_d2cf08[228].setHSV(35.0f,0.12f,0.87f);
	xcolors_d2cf08[229].setHSV(0.0f,0.0f,1.0f);
	opR1a_discard404be0("..." + gameStrings_cfbef0[22]);
}

//==================================================================
// 0x415ce0 record
//==================================================================
struct OpR1a_Record	// NOTE: placeholder name
{
	int id;	// +0x00
	string name;	// +0x04
	bool flag20;	// +0x20
	int value24;	// +0x24
	bool flag28;
	bool flag29;
	bool flag2a;
	bool flag2b;
	bool flag2c;
	bool flag2d;

	OpR1a_Record(int id_, string name_, bool flag20_, int value24_, bool flag28_, bool flag29_, bool flag2a_, bool flag2b_, bool flag2c_, bool flag2d_);
	OpR1a_Record(const OpR1a_Record &other);
	void setValues(int value24_, bool flag28_, bool flag29_, bool flag2a_);
};

OpR1a_Record::OpR1a_Record(int id_, string name_, bool flag20_, int value24_, bool flag28_, bool flag29_, bool flag2a_, bool flag2b_, bool flag2c_, bool flag2d_)
	: id	(id_)
	, name	(name_)
	, flag20	(flag20_)
	, value24	(value24_)
	, flag28	(flag28_)
	, flag29	(flag29_)
	, flag2a	(flag2a_)
	, flag2b	(flag2b_)
	, flag2c	(flag2c_)
	, flag2d	(flag2d_)
{
}

OpR1a_Record::OpR1a_Record(const OpR1a_Record &other)
	: id	(other.id)
	, name	(other.name)
	, flag20	(other.flag20)
	, value24	(other.value24)
	, flag28	(other.flag28)
	, flag29	(other.flag29)
	, flag2a	(other.flag2a)
	, flag2b	(other.flag2b)
	, flag2c	(other.flag2c)
	, flag2d	(other.flag2d)
{
}

void OpR1a_Record::setValues(int value24_, bool flag28_, bool flag29_, bool flag2a_)
{
	value24 = value24_;
	flag28 = flag28_;
	flag29 = flag29_;
	flag2a = flag2a_;
}

//==================================================================
// REX sound samples (0x418e60-0x4191f0)
//==================================================================
struct Mix_Chunk
{
	int allocated;	// +0x00
	unsigned char *abuf;	// +0x04
	unsigned int alen;	// +0x08
	unsigned char volume;	// +0x0c
};

extern "C" int Mix_QuerySpec(int *frequency, unsigned short *format, int *channels);
extern void *(*sdlAlloc)(unsigned int size);	// NOTE: placeholder name (0xd2f340)

void logFatal(string location, string message);	// NOTE: placeholder name (0x404fd0)

Mix_Chunk *OpR1a_sampleChangePitch(Mix_Chunk *input, double pitch)	// NOTE: placeholder name (0x418f50)
{
	short *inBuf;
	int size;
	int outLen;
	short *output;
	Mix_Chunk *outBuf;
	double step;
	int i;
	if (input->allocated != 1)
		logFatal("REX_SampleChangePitch()","Input sample not allocated");

	outBuf = (Mix_Chunk *)sdlAlloc(0x10);
	outBuf->allocated = 1;
	outBuf->alen = (int)((input->alen >> 2) / pitch) << 2;
	outBuf->abuf = (unsigned char *)sdlAlloc(outBuf->alen);
	outBuf->volume = input->volume;
	memset(outBuf->abuf,0,outBuf->alen);

	inBuf = (short *)input->abuf;
	output = (short *)outBuf->abuf;
	size = input->alen >> 2;
	outLen = outBuf->alen >> 2;
	i = 0;
	step = 0.0;
	for (; i < outLen && (int)step < size; step += pitch, i++)
	{
		for (int c = 0; c < 2; c++)
			output[i * 2 + c] = inBuf[(int)step * 2 + c];
	}
	return outBuf;
}

int OpR1a_sampleGetLength(Mix_Chunk *chunk, const string &name)	// NOTE: placeholder name (0x4190f0)
{
	unsigned int bytes = 0;
	unsigned int frames = 0;
	int frequency = 0;
	unsigned short format = 0;
	int channels = 0;
	if (Mix_QuerySpec(&frequency,&format,&channels))
	{
		bytes = chunk->alen / ((format & 0xff) / 8);
		frames = bytes / channels;
		return frames * 1000 / frequency;
	}
	else
	{
		logFatal("REX_SampleGetLength()","Unable to determine length of sound sample: " + name);
	}
	return 0;
}

class XResourceMgr
{
public:
	Mix_Chunk *getSoundFromFile(const string &path);	// NOTE: placeholder name (0x415b00)
};
extern XResourceMgr *resourceMgr;	// NOTE: placeholder name (0xcefa88)

struct OpR1a_SoundSample	// NOTE: placeholder name
{
	Mix_Chunk *chunk;	// +0x00
	int length;	// +0x04
	string name;	// +0x08

	OpR1a_SoundSample(const string &file);	// 0x4191f0
	OpR1a_SoundSample(Mix_Chunk *source, double pitch, const string &name_);	// 0x419290
};

OpR1a_SoundSample::OpR1a_SoundSample(const string &file)
{
	name = file;
	chunk = resourceMgr->getSoundFromFile(name);
	length = OpR1a_sampleGetLength(chunk,name);
}

OpR1a_SoundSample::OpR1a_SoundSample(Mix_Chunk *source, double pitch, const string &name_)
{
	name = name_;
	chunk = OpR1a_sampleChangePitch(source,pitch);
	length = OpR1a_sampleGetLength(chunk,name);
}

//==================================================================
// REX audio mixer (0x419360-0x41a840)
//==================================================================
extern "C" int SDL_Init(unsigned int flags);
extern "C" int Mix_OpenAudio(int frequency, unsigned short format, int channels, int chunksize);
extern "C" int Mix_AllocateChannels(int numchans);
extern "C" int Mix_Volume(int channel, int volume);
extern "C" const char *SDL_GetError(void);

extern unsigned int tickCount;	// NOTE: placeholder name (0xcaed20)
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)
void opR1a_removeAt9ce660(vector<OpR1a_SoundSample*> &v, int index);	// NOTE: placeholder name (0x9ce660)
void opR1a_eraseAt9ce6d0(vector<unsigned int> &v, unsigned int &i);	// NOTE: placeholder name (0x9ce6d0)

class OpR1a_AudioMixer	// NOTE: placeholder name
{
public:
	bool enabled;	// +0x00
	vector<OpR1a_SoundSample*> samples;	// +0x04
	int channelCount;	// +0x14
	int unknown18;	// +0x18
	int unknown1c;	// +0x1c
	int volume;	// +0x20
	vector<OpR1a_SoundSample*> channelSamples;	// +0x24
	vector<unsigned int> channelEnds;	// +0x34
	vector<unsigned int> unknown44;	// +0x44

	OpR1a_AudioMixer();	// 0x419360
	void clearFinished();	// 0x4194d0
	void setVolume(int percent);	// 0x419580
	int loadSound(string file);	// 0x4195c0
	int playSound(int index, int loops, double pitchVariance);	// 0x419680
	void setSoundVolume(int index, int percent);	// 0x419c10
	int reserveChannels(int count);	// 0x419c70
	int groupChannels(int from, int to, int tag);	// 0x419e70
	int playSoundGroup(int group, int index, int loops, int fade, double pitchVariance);	// 0x41a230
};

OpR1a_AudioMixer::OpR1a_AudioMixer()
	: enabled	(true)
	, channelCount	(16)
	, unknown18	(0)
	, unknown1c	(10)
	, volume	(128)
{
	SDL_Init(0x10);
	if (Mix_OpenAudio(22050,0x8010,2,2048) < 0)
	{
		logWarning("XAudio()",string("Mix_OpenAudio() failed to initialize") + SDL_GetError());
		enabled = false;
	}
	Mix_AllocateChannels(channelCount);
}

void OpR1a_AudioMixer::clearFinished()
{
	for (unsigned int i = 0; i < channelEnds.size(); i++)
	{
		if (tickCount > channelEnds[i])
		{
			opR1a_removeAt9ce660(channelSamples,i);
			opR1a_eraseAt9ce6d0(channelEnds,i);
		}
	}
}

void OpR1a_AudioMixer::setVolume(int percent)
{
	volume = (int)(percent / 10.0 * 128.0);
	Mix_Volume(-1,volume);
}

int OpR1a_AudioMixer::loadSound(string file)
{
	samples.push_back(new OpR1a_SoundSample(file));
	return samples.size() - 1;
}

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)
void logMessage(string location, string message);	// NOTE: placeholder name (0x404bf0)
string intToString(int value);

extern RNG rng;	// 0xd30908
extern "C" int Mix_PlayChannelTimed(int channel, Mix_Chunk *chunk, int loops, int ticks);
extern "C" int Mix_Playing(int channel);
extern "C" int Mix_FadeInChannelTimed(int channel, Mix_Chunk *chunk, int loops, int ms, int ticks);
extern "C" int Mix_GroupAvailable(int tag);
extern "C" int Mix_ReserveChannels(int num);
extern "C" int Mix_GroupChannels(int from, int to, int tag);
extern "C" int Mix_VolumeChunk(Mix_Chunk *chunk, int volume);

int OpR1a_AudioMixer::playSound(int index, int loops, double pitchVariance)
{
	bool success = false;
	int channel;
	if (pitchVariance != 0.0)
	{
		if (loops != 0)
		{
			logError("XAudio()::playSound()","Cannot apply random pitch to looped sound: \"" + samples[index]->name + "\"");
		}
		else
		{
			channelSamples.push_back(new OpR1a_SoundSample(samples[index]->chunk,rng.rangeFloat(1.0 - pitchVariance,1.0 + pitchVariance),samples[index]->name));
			channelEnds.push_back(tickCount + channelSamples.back()->length + 5000);
			channel = Mix_PlayChannelTimed(-1,channelSamples.back()->chunk,loops,-1);
			success = true;
		}
	}

	if (!success)
		channel = Mix_PlayChannelTimed(-1,samples[index]->chunk,loops,-1);

	if (channel < 0)
	{
		if (Mix_Playing(-1) == channelCount)
		{
			channelCount++;
			Mix_AllocateChannels(channelCount);
			logMessage("XAudio()::playSound()","No free channels to play sound \"" + samples[index]->name + "\", added another (->" + intToString(channelCount) + ")");
			channel = Mix_PlayChannelTimed(-1,samples[index]->chunk,loops,-1);
		}
		else
		{
			logWarning("XAudio()::playSound()","Failed to play sound \"" + samples[index]->name + "\"");
		}
	}

	if (channel >= 0)
		Mix_Volume(channel,volume);

	return channel;
}

int OpR1a_AudioMixer::playSoundGroup(int group, int index, int loops, int fade, double pitchVariance)
{
	int result = -1;
	int channel = Mix_GroupAvailable(group);
	if (channel == -1)
		return -1;

	bool done = false;
	if (pitchVariance != 0.0)
	{
		if (loops != 0)
		{
			logError("XAudio()::playSoundGroup()","Cannot apply random pitch to looped sound: \"" + samples[index]->name + "\"");
		}
		else
		{
			channelSamples.push_back(new OpR1a_SoundSample(samples[index]->chunk,rng.rangeFloat(1.0 - pitchVariance,1.0 + pitchVariance),samples[index]->name));
			channelEnds.push_back(tickCount + channelSamples.back()->length + 5000);
			result = fade != 0 ? Mix_FadeInChannelTimed(channel,channelSamples.back()->chunk,loops,fade,-1) : Mix_PlayChannelTimed(channel,channelSamples.back()->chunk,loops,-1);
			done = true;
		}
	}

	if (!done)
		result = fade != 0 ? Mix_FadeInChannelTimed(channel,samples[index]->chunk,loops,fade,-1) : Mix_PlayChannelTimed(channel,samples[index]->chunk,loops,-1);

	if (result < 0)
		logError("XAudio()::playSoundGroup()","Failed to play sound \"" + samples[index]->name + "\": " + SDL_GetError());
	else
		Mix_Volume(result,volume);

	return result;
}

int OpR1a_AudioMixer::reserveChannels(int count)
{
	if (count == unknown18)
		return unknown18;

	channelCount = count + 16;
	Mix_AllocateChannels(channelCount);
	unknown18 = Mix_ReserveChannels(count);
	if (unknown18 != count)
		logError("XAudio()::reserveChannels()","Attempted to reserve " + intToString(count) + " only reserved " + intToString(unknown18));

	return unknown18;
}

int OpR1a_AudioMixer::groupChannels(int from, int to, int tag)
{
	int grouped = Mix_GroupChannels(from,to,tag);
	if (grouped < to - from + 1)
		logError("XAudio()::groupChannels()","Attempted to assign groupTag " + intToString(tag) + " to channels " + intToString(from) + "-" + intToString(to) + ", but only " + intToString(grouped) + " were tagged");

	return grouped;
}

void OpR1a_AudioMixer::setSoundVolume(int index, int percent)
{
	Mix_VolumeChunk(samples[index]->chunk,(int)(percent / 100.0 * 128.0));
}

//==================================================================
// XMouse screen edge test (0x41a780)
//==================================================================
bool opR1a_between(int low, int value, int high);	// NOTE: placeholder name (0x9daf80)

class OpR1a_Mouse	// NOTE: placeholder name (object at 0xcefa94; same layout as XMouse)
{
public:
	int x;
	int y;
	char padding08[0x10 - 0x08];
	int mouseX;
	int mouseY;

	bool isOutsideMargin(int margin);	// NOTE: placeholder name (0x41a780)
};

extern SDL_Surface *screenSurface;	// NOTE: placeholder name (0xcefa80)

bool OpR1a_Mouse::isOutsideMargin(int margin)
{
	return !(opR1a_between(margin,mouseX,screenSurface->w - margin - 1) && opR1a_between(margin,mouseY,screenSurface->h - margin - 1));
}

//==================================================================
// System clipboard (0x41ad60)
//==================================================================
int opX1InitializeClipboardWindow();	// 0x41ac30

class OpR1a_SystemClipboard	// NOTE: placeholder name
{
public:
	bool initialized;	// +0x00

	OpR1a_SystemClipboard();	// 0x41ad60
};

OpR1a_SystemClipboard::OpR1a_SystemClipboard()
{
	if (opX1InitializeClipboardWindow() < 0)
	{
		logError("XSystemClipboard()","Init failed: " + string(SDL_GetError()));
		initialized = false;
	}
	else
		initialized = true;
}
