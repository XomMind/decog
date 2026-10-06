// op_q5: container helper instances over vector<bool> (placeholder names)
// NOTE: placeholder names
#include <vector>
using namespace std;

template <class T> void OpQ5_moveElement(vector<T> &v, unsigned int from, unsigned int to)	// NOTE: placeholder name
{
	if (from == to)
		return;
	else if (from < to)
		rotate(v.begin()+from,v.begin()+from+1,v.begin()+to+1);
	else
		rotate(v.begin()+to,v.begin()+from,v.begin()+from+1);
}

template void OpQ5_moveElement<bool>(vector<bool> &v, unsigned int from, unsigned int to);
