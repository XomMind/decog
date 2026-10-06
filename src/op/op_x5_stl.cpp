// op_x5: std (VS2010) template instances over placeholder element types, 0x80f000-0xa044d0
#include <string>
#include <vector>
using namespace std;

template class std::basic_string<char>;
template class std::basic_string<wchar_t>;

struct OpX5_C3 { char b[3]; };	// NOTE: placeholder name
struct OpX5_B9b87a0 { int m; };	// NOTE: placeholder name
struct OpX5_B9b9200 { int m; };	// NOTE: placeholder name
struct OpX5_P9b9bd0 { char b[16]; };	// NOTE: placeholder name
struct OpX5_P9ba830 { char b[16]; };	// NOTE: placeholder name

template OpX5_C3 &vector<OpX5_C3>::at(size_t pos);
template OpX5_B9b87a0 &vector<OpX5_B9b87a0>::back();
template OpX5_B9b9200 &vector<OpX5_B9b9200>::back();
template void vector<OpX5_P9b9bd0>::push_back(OpX5_P9b9bd0 &&val);
template void vector<OpX5_P9ba830>::push_back(OpX5_P9ba830 &&val);

class Console;

struct Point
{
	int x;
	int y;
};

class HEntity
{
public:
	int ID;
};

struct OpX5_E8	// NOTE: placeholder name
{
	int a;
	int b;
};

struct OpX5_Q9c07a0	// NOTE: placeholder name
{
	vector<Console*> a;
	vector<Console*> b;
	int n;
	void reset();
};

struct OpX5_Q9c1b20	// NOTE: placeholder name
{
	vector<string> a;
	vector<Console*> b;
	int n;
	void reset();
};

struct OpX5_Q9c1bb0	// NOTE: placeholder name
{
	vector<Point> a;
	vector<Console*> b;
	int n;
	OpX5_Q9c1bb0();
	void reset();
};

struct OpX5_Q9c1be0	// NOTE: placeholder name
{
	vector<HEntity> a;
	vector<Console*> b;
	int n;
	OpX5_Q9c1be0();
	void reset();
};

struct OpX5_Q9c1c10	// NOTE: placeholder name
{
	vector<OpX5_E8> a;
	vector<Console*> b;
	int n;
	OpX5_Q9c1c10();
	void reset();
};

void OpX5_Q9c07a0::reset()
{
	a.clear();
	b.clear();
	n = 0;
}

void OpX5_Q9c1b20::reset()
{
	a.clear();
	b.clear();
	n = 0;
}

OpX5_Q9c1bb0::OpX5_Q9c1bb0()
{
	reset();
}

void OpX5_Q9c1bb0::reset()
{
	a.clear();
	b.clear();
	n = 0;
}

OpX5_Q9c1be0::OpX5_Q9c1be0()
{
	reset();
}

void OpX5_Q9c1be0::reset()
{
	a.clear();
	b.clear();
	n = 0;
}

OpX5_Q9c1c10::OpX5_Q9c1c10()
{
	reset();
}

void OpX5_Q9c1c10::reset()
{
	a.clear();
	b.clear();
	n = 0;
}

struct OpX5_W4	// NOTE: placeholder name
{
	int v;
};

struct OpX5_H4;	// NOTE: placeholder name (pointer element only)

template vector<OpX5_W4>::iterator vector<OpX5_W4>::insert<OpX5_W4 &>(vector<OpX5_W4>::const_iterator where, OpX5_W4 &val);
template vector<OpX5_H4*>::iterator vector<OpX5_H4*>::insert<OpX5_H4 *&>(vector<OpX5_H4*>::const_iterator where, OpX5_H4 *&val);
template void vector<unsigned int>::assign<int>(int count, int val);

template void basic_string<char>::insert<vector<char>::iterator>(basic_string<char>::const_iterator where, vector<char>::iterator first, vector<char>::iterator last);

#include <iterator>
template class std::istreambuf_iterator<char>;

#include <algorithm>

struct OpX5_P4	// NOTE: placeholder name
{
	int v;
};

template vector<string>::iterator std::lower_bound<vector<string>::iterator, string>(vector<string>::iterator first, vector<string>::iterator last, const string &val);
template vector<OpX5_P4>::iterator std::lower_bound<vector<OpX5_P4>::iterator, OpX5_P4, bool (*)(const OpX5_P4 &, const OpX5_P4 &)>(vector<OpX5_P4>::iterator first, vector<OpX5_P4>::iterator last, const OpX5_P4 &val, bool (*pred)(const OpX5_P4 &, const OpX5_P4 &));

struct OpX5_R4	// NOTE: placeholder name
{
	int v;
};

struct OpX5_E28	// NOTE: placeholder name
{
	int v[10];
};

bool operator<(const OpX5_E28 &a, const OpX5_E28 &b);	// NOTE: placeholder name

template void std::reverse<vector<OpX5_R4>::iterator>(vector<OpX5_R4>::iterator first, vector<OpX5_R4>::iterator last);
template void std::sort<vector<OpX5_E28>::iterator>(vector<OpX5_E28>::iterator first, vector<OpX5_E28>::iterator last);

struct OpX5_TA	// NOTE: placeholder name
{
	int v;
};

struct OpX5_TC	// NOTE: placeholder name
{
	int v[2];
};

struct OpX5_Obj;	// NOTE: placeholder name

bool operator<(const OpX5_TA &a, const OpX5_TA &b);	// NOTE: placeholder name
bool operator<(const OpX5_TC &a, const OpX5_TC &b);	// NOTE: placeholder name

template void std::_Insertion_sort<OpX5_TA*>(OpX5_TA *first, OpX5_TA *last);
template void std::_Insertion_sort<string*>(string *first, string *last);
template void std::_Insertion_sort<OpX5_Obj**, bool (*)(OpX5_Obj *, OpX5_Obj *)>(OpX5_Obj **first, OpX5_Obj **last, bool (*pred)(OpX5_Obj *, OpX5_Obj *));
template void std::_Insertion_sort<OpX5_TC*, bool (*)(OpX5_TC, OpX5_TC)>(OpX5_TC *first, OpX5_TC *last, bool (*pred)(OpX5_TC, OpX5_TC));
template void std::_Insertion_sort<string*, bool (*)(const string &, const string &)>(string *first, string *last, bool (*pred)(const string &, const string &));
template void std::sort_heap<string*>(string *first, string *last);
template void std::_Sort_heap<OpX5_TA*>(OpX5_TA *first, OpX5_TA *last);

template void std::sort_heap<OpX5_TA*>(OpX5_TA *first, OpX5_TA *last);

template <class T> void OpX5_deleteObjectAndStep(vector<T*> &v, int &index)	// NOTE: placeholder name
{
	delete v[index];
	v.erase(v.begin()+index);
	index--;
}

template <class T> void OpX5_insertAt(vector<T> &v, int index, T value)	// NOTE: placeholder name
{
	if (index == v.size())
		v.push_back(value);
	else
		v.insert(v.begin()+index,value);
}

struct OpX5_D9de640	// NOTE: placeholder name
{
	int v;
};

template void OpX5_deleteObjectAndStep<OpX5_D9de640>(vector<OpX5_D9de640*> &v, int &index);
template void OpX5_insertAt<OpX5_H4*>(vector<OpX5_H4*> &v, int index, OpX5_H4 *value);
