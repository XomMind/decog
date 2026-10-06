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

template void readBinary<char>(istream &stream, char *value);
template void writeBinary<char>(ostream &stream, char *value);
template void OpG_writeVector<char>(ostream &stream, vector<char> &v);
template void OpG_readVector<char>(istream &stream, vector<char> &v);
template void readBinary<bool>(istream &stream, bool *value);
template void writeBinary<bool>(ostream &stream, bool *value);
template void OpG_writeVector<bool>(ostream &stream, vector<bool> &v);
template void OpG_readVector<bool>(istream &stream, vector<bool> &v);
template void readBinary<int>(istream &stream, int *value);
template void writeBinary<int>(ostream &stream, int *value);
template void OpG_writeVector<int>(ostream &stream, vector<int> &v);
template void OpG_readVector<int>(istream &stream, vector<int> &v);
template void readBinary<short>(istream &stream, short *value);
template void writeBinary<short>(ostream &stream, short *value);
template void OpG_writeVector<short>(ostream &stream, vector<short> &v);
template void OpG_readVector<short>(istream &stream, vector<short> &v);
template void readBinary<float>(istream &stream, float *value);
template void writeBinary<float>(ostream &stream, float *value);
template void OpG_writeVector<float>(ostream &stream, vector<float> &v);
template void OpG_readVector<float>(istream &stream, vector<float> &v);
template void readBinary<double>(istream &stream, double *value);
template void writeBinary<double>(ostream &stream, double *value);
template void OpG_writeVector<double>(ostream &stream, vector<double> &v);
template void OpG_readVector<double>(istream &stream, vector<double> &v);
template void readBinary<__int64>(istream &stream, __int64 *value);
template void writeBinary<__int64>(ostream &stream, __int64 *value);
template void OpG_writeVector<__int64>(ostream &stream, vector<__int64> &v);
template void OpG_readVector<__int64>(istream &stream, vector<__int64> &v);
struct OpG_Q_4_n	// NOTE: placeholder name
{
	int data[1];
	OpG_Q_4_n(istream &stream);
	~OpG_Q_4_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_4_n>(istream &stream, vector<OpG_Q_4_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_4_n>(istream &stream, OpG_Q_4_n *&p);
struct OpG_Q_8_n	// NOTE: placeholder name
{
	int data[2];
	OpG_Q_8_n(istream &stream);
	~OpG_Q_8_n();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Q_8_n>(ostream &stream, vector<OpG_Q_8_n*> &v);
template void OpG_readObjects<OpG_Q_8_n>(istream &stream, vector<OpG_Q_8_n*> &v, int skip);
template void OpG_writePointer<OpG_Q_8_n>(ostream &stream, OpG_Q_8_n *&p);
template void OpG_readPointer<OpG_Q_8_n>(istream &stream, OpG_Q_8_n *&p);
template void OpG_readReference<OpG_Q_8_n>(istream &stream, OpG_Q_8_n *&p, vector<OpG_Q_8_n*> &list);
template void OpG_deleteObjects<OpG_Q_8_n>(vector<OpG_Q_8_n*> &v);
template void OpG_clearObjects<OpG_Q_8_n>(vector<OpG_Q_8_n*> &v);
template void OpG_deleteObject<OpG_Q_8_n>(vector<OpG_Q_8_n*> &v, int index);
struct OpG_Q_c_n	// NOTE: placeholder name
{
	int data[3];
	OpG_Q_c_n(istream &stream);
	~OpG_Q_c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_c_n>(istream &stream, vector<OpG_Q_c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_c_n>(istream &stream, OpG_Q_c_n *&p);
struct OpG_Q_10_n	// NOTE: placeholder name
{
	int data[4];
	OpG_Q_10_n(istream &stream);
	~OpG_Q_10_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_10_n>(istream &stream, vector<OpG_Q_10_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_10_n>(istream &stream, OpG_Q_10_n *&p);
struct OpG_Q_14_n	// NOTE: placeholder name
{
	int data[5];
	OpG_Q_14_n(istream &stream);
	~OpG_Q_14_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_14_n>(istream &stream, vector<OpG_Q_14_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_14_n>(istream &stream, OpG_Q_14_n *&p);
struct OpG_Q_18_n	// NOTE: placeholder name
{
	int data[6];
	OpG_Q_18_n(istream &stream);
	~OpG_Q_18_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_18_n>(istream &stream, vector<OpG_Q_18_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_18_n>(istream &stream, OpG_Q_18_n *&p);
struct OpG_Q_1c_n	// NOTE: placeholder name
{
	int data[7];
	OpG_Q_1c_n(istream &stream);
	~OpG_Q_1c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_1c_n>(istream &stream, vector<OpG_Q_1c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_1c_n>(istream &stream, OpG_Q_1c_n *&p);
struct OpG_Q_20_n	// NOTE: placeholder name
{
	int data[8];
	OpG_Q_20_n(istream &stream);
	~OpG_Q_20_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_20_n>(istream &stream, vector<OpG_Q_20_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_20_n>(istream &stream, OpG_Q_20_n *&p);
struct OpG_Q_24_n	// NOTE: placeholder name
{
	int data[9];
	OpG_Q_24_n(istream &stream);
	~OpG_Q_24_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_24_n>(istream &stream, vector<OpG_Q_24_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_24_n>(istream &stream, OpG_Q_24_n *&p);
struct OpG_Q_28_n	// NOTE: placeholder name
{
	int data[10];
	OpG_Q_28_n(istream &stream);
	~OpG_Q_28_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_28_n>(istream &stream, vector<OpG_Q_28_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_28_n>(istream &stream, OpG_Q_28_n *&p);
struct OpG_Q_2c_n	// NOTE: placeholder name
{
	int data[11];
	OpG_Q_2c_n(istream &stream);
	~OpG_Q_2c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_2c_n>(istream &stream, vector<OpG_Q_2c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_2c_n>(istream &stream, OpG_Q_2c_n *&p);
struct OpG_Q_30_n	// NOTE: placeholder name
{
	int data[12];
	OpG_Q_30_n(istream &stream);
	~OpG_Q_30_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_30_n>(istream &stream, vector<OpG_Q_30_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_30_n>(istream &stream, OpG_Q_30_n *&p);
struct OpG_Q_34_n	// NOTE: placeholder name
{
	int data[13];
	OpG_Q_34_n(istream &stream);
	~OpG_Q_34_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_34_n>(istream &stream, vector<OpG_Q_34_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_34_n>(istream &stream, OpG_Q_34_n *&p);
struct OpG_Q_38_n	// NOTE: placeholder name
{
	int data[14];
	OpG_Q_38_n(istream &stream);
	~OpG_Q_38_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_38_n>(istream &stream, vector<OpG_Q_38_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_38_n>(istream &stream, OpG_Q_38_n *&p);
struct OpG_Q_3c_n	// NOTE: placeholder name
{
	int data[15];
	OpG_Q_3c_n(istream &stream);
	~OpG_Q_3c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_3c_n>(istream &stream, vector<OpG_Q_3c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_3c_n>(istream &stream, OpG_Q_3c_n *&p);
struct OpG_Q_44_n	// NOTE: placeholder name
{
	int data[17];
	OpG_Q_44_n(istream &stream);
	~OpG_Q_44_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_44_n>(istream &stream, vector<OpG_Q_44_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_44_n>(istream &stream, OpG_Q_44_n *&p);
struct OpG_Q_48_n	// NOTE: placeholder name
{
	int data[18];
	OpG_Q_48_n(istream &stream);
	~OpG_Q_48_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_48_n>(istream &stream, vector<OpG_Q_48_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_48_n>(istream &stream, OpG_Q_48_n *&p);
struct OpG_Q_4c_n	// NOTE: placeholder name
{
	int data[19];
	OpG_Q_4c_n(istream &stream);
	~OpG_Q_4c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_4c_n>(istream &stream, vector<OpG_Q_4c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_4c_n>(istream &stream, OpG_Q_4c_n *&p);
struct OpG_Q_50_n	// NOTE: placeholder name
{
	int data[20];
	OpG_Q_50_n(istream &stream);
	~OpG_Q_50_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_50_n>(istream &stream, vector<OpG_Q_50_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_50_n>(istream &stream, OpG_Q_50_n *&p);
struct OpG_Q_60_n	// NOTE: placeholder name
{
	int data[24];
	OpG_Q_60_n(istream &stream);
	~OpG_Q_60_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_60_n>(istream &stream, vector<OpG_Q_60_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_60_n>(istream &stream, OpG_Q_60_n *&p);
struct OpG_Q_64_n	// NOTE: placeholder name
{
	int data[25];
	OpG_Q_64_n(istream &stream);
	~OpG_Q_64_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_64_n>(istream &stream, vector<OpG_Q_64_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_64_n>(istream &stream, OpG_Q_64_n *&p);
struct OpG_Q_70_n	// NOTE: placeholder name
{
	int data[28];
	OpG_Q_70_n(istream &stream);
	~OpG_Q_70_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_70_n>(istream &stream, vector<OpG_Q_70_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_70_n>(istream &stream, OpG_Q_70_n *&p);
struct OpG_Q_78_n	// NOTE: placeholder name
{
	int data[30];
	OpG_Q_78_n(istream &stream);
	~OpG_Q_78_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_78_n>(istream &stream, vector<OpG_Q_78_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_78_n>(istream &stream, OpG_Q_78_n *&p);
struct OpG_Q_7c_n	// NOTE: placeholder name
{
	int data[31];
	OpG_Q_7c_n(istream &stream);
	~OpG_Q_7c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_7c_n>(istream &stream, vector<OpG_Q_7c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_7c_n>(istream &stream, OpG_Q_7c_n *&p);
struct OpG_Q_90_n	// NOTE: placeholder name
{
	int data[36];
	OpG_Q_90_n(istream &stream);
	~OpG_Q_90_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_90_n>(istream &stream, vector<OpG_Q_90_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_90_n>(istream &stream, OpG_Q_90_n *&p);
struct OpG_Q_9c_n	// NOTE: placeholder name
{
	int data[39];
	OpG_Q_9c_n(istream &stream);
	~OpG_Q_9c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_9c_n>(istream &stream, vector<OpG_Q_9c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_9c_n>(istream &stream, OpG_Q_9c_n *&p);
struct OpG_Q_a0_n	// NOTE: placeholder name
{
	int data[40];
	OpG_Q_a0_n(istream &stream);
	~OpG_Q_a0_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_a0_n>(istream &stream, vector<OpG_Q_a0_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_a0_n>(istream &stream, OpG_Q_a0_n *&p);
struct OpG_Q_a4_n	// NOTE: placeholder name
{
	int data[41];
	OpG_Q_a4_n(istream &stream);
	~OpG_Q_a4_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_a4_n>(istream &stream, vector<OpG_Q_a4_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_a4_n>(istream &stream, OpG_Q_a4_n *&p);
struct OpG_Q_ac_n	// NOTE: placeholder name
{
	int data[43];
	OpG_Q_ac_n(istream &stream);
	~OpG_Q_ac_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_ac_n>(istream &stream, vector<OpG_Q_ac_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_ac_n>(istream &stream, OpG_Q_ac_n *&p);
struct OpG_Q_c0_n	// NOTE: placeholder name
{
	int data[48];
	OpG_Q_c0_n(istream &stream);
	~OpG_Q_c0_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_c0_n>(istream &stream, vector<OpG_Q_c0_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_c0_n>(istream &stream, OpG_Q_c0_n *&p);
struct OpG_Q_d0_n	// NOTE: placeholder name
{
	int data[52];
	OpG_Q_d0_n(istream &stream);
	~OpG_Q_d0_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_d0_n>(istream &stream, vector<OpG_Q_d0_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_d0_n>(istream &stream, OpG_Q_d0_n *&p);
struct OpG_Q_d8_n	// NOTE: placeholder name
{
	int data[54];
	OpG_Q_d8_n(istream &stream);
	~OpG_Q_d8_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_d8_n>(istream &stream, vector<OpG_Q_d8_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_d8_n>(istream &stream, OpG_Q_d8_n *&p);
struct OpG_Q_e0_n	// NOTE: placeholder name
{
	int data[56];
	OpG_Q_e0_n(istream &stream);
	~OpG_Q_e0_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_e0_n>(istream &stream, vector<OpG_Q_e0_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_e0_n>(istream &stream, OpG_Q_e0_n *&p);
struct OpG_Q_100_n	// NOTE: placeholder name
{
	int data[64];
	OpG_Q_100_n(istream &stream);
	~OpG_Q_100_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_100_n>(istream &stream, vector<OpG_Q_100_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_100_n>(istream &stream, OpG_Q_100_n *&p);
struct OpG_Q_130_n	// NOTE: placeholder name
{
	int data[76];
	OpG_Q_130_n(istream &stream);
	~OpG_Q_130_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_130_n>(istream &stream, vector<OpG_Q_130_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_130_n>(istream &stream, OpG_Q_130_n *&p);
struct OpG_Q_148_n	// NOTE: placeholder name
{
	int data[82];
	OpG_Q_148_n(istream &stream);
	~OpG_Q_148_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_148_n>(istream &stream, vector<OpG_Q_148_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_148_n>(istream &stream, OpG_Q_148_n *&p);
struct OpG_Q_170_n	// NOTE: placeholder name
{
	int data[92];
	OpG_Q_170_n(istream &stream);
	~OpG_Q_170_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_170_n>(istream &stream, vector<OpG_Q_170_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_170_n>(istream &stream, OpG_Q_170_n *&p);
struct OpG_Q_1d8_n	// NOTE: placeholder name
{
	int data[118];
	OpG_Q_1d8_n(istream &stream);
	~OpG_Q_1d8_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_1d8_n>(istream &stream, vector<OpG_Q_1d8_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_1d8_n>(istream &stream, OpG_Q_1d8_n *&p);
struct OpG_Q_22c_n	// NOTE: placeholder name
{
	int data[139];
	OpG_Q_22c_n(istream &stream);
	~OpG_Q_22c_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_22c_n>(istream &stream, vector<OpG_Q_22c_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_22c_n>(istream &stream, OpG_Q_22c_n *&p);
struct OpG_Q_280_n	// NOTE: placeholder name
{
	int data[160];
	OpG_Q_280_n(istream &stream);
	~OpG_Q_280_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_280_n>(istream &stream, vector<OpG_Q_280_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_280_n>(istream &stream, OpG_Q_280_n *&p);
struct OpG_Q_2a4_n	// NOTE: placeholder name
{
	int data[169];
	OpG_Q_2a4_n(istream &stream);
	~OpG_Q_2a4_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_2a4_n>(istream &stream, vector<OpG_Q_2a4_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_2a4_n>(istream &stream, OpG_Q_2a4_n *&p);
struct OpG_Q_c68_n	// NOTE: placeholder name
{
	int data[794];
	OpG_Q_c68_n(istream &stream);
	~OpG_Q_c68_n();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_c68_n>(istream &stream, vector<OpG_Q_c68_n*> &v, int skip);
template void OpG_readPointer<OpG_Q_c68_n>(istream &stream, OpG_Q_c68_n *&p);
struct OpG_Q_4_v	// NOTE: placeholder name
{
	OpG_Q_4_v(istream &stream);
	virtual ~OpG_Q_4_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_4_v>(istream &stream, vector<OpG_Q_4_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_4_v>(istream &stream, OpG_Q_4_v *&p);
struct OpG_Q_8_v	// NOTE: placeholder name
{
	int data[1];
	OpG_Q_8_v(istream &stream);
	virtual ~OpG_Q_8_v();
	void serialize(ostream &stream);
};
template void OpG_writeObjects<OpG_Q_8_v>(ostream &stream, vector<OpG_Q_8_v*> &v);
template void OpG_readObjects<OpG_Q_8_v>(istream &stream, vector<OpG_Q_8_v*> &v, int skip);
template void OpG_writePointer<OpG_Q_8_v>(ostream &stream, OpG_Q_8_v *&p);
template void OpG_readPointer<OpG_Q_8_v>(istream &stream, OpG_Q_8_v *&p);
template void OpG_readReference<OpG_Q_8_v>(istream &stream, OpG_Q_8_v *&p, vector<OpG_Q_8_v*> &list);
template void OpG_deleteObjects<OpG_Q_8_v>(vector<OpG_Q_8_v*> &v);
template void OpG_clearObjects<OpG_Q_8_v>(vector<OpG_Q_8_v*> &v);
template void OpG_deleteObject<OpG_Q_8_v>(vector<OpG_Q_8_v*> &v, int index);
struct OpG_Q_c_v	// NOTE: placeholder name
{
	int data[2];
	OpG_Q_c_v(istream &stream);
	virtual ~OpG_Q_c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_c_v>(istream &stream, vector<OpG_Q_c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_c_v>(istream &stream, OpG_Q_c_v *&p);
struct OpG_Q_10_v	// NOTE: placeholder name
{
	int data[3];
	OpG_Q_10_v(istream &stream);
	virtual ~OpG_Q_10_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_10_v>(istream &stream, vector<OpG_Q_10_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_10_v>(istream &stream, OpG_Q_10_v *&p);
struct OpG_Q_14_v	// NOTE: placeholder name
{
	int data[4];
	OpG_Q_14_v(istream &stream);
	virtual ~OpG_Q_14_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_14_v>(istream &stream, vector<OpG_Q_14_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_14_v>(istream &stream, OpG_Q_14_v *&p);
struct OpG_Q_18_v	// NOTE: placeholder name
{
	int data[5];
	OpG_Q_18_v(istream &stream);
	virtual ~OpG_Q_18_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_18_v>(istream &stream, vector<OpG_Q_18_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_18_v>(istream &stream, OpG_Q_18_v *&p);
struct OpG_Q_1c_v	// NOTE: placeholder name
{
	int data[6];
	OpG_Q_1c_v(istream &stream);
	virtual ~OpG_Q_1c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_1c_v>(istream &stream, vector<OpG_Q_1c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_1c_v>(istream &stream, OpG_Q_1c_v *&p);
struct OpG_Q_20_v	// NOTE: placeholder name
{
	int data[7];
	OpG_Q_20_v(istream &stream);
	virtual ~OpG_Q_20_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_20_v>(istream &stream, vector<OpG_Q_20_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_20_v>(istream &stream, OpG_Q_20_v *&p);
struct OpG_Q_24_v	// NOTE: placeholder name
{
	int data[8];
	OpG_Q_24_v(istream &stream);
	virtual ~OpG_Q_24_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_24_v>(istream &stream, vector<OpG_Q_24_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_24_v>(istream &stream, OpG_Q_24_v *&p);
struct OpG_Q_28_v	// NOTE: placeholder name
{
	int data[9];
	OpG_Q_28_v(istream &stream);
	virtual ~OpG_Q_28_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_28_v>(istream &stream, vector<OpG_Q_28_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_28_v>(istream &stream, OpG_Q_28_v *&p);
struct OpG_Q_2c_v	// NOTE: placeholder name
{
	int data[10];
	OpG_Q_2c_v(istream &stream);
	virtual ~OpG_Q_2c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_2c_v>(istream &stream, vector<OpG_Q_2c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_2c_v>(istream &stream, OpG_Q_2c_v *&p);
struct OpG_Q_30_v	// NOTE: placeholder name
{
	int data[11];
	OpG_Q_30_v(istream &stream);
	virtual ~OpG_Q_30_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_30_v>(istream &stream, vector<OpG_Q_30_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_30_v>(istream &stream, OpG_Q_30_v *&p);
struct OpG_Q_34_v	// NOTE: placeholder name
{
	int data[12];
	OpG_Q_34_v(istream &stream);
	virtual ~OpG_Q_34_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_34_v>(istream &stream, vector<OpG_Q_34_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_34_v>(istream &stream, OpG_Q_34_v *&p);
struct OpG_Q_38_v	// NOTE: placeholder name
{
	int data[13];
	OpG_Q_38_v(istream &stream);
	virtual ~OpG_Q_38_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_38_v>(istream &stream, vector<OpG_Q_38_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_38_v>(istream &stream, OpG_Q_38_v *&p);
struct OpG_Q_3c_v	// NOTE: placeholder name
{
	int data[14];
	OpG_Q_3c_v(istream &stream);
	virtual ~OpG_Q_3c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_3c_v>(istream &stream, vector<OpG_Q_3c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_3c_v>(istream &stream, OpG_Q_3c_v *&p);
struct OpG_Q_44_v	// NOTE: placeholder name
{
	int data[16];
	OpG_Q_44_v(istream &stream);
	virtual ~OpG_Q_44_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_44_v>(istream &stream, vector<OpG_Q_44_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_44_v>(istream &stream, OpG_Q_44_v *&p);
struct OpG_Q_48_v	// NOTE: placeholder name
{
	int data[17];
	OpG_Q_48_v(istream &stream);
	virtual ~OpG_Q_48_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_48_v>(istream &stream, vector<OpG_Q_48_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_48_v>(istream &stream, OpG_Q_48_v *&p);
struct OpG_Q_4c_v	// NOTE: placeholder name
{
	int data[18];
	OpG_Q_4c_v(istream &stream);
	virtual ~OpG_Q_4c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_4c_v>(istream &stream, vector<OpG_Q_4c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_4c_v>(istream &stream, OpG_Q_4c_v *&p);
struct OpG_Q_50_v	// NOTE: placeholder name
{
	int data[19];
	OpG_Q_50_v(istream &stream);
	virtual ~OpG_Q_50_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_50_v>(istream &stream, vector<OpG_Q_50_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_50_v>(istream &stream, OpG_Q_50_v *&p);
struct OpG_Q_60_v	// NOTE: placeholder name
{
	int data[23];
	OpG_Q_60_v(istream &stream);
	virtual ~OpG_Q_60_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_60_v>(istream &stream, vector<OpG_Q_60_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_60_v>(istream &stream, OpG_Q_60_v *&p);
struct OpG_Q_64_v	// NOTE: placeholder name
{
	int data[24];
	OpG_Q_64_v(istream &stream);
	virtual ~OpG_Q_64_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_64_v>(istream &stream, vector<OpG_Q_64_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_64_v>(istream &stream, OpG_Q_64_v *&p);
struct OpG_Q_70_v	// NOTE: placeholder name
{
	int data[27];
	OpG_Q_70_v(istream &stream);
	virtual ~OpG_Q_70_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_70_v>(istream &stream, vector<OpG_Q_70_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_70_v>(istream &stream, OpG_Q_70_v *&p);
struct OpG_Q_78_v	// NOTE: placeholder name
{
	int data[29];
	OpG_Q_78_v(istream &stream);
	virtual ~OpG_Q_78_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_78_v>(istream &stream, vector<OpG_Q_78_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_78_v>(istream &stream, OpG_Q_78_v *&p);
struct OpG_Q_7c_v	// NOTE: placeholder name
{
	int data[30];
	OpG_Q_7c_v(istream &stream);
	virtual ~OpG_Q_7c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_7c_v>(istream &stream, vector<OpG_Q_7c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_7c_v>(istream &stream, OpG_Q_7c_v *&p);
struct OpG_Q_90_v	// NOTE: placeholder name
{
	int data[35];
	OpG_Q_90_v(istream &stream);
	virtual ~OpG_Q_90_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_90_v>(istream &stream, vector<OpG_Q_90_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_90_v>(istream &stream, OpG_Q_90_v *&p);
struct OpG_Q_9c_v	// NOTE: placeholder name
{
	int data[38];
	OpG_Q_9c_v(istream &stream);
	virtual ~OpG_Q_9c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_9c_v>(istream &stream, vector<OpG_Q_9c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_9c_v>(istream &stream, OpG_Q_9c_v *&p);
struct OpG_Q_a0_v	// NOTE: placeholder name
{
	int data[39];
	OpG_Q_a0_v(istream &stream);
	virtual ~OpG_Q_a0_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_a0_v>(istream &stream, vector<OpG_Q_a0_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_a0_v>(istream &stream, OpG_Q_a0_v *&p);
struct OpG_Q_a4_v	// NOTE: placeholder name
{
	int data[40];
	OpG_Q_a4_v(istream &stream);
	virtual ~OpG_Q_a4_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_a4_v>(istream &stream, vector<OpG_Q_a4_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_a4_v>(istream &stream, OpG_Q_a4_v *&p);
struct OpG_Q_ac_v	// NOTE: placeholder name
{
	int data[42];
	OpG_Q_ac_v(istream &stream);
	virtual ~OpG_Q_ac_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_ac_v>(istream &stream, vector<OpG_Q_ac_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_ac_v>(istream &stream, OpG_Q_ac_v *&p);
struct OpG_Q_c0_v	// NOTE: placeholder name
{
	int data[47];
	OpG_Q_c0_v(istream &stream);
	virtual ~OpG_Q_c0_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_c0_v>(istream &stream, vector<OpG_Q_c0_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_c0_v>(istream &stream, OpG_Q_c0_v *&p);
struct OpG_Q_d0_v	// NOTE: placeholder name
{
	int data[51];
	OpG_Q_d0_v(istream &stream);
	virtual ~OpG_Q_d0_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_d0_v>(istream &stream, vector<OpG_Q_d0_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_d0_v>(istream &stream, OpG_Q_d0_v *&p);
struct OpG_Q_d8_v	// NOTE: placeholder name
{
	int data[53];
	OpG_Q_d8_v(istream &stream);
	virtual ~OpG_Q_d8_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_d8_v>(istream &stream, vector<OpG_Q_d8_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_d8_v>(istream &stream, OpG_Q_d8_v *&p);
struct OpG_Q_e0_v	// NOTE: placeholder name
{
	int data[55];
	OpG_Q_e0_v(istream &stream);
	virtual ~OpG_Q_e0_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_e0_v>(istream &stream, vector<OpG_Q_e0_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_e0_v>(istream &stream, OpG_Q_e0_v *&p);
struct OpG_Q_100_v	// NOTE: placeholder name
{
	int data[63];
	OpG_Q_100_v(istream &stream);
	virtual ~OpG_Q_100_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_100_v>(istream &stream, vector<OpG_Q_100_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_100_v>(istream &stream, OpG_Q_100_v *&p);
struct OpG_Q_130_v	// NOTE: placeholder name
{
	int data[75];
	OpG_Q_130_v(istream &stream);
	virtual ~OpG_Q_130_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_130_v>(istream &stream, vector<OpG_Q_130_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_130_v>(istream &stream, OpG_Q_130_v *&p);
struct OpG_Q_148_v	// NOTE: placeholder name
{
	int data[81];
	OpG_Q_148_v(istream &stream);
	virtual ~OpG_Q_148_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_148_v>(istream &stream, vector<OpG_Q_148_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_148_v>(istream &stream, OpG_Q_148_v *&p);
struct OpG_Q_170_v	// NOTE: placeholder name
{
	int data[91];
	OpG_Q_170_v(istream &stream);
	virtual ~OpG_Q_170_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_170_v>(istream &stream, vector<OpG_Q_170_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_170_v>(istream &stream, OpG_Q_170_v *&p);
struct OpG_Q_1d8_v	// NOTE: placeholder name
{
	int data[117];
	OpG_Q_1d8_v(istream &stream);
	virtual ~OpG_Q_1d8_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_1d8_v>(istream &stream, vector<OpG_Q_1d8_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_1d8_v>(istream &stream, OpG_Q_1d8_v *&p);
struct OpG_Q_22c_v	// NOTE: placeholder name
{
	int data[138];
	OpG_Q_22c_v(istream &stream);
	virtual ~OpG_Q_22c_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_22c_v>(istream &stream, vector<OpG_Q_22c_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_22c_v>(istream &stream, OpG_Q_22c_v *&p);
struct OpG_Q_280_v	// NOTE: placeholder name
{
	int data[159];
	OpG_Q_280_v(istream &stream);
	virtual ~OpG_Q_280_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_280_v>(istream &stream, vector<OpG_Q_280_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_280_v>(istream &stream, OpG_Q_280_v *&p);
struct OpG_Q_2a4_v	// NOTE: placeholder name
{
	int data[168];
	OpG_Q_2a4_v(istream &stream);
	virtual ~OpG_Q_2a4_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_2a4_v>(istream &stream, vector<OpG_Q_2a4_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_2a4_v>(istream &stream, OpG_Q_2a4_v *&p);
struct OpG_Q_c68_v	// NOTE: placeholder name
{
	int data[793];
	OpG_Q_c68_v(istream &stream);
	virtual ~OpG_Q_c68_v();
	void serialize(ostream &stream);
};
template void OpG_readObjects<OpG_Q_c68_v>(istream &stream, vector<OpG_Q_c68_v*> &v, int skip);
template void OpG_readPointer<OpG_Q_c68_v>(istream &stream, OpG_Q_c68_v *&p);
