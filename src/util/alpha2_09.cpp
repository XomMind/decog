// alpha2_09: DF generator settings loader (0x4bd340), the DF counterpart of LC41Settings::read (0x4c8740).
// NOTE: placeholder names / placeholder layout; stream declarations follow src/util/loop_charlie_41_settings.cpp.
#include <string>
#include <vector>
#include <cstdio>
#include <istream>
#include "../thirdparty/zfstream.h"
using namespace std;
struct PHYSFS_File;
namespace PhysFScpp
{
	class base_fstream
	{
	protected:
		PHYSFS_File *const file;
	public:
		base_fstream(PHYSFS_File *);
		virtual ~base_fstream();
		bool isOpen_404af0() throw();
	};
	class ifstream : public base_fstream, public std::istream
	{
	public:
		ifstream(const string &, ios_base::openmode = ios_base::in);
		virtual ~ifstream();
		void close9c05e0() throw();
	};
}

struct A2SRange
{
	int low;
	int high;
	void set_409ff0(int value) throw();
	void set_40a010(int a, int b) throw();
	bool parse_40bf80(const string &text);
};
struct A2STally	// 0x14 bytes
{
	int total;
	vector<int> weights;
	void add_4481c0(int weight);
};
struct A2SBranching	// +0x58 (0x44 bytes)
{
	void reset_448060() throw();
	void setA_451950(int value) throw();
	void setB_4e8050(int value) throw();
	void setC_44d6d0(int value) throw();
	void setD_451400(int value) throw();
	void setE_448080(int value) throw();
	int data[0x44 / 4];
};
struct A2SLevel	// 0x0c bytes
{
	int value;
	int min;
	int max;
};
struct A2SRoomSettings	// 0x44 bytes
{
	int minArea;
	int maxArea;
	int maxCount;
	vector<int> widths;
	vector<int> heights;
	int corridorChance;
	int corridorTries;
	int clearance;
	A2SRange segmentLength;
	int turns;
};
struct A2SSpawn	// 0x84 bytes
{
	A2SSpawn();	// 0x448aa0
	~A2SSpawn();	// 0x448b40
	bool enabled;
	int level;
	int count;
	int chance;
	int direction;
	A2SRange x;	// +0x14
	A2SRange y;	// +0x1c
	A2SRange delay;	// +0x24
	vector<unsigned int> dirs;	// +0x2c
	A2SRange param3c;
	A2SRange param44;
	A2SRange param4c;
	A2SRange param54;
	A2SRange param5c;
	A2SRange param64;
	A2SRange param6c;
	A2SRange param74;
	A2SRange param7c;
};
struct A2SRecord	// 0xac bytes
{
	A2SRecord();	// 0x4bf280
	~A2SRecord();	// 0x4bf300
	void suffix_4485a0();
	bool enabled;
	int level;
	int chance;
	int type;
	int index;
	string name;	// +0x14
	string suffix;	// +0x30
	bool flag4c;
	string other;	// +0x50
	int value;	// +0x6c
	vector<unsigned int> directions;	// +0x70
	int category;	// +0x80
	bool flag84;
	A2SRange range88;
	A2SRange range90;
	A2SRange range98;
	A2SRange rangeA0;
	int extra;	// +0xa8
};
struct A2SSettings	// DF settings (0x280 bytes)
{
	bool read(const string &filename, bool binary);
	void load_4bf380(istream &in);

	int f0;
	int f4;
	float f8;
	int fc;
	int f10;
	A2STally tally14;
	A2STally tally28;
	A2STally tally3c;
	int f50;
	int f54;
	A2SBranching branching;	// +0x58
	int f9c;
	vector<A2SLevel> levels;	// +0xa0
	int fb0;
	vector<int> fb4;	// +0xb4
	A2SRoomSettings rooms[3];	// +0xc4
	int f190;
	bool skipPost;	// +0x194
	int f198;
	int f19c;
	int width;	// +0x1a0
	int height;	// +0x1a4
	int f1a8;
	vector<A2SRecord> records;	// +0x1ac
	vector<A2SSpawn> spawns;	// +0x1bc
	char pad1cc[0x1e0 - 0x1cc];
	A2SRange exitArea;	// +0x1e0
	char pad1e8[0x208 - 0x1e8];
	A2SRange exit208;
	char pad210[0x218 - 0x210];
	A2SRange exit218;
	A2SRange exit220;
	A2SRange exit228;
	A2SRange exit230;
	A2SRange exit238;
	A2SRange exit240;
	A2SRange exit248;
	vector<string> isolated;	// +0x250
	A2SRange floorPercent;	// +0x260
	int minRooms[3];	// +0x268
	int f274;
	int f278;
	int f27c;
};

struct A2SResource
{
	bool exists_415590(string name);
};
extern A2SResource *a2s_resources_cefa88;
struct A2SLog
{
	void end_410e50(int code);
};
extern A2SLog *a2s_log_cefa64;
bool a2s_line_4074b0(PhysFScpp::ifstream *in, string &line, int key);
int a2s_value_432ac0(int counter);
void a2s_parse_4bd1d0(string &line, vector<string> &parts);
int a2s_int_4bd2c0(const string &text);
float a2s_float_405ab0(const string &text);
void a2s_erase_4077e0(string &text);
int a2s_find_9cda80(const string *names, unsigned int count, string name);
int a2s_min_9cdb30(int a, int b);
bool a2s_between_9d4c40(int low, int value, int high);
extern string a2s_keys_cf2008[];
extern string a2s_dirNames_d162a0[];
extern string a2s_dirNames_cf63b8[];
extern string a2s_typeNames_d1e4b8[];
extern string a2s_categories_d2e840[];
extern int a2s_argCounts_bb83c8[];
extern const char a2s_dash_bcecec[], a2s_dash_bcecf0[], a2s_dash_bcecf4[], a2s_dash_bcecf8[], a2s_dash_bcecfc[];

bool A2SSettings::read(const string &filename, bool binary)
{
	exitArea.set_409ff0(-1);
	FILE *file = 0;
	if (!a2s_resources_cefa88->exists_415590(filename))
		return false;
	else if (binary)
	{
		if (file)
			fclose(file);
		gzifstream input(filename.c_str(),ios::binary);
		load_4bf380(input);
		input.close();
	}
	else
	{
		int counter = 0;
		string line;
		vector<string> parts;
		int next = 0;
		int type;
		if (file)
			fclose(file);
		PhysFScpp::ifstream input(filename.c_str());
		if (!input.isOpen_404af0())
		{
			a2s_log_cefa64->end_410e50(2);
			return false;
		}
		while (a2s_line_4074b0(&input,line,a2s_value_432ac0(counter)))
		{
			counter++;
			parts.clear();
			a2s_parse_4bd1d0(line,parts);
			if (!parts.empty())
			{
				type = a2s_find_9cda80(a2s_keys_cf2008,52,parts[0]);
				if (type == -1)
					return false;
				if (next < 48 && type != next)
					return false;
				if (a2s_argCounts_bb83c8[type] == 0 && parts.size() <= 2)
					return false;
				if (a2s_argCounts_bb83c8[type] > 0 && parts.size() - 1 != a2s_argCounts_bb83c8[type])
					return false;
				switch (type)
				{
					case 0:
						f10 = a2s_int_4bd2c0(parts[1]);
						break;
					case 1:
						f0 = a2s_int_4bd2c0(parts[1]);
						break;
					case 2:
					{
						A2SLevel level;
						for (unsigned int i = 1; i < parts.size(); i++)
						{
							levels.push_back(level);
							levels.back().value = a2s_int_4bd2c0(parts[i]);
						}
						break;
					}
					case 3:
						if (parts.size() - 1 != levels.size())
							return false;
						for (unsigned int i = 1; i < parts.size(); i++)
							levels[i - 1].min = a2s_int_4bd2c0(parts[i]);
						break;
					case 4:
						if (parts.size() - 1 != levels.size())
							return false;
						for (unsigned int i = 1; i < parts.size(); i++)
							levels[i - 1].max = a2s_int_4bd2c0(parts[i]);
						break;
					case 5:
						fb0 = a2s_int_4bd2c0(parts[1]);
						break;
					case 6:
						for (unsigned int i = 1; i < parts.size(); i++)
							fb4.push_back(a2s_int_4bd2c0(parts[i]));
						break;
					case 7:
						for (unsigned int i = 1; i < parts.size(); i++)
							tally14.add_4481c0(a2s_int_4bd2c0(parts[i]));
						break;
					case 8:
						for (unsigned int i = 1; i < parts.size(); i++)
							tally28.add_4481c0(a2s_int_4bd2c0(parts[i]));
						break;
					case 9:
						for (unsigned int i = 1; i < parts.size(); i++)
							tally3c.add_4481c0(a2s_int_4bd2c0(parts[i]));
						break;
					case 10:
						f50 = a2s_int_4bd2c0(parts[1]);
						break;
					case 11:
						f54 = a2s_int_4bd2c0(parts[1]);
						break;
					case 12:
						branching.reset_448060();
						branching.setA_451950(a2s_int_4bd2c0(parts[1]));
						break;
					case 13:
						branching.setB_4e8050(a2s_int_4bd2c0(parts[1]));
						break;
					case 14:
						branching.setC_44d6d0(a2s_int_4bd2c0(parts[1]));
						break;
					case 15:
						branching.setD_451400(a2s_int_4bd2c0(parts[1]));
						break;
					case 16:
						branching.setE_448080(a2s_int_4bd2c0(parts[1]));
						break;
					case 17:
						f9c = a2s_int_4bd2c0(parts[1]);
						break;
					case 18:
						f4 = a2s_int_4bd2c0(parts[1]);
						break;
					case 19:
						f8 = a2s_float_405ab0(parts[1]);
						break;
					case 20:
						fc = a2s_int_4bd2c0(parts[1]);
						break;
					case 21:
					case 22:
					case 23:
						rooms[type - 21].minArea = a2s_int_4bd2c0(parts[1]);
						rooms[type - 21].maxArea = a2s_int_4bd2c0(parts[2]);
						break;
					case 24:
					case 25:
					case 26:
						rooms[type - 24].maxCount = a2s_int_4bd2c0(parts[1]);
						break;
					case 27:
					case 28:
					case 29:
						for (unsigned int i = 1; i < parts.size(); i++)
							rooms[type - 27].widths.push_back(a2s_int_4bd2c0(parts[i]));
						break;
					case 30:
					case 31:
					case 32:
						for (unsigned int i = 1; i < parts.size(); i++)
							rooms[type - 30].heights.push_back(a2s_int_4bd2c0(parts[i]));
						break;
					case 33:
						f190 = a2s_int_4bd2c0(parts[1]);
						break;
					case 34:
						skipPost = a2s_int_4bd2c0(parts[1]);
						break;
					case 35:
						f198 = a2s_int_4bd2c0(parts[1]);
						if (!a2s_between_9d4c40(0,f198,501))
							f198 = 500;
						break;
					case 36:
						f19c = a2s_int_4bd2c0(parts[1]);
						break;
					case 37:
						for (int i = 0; i < 3; i++)
							rooms[i].corridorChance = a2s_int_4bd2c0(parts[i + 1]);
						break;
					case 38:
						for (int i = 0; i < 3; i++)
							rooms[i].corridorTries = a2s_int_4bd2c0(parts[i + 1]);
						break;
					case 39:
						for (int i = 0; i < 3; i++)
							rooms[i].clearance = a2s_int_4bd2c0(parts[i + 1]);
						break;
					case 40:
						for (int i = 0; i < 3; i++)
							rooms[i].segmentLength.set_40a010(a2s_int_4bd2c0(parts[i * 2 + 1]),a2s_int_4bd2c0(parts[i * 2 + 2]));
						break;
					case 41:
						for (int i = 0; i < 3; i++)
							rooms[i].turns = a2s_min_9cdb30(a2s_int_4bd2c0(parts[i + 1]),10);
						break;
					case 42:
						floorPercent.set_40a010(a2s_int_4bd2c0(parts[1]),a2s_int_4bd2c0(parts[2]));
						break;
					case 43:
						for (int i = 0; i < 3; i++)
							minRooms[i] = a2s_int_4bd2c0(parts[i + 1]);
						f274 = a2s_int_4bd2c0(parts[4]);
						break;
					case 44:
						f278 = a2s_int_4bd2c0(parts[1]);
						break;
					case 45:
						f27c = a2s_int_4bd2c0(parts[1]);
						break;
					case 46:
						width = a2s_int_4bd2c0(parts[1]);
						height = a2s_int_4bd2c0(parts[2]);
						if (width <= 0 || height <= 0)
							return false;
						break;
					case 47:
						f1a8 = a2s_int_4bd2c0(parts[1]);
						break;
					case 48:
					{
						A2SSpawn spawn;
						spawns.push_back(spawn);
						spawns.back().enabled = true;
						spawns.back().level = a2s_int_4bd2c0(parts[1]);
						spawns.back().count = a2s_int_4bd2c0(parts[2]);
						spawns.back().chance = parts[3] == a2s_dash_bcecec ? 100 : a2s_int_4bd2c0(parts[3]);
						spawns.back().direction = a2s_find_9cda80(a2s_dirNames_d162a0,4,parts[4]);
						if (spawns.back().direction == -1)
							return false;
						if (parts[8] == a2s_dash_bcecf0)
						{
							for (int d = 0; d < 4; d++)
								spawns.back().dirs.push_back((unsigned int)d);
						}
						else
						{
							for (unsigned int c = 0; c < parts[8].size(); c++)
							{
								switch (parts[8][c])
								{
									case 'N':
										spawns.back().dirs.push_back(0);
										break;
									case 'E':
										spawns.back().dirs.push_back(1);
										break;
									case 'S':
										spawns.back().dirs.push_back(2);
										break;
									case 'W':
										spawns.back().dirs.push_back(3);
										break;
									default:
										return false;
								}
							}
						}
						if (!spawns.back().x.parse_40bf80(parts[5]) || !spawns.back().y.parse_40bf80(parts[6]) || !spawns.back().delay.parse_40bf80(parts[7]) || !spawns.back().param3c.parse_40bf80(parts[9]) || !spawns.back().param44.parse_40bf80(parts[10]) || !spawns.back().param4c.parse_40bf80(parts[11]) || !spawns.back().param54.parse_40bf80(parts[12]) || !spawns.back().param5c.parse_40bf80(parts[13]) || !spawns.back().param64.parse_40bf80(parts[14]) || !spawns.back().param6c.parse_40bf80(parts[15]) || !spawns.back().param74.parse_40bf80(parts[16]) || !spawns.back().param7c.parse_40bf80(parts[17]))
							return false;
						break;
					}
					case 49:
						if (exitArea.low != -1)
							return false;
						if (!exit208.parse_40bf80(parts[9]) || !exit218.parse_40bf80(parts[11]) || !exit220.parse_40bf80(parts[12]) || !exit228.parse_40bf80(parts[13]) || !exit230.parse_40bf80(parts[14]) || !exit238.parse_40bf80(parts[15]) || !exit240.parse_40bf80(parts[16]) || !exit248.parse_40bf80(parts[17]))
							return false;
						exitArea.set_409ff0(0);
						break;
					case 50:
					{
						A2SRecord record;
						records.push_back(record);
						A2SRecord *data = &records.back();
						data->enabled = true;
						data->level = a2s_int_4bd2c0(parts[1]);
						data->chance = parts[2] == a2s_dash_bcecf4 ? 100 : a2s_int_4bd2c0(parts[2]);
						data->type = a2s_find_9cda80(a2s_typeNames_d1e4b8,21,parts[3]);
						data->index = -1;
						if (data->type == -1)
						{
							data->type = 21;
							if (parts[3][0] == '*')
							{
								data->flag4c = true;
								a2s_erase_4077e0(parts[3]);
							}
							data->name = parts[3];
							data->suffix_4485a0();
							if (parts[4] != a2s_dash_bcecf8)
								data->other = parts[4];
						}
						data->value = a2s_int_4bd2c0(parts[5]);
						if (parts[6] != a2s_dash_bcecfc)
						{
							for (int i = 0; i < 4; i++)
							{
								if (parts[6].find(a2s_dirNames_cf63b8[i],0) != string::npos)
									data->directions.push_back((unsigned int)i);
							}
						}
						if (data->type == 21 && data->directions.empty())
							data->directions.push_back(2);
						data->category = a2s_find_9cda80(a2s_categories_d2e840,6,parts[7]);
						if (data->category == -1)
							return false;
						data->flag84 = false;
						if (!data->range88.parse_40bf80(parts[8]) || !data->range90.parse_40bf80(parts[9]) || !data->range98.parse_40bf80(parts[10]) || !data->rangeA0.parse_40bf80(parts[11]))
							return false;
						data->extra = 0;
						break;
					}
					case 51:
						isolated.push_back(parts[1]);
						break;
				}
				next++;
			}
		}
		input.close9c05e0();
		if (next < 48)
			return false;
	}
	return true;
}
