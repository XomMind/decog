// op_r5h_reg: singleton-pointer registration helpers (0x9b70f0-0x9b82d0), Beta 17.1.
// NOTE: class/global/method names are placeholders; each helper stores (this - 0x31) in a global and returns this.
#include <string>
#include <vector>
using namespace std;

struct OpR5h_Pad31	// NOTE: placeholder name
{
	char pad[0x31];
};

class OpR5h_RegBase	// NOTE: placeholder name
{
public:
	OpR5h_RegBase *register224();	// NOTE: placeholder name (0x9b70f0)
	OpR5h_RegBase *register228();	// NOTE: placeholder name (0x9b71d0)
	OpR5h_RegBase *register22c();	// NOTE: placeholder name (0x9b7290)
	OpR5h_RegBase *register230();	// NOTE: placeholder name (0x9b72f0)
	OpR5h_RegBase *register234();	// NOTE: placeholder name (0x9b7350)
	OpR5h_RegBase *register238();	// NOTE: placeholder name (0x9b8210)
	OpR5h_RegBase *register23c();	// NOTE: placeholder name (0x9b8270)
	OpR5h_RegBase *register240();	// NOTE: placeholder name (0x9b82d0)
};

class OpR5h_RegOwner : public OpR5h_Pad31, public OpR5h_RegBase	// NOTE: placeholder name
{
};

OpR5h_RegOwner *opR5h_global_d3c224;	// NOTE: placeholder name (0xd3c224)
OpR5h_RegOwner *opR5h_global_d3c228;	// NOTE: placeholder name (0xd3c228)
OpR5h_RegOwner *opR5h_global_d3c22c;	// NOTE: placeholder name (0xd3c22c)
OpR5h_RegOwner *opR5h_global_d3c230;	// NOTE: placeholder name (0xd3c230)
OpR5h_RegOwner *opR5h_global_d3c234;	// NOTE: placeholder name (0xd3c234)
OpR5h_RegOwner *opR5h_global_d3c238;	// NOTE: placeholder name (0xd3c238)
OpR5h_RegOwner *opR5h_global_d3c23c;	// NOTE: placeholder name (0xd3c23c)
OpR5h_RegOwner *opR5h_global_d3c240;	// NOTE: placeholder name (0xd3c240)

OpR5h_RegBase *OpR5h_RegBase::register224()
{
	opR5h_global_d3c224 = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register228()
{
	opR5h_global_d3c228 = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register22c()
{
	opR5h_global_d3c22c = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register230()
{
	opR5h_global_d3c230 = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register234()
{
	opR5h_global_d3c234 = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register238()
{
	opR5h_global_d3c238 = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register23c()
{
	opR5h_global_d3c23c = (OpR5h_RegOwner*)this;
	return this;
}

OpR5h_RegBase *OpR5h_RegBase::register240()
{
	opR5h_global_d3c240 = (OpR5h_RegOwner*)this;
	return this;
}
