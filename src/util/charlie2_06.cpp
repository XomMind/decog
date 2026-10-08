// GM::initialize (0x789c30): lays out the UI areas, creates the front-end consoles, maps REX glyph
// ranges, loads tutorial records, runs the user-data backup/metadata/update steps and installs the
// pathfinding callbacks.
// NOTE: placeholder names and layouts throughout (C2G*, c2g_<address>).
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

void logInfo(string location, string message);
void logInfo(string message);
void logMessage(string message);
string intToString(int v);
void *opY2_startNetworkThread(void *id, bool force, int (*fn)(void *), void *data);
void fontSetChanged(bool ignore);

class RNG
{
public:
	// NOTE: placeholder layout; declared 8 bytes short of the real 0x9d4 to offset VS2010's 16-byte padding
	// of the string buffers declared next to it (keeps the exe's ebp-0xe14 slot)
	int f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64, f65, f66, f67, f68, f69, f70, f71, f72, f73, f74, f75, f76, f77, f78, f79, f80, f81, f82, f83, f84, f85, f86, f87, f88, f89, f90, f91, f92, f93, f94, f95, f96, f97, f98, f99, f100, f101, f102, f103, f104, f105, f106, f107, f108, f109, f110, f111, f112, f113, f114, f115, f116, f117, f118, f119, f120, f121, f122, f123, f124, f125, f126, f127, f128, f129, f130, f131, f132, f133, f134, f135, f136, f137, f138, f139, f140, f141, f142, f143, f144, f145, f146, f147, f148, f149, f150, f151, f152, f153, f154, f155, f156, f157, f158, f159, f160, f161, f162, f163, f164, f165, f166, f167, f168, f169, f170, f171, f172, f173, f174, f175, f176, f177, f178, f179, f180, f181, f182, f183, f184, f185, f186, f187, f188, f189, f190, f191, f192, f193, f194, f195, f196, f197, f198, f199, f200, f201, f202, f203, f204, f205, f206, f207, f208, f209, f210, f211, f212, f213, f214, f215, f216, f217, f218, f219, f220, f221, f222, f223, f224, f225, f226, f227, f228, f229, f230, f231, f232, f233, f234, f235, f236, f237, f238, f239, f240, f241, f242, f243, f244, f245, f246, f247, f248, f249, f250, f251, f252, f253, f254, f255, f256, f257, f258, f259, f260, f261, f262, f263, f264, f265, f266, f267, f268, f269, f270, f271, f272, f273, f274, f275, f276, f277, f278, f279, f280, f281, f282, f283, f284, f285, f286, f287, f288, f289, f290, f291, f292, f293, f294, f295, f296, f297, f298, f299, f300, f301, f302, f303, f304, f305, f306, f307, f308, f309, f310, f311, f312, f313, f314, f315, f316, f317, f318, f319, f320, f321, f322, f323, f324, f325, f326, f327, f328, f329, f330, f331, f332, f333, f334, f335, f336, f337, f338, f339, f340, f341, f342, f343, f344, f345, f346, f347, f348, f349, f350, f351, f352, f353, f354, f355, f356, f357, f358, f359, f360, f361, f362, f363, f364, f365, f366, f367, f368, f369, f370, f371, f372, f373, f374, f375, f376, f377, f378, f379, f380, f381, f382, f383, f384, f385, f386, f387, f388, f389, f390, f391, f392, f393, f394, f395, f396, f397, f398, f399, f400, f401, f402, f403, f404, f405, f406, f407, f408, f409, f410, f411, f412, f413, f414, f415, f416, f417, f418, f419, f420, f421, f422, f423, f424, f425, f426, f427, f428, f429, f430, f431, f432, f433, f434, f435, f436, f437, f438, f439, f440, f441, f442, f443, f444, f445, f446, f447, f448, f449, f450, f451, f452, f453, f454, f455, f456, f457, f458, f459, f460, f461, f462, f463, f464, f465, f466, f467, f468, f469, f470, f471, f472, f473, f474, f475, f476, f477, f478, f479, f480, f481, f482, f483, f484, f485, f486, f487, f488, f489, f490, f491, f492, f493, f494, f495, f496, f497, f498, f499, f500, f501, f502, f503, f504, f505, f506, f507, f508, f509, f510, f511, f512, f513, f514, f515, f516, f517, f518, f519, f520, f521, f522, f523, f524, f525, f526, f527, f528, f529, f530, f531, f532, f533, f534, f535, f536, f537, f538, f539, f540, f541, f542, f543, f544, f545, f546, f547, f548, f549, f550, f551, f552, f553, f554, f555, f556, f557, f558, f559, f560, f561, f562, f563, f564, f565, f566, f567, f568, f569, f570, f571, f572, f573, f574, f575, f576, f577, f578, f579, f580, f581, f582, f583, f584, f585, f586, f587, f588, f589, f590, f591, f592, f593, f594, f595, f596, f597, f598, f599, f600, f601, f602, f603, f604, f605, f606, f607, f608, f609, f610, f611, f612, f613, f614, f615, f616, f617, f618, f619, f620, f621, f622, f623, f624, f625, f626;
	RNG();
	~RNG();
	int seed();
	int seed(int s);
	int rangeInt(float lo, float hi);
	int rangeInt406d70(float lo, float hi) throw();	// NOTE: private alias of RNG::rangeInt (nothrow region)
};
extern RNG rng;

struct C2GArea	// NOTE: placeholder (x, y, w, h)
{
	int x, y, w, h;
	C2GArea(int nx, int ny, int nw, int nh);
	void set40a840(int nx, int ny, int nw, int nh);
	void copy40a720(const C2GArea &o);
};
struct C2GPoint { int x, y; };
struct C2GPos { int x, y; C2GPos(int nx, int ny); C2GPos(const C2GPos &o) throw(); };
struct C2GColor { unsigned char r, g, b; C2GColor(const C2GColor &o); };
class C2GConsole	// NOTE: placeholder (XConsole)
{
public:
	void clear();
	void removeSubconsole(C2GConsole *child);
	void removeEmptyLayers();
};
class C2GDifficulty : public C2GConsole { public: int pad[0x1f]; C2GDifficulty(); };
class C2GTrailer : public C2GConsole { public: int pad[0x1d]; C2GTrailer(); };
class C2GRexpaint : public C2GConsole { public: int pad[0x1e]; C2GRexpaint(); };
class C2GTitle : public C2GConsole { public: int pad[0x1d]; C2GTitle(); };
class C2GIntro : public C2GConsole { public: int pad[0x25]; C2GIntro(); };
class C2G96cc30 : public C2GConsole { public: int pad[0x2d]; C2G96cc30(); };
class C2GProgress : public C2GConsole	// NOTE: placeholder (XStartupProgress, 0x80 bytes)
{
public:
	int pad[0x20];
	C2GProgress(C2GConsole *parent, int width, int height, int a, int b, C2GColor color, C2GPos pos);
	void addLine(const string &line, bool flag);
};
struct C2GCallback { int vtbl; };
struct C2GMoveCallback : C2GCallback { C2GMoveCallback() throw(); };
struct C2GPathCallback : C2GCallback { C2GPathCallback() throw(); };
struct C2GDesireCallback : C2GCallback { C2GDesireCallback() throw(); };
struct C2GMachineCallback : C2GCallback { C2GMachineCallback() throw(); };
struct C2GCaveCallback : C2GCallback { C2GCaveCallback() throw(); };
struct C2GCaveinCallback : C2GCallback { C2GCaveinCallback() throw(); };
struct C2GSubCallback : C2GCallback { C2GSubCallback() throw(); };
struct C2GSoundCallback : C2GCallback { C2GSoundCallback() throw(); };
class C2GRex	// NOTE: placeholder (REX at 0xd223f0)
{
public:
	int width418980();
	int height4189a0();
	C2GConsole *getHighlighter();
	void map425e10(int layer, int first, int last, int x, int y);
	void setFontCallback418ca0(void (*fn)(bool));
	void setFilenameCallback418da0(void *fn);
	void setSoundCallback(void *fn);
	void setName(string name);
	void renderRoot();
};
class C2GGz	// NOTE: placeholder (gzifstream; the third ctor argument is its virtual-base flag)
{			// NOTE: declared 0xb4 bytes, not the real 0xbc: VS2010 pads our string-temporary pool to 16 bytes
			// and the 8 bytes it gains here keep the exe's frame offsets (gz at ebp-0x2c4)
public:
	int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50, f54, f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c, f80, f84, f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac, fb0;
	C2GGz(const char *path, int mode, int vbase);
	~C2GGz();
	bool is_open();
	void close();
};
struct C2GRec7c { bool check(); };
struct C2GRec { char p00[8]; string name; char p24[0x7c - 0x24]; C2GRec7c f7c; };
struct C2GRecList { unsigned size() const; C2GRec *&operator[](unsigned i); };
struct C2GEntry { string name; char p1c[0x38 - 0x1c]; };
struct C2GIntVec { void assign(unsigned n, const int &v); int &operator[](unsigned i); };
struct C2GMeta { void unserialize(); void reset778500(); };
struct C2GConfig { void save(int a, int b); };
struct C2GLog { void end(int v); };
struct C2GMixer { void setVolume(int v); };
struct C2GWindow { void toggle1c(); void toggle1d(); };
struct C2GHook { void set(void *fn); };

class GM	// NOTE: placeholder layout
{
public:
	void loadDataset();
	void unknown78d700(int a, int b);
	bool initialize();
};

extern C2GArea c2g_d01a14, c2g_d30234, c2g_d316c4, c2g_d35dc8, c2g_cf4564, c2g_d358b0, c2g_cf4154, c2g_d39268,
	c2g_d01a24, c2g_d30244, c2g_d316d4, c2g_d35dd8, c2g_d01a34, c2g_d30254, c2g_d316e4, c2g_d35de8, c2g_d31680,
	c2g_d1ed58, c2g_cf75a0, c2g_d1e844, c2g_d2600c, c2g_d20b4c, c2g_cf27ec, c2g_d1e1c8, c2g_d38464, c2g_cfb78c,
	c2g_d35e08, c2g_d33be0, c2g_d01a04, c2g_d35b6c, c2g_d31690, c2g_d20464, c2g_cf0da8, c2g_d32e00, c2g_d32ebc,
	c2g_d22f7c, c2g_d2a88c, c2g_d21e48, c2g_d316b4, c2g_d3238c, c2g_d2975c;
extern int c2g_caf128, c2g_caf12c, c2g_cefab4, c2g_cefab8, c2g_cebd5c, c2g_cebd64, c2g_cefc94, c2g_cefc98;
extern bool c2g_d28e55, c2g_cefb2e, c2g_cefb2f, c2g_d28d08, c2g_d28d30, c2g_d28c8b, c2g_d28fc4, c2g_d28d05,
	c2g_cefacd, c2g_cefacc, c2g_cefc5c, c2g_cefc5d, c2g_d28cb0;
extern int c2g_d28c8c;
extern C2GRex c2g_d223f0;
extern C2GConsole *c2g_cec028, *c2g_cec02c, *c2g_cec030, *c2g_cec034;
extern int c2g_cec13c, c2g_cec140, c2g_cec144, c2g_cec148;
extern C2GProgress *c2g_cefa7c;
extern C2GColor *c2g_d2981c;
extern C2GIntVec c2g_d22590;
extern string c2g_cfd42c, c2g_d32f00[], c2g_d05ab4, c2g_d16318[], c2g_d25664;
extern C2GMixer *c2g_cefa90;
extern C2GHook *c2g_cefa8c;
extern C2GMeta c2g_d25628;
extern C2GRecList c2g_d257b0, c2g_d2d1c4;
extern C2GConfig c2g_d28c68;
extern C2GLog *c2g_cefa64;
extern C2GEntry c2g_d035f4[];
extern C2GCallback *c2g_cefc2c, *c2g_cefc30, *c2g_cefc34, *c2g_cefc38, *c2g_cefc3c, *c2g_cefc40, *c2g_cefc44,
	*c2g_cefc48;
extern C2GWindow *c2g_cefaa0;
extern const float c2g_c3703c;

void c2g_point4b33b0(C2GPoint *p);
int c2g_height4b34b0();
bool opr1c_hasPtr_cebd5c();
int c2g_halfDiff437190(int a, int b);
void c2g_readInt(C2GGz &in, int *v);	// NOTE: readBinary<int>
void c2g_readString(C2GGz &in, string &s);
int c2g_findStringIndex(const string *list, unsigned n, string s);
void c2g_initColors434140();
void c2g_initColors4704b0();
void c2g_init45f9e0();
void c2g_initDice433d80();
void opY3_makeFilename(string &filename);
void playSound_4fd9c0();
void opr4a_unknown789a70();
void c2g_backup466a20();
string c2g_rotateText(const string &s);
int c2g_hashSeed(string &s);
bool c2g_find9d7a40(C2GRecList &list, string &name, C2GRec *&out);
void c2g_decode4712a0(string &s);
int OpC_newsThread_470fb0(void *data);

extern const char c2g_bf6d44[], c2g_bf6d58[], c2g_bf6d6c[], c2g_bf6d84[], c2g_bf6d98[], c2g_bf6dac[], c2g_bf6dc0[],
	c2g_bf6de4[], c2g_bf6ddc[], c2g_bf6e14[], c2g_bf6e0c[], c2g_bf6e1c[], c2g_bf6dec[], c2g_bf6e2c[], c2g_bf6e20[],
	c2g_bf6e34[], c2g_bf6e3c[], c2g_bf6e4c[], c2g_bf6e54[], c2g_bf6e80[], c2g_bf6e8c[], c2g_bf6edc[], c2g_bf6ea4[],
	c2g_bf6ee8[], c2g_bf6ef0[], c2g_bf6f18[], c2g_bf6f40[];

bool GM::initialize()
{
	logInfo(c2g_bf6d58, c2g_bf6d44);
	rng.seed();
	c2g_d01a14.set40a840(0, c2g_cebd5c != 2 ? 0 : -9, c2g_caf128 / 2 * c2g_cefab4, 10);
	c2g_d30234.set40a840(1, 2, c2g_d01a14.w - 2, 6);
	c2g_cebd64 = c2g_d30234.w;
	c2g_d316c4.set40a840(1, 1, c2g_d01a14.w - 2, 1);
	c2g_d35dc8.set40a840(1, c2g_d01a14.h - 2, c2g_d01a14.w - 2, 1);
	c2g_cf4564.set40a840(0, 0, c2g_caf128 / 2 * c2g_cefab4, c2g_d223f0.height4189a0());
	c2g_d358b0.set40a840(1, 2, c2g_cf4564.w - 2, c2g_cf4564.h - 4);
	c2g_cf4154.copy40a720(c2g_d316c4);
	c2g_d39268.set40a840(1, c2g_cf4564.h - 2, c2g_cf4564.w - 2, 1);
	c2g_d01a24.set40a840(c2g_d01a14.w, c2g_d01a14.y, c2g_caf128 / 2 * c2g_cefab4, 10);
	c2g_d30244.set40a840(1, 2, c2g_d01a24.w - 2, 6);
	c2g_d316d4.set40a840(1, 1, c2g_d01a24.w - 2, 1);
	c2g_d35dd8.set40a840(1, c2g_d01a24.h - 2, c2g_d01a24.w - 2, 1);
	c2g_d01a34.copy40a720(c2g_d01a24);
	c2g_d30254.copy40a720(c2g_d30244);
	c2g_d316e4.copy40a720(c2g_d316d4);
	c2g_d35de8.copy40a720(c2g_d35dd8);
	c2g_d31680.copy40a720(c2g_d01a24);
	c2g_d1ed58.copy40a720(c2g_d316d4);
	c2g_cf75a0.copy40a720(c2g_d35dd8);
	c2g_d1e844.copy40a720(c2g_d01a24);
	c2g_d2600c.copy40a720(c2g_d316d4);
	c2g_d20b4c.copy40a720(c2g_d35dd8);
	c2g_cf27ec.set40a840(0, c2g_cebd5c == 2 ? 1 : 10, c2g_cefab4, c2g_cefab8);
	c2g_d1e1c8.set40a840(0, c2g_d01a14.y + c2g_d01a14.h, c2g_cf27ec.w * c2g_caf128, 1);
	c2g_d38464.set40a840(c2g_cf27ec.w * c2g_caf128, 0, 0x3c, c2g_cebd5c == 0 ? 10 : 9);
	c2g_cfb78c.set40a840(c2g_cf27ec.w * c2g_caf128, c2g_d38464.h, 0x1e, 4);
	c2g_d35e08.set40a840(c2g_cf27ec.w * c2g_caf128 + 0x1e, c2g_d38464.h, 0x1e, 4);
	C2GPoint pt;
	c2g_point4b33b0(&pt);
	c2g_d33be0.set40a840(pt.x, pt.y, 0x3c, 0xe);
	c2g_d01a04.copy40a720(C2GArea(1, 1, c2g_d33be0.w - 2, 1));
	c2g_d35b6c.copy40a720(C2GArea(1, c2g_d33be0.h - 2, c2g_d33be0.w - 2, 1));
	c2g_d31690.set40a840(c2g_cf27ec.w * c2g_caf128, c2g_cfb78c.y + c2g_cfb78c.h, 0x3c, c2g_height4b34b0());
	c2g_d20464.set40a840(0, opr1c_hasPtr_cebd5c() ? 0 : c2g_cf27ec.y, 0x32,
		opr1c_hasPtr_cebd5c() ? c2g_d223f0.height4189a0() : c2g_cf27ec.h * c2g_caf12c);
	c2g_cf0da8.set40a840(c2g_cf27ec.w * c2g_caf128 - 0x32, c2g_d20464.y, 0x32, c2g_d20464.h);
	c2g_d32e00.set40a840(c2g_cf0da8.x - 10, (c2g_cf0da8.h < 0x32 ? 6 : 16) + c2g_cf0da8.y, 0xc, 0x1d);
	c2g_d32ebc.set40a840(c2g_halfDiff437190(c2g_cf0da8.w, c2g_d223f0.width418980()),
		c2g_halfDiff437190(c2g_cf0da8.h, c2g_d223f0.height4189a0()), c2g_cf0da8.w, c2g_cf0da8.h);
	c2g_d22f7c.set40a840(c2g_d32ebc.x - 10, (c2g_cf0da8.h < 0x32 ? 6 : 16) + c2g_d32ebc.y, 0xc, 0x1d);
	c2g_d2a88c.set40a840(c2g_cf27ec.w * c2g_caf128 - 100, c2g_d20464.y, 0x32, c2g_d20464.h);
	c2g_d21e48.set40a840(c2g_cf27ec.w * c2g_caf128 - 0x32, c2g_d20464.y, 0x32, 9);
	c2g_d316b4.set40a840(c2g_cf27ec.w * c2g_caf128 - 0x32, c2g_d20464.y, 0x32, c2g_d20464.h);
	c2g_d3238c.set40a840(0, opr1c_hasPtr_cebd5c() ? 0 : c2g_cf27ec.y, c2g_caf128 / 2 * c2g_cf27ec.w, c2g_d20464.h);
	c2g_d2975c.set40a840(0x19, 0x18, 0x1e, 0xc);
	c2g_cefc94 = c2g_d223f0.height4189a0() - c2g_d33be0.h - c2g_cfb78c.h - c2g_d38464.h - 2 - (c2g_d28e55 ? 0 : 4);
	c2g_cefc98 = c2g_cefc94 - (c2g_d28e55 ? 4 : 0);
	logMessage(c2g_bf6d6c);
	c2g_cec028 = new C2GDifficulty;
	c2g_cec02c = c2g_cefb2e ? (C2GConsole *)new C2GTrailer : c2g_cefb2f ? (C2GConsole *)new C2GRexpaint : (C2GConsole *)new C2GTitle;
	c2g_cec030 = c2g_d28d08 ? new C2GIntro : 0;
	c2g_cec034 = new C2G96cc30;
	c2g_cec13c = 0;
	c2g_cec140 = 0;
	c2g_cec144 = 0;
	c2g_cec148 = 0;
	c2g_cefa7c = new C2GProgress(c2g_d223f0.getHighlighter(), c2g_d223f0.width418980(), c2g_d223f0.height4189a0(), 0, 0,
		*c2g_d2981c, C2GPos(5, 0xc));
	c2g_cefa7c->addLine(c2g_bf6d84, true);
	logMessage(c2g_bf6d98);
	for (int i = 0; i < 4; i++)
	{
		c2g_d223f0.map425e10(i, 0x80, 0x8b, 0, 4);
		c2g_d223f0.map425e10(i, 0x8c, 0x97, 0xc, 4);
		c2g_d223f0.map425e10(i, 0x98, 0xa9, 0, 5);
		c2g_d223f0.map425e10(i, 0xaa, 0xae, 0x12, 5);
		c2g_d223f0.map425e10(i, 0xaf, 0xb1, 0xb, 1);
		c2g_d223f0.map425e10(i, 0xb2, 0xb3, 0x1e, 2);
	}
	for (int layer = 2; layer <= 3; layer++)
	{
		c2g_d223f0.map425e10(layer, 0xb4, 0xbf, 0, 6);
		c2g_d223f0.map425e10(layer, 0xc0, 0xcb, 0xc, 6);
		c2g_d223f0.map425e10(layer, 0xcc, 0xdd, 0, 7);
		c2g_d223f0.map425e10(layer, 0xde, 0xe2, 0x12, 7);
		for (int row = 9, start = 0xe3; start < 0x263; row++, start += 0x20)
			c2g_d223f0.map425e10(layer, start, start + 0x1f, 0, row);
	}
	c2g_d223f0.map425e10(4, 0, 0xff, 0, 0);
	c2g_d223f0.map425e10(5, 0, 0xff, 0, 0);
	c2g_d22590.assign(0x57, 0);
	c2g_cefa7c->addLine(c2g_bf6dac, true);
	logMessage(c2g_bf6dc0);
	C2GGz it((c2g_cfd42c + c2g_bf6de4 + c2g_bf6ddc).c_str(), 0x20, 1);
	if (!it.is_open())
		logMessage(c2g_bf6e1c + (c2g_cfd42c + c2g_bf6e14 + c2g_bf6e0c) + c2g_bf6dec);
	else
	{
		int count;
		int value;
		int index;
		c2g_readInt(it, &count);
		for (int j = 0; j < count; j++)
		{
			string name;
			c2g_readString(it, name);
			c2g_readInt(it, &value);
			if (value != 0)
			{
				index = c2g_findStringIndex(c2g_d32f00, 0x57, name);
				if (index != -1)
					c2g_d22590[index] = value;
			}
		}
		it.close();
	}
	remove((c2g_cfd42c + c2g_bf6e2c + c2g_bf6e20).c_str());
	c2g_cefa7c->addLine(c2g_bf6e34, true);
	c2g_initColors434140();
	c2g_initColors4704b0();
	c2g_init45f9e0();
	loadDataset();
	if (c2g_d28d30)
	{
		c2g_d28d30 = false;
		unknown78d700(0, 0);
	}
	c2g_initDice433d80();
	if (c2g_d28c8b)
		c2g_cefa90->setVolume(0);
	else
		c2g_cefa90->setVolume(c2g_d28c8c);
	c2g_d223f0.setFontCallback418ca0(fontSetChanged);
	c2g_d223f0.setFilenameCallback418da0((void *)opY3_makeFilename);
	c2g_d223f0.setSoundCallback((void *)playSound_4fd9c0);
	c2g_d223f0.setName(c2g_cfd42c + c2g_bf6e3c);
	c2g_cefa8c->set((void *)opr4a_unknown789a70);
	c2g_cefa7c->addLine(c2g_bf6e4c, true);
	c2g_backup466a20();
	ifstream input(c2g_rotateText(c2g_bf6e54).c_str());
	if (input.is_open())
	{
		string line;
		while (getline(input, line))
		{
			if (line.size() >= 1000)
			{
				string data = line;
				string front(data.begin(), data.begin() + 7);
				int id = c2g_hashSeed(front);
				RNG pool;
				pool.seed(id);
				vector<bool> visited(1000, false);
				for (int k = 0; k < 7; k++)
					visited[k] = true;
				for (unsigned m = 0; m < c2g_d05ab4.size(); m++)
				{
					int pos;
					do
					{
						pos = pool.rangeInt406d70(0, c2g_c3703c);
					} while (visited[pos]);
					visited[pos] = true;
					if (data[pos] != c2g_d05ab4[m])
						goto mismatch;
				}
				c2g_cefacc = true;
			mismatch:
				break;
			}
		}
	}
	c2g_cefa7c->addLine(c2g_bf6e80, true);
	logInfo(c2g_bf6e8c);
	c2g_d25628.unserialize();
	if (c2g_d28fc4)
	{
		logMessage(c2g_bf6edc + intToString(c2g_d257b0.size()) + c2g_bf6ea4);
		c2g_d25628.reset778500();
		c2g_d28c68.save(2, 0);
	}
	c2g_cefa64->end(2);
	if (c2g_d28d05)
	{
		c2g_cefa7c->addLine(c2g_bf6ee8, true);
		opY2_startNetworkThread(0, true, OpC_newsThread_470fb0, 0);
	}
	if (c2g_cefacd)
	{
		C2GRec *rec;
		for (int a = 0; a < 0x548; a++)
		{
			if (!c2g_d035f4[a].name.empty())
			{
				if (c2g_find9d7a40(c2g_d2d1c4, c2g_d035f4[a].name, rec))
					rec->f7c.check();
			}
		}
		if (0) {}
		for (unsigned b = 0; b < c2g_d2d1c4.size(); b++)
		{
			if (c2g_d2d1c4[b]->f7c.check())
				continue;
			for (int c = 0; c < 0x548; c++)
			{
				if (c2g_d035f4[c].name == c2g_d2d1c4[b]->name)
					break;
			}
		}
	}
	if (c2g_cefacd)
	{
		for (int d = 0; d < 1000; d++)
			for (int e = d + 1; e < 1000; e++)
				if (!c2g_d16318[e].empty())
					c2g_d16318[d] == c2g_d16318[e];
	}
	if (0) {}
	string str = c2g_d25664;
	c2g_decode4712a0(str);
	if (str == c2g_bf6ef0)
		c2g_cefc5c = true;
	else if (str == c2g_bf6f18)
		c2g_cefc5d = true;
	c2g_cefa7c->addLine(c2g_bf6f40, true);
	c2g_cefc2c = new C2GMoveCallback;
	c2g_cefc30 = new C2GPathCallback;
	c2g_cefc34 = new C2GDesireCallback;
	c2g_cefc38 = new C2GMachineCallback;
	c2g_cefc3c = new C2GCaveCallback;
	c2g_cefc40 = new C2GCaveinCallback;
	c2g_cefc44 = new C2GSubCallback;
	c2g_cefc48 = new C2GSoundCallback;
	if (c2g_d28cb0)
	{
		c2g_cefaa0->toggle1c();
		c2g_cefaa0->toggle1d();
	}
	c2g_cefa7c->clear();
	c2g_d223f0.renderRoot();
	c2g_d223f0.getHighlighter()->removeSubconsole(c2g_cefa7c);
	c2g_cefa7c = 0;
	c2g_d223f0.getHighlighter()->removeEmptyLayers();
	c2g_cefa64->end(2);
	return true;
}
