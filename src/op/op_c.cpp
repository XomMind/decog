// op_c: assorted game functions matched against COGMIND.exe (Beta 17.1), range 0x470000-0x5e0000.
// NOTE: class layouts are partial; padding members and all names here are placeholders
//	unless stated otherwise.
#include <string>
#include <vector>
#include <cctype>
#include "../engine/xcolor.h"
using namespace std;

//==================================================================
// node graph traversal (0x46ff70-0x4704a3)
//==================================================================

struct OpC_Node;	// NOTE: placeholder name

class OpC_HNode	// NOTE: placeholder name
{
	int	ID;
public:
	OpC_Node *operator->() const;	// 0x9b7910
	bool isValid() const;	// 0x...
};

struct OpC_Node	// NOTE: placeholder name
{
	int					pad0;
	int					type;
	int					ID;
	vector<OpC_HNode>	links;
	char				pad1c[0x26 - 0x1c];
	bool				flag26;
	bool				flag27;
};

template <class T> bool OpC_addUnique(vector<T> &v, T e);	// NOTE: placeholder name (0x9d30e0)
template <class T> bool OpC_inVector(vector<T> &v, T e);	// NOTE: placeholder name (0x9d31e0)

void OpC_findNodes_46ff70(int type, int ID, OpC_HNode node, vector<OpC_HNode> &matches, vector<OpC_HNode> &visited);	// NOTE: placeholder name

void OpC_findNodes_470050(int ID, OpC_HNode node, vector<OpC_HNode> &matches, vector<OpC_HNode> &visited)	// NOTE: placeholder name
{
	if (node->ID == ID)
		OpC_addUnique(matches,node);
	visited.push_back(node);
	for (unsigned int i = 0; i < node->links.size(); i++)
	{
		if (!OpC_inVector(visited,node->links[i]) && node->links[i]->type != 12 && node->links[i]->type != 13 && node->links[i]->type != 14)
			OpC_findNodes_470050(ID,node->links[i],matches,visited);
	}
}

bool OpC_findNode_470180(int type, int ID, OpC_HNode node, OpC_HNode *result)	// NOTE: placeholder name
{
	vector<OpC_HNode> matches;
	vector<OpC_HNode> visited;
	OpC_findNodes_46ff70(type,ID,node,matches,visited);
	if (!matches.empty())
		*result = matches[0];
	return result->isValid();
}

void OpC_findNodes_470240(OpC_HNode node, int ID, vector<OpC_HNode> &matches, vector<OpC_HNode> &visited)	// NOTE: placeholder name
{
	if (node->flag26 && !node->flag27 && node->ID == ID)
		OpC_addUnique(matches,node);
	visited.push_back(node);
	for (unsigned int i = 0; i < node->links.size(); i++)
	{
		if (!OpC_inVector(visited,node->links[i]))
			OpC_findNodes_470240(node->links[i],ID,matches,visited);
	}
}

void OpC_findNodes_470320(OpC_HNode node, int ID, vector<OpC_HNode> &matches, vector<OpC_HNode> &visited)	// NOTE: placeholder name
{
	if (!node->flag26 && !node->flag27 && node->ID == ID)
		OpC_addUnique(matches,node);
	visited.push_back(node);
	for (unsigned int i = 0; i < node->links.size(); i++)
	{
		if (!OpC_inVector(visited,node->links[i]))
			OpC_findNodes_470320(node->links[i],ID,matches,visited);
	}
}

void OpC_findNodes_470400(OpC_HNode node, vector<OpC_HNode> &matches, vector<OpC_HNode> &visited)	// NOTE: placeholder name
{
	OpC_addUnique(matches,node);
	visited.push_back(node);
	for (unsigned int i = 0; i < node->links.size(); i++)
	{
		if (!OpC_inVector(visited,node->links[i]))
			OpC_findNodes_470400(node->links[i],matches,visited);
	}
}

//==================================================================
// 0x4704b0
//==================================================================

extern XColor *OpC_color_cf6b24;	// NOTE: placeholder name
extern XColor *OpC_color_d338c8;	// NOTE: placeholder name
extern XColor *OpC_color_d22130;	// NOTE: placeholder name
extern XColor *OpC_color_cf13fc;	// NOTE: placeholder name
extern XColor *OpC_color_d2f170;	// NOTE: placeholder name
extern XColor *OpC_color_d22fcc;	// NOTE: placeholder name
extern XColor OpC_color_d2c35c;	// NOTE: placeholder name
extern XColor OpC_color_d2c35f;	// NOTE: placeholder name
extern XColor OpC_color_d2c362;	// NOTE: placeholder name
extern XColor OpC_color_d2c365;	// NOTE: placeholder name
extern XColor OpC_color_d2c368;	// NOTE: placeholder name
extern XColor OpC_color_d2c36b;	// NOTE: placeholder name
extern XColor OpC_color_d2c36e;	// NOTE: placeholder name

void OpC_initColors_4704b0()	// NOTE: placeholder name
{
	OpC_color_d2c35c = *OpC_color_cf6b24;
	OpC_color_d2c35f = *OpC_color_d338c8;
	OpC_color_d2c362 = *OpC_color_d22130;
	OpC_color_d2c365 = *OpC_color_cf13fc;
	OpC_color_d2c368 = *OpC_color_d2f170;
	OpC_color_d2c36b = *OpC_color_d22fcc;
	OpC_color_d2c36e = *OpC_color_d22fcc;
}

//==================================================================
// 0x470570
//==================================================================

extern int OpC_current_d2573c;	// NOTE: placeholder name
extern bool OpC_flag_d28d05;	// NOTE: placeholder name
extern bool OpC_flag_d25718;	// NOTE: placeholder name (set when the game is up to date)
extern bool OpC_flag_d28dee;	// NOTE: placeholder name
extern bool OpC_flag_d28d04;	// NOTE: placeholder name
extern unsigned int tickCount;	// 0xcaed20

struct OpC_Struct470570	// NOTE: placeholder name
{
	OpC_Struct470570();
	void reset_470bb0() throw();	// NOTE: placeholder name
	bool apply_4705b0();	// NOTE: placeholder name
	bool check_4705f0();	// NOTE: placeholder name
	bool check_470630();	// NOTE: placeholder name
	void add_470c00(int value_);	// NOTE: placeholder name

	int				value;
	bool			flag4;
	bool			flag5;
	unsigned int	tick;
	int				count;
	bool			flag10;
	vector<int>		values;
};

OpC_Struct470570::OpC_Struct470570()
	: value		(-1)
	, flag4		(false)
	, flag5		(false)
	, flag10	(false)
{
	reset_470bb0();
}

bool OpC_Struct470570::apply_4705b0()
{
	if (value != -1 && OpC_current_d2573c != value)
	{
		OpC_current_d2573c = value;
		return true;
	}
	else
		return false;
}

bool OpC_Struct470570::check_4705f0()
{
	if (OpC_flag_d28d05 && !flag4 && !OpC_flag_d25718)
	{
		flag4 = true;
		return true;
	}
	else
		return false;
}

bool OpC_Struct470570::check_470630()
{
	if (OpC_flag_d28dee && !flag5 && !OpC_flag_d28d04)
	{
		flag5 = true;
		return true;
	}
	else
		return false;
}

void OpC_Struct470570::reset_470bb0()
{
	tick = tickCount;
	count = 0;
}

void OpC_Struct470570::add_470c00(int value_)
{
	values.push_back(value_);
}

//==================================================================
// GM
//==================================================================

extern vector<unsigned int> OpC_sessionTimes_cf4cd8;	// NOTE: placeholder name

class GM
{
public:
	unsigned int getSessionTimeTotal();
	unsigned int unknown470aa0(bool keep);	// NOTE: placeholder name
};

unsigned int GM::unknown470aa0(bool keep)
{
	OpC_sessionTimes_cf4cd8.push_back(getSessionTimeTotal());
	unsigned int total = 0;
	for (unsigned int i = 0; i < OpC_sessionTimes_cf4cd8.size(); i++)
		total += OpC_sessionTimes_cf4cd8[i] / 1000;
	if (!keep)
		OpC_sessionTimes_cf4cd8.pop_back();
	return total;
}

//==================================================================
// news
//==================================================================

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)

bool extractNewsContent(const string &text, const string &tag, string &content)
{
	string tagOpen = "<" + tag + ">";
	string tagClose = "</" + tag + ">";
	int startPos = text.find(tagOpen,0);
	int endPos = text.find(tagClose,0);
	if (startPos == string::npos)
	{
		logError("extractNewsContent()","Invalid news format, tag not found: " + tagOpen);
		return false;
	}
	if (endPos == string::npos)
	{
		logError("extractNewsContent()","Invalid news format, tag not found: " + tagClose);
		return false;
	}
	startPos += tagOpen.length();
	if (startPos >= endPos)
	{
		logError("extractNewsContent()","Invalid news format, tag empty: " + tagOpen);
		return false;
	}
	content.assign(text.begin() + startPos,text.begin() + endPos);
	return true;
}

class Http
{
public:
	Http(const string &host, const string &path, int port);	// 0x4499c0
	~Http();	// 0x9f51f0
	string newsCheck(bool flag);

	char data[0x3c];
};

class Network
{
public:
	static void threadQuitting(int threadType);
};

extern string gameString_cf33fc;
extern string OpC_newsVersion_d256e0;	// NOTE: placeholder name
extern string OpC_newsBuild_d256fc;	// NOTE: placeholder name
extern string OpC_newsText_d2571c;	// NOTE: placeholder name
extern bool OpC_newsRead_d25738;	// NOTE: placeholder name
string OpC_buildToVersion_432720(const string &build);	// NOTE: placeholder name
float stringToFloat_405ab0(const string &text);	// NOTE: placeholder name

int OpC_newsThread_470fb0(void *data)	// NOTE: placeholder name
{
	Http http("www.gridsagegames.com","/cogmind/temp/news_update.php",80);
	string response = http.newsCheck(false);
	if (!response.empty())
	{
		extractNewsContent(response,"VERSION",OpC_newsVersion_d256e0);
		extractNewsContent(response,"BUILD",OpC_newsBuild_d256fc);
		string currentVersion = OpC_buildToVersion_432720(gameString_cf33fc);
		string latestVersion = OpC_buildToVersion_432720(OpC_newsBuild_d256fc);
		OpC_flag_d25718 = stringToFloat_405ab0(currentVersion) >= stringToFloat_405ab0(latestVersion);
		string news;
		extractNewsContent(response,"NEWS",news);
		if (news != OpC_newsText_d2571c)
		{
			OpC_newsText_d2571c = news;
			OpC_newsRead_d25738 = false;
		}
	}
	Network::threadQuitting(0);
	return 0;
}

//==================================================================
// 0x4712a0-0x471920
//==================================================================

string &OpC_decode_4712a0(string &text)	// NOTE: placeholder name
{
	int shift = 13;
	for (unsigned int i = 0; i < text.length(); i++)
	{
		if (isalpha(text[i]))
		{
			if (text[i] >= 'a')
			{
				text[i] -= shift;
				if (text[i] < 'a')
					text[i] = 'z' - ('a' - text[i]) + 1;
			}
			else
			{
				text[i] -= shift;
				if (text[i] < 'A')
					text[i] = 'Z' - ('A' - text[i]) + 1;
			}
		}
		else if (isdigit(text[i]))
		{
			switch (text[i])
			{
			case '0': text[i] = '5'; break;
			case '1': text[i] = '6'; break;
			case '2': text[i] = '7'; break;
			case '3': text[i] = '8'; break;
			case '4': text[i] = '9'; break;
			case '5': text[i] = '0'; break;
			case '6': text[i] = '1'; break;
			case '7': text[i] = '2'; break;
			case '8': text[i] = '3'; break;
			case '9': text[i] = '4'; break;
			}
		}
		else if (text[i] == '&')
			text[i] = '-';
		else if (text[i] == '-')
			text[i] = '&';
	}
	return text;
}

struct SDL_Thread;
SDL_Thread *OpC_createThread_449730(int threadType, bool force, int (*fn)(void *), void *data);	// NOTE: placeholder name
int newsThread79ba00(void *data);	// NOTE: placeholder name
extern string OpC_key_d25664;	// NOTE: placeholder name

struct OpC_Struct471550	// NOTE: placeholder name
{
	void init_4715a0();	// NOTE: placeholder name

	bool			flag0;
	vector<string>	keys;
	string			key;
	bool			valid;
	SDL_Thread		*thread;
	int				interval;
	bool			flag3c;
	bool			flag3d;
	string			text40;
	vector<int>		vector5c;
	vector<int>		vector6c;
	vector<int>		vector7c;
};

void OpC_Struct471550::init_4715a0()
{
	flag0 = true;
	valid = false;
	key = OpC_key_d25664;
	OpC_decode_4712a0(key);
	keys.push_back("7r2449po&5922&9n54&350p&o97o19r9s264");
	for (unsigned int i = 0; i < keys.size(); i++)
	{
		if (key == keys[i])
		{
			valid = true;
			break;
		}
	}
	thread = NULL;
	interval = 300000;
	flag3c = false;
	flag3d = false;
	if (valid)
	{
		thread = OpC_createThread_449730(6,true,newsThread79ba00,NULL);
		if (thread == NULL)
			valid = false;
	}
}

OpC_Struct471550 *OpC_construct_471550(OpC_Struct471550 *p)	// NOTE: forces the implicit ctor
{
	return new (p) OpC_Struct471550;
}

string OpC_formatDateTime_4716f0(string date, string time)	// NOTE: placeholder name
{
	date.insert(date.begin() + 4,'.');
	date.insert(date.begin() + 2,'.');
	time.insert(time.begin() + 4,':');
	time.insert(time.begin() + 2,':');
	return "20" + date + " @ " + time;
}

class OpC_Deletable	// NOTE: placeholder name
{
public:
	virtual ~OpC_Deletable();
};

struct OpC_Owner4718c0	// NOTE: placeholder name
{
	OpC_Owner4718c0(bool flag_);
	~OpC_Owner4718c0();

	OpC_Deletable	*object;
	bool			flag;
};

OpC_Owner4718c0::OpC_Owner4718c0(bool flag_)
{
	object = NULL;
	flag = flag_;
}

OpC_Owner4718c0::~OpC_Owner4718c0()
{
	delete object;
}

//==================================================================
// UploadScoreData
//==================================================================

class ProtoMessage	// NOTE: placeholder name (protobuf MessageLite, library code)
{
public:
	bool ParseFromString(const string &data);	// 0xa5ad90
};

namespace Protobuf
{
class PostScoresheetRequest : public ProtoMessage
{
public:
	PostScoresheetRequest();

	char data[0x14];
};
}

void readString(istream &in, string &s);	// NOTE: placeholder name (0x4096f0)

class UploadScoreData
{
public:
	UploadScoreData(istream &in, bool flag_);

	ProtoMessage	*data;	// NOTE: placeholder name
	bool			flag;	// NOTE: placeholder name
};

UploadScoreData::UploadScoreData(istream &in, bool flag_)
{
	flag = flag_;
	data = new Protobuf::PostScoresheetRequest;
	string buffer;
	readString(in,buffer);
	if (!data->ParseFromString(buffer))
		logError("UploadScoreData()","Unserialization failed!");
}

//==================================================================
// 0x471b30-0x471f3a
//==================================================================

template <class T> void readBinary(istream &stream, T *value);	// 0x9d8480 (int), 0x9cf520 (bool), NOTE: placeholder name

struct OpC_Record471b30	// NOTE: placeholder name
{
	OpC_Record471b30(istream &in);

	int		value0;
	string	text4;
	string	text20;
	int		value3c;
	bool	flag40;
	bool	flag41;
	int		value44;
	bool	flag48;
	bool	flag49;
	int		value4c;
};

OpC_Record471b30::OpC_Record471b30(istream &in)
{
	readBinary(in,&value0);
	readString(in,text4);
	readString(in,text20);
	readBinary(in,&value3c);
	readBinary(in,&flag40);
	readBinary(in,&flag41);
	readBinary(in,&value44);
	readBinary(in,&flag48);
	readBinary(in,&flag49);
	readBinary(in,&value4c);
}

struct OpC_NamedRecord	// NOTE: placeholder name
{
	char	pad0[0x20];
	string	name;
};

extern vector<OpC_NamedRecord *> OpC_records_d389c4;	// NOTE: placeholder name
string OpC_stringFunc_4082b0(const string &text);	// NOTE: placeholder name
void OpC_replaceAll_407f00(string &text, string from, string to);	// NOTE: placeholder name
void OpC_removeChar_408100(string &text, char c);	// NOTE: placeholder name
void OpC_stringFunc_408660(string &text, char c);	// NOTE: placeholder name

string OpC_getRecordFileName_471c50(int index)	// NOTE: placeholder name
{
	string name = OpC_records_d389c4[index]->name;
	name = OpC_stringFunc_4082b0(name);
	OpC_replaceAll_407f00(name," ","_");
	OpC_removeChar_408100(name,'.');
	OpC_removeChar_408100(name,'\'');
	OpC_removeChar_408100(name,'-');
	OpC_removeChar_408100(name,':');
	OpC_removeChar_408100(name,'(');
	OpC_removeChar_408100(name,'%');
	OpC_removeChar_408100(name,')');
	OpC_stringFunc_408660(name,'_');
	return name;
}

string OpC_getFileName_471dd0(const string &text)	// NOTE: placeholder name
{
	string name = text;
	name = OpC_stringFunc_4082b0(name);
	OpC_replaceAll_407f00(name," ","_");
	OpC_removeChar_408100(name,'.');
	OpC_removeChar_408100(name,'\'');
	OpC_removeChar_408100(name,'-');
	OpC_removeChar_408100(name,':');
	OpC_removeChar_408100(name,'(');
	OpC_removeChar_408100(name,'%');
	OpC_removeChar_408100(name,')');
	OpC_stringFunc_408660(name,'_');
	return name;
}
