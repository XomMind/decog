// op_x5_manip: istream manipulator applier (placeholder names)
#include <istream>
using namespace std;
struct OpX5_Arg	// NOTE: placeholder name
{
	int a;
	int b;
};

struct OpX5_Manip	// NOTE: placeholder name
{
	void (*fn)(ios_base *base, OpX5_Arg arg);
	int pad4;
	OpX5_Arg arg;
};

istream *OpX5_applyManip(istream *s, OpX5_Manip *m)	// NOTE: placeholder name
{
	m->fn(s,m->arg);
	return s;
}
