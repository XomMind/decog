// op_y9: global pools (clearAll/serialize/unserialize) and helpers in 0x9d0000-0xb60000
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

template <class T> void OpY9_writeBinary(ostream &stream, T *value);	// NOTE: placeholder name
template <class T> void OpY9_readBinary(istream &stream, T *value);	// NOTE: placeholder name
template <class T> void OpY9_writeVector(ostream &stream, vector<T> &v);	// NOTE: placeholder name
template <class T> void OpY9_readVector(istream &stream, vector<T> &v);	// NOTE: placeholder name
extern int opY9_unknown_cefa6c;	// NOTE: placeholder name

struct OpY9_Rec7	// NOTE: placeholder name
{
	int data[30];
	OpY9_Rec7(istream &stream);
	~OpY9_Rec7();
	void serialize(ostream &stream);
};

struct OpY9_Pool7	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d0350
	void serialize(ostream &stream);	// 0x9d03e0
	void unserialize(istream &stream);	// 0x9d04b0

	vector<OpY9_Rec7*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool7::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
		{
			delete items[i];
		}
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool7::serialize(ostream &stream)
{
	unsigned int count = items.size();
	bool objectExists;
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool7::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec7(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

struct OpY9_Rec5	// NOTE: placeholder name
{
	int data[82];
	OpY9_Rec5(istream &stream);
	~OpY9_Rec5();
	void serialize(ostream &stream);
};

struct OpY9_Pool5	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d08a0
	void serialize(ostream &stream);	// 0x9d0930
	void unserialize(istream &stream);	// 0x9d0a00

	vector<OpY9_Rec5*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool5::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
			delete items[i];
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool5::serialize(ostream &stream)
{
	bool objectExists;
	unsigned int count = items.size();
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool5::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec5(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

struct OpY9_Rec6	// NOTE: placeholder name
{
	int data[20];
	OpY9_Rec6(istream &stream);
	~OpY9_Rec6();
	void serialize(ostream &stream);
};

struct OpY9_Pool6	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d0d30
	void serialize(ostream &stream);	// 0x9d0dc0
	void unserialize(istream &stream);	// 0x9d0e90

	vector<OpY9_Rec6*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool6::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
			delete items[i];
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool6::serialize(ostream &stream)
{
	bool objectExists;
	unsigned int count = items.size();
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool6::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec6(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

struct OpY9_Rec8	// NOTE: placeholder name
{
	int data[15];
	OpY9_Rec8(istream &stream);
	~OpY9_Rec8();
	void serialize(ostream &stream);
};

struct OpY9_Pool8	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d1600
	void serialize(ostream &stream);	// 0x9d1690
	void unserialize(istream &stream);	// 0x9d1760

	vector<OpY9_Rec8*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool8::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
			delete items[i];
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool8::serialize(ostream &stream)
{
	bool objectExists;
	unsigned int count = items.size();
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool8::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec8(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

struct OpY9_Rec4	// NOTE: placeholder name
{
	int data[4];
	OpY9_Rec4(istream &stream);
	~OpY9_Rec4();
	void serialize(ostream &stream);
};

struct OpY9_Pool4	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d1890
	void serialize(ostream &stream);	// 0x9d1920
	void unserialize(istream &stream);	// 0x9d19f0

	vector<OpY9_Rec4*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool4::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
			delete items[i];
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool4::serialize(ostream &stream)
{
	bool objectExists;
	unsigned int count = items.size();
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool4::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec4(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

struct OpY9_Rec9	// NOTE: placeholder name
{
	int data[25];
	OpY9_Rec9(istream &stream);
	~OpY9_Rec9();
	void serialize(ostream &stream);
};

struct OpY9_Pool9	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d35d0
	void serialize(ostream &stream);	// 0x9d3660
	void unserialize(istream &stream);	// 0x9d3730

	vector<OpY9_Rec9*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool9::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
			delete items[i];
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool9::serialize(ostream &stream)
{
	bool objectExists;
	unsigned int count = items.size();
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool9::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec9(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

struct OpY9_Rec10	// NOTE: placeholder name
{
	int data[6];
	OpY9_Rec10(istream &stream);
	~OpY9_Rec10();
	void serialize(ostream &stream);
};

struct OpY9_Pool10	// NOTE: placeholder name
{
	void clearAll(bool deleteItems);	// 0x9d3860
	void serialize(ostream &stream);	// 0x9d38f0
	void unserialize(istream &stream);	// 0x9d39c0

	vector<OpY9_Rec10*> items;
	vector<int> list1;
	vector<int> list2;
};

void OpY9_Pool10::clearAll(bool deleteItems)
{
	if (deleteItems)
	{
		for (unsigned int i = 0; i < items.size(); i++)
			delete items[i];
	}
	items.clear();
	list1.clear();
	list2.clear();
}

void OpY9_Pool10::serialize(ostream &stream)
{
	bool objectExists;
	unsigned int count = items.size();
	OpY9_writeBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		objectExists = (bool)items[i];
		OpY9_writeBinary(stream,&objectExists);
		if (objectExists)
			items[i]->serialize(stream);
	}
	OpY9_writeVector(stream,list1);
	OpY9_writeVector(stream,list2);
	OpY9_writeBinary(stream,&opY9_unknown_cefa6c);
}

void OpY9_Pool10::unserialize(istream &stream)
{
	bool objectExists;
	unsigned int count;
	OpY9_readBinary(stream,&count);
	for (unsigned int i = 0; i < count; i++)
	{
		OpY9_readBinary(stream,&objectExists);
		if (objectExists)
			items.push_back(new OpY9_Rec10(stream));
		else
			items.push_back(NULL);
	}
	OpY9_readVector(stream,list1);
	OpY9_readVector(stream,list2);
	OpY9_readBinary(stream,&opY9_unknown_cefa6c);
}

