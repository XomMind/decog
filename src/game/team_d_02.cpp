// team_d_02: dynamic initializers of geometry globals (Point, Rect, Area, int/float pairs)
// NOTE: all global names are placeholders carrying the exe data address; types come from the
// constructor/destructor callees.
#include <vector>
#include <string>
using namespace std;

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;

	Point();
	Point(int v);
	Point(int x_, int y_);
};

struct Unknown40c7b0	// NOTE: placeholder name (two int pairs; constructor 0x40c7b0)
{
	int a[4];

	Unknown40c7b0(int a0, int a1, int b0, int b1);
};

struct Unknown40c490	// NOTE: placeholder name (float pair; constructor 0x40c490)
{
	float a;
	float b;

	Unknown40c490(float a_, float b_);
};

struct Rect	// NOTE: placeholder layout
{
	int x, y, width, height;

	Rect(int x_, int y_, int width_, int height_);
};

struct Unknown456980	// NOTE: placeholder name (constructor 0x456980)
{
	int a[4];

	Unknown456980();
};

struct Area	// NOTE: placeholder layout
{
	int a[4];

	Area();
};

Point	pt_cfd2dc(2, 4);
Point	pt_cf1694(10, 30);
Point	pts_d38434[6] =
{
	Point(3, 4),
	Point(2, 3),
	Point(3, 5),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1)
};
Point	pts_d37a00[8] =
{
	Point(3, 4),
	Point(2, 3),
	Point(2, 3),
	Point(2, 2),
	Point(2, 2),
	Point(3, 3),
	Point(2, 2),
	Point(2, 2)
};
Point	pt_cf39f8(10, 50);
Point	pt_cf2734(0, 3);
Point	pt_d2f128(0, 30);
Point	pt_d21b3c(7, 11);
Point	pt_d22fa0(40, 90);
Point	pt_d2e214(8, 12);
Point	pt_d1f38c(50, 125);
Point	pt_d2a4f4(1, 3);
Point	pt_d306a4(3, 6);
Point	pt_d035c8(1, 3);
Point	pt_d35bd0(1, 4);
Point	pt_d01d58(8, 12);
Point	pt_d2d478(-20, 50);
Point	pt_d2a7c8(15, 30);
Point	pt_d2ed3c(15, 30);
Point	pt_cf2000(20, 27);
Point	pt_cf11cc(20, 40);
Point	pt_d38424(35, 50);
Point	pt_cf1f1c(7, 13);
Point	pt_d2e21c(2, 3);
Point	pt_d2b4cc(50, 100);
Point	pt_d386b8(15, 75);
Point	pt_d30550(8, 12);
Point	pt_d35b7c(4, 6);
Point	pt_cf39cc(1, 3);
Point	pt_d31724(10, 20);
Point	pt_cfbed0(5, 10);
Point	pt_d01b40(5, 10);
Point	pt_d1e04c(3, 5);
Point	pt_cefcfc(5, 10);
Point	pts_d2c3b8[4] =
{
	Point(2, 2),
	Point(2, 3),
	Point(0, 0),
	Point(3, 4)
};
Point	pts_cf45b0[4] =
{
	Point(1, 2),
	Point(1, 2),
	Point(0, 0),
	Point(1, 2)
};
Point	pts_d35890[4] =
{
	Point(2, 3),
	Point(2, 3),
	Point(0, 0),
	Point(4, 7)
};
Point	pts_d33ad8[32] =
{
	Point(0, 10),
	Point(0, 10),
	Point(0, 10),
	Point(0, 10),
	Point(0, 10),
	Point(10, 20),
	Point(0, 15),
	Point(10, 40),
	Point(10, 25),
	Point(0, 10),
	Point(0, 10),
	Point(0, 10),
	Point(5, 15),
	Point(10, 20),
	Point(0, 0),
	Point(0, 0),
	Point(5, 10),
	Point(0, 0),
	Point(5, 15),
	Point(5, 15),
	Point(5, 15),
	Point(0, 20),
	Point(0, 20),
	Point(0, 0),
	Point(0, 10),
	Point(0, 10),
	Point(0, 15),
	Point(0, 10),
	Point(0, 10),
	Point(0, 10),
	Point(0, 10),
	Point(0, 0)
};
Point	pts_d20518[32] =
{
	Point(10, 25),
	Point(20, 35),
	Point(20, 35),
	Point(15, 30),
	Point(10, 25),
	Point(20, 30),
	Point(20, 35),
	Point(30, 70),
	Point(20, 35),
	Point(10, 25),
	Point(10, 25),
	Point(10, 25),
	Point(15, 35),
	Point(15, 35),
	Point(0, 0),
	Point(0, 0),
	Point(10, 25),
	Point(0, 0),
	Point(15, 40),
	Point(15, 40),
	Point(15, 40),
	Point(10, 40),
	Point(20, 50),
	Point(0, 0),
	Point(10, 40),
	Point(10, 40),
	Point(20, 60),
	Point(15, 40),
	Point(10, 30),
	Point(10, 30),
	Point(10, 30),
	Point(0, 0)
};
Point	pts_cf3a30[32] =
{
	Point(0, 99999),
	Point(1, 99999),
	Point(1, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(1, 99999),
	Point(0, 99999),
	Point(0, 100),
	Point(15, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(1, 99999),
	Point(0, 99999),
	Point(0, 100),
	Point(0, 4),
	Point(2, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(-150, 99999),
	Point(1, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(1, 99999),
	Point(-100, 99999),
	Point(-50, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(0, 99999),
	Point(0, 100)
};
Unknown40c7b0	unk_cfe12c(200, 600, 100, 300);
Unknown40c7b0	unk_d2e8e8(600, 900, 300, 450);
Unknown40c7b0	unk_d31b58(1000, 1400, 500, 700);
Unknown40c7b0	unk_d22580(800, 1200, 400, 600);
Unknown40c7b0	unk_d2ea20(1100, 1600, 550, 800);
Point	pt_cfd1dc(35, 75);
Point	pts_d221b4[6] =
{
	Point(3, 4),
	Point(2, 3),
	Point(3, 4),
	Point(2, 3),
	Point(2, 3),
	Point(2, 3)
};
Unknown40c7b0	unks_cf0fb8[10] =
{
	Unknown40c7b0(400, 600, 200, 300),
	Unknown40c7b0(100, 300, 50, 150),
	Unknown40c7b0(100, 300, 50, 150),
	Unknown40c7b0(400, 600, 200, 300),
	Unknown40c7b0(200, 400, 100, 200),
	Unknown40c7b0(300, 440, 150, 220),
	Unknown40c7b0(400, 600, 200, 300),
	Unknown40c7b0(0, 0, 0, 0),
	Unknown40c7b0(300, 440, 150, 220),
	Unknown40c7b0(0, 0, 0, 0)
};
Unknown40c7b0	unks_cf1f60[10] =
{
	Unknown40c7b0(0, 0, 0, 0),
	Unknown40c7b0(0, 0, 0, 0),
	Unknown40c7b0(300, 600, 150, 300),
	Unknown40c7b0(500, 800, 250, 400),
	Unknown40c7b0(400, 600, 200, 300),
	Unknown40c7b0(0, 0, 0, 0),
	Unknown40c7b0(300, 600, 150, 300),
	Unknown40c7b0(0, 0, 0, 0),
	Unknown40c7b0(0, 0, 0, 0),
	Unknown40c7b0(0, 0, 0, 0)
};
Point	pt_d32384(3, 3);
Unknown40c7b0	unk_d223d4(160, 350, 80, 175);
Unknown40c7b0	unk_cfc194(250, 500, 125, 250);
Point	pt_d01d50(20, 60);
Unknown40c7b0	unk_cf7658(20, 40, 10, 20);
Unknown40c7b0	unk_d35b38(150, 300, 75, 150);
Unknown40c7b0	unk_cf6ec4(150, 500, 75, 250);
Unknown40c7b0	unk_d305c8(80, 160, 40, 80);
Unknown40c7b0	unk_d1ed48(150, 500, 75, 250);
Unknown40c7b0	unk_cf34f8(8, 16, 4, 8);
Unknown40c7b0	unk_d396f4(30, 60, 15, 30);
Unknown40c7b0	unk_d20444(200, 300, 100, 150);
Unknown40c7b0	unk_cfc1b4(160, 240, 80, 120);
Point	pt_d2c650(8, 10);
Point	pt_d216e8(10, 20);
Point	pt_d2c374(15, 30);
Unknown40c7b0	unk_d1deec(200, 400, 100, 200);
Unknown40c7b0	unk_d29ad0(100, 200, 50, 100);
Point	pts_d395b0[8] =
{
	Point(1, 3),
	Point(75, 125),
	Point(1, 3),
	Point(25, 100),
	Point(1, 3),
	Point(50, 200),
	Point(10, 40),
	Point(3, 12)
};
Point	pt_d1e33c(250, 1000);
Point	pt_d20858(25, 35);
Point	pts_cf6b0c[3] =
{
	Point(1200, 1600),
	Point(1600, 2000),
	Point(5000, 5000)
};
Point	pt_cf1058(2, 1);
Point	pts_d015d8[8] =
{
	Point(0, -1),
	Point(1, -1),
	Point(1, 0),
	Point(1, 1),
	Point(0, 1),
	Point(-1, 1),
	Point(-1, 0),
	Point(-1, -1)
};
Unknown40c490	unk_d0183c(0.05000000074505806f, 0.20000000298023224f);
Unknown40c490	unk_d29724(0.0f, 0.019999999552965164f);
Point	pt_d20258(50, 150);
Point	pt_d1d614(3, 15);
Point	pt_d2c400(5, 10);
Point	pt_d3172c(25, 75);
Point	pt_d3861c(95, 100);
Rect	rect_cf4da4(90, 90, 20, 20);
Point	pt_d2a7d0(50, 100);
Point	pt_d35bd8(300, 800);
Point	pt_d30358(10, 12);
Point	pt_d1de90(4, 5);
Point	pt_d2f658(2, 2);
Point	pt_d2a4fc(2, 2);
Point	pt_d1f3b0(1, 2);
Unknown40c490	unks_cfbed8[3] =
{
	Unknown40c490(0.5f, 1.0f),
	Unknown40c490(0.6000000238418579f, 1.0f),
	Unknown40c490(0.75f, 1.0f)
};
Point	pt_d2f17c(2, 5);
Point	pt_d035d0(2, 30);
Point	pts_d03240[4] =
{
	Point(0, -1),
	Point(1, 0),
	Point(0, 1),
	Point(-1, 0)
};
Area	area_d35b84;
Point	pt_cfd420(-1);
Unknown456980	unk_d20cf4;
Point	pt_d2c43c(2, 5);
Point	pt_d02b5c(5, 25);
Point	pt_cf2814(5, 35);
Unknown40c490	unk_d2ed00(0.4000000059604645f, 0.75f);
Point	pts_d1dde0[21] =
{
	Point(2, 2),
	Point(3, 3),
	Point(1, 1),
	Point(3, 4),
	Point(2, 3),
	Point(1, 2),
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
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1),
	Point(1, 1)
};
Point	pt_d38624(2, 4);
Point	pt_cf76e0(1, 100);
Point	pt_d2588c(15, 30);
Point	pt_d26004(5, 10);
Point	pt_cf272c(3, 5);
Point	pt_cfcc6c(134, 31);
Point	pt_d3578c(144, 31);
Point	pt_cfbec0(4, 4);
Point	pt_d21754(3, 3);
Point	pt_d323bc(0, 10);
Point	pt_d204fc(22, 1);
Point	pt_d2284c(27, 1);
Point	pt_d39704(2, 33);
Point	pt_d37d40(3, 2);
Rect	rect_d22270(2, 2, 148, 2);
Rect	rects_d39584[2] =
{
	Rect(2, 5, 146, 1),
	Rect(2, 4, 146, 1)
};
Point	pts_d257f0[2] =
{
	Point(2, 8),
	Point(2, 5)
};
Rect	rect_cf67d0(2, 2, 47, 2);
Point	pts_cefd20[6] =
{
	Point(1, 0),
	Point(-1, 0),
	Point(0, -1),
	Point(0, 1),
	Point(0, -1),
	Point(0, 1)
};
Point	pt_d35794(15, 1);
Point	pt_d1d62c(10, 1);
Point	pt_d2e9c0(18, 1);
Point	pt_cfd2e4(3, 2);
Point	pt_d1e854(19, 2);
Point	pt_d29d98(8, 4);
Point	pt_d37d48(29, 4);
Point	pt_d25800(50, 4);
Point	pt_cf0c60(3, 5);
Point	pt_d35880(2, 1);
Point	pt_d384cc(2, 1);
Point	pt_cfd2c4(30, 4);
Point	pt_d31658(2, 2);
Point	pt_cfc21c(100, 500);
Point	pt_d25e80(51, 9);
Point	pt_cefd58(8000, 12000);
Point	pt_d31bf4(5, 10);
Point	pts_cfe610[12] =
{
	Point(0, 0),
	Point(0, 0),
	Point(0, 50),
	Point(250, 500),
	Point(500, 1000),
	Point(750, 2000),
	Point(750, 2500),
	Point(1000, 3000),
	Point(1000, 4000),
	Point(1000, 5000),
	Point(0, 0),
	Point(0, 0)
};
Point	pt_d3863c(5, 15);
Rect	rect_d21db0(17, 23, 34, 14);
Point	pt_d338c0(-11, -13);
Point	pt_d20ce8;
Point	pt_d0155c;
Point	pt_cf39d4(3, 2);
Point	pts_d25898[35] =
{
	Point(9700, 9999),
	Point(8400, 8500),
	Point(7900, 8100),
	Point(7800, 7920),
	Point(7450, 7600),
	Point(7100, 7400),
	Point(7000, 7200),
	Point(6900, 7100),
	Point(6600, 6700),
	Point(6500, 6650),
	Point(6000, 6100),
	Point(5875, 6025),
	Point(5600, 5900),
	Point(5500, 5650),
	Point(5400, 5525),
	Point(5000, 5200),
	Point(4200, 4400),
	Point(4000, 4225),
	Point(3900, 4025),
	Point(3600, 3800),
	Point(1800, 2000),
	Point(1200, 1300),
	Point(1200, 1300),
	Point(1100, 1300),
	Point(1100, 1200),
	Point(1100, 1200),
	Point(1000, 1200),
	Point(1000, 1200),
	Point(900, 1200),
	Point(900, 1200),
	Point(900, 1200),
	Point(800, 1200),
	Point(800, 1200),
	Point(700, 1200),
	Point(700, 1200)
};
Point	pt_d1d634(25, 50);
Point	pt_cefd70;
Point	pts_cfb870[17] =
{
	Point(28, 0),
	Point(2, 2),
	Point(28, 3),
	Point(2, 6),
	Point(28, 7),
	Point(2, 10),
	Point(28, 11),
	Point(28, 14),
	Point(2, 17),
	Point(28, 17),
	Point(28, 19),
	Point(2, 22),
	Point(2, 26),
	Point(0, 28),
	Point(-2, 30),
	Point(28, 26),
	Point(34, 36)
};
Area	area_d31b48;
Area	area_d2f118;
Area	area_d1da98;
Area	area_d21dc0;
Area	area_d22318;
Point	pt_d01b38(100, 800);
