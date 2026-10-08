// team_b_51: damage/shot flash effects (0x965250, 0x965430) matched against COGMIND.exe (Beta 17.1).
// NOTE: partial layouts; placeholder names.
class RNG
{
public:
	int rangeInt(float low, float high);
};
extern RNG rng;	// 0xd30908
struct Pos { int x; int y; Pos(int x_, int y_); };
struct Rect { int x; int y; int width; int height; Rect(int x_, int y_, int width_, int height_); };
int OpX5_minInt(int a, int b);
class XConsole { public: virtual ~XConsole(); void unknown429fe0(XConsole *console, const Pos &pos, const Rect &rect);	/* NOTE: placeholder name */ };
class TeamB_FlashFx : public XConsole	// NOTE: placeholder name (CEffect)
{
public:
	TeamB_FlashFx(XConsole *parent, const Rect &rect, int type_);	// NOTE: placeholder name (CEffect::CEffect 0x4b2b90)
	void replaceSpecialChars(int ch);	// NOTE: placeholder name
	char pad04[0x70 - 4];
};
class TeamB_FlashRex { public: int unknown418980(); int unknown4189a0(); XConsole *getRoot_4ab670(); };	// NOTE: placeholder name (REX)
extern TeamB_FlashRex teamb_flashRex_d223f0;	// NOTE: placeholder name
class TeamB_ScreenShake { public: void start(int amount); };	// NOTE: placeholder name (XScreenShake)
extern TeamB_ScreenShake teamb_screenShake_d16188;	// NOTE: placeholder name
extern bool teamb_screenShakeEnabled_d28d4d;	// NOTE: placeholder name
extern int teamb_mapRowTop_cf27f0;	// NOTE: placeholder name
extern int teamb_mapWidth_cf27f4;	// NOTE: placeholder name
extern int teamb_mapLeft_cf27ec;	// NOTE: placeholder name
extern int teamb_cellWidth_caf128;	// NOTE: placeholder name
class TeamB_FlashLayer : public XConsole	// NOTE: placeholder name (object at 0xcec138)
{
public:
	char pad04[0x78 - 4];
	int count;
	void damageFlash965250(int damage);
	void shotFlash965430(int amount);
};
void TeamB_FlashLayer::damageFlash965250(int damage)	// 0x965250
{
	int w, h;
	if (damage > 50)
		damage = 50;
	for (int n = damage / 10 + 1; n >= 0; n--)
	{
		if (count >= 7)
			break;
		w = OpX5_minInt(teamb_flashRex_d223f0.unknown418980() / 2,rng.rangeInt(10,30) + damage / 5);
		h = OpX5_minInt(teamb_flashRex_d223f0.unknown4189a0(),rng.rangeInt(1,2) + damage / 20);
		new TeamB_FlashFx(this,Rect(rng.rangeInt(0,teamb_flashRex_d223f0.unknown418980() - w * 2),rng.rangeInt(0,teamb_flashRex_d223f0.unknown4189a0() - h),w,h),0);
		count++;
	}
	if (teamb_screenShakeEnabled_d28d4d)
		teamb_screenShake_d16188.start(0x32);
}

void TeamB_FlashLayer::shotFlash965430(int amount)	// 0x965430
{
	int w, h, x, y;
	for (int n = amount * 4; n > 0; n--)
	{
		w = rng.rangeInt(10,30);
		y = rng.rangeInt(0,teamb_flashRex_d223f0.unknown4189a0() - 1);
		x = rng.rangeInt(y < teamb_mapRowTop_cf27f0 ? 0 : teamb_mapWidth_cf27f4 * teamb_cellWidth_caf128 + teamb_mapLeft_cf27ec,teamb_flashRex_d223f0.unknown418980() - w);
		TeamB_FlashFx *e = new TeamB_FlashFx(this,Rect(x,y,w,1),2);
		teamb_flashRex_d223f0.getRoot_4ab670()->unknown429fe0(e,Pos(0,0),Rect(x,y,w,1));
		e->replaceSpecialChars(0x23);
	}
}
