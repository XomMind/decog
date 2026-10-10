// team_c_02: dynamic initializers of Point / XColor / std container globals and reference copies
// NOTE: all names are placeholders (carry the exe data address)
#include <vector>
#include <string>
using namespace std;

struct Unknown3	// NOTE: placeholder name
{
	char pad[3];
};

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	XColor();
	XColor(int r_, int g_, int b_);
};

struct Point
{
	int x;
	int y;

	Point(int v);
	Point(int x_, int y_);
};

extern Unknown3&	ptr_cfe670;
extern XColor&	ptr_d20438;
extern XColor&	ptr_d204ac;
extern Unknown3&	ptr_d2c418;
extern Unknown3&	ptr_d2e7c4;

// vec_d2b4bc holds 3-byte elements: its exe destructor (0x9b3da0) calls the _Tidy at 0x9be310, which divides
// by 3. A private element type keeps the instance distinct from vector<unsigned int>, whose destructor other
// files pair with the 4-byte-element destructor (sharing it broke the ??__Fvec_d2b4bc row).
struct Elem3_d2b4bc { unsigned char r, g, b; };	// NOTE: placeholder name and layout (size 3 from the exe)
vector<Elem3_d2b4bc>	vec_d2b4bc;
XColor	color_cefd14(1, 1, 1);
vector<unsigned int>	vec_d20ae8;
string	str_d204b0;
string	str_d2d490;
string	str_d2d4d8;
vector<Point>	vec_d2d4f4;
vector<string>	vec_d2d4c8;
vector<Point>	vec_d2ed08;
vector<unsigned int>	vec_d2d480;
string	str_d37998;
Point	point_d2b4ec(0, 50);
Point	point_d1dafc(0, 1);
Point	point_d21948[38] = {
	Point(0, 0),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100),
	Point(50, 100)
};
Point	point_d2d1bc(4, 18);
Point	point_d2d348[38] = {
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(1, 2),
	Point(1, 1),
	Point(1, 2),
	Point(1, 1),
	Point(1, 1),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(1, 1),
	Point(2, 2),
	Point(2, 2),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(2, 2),
	Point(1, 1),
	Point(1, 1),
	Point(2, 2),
	Point(1, 1),
	Point(1, 1),
	Point(2, 2),
	Point(2, 2),
	Point(1, 1),
	Point(0, 0),
	Point(1, 1),
	Point(1, 1),
	Point(0, 0),
	Point(0, 0)
};
Point	point_d25874[3] = {
	Point(1, 4),
	Point(3, 7),
	Point(5, 9)
};
Point	point_d307c8(1, 9);
Point	point_d35888(2, 3);
Point	point_d223cc(20, 40);
Point	point_d1ecb4(100, 1000);
Point	point_d1d640[110] = {
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(3, 3),
	Point(2, 2),
	Point(2, 2),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(2, 2),
	Point(0, 0),
	Point(0, 0),
	Point(3, 4),
	Point(2, 3),
	Point(2, 3),
	Point(2, 3),
	Point(2, 3),
	Point(0, 0),
	Point(0, 0),
	Point(2, 2),
	Point(0, 0),
	Point(0, 0),
	Point(3, 4),
	Point(2, 3),
	Point(3, 3),
	Point(3, 3),
	Point(3, 3),
	Point(1, 1),
	Point(0, 0),
	Point(3, 3),
	Point(0, 0),
	Point(0, 0),
	Point(3, 4),
	Point(3, 3),
	Point(3, 4),
	Point(3, 4),
	Point(3, 4),
	Point(1, 1),
	Point(1, 1),
	Point(3, 4),
	Point(0, 0),
	Point(0, 0),
	Point(3, 4),
	Point(3, 4),
	Point(3, 4),
	Point(3, 4),
	Point(3, 4),
	Point(1, 2),
	Point(1, 1),
	Point(3, 4),
	Point(0, 0),
	Point(0, 0),
	Point(4, 5),
	Point(3, 4),
	Point(3, 5),
	Point(3, 4),
	Point(3, 4),
	Point(1, 2),
	Point(1, 2),
	Point(3, 4),
	Point(0, 0),
	Point(0, 0),
	Point(4, 5),
	Point(3, 4),
	Point(3, 4),
	Point(4, 4),
	Point(3, 4),
	Point(2, 2),
	Point(1, 2),
	Point(4, 4),
	Point(0, 0),
	Point(0, 0),
	Point(3, 5),
	Point(4, 4),
	Point(3, 5),
	Point(4, 4),
	Point(4, 4),
	Point(2, 2),
	Point(1, 2),
	Point(4, 4),
	Point(4, 5),
	Point(0, 0),
	Point(4, 5),
	Point(3, 5),
	Point(4, 4),
	Point(4, 4),
	Point(4, 4),
	Point(2, 2),
	Point(1, 2),
	Point(4, 4),
	Point(4, 5),
	Point(0, 0),
	Point(4, 6),
	Point(4, 5),
	Point(4, 5),
	Point(4, 4),
	Point(4, 4),
	Point(2, 2),
	Point(1, 2),
	Point(4, 4),
	Point(0, 0),
	Point(0, 0)
};
Point	point_d32cf4(0, 2);
Point	point_cfd300(3, 9);
Point	point_d33bd8(1, 3);
Point	point_d357a0[22] = {
	Point(50, 150),
	Point(50, 100),
	Point(60, 160),
	Point(50, 100),
	Point(70, 170),
	Point(50, 100),
	Point(80, 180),
	Point(50, 100),
	Point(90, 190),
	Point(50, 100),
	Point(100, 200),
	Point(50, 100),
	Point(100, 210),
	Point(50, 100),
	Point(100, 220),
	Point(50, 100),
	Point(100, 230),
	Point(50, 100),
	Point(100, 240),
	Point(50, 100),
	Point(100, 250),
	Point(50, 100)
};
Point	point_cf08f8[22] = {
	Point(0, 0),
	Point(0, 0),
	Point(1, 3),
	Point(0, 0),
	Point(1, 3),
	Point(0, 0),
	Point(2, 3),
	Point(1, 1),
	Point(2, 3),
	Point(1, 2),
	Point(3, 3),
	Point(1, 2),
	Point(3, 4),
	Point(1, 2),
	Point(3, 4),
	Point(2, 2),
	Point(4, 4),
	Point(2, 2),
	Point(4, 5),
	Point(2, 3),
	Point(4, 5),
	Point(2, 3)
};
Point	point_d35bc8(250, 400);
Point	surgicalPartySizes_d29310[22] = {
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(0, 0),
	Point(1, 1),
	Point(0, 0),
	Point(1, 1),
	Point(0, 0),
	Point(2, 2),
	Point(0, 0),
	Point(2, 2),
	Point(0, 0),
	Point(2, 3),
	Point(1, 1),
	Point(2, 3),
	Point(1, 2),
	Point(2, 3),
	Point(2, 2)
};
Point	interceptTrackerCounts_d387d8[11] = {
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 2),
	Point(1, 2),
	Point(2, 2),
	Point(2, 2)
};
Point	couplingPartySizes_cf0c90[11] = {
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1)
};
Point	point_d30348(20, 25);
Point	point_d21760(8, 10);
Point	point_cf1400[22] = {
	Point(0, 0),
	Point(0, 0),
	Point(1, 2),
	Point(0, 0),
	Point(1, 2),
	Point(0, 0),
	Point(2, 3),
	Point(1, 1),
	Point(2, 3),
	Point(1, 1),
	Point(2, 3),
	Point(1, 2),
	Point(2, 3),
	Point(1, 2),
	Point(3, 4),
	Point(2, 2),
	Point(3, 4),
	Point(2, 2),
	Point(3, 4),
	Point(2, 3),
	Point(3, 4),
	Point(2, 3)
};
Point	point_d30350(150, 300);
Point	point_cf39ec(500, 800);
Point	point_d22310(10, 15);
Point	point_d2f174(5, 10);
Point	point_cf1f30[6] = {
	Point(3, 10),
	Point(4, 9),
	Point(3, 10),
	Point(4, 10),
	Point(3, 10),
	Point(3, 10)
};
Point	point_d31508(10, 20);
Point	point_cf0468(50, 100);
Point	point_d1de88(75, 125);
Point	point_d2ec2c(0, 2);
XColor	color_d3296c(0, 0, 0);
XColor	colors_d01724[9];
XColor	colors_cf0e98[90];
Unknown3&	ptr_d25f70	= ptr_d2e7c4;
Unknown3&	ptr_d396f0	= ptr_d2c418;
Unknown3&	ptr_cefdd0	= ptr_cfe670;
Point	point_d2c464(3, 6);
Point	point_d395a4(20, 40);
Point	point_cfb688(3, 7);
Point	point_cf08e4(5, 20);
Point	point_d2e838(1, 3);
Point	point_d21b34(2, 8);
Point	point_d2c3f4(10, 95);
Point	point_d1e01c(10, 100);
Point	point_d2e20c(4, 4);
XColor	colors_d2ed1c[10];
XColor&	ptr_d316f8	= ptr_d20438;
Point	point_d1f384(1, 1);
Point	point_d38724(4, 12);
Point	point_cfc178(12, 24);
Point	point_d1619c(25, 150);
Point	point_d22258(1, 5);
Point	point_d28fd0(2, 5);
XColor	colors_cfc1c8[22];
Point	point_d2c3b0(20, 40);
Point	point_d22260(10, 15);
Point	point_d22268(4, 6);
Point	point_d305d8(15, 25);
Point	point_d38830(5, 10);
Point	point_d2191c(5, 10);
Point	point_d2f130(3, 4);
Point	point_cf4538(3, 5);
Point	point_d389d4(75, 100);
Point	point_d2ecf8(100, 150);
XColor&	ptr_d22fb8	= ptr_d204ac;
Point	point_d25dd8(10, 15);
Point	point_d389bc(1, 4);
Point	point_d21e40(1, 3);
Point	point_d3978c(5, 5);
Point	point_d221a8(2, 6);
Point	point_cf687c(4, 10);

Point	point_d2a688[38] = {
	Point(0),
	Point(0),
	Point(3, 6),
	Point(18, 28),
	Point(15, 25),
	Point(15, 25),
	Point(0),
	Point(0),
	Point(0),
	Point(3, 6),
	Point(0),
	Point(0),
	Point(0),
	Point(5, 7),
	Point(2, 4),
	Point(0),
	Point(0),
	Point(0),
	Point(0),
	Point(0),
	Point(0),
	Point(0),
	Point(0),
	Point(10, 15),
	Point(4, 6),
	Point(0),
	Point(0),
	Point(3, 6),
	Point(8, 12),
	Point(0),
	Point(3, 6),
	Point(3, 6),
	Point(3, 6),
	Point(8, 10),
	Point(8, 12),
	Point(0),
	Point(0),
	Point(0)
};
