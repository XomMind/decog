// cc_r2_31: dynamic initializers of the 230-element XColor array at 0xd2cf08, the global RNG
// (0xd30908), a Pos global, and reference globals bound to the first array elements.
// NOTE: placeholder names carry the exe data address.

using namespace std;

struct RNG
{
	RNG();
	~RNG();
};

struct Pos	// NOTE: placeholder layout
{
	int x;
	int y;

	Pos(int x_, int y_);
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
};

RNG		rng;
Pos		pos_cf08ec(2, 3);	// NOTE: placeholder name
XColor	xcolors_d2cf08[230];	// NOTE: placeholder name

XColor&	ptr_cf6ed4	= xcolors_d2cf08[0];
XColor&	ptr_d30424	= xcolors_d2cf08[1];
XColor&	ptr_d22130	= xcolors_d2cf08[2];
XColor&	ptr_d204ac	= xcolors_d2cf08[3];
XColor&	ptr_d2f34c	= xcolors_d2cf08[4];
XColor&	ptr_d35bbc	= xcolors_d2cf08[5];
XColor&	ptr_d37994	= xcolors_d2cf08[6];
XColor&	ptr_d388f0	= xcolors_d2cf08[7];
XColor&	ptr_d379fc	= xcolors_d2cf08[8];
XColor&	ptr_d2e234	= xcolors_d2cf08[9];
XColor&	ptr_d33ac4	= xcolors_d2cf08[10];
XColor&	ptr_d2061c	= xcolors_d2cf08[11];
XColor&	ptr_d1dae8	= xcolors_d2cf08[12];
XColor&	ptr_d29818	= xcolors_d2cf08[13];
XColor&	ptr_d2087c	= xcolors_d2cf08[14];
XColor&	ptr_d226e8	= xcolors_d2cf08[15];
XColor&	ptr_cf11c8	= xcolors_d2cf08[16];
XColor&	ptr_d29264	= xcolors_d2cf08[17];
XColor&	ptr_d1d63c	= xcolors_d2cf08[18];
XColor&	ptr_d2e61c	= xcolors_d2cf08[19];
XColor&	ptr_cfd4cc	= xcolors_d2cf08[20];
XColor&	ptr_d323c4	= xcolors_d2cf08[21];
XColor&	ptr_d338c8	= xcolors_d2cf08[22];
XColor&	ptr_cf27e8	= xcolors_d2cf08[23];
XColor&	ptr_d23094	= xcolors_d2cf08[24];
XColor&	ptr_d21b44	= xcolors_d2cf08[25];
XColor&	ptr_d230ec	= xcolors_d2cf08[26];
XColor&	ptr_d2544c	= xcolors_d2cf08[27];
XColor&	ptr_cefd64	= xcolors_d2cf08[28];
XColor&	ptr_d2976c	= xcolors_d2cf08[29];
XColor&	ptr_d32df8	= xcolors_d2cf08[30];
XColor&	ptr_d30824	= xcolors_d2cf08[31];
XColor&	ptr_cf766c	= xcolors_d2cf08[32];
XColor&	ptr_d29d68	= xcolors_d2cf08[33];
XColor&	ptr_d21b20	= xcolors_d2cf08[34];
XColor&	ptr_d0249c	= xcolors_d2cf08[35];
XColor&	ptr_cf1f28	= xcolors_d2cf08[36];
XColor&	ptr_cf13f8	= xcolors_d2cf08[37];
XColor&	ptr_d35b94	= xcolors_d2cf08[38];
XColor&	ptr_d1ecbc	= xcolors_d2cf08[39];
XColor&	ptr_cf44c4	= xcolors_d2cf08[40];
XColor&	ptr_d1d46c	= xcolors_d2cf08[41];
XColor&	ptr_cf13fc	= xcolors_d2cf08[42];
XColor&	ptr_d20438	= xcolors_d2cf08[43];
XColor&	ptr_cf281c	= xcolors_d2cf08[44];
