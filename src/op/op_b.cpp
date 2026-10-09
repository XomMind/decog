// op_b: functions in 0x440000-0x470000.
// NOTE: class layouts are partial; names marked as placeholders are invented.
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <fstream>

using namespace std;

string intToString(int value);

template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480 (int), 0x9cf520 (bool), NOTE: placeholder name

struct Pos
{
	int x;
	int y;

	Pos();	// (-1,-1)
	Pos(const Pos &pos) throw();
	Pos &operator=(const Pos &pos);
	void translate(int dx, int dy);	// 0x40a2a0, NOTE: placeholder
	void read(istream &stream);	// 0x40a330, NOTE: placeholder name
};

string OpB_dateString_436e70(int a, int b, int c);	// NOTE: placeholder name

class OpB_Unk_4b98a0	// NOTE: placeholder name
{
public:
	string unknown4b98a0();	// NOTE: placeholder name
	string unknown4455b0();	// NOTE: placeholder name
};

string OpB_Unk_4b98a0::unknown4455b0()
{
	return unknown4b98a0() + "-" + OpB_dateString_436e70(0,0,0);
}

//==================================================================
// Config
//==================================================================

int roundToInt(float value);	// 0x406360, NOTE: placeholder name

struct XColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	string toString();
};

struct XColorFilter	// NOTE: placeholder name
{
	int type;
	int amount;
	float value;
	XColor color;
};

extern string OpB_colorFilterNames[];	// 0xd39468, NOTE: placeholder name
extern int OpB_colorFilterArgType[];	// 0xbb6d0c, NOTE: placeholder name

class Config	// NOTE: placeholder layout
{
public:
	~Config();
	string colorFiltersToString(int which);	// NOTE: placeholder name

	int unknown0;
	string unknown4;
	char pad20[0x64 - 0x20];
	string unknown64;
	string unknown80;
	char pad9c[0xad - 0x9c];
	bool bigFont;	// NOTE: placeholder name
	char padae[0x108 - 0xae];
	vector<bool> unknown108;
	char pad11c[0x128 - 0x11c];
	vector<XColorFilter> colorFiltersA;	// NOTE: placeholder name
	vector<XColorFilter> colorFiltersB;	// NOTE: placeholder name
	char pad148[0x250 - 0x148];
	ofstream unknown250;
};

extern Config config;	// 0xd28c68

Config::~Config()
{
}

string Config::colorFiltersToString(int which)
{
	vector<XColorFilter> &filters = (which == 77 ? colorFiltersA : colorFiltersB);
	string str;
	if (filters.empty())
		str = OpB_colorFilterNames[0];
	else for (unsigned int i = 0; i < filters.size(); i++)
	{
		if (i != 0)
			str += "|";
		str += OpB_colorFilterNames[filters[i].type];
		switch (OpB_colorFilterArgType[filters[i].type])
		{
		case 1:
			str += "(" + intToString(filters[i].amount) + ")";
			break;
		case 2:
			str += "(" + intToString(roundToInt(filters[i].value * 100.0)) + ")";
			break;
		case 3:
			str += filters[i].color.toString();
			break;
		}
	}
	return str;
}

extern int fontCellWidth;	// 0xcaf128, NOTE: placeholder name
extern int fontCellScale;	// 0xcaf12c, NOTE: placeholder name
extern int OpB_screenWidth_cefaac;	// NOTE: placeholder name
extern int OpB_screenHeight_cefab0;	// NOTE: placeholder name
extern int OpB_screenCellsX_cefab4;	// NOTE: placeholder name
extern int OpB_screenCellsY_cefab8;	// NOTE: placeholder name

// The verifier pairs data by symbol start, so members of the global config read at a fixed
//	address are declared as their own objects here.
extern bool OpB_configBigFont;	// config.bigFont (0xd28d15), NOTE: placeholder name

void OpB_updateFontScale_446320()	// NOTE: placeholder name
{
	fontCellWidth = OpB_configBigFont ? 4 : 2;
	fontCellScale = OpB_configBigFont ? 2 : 1;
	OpB_screenCellsX_cefab4 = OpB_screenWidth_cefaac / (OpB_configBigFont ? 2 : 1);
	OpB_screenCellsY_cefab8 = OpB_screenHeight_cefab0 / (OpB_configBigFont ? 2 : 1);
}

//==================================================================
// AsciiImage
//==================================================================

class OpS7_CellGrid	// NOTE: placeholder name (retail copy-constructs the layers through this configured ctor 0x9cdd40; same layout as XBuffer)
{
public:
	OpS7_CellGrid(const OpS7_CellGrid &grid);	// 0x9cdd40

	int width;
	int height;
	void *cells;
};

class XBuffer	// NOTE: placeholder layout
{
public:
	~XBuffer();	// 0x9cec20

	int width;
	int height;
	void *cells;
};

template <class T> void OpB_deleteVectorContents(vector<T*> &v) throw();	// 0x9cf360 for XBuffer, NOTE: placeholder name
template <class T> void OpB_clearVector(vector<T*> &v);	// 0x9cf340 for XBuffer, NOTE: placeholder name

// layered REXPaint image
class AsciiImage
{
public:
	AsciiImage() throw();	// 0x4588d0
	AsciiImage(const AsciiImage &image);
	~AsciiImage();
	AsciiImage &operator=(const AsciiImage &image);
	void read(istream &stream);	// 0x437560, NOTE: placeholder name

	vector<XBuffer*> layers;
};

AsciiImage::AsciiImage(const AsciiImage &image)
{
	for (unsigned int i = 0; i < image.layers.size(); i++)
		layers.push_back((XBuffer *)new OpS7_CellGrid(*(OpS7_CellGrid *)image.layers[i]));
}

AsciiImage &AsciiImage::operator=(const AsciiImage &image)
{
	OpB_clearVector(layers);
	for (unsigned int i = 0; i < image.layers.size(); i++)
		layers.push_back((XBuffer *)new OpS7_CellGrid(*(OpS7_CellGrid *)image.layers[i]));
	return *this;
}

AsciiImage::~AsciiImage()
{
	OpB_deleteVectorContents(layers);
}

//==================================================================
// Pos helpers
//==================================================================

void OpB_translateRotated(Pos *pos, int rotation, int dx, int dy)	// NOTE: placeholder name
{
	switch (rotation)
	{
	case 0:
		pos->translate(dx,-dy);
		break;
	case 1:
		pos->translate(dy,dx);
		break;
	case 2:
		pos->translate(-dx,dy);
		break;
	case 3:
		pos->translate(-dy,-dx);
		break;
	}
}

// a named REXPaint image with placement data
struct OpB_ImageRecord	// NOTE: placeholder name
{
	AsciiImage	image;
	string		name;	// NOTE: placeholder name
	string		file;	// NOTE: placeholder name
	int			unknown48;
	int			unknown4C;
	Pos			offset;	// NOTE: placeholder name
	int			unknown58;
	bool		unknown5C;

	OpB_ImageRecord();
	OpB_ImageRecord(const OpB_ImageRecord &record);
	OpB_ImageRecord(istream &stream);
	void operator=(const OpB_ImageRecord &record);
};

OpB_ImageRecord::OpB_ImageRecord()
{
}

OpB_ImageRecord::OpB_ImageRecord(const OpB_ImageRecord &record)
	: image		(record.image)
	, name		(record.name)
	, file		(record.file)
	, unknown48	(record.unknown48)
	, unknown4C	(record.unknown4C)
	, offset	(record.offset)
	, unknown58	(record.unknown58)
	, unknown5C	(record.unknown5C)
{
}

OpB_ImageRecord::OpB_ImageRecord(istream &stream)
{
	image.read(stream);
	readBinary(stream,&unknown48);
	readBinary(stream,&unknown4C);
	offset.read(stream);
	readBinary(stream,&unknown58);
	readBinary(stream,&unknown5C);
}

void OpB_ImageRecord::operator=(const OpB_ImageRecord &record)
{
	image = record.image;
	name = record.name;
	file = record.file;
	unknown48 = record.unknown48;
	unknown4C = record.unknown4C;
	offset = record.offset;
	unknown58 = record.unknown58;
	unknown5C = record.unknown5C;
}
