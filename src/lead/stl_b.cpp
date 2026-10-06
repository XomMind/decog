// lead_stl_b: explicit map/set/list/deque instantiations over placeholder types (see stl_a.cpp)
// NOTE: placeholder element types.
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <vector>
using namespace std;

struct B8_0
{
	char pad[8];
	bool operator==(const B8_0 &e) const;
	bool operator<(const B8_0 &e) const;
};

struct B8_1
{
	char pad[8];
	bool operator==(const B8_1 &e) const;
	bool operator<(const B8_1 &e) const;
	B8_1();
	B8_1(const B8_1 &e);
};

struct B8_2
{
	char pad[8];
	bool operator==(const B8_2 &e) const;
	bool operator<(const B8_2 &e) const;
	B8_2();
	B8_2(const B8_2 &e);
	B8_2 &operator=(const B8_2 &e);
	~B8_2();
};

struct Bc_0
{
	char pad[12];
	bool operator==(const Bc_0 &e) const;
	bool operator<(const Bc_0 &e) const;
};

struct Bc_1
{
	char pad[12];
	bool operator==(const Bc_1 &e) const;
	bool operator<(const Bc_1 &e) const;
	Bc_1();
	Bc_1(const Bc_1 &e);
};

struct Bc_2
{
	char pad[12];
	bool operator==(const Bc_2 &e) const;
	bool operator<(const Bc_2 &e) const;
	Bc_2();
	Bc_2(const Bc_2 &e);
	Bc_2 &operator=(const Bc_2 &e);
	~Bc_2();
};

struct B10_0
{
	char pad[16];
	bool operator==(const B10_0 &e) const;
	bool operator<(const B10_0 &e) const;
};

struct B10_1
{
	char pad[16];
	bool operator==(const B10_1 &e) const;
	bool operator<(const B10_1 &e) const;
	B10_1();
	B10_1(const B10_1 &e);
};

struct B10_2
{
	char pad[16];
	bool operator==(const B10_2 &e) const;
	bool operator<(const B10_2 &e) const;
	B10_2();
	B10_2(const B10_2 &e);
	B10_2 &operator=(const B10_2 &e);
	~B10_2();
};

struct B14_0
{
	char pad[20];
	bool operator==(const B14_0 &e) const;
	bool operator<(const B14_0 &e) const;
};

struct B14_1
{
	char pad[20];
	bool operator==(const B14_1 &e) const;
	bool operator<(const B14_1 &e) const;
	B14_1();
	B14_1(const B14_1 &e);
};

struct B14_2
{
	char pad[20];
	bool operator==(const B14_2 &e) const;
	bool operator<(const B14_2 &e) const;
	B14_2();
	B14_2(const B14_2 &e);
	B14_2 &operator=(const B14_2 &e);
	~B14_2();
};

struct B18_0
{
	char pad[24];
	bool operator==(const B18_0 &e) const;
	bool operator<(const B18_0 &e) const;
};

struct B18_1
{
	char pad[24];
	bool operator==(const B18_1 &e) const;
	bool operator<(const B18_1 &e) const;
	B18_1();
	B18_1(const B18_1 &e);
};

struct B18_2
{
	char pad[24];
	bool operator==(const B18_2 &e) const;
	bool operator<(const B18_2 &e) const;
	B18_2();
	B18_2(const B18_2 &e);
	B18_2 &operator=(const B18_2 &e);
	~B18_2();
};

struct B20_0
{
	char pad[32];
	bool operator==(const B20_0 &e) const;
	bool operator<(const B20_0 &e) const;
};

struct B20_1
{
	char pad[32];
	bool operator==(const B20_1 &e) const;
	bool operator<(const B20_1 &e) const;
	B20_1();
	B20_1(const B20_1 &e);
};

struct B20_2
{
	char pad[32];
	bool operator==(const B20_2 &e) const;
	bool operator<(const B20_2 &e) const;
	B20_2();
	B20_2(const B20_2 &e);
	B20_2 &operator=(const B20_2 &e);
	~B20_2();
};

struct B30_0
{
	char pad[48];
	bool operator==(const B30_0 &e) const;
	bool operator<(const B30_0 &e) const;
};

struct B30_1
{
	char pad[48];
	bool operator==(const B30_1 &e) const;
	bool operator<(const B30_1 &e) const;
	B30_1();
	B30_1(const B30_1 &e);
};

struct B30_2
{
	char pad[48];
	bool operator==(const B30_2 &e) const;
	bool operator<(const B30_2 &e) const;
	B30_2();
	B30_2(const B30_2 &e);
	B30_2 &operator=(const B30_2 &e);
	~B30_2();
};

template class std::list<int>;
template class std::deque<int>;
template class std::list<unsigned int>;
template class std::deque<unsigned int>;
template class std::list<char>;
template class std::deque<char>;
template class std::list<float>;
template class std::deque<float>;
template class std::list<void *>;
template class std::deque<void *>;
template class std::list<string>;
template class std::deque<string>;
template class std::list<vector<int>>;
template class std::deque<vector<int>>;
template class std::list<vector<string>>;
template class std::deque<vector<string>>;
template class std::list<B8_0>;
template class std::deque<B8_0>;
template class std::list<B8_1>;
template class std::deque<B8_1>;
template class std::list<B8_2>;
template class std::deque<B8_2>;
template class std::list<Bc_0>;
template class std::deque<Bc_0>;
template class std::list<Bc_1>;
template class std::deque<Bc_1>;
template class std::list<Bc_2>;
template class std::deque<Bc_2>;
template class std::list<B10_0>;
template class std::deque<B10_0>;
template class std::list<B10_1>;
template class std::deque<B10_1>;
template class std::list<B10_2>;
template class std::deque<B10_2>;
template class std::list<B14_0>;
template class std::deque<B14_0>;
template class std::list<B14_1>;
template class std::deque<B14_1>;
template class std::list<B14_2>;
template class std::deque<B14_2>;
template class std::list<B18_0>;
template class std::deque<B18_0>;
template class std::list<B18_1>;
template class std::deque<B18_1>;
template class std::list<B18_2>;
template class std::deque<B18_2>;
template class std::list<B20_0>;
template class std::deque<B20_0>;
template class std::list<B20_1>;
template class std::deque<B20_1>;
template class std::list<B20_2>;
template class std::deque<B20_2>;
template class std::list<B30_0>;
template class std::deque<B30_0>;
template class std::list<B30_1>;
template class std::deque<B30_1>;
template class std::list<B30_2>;
template class std::deque<B30_2>;
template class std::set<int>;
template class std::map<int, int>;
template class std::map<int, unsigned int>;
template class std::map<int, char>;
template class std::map<int, float>;
template class std::map<int, void *>;
template class std::map<int, string>;
template class std::map<int, vector<int>>;
template class std::map<int, vector<string>>;
template class std::map<int, B8_0>;
template class std::map<int, B8_1>;
template class std::map<int, B8_2>;
template class std::map<int, Bc_0>;
template class std::map<int, Bc_1>;
template class std::map<int, Bc_2>;
template class std::map<int, B10_0>;
template class std::map<int, B10_1>;
template class std::map<int, B10_2>;
template class std::set<unsigned int>;
template class std::map<unsigned int, int>;
template class std::map<unsigned int, unsigned int>;
template class std::map<unsigned int, char>;
template class std::map<unsigned int, float>;
template class std::map<unsigned int, void *>;
template class std::map<unsigned int, string>;
template class std::map<unsigned int, vector<int>>;
template class std::map<unsigned int, vector<string>>;
template class std::map<unsigned int, B8_0>;
template class std::map<unsigned int, B8_1>;
template class std::map<unsigned int, B8_2>;
template class std::map<unsigned int, Bc_0>;
template class std::map<unsigned int, Bc_1>;
template class std::map<unsigned int, Bc_2>;
template class std::map<unsigned int, B10_0>;
template class std::map<unsigned int, B10_1>;
template class std::map<unsigned int, B10_2>;
template class std::set<string>;
template class std::map<string, int>;
template class std::map<string, unsigned int>;
template class std::map<string, char>;
template class std::map<string, float>;
template class std::map<string, void *>;
template class std::map<string, string>;
template class std::map<string, vector<int>>;
template class std::map<string, vector<string>>;
template class std::map<string, B8_0>;
template class std::map<string, B8_1>;
template class std::map<string, B8_2>;
template class std::map<string, Bc_0>;
template class std::map<string, Bc_1>;
template class std::map<string, Bc_2>;
template class std::map<string, B10_0>;
template class std::map<string, B10_1>;
template class std::map<string, B10_2>;
template class std::set<void *>;
template class std::map<void *, int>;
template class std::map<void *, unsigned int>;
template class std::map<void *, char>;
template class std::map<void *, float>;
template class std::map<void *, void *>;
template class std::map<void *, string>;
template class std::map<void *, vector<int>>;
template class std::map<void *, vector<string>>;
template class std::map<void *, B8_0>;
template class std::map<void *, B8_1>;
template class std::map<void *, B8_2>;
template class std::map<void *, Bc_0>;
template class std::map<void *, Bc_1>;
template class std::map<void *, Bc_2>;
template class std::map<void *, B10_0>;
template class std::map<void *, B10_1>;
template class std::map<void *, B10_2>;
template class std::set<char>;
template class std::map<char, int>;
template class std::map<char, unsigned int>;
template class std::map<char, char>;
template class std::map<char, float>;
template class std::map<char, void *>;
template class std::map<char, string>;
template class std::map<char, vector<int>>;
template class std::map<char, vector<string>>;
template class std::map<char, B8_0>;
template class std::map<char, B8_1>;
template class std::map<char, B8_2>;
template class std::map<char, Bc_0>;
template class std::map<char, Bc_1>;
template class std::map<char, Bc_2>;
template class std::map<char, B10_0>;
template class std::map<char, B10_1>;
template class std::map<char, B10_2>;
