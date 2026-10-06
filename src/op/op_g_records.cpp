// Recovered serialization template families. Placeholder record layouts.
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name

// ---- serialization helpers (placeholder names) ----

template <class T> void readBinary(istream &stream, T *value)	// NOTE: placeholder name
{
	stream.read((char*)value,sizeof(T));
}

template <class T> void writeBinary(ostream &stream, T *value)	// NOTE: placeholder name
{
	stream.write((char*)value,sizeof(T));
}

template <class T> void OpG_writeVector(ostream &stream, vector<T> &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		stream.write((char*)&v[i],sizeof(T));
}

template <class T> void OpG_readVector(istream &stream, vector<T> &v)	// NOTE: placeholder name
{
	int count;
	stream.read((char*)&count,sizeof(count));
	while (count)
	{
		T value;
		stream.read((char*)&value,sizeof(T));
		v.push_back(value);
		count--;
	}
}

template <class T> void OpG_writeObjects(ostream &stream, vector<T*> &v)	// NOTE: placeholder name
{
	unsigned int count = v.size();
	stream.write((char*)&count,sizeof(count));
	for (unsigned int i = 0; i < count; i++)
		v[i]->serialize(stream);
}

template <class T> void OpG_readObjects(istream &stream, vector<T*> &v, int skip)	// NOTE: placeholder name
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

template <class T> void OpG_writePointer(ostream &stream, T *&p)	// NOTE: placeholder name
{
	bool exists = p != NULL;
	writeBinary(stream,&exists);
	if (exists)
		p->serialize(stream);
}

template <class T> void OpG_readPointer(istream &stream, T *&p)	// NOTE: placeholder name
{
	bool exists;
	readBinary(stream,&exists);
	p = exists ? new T(stream) : NULL;
}

template <class T> void OpG_readReference(istream &stream, T *&p, vector<T*> &list)	// NOTE: placeholder name
{
	bool exists;
	readBinary(stream,&exists);
	if (exists)
	{
		int index;
		readBinary(stream,&index);
		if (index >= list.size())
		{
			logError("14.3","sdfklj245oi317r908fd");
			p = list[0];
		}
		else p = list[index];
	}
	else p = NULL;
}

template <class T> void OpG_deleteObjects(vector<T*> &v)	// NOTE: placeholder name
{
	for (unsigned int i = 0; i < v.size(); i++)
		delete v[i];
}

template <class T> void OpG_clearObjects(vector<T*> &v)	// NOTE: placeholder name
{
	OpG_deleteObjects(v);
	v.clear();
}

template <class T> void OpG_deleteObject(vector<T*> &v, int index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
}


struct OpG_Record_9d1360	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9d1360(istream &stream);
	~OpG_Record_9d1360();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9d1360>(istream &stream, vector<OpG_Record_9d1360*> &v, int skip);
struct OpG_Record_9d6580	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d6580(istream &stream);
	~OpG_Record_9d6580();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9d6580>(istream &stream, vector<OpG_Record_9d6580*> &v, int skip);
struct OpG_Record_9d8250	// NOTE: placeholder name
{
	int data[4];
	OpG_Record_9d8250(istream &stream);
	~OpG_Record_9d8250();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9d8250>(istream &stream, vector<OpG_Record_9d8250*> &v, int skip);
struct OpG_Record_9d8860	// NOTE: placeholder name
{
	int data[4];
	OpG_Record_9d8860(istream &stream);
	~OpG_Record_9d8860();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9d8860>(istream &stream, vector<OpG_Record_9d8860*> &v, int skip);
struct OpG_Record_9d96a0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d96a0(istream &stream);
	~OpG_Record_9d96a0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9d96a0>(istream &stream, vector<OpG_Record_9d96a0*> &v, int skip);
struct OpG_Record_9da570	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9da570(istream &stream);
	~OpG_Record_9da570();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9da570>(istream &stream, vector<OpG_Record_9da570*> &v, int skip);
struct OpG_Record_9db0a0	// NOTE: placeholder name
{
	int data[9];
	OpG_Record_9db0a0(istream &stream);
	~OpG_Record_9db0a0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9db0a0>(istream &stream, vector<OpG_Record_9db0a0*> &v, int skip);
struct OpG_Record_9dc620	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9dc620(istream &stream);
	~OpG_Record_9dc620();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dc620>(istream &stream, vector<OpG_Record_9dc620*> &v, int skip);
struct OpG_Record_9dc760	// NOTE: placeholder name
{
	int data[5];
	OpG_Record_9dc760(istream &stream);
	~OpG_Record_9dc760();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dc760>(istream &stream, vector<OpG_Record_9dc760*> &v, int skip);
struct OpG_Record_9dcbd0	// NOTE: placeholder name
{
	int data[14];
	OpG_Record_9dcbd0(istream &stream);
	~OpG_Record_9dcbd0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dcbd0>(istream &stream, vector<OpG_Record_9dcbd0*> &v, int skip);
struct OpG_Record_9dce50	// NOTE: placeholder name
{
	int data[4];
	OpG_Record_9dce50(istream &stream);
	~OpG_Record_9dce50();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dce50>(istream &stream, vector<OpG_Record_9dce50*> &v, int skip);
struct OpG_Record_9dcf90	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9dcf90(istream &stream);
	~OpG_Record_9dcf90();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dcf90>(istream &stream, vector<OpG_Record_9dcf90*> &v, int skip);
struct OpG_Record_9dd0d0	// NOTE: placeholder name
{
	int data[4];
	OpG_Record_9dd0d0(istream &stream);
	~OpG_Record_9dd0d0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dd0d0>(istream &stream, vector<OpG_Record_9dd0d0*> &v, int skip);
struct OpG_Record_9dd370	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9dd370(istream &stream);
	~OpG_Record_9dd370();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dd370>(istream &stream, vector<OpG_Record_9dd370*> &v, int skip);
struct OpG_Record_9dd550	// NOTE: placeholder name
{
	int data[5];
	OpG_Record_9dd550(istream &stream);
	~OpG_Record_9dd550();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dd550>(istream &stream, vector<OpG_Record_9dd550*> &v, int skip);
struct OpG_Record_9dd690	// NOTE: placeholder name
{
	int data[9];
	OpG_Record_9dd690(istream &stream);
	~OpG_Record_9dd690();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dd690>(istream &stream, vector<OpG_Record_9dd690*> &v, int skip);
struct OpG_Record_9dd7d0	// NOTE: placeholder name
{
	int data[7];
	OpG_Record_9dd7d0(istream &stream);
	~OpG_Record_9dd7d0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dd7d0>(istream &stream, vector<OpG_Record_9dd7d0*> &v, int skip);
struct OpG_Record_9dd910	// NOTE: placeholder name
{
	int data[10];
	OpG_Record_9dd910(istream &stream);
	~OpG_Record_9dd910();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dd910>(istream &stream, vector<OpG_Record_9dd910*> &v, int skip);
struct OpG_Record_9dda50	// NOTE: placeholder name
{
	int data[13];
	OpG_Record_9dda50(istream &stream);
	~OpG_Record_9dda50();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dda50>(istream &stream, vector<OpG_Record_9dda50*> &v, int skip);
struct OpG_Record_9ddc30	// NOTE: placeholder name
{
	int data[11];
	OpG_Record_9ddc30(istream &stream);
	~OpG_Record_9ddc30();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9ddc30>(istream &stream, vector<OpG_Record_9ddc30*> &v, int skip);
struct OpG_Record_9ddd70	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9ddd70(istream &stream);
	~OpG_Record_9ddd70();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9ddd70>(istream &stream, vector<OpG_Record_9ddd70*> &v, int skip);
struct OpG_Record_9ded30	// NOTE: placeholder name
{
	int data[5];
	OpG_Record_9ded30(istream &stream);
	~OpG_Record_9ded30();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9ded30>(istream &stream, vector<OpG_Record_9ded30*> &v, int skip);
struct OpG_Record_9dee70	// NOTE: placeholder name
{
	int data[4];
	OpG_Record_9dee70(istream &stream);
	~OpG_Record_9dee70();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dee70>(istream &stream, vector<OpG_Record_9dee70*> &v, int skip);
struct OpG_Record_9df060	// NOTE: placeholder name
{
	int data[13];
	OpG_Record_9df060(istream &stream);
	~OpG_Record_9df060();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9df060>(istream &stream, vector<OpG_Record_9df060*> &v, int skip);
struct OpG_Record_9df1a0	// NOTE: placeholder name
{
	int data[7];
	OpG_Record_9df1a0(istream &stream);
	~OpG_Record_9df1a0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9df1a0>(istream &stream, vector<OpG_Record_9df1a0*> &v, int skip);
struct OpG_Record_9df4d0	// NOTE: placeholder name
{
	int data[14];
	OpG_Record_9df4d0(istream &stream);
	~OpG_Record_9df4d0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9df4d0>(istream &stream, vector<OpG_Record_9df4d0*> &v, int skip);
struct OpG_Record_9dfaa0	// NOTE: placeholder name
{
	int data[11];
	OpG_Record_9dfaa0(istream &stream);
	~OpG_Record_9dfaa0();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Record_9dfaa0>(istream &stream, vector<OpG_Record_9dfaa0*> &v, int skip);
struct OpG_Record_9d9e20	// NOTE: placeholder name
{
	int data[36];
	OpG_Record_9d9e20(istream &stream);
	~OpG_Record_9d9e20();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9d9e20>(istream &stream, OpG_Record_9d9e20 *&p);
struct OpG_Record_9d12b0	// NOTE: placeholder name
{
	int data[10];
	OpG_Record_9d12b0(istream &stream);
	~OpG_Record_9d12b0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9d12b0>(istream &stream, OpG_Record_9d12b0 *&p);
struct OpG_Record_9d8510	// NOTE: placeholder name
{
	int data[5];
	OpG_Record_9d8510(istream &stream);
	~OpG_Record_9d8510();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9d8510>(istream &stream, OpG_Record_9d8510 *&p);
struct OpG_Record_9d89a0	// NOTE: placeholder name
{
	int data[7];
	OpG_Record_9d89a0(istream &stream);
	~OpG_Record_9d89a0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9d89a0>(istream &stream, OpG_Record_9d89a0 *&p);
struct OpG_Record_9d8b00	// NOTE: placeholder name
{
	int data[4];
	OpG_Record_9d8b00(istream &stream);
	~OpG_Record_9d8b00();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9d8b00>(istream &stream, OpG_Record_9d8b00 *&p);
struct OpG_Record_9d9ed0	// NOTE: placeholder name
{
	int data[8];
	OpG_Record_9d9ed0(istream &stream);
	~OpG_Record_9d9ed0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9d9ed0>(istream &stream, OpG_Record_9d9ed0 *&p);
struct OpG_Record_9da4c0	// NOTE: placeholder name
{
	int data[5];
	OpG_Record_9da4c0(istream &stream);
	~OpG_Record_9da4c0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9da4c0>(istream &stream, OpG_Record_9da4c0 *&p);
struct OpG_Record_9dab20	// NOTE: placeholder name
{
	int data[6];
	OpG_Record_9dab20(istream &stream);
	~OpG_Record_9dab20();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9dab20>(istream &stream, OpG_Record_9dab20 *&p);
struct OpG_Record_9dabd0	// NOTE: placeholder name
{
	int data[8];
	OpG_Record_9dabd0(istream &stream);
	~OpG_Record_9dabd0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9dabd0>(istream &stream, OpG_Record_9dabd0 *&p);
struct OpG_Record_9db1e0	// NOTE: placeholder name
{
	int data[9];
	OpG_Record_9db1e0(istream &stream);
	~OpG_Record_9db1e0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9db1e0>(istream &stream, OpG_Record_9db1e0 *&p);
struct OpG_Record_9dd210	// NOTE: placeholder name
{
	int data[9];
	OpG_Record_9dd210(istream &stream);
	~OpG_Record_9dd210();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9dd210>(istream &stream, OpG_Record_9dd210 *&p);
struct OpG_Record_9dd2c0	// NOTE: placeholder name
{
	int data[3];
	OpG_Record_9dd2c0(istream &stream);
	~OpG_Record_9dd2c0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9dd2c0>(istream &stream, OpG_Record_9dd2c0 *&p);
struct OpG_Record_9debd0	// NOTE: placeholder name
{
	int data[11];
	OpG_Record_9debd0(istream &stream);
	~OpG_Record_9debd0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9debd0>(istream &stream, OpG_Record_9debd0 *&p);
struct OpG_Record_9dec80	// NOTE: placeholder name
{
	int data[13];
	OpG_Record_9dec80(istream &stream);
	~OpG_Record_9dec80();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9dec80>(istream &stream, OpG_Record_9dec80 *&p);
struct OpG_Record_9defb0	// NOTE: placeholder name
{
	int data[13];
	OpG_Record_9defb0(istream &stream);
	~OpG_Record_9defb0();
	void serialize(ostream &stream);
};
template void OpG_readPointer<OpG_Record_9defb0>(istream &stream, OpG_Record_9defb0 *&p);
struct OpG_Record_9d0770	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d0770(istream &stream);
	~OpG_Record_9d0770();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d0770>(vector<OpG_Record_9d0770*> &v, int index);
struct OpG_Record_9d4760	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d4760(istream &stream);
	~OpG_Record_9d4760();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d4760>(vector<OpG_Record_9d4760*> &v, int index);
struct OpG_Record_9d47d0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d47d0(istream &stream);
	~OpG_Record_9d47d0();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d47d0>(vector<OpG_Record_9d47d0*> &v, int index);
struct OpG_Record_9d48c0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d48c0(istream &stream);
	~OpG_Record_9d48c0();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d48c0>(vector<OpG_Record_9d48c0*> &v, int index);
struct OpG_Record_9d4950	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d4950(istream &stream);
	~OpG_Record_9d4950();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d4950>(vector<OpG_Record_9d4950*> &v, int index);
struct OpG_Record_9d6210	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d6210(istream &stream);
	~OpG_Record_9d6210();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d6210>(vector<OpG_Record_9d6210*> &v, int index);
struct OpG_Record_9d7850	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d7850(istream &stream);
	~OpG_Record_9d7850();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9d7850>(vector<OpG_Record_9d7850*> &v, int index);
struct OpG_Record_9da980	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9da980(istream &stream);
	~OpG_Record_9da980();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9da980>(vector<OpG_Record_9da980*> &v, int index);
struct OpG_Record_9db030	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9db030(istream &stream);
	~OpG_Record_9db030();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9db030>(vector<OpG_Record_9db030*> &v, int index);
struct OpG_Record_9de160	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de160(istream &stream);
	~OpG_Record_9de160();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9de160>(vector<OpG_Record_9de160*> &v, int index);
struct OpG_Record_9de210	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de210(istream &stream);
	~OpG_Record_9de210();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9de210>(vector<OpG_Record_9de210*> &v, int index);
struct OpG_Record_9de400	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de400(istream &stream);
	~OpG_Record_9de400();
	void serialize(ostream &stream);
};
template void OpG_deleteObject<OpG_Record_9de400>(vector<OpG_Record_9de400*> &v, int index);
struct OpG_Record_9ce720	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ce720(istream &stream);
	~OpG_Record_9ce720();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9ce720>(vector<OpG_Record_9ce720*> &v);
struct OpG_Record_9ce780	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ce780(istream &stream);
	~OpG_Record_9ce780();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9ce780>(vector<OpG_Record_9ce780*> &v);
struct OpG_Record_9cf360	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9cf360(istream &stream);
	~OpG_Record_9cf360();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9cf360>(vector<OpG_Record_9cf360*> &v);
struct OpG_Record_9cfb10	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9cfb10(istream &stream);
	~OpG_Record_9cfb10();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9cfb10>(vector<OpG_Record_9cfb10*> &v);
struct OpG_Record_9cfb70	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9cfb70(istream &stream);
	~OpG_Record_9cfb70();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9cfb70>(vector<OpG_Record_9cfb70*> &v);
struct OpG_Record_9d0710	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d0710(istream &stream);
	~OpG_Record_9d0710();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9d0710>(vector<OpG_Record_9d0710*> &v);
struct OpG_Record_9d1d80	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d1d80(istream &stream);
	~OpG_Record_9d1d80();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9d1d80>(vector<OpG_Record_9d1d80*> &v);
struct OpG_Record_9d8e70	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8e70(istream &stream);
	~OpG_Record_9d8e70();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9d8e70>(vector<OpG_Record_9d8e70*> &v);
struct OpG_Record_9d9bb0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d9bb0(istream &stream);
	~OpG_Record_9d9bb0();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9d9bb0>(vector<OpG_Record_9d9bb0*> &v);
struct OpG_Record_9d9c50	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d9c50(istream &stream);
	~OpG_Record_9d9c50();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9d9c50>(vector<OpG_Record_9d9c50*> &v);
struct OpG_Record_9ddef0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ddef0(istream &stream);
	~OpG_Record_9ddef0();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9ddef0>(vector<OpG_Record_9ddef0*> &v);
struct OpG_Record_9ddf50	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ddf50(istream &stream);
	~OpG_Record_9ddf50();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9ddf50>(vector<OpG_Record_9ddf50*> &v);
struct OpG_Record_9ddfb0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ddfb0(istream &stream);
	~OpG_Record_9ddfb0();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9ddfb0>(vector<OpG_Record_9ddfb0*> &v);
struct OpG_Record_9de010	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de010(istream &stream);
	~OpG_Record_9de010();
	void serialize(ostream &stream);
};
template void OpG_deleteObjects<OpG_Record_9de010>(vector<OpG_Record_9de010*> &v);
struct OpG_Record_9d11d0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d11d0(istream &stream);
	~OpG_Record_9d11d0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d11d0>(ostream &stream, vector<OpG_Record_9d11d0*> &v);
struct OpG_Record_9d2010	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d2010(istream &stream);
	~OpG_Record_9d2010();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d2010>(ostream &stream, vector<OpG_Record_9d2010*> &v);
struct OpG_Record_9d3e30	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d3e30(istream &stream);
	~OpG_Record_9d3e30();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d3e30>(ostream &stream, vector<OpG_Record_9d3e30*> &v);
struct OpG_Record_9d4160	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d4160(istream &stream);
	~OpG_Record_9d4160();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d4160>(ostream &stream, vector<OpG_Record_9d4160*> &v);
struct OpG_Record_9d6070	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d6070(istream &stream);
	~OpG_Record_9d6070();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d6070>(ostream &stream, vector<OpG_Record_9d6070*> &v);
struct OpG_Record_9d6770	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d6770(istream &stream);
	~OpG_Record_9d6770();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d6770>(ostream &stream, vector<OpG_Record_9d6770*> &v);
struct OpG_Record_9d8800	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8800(istream &stream);
	~OpG_Record_9d8800();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d8800>(ostream &stream, vector<OpG_Record_9d8800*> &v);
struct OpG_Record_9d8cf0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8cf0(istream &stream);
	~OpG_Record_9d8cf0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d8cf0>(ostream &stream, vector<OpG_Record_9d8cf0*> &v);
struct OpG_Record_9d8e10	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8e10(istream &stream);
	~OpG_Record_9d8e10();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d8e10>(ostream &stream, vector<OpG_Record_9d8e10*> &v);
struct OpG_Record_9d95a0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d95a0(istream &stream);
	~OpG_Record_9d95a0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9d95a0>(ostream &stream, vector<OpG_Record_9d95a0*> &v);
struct OpG_Record_9da750	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9da750(istream &stream);
	~OpG_Record_9da750();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9da750>(ostream &stream, vector<OpG_Record_9da750*> &v);
struct OpG_Record_9da7f0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9da7f0(istream &stream);
	~OpG_Record_9da7f0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9da7f0>(ostream &stream, vector<OpG_Record_9da7f0*> &v);
struct OpG_Record_9db290	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9db290(istream &stream);
	~OpG_Record_9db290();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9db290>(ostream &stream, vector<OpG_Record_9db290*> &v);
struct OpG_Record_9dbe20	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dbe20(istream &stream);
	~OpG_Record_9dbe20();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dbe20>(ostream &stream, vector<OpG_Record_9dbe20*> &v);
struct OpG_Record_9dbe80	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dbe80(istream &stream);
	~OpG_Record_9dbe80();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dbe80>(ostream &stream, vector<OpG_Record_9dbe80*> &v);
struct OpG_Record_9dc000	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc000(istream &stream);
	~OpG_Record_9dc000();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc000>(ostream &stream, vector<OpG_Record_9dc000*> &v);
struct OpG_Record_9dc060	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc060(istream &stream);
	~OpG_Record_9dc060();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc060>(ostream &stream, vector<OpG_Record_9dc060*> &v);
struct OpG_Record_9dc0c0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc0c0(istream &stream);
	~OpG_Record_9dc0c0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc0c0>(ostream &stream, vector<OpG_Record_9dc0c0*> &v);
struct OpG_Record_9dc120	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc120(istream &stream);
	~OpG_Record_9dc120();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc120>(ostream &stream, vector<OpG_Record_9dc120*> &v);
struct OpG_Record_9dc180	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc180(istream &stream);
	~OpG_Record_9dc180();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc180>(ostream &stream, vector<OpG_Record_9dc180*> &v);
struct OpG_Record_9dc1e0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc1e0(istream &stream);
	~OpG_Record_9dc1e0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc1e0>(ostream &stream, vector<OpG_Record_9dc1e0*> &v);
struct OpG_Record_9dc240	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc240(istream &stream);
	~OpG_Record_9dc240();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc240>(ostream &stream, vector<OpG_Record_9dc240*> &v);
struct OpG_Record_9dc320	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc320(istream &stream);
	~OpG_Record_9dc320();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc320>(ostream &stream, vector<OpG_Record_9dc320*> &v);
struct OpG_Record_9dc380	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc380(istream &stream);
	~OpG_Record_9dc380();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc380>(ostream &stream, vector<OpG_Record_9dc380*> &v);
struct OpG_Record_9dc3e0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc3e0(istream &stream);
	~OpG_Record_9dc3e0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc3e0>(ostream &stream, vector<OpG_Record_9dc3e0*> &v);
struct OpG_Record_9dc440	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc440(istream &stream);
	~OpG_Record_9dc440();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc440>(ostream &stream, vector<OpG_Record_9dc440*> &v);
struct OpG_Record_9dc4a0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc4a0(istream &stream);
	~OpG_Record_9dc4a0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc4a0>(ostream &stream, vector<OpG_Record_9dc4a0*> &v);
struct OpG_Record_9dc560	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc560(istream &stream);
	~OpG_Record_9dc560();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc560>(ostream &stream, vector<OpG_Record_9dc560*> &v);
struct OpG_Record_9dc5c0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc5c0(istream &stream);
	~OpG_Record_9dc5c0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dc5c0>(ostream &stream, vector<OpG_Record_9dc5c0*> &v);
struct OpG_Record_9de9c0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de9c0(istream &stream);
	~OpG_Record_9de9c0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9de9c0>(ostream &stream, vector<OpG_Record_9de9c0*> &v);
struct OpG_Record_9dea20	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dea20(istream &stream);
	~OpG_Record_9dea20();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9dea20>(ostream &stream, vector<OpG_Record_9dea20*> &v);
struct OpG_Record_9deac0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9deac0(istream &stream);
	~OpG_Record_9deac0();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9deac0>(ostream &stream, vector<OpG_Record_9deac0*> &v);
struct OpG_Record_9deb20	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9deb20(istream &stream);
	~OpG_Record_9deb20();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9deb20>(ostream &stream, vector<OpG_Record_9deb20*> &v);
struct OpG_Record_9df390	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9df390(istream &stream);
	~OpG_Record_9df390();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Record_9df390>(ostream &stream, vector<OpG_Record_9df390*> &v);
struct OpG_Record_9d1190	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d1190(istream &stream);
	~OpG_Record_9d1190();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d1190>(ostream &stream, OpG_Record_9d1190 *&p);
struct OpG_Record_9d1230	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d1230(istream &stream);
	~OpG_Record_9d1230();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d1230>(ostream &stream, OpG_Record_9d1230 *&p);
struct OpG_Record_9d1270	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d1270(istream &stream);
	~OpG_Record_9d1270();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d1270>(ostream &stream, OpG_Record_9d1270 *&p);
struct OpG_Record_9d1fd0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d1fd0(istream &stream);
	~OpG_Record_9d1fd0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d1fd0>(ostream &stream, OpG_Record_9d1fd0 *&p);
struct OpG_Record_9d84d0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d84d0(istream &stream);
	~OpG_Record_9d84d0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d84d0>(ostream &stream, OpG_Record_9d84d0 *&p);
struct OpG_Record_9d8d50	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8d50(istream &stream);
	~OpG_Record_9d8d50();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d8d50>(ostream &stream, OpG_Record_9d8d50 *&p);
struct OpG_Record_9d8d90	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8d90(istream &stream);
	~OpG_Record_9d8d90();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d8d90>(ostream &stream, OpG_Record_9d8d90 *&p);
struct OpG_Record_9d8dd0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d8dd0(istream &stream);
	~OpG_Record_9d8dd0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d8dd0>(ostream &stream, OpG_Record_9d8dd0 *&p);
struct OpG_Record_9d9660	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d9660(istream &stream);
	~OpG_Record_9d9660();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d9660>(ostream &stream, OpG_Record_9d9660 *&p);
struct OpG_Record_9d9cb0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d9cb0(istream &stream);
	~OpG_Record_9d9cb0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d9cb0>(ostream &stream, OpG_Record_9d9cb0 *&p);
struct OpG_Record_9d9cf0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d9cf0(istream &stream);
	~OpG_Record_9d9cf0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9d9cf0>(ostream &stream, OpG_Record_9d9cf0 *&p);
struct OpG_Record_9da7b0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9da7b0(istream &stream);
	~OpG_Record_9da7b0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9da7b0>(ostream &stream, OpG_Record_9da7b0 *&p);
struct OpG_Record_9dace0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dace0(istream &stream);
	~OpG_Record_9dace0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9dace0>(ostream &stream, OpG_Record_9dace0 *&p);
struct OpG_Record_9dad20	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dad20(istream &stream);
	~OpG_Record_9dad20();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9dad20>(ostream &stream, OpG_Record_9dad20 *&p);
struct OpG_Record_9dad60	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dad60(istream &stream);
	~OpG_Record_9dad60();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9dad60>(ostream &stream, OpG_Record_9dad60 *&p);
struct OpG_Record_9db2f0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9db2f0(istream &stream);
	~OpG_Record_9db2f0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9db2f0>(ostream &stream, OpG_Record_9db2f0 *&p);
struct OpG_Record_9dc2a0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc2a0(istream &stream);
	~OpG_Record_9dc2a0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9dc2a0>(ostream &stream, OpG_Record_9dc2a0 *&p);
struct OpG_Record_9dc2e0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dc2e0(istream &stream);
	~OpG_Record_9dc2e0();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9dc2e0>(ostream &stream, OpG_Record_9dc2e0 *&p);
struct OpG_Record_9de940	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de940(istream &stream);
	~OpG_Record_9de940();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9de940>(ostream &stream, OpG_Record_9de940 *&p);
struct OpG_Record_9de980	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de980(istream &stream);
	~OpG_Record_9de980();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9de980>(ostream &stream, OpG_Record_9de980 *&p);
struct OpG_Record_9dea80	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dea80(istream &stream);
	~OpG_Record_9dea80();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9dea80>(ostream &stream, OpG_Record_9dea80 *&p);
struct OpG_Record_9df610	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9df610(istream &stream);
	~OpG_Record_9df610();
	void serialize(ostream &stream);
};
template void OpG_writePointer<OpG_Record_9df610>(ostream &stream, OpG_Record_9df610 *&p);
struct OpG_Record_9ce820	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ce820(istream &stream);
	~OpG_Record_9ce820();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9ce820>(vector<OpG_Record_9ce820*> &v);
struct OpG_Record_9cead0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9cead0(istream &stream);
	~OpG_Record_9cead0();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9cead0>(vector<OpG_Record_9cead0*> &v);
struct OpG_Record_9cf340	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9cf340(istream &stream);
	~OpG_Record_9cf340();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9cf340>(vector<OpG_Record_9cf340*> &v);
struct OpG_Record_9d0670	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d0670(istream &stream);
	~OpG_Record_9d0670();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d0670>(vector<OpG_Record_9d0670*> &v);
struct OpG_Record_9d2070	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d2070(istream &stream);
	~OpG_Record_9d2070();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d2070>(vector<OpG_Record_9d2070*> &v);
struct OpG_Record_9d3f00	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d3f00(istream &stream);
	~OpG_Record_9d3f00();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d3f00>(vector<OpG_Record_9d3f00*> &v);
struct OpG_Record_9d3f20	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d3f20(istream &stream);
	~OpG_Record_9d3f20();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d3f20>(vector<OpG_Record_9d3f20*> &v);
struct OpG_Record_9d3f80	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d3f80(istream &stream);
	~OpG_Record_9d3f80();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d3f80>(vector<OpG_Record_9d3f80*> &v);
struct OpG_Record_9d4140	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d4140(istream &stream);
	~OpG_Record_9d4140();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d4140>(vector<OpG_Record_9d4140*> &v);
struct OpG_Record_9d4930	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9d4930(istream &stream);
	~OpG_Record_9d4930();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9d4930>(vector<OpG_Record_9d4930*> &v);
struct OpG_Record_9da360	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9da360(istream &stream);
	~OpG_Record_9da360();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9da360>(vector<OpG_Record_9da360*> &v);
struct OpG_Record_9ddeb0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9ddeb0(istream &stream);
	~OpG_Record_9ddeb0();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9ddeb0>(vector<OpG_Record_9ddeb0*> &v);
struct OpG_Record_9dded0	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9dded0(istream &stream);
	~OpG_Record_9dded0();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9dded0>(vector<OpG_Record_9dded0*> &v);
struct OpG_Record_9de070	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de070(istream &stream);
	~OpG_Record_9de070();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9de070>(vector<OpG_Record_9de070*> &v);
struct OpG_Record_9de090	// NOTE: placeholder name
{
	int data[2];
	OpG_Record_9de090(istream &stream);
	~OpG_Record_9de090();
	void serialize(ostream &stream);
};
template void OpG_clearObjects<OpG_Record_9de090>(vector<OpG_Record_9de090*> &v);
