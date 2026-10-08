// team_a_20: string/parse helpers from the 600-2500 byte band (0x400000-0x4fffff) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names; local names follow docs/local-name-buckets.txt.
#include <string>
#include <vector>
#include "engine/xcolor.h"
using namespace std;

void opw8_eraseLastChar(string &s);	// NOTE: placeholder name (0x407840)

// splits text at separator characters, keeping quoted runs together (0x408860)
void OpW7_split_408860(const string &text, char separator, char quote, vector<string> &out, bool escapes)	// NOTE: placeholder name
{
	if (text.empty())
		return;
	unsigned int start = *text.begin() == separator ? text.find_first_not_of(separator,0) : 0;
	unsigned int end = *(text.end() - 1) == separator ? text.find_last_not_of(separator) : text.size() - 1;
	out.push_back(string());
	string *part = &out.back();
	bool quoted = false;
	for (int i = start; i <= end; i++)	// unsigned compare as in the original
	{
		if (text[i] == quote)
		{
			if (escapes && i > 0 && text[i - 1] == '\\')
			{
				opw8_eraseLastChar(*part);
				*part += text[i];
			}
			else
				quoted = !quoted;
		}
		else if (text[i] == separator && !quoted)
		{
			out.push_back(string());
			part = &out.back();
			while (text[i + 1] == separator)
				i++;
		}
		else
			*part += text[i];
	}
}

// splits text into lines of at most width characters, breaking at newlines or spaces (0x408e60)
int opr5e_wrapText_408e60(string text, int width, vector<string> *out)	// NOTE: placeholder name
{
	while (true)
	{
		if (text.size() <= width)
		{
			out->push_back(text);
			break;
		}
		int end = width - 1;
		int index = -1;
		for (int i = 0; i <= end; i++)
		{
			if (text[i] == '\n')
			{
				index = i;
				goto cut;
			}
		}
		for (int j = end; j >= 0; j--)
		{
			if (text[j] == ' ')
			{
				index = j;
				break;
			}
		}
		if (index == -1)
			index = end;
		else
		{
			for (int k = index; k < text.size(); k++)
			{
				if (text[k] == ' ')
					text.erase(k,1);
				else
					break;
			}
			for (int m = index - 1; m >= 0; m--)
			{
				if (text[m] == ' ')
					text.erase(m,1);
				else
					break;
			}
		}
cut:
		if (!text.empty())
		{
			out->push_back(string(text.begin(),text.begin() + index));
			text.erase(text.begin(),text.begin() + index);
		}
		if (text.empty())
			break;
	}
	return out->size();
}

extern XColor &ptr_cf281c;
extern XColor &ta20_color_cfabbc;	// NOTE: placeholder name (0xcfabbc)
extern XColor &ptr_d0249c;
extern XColor &ta20_color_d15d98;	// NOTE: placeholder name (0xd15d98)
extern XColor &ta20_color_d20618;	// NOTE: placeholder name (0xd20618)
extern XColor &ptr_d2087c;
extern XColor &ta20_color_d20a74;	// NOTE: placeholder name (0xd20a74)
extern XColor &ta20_color_d20b78;	// NOTE: placeholder name (0xd20b78)
extern XColor &ptr_d21b44;
extern XColor &ta20_color_d25e0c;	// NOTE: placeholder name (0xd25e0c)
extern XColor &ta20_color_d25f60;	// NOTE: placeholder name (0xd25f60)
extern XColor &ta20_color_d31574;	// NOTE: placeholder name (0xd31574)
extern XColor &ta20_color_d32dfc;	// NOTE: placeholder name (0xd32dfc)
extern XColor &ta20_color_d338bc;	// NOTE: placeholder name (0xd338bc)
extern XColor &ptr_d35bbc;
extern XColor &ta20_color_d35bc4;	// NOTE: placeholder name (0xd35bc4)
extern XColor &ta20_color_d38644;	// NOTE: placeholder name (0xd38644)
extern XColor &ta20_color_d386c8;	// NOTE: placeholder name (0xd386c8)
extern XColor cols_cf0d48[32];	// NOTE: placeholder name

// fills a 32-entry colour table from the named palette colours (0x48b9b0)
void initColorTable_48b9b0()	// NOTE: placeholder name
{
	cols_cf0d48[0] = ptr_d2087c;
	cols_cf0d48[1] = ptr_d0249c;
	cols_cf0d48[2] = ta20_color_d31574;
	cols_cf0d48[3] = ptr_d0249c;
	cols_cf0d48[4] = ptr_d21b44;
	cols_cf0d48[5] = ta20_color_d20b78;
	cols_cf0d48[6] = ptr_d35bbc;
	cols_cf0d48[7] = ptr_d2087c;
	cols_cf0d48[8] = ta20_color_d31574;
	cols_cf0d48[9] = ta20_color_d20a74;
	cols_cf0d48[10] = ta20_color_d38644;
	cols_cf0d48[11] = ptr_cf281c;
	cols_cf0d48[12] = ta20_color_d386c8;
	cols_cf0d48[13] = ta20_color_d25f60;
	cols_cf0d48[14] = ta20_color_d25f60;
	cols_cf0d48[15] = ta20_color_d20618;
	cols_cf0d48[16] = ta20_color_cfabbc;
	cols_cf0d48[17] = ta20_color_d32dfc;
	cols_cf0d48[18] = ta20_color_d15d98;
	cols_cf0d48[19] = ta20_color_d15d98;
	cols_cf0d48[20] = ta20_color_d25e0c;
	cols_cf0d48[21] = ta20_color_d338bc;
	cols_cf0d48[22] = ta20_color_cfabbc;
	cols_cf0d48[23] = ta20_color_d35bc4;
	cols_cf0d48[24] = ta20_color_d338bc;
	cols_cf0d48[25] = ta20_color_d386c8;
	cols_cf0d48[26] = ptr_cf281c;
	cols_cf0d48[27] = ta20_color_d25f60;
	cols_cf0d48[28] = ta20_color_d25f60;
	cols_cf0d48[29] = ptr_d21b44;
	cols_cf0d48[30] = ta20_color_d338bc;
	cols_cf0d48[31] = ta20_color_d38644;
}

extern XColor &COLOR_WHITE;
extern XColor &ptr_cf281c;
extern XColor &ptr_d0249c;
extern XColor &ptr_d1d46c;
extern XColor &ptr_d2087c;
extern XColor &ptr_d21b44;
extern XColor &ptr_d30424;
extern XColor &ptr_d323c4;
extern XColor &ptr_d35bbc;
extern XColor &ta20_ref_cf44c0;	// NOTE: placeholder name
extern XColor &ta20_ref_cfc180;	// NOTE: placeholder name
extern XColor &ta20_ref_d15d98;	// NOTE: placeholder name
extern XColor &ta20_ref_d1e048;	// NOTE: placeholder name
extern XColor &ta20_ref_d20618;	// NOTE: placeholder name
extern XColor &ta20_ref_d20a74;	// NOTE: placeholder name
extern XColor &ta20_ref_d20b70;	// NOTE: placeholder name
extern XColor &ta20_ref_d25e0c;	// NOTE: placeholder name
extern XColor &ta20_ref_d2ea1c;	// NOTE: placeholder name
extern XColor &ta20_ref_d31574;	// NOTE: placeholder name
extern XColor &ta20_ref_d3579c;	// NOTE: placeholder name
extern XColor &ta20_ref_d35bc4;	// NOTE: placeholder name
extern XColor &ta20_ref_d35be0;	// NOTE: placeholder name
extern XColor &ta20_ref_d38644;	// NOTE: placeholder name
extern XColor &ta20_ref_d386c8;	// NOTE: placeholder name
extern XColor ta20_col_cf0e98;	// NOTE: placeholder name
extern XColor ta20_col_cf0e9b;	// NOTE: placeholder name
extern XColor ta20_col_cf0e9e;	// NOTE: placeholder name
extern XColor ta20_col_cf0ea1;	// NOTE: placeholder name
extern XColor ta20_col_cf0ea4;	// NOTE: placeholder name
extern XColor ta20_col_cf0ea7;	// NOTE: placeholder name
extern XColor ta20_col_cf0eaa;	// NOTE: placeholder name
extern XColor ta20_col_cf0ead;	// NOTE: placeholder name
extern XColor ta20_col_cf0eb0;	// NOTE: placeholder name
extern XColor ta20_col_cf0eb3;	// NOTE: placeholder name
extern XColor ta20_col_cf0eb6;	// NOTE: placeholder name
extern XColor ta20_col_cf0eb9;	// NOTE: placeholder name
extern XColor ta20_col_cf0ebc;	// NOTE: placeholder name
extern XColor ta20_col_cf0ebf;	// NOTE: placeholder name
extern XColor ta20_col_cf0ec2;	// NOTE: placeholder name
extern XColor ta20_col_cf0ec5;	// NOTE: placeholder name
extern XColor ta20_col_cf0ec8;	// NOTE: placeholder name
extern XColor ta20_col_cf0ecb;	// NOTE: placeholder name
extern XColor ta20_col_cf0ece;	// NOTE: placeholder name
extern XColor ta20_col_cf0ed1;	// NOTE: placeholder name
extern XColor ta20_col_cf0ed4;	// NOTE: placeholder name
extern XColor ta20_col_cf0ed7;	// NOTE: placeholder name
extern XColor ta20_col_cf0eda;	// NOTE: placeholder name
extern XColor ta20_col_cf0edd;	// NOTE: placeholder name
extern XColor ta20_col_cf0ee0;	// NOTE: placeholder name
extern XColor ta20_col_cf0ee3;	// NOTE: placeholder name
extern XColor ta20_col_cf0ee6;	// NOTE: placeholder name
extern XColor ta20_col_cf0ee9;	// NOTE: placeholder name
extern XColor ta20_col_cf0eec;	// NOTE: placeholder name
extern XColor ta20_col_cf0eef;	// NOTE: placeholder name
extern XColor ta20_col_cf0ef2;	// NOTE: placeholder name
extern XColor ta20_col_cf0ef5;	// NOTE: placeholder name
extern XColor ta20_col_cf0ef8;	// NOTE: placeholder name
extern XColor ta20_col_cf0efb;	// NOTE: placeholder name
extern XColor ta20_col_cf0efe;	// NOTE: placeholder name
extern XColor ta20_col_cf0f01;	// NOTE: placeholder name
extern XColor ta20_col_cf0f04;	// NOTE: placeholder name
extern XColor ta20_col_cf0f07;	// NOTE: placeholder name
extern XColor ta20_col_cf0f0a;	// NOTE: placeholder name
extern XColor ta20_col_cf0f0d;	// NOTE: placeholder name
extern XColor ta20_col_cf0f10;	// NOTE: placeholder name
extern XColor ta20_col_cf0f13;	// NOTE: placeholder name
extern XColor ta20_col_cf0f16;	// NOTE: placeholder name
extern XColor ta20_col_cf0f19;	// NOTE: placeholder name
extern XColor ta20_col_cf0f1c;	// NOTE: placeholder name
extern XColor ta20_col_cf0f1f;	// NOTE: placeholder name
extern XColor ta20_col_cf0f22;	// NOTE: placeholder name
extern XColor ta20_col_cf0f25;	// NOTE: placeholder name
extern XColor ta20_col_cf0f28;	// NOTE: placeholder name
extern XColor ta20_col_cf0f2b;	// NOTE: placeholder name
extern XColor ta20_col_cf0f2e;	// NOTE: placeholder name
extern XColor ta20_col_cf0f31;	// NOTE: placeholder name
extern XColor ta20_col_cf0f34;	// NOTE: placeholder name
extern XColor ta20_col_cf0f37;	// NOTE: placeholder name
extern XColor ta20_col_cf0f3a;	// NOTE: placeholder name
extern XColor ta20_col_cf0f3d;	// NOTE: placeholder name
extern XColor ta20_col_cf0f40;	// NOTE: placeholder name
extern XColor ta20_col_cf0f43;	// NOTE: placeholder name
extern XColor ta20_col_cf0f46;	// NOTE: placeholder name
extern XColor ta20_col_cf0f49;	// NOTE: placeholder name
extern XColor ta20_col_cf0f4c;	// NOTE: placeholder name
extern XColor ta20_col_cf0f4f;	// NOTE: placeholder name
extern XColor ta20_col_cf0f52;	// NOTE: placeholder name
extern XColor ta20_col_cf0f55;	// NOTE: placeholder name
extern XColor ta20_col_cf0f58;	// NOTE: placeholder name
extern XColor ta20_col_cf0f5b;	// NOTE: placeholder name
extern XColor ta20_col_cf0f5e;	// NOTE: placeholder name
extern XColor ta20_col_cf0f61;	// NOTE: placeholder name
extern XColor ta20_col_cf0f64;	// NOTE: placeholder name
extern XColor ta20_col_cf0f67;	// NOTE: placeholder name
extern XColor ta20_col_cf0f6a;	// NOTE: placeholder name
extern XColor ta20_col_cf0f6d;	// NOTE: placeholder name
extern XColor ta20_col_cf0f70;	// NOTE: placeholder name
extern XColor ta20_col_cf0f73;	// NOTE: placeholder name
extern XColor ta20_col_cf0f76;	// NOTE: placeholder name
extern XColor ta20_col_cf0f79;	// NOTE: placeholder name
extern XColor ta20_col_cf0f7c;	// NOTE: placeholder name
extern XColor ta20_col_cf0f7f;	// NOTE: placeholder name
extern XColor ta20_col_cf0f82;	// NOTE: placeholder name
extern XColor ta20_col_cf0f85;	// NOTE: placeholder name
extern XColor ta20_col_cf0f88;	// NOTE: placeholder name
extern XColor ta20_col_cf0f8b;	// NOTE: placeholder name
extern XColor ta20_col_cf0f8e;	// NOTE: placeholder name
extern XColor ta20_col_cf0f91;	// NOTE: placeholder name
extern XColor ta20_col_cf0f94;	// NOTE: placeholder name
extern XColor ta20_col_cf0f97;	// NOTE: placeholder name
extern XColor ta20_col_cf0f9a;	// NOTE: placeholder name
extern XColor ta20_col_cf0f9d;	// NOTE: placeholder name
extern XColor ta20_col_cf0fa0;	// NOTE: placeholder name
extern XColor ta20_col_cf0fa3;	// NOTE: placeholder name
extern XColor ta20_col_d01724;	// NOTE: placeholder name
extern XColor ta20_col_d01727;	// NOTE: placeholder name
extern XColor ta20_col_d0172a;	// NOTE: placeholder name
extern XColor ta20_col_d0172d;	// NOTE: placeholder name
extern XColor ta20_col_d01730;	// NOTE: placeholder name
extern XColor ta20_col_d01733;	// NOTE: placeholder name
extern XColor ta20_col_d01736;	// NOTE: placeholder name
extern XColor ta20_col_d01739;	// NOTE: placeholder name
extern XColor ta20_col_d0173c;	// NOTE: placeholder name

// fills two colour tables from the palette references (0x433410)
void opt5_433410()	// NOTE: placeholder name
{
	ta20_col_cf0e98 = ta20_col_cf0eaa = ta20_ref_d386c8;
	ta20_col_cf0e9b = ta20_col_cf0ead = ta20_ref_d386c8;
	ta20_col_cf0e9e = ta20_col_cf0eb0 = ta20_ref_d15d98;
	ta20_col_cf0ea1 = ta20_col_cf0eb3 = ta20_ref_d15d98;
	ta20_col_cf0ea4 = ta20_col_cf0eb6 = ta20_ref_d31574;
	ta20_col_cf0ea7 = ta20_col_cf0eb9 = ta20_ref_d31574;
	ta20_col_cf0ebc = ta20_ref_cfc180;
	ta20_col_cf0ebf = ta20_ref_d3579c;
	ta20_col_cf0ec2 = ta20_ref_d3579c;
	ta20_col_cf0ec5 = ta20_ref_d38644;
	ta20_col_cf0ec8 = ta20_ref_d38644;
	ta20_col_cf0ecb = ta20_ref_d1e048;
	ta20_col_cf0ece = ta20_ref_cfc180;
	ta20_col_cf0ed1 = ptr_cf281c;
	ta20_col_cf0ed4 = ptr_d0249c;
	ta20_col_cf0ed7 = ptr_d21b44;
	ta20_col_cf0eda = ptr_d2087c;
	ta20_col_cf0edd = ptr_d35bbc;
	ta20_col_cf0ee0 = ta20_ref_cfc180;
	ta20_col_cf0ee3 = ta20_ref_d25e0c;
	ta20_col_cf0ee6 = ta20_ref_d25e0c;
	ta20_col_cf0ee9 = ta20_ref_d25e0c;
	ta20_col_cf0eec = ta20_ref_d25e0c;
	ta20_col_cf0eef = ta20_ref_d25e0c;
	ta20_col_cf0ef2 = ta20_ref_cfc180;
	ta20_col_cf0ef5 = ta20_ref_d20618;
	ta20_col_cf0ef8 = ta20_ref_d2ea1c;
	ta20_col_cf0efb = ta20_ref_d2ea1c;
	ta20_col_cf0efe = ta20_ref_d20a74;
	ta20_col_cf0f01 = ta20_ref_d20a74;
	ta20_col_cf0f04 = ta20_ref_cfc180;
	ta20_col_cf0f07 = ta20_ref_d20618;
	ta20_col_cf0f0a = ta20_ref_d2ea1c;
	ta20_col_cf0f0d = ta20_ref_d2ea1c;
	ta20_col_cf0f10 = ta20_ref_d20a74;
	ta20_col_cf0f13 = ta20_ref_d20a74;
	ta20_col_cf0f16 = ta20_ref_cfc180;
	ta20_col_cf0f19 = ta20_ref_d35be0;
	ta20_col_cf0f1c = ta20_ref_d20b70;
	ta20_col_cf0f1f = ta20_ref_d20b70;
	ta20_col_cf0f22 = ta20_ref_d35bc4;
	ta20_col_cf0f25 = ta20_ref_d35bc4;
	ta20_col_cf0f28 = ta20_ref_cfc180;
	ta20_col_cf0f2b = COLOR_WHITE;
	ta20_col_cf0f2e = ta20_ref_d20b70;
	ta20_col_cf0f31 = ta20_ref_d20b70;
	ta20_col_cf0f34 = ta20_ref_d35bc4;
	ta20_col_cf0f37 = ta20_ref_d35bc4;
	ta20_col_cf0f3a = ta20_ref_cfc180;
	ta20_col_cf0f3d = ta20_ref_d35be0;
	ta20_col_cf0f40 = ta20_ref_d20b70;
	ta20_col_cf0f43 = ta20_ref_d20b70;
	ta20_col_cf0f46 = ta20_ref_d35bc4;
	ta20_col_cf0f49 = ta20_ref_d35bc4;
	ta20_col_cf0f4c = ta20_ref_cfc180;
	ta20_col_cf0f4f = ta20_ref_d35be0;
	ta20_col_cf0f52 = ta20_ref_d20b70;
	ta20_col_cf0f55 = ta20_ref_d20b70;
	ta20_col_cf0f58 = ta20_ref_d35bc4;
	ta20_col_cf0f5b = ta20_ref_d35bc4;
	ta20_col_cf0f5e = ta20_ref_cfc180;
	ta20_col_cf0f61 = ptr_cf281c;
	ta20_col_cf0f64 = ptr_d0249c;
	ta20_col_cf0f67 = ptr_d21b44;
	ta20_col_cf0f6a = ptr_d2087c;
	ta20_col_cf0f6d = ptr_d35bbc;
	ta20_col_cf0f70 = ta20_ref_cfc180;
	ta20_col_cf0f73 = COLOR_WHITE;
	ta20_col_cf0f76 = COLOR_WHITE;
	ta20_col_cf0f79 = COLOR_WHITE;
	ta20_col_cf0f7c = COLOR_WHITE;
	ta20_col_cf0f7f = COLOR_WHITE;
	ta20_col_cf0f82 = ta20_ref_cfc180;
	ta20_col_cf0f85 = ta20_ref_d35be0;
	ta20_col_cf0f88 = ta20_ref_d20b70;
	ta20_col_cf0f8b = ta20_ref_d20b70;
	ta20_col_cf0f8e = ta20_ref_d35bc4;
	ta20_col_cf0f91 = ta20_ref_d35bc4;
	ta20_col_cf0f94 = ta20_ref_cfc180;
	ta20_col_cf0f97 = ta20_ref_d35be0;
	ta20_col_cf0f9a = ta20_ref_d20b70;
	ta20_col_cf0f9d = ta20_ref_d20b70;
	ta20_col_cf0fa0 = ta20_ref_d35bc4;
	ta20_col_cf0fa3 = ta20_ref_d35bc4;
	ta20_col_d01724 = ta20_ref_cfc180;
	ta20_col_d01727 = ptr_d1d46c;
	ta20_col_d0172a = ptr_d30424;
	ta20_col_d0172d = ta20_ref_cf44c0;
	ta20_col_d01730 = ta20_ref_cf44c0;
	ta20_col_d01736 = ptr_d323c4;
	ta20_col_d01739 = ptr_d323c4;
	ta20_col_d01733 = ptr_d1d46c;
	ta20_col_d0173c = ptr_d323c4;
}
