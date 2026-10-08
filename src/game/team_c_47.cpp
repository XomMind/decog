// team_c_47: prefab grid rotation (0x437ee0): squares each layer of a prefab (expand/rotate/contract) and, when asked,
//	remaps the directional box-drawing glyphs (128-174) to their rotated forms (called from BS::placeMachine)
// NOTE: names are placeholders
#include <vector>
#include <cstdlib>
using namespace std;

bool OpT8b_Fn9daf80(int low, int value, int high);	// NOTE: placeholder name (in range)

struct C47_Cell { int font; int ch; int glyph; unsigned char foreR, foreG, foreB, backR, backG, backB; C47_Cell(); C47_Cell(const C47_Cell &o); int getChar(); void setChar(int ch_); };	// NOTE: placeholder (XCell)
struct C47_Grid { int width; int height; C47_Cell *cells; int getWidth(); int getHeight(); C47_Cell *at(int x, int y); void expand(C47_Cell fill, int left, int top, int right, int bottom); void contract(int left, int top, int right, int bottom); };	// NOTE: placeholder (OpS7_CellGrid)
void ops7_rotateGrid_9cf450(C47_Grid *grid);	// NOTE: placeholder name

class C47_Prefab	// NOTE: placeholder (machine prefab layers)
{
public:
	vector<C47_Grid *> v0;

	void rotate_437ee0(bool remapGlyphs);
};

void C47_Prefab::rotate_437ee0(bool remapGlyphs)
{
	C47_Cell center;
	for (unsigned int col = 0; col < v0.size(); col++)
	{
		if (v0[col]->getWidth() == v0[col]->getHeight())
			ops7_rotateGrid_9cf450(v0[col]);
		else
		{
			bool cols = v0[col]->getWidth() > v0[col]->getHeight();
			int current = abs(v0[col]->getWidth() - v0[col]->getHeight());
			if (cols)
				v0[col]->expand(center,0,0,0,current);
			else
				v0[col]->expand(center,0,current,0,0);
			ops7_rotateGrid_9cf450(v0[col]);
			if (cols)
				v0[col]->contract(current,0,0,0);
			else
				v0[col]->contract(0,0,0,current);
		}
		if (remapGlyphs)
		{
			for (int cols = 0; cols < v0[col]->getWidth(); cols++)
			{
				for (int current = 0; current < v0[col]->getHeight(); current++)
				{
					if (OpT8b_Fn9daf80(128,v0[col]->at(cols,current)->getChar(),174))
					{
						switch (v0[col]->at(cols,current)->getChar())
						{
						case 128:
							v0[col]->at(cols,current)->setChar(129);
							break;
						case 129:
							v0[col]->at(cols,current)->setChar(128);
							break;
						case 131:
							v0[col]->at(cols,current)->setChar(132);
							break;
						case 132:
							v0[col]->at(cols,current)->setChar(133);
							break;
						case 133:
							v0[col]->at(cols,current)->setChar(134);
							break;
						case 134:
							v0[col]->at(cols,current)->setChar(131);
							break;
						case 135:
							v0[col]->at(cols,current)->setChar(136);
							break;
						case 136:
							v0[col]->at(cols,current)->setChar(137);
							break;
						case 137:
							v0[col]->at(cols,current)->setChar(138);
							break;
						case 138:
							v0[col]->at(cols,current)->setChar(135);
							break;
						case 140:
							v0[col]->at(cols,current)->setChar(141);
							break;
						case 141:
							v0[col]->at(cols,current)->setChar(140);
							break;
						case 143:
							v0[col]->at(cols,current)->setChar(144);
							break;
						case 144:
							v0[col]->at(cols,current)->setChar(145);
							break;
						case 145:
							v0[col]->at(cols,current)->setChar(146);
							break;
						case 146:
							v0[col]->at(cols,current)->setChar(143);
							break;
						case 147:
							v0[col]->at(cols,current)->setChar(148);
							break;
						case 148:
							v0[col]->at(cols,current)->setChar(149);
							break;
						case 149:
							v0[col]->at(cols,current)->setChar(150);
							break;
						case 150:
							v0[col]->at(cols,current)->setChar(147);
							break;
						case 152:
							v0[col]->at(cols,current)->setChar(158);
							break;
						case 153:
							v0[col]->at(cols,current)->setChar(159);
							break;
						case 154:
							v0[col]->at(cols,current)->setChar(160);
							break;
						case 155:
							v0[col]->at(cols,current)->setChar(161);
							break;
						case 156:
							v0[col]->at(cols,current)->setChar(157);
							break;
						case 157:
							v0[col]->at(cols,current)->setChar(156);
							break;
						case 158:
							v0[col]->at(cols,current)->setChar(155);
							break;
						case 159:
							v0[col]->at(cols,current)->setChar(154);
							break;
						case 160:
							v0[col]->at(cols,current)->setChar(153);
							break;
						case 161:
							v0[col]->at(cols,current)->setChar(152);
							break;
						case 162:
							v0[col]->at(cols,current)->setChar(164);
							break;
						case 163:
							v0[col]->at(cols,current)->setChar(165);
							break;
						case 164:
							v0[col]->at(cols,current)->setChar(166);
							break;
						case 165:
							v0[col]->at(cols,current)->setChar(167);
							break;
						case 166:
							v0[col]->at(cols,current)->setChar(169);
							break;
						case 167:
							v0[col]->at(cols,current)->setChar(168);
							break;
						case 168:
							v0[col]->at(cols,current)->setChar(163);
							break;
						case 169:
							v0[col]->at(cols,current)->setChar(162);
							break;
						case 171:
							v0[col]->at(cols,current)->setChar(172);
							break;
						case 172:
							v0[col]->at(cols,current)->setChar(174);
							break;
						case 173:
							v0[col]->at(cols,current)->setChar(171);
							break;
						case 174:
							v0[col]->at(cols,current)->setChar(173);
							break;
						}
					}
				}
			}
		}
	}
}
