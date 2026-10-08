// team_a_24: IMG_SavePNG_RW (0x413f60), the public-domain SDL PNG writer (IMG_savepng.c) Cogmind bundles, matched
// against COGMIND.exe (Beta 17.1). libpng 1.2.40 and SDL 1.2 are imported from their DLLs.
#include <setjmp.h>
#include <stdlib.h>

typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned int Uint32;

struct SDL_Color { Uint8 r, g, b, unused; };
struct SDL_Palette { int ncolors; SDL_Color *colors; };
struct SDL_PixelFormat
{
	SDL_Palette *palette;
	Uint8 BitsPerPixel, BytesPerPixel;
	Uint8 Rloss, Gloss, Bloss, Aloss;
	Uint8 Rshift, Gshift, Bshift, Ashift;
	Uint32 Rmask, Gmask, Bmask, Amask;
	Uint32 colorkey;
	Uint8 alpha;
};
struct SDL_Surface
{
	Uint32 flags;
	SDL_PixelFormat *format;
	int w, h;
	Uint16 pitch;
	void *pixels;
	int offset;
};
struct SDL_RWops;
struct SDL_Rect;
#define SDL_SWSURFACE	0x00000000
#define SDL_SRCCOLORKEY	0x00001000
#define SDL_SRCALPHA	0x00010000
#define SDL_MUSTLOCK(surface) ((surface)->offset || (((surface)->flags & (0x00000001|0x00000004|0x00004000)) != 0))

extern "C" __declspec(dllimport) void SDL_SetError(const char *fmt, ...);
extern "C" __declspec(dllimport) SDL_Surface *SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
extern "C" __declspec(dllimport) int SDL_SetAlpha(SDL_Surface *surface, Uint32 flag, Uint8 alpha);
extern "C" __declspec(dllimport) int SDL_UpperBlit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
extern "C" __declspec(dllimport) void SDL_FreeSurface(SDL_Surface *surface);
extern "C" __declspec(dllimport) int SDL_LockSurface(SDL_Surface *surface);
extern "C" __declspec(dllimport) void SDL_UnlockSurface(SDL_Surface *surface);
#define SDL_BlitSurface SDL_UpperBlit

typedef unsigned char png_byte;
typedef struct png_color_struct { png_byte red, green, blue; } png_color;
typedef png_color *png_colorp;
typedef struct png_struct_def { jmp_buf jmpbuf; } png_struct;	// only the leading jmp_buf is used here
typedef png_struct *png_structp;
typedef struct png_info_struct png_info;
typedef png_info *png_infop;
typedef void (*png_rw_ptr)(png_structp, png_byte *, unsigned int);
typedef void (*png_flush_ptr)(png_structp);
#define PNG_LIBPNG_VER_STRING "1.2.40"
#define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_PALETTE 3
#define PNG_COLOR_TYPE_RGB_ALPHA 6
#define PNG_INTERLACE_NONE 0
#define PNG_COMPRESSION_TYPE_DEFAULT 0
#define PNG_FILTER_TYPE_DEFAULT 0
#define PNG_FILTER_NONE 0x08
#define Z_NO_COMPRESSION 0
#define Z_BEST_COMPRESSION 9
#define Z_DEFAULT_COMPRESSION (-1)

extern "C" __declspec(dllimport) png_structp png_create_write_struct(const char *user_png_ver, void *error_ptr, void *error_fn, void *warn_fn);
extern "C" __declspec(dllimport) png_infop png_create_info_struct(png_structp png_ptr);
extern "C" __declspec(dllimport) void png_set_write_fn(png_structp png_ptr, void *io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn);
extern "C" __declspec(dllimport) void png_set_filter(png_structp png_ptr, int method, int filters);
extern "C" __declspec(dllimport) void png_set_compression_level(png_structp png_ptr, int level);
extern "C" __declspec(dllimport) void png_set_IHDR(png_structp png_ptr, png_infop info_ptr, unsigned int width, unsigned int height, int bit_depth, int color_type, int interlace_method, int compression_method, int filter_method);
extern "C" __declspec(dllimport) void png_set_PLTE(png_structp png_ptr, png_infop info_ptr, png_colorp palette, int num_palette);
extern "C" __declspec(dllimport) void png_set_tRNS(png_structp png_ptr, png_infop info_ptr, png_byte *trans, int num_trans, void *trans_values);
extern "C" __declspec(dllimport) void png_write_info(png_structp png_ptr, png_infop info_ptr);
extern "C" __declspec(dllimport) void png_write_image(png_structp png_ptr, png_byte **image);
extern "C" __declspec(dllimport) void png_write_end(png_structp png_ptr, png_infop info_ptr);
extern "C" __declspec(dllimport) void png_destroy_write_struct(png_structp *png_ptr_ptr, png_infop *info_ptr_ptr);

void pngWriteData_413f20(void *png, unsigned char *data, unsigned int length);	// NOTE: placeholder name (team_a_18.cpp)

int IMG_SavePNG_RW(SDL_Surface *surf, SDL_RWops *src, int compression)
{
	png_structp png_ptr;
	png_infop info_ptr;
	SDL_PixelFormat *fmt=NULL;
	SDL_Surface *tempsurf=NULL;
	int ret,funky_format,used_alpha;
	unsigned int i,temp_alpha;
	png_colorp palette;
	Uint8 *palette_alpha=NULL;
	png_byte **row_pointers=NULL;
	png_ptr=NULL;info_ptr=NULL;palette=NULL;ret=-1;
	funky_format=0;

	if( !src || !surf) {
		goto savedone; /* Nothing to do. */
	}

	row_pointers=(png_byte **)malloc(surf->h * sizeof(png_byte*));
	if (!row_pointers) {
		SDL_SetError("Couldn't allocate memory for rowpointers");
		goto savedone;
	}

	png_ptr=png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL,NULL,NULL);
	if (!png_ptr){
		SDL_SetError("Couldn't allocate memory for PNG file");
		goto savedone;
	}
	info_ptr= png_create_info_struct(png_ptr);
	if (!info_ptr){
		SDL_SetError("Couldn't allocate image information for PNG file");
		goto savedone;
	}
	/* setup custom writer functions */
	png_set_write_fn(png_ptr,(void *)src,(png_rw_ptr)pngWriteData_413f20,NULL);

	if (setjmp(png_jmpbuf(png_ptr))){
		SDL_SetError("Unknown error writing PNG");
		goto savedone;
	}

	if(compression>Z_BEST_COMPRESSION)
		compression=Z_BEST_COMPRESSION;

	if(compression == Z_NO_COMPRESSION) // No compression
	{
		png_set_filter(png_ptr,0,PNG_FILTER_NONE);
		png_set_compression_level(png_ptr,Z_NO_COMPRESSION);
	}
	else if(compression<0) // Default compression
		png_set_compression_level(png_ptr,Z_DEFAULT_COMPRESSION);
	else
		png_set_compression_level(png_ptr,compression);

	fmt=surf->format;
	if(fmt->BitsPerPixel==8){ /* Paletted */
		png_set_IHDR(png_ptr,info_ptr,
			surf->w,surf->h,8,PNG_COLOR_TYPE_PALETTE,
			PNG_INTERLACE_NONE,PNG_COMPRESSION_TYPE_DEFAULT,
			PNG_FILTER_TYPE_DEFAULT);
		palette=(png_colorp) malloc(fmt->palette->ncolors * sizeof(png_color));
		if (!palette) {
			SDL_SetError("Couldn't create memory for palette");
			goto savedone;
		}
		for (i=0;i<fmt->palette->ncolors;i++) {
			palette[i].red=fmt->palette->colors[i].r;
			palette[i].green=fmt->palette->colors[i].g;
			palette[i].blue=fmt->palette->colors[i].b;
		}
		png_set_PLTE(png_ptr,info_ptr,palette,fmt->palette->ncolors);
		if (surf->flags&SDL_SRCCOLORKEY) {
			palette_alpha=(Uint8 *)malloc((fmt->colorkey+1)*sizeof(Uint8));
			if (!palette_alpha) {
				SDL_SetError("Couldn't create memory for palette transparency");
				goto savedone;
			}
			/* FIXME: memset? */
			for (i=0;i<(fmt->colorkey+1);i++) {
				palette_alpha[i]=255;
			}
			palette_alpha[fmt->colorkey]=0;
			png_set_tRNS(png_ptr,info_ptr,palette_alpha,fmt->colorkey+1,NULL);
		}
	}else{ /* Truecolor */
		if (fmt->Amask) {
			png_set_IHDR(png_ptr,info_ptr,
				surf->w,surf->h,8,PNG_COLOR_TYPE_RGB_ALPHA,
				PNG_INTERLACE_NONE,PNG_COMPRESSION_TYPE_DEFAULT,
				PNG_FILTER_TYPE_DEFAULT);
		} else {
			png_set_IHDR(png_ptr,info_ptr,
				surf->w,surf->h,8,PNG_COLOR_TYPE_RGB,
				PNG_INTERLACE_NONE,PNG_COMPRESSION_TYPE_DEFAULT,
				PNG_FILTER_TYPE_DEFAULT);
		}
	}
	png_write_info(png_ptr, info_ptr);

	if (fmt->BitsPerPixel==8) { /* Paletted */
		for(i=0;i<surf->h;i++){
			row_pointers[i]= ((png_byte*)surf->pixels) + i*surf->pitch;
		}
		if(SDL_MUSTLOCK(surf)){
			SDL_LockSurface(surf);
		}
		png_write_image(png_ptr, row_pointers);
		if(SDL_MUSTLOCK(surf)){
			SDL_UnlockSurface(surf);
		}
	}else{ /* Truecolor */
		if(fmt->BytesPerPixel==3){
			if(fmt->Amask){ /* check for 24 bit with alpha */
				funky_format=1;
			}else{
				/* Check for RGB/BGR/GBR/RBG/etc surfaces.*/
				if(fmt->Rmask!=0x0000FF
				|| fmt->Gmask!=0x00FF00
				|| fmt->Bmask!=0xFF0000){
					funky_format=1;
				}
			}
		}else if (fmt->BytesPerPixel==4){
			if (!fmt->Amask) { /* check for 32bit but no alpha */
				funky_format=1;
			}else{
				/* Check for ARGB/ABGR/GBAR/RABG/etc surfaces.*/
				if(fmt->Rmask!=0x000000FF
				|| fmt->Gmask!=0x0000FF00
				|| fmt->Bmask!=0x00FF0000
				|| fmt->Amask!=0xFF000000){
					funky_format=1;
				}
			}
		}else{ /* 555 or 565 16 bit color */
			funky_format=1;
		}
		if (funky_format) {
			/* Allocate non-funky format, and copy pixeldata in*/
			if(fmt->Amask){
				tempsurf = SDL_CreateRGBSurface(SDL_SWSURFACE, surf->w, surf->h, 24,
										0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
			}else{
				tempsurf = SDL_CreateRGBSurface(SDL_SWSURFACE, surf->w, surf->h, 24,
										0x0000ff, 0x00ff00, 0xff0000, 0x00000000);
			}
			if(!tempsurf){
				SDL_SetError("Couldn't allocate temp surface");
				goto savedone;
			}
			if(surf->flags&SDL_SRCALPHA){
				temp_alpha=fmt->alpha;
				used_alpha=1;
				SDL_SetAlpha(surf,0,255); /* Set for an opaque blit */
			}else{
				used_alpha=0;
			}
			if(SDL_BlitSurface(surf,NULL,tempsurf,NULL)!=0){
				SDL_SetError("Couldn't blit surface to temp surface");
				SDL_FreeSurface(tempsurf);
				goto savedone;
			}
			if (used_alpha) {
				SDL_SetAlpha(surf,SDL_SRCALPHA,(Uint8)temp_alpha); /* Restore alpha settings*/
			}
			for(i=0;i<tempsurf->h;i++){
				row_pointers[i]= ((png_byte*)tempsurf->pixels) + i*tempsurf->pitch;
			}
			if(SDL_MUSTLOCK(tempsurf)){
				SDL_LockSurface(tempsurf);
			}
			png_write_image(png_ptr, row_pointers);
			if(SDL_MUSTLOCK(tempsurf)){
				SDL_UnlockSurface(tempsurf);
			}
			SDL_FreeSurface(tempsurf);
		} else {
			for(i=0;i<surf->h;i++){
				row_pointers[i]= ((png_byte*)surf->pixels) + i*surf->pitch;
			}
			if(SDL_MUSTLOCK(surf)){
				SDL_LockSurface(surf);
			}
			png_write_image(png_ptr, row_pointers);
			if(SDL_MUSTLOCK(surf)){
				SDL_UnlockSurface(surf);
			}
		}
	}

	png_write_end(png_ptr, NULL);
	ret=0; /* got here, so nothing went wrong. YAY! */

savedone: /* clean up and return */
	png_destroy_write_struct(&png_ptr,&info_ptr);
	if (palette) {
		free(palette);
	}
	if (palette_alpha) {
		free(palette_alpha);
	}
	if (row_pointers) {
		free(row_pointers);
	}
	return ret;
}
