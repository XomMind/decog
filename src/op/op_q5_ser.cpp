// op_q5: serialization template instances (0x9cf000-0x9e3000). Placeholder record types.
// NOTE: placeholder names
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value,sizeof(T));
}

template <class T> void OpQ5_writeObjects(ostream &stream, vector<T*> &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		v[i]->serialize(stream);
}

template <class T> void OpQ5_writePointer(ostream &stream, T *&p)	// NOTE: placeholder name
{
	bool exists = p != NULL;
	writeBinary(stream,&exists);
	if (exists)
		p->serialize(stream);
}

template <class T> void OpQ5_readReference(istream &stream, T *&p, vector<T*> &list)	// NOTE: placeholder name
{
	bool exists;
	readBinary(stream,&exists);
	if (exists)
	{
		int index;
		readBinary(stream,&index);
		if (index >= list.size())
		{
			logError("sdfklj245oi317r908fd","14.3");
			p = list[0];
			return;
		}
		p = list[index];
	}
	else p = NULL;
}

template <class T> void OpQ5_readObjects(istream &stream, vector<T*> &v, int skip)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	count -= skip;
	while (count)
	{
		v.push_back(new T(stream));
		count--;
	}
	if (skip)
	{
		vector<T*> discard;
		while (skip)
		{
			discard.push_back(new T(stream));
			skip--;
		}
	}
}

template <class T> void OpQ5_readPointer(istream &stream, T *&p)	// NOTE: placeholder name
{
	bool exists;
	readBinary(stream,&exists);
	p = exists ? new T(stream) : NULL;
}

template <class T> void OpQ5_deleteObjects(vector<T*> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
		delete v[i];
}

template <class T> void OpQ5_clearObjects(vector<T*> &v)	// NOTE: placeholder name
{
	OpQ5_deleteObjects(v);
	v.clear();
}

template <class T> void OpQ5_deleteObject(vector<T*> &v, int index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
}

template <class T> void OpQ5_deleteObjectAndStep(vector<T*> &v, int &index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
	index--;
}


struct OpQ5_T9cf200
{
	char pad[12];
	OpQ5_T9cf200(istream &stream);
	~OpQ5_T9cf200();
	void serialize(ostream &stream);
};

struct OpQ5_T9cf360
{
	char pad[4];
	OpQ5_T9cf360(istream &stream);
	~OpQ5_T9cf360();
	void serialize(ostream &stream);
};

struct OpQ5_T9cfb10
{
	char pad[4];
	OpQ5_T9cfb10(istream &stream);
	~OpQ5_T9cfb10();
	void serialize(ostream &stream);
};

struct OpQ5_T9cfb70
{
	char pad[4];
	OpQ5_T9cfb70(istream &stream);
	~OpQ5_T9cfb70();
	void serialize(ostream &stream);
};

class C065_Rec5188c0	// NOTE: placeholder layout; the exe's OpQ5_readObjects 0x9d0160 builds its records with 0x5188c0 (row C065_Rec5188c0::C065_Rec5188c0)
{
	char pad[20];
public:
	C065_Rec5188c0(istream &stream);
};

struct OpQ5_T9d02a0
{
	char pad[4];
	OpQ5_T9d02a0(istream &stream);
	~OpQ5_T9d02a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d0710
{
	char pad[4];
	OpQ5_T9d0710(istream &stream);
	~OpQ5_T9d0710();
	void serialize(ostream &stream);
};

struct OpQ5_T9d0770
{
	char pad[4];
	OpQ5_T9d0770(istream &stream);
	~OpQ5_T9d0770();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1050
{
	char pad[8];
	OpQ5_T9d1050(istream &stream);
	~OpQ5_T9d1050();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1190
{
	char pad[4];
	OpQ5_T9d1190(istream &stream);
	~OpQ5_T9d1190();
	void serialize(ostream &stream);
};

struct OpQ5_T9d11d0
{
	char pad[4];
	OpQ5_T9d11d0(istream &stream);
	~OpQ5_T9d11d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1230
{
	char pad[4];
	OpQ5_T9d1230(istream &stream);
	~OpQ5_T9d1230();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1270
{
	char pad[4];
	OpQ5_T9d1270(istream &stream);
	~OpQ5_T9d1270();
	void serialize(ostream &stream);
};

struct OpQ5_T9d12b0
{
	char pad[40];
	OpQ5_T9d12b0(istream &stream);
	~OpQ5_T9d12b0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1360
{
	char pad[12];
	OpQ5_T9d1360(istream &stream);
	~OpQ5_T9d1360();
	void serialize(ostream &stream);
};

struct OpQ5_T9d14a0
{
	char pad[72];
	OpQ5_T9d14a0(istream &stream);
	~OpQ5_T9d14a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1550
{
	char pad[1];
	OpQ5_T9d1550(istream &stream);
	~OpQ5_T9d1550();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1d80
{
	char pad[4];
	OpQ5_T9d1d80(istream &stream);
	~OpQ5_T9d1d80();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1de0
{
	char pad[328];
	OpQ5_T9d1de0(istream &stream);
	~OpQ5_T9d1de0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1e90
{
	char pad[120];
	OpQ5_T9d1e90(istream &stream);
	~OpQ5_T9d1e90();
	void serialize(ostream &stream);
};

struct OpQ5_T9d1fd0
{
	char pad[4];
	OpQ5_T9d1fd0(istream &stream);
	~OpQ5_T9d1fd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d2010
{
	char pad[4];
	OpQ5_T9d2010(istream &stream);
	~OpQ5_T9d2010();
	void serialize(ostream &stream);
};

struct OpQ5_T9d3bd0
{
	char pad[48];
	OpQ5_T9d3bd0(istream &stream);
	~OpQ5_T9d3bd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d3d10
{
	char pad[4];
	OpQ5_T9d3d10(istream &stream);
	~OpQ5_T9d3d10();
	void serialize(ostream &stream);
};

struct OpQ5_T9d3e30
{
	char pad[4];
	OpQ5_T9d3e30(istream &stream);
	~OpQ5_T9d3e30();
	void serialize(ostream &stream);
};

struct OpQ5_T9d4160
{
	char pad[4];
	OpQ5_T9d4160(istream &stream);
	~OpQ5_T9d4160();
	void serialize(ostream &stream);
};

struct OpQ5_T9d41c0
{
	char pad[32];
	OpQ5_T9d41c0(istream &stream);
	~OpQ5_T9d41c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d4760
{
	char pad[4];
	OpQ5_T9d4760(istream &stream);
	~OpQ5_T9d4760();
	void serialize(ostream &stream);
};

struct OpQ5_T9d47d0
{
	char pad[4];
	OpQ5_T9d47d0(istream &stream);
	~OpQ5_T9d47d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d4840
{
	char pad[4];
	OpQ5_T9d4840(istream &stream);
	~OpQ5_T9d4840();
	void serialize(ostream &stream);
};

struct OpQ5_T9d48c0
{
	char pad[4];
	OpQ5_T9d48c0(istream &stream);
	~OpQ5_T9d48c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d4950
{
	char pad[4];
	OpQ5_T9d4950(istream &stream);
	~OpQ5_T9d4950();
	void serialize(ostream &stream);
};

struct OpQ5_T9d5880
{
	char pad[4];
	OpQ5_T9d5880(istream &stream);
	~OpQ5_T9d5880();
	void serialize(ostream &stream);
};

struct OpQ5_T9d5970
{
	char pad[4];
	OpQ5_T9d5970(istream &stream);
	~OpQ5_T9d5970();
	void serialize(ostream &stream);
};

struct OpQ5_T9d5da0
{
	char pad[4];
	OpQ5_T9d5da0(istream &stream);
	~OpQ5_T9d5da0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d5e90
{
	char pad[4];
	OpQ5_T9d5e90(istream &stream);
	~OpQ5_T9d5e90();
	void serialize(ostream &stream);
};

struct OpQ5_T9d5f80
{
	char pad[4];
	OpQ5_T9d5f80(istream &stream);
	~OpQ5_T9d5f80();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6070
{
	char pad[4];
	OpQ5_T9d6070(istream &stream);
	~OpQ5_T9d6070();
	void serialize(ostream &stream);
};

struct OpQ5_T9d60d0
{
	char pad[40];
	OpQ5_T9d60d0(istream &stream);
	~OpQ5_T9d60d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6210
{
	char pad[4];
	OpQ5_T9d6210(istream &stream);
	~OpQ5_T9d6210();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6300
{
	char pad[4];
	OpQ5_T9d6300(istream &stream);
	~OpQ5_T9d6300();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6490
{
	char pad[4];
	OpQ5_T9d6490(istream &stream);
	~OpQ5_T9d6490();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6580
{
	char pad[8];
	OpQ5_T9d6580(istream &stream);
	~OpQ5_T9d6580();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6770
{
	char pad[4];
	OpQ5_T9d6770(istream &stream);
	~OpQ5_T9d6770();
	void serialize(ostream &stream);
};

struct OpQ5_T9d67d0
{
	char pad[4];
	OpQ5_T9d67d0(istream &stream);
	~OpQ5_T9d67d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d68c0
{
	char pad[4];
	OpQ5_T9d68c0(istream &stream);
	~OpQ5_T9d68c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d69b0
{
	char pad[4];
	OpQ5_T9d69b0(istream &stream);
	~OpQ5_T9d69b0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6aa0
{
	char pad[4];
	OpQ5_T9d6aa0(istream &stream);
	~OpQ5_T9d6aa0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6b90
{
	char pad[16];
	OpQ5_T9d6b90(istream &stream);
	~OpQ5_T9d6b90();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6cd0
{
	char pad[156];
	OpQ5_T9d6cd0(istream &stream);
	~OpQ5_T9d6cd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6e60
{
	char pad[164];
	OpQ5_T9d6e60(istream &stream);
	~OpQ5_T9d6e60();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6f10
{
	char pad[640];
	OpQ5_T9d6f10(istream &stream);
	~OpQ5_T9d6f10();
	void serialize(ostream &stream);
};

struct OpQ5_T9d6fc0
{
	char pad[4];
	OpQ5_T9d6fc0(istream &stream);
	~OpQ5_T9d6fc0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d7150
{
	char pad[472];
	OpQ5_T9d7150(istream &stream);
	~OpQ5_T9d7150();
	void serialize(ostream &stream);
};

struct OpQ5_T9d7850
{
	char pad[4];
	OpQ5_T9d7850(istream &stream);
	~OpQ5_T9d7850();
	void serialize(ostream &stream);
};

struct OpQ5_T9d7fb0
{
	char pad[4];
	OpQ5_T9d7fb0(istream &stream);
	~OpQ5_T9d7fb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8110
{
	char pad[4];
	OpQ5_T9d8110(istream &stream);
	~OpQ5_T9d8110();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8250
{
	char pad[16];
	OpQ5_T9d8250(istream &stream);
	~OpQ5_T9d8250();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8390
{
	char pad[4];
	OpQ5_T9d8390(istream &stream);
	~OpQ5_T9d8390();
	void serialize(ostream &stream);
};

struct OpQ5_T9d84d0
{
	char pad[4];
	OpQ5_T9d84d0(istream &stream);
	~OpQ5_T9d84d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8510
{
	char pad[20];
	OpQ5_T9d8510(istream &stream);
	~OpQ5_T9d8510();
	void serialize(ostream &stream);
};

struct OpQ5_T9d86c0
{
	char pad[28];
	OpQ5_T9d86c0(istream &stream);
	~OpQ5_T9d86c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8800
{
	char pad[4];
	OpQ5_T9d8800(istream &stream);
	~OpQ5_T9d8800();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8860
{
	char pad[16];
	OpQ5_T9d8860(istream &stream);
	~OpQ5_T9d8860();
	void serialize(ostream &stream);
};

struct OpQ5_T9d89a0
{
	char pad[28];
	OpQ5_T9d89a0(istream &stream);
	~OpQ5_T9d89a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8a50
{
	char pad[24];
	OpQ5_T9d8a50(istream &stream);
	~OpQ5_T9d8a50();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8b00
{
	char pad[16];
	OpQ5_T9d8b00(istream &stream);
	~OpQ5_T9d8b00();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8bb0
{
	char pad[36];
	OpQ5_T9d8bb0(istream &stream);
	~OpQ5_T9d8bb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8cf0
{
	char pad[4];
	OpQ5_T9d8cf0(istream &stream);
	~OpQ5_T9d8cf0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8d50
{
	char pad[4];
	OpQ5_T9d8d50(istream &stream);
	~OpQ5_T9d8d50();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8d90
{
	char pad[4];
	OpQ5_T9d8d90(istream &stream);
	~OpQ5_T9d8d90();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8dd0
{
	char pad[4];
	OpQ5_T9d8dd0(istream &stream);
	~OpQ5_T9d8dd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8e10
{
	char pad[4];
	OpQ5_T9d8e10(istream &stream);
	~OpQ5_T9d8e10();
	void serialize(ostream &stream);
};

struct OpQ5_T9d8e70
{
	char pad[4];
	OpQ5_T9d8e70(istream &stream);
	~OpQ5_T9d8e70();
	void serialize(ostream &stream);
};

struct OpQ5_T9d92d0
{
	char pad[4];
	OpQ5_T9d92d0(istream &stream);
	~OpQ5_T9d92d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d95a0
{
	char pad[4];
	OpQ5_T9d95a0(istream &stream);
	~OpQ5_T9d95a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9660
{
	char pad[4];
	OpQ5_T9d9660(istream &stream);
	~OpQ5_T9d9660();
	void serialize(ostream &stream);
};

struct OpQ5_T9d96a0
{
	char pad[8];
	OpQ5_T9d96a0(istream &stream);
	~OpQ5_T9d96a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d97e0
{
	char pad[304];
	OpQ5_T9d97e0(istream &stream);
	~OpQ5_T9d97e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9bb0
{
	char pad[4];
	OpQ5_T9d9bb0(istream &stream);
	~OpQ5_T9d9bb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9c50
{
	char pad[4];
	OpQ5_T9d9c50(istream &stream);
	~OpQ5_T9d9c50();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9cb0
{
	char pad[4];
	OpQ5_T9d9cb0(istream &stream);
	~OpQ5_T9d9cb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9cf0
{
	char pad[4];
	OpQ5_T9d9cf0(istream &stream);
	~OpQ5_T9d9cf0();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9d30
{
	char pad[4];
	OpQ5_T9d9d30(istream &stream);
	~OpQ5_T9d9d30();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9e20
{
	char pad[144];
	OpQ5_T9d9e20(istream &stream);
	~OpQ5_T9d9e20();
	void serialize(ostream &stream);
};

struct OpQ5_T9d9ed0
{
	char pad[32];
	OpQ5_T9d9ed0(istream &stream);
	~OpQ5_T9d9ed0();
	void serialize(ostream &stream);
};

struct OpQ5_T9da040
{
	char pad[4];
	OpQ5_T9da040(istream &stream);
	~OpQ5_T9da040();
	void serialize(ostream &stream);
};

struct OpQ5_T9da380
{
	char pad[56];
	OpQ5_T9da380(istream &stream);
	~OpQ5_T9da380();
	void serialize(ostream &stream);
};

struct OpQ5_T9da4c0
{
	char pad[20];
	OpQ5_T9da4c0(istream &stream);
	~OpQ5_T9da4c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9da570
{
	char pad[12];
	OpQ5_T9da570(istream &stream);
	~OpQ5_T9da570();
	void serialize(ostream &stream);
};

struct OpQ5_T9da750
{
	char pad[4];
	OpQ5_T9da750(istream &stream);
	~OpQ5_T9da750();
	void serialize(ostream &stream);
};

struct OpQ5_T9da7b0
{
	char pad[4];
	OpQ5_T9da7b0(istream &stream);
	~OpQ5_T9da7b0();
	void serialize(ostream &stream);
};

struct OpQ5_T9da7f0
{
	char pad[4];
	OpQ5_T9da7f0(istream &stream);
	~OpQ5_T9da7f0();
	void serialize(ostream &stream);
};

struct OpQ5_T9da980
{
	char pad[4];
	OpQ5_T9da980(istream &stream);
	~OpQ5_T9da980();
	void serialize(ostream &stream);
};

struct OpQ5_T9da9f0
{
	char pad[4];
	OpQ5_T9da9f0(istream &stream);
	~OpQ5_T9da9f0();
	void serialize(ostream &stream);
};

struct OpQ5_T9daa70
{
	char pad[100];
	OpQ5_T9daa70(istream &stream);
	~OpQ5_T9daa70();
	void serialize(ostream &stream);
};

struct OpQ5_T9dab20
{
	char pad[24];
	OpQ5_T9dab20(istream &stream);
	~OpQ5_T9dab20();
	void serialize(ostream &stream);
};

struct OpQ5_T9dabd0
{
	char pad[32];
	OpQ5_T9dabd0(istream &stream);
	~OpQ5_T9dabd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dace0
{
	char pad[4];
	OpQ5_T9dace0(istream &stream);
	~OpQ5_T9dace0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dad20
{
	char pad[4];
	OpQ5_T9dad20(istream &stream);
	~OpQ5_T9dad20();
	void serialize(ostream &stream);
};

struct OpQ5_T9dad60
{
	char pad[4];
	OpQ5_T9dad60(istream &stream);
	~OpQ5_T9dad60();
	void serialize(ostream &stream);
};

struct OpQ5_T9db030
{
	char pad[4];
	OpQ5_T9db030(istream &stream);
	~OpQ5_T9db030();
	void serialize(ostream &stream);
};

struct OpQ5_T9db0a0
{
	char pad[36];
	OpQ5_T9db0a0(istream &stream);
	~OpQ5_T9db0a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9db1e0
{
	char pad[36];
	OpQ5_T9db1e0(istream &stream);
	~OpQ5_T9db1e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9db290
{
	char pad[4];
	OpQ5_T9db290(istream &stream);
	~OpQ5_T9db290();
	void serialize(ostream &stream);
};

struct OpQ5_T9db2f0
{
	char pad[4];
	OpQ5_T9db2f0(istream &stream);
	~OpQ5_T9db2f0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dbd40
{
	char pad[4];
	OpQ5_T9dbd40(istream &stream);
	~OpQ5_T9dbd40();
	void serialize(ostream &stream);
};

struct OpQ5_T9dbe20
{
	char pad[4];
	OpQ5_T9dbe20(istream &stream);
	~OpQ5_T9dbe20();
	void serialize(ostream &stream);
};

struct OpQ5_T9dbe80
{
	char pad[4];
	OpQ5_T9dbe80(istream &stream);
	~OpQ5_T9dbe80();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc000
{
	char pad[4];
	OpQ5_T9dc000(istream &stream);
	~OpQ5_T9dc000();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc060
{
	char pad[4];
	OpQ5_T9dc060(istream &stream);
	~OpQ5_T9dc060();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc0c0
{
	char pad[4];
	OpQ5_T9dc0c0(istream &stream);
	~OpQ5_T9dc0c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc120
{
	char pad[4];
	OpQ5_T9dc120(istream &stream);
	~OpQ5_T9dc120();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc180
{
	char pad[4];
	OpQ5_T9dc180(istream &stream);
	~OpQ5_T9dc180();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc1e0
{
	char pad[4];
	OpQ5_T9dc1e0(istream &stream);
	~OpQ5_T9dc1e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc240
{
	char pad[4];
	OpQ5_T9dc240(istream &stream);
	~OpQ5_T9dc240();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc2a0
{
	char pad[4];
	OpQ5_T9dc2a0(istream &stream);
	~OpQ5_T9dc2a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc2e0
{
	char pad[4];
	OpQ5_T9dc2e0(istream &stream);
	~OpQ5_T9dc2e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc320
{
	char pad[4];
	OpQ5_T9dc320(istream &stream);
	~OpQ5_T9dc320();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc380
{
	char pad[4];
	OpQ5_T9dc380(istream &stream);
	~OpQ5_T9dc380();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc3e0
{
	char pad[4];
	OpQ5_T9dc3e0(istream &stream);
	~OpQ5_T9dc3e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc440
{
	char pad[4];
	OpQ5_T9dc440(istream &stream);
	~OpQ5_T9dc440();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc4a0
{
	char pad[4];
	OpQ5_T9dc4a0(istream &stream);
	~OpQ5_T9dc4a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc560
{
	char pad[4];
	OpQ5_T9dc560(istream &stream);
	~OpQ5_T9dc560();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc5c0
{
	char pad[4];
	OpQ5_T9dc5c0(istream &stream);
	~OpQ5_T9dc5c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc620
{
	char pad[12];
	OpQ5_T9dc620(istream &stream);
	~OpQ5_T9dc620();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc760
{
	char pad[20];
	OpQ5_T9dc760(istream &stream);
	~OpQ5_T9dc760();
	void serialize(ostream &stream);
};

struct OpQ5_T9dc950
{
	char pad[52];
	OpQ5_T9dc950(istream &stream);
	~OpQ5_T9dc950();
	void serialize(ostream &stream);
};

struct OpQ5_T9dca90
{
	char pad[96];
	OpQ5_T9dca90(istream &stream);
	~OpQ5_T9dca90();
	void serialize(ostream &stream);
};

struct OpQ5_T9dcbd0
{
	char pad[56];
	OpQ5_T9dcbd0(istream &stream);
	~OpQ5_T9dcbd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dcd10
{
	char pad[44];
	OpQ5_T9dcd10(istream &stream);
	~OpQ5_T9dcd10();
	void serialize(ostream &stream);
};

struct OpQ5_T9dce50
{
	char pad[16];
	OpQ5_T9dce50(istream &stream);
	~OpQ5_T9dce50();
	void serialize(ostream &stream);
};

struct OpQ5_T9dcf90
{
	char pad[12];
	OpQ5_T9dcf90(istream &stream);
	~OpQ5_T9dcf90();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd0d0
{
	char pad[16];
	OpQ5_T9dd0d0(istream &stream);
	~OpQ5_T9dd0d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd210
{
	char pad[36];
	OpQ5_T9dd210(istream &stream);
	~OpQ5_T9dd210();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd2c0
{
	char pad[12];
	OpQ5_T9dd2c0(istream &stream);
	~OpQ5_T9dd2c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd370
{
	char pad[12];
	OpQ5_T9dd370(istream &stream);
	~OpQ5_T9dd370();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd550
{
	char pad[20];
	OpQ5_T9dd550(istream &stream);
	~OpQ5_T9dd550();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd690
{
	char pad[36];
	OpQ5_T9dd690(istream &stream);
	~OpQ5_T9dd690();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd7d0
{
	char pad[28];
	OpQ5_T9dd7d0(istream &stream);
	~OpQ5_T9dd7d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dd910
{
	char pad[40];
	OpQ5_T9dd910(istream &stream);
	~OpQ5_T9dd910();
	void serialize(ostream &stream);
};

struct OpQ5_T9dda50
{
	char pad[52];
	OpQ5_T9dda50(istream &stream);
	~OpQ5_T9dda50();
	void serialize(ostream &stream);
};

struct OpQ5_T9ddc30
{
	char pad[44];
	OpQ5_T9ddc30(istream &stream);
	~OpQ5_T9ddc30();
	void serialize(ostream &stream);
};

struct OpQ5_T9ddd70
{
	char pad[12];
	OpQ5_T9ddd70(istream &stream);
	~OpQ5_T9ddd70();
	void serialize(ostream &stream);
};

struct OpQ5_T9ddef0
{
	char pad[4];
	OpQ5_T9ddef0(istream &stream);
	~OpQ5_T9ddef0();
	void serialize(ostream &stream);
};

struct OpQ5_T9ddf50
{
	char pad[4];
	OpQ5_T9ddf50(istream &stream);
	~OpQ5_T9ddf50();
	void serialize(ostream &stream);
};

struct OpQ5_T9ddfb0
{
	char pad[4];
	OpQ5_T9ddfb0(istream &stream);
	~OpQ5_T9ddfb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9de010
{
	char pad[4];
	OpQ5_T9de010(istream &stream);
	~OpQ5_T9de010();
	void serialize(ostream &stream);
};

struct OpQ5_T9de160
{
	char pad[4];
	OpQ5_T9de160(istream &stream);
	~OpQ5_T9de160();
	void serialize(ostream &stream);
};

struct OpQ5_T9de210
{
	char pad[4];
	OpQ5_T9de210(istream &stream);
	~OpQ5_T9de210();
	void serialize(ostream &stream);
};

struct OpQ5_T9de400
{
	char pad[4];
	OpQ5_T9de400(istream &stream);
	~OpQ5_T9de400();
	void serialize(ostream &stream);
};

struct OpQ5_T9de5c0
{
	char pad[4];
	OpQ5_T9de5c0(istream &stream);
	~OpQ5_T9de5c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9de730
{
	char pad[4];
	OpQ5_T9de730(istream &stream);
	~OpQ5_T9de730();
	void serialize(ostream &stream);
};

struct OpQ5_T9de820
{
	char pad[4];
	OpQ5_T9de820(istream &stream);
	~OpQ5_T9de820();
	void serialize(ostream &stream);
};

struct OpQ5_T9de940
{
	char pad[4];
	OpQ5_T9de940(istream &stream);
	~OpQ5_T9de940();
	void serialize(ostream &stream);
};

struct OpQ5_T9de980
{
	char pad[4];
	OpQ5_T9de980(istream &stream);
	~OpQ5_T9de980();
	void serialize(ostream &stream);
};

struct OpQ5_T9de9c0
{
	char pad[4];
	OpQ5_T9de9c0(istream &stream);
	~OpQ5_T9de9c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dea20
{
	char pad[4];
	OpQ5_T9dea20(istream &stream);
	~OpQ5_T9dea20();
	void serialize(ostream &stream);
};

struct OpQ5_T9dea80
{
	char pad[4];
	OpQ5_T9dea80(istream &stream);
	~OpQ5_T9dea80();
	void serialize(ostream &stream);
};

struct OpQ5_T9deac0
{
	char pad[4];
	OpQ5_T9deac0(istream &stream);
	~OpQ5_T9deac0();
	void serialize(ostream &stream);
};

struct OpQ5_T9deb20
{
	char pad[4];
	OpQ5_T9deb20(istream &stream);
	~OpQ5_T9deb20();
	void serialize(ostream &stream);
};

struct OpQ5_T9debd0
{
	char pad[44];
	OpQ5_T9debd0(istream &stream);
	~OpQ5_T9debd0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dec80
{
	char pad[52];
	OpQ5_T9dec80(istream &stream);
	~OpQ5_T9dec80();
	void serialize(ostream &stream);
};

struct OpQ5_T9ded30
{
	char pad[20];
	OpQ5_T9ded30(istream &stream);
	~OpQ5_T9ded30();
	void serialize(ostream &stream);
};

struct OpQ5_T9dee70
{
	char pad[16];
	OpQ5_T9dee70(istream &stream);
	~OpQ5_T9dee70();
	void serialize(ostream &stream);
};

struct OpQ5_T9defb0
{
	char pad[52];
	OpQ5_T9defb0(istream &stream);
	~OpQ5_T9defb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9df060
{
	char pad[52];
	OpQ5_T9df060(istream &stream);
	~OpQ5_T9df060();
	void serialize(ostream &stream);
};

struct OpQ5_T9df1a0
{
	char pad[28];
	OpQ5_T9df1a0(istream &stream);
	~OpQ5_T9df1a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9df390
{
	char pad[4];
	OpQ5_T9df390(istream &stream);
	~OpQ5_T9df390();
	void serialize(ostream &stream);
};

struct OpQ5_T9df4d0
{
	char pad[56];
	OpQ5_T9df4d0(istream &stream);
	~OpQ5_T9df4d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9df610
{
	char pad[4];
	OpQ5_T9df610(istream &stream);
	~OpQ5_T9df610();
	void serialize(ostream &stream);
};

struct OpQ5_T9df650
{
	char pad[3176];
	OpQ5_T9df650(istream &stream);
	~OpQ5_T9df650();
	void serialize(ostream &stream);
};

struct OpQ5_T9df700
{
	char pad[4];
	OpQ5_T9df700(istream &stream);
	~OpQ5_T9df700();
	void serialize(ostream &stream);
};

struct OpQ5_T9df780
{
	char pad[80];
	OpQ5_T9df780(istream &stream);
	~OpQ5_T9df780();
	void serialize(ostream &stream);
};

struct OpQ5_T9df8c0
{
	char pad[124];
	OpQ5_T9df8c0(istream &stream);
	~OpQ5_T9df8c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dfaa0
{
	char pad[44];
	OpQ5_T9dfaa0(istream &stream);
	~OpQ5_T9dfaa0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dfc30
{
	char pad[144];
	OpQ5_T9dfc30(istream &stream);
	~OpQ5_T9dfc30();
	void serialize(ostream &stream);
};

struct OpQ5_T9dfdc0
{
	char pad[216];
	OpQ5_T9dfdc0(istream &stream);
	~OpQ5_T9dfdc0();
	void serialize(ostream &stream);
};

struct OpQ5_T9dff00
{
	char pad[256];
	OpQ5_T9dff00(istream &stream);
	~OpQ5_T9dff00();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0040
{
	char pad[40];
	OpQ5_T9e0040(istream &stream);
	~OpQ5_T9e0040();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0180
{
	char pad[68];
	OpQ5_T9e0180(istream &stream);
	~OpQ5_T9e0180();
	void serialize(ostream &stream);
};

struct OpQ5_T9e02c0
{
	char pad[56];
	OpQ5_T9e02c0(istream &stream);
	~OpQ5_T9e02c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0400
{
	char pad[4];
	OpQ5_T9e0400(istream &stream);
	~OpQ5_T9e0400();
	void serialize(ostream &stream);
};

struct OpQ5_T9e04f0
{
	char pad[76];
	OpQ5_T9e04f0(istream &stream);
	~OpQ5_T9e04f0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0680
{
	char pad[172];
	OpQ5_T9e0680(istream &stream);
	~OpQ5_T9e0680();
	void serialize(ostream &stream);
};

struct OpQ5_T9e07c0
{
	char pad[32];
	OpQ5_T9e07c0(istream &stream);
	~OpQ5_T9e07c0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0900
{
	char pad[96];
	OpQ5_T9e0900(istream &stream);
	~OpQ5_T9e0900();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0a40
{
	char pad[72];
	OpQ5_T9e0a40(istream &stream);
	~OpQ5_T9e0a40();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0b80
{
	char pad[160];
	OpQ5_T9e0b80(istream &stream);
	~OpQ5_T9e0b80();
	void serialize(ostream &stream);
};

struct OpQ5_T9e0cc0
{
	char pad[208];
	OpQ5_T9e0cc0(istream &stream);
	~OpQ5_T9e0cc0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e13a0
{
	char pad[44];
	OpQ5_T9e13a0(istream &stream);
	~OpQ5_T9e13a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e14e0
{
	char pad[52];
	OpQ5_T9e14e0(istream &stream);
	~OpQ5_T9e14e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e1620
{
	char pad[256];
	OpQ5_T9e1620(istream &stream);
	~OpQ5_T9e1620();
	void serialize(ostream &stream);
};

struct OpQ5_T9e1760
{
	char pad[60];
	OpQ5_T9e1760(istream &stream);
	~OpQ5_T9e1760();
	void serialize(ostream &stream);
};

struct OpQ5_T9e18a0
{
	char pad[192];
	OpQ5_T9e18a0(istream &stream);
	~OpQ5_T9e18a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e19e0
{
	char pad[24];
	OpQ5_T9e19e0(istream &stream);
	~OpQ5_T9e19e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e1b20
{
	char pad[28];
	OpQ5_T9e1b20(istream &stream);
	~OpQ5_T9e1b20();
	void serialize(ostream &stream);
};

struct OpQ5_T9e1c60
{
	char pad[96];
	OpQ5_T9e1c60(istream &stream);
	~OpQ5_T9e1c60();
	void serialize(ostream &stream);
};

struct OpQ5_T9e1da0
{
	char pad[68];
	OpQ5_T9e1da0(istream &stream);
	~OpQ5_T9e1da0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e1ee0
{
	char pad[80];
	OpQ5_T9e1ee0(istream &stream);
	~OpQ5_T9e1ee0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e2080
{
	char pad[40];
	OpQ5_T9e2080(istream &stream);
	~OpQ5_T9e2080();
	void serialize(ostream &stream);
};

struct OpQ5_T9e2130
{
	char pad[4];
	OpQ5_T9e2130(istream &stream);
	~OpQ5_T9e2130();
	void serialize(ostream &stream);
};

struct OpQ5_T9e2170
{
	char pad[36];
	OpQ5_T9e2170(istream &stream);
	~OpQ5_T9e2170();
	void serialize(ostream &stream);
};

struct OpQ5_T9e22b0
{
	char pad[4];
	OpQ5_T9e22b0(istream &stream);
	~OpQ5_T9e22b0();
	void serialize(ostream &stream);
};

struct OpQ5_T9e2730
{
	char pad[4];
	OpQ5_T9e2730(istream &stream);
	~OpQ5_T9e2730();
	void serialize(ostream &stream);
};

struct OpQ5_T9e2b60
{
	char pad[4];
	OpQ5_T9e2b60(istream &stream);
	~OpQ5_T9e2b60();
	void serialize(ostream &stream);
};

struct OpQ5_T9e2c40
{
	char pad[4];
	OpQ5_T9e2c40(istream &stream);
	~OpQ5_T9e2c40();
	void serialize(ostream &stream);
};

struct OpQ5_T9ed5d0
{
	char pad[4];
	OpQ5_T9ed5d0(istream &stream);
	~OpQ5_T9ed5d0();
	void serialize(ostream &stream);
};

struct OpQ5_T9ed630
{
	char pad[4];
	OpQ5_T9ed630(istream &stream);
	~OpQ5_T9ed630();
	void serialize(ostream &stream);
};

struct OpQ5_T9ed890
{
	char pad[4];
	OpQ5_T9ed890(istream &stream);
	~OpQ5_T9ed890();
	void serialize(ostream &stream);
};

struct OpQ5_T9ed8f0
{
	char pad[4];
	OpQ5_T9ed8f0(istream &stream);
	~OpQ5_T9ed8f0();
	void serialize(ostream &stream);
};

struct OpQ5_T9eda10
{
	char pad[4];
	OpQ5_T9eda10(istream &stream);
	~OpQ5_T9eda10();
	void serialize(ostream &stream);
};

struct OpQ5_T9edaa0
{
	char pad[4];
	OpQ5_T9edaa0(istream &stream);
	~OpQ5_T9edaa0();
	void serialize(ostream &stream);
};

struct OpQ5_T9ee370
{
	char pad[12];
	OpQ5_T9ee370(istream &stream);
	~OpQ5_T9ee370();
	void serialize(ostream &stream);
};

struct OpQ5_T9ee900
{
	char pad[4];
	OpQ5_T9ee900(istream &stream);
	~OpQ5_T9ee900();
	void serialize(ostream &stream);
};

struct OpQ5_T9ee940
{
	char pad[4];
	OpQ5_T9ee940(istream &stream);
	~OpQ5_T9ee940();
	void serialize(ostream &stream);
};

struct OpQ5_T9ee9a0
{
	char pad[76];
	OpQ5_T9ee9a0(istream &stream);
	~OpQ5_T9ee9a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9eea50
{
	char pad[16];
	OpQ5_T9eea50(istream &stream);
	~OpQ5_T9eea50();
	void serialize(ostream &stream);
};

struct OpQ5_T9eeb90
{
	char pad[4];
	OpQ5_T9eeb90(istream &stream);
	~OpQ5_T9eeb90();
	void serialize(ostream &stream);
};

struct OpQ5_T9eebf0
{
	char pad[4];
	OpQ5_T9eebf0(istream &stream);
	~OpQ5_T9eebf0();
	void serialize(ostream &stream);
};

struct OpQ5_T9eec50
{
	char pad[4];
	OpQ5_T9eec50(istream &stream);
	~OpQ5_T9eec50();
	void serialize(ostream &stream);
};

struct OpQ5_T9eecb0
{
	char pad[4];
	OpQ5_T9eecb0(istream &stream);
	~OpQ5_T9eecb0();
	void serialize(ostream &stream);
};

struct OpQ5_T9eeec0
{
	char pad[16];
	OpQ5_T9eeec0(istream &stream);
	~OpQ5_T9eeec0();
	void serialize(ostream &stream);
};

struct OpQ5_T9ef000
{
	char pad[36];
	OpQ5_T9ef000(istream &stream);
	~OpQ5_T9ef000();
	void serialize(ostream &stream);
};

struct OpQ5_T9ef2e0
{
	char pad[4];
	OpQ5_T9ef2e0(istream &stream);
	~OpQ5_T9ef2e0();
	void serialize(ostream &stream);
};

struct OpQ5_T9ef340
{
	char pad[4];
	OpQ5_T9ef340(istream &stream);
	~OpQ5_T9ef340();
	void serialize(ostream &stream);
};

struct OpQ5_T9ef3a0
{
	char pad[4];
	OpQ5_T9ef3a0(istream &stream);
	~OpQ5_T9ef3a0();
	void serialize(ostream &stream);
};

struct OpQ5_T9ef400
{
	char pad[4];
	OpQ5_T9ef400(istream &stream);
	~OpQ5_T9ef400();
	void serialize(ostream &stream);
};

struct OpQ5_T9ef560
{
	char pad[4];
	OpQ5_T9ef560(istream &stream);
	~OpQ5_T9ef560();
	void serialize(ostream &stream);
};

template void OpQ5_readObjects<OpQ5_T9cf200>(istream &stream, vector<OpQ5_T9cf200*> &v, int skip);
template void OpQ5_clearObjects<OpQ5_T9cf360>(vector<OpQ5_T9cf360*> &v);
template void OpQ5_deleteObjects<OpQ5_T9cf360>(vector<OpQ5_T9cf360*> &v);
template void OpQ5_deleteObjects<OpQ5_T9cfb10>(vector<OpQ5_T9cfb10*> &v);
template void OpQ5_deleteObjects<OpQ5_T9cfb70>(vector<OpQ5_T9cfb70*> &v);
template void OpQ5_readObjects<C065_Rec5188c0>(istream &stream, vector<C065_Rec5188c0*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9d02a0>(ostream &stream, vector<OpQ5_T9d02a0*> &v);
template void OpQ5_clearObjects<OpQ5_T9e2c40>(vector<OpQ5_T9e2c40*> &v);
template void OpQ5_deleteObjects<OpQ5_T9d0710>(vector<OpQ5_T9d0710*> &v);
template void OpQ5_deleteObject<OpQ5_T9d0770>(vector<OpQ5_T9d0770*> &v, int index);
template void OpQ5_readObjects<OpQ5_T9d1050>(istream &stream, vector<OpQ5_T9d1050*> &v, int skip);
template void OpQ5_writePointer<OpQ5_T9d1190>(ostream &stream, OpQ5_T9d1190 *&p);
template void OpQ5_writeObjects<OpQ5_T9d11d0>(ostream &stream, vector<OpQ5_T9d11d0*> &v);
template void OpQ5_writePointer<OpQ5_T9d1230>(ostream &stream, OpQ5_T9d1230 *&p);
template void OpQ5_writePointer<OpQ5_T9d1270>(ostream &stream, OpQ5_T9d1270 *&p);
template void OpQ5_readPointer<OpQ5_T9d12b0>(istream &stream, OpQ5_T9d12b0 *&p);
template void OpQ5_readObjects<OpQ5_T9d1360>(istream &stream, vector<OpQ5_T9d1360*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9d14a0>(istream &stream, OpQ5_T9d14a0 *&p);
template void OpQ5_readPointer<OpQ5_T9d1550>(istream &stream, OpQ5_T9d1550 *&p);
template void OpQ5_deleteObjects<OpQ5_T9d1d80>(vector<OpQ5_T9d1d80*> &v);
template void OpQ5_readPointer<OpQ5_T9d1de0>(istream &stream, OpQ5_T9d1de0 *&p);
template void OpQ5_readObjects<OpQ5_T9d1e90>(istream &stream, vector<OpQ5_T9d1e90*> &v, int skip);
template void OpQ5_writePointer<OpQ5_T9d1fd0>(ostream &stream, OpQ5_T9d1fd0 *&p);
template void OpQ5_writeObjects<OpQ5_T9d2010>(ostream &stream, vector<OpQ5_T9d2010*> &v);
template void OpQ5_clearObjects<OpQ5_T9ed5d0>(vector<OpQ5_T9ed5d0*> &v);
template void OpQ5_readObjects<OpQ5_T9d3bd0>(istream &stream, vector<OpQ5_T9d3bd0*> &v, int skip);
template void OpQ5_deleteObjectAndStep<OpQ5_T9d3d10>(vector<OpQ5_T9d3d10*> &v, int &index);
template void OpQ5_writeObjects<OpQ5_T9d3e30>(ostream &stream, vector<OpQ5_T9d3e30*> &v);
template void OpQ5_clearObjects<OpQ5_T9d8e70>(vector<OpQ5_T9d8e70*> &v);
template void OpQ5_clearObjects<OpQ5_T9ed890>(vector<OpQ5_T9ed890*> &v);
template void OpQ5_clearObjects<OpQ5_T9ed8f0>(vector<OpQ5_T9ed8f0*> &v);
template void OpQ5_clearObjects<OpQ5_T9eda10>(vector<OpQ5_T9eda10*> &v);
template void OpQ5_writeObjects<OpQ5_T9d4160>(ostream &stream, vector<OpQ5_T9d4160*> &v);
template void OpQ5_readObjects<OpQ5_T9d41c0>(istream &stream, vector<OpQ5_T9d41c0*> &v, int skip);
template void OpQ5_deleteObject<OpQ5_T9d4760>(vector<OpQ5_T9d4760*> &v, int index);
template void OpQ5_deleteObject<OpQ5_T9d47d0>(vector<OpQ5_T9d47d0*> &v, int index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9d4840>(vector<OpQ5_T9d4840*> &v, int &index);
template void OpQ5_deleteObject<OpQ5_T9d48c0>(vector<OpQ5_T9d48c0*> &v, int index);
template void OpQ5_clearObjects<OpQ5_T9edaa0>(vector<OpQ5_T9edaa0*> &v);
template void OpQ5_deleteObject<OpQ5_T9d4950>(vector<OpQ5_T9d4950*> &v, int index);
template void OpQ5_readReference<OpQ5_T9d5880>(istream &stream, OpQ5_T9d5880 *&p, vector<OpQ5_T9d5880*> &list);
template void OpQ5_readReference<OpQ5_T9d5970>(istream &stream, OpQ5_T9d5970 *&p, vector<OpQ5_T9d5970*> &list);
template void OpQ5_readReference<OpQ5_T9d5da0>(istream &stream, OpQ5_T9d5da0 *&p, vector<OpQ5_T9d5da0*> &list);
template void OpQ5_readReference<OpQ5_T9d5e90>(istream &stream, OpQ5_T9d5e90 *&p, vector<OpQ5_T9d5e90*> &list);
template void OpQ5_readReference<OpQ5_T9d5f80>(istream &stream, OpQ5_T9d5f80 *&p, vector<OpQ5_T9d5f80*> &list);
template void OpQ5_writeObjects<OpQ5_T9d6070>(ostream &stream, vector<OpQ5_T9d6070*> &v);
template void OpQ5_readObjects<OpQ5_T9d60d0>(istream &stream, vector<OpQ5_T9d60d0*> &v, int skip);
template void OpQ5_deleteObject<OpQ5_T9d6210>(vector<OpQ5_T9d6210*> &v, int index);
template void OpQ5_readReference<OpQ5_T9d6300>(istream &stream, OpQ5_T9d6300 *&p, vector<OpQ5_T9d6300*> &list);
template void OpQ5_readReference<OpQ5_T9d6490>(istream &stream, OpQ5_T9d6490 *&p, vector<OpQ5_T9d6490*> &list);
template void OpQ5_readObjects<OpQ5_T9d6580>(istream &stream, vector<OpQ5_T9d6580*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9d6770>(ostream &stream, vector<OpQ5_T9d6770*> &v);
template void OpQ5_readReference<OpQ5_T9d67d0>(istream &stream, OpQ5_T9d67d0 *&p, vector<OpQ5_T9d67d0*> &list);
template void OpQ5_readReference<OpQ5_T9d68c0>(istream &stream, OpQ5_T9d68c0 *&p, vector<OpQ5_T9d68c0*> &list);
template void OpQ5_readReference<OpQ5_T9d69b0>(istream &stream, OpQ5_T9d69b0 *&p, vector<OpQ5_T9d69b0*> &list);
template void OpQ5_readReference<OpQ5_T9d6aa0>(istream &stream, OpQ5_T9d6aa0 *&p, vector<OpQ5_T9d6aa0*> &list);
template void OpQ5_readObjects<OpQ5_T9d6b90>(istream &stream, vector<OpQ5_T9d6b90*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9d6cd0>(istream &stream, vector<OpQ5_T9d6cd0*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9d6e60>(istream &stream, OpQ5_T9d6e60 *&p);
template void OpQ5_readPointer<OpQ5_T9d6f10>(istream &stream, OpQ5_T9d6f10 *&p);
template void OpQ5_readReference<OpQ5_T9d6fc0>(istream &stream, OpQ5_T9d6fc0 *&p, vector<OpQ5_T9d6fc0*> &list);
template void OpQ5_readObjects<OpQ5_T9d7150>(istream &stream, vector<OpQ5_T9d7150*> &v, int skip);
template void OpQ5_deleteObject<OpQ5_T9d7850>(vector<OpQ5_T9d7850*> &v, int index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9d7fb0>(vector<OpQ5_T9d7fb0*> &v, int &index);
template void OpQ5_readReference<OpQ5_T9d8110>(istream &stream, OpQ5_T9d8110 *&p, vector<OpQ5_T9d8110*> &list);
template void OpQ5_readObjects<OpQ5_T9d8250>(istream &stream, vector<OpQ5_T9d8250*> &v, int skip);
template void OpQ5_readReference<OpQ5_T9d8390>(istream &stream, OpQ5_T9d8390 *&p, vector<OpQ5_T9d8390*> &list);
template void OpQ5_writePointer<OpQ5_T9d84d0>(ostream &stream, OpQ5_T9d84d0 *&p);
template void OpQ5_readPointer<OpQ5_T9d8510>(istream &stream, OpQ5_T9d8510 *&p);
template void OpQ5_readObjects<OpQ5_T9d86c0>(istream &stream, vector<OpQ5_T9d86c0*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9d8800>(ostream &stream, vector<OpQ5_T9d8800*> &v);
template void OpQ5_readObjects<OpQ5_T9d8860>(istream &stream, vector<OpQ5_T9d8860*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9d89a0>(istream &stream, OpQ5_T9d89a0 *&p);
template void OpQ5_readPointer<OpQ5_T9d8a50>(istream &stream, OpQ5_T9d8a50 *&p);
template void OpQ5_readPointer<OpQ5_T9d8b00>(istream &stream, OpQ5_T9d8b00 *&p);
template void OpQ5_readObjects<OpQ5_T9d8bb0>(istream &stream, vector<OpQ5_T9d8bb0*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9d8cf0>(ostream &stream, vector<OpQ5_T9d8cf0*> &v);
template void OpQ5_writePointer<OpQ5_T9d8d50>(ostream &stream, OpQ5_T9d8d50 *&p);
template void OpQ5_writePointer<OpQ5_T9d8d90>(ostream &stream, OpQ5_T9d8d90 *&p);
template void OpQ5_writePointer<OpQ5_T9d8dd0>(ostream &stream, OpQ5_T9d8dd0 *&p);
template void OpQ5_writeObjects<OpQ5_T9d8e10>(ostream &stream, vector<OpQ5_T9d8e10*> &v);
template void OpQ5_deleteObjects<OpQ5_T9d8e70>(vector<OpQ5_T9d8e70*> &v);
template void OpQ5_readReference<OpQ5_T9d92d0>(istream &stream, OpQ5_T9d92d0 *&p, vector<OpQ5_T9d92d0*> &list);
template void OpQ5_writeObjects<OpQ5_T9d95a0>(ostream &stream, vector<OpQ5_T9d95a0*> &v);
template void OpQ5_writePointer<OpQ5_T9d9660>(ostream &stream, OpQ5_T9d9660 *&p);
template void OpQ5_readObjects<OpQ5_T9d96a0>(istream &stream, vector<OpQ5_T9d96a0*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9d97e0>(istream &stream, OpQ5_T9d97e0 *&p);
template void OpQ5_deleteObjects<OpQ5_T9d9bb0>(vector<OpQ5_T9d9bb0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9d9c50>(vector<OpQ5_T9d9c50*> &v);
template void OpQ5_writePointer<OpQ5_T9d9cb0>(ostream &stream, OpQ5_T9d9cb0 *&p);
template void OpQ5_writePointer<OpQ5_T9d9cf0>(ostream &stream, OpQ5_T9d9cf0 *&p);
template void OpQ5_readReference<OpQ5_T9d9d30>(istream &stream, OpQ5_T9d9d30 *&p, vector<OpQ5_T9d9d30*> &list);
template void OpQ5_readPointer<OpQ5_T9d9e20>(istream &stream, OpQ5_T9d9e20 *&p);
template void OpQ5_readPointer<OpQ5_T9d9ed0>(istream &stream, OpQ5_T9d9ed0 *&p);
template void OpQ5_readReference<OpQ5_T9da040>(istream &stream, OpQ5_T9da040 *&p, vector<OpQ5_T9da040*> &list);
template void OpQ5_clearObjects<OpQ5_T9d1d80>(vector<OpQ5_T9d1d80*> &v);
template void OpQ5_readObjects<OpQ5_T9da380>(istream &stream, vector<OpQ5_T9da380*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9da4c0>(istream &stream, OpQ5_T9da4c0 *&p);
template void OpQ5_readObjects<OpQ5_T9da570>(istream &stream, vector<OpQ5_T9da570*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9da750>(ostream &stream, vector<OpQ5_T9da750*> &v);
template void OpQ5_writePointer<OpQ5_T9da7b0>(ostream &stream, OpQ5_T9da7b0 *&p);
template void OpQ5_writeObjects<OpQ5_T9da7f0>(ostream &stream, vector<OpQ5_T9da7f0*> &v);
template void OpQ5_deleteObject<OpQ5_T9da980>(vector<OpQ5_T9da980*> &v, int index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9da9f0>(vector<OpQ5_T9da9f0*> &v, int &index);
template void OpQ5_readPointer<OpQ5_T9daa70>(istream &stream, OpQ5_T9daa70 *&p);
template void OpQ5_readPointer<OpQ5_T9dab20>(istream &stream, OpQ5_T9dab20 *&p);
template void OpQ5_readPointer<OpQ5_T9dabd0>(istream &stream, OpQ5_T9dabd0 *&p);
template void OpQ5_writePointer<OpQ5_T9dace0>(ostream &stream, OpQ5_T9dace0 *&p);
template void OpQ5_writePointer<OpQ5_T9dad20>(ostream &stream, OpQ5_T9dad20 *&p);
template void OpQ5_writePointer<OpQ5_T9dad60>(ostream &stream, OpQ5_T9dad60 *&p);
template void OpQ5_deleteObject<OpQ5_T9db030>(vector<OpQ5_T9db030*> &v, int index);
template void OpQ5_readObjects<OpQ5_T9db0a0>(istream &stream, vector<OpQ5_T9db0a0*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9db1e0>(istream &stream, OpQ5_T9db1e0 *&p);
template void OpQ5_writeObjects<OpQ5_T9db290>(ostream &stream, vector<OpQ5_T9db290*> &v);
template void OpQ5_writePointer<OpQ5_T9db2f0>(ostream &stream, OpQ5_T9db2f0 *&p);
template void OpQ5_deleteObjectAndStep<OpQ5_T9dbd40>(vector<OpQ5_T9dbd40*> &v, int &index);
template void OpQ5_writeObjects<OpQ5_T9dbe20>(ostream &stream, vector<OpQ5_T9dbe20*> &v);
template void OpQ5_writeObjects<OpQ5_T9dbe80>(ostream &stream, vector<OpQ5_T9dbe80*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc000>(ostream &stream, vector<OpQ5_T9dc000*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc060>(ostream &stream, vector<OpQ5_T9dc060*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc0c0>(ostream &stream, vector<OpQ5_T9dc0c0*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc120>(ostream &stream, vector<OpQ5_T9dc120*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc180>(ostream &stream, vector<OpQ5_T9dc180*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc1e0>(ostream &stream, vector<OpQ5_T9dc1e0*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc240>(ostream &stream, vector<OpQ5_T9dc240*> &v);
template void OpQ5_writePointer<OpQ5_T9dc2a0>(ostream &stream, OpQ5_T9dc2a0 *&p);
template void OpQ5_writePointer<OpQ5_T9dc2e0>(ostream &stream, OpQ5_T9dc2e0 *&p);
template void OpQ5_writeObjects<OpQ5_T9dc320>(ostream &stream, vector<OpQ5_T9dc320*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc380>(ostream &stream, vector<OpQ5_T9dc380*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc3e0>(ostream &stream, vector<OpQ5_T9dc3e0*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc440>(ostream &stream, vector<OpQ5_T9dc440*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc4a0>(ostream &stream, vector<OpQ5_T9dc4a0*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc560>(ostream &stream, vector<OpQ5_T9dc560*> &v);
template void OpQ5_writeObjects<OpQ5_T9dc5c0>(ostream &stream, vector<OpQ5_T9dc5c0*> &v);
template void OpQ5_readObjects<OpQ5_T9dc620>(istream &stream, vector<OpQ5_T9dc620*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dc760>(istream &stream, vector<OpQ5_T9dc760*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dc950>(istream &stream, vector<OpQ5_T9dc950*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dca90>(istream &stream, vector<OpQ5_T9dca90*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dcbd0>(istream &stream, vector<OpQ5_T9dcbd0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dcd10>(istream &stream, vector<OpQ5_T9dcd10*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dce50>(istream &stream, vector<OpQ5_T9dce50*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dcf90>(istream &stream, vector<OpQ5_T9dcf90*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dd0d0>(istream &stream, vector<OpQ5_T9dd0d0*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9dd210>(istream &stream, OpQ5_T9dd210 *&p);
template void OpQ5_readPointer<OpQ5_T9dd2c0>(istream &stream, OpQ5_T9dd2c0 *&p);
template void OpQ5_readObjects<OpQ5_T9dd370>(istream &stream, vector<OpQ5_T9dd370*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dd550>(istream &stream, vector<OpQ5_T9dd550*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dd690>(istream &stream, vector<OpQ5_T9dd690*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dd7d0>(istream &stream, vector<OpQ5_T9dd7d0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dd910>(istream &stream, vector<OpQ5_T9dd910*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dda50>(istream &stream, vector<OpQ5_T9dda50*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9ddc30>(istream &stream, vector<OpQ5_T9ddc30*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9ddd70>(istream &stream, vector<OpQ5_T9ddd70*> &v, int skip);
template void OpQ5_clearObjects<OpQ5_T9eeb90>(vector<OpQ5_T9eeb90*> &v);
template void OpQ5_clearObjects<OpQ5_T9eebf0>(vector<OpQ5_T9eebf0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ddef0>(vector<OpQ5_T9ddef0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ddf50>(vector<OpQ5_T9ddf50*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ddfb0>(vector<OpQ5_T9ddfb0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9de010>(vector<OpQ5_T9de010*> &v);
template void OpQ5_clearObjects<OpQ5_T9eec50>(vector<OpQ5_T9eec50*> &v);
template void OpQ5_clearObjects<OpQ5_T9eecb0>(vector<OpQ5_T9eecb0*> &v);
template void OpQ5_deleteObject<OpQ5_T9de160>(vector<OpQ5_T9de160*> &v, int index);
template void OpQ5_deleteObject<OpQ5_T9de210>(vector<OpQ5_T9de210*> &v, int index);
template void OpQ5_deleteObject<OpQ5_T9de400>(vector<OpQ5_T9de400*> &v, int index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9de5c0>(vector<OpQ5_T9de5c0*> &v, int &index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9de730>(vector<OpQ5_T9de730*> &v, int &index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9de820>(vector<OpQ5_T9de820*> &v, int &index);
template void OpQ5_writePointer<OpQ5_T9de940>(ostream &stream, OpQ5_T9de940 *&p);
template void OpQ5_writePointer<OpQ5_T9de980>(ostream &stream, OpQ5_T9de980 *&p);
template void OpQ5_writeObjects<OpQ5_T9de9c0>(ostream &stream, vector<OpQ5_T9de9c0*> &v);
template void OpQ5_writeObjects<OpQ5_T9dea20>(ostream &stream, vector<OpQ5_T9dea20*> &v);
template void OpQ5_writePointer<OpQ5_T9dea80>(ostream &stream, OpQ5_T9dea80 *&p);
template void OpQ5_writeObjects<OpQ5_T9deac0>(ostream &stream, vector<OpQ5_T9deac0*> &v);
template void OpQ5_writeObjects<OpQ5_T9deb20>(ostream &stream, vector<OpQ5_T9deb20*> &v);
template void OpQ5_readPointer<OpQ5_T9debd0>(istream &stream, OpQ5_T9debd0 *&p);
template void OpQ5_readPointer<OpQ5_T9dec80>(istream &stream, OpQ5_T9dec80 *&p);
template void OpQ5_readObjects<OpQ5_T9ded30>(istream &stream, vector<OpQ5_T9ded30*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dee70>(istream &stream, vector<OpQ5_T9dee70*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9defb0>(istream &stream, OpQ5_T9defb0 *&p);
template void OpQ5_readObjects<OpQ5_T9df060>(istream &stream, vector<OpQ5_T9df060*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9df1a0>(istream &stream, vector<OpQ5_T9df1a0*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9df390>(ostream &stream, vector<OpQ5_T9df390*> &v);
template void OpQ5_readObjects<OpQ5_T9df4d0>(istream &stream, vector<OpQ5_T9df4d0*> &v, int skip);
template void OpQ5_writePointer<OpQ5_T9df610>(ostream &stream, OpQ5_T9df610 *&p);
template void OpQ5_readPointer<OpQ5_T9df650>(istream &stream, OpQ5_T9df650 *&p);
template void OpQ5_deleteObjectAndStep<OpQ5_T9df700>(vector<OpQ5_T9df700*> &v, int &index);
template void OpQ5_readObjects<OpQ5_T9df780>(istream &stream, vector<OpQ5_T9df780*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9df8c0>(istream &stream, vector<OpQ5_T9df8c0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dfaa0>(istream &stream, vector<OpQ5_T9dfaa0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dfc30>(istream &stream, vector<OpQ5_T9dfc30*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dfdc0>(istream &stream, vector<OpQ5_T9dfdc0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9dff00>(istream &stream, vector<OpQ5_T9dff00*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0040>(istream &stream, vector<OpQ5_T9e0040*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0180>(istream &stream, vector<OpQ5_T9e0180*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e02c0>(istream &stream, vector<OpQ5_T9e02c0*> &v, int skip);
template void OpQ5_readReference<OpQ5_T9e0400>(istream &stream, OpQ5_T9e0400 *&p, vector<OpQ5_T9e0400*> &list);
template void OpQ5_readObjects<OpQ5_T9e04f0>(istream &stream, vector<OpQ5_T9e04f0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0680>(istream &stream, vector<OpQ5_T9e0680*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e07c0>(istream &stream, vector<OpQ5_T9e07c0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0900>(istream &stream, vector<OpQ5_T9e0900*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0a40>(istream &stream, vector<OpQ5_T9e0a40*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0b80>(istream &stream, vector<OpQ5_T9e0b80*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e0cc0>(istream &stream, vector<OpQ5_T9e0cc0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e13a0>(istream &stream, vector<OpQ5_T9e13a0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e14e0>(istream &stream, vector<OpQ5_T9e14e0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e1620>(istream &stream, vector<OpQ5_T9e1620*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e1760>(istream &stream, vector<OpQ5_T9e1760*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e18a0>(istream &stream, vector<OpQ5_T9e18a0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e19e0>(istream &stream, vector<OpQ5_T9e19e0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e1b20>(istream &stream, vector<OpQ5_T9e1b20*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e1c60>(istream &stream, vector<OpQ5_T9e1c60*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e1da0>(istream &stream, vector<OpQ5_T9e1da0*> &v, int skip);
template void OpQ5_readObjects<OpQ5_T9e1ee0>(istream &stream, vector<OpQ5_T9e1ee0*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9e2080>(istream &stream, OpQ5_T9e2080 *&p);
template void OpQ5_writePointer<OpQ5_T9e2130>(ostream &stream, OpQ5_T9e2130 *&p);
template void OpQ5_readObjects<OpQ5_T9e2170>(istream &stream, vector<OpQ5_T9e2170*> &v, int skip);
template void OpQ5_writeObjects<OpQ5_T9e22b0>(ostream &stream, vector<OpQ5_T9e22b0*> &v);
template void OpQ5_clearObjects<OpQ5_T9ef2e0>(vector<OpQ5_T9ef2e0*> &v);
template void OpQ5_clearObjects<OpQ5_T9ef340>(vector<OpQ5_T9ef340*> &v);
template void OpQ5_clearObjects<OpQ5_T9ef3a0>(vector<OpQ5_T9ef3a0*> &v);
template void OpQ5_clearObjects<OpQ5_T9ef400>(vector<OpQ5_T9ef400*> &v);
template void OpQ5_deleteObjectAndStep<OpQ5_T9e2730>(vector<OpQ5_T9e2730*> &v, int &index);
template void OpQ5_deleteObjectAndStep<OpQ5_T9e2b60>(vector<OpQ5_T9e2b60*> &v, int &index);
template void OpQ5_clearObjects<OpQ5_T9ef560>(vector<OpQ5_T9ef560*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ed5d0>(vector<OpQ5_T9ed5d0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ed630>(vector<OpQ5_T9ed630*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ed890>(vector<OpQ5_T9ed890*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ed8f0>(vector<OpQ5_T9ed8f0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9eda10>(vector<OpQ5_T9eda10*> &v);
template void OpQ5_deleteObjects<OpQ5_T9edaa0>(vector<OpQ5_T9edaa0*> &v);
template void OpQ5_readObjects<OpQ5_T9ee370>(istream &stream, vector<OpQ5_T9ee370*> &v, int skip);
template void OpQ5_writePointer<OpQ5_T9ee900>(ostream &stream, OpQ5_T9ee900 *&p);
template void OpQ5_writeObjects<OpQ5_T9ee940>(ostream &stream, vector<OpQ5_T9ee940*> &v);
template void OpQ5_readPointer<OpQ5_T9ee9a0>(istream &stream, OpQ5_T9ee9a0 *&p);
template void OpQ5_readObjects<OpQ5_T9eea50>(istream &stream, vector<OpQ5_T9eea50*> &v, int skip);
template void OpQ5_deleteObjects<OpQ5_T9eeb90>(vector<OpQ5_T9eeb90*> &v);
template void OpQ5_deleteObjects<OpQ5_T9eebf0>(vector<OpQ5_T9eebf0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9eec50>(vector<OpQ5_T9eec50*> &v);
template void OpQ5_deleteObjects<OpQ5_T9eecb0>(vector<OpQ5_T9eecb0*> &v);
template void OpQ5_readObjects<OpQ5_T9eeec0>(istream &stream, vector<OpQ5_T9eeec0*> &v, int skip);
template void OpQ5_readPointer<OpQ5_T9ef000>(istream &stream, OpQ5_T9ef000 *&p);
template void OpQ5_deleteObjects<OpQ5_T9ef2e0>(vector<OpQ5_T9ef2e0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ef340>(vector<OpQ5_T9ef340*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ef3a0>(vector<OpQ5_T9ef3a0*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ef400>(vector<OpQ5_T9ef400*> &v);
template void OpQ5_deleteObjects<OpQ5_T9ef560>(vector<OpQ5_T9ef560*> &v);
template void readBinary<bool>(istream &stream, bool *value);
template void readBinary<int>(istream &stream, int *value);
template void writeBinary<int>(ostream &stream, int *value);
