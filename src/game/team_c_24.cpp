// team_c_24: opC_initLayouts_4b6c40 (0x4b6c40): one-time setup of two XColor palettes and the per-slot point/value tables
// NOTE: function and global names are placeholders (globals carry the exe address)
#include <vector>
using namespace std;

struct XColor
{
	unsigned char r, g, b;
	XColor(const XColor &c);
	XColor &operator=(XColor c);
};

struct Point
{
	int x;
	int y;
	Point(int x_, int y_);
};

void OpW7_initColors();	// 0x4b6b20

extern vector< vector<Point> > layout_cf4d94;	// NOTE: placeholder name
extern vector< vector<int> > lists_cf670c;	// NOTE: placeholder name
extern vector< vector<int> > lists_d21f5c;	// NOTE: placeholder name
extern XColor color_d21e5c;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e5f;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e62;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e65;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e68;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e6b;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e6e;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e71;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e74;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e77;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e7a;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e7d;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e80;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e83;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e86;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e89;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d21e8c;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c37c;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c37f;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c382;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c385;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c388;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c38b;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c38e;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c391;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c394;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c397;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c39a;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c39d;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c3a0;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c3a3;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c3a6;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c3a9;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor color_d2c3ac;	// NOTE: placeholder name (element of a 17-entry palette)
extern XColor &ptr_cefdcc;	// NOTE: placeholder name
extern XColor &ptr_cf13fc;	// NOTE: placeholder name
extern XColor &ptr_cf6b24;	// NOTE: placeholder name
extern XColor &ptr_cf766c;	// NOTE: placeholder name
extern XColor &ptr_cfc174;	// NOTE: placeholder name
extern XColor &ptr_d0249c;	// NOTE: placeholder name
extern XColor &ptr_d20618;	// NOTE: placeholder name
extern XColor &ptr_d20b70;	// NOTE: placeholder name
extern XColor &ptr_d21b44;	// NOTE: placeholder name
extern XColor &ptr_d22130;	// NOTE: placeholder name
extern XColor &ptr_d227ac;	// NOTE: placeholder name
extern XColor &ptr_d22fcc;	// NOTE: placeholder name
extern XColor &ptr_d25f60;	// NOTE: placeholder name
extern XColor &ptr_d28fcc;	// NOTE: placeholder name
extern XColor &ptr_d2f170;	// NOTE: placeholder name
extern XColor &ptr_d316f4;	// NOTE: placeholder name
extern XColor &ptr_d32efc;	// NOTE: placeholder name
extern XColor &ptr_d338bc;	// NOTE: placeholder name
extern XColor &ptr_d338c8;	// NOTE: placeholder name
extern XColor &ptr_d35064;	// NOTE: placeholder name
extern XColor &ptr_d35bbc;	// NOTE: placeholder name
extern XColor &ptr_d38644;	// NOTE: placeholder name
extern XColor &ptr_d386c8;	// NOTE: placeholder name

void opC_initLayouts_4b6c40()	// NOTE: placeholder name
{
	if (!layout_cf4d94.empty())
		return;
	OpW7_initColors();
	color_d21e5c = ptr_d20b70;
	color_d21e5f = ptr_d21b44;
	color_d21e62 = ptr_d20618;
	color_d21e65 = ptr_d35bbc;
	color_d21e68 = ptr_d38644;
	color_d21e6b = ptr_d386c8;
	color_d21e6e = ptr_d25f60;
	color_d21e71 = ptr_d20618;
	color_d21e74 = ptr_d35064;
	color_d21e77 = ptr_d25f60;
	color_d21e7a = ptr_d38644;
	color_d21e7d = ptr_d0249c;
	color_d21e80 = ptr_d338bc;
	color_d21e83 = ptr_d25f60;
	color_d21e86 = ptr_d338bc;
	color_d21e89 = ptr_d22fcc;
	color_d21e8c = ptr_d28fcc;
	color_d2c37c = ptr_cfc174;
	color_d2c37f = ptr_d338c8;
	color_d2c382 = ptr_d35064;
	color_d2c385 = ptr_d22130;
	color_d2c388 = ptr_d32efc;
	color_d2c38b = ptr_d2f170;
	color_d2c38e = ptr_cf6b24;
	color_d2c391 = ptr_d35064;
	color_d2c394 = ptr_cefdcc;
	color_d2c397 = ptr_cf6b24;
	color_d2c39a = ptr_d32efc;
	color_d2c39d = ptr_cf766c;
	color_d2c3a0 = ptr_cf13fc;
	color_d2c3a3 = ptr_cf6b24;
	color_d2c3a6 = ptr_cf13fc;
	color_d2c3a9 = ptr_d316f4;
	color_d2c3ac = ptr_d227ac;
	layout_cf4d94.assign(17,vector<Point>());
	layout_cf4d94[0].push_back(Point(13,0));
	layout_cf4d94[1].push_back(Point(13,2));
	layout_cf4d94[2].push_back(Point(16,3));
	layout_cf4d94[3].push_back(Point(13,6));
	layout_cf4d94[4].push_back(Point(16,7));
	layout_cf4d94[5].push_back(Point(13,10));
	layout_cf4d94[6].push_back(Point(17,11));
	layout_cf4d94[7].push_back(Point(9,14));
	layout_cf4d94[7].push_back(Point(13,14));
	layout_cf4d94[8].push_back(Point(7,17));
	layout_cf4d94[9].push_back(Point(23,17));
	layout_cf4d94[10].push_back(Point(22,19));
	layout_cf4d94[11].push_back(Point(7,23));
	layout_cf4d94[11].push_back(Point(10,22));
	layout_cf4d94[11].push_back(Point(13,23));
	layout_cf4d94[11].push_back(Point(16,23));
	layout_cf4d94[11].push_back(Point(21,23));
	layout_cf4d94[11].push_back(Point(23,23));
	layout_cf4d94[12].push_back(Point(7,26));
	layout_cf4d94[13].push_back(Point(7,28));
	layout_cf4d94[14].push_back(Point(9,30));
	layout_cf4d94[15].push_back(Point(19,26));
	layout_cf4d94[16].push_back(Point(15,36));
	lists_cf670c.assign(17,vector<int>());
	lists_d21f5c.assign(17,vector<int>());
	lists_cf670c[0].push_back(0);
	lists_d21f5c[0].push_back(0);
	lists_cf670c[0].push_back(1);
	lists_d21f5c[0].push_back(60);
	lists_cf670c[0].push_back(2);
	lists_d21f5c[0].push_back(80);
	lists_cf670c[1].push_back(0);
	lists_d21f5c[1].push_back(0);
	lists_cf670c[1].push_back(1);
	lists_d21f5c[1].push_back(30);
	lists_cf670c[1].push_back(2);
	lists_d21f5c[1].push_back(50);
	lists_cf670c[2].push_back(0);
	lists_d21f5c[2].push_back(0);
	lists_cf670c[2].push_back(1);
	lists_d21f5c[2].push_back(20);
	lists_cf670c[2].push_back(2);
	lists_d21f5c[2].push_back(50);
	lists_cf670c[3].push_back(0);
	lists_d21f5c[3].push_back(0);
	lists_cf670c[3].push_back(1);
	lists_d21f5c[3].push_back(50);
	lists_cf670c[3].push_back(2);
	lists_d21f5c[3].push_back(70);
	lists_cf670c[3].push_back(1);
	lists_d21f5c[3].push_back(80);
	lists_cf670c[3].push_back(2);
	lists_d21f5c[3].push_back(90);
	lists_cf670c[4].push_back(0);
	lists_d21f5c[4].push_back(0);
	lists_cf670c[4].push_back(1);
	lists_d21f5c[4].push_back(40);
	lists_cf670c[4].push_back(2);
	lists_d21f5c[4].push_back(60);
	lists_cf670c[5].push_back(0);
	lists_d21f5c[5].push_back(0);
	lists_cf670c[5].push_back(1);
	lists_d21f5c[5].push_back(40);
	lists_cf670c[5].push_back(2);
	lists_d21f5c[5].push_back(60);
	lists_cf670c[6].push_back(0);
	lists_d21f5c[6].push_back(0);
	lists_cf670c[6].push_back(1);
	lists_d21f5c[6].push_back(10);
	lists_cf670c[6].push_back(2);
	lists_d21f5c[6].push_back(40);
	lists_cf670c[7].push_back(0);
	lists_d21f5c[7].push_back(0);
	lists_cf670c[7].push_back(1);
	lists_d21f5c[7].push_back(10);
	lists_cf670c[7].push_back(2);
	lists_d21f5c[7].push_back(30);
	lists_cf670c[8].push_back(2);
	lists_d21f5c[8].push_back(0);
	lists_cf670c[9].push_back(5);
	lists_d21f5c[9].push_back(0);
	lists_cf670c[9].push_back(6);
	lists_d21f5c[9].push_back(60);
	lists_cf670c[10].push_back(5);
	lists_d21f5c[10].push_back(0);
	lists_cf670c[10].push_back(6);
	lists_d21f5c[10].push_back(40);
	lists_cf670c[11].push_back(2);
	lists_d21f5c[11].push_back(0);
	lists_cf670c[11].push_back(3);
	lists_d21f5c[11].push_back(30);
	lists_cf670c[11].push_back(2);
	lists_d21f5c[11].push_back(50);
	lists_cf670c[11].push_back(4);
	lists_d21f5c[11].push_back(60);
	lists_cf670c[12].push_back(4);
	lists_d21f5c[12].push_back(0);
	lists_cf670c[13].push_back(7);
	lists_d21f5c[13].push_back(0);
	lists_cf670c[13].push_back(8);
	lists_d21f5c[13].push_back(10);
	lists_cf670c[13].push_back(4);
	lists_d21f5c[13].push_back(50);
	lists_cf670c[14].push_back(4);
	lists_d21f5c[14].push_back(0);
	lists_cf670c[15].push_back(9);
	lists_d21f5c[15].push_back(0);
	lists_cf670c[16].push_back(10);
	lists_d21f5c[16].push_back(0);
}
