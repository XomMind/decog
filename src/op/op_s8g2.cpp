// scratch generator TU (will be pruned)
#include <string>
#include <vector>
#include <algorithm>

template<int N> struct OpS8g_P { char pad[N]; };

template<class T> bool OpS8g_lt(const T& a, const T& b);

template<class T> struct OpS8g_Fam
{
	static void run(T* a, T* b, T* c, std::vector<T>& v, const T& val, bool (*p)(const T&, const T&))
	{
		std::make_heap(a, b, p);
		std::sort_heap(a, b, p);
		std::pop_heap(a, b, p);
		std::push_heap(a, b, p);
		std::_Insertion_sort(a, b, p);
		std::_Med3(a, b, c, p);
		std::_Median(a, b, c, p);
		std::sort(a, b, p);
		std::stable_sort(a, b, p);
		std::partial_sort(a, b, c, p);
		std::rotate(a, b, c);
		std::rotate(v.begin(), v.begin(), v.end());
		std::copy(a, b, c);
		std::copy_backward(a, b, c);
		std::lower_bound(a, b, val, p);
		std::upper_bound(a, b, val, p);
		v.push_back(val);
		v.insert(v.begin(), a, b);
		v.insert(v.begin(), (size_t)3, val);
		v.template emplace_back<T>(T(val));
		v.erase(v.begin(), v.end());
		v.erase(v.begin());
		v.resize(5, val);
		v.assign(a, b);
		v.reserve(5);
	}
};

#define FAM(T,N) void OpS8g_f##N(T* a, T* b, T* c, std::vector<T>& v, const T& val, bool (*p)(const T&, const T&)) { OpS8g_Fam<T>::run(a,b,c,v,val,p); }

typedef OpS8g_P<4> S4;	typedef OpS8g_P<8> S8;	typedef OpS8g_P<12> S12;	typedef OpS8g_P<16> S16;	typedef OpS8g_P<20> S20;	typedef OpS8g_P<24> S24;	typedef OpS8g_P<28> S28;
typedef OpS8g_P<32> S32;	typedef OpS8g_P<36> S36;	typedef OpS8g_P<40> S40;
FAM(S4,4) FAM(S8,8) FAM(S12,12) FAM(S16,16) FAM(S20,20) FAM(S24,24) FAM(S28,28) FAM(S32,32) FAM(S36,36) FAM(S40,40)
