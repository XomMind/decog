// team_c_07: singleton pool accessors for the globals registered by op_r5h_reg (0xd3c224-0xd3c240):
// unregister (store 0), static getter, and handle -> object lookup through the pool.
// NOTE: all class/method names are placeholders

class OpR5h_RegOwner;

extern OpR5h_RegOwner *opR5h_global_d3c224;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c228;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c22c;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c230;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c234;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c238;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c23c;	// op_r5h_reg.cpp
extern OpR5h_RegOwner *opR5h_global_d3c240;	// op_r5h_reg.cpp

class OpC_Pool	// NOTE: placeholder name (get() is ICF-folded with OpX1_EntityPool::get, 0x9d3af0)
{
public:
	void *get(int id);
};

class OpC_RegBase	// NOTE: placeholder name
{
public:
	void unregister224();	// 0x9b7130
	void unregister228();	// 0x9b7210
	void unregister22c();	// 0x9b72d0
	void unregister230();	// 0x9b7330
	void unregister234();	// 0x9b7390
	void unregister238();	// 0x9b8250
	void unregister23c();	// 0x9b82b0
	void unregister240();	// 0x9b8310
};

OpR5h_RegOwner *OpC_getPool224();	// 0x9bfdb0
OpR5h_RegOwner *OpC_getPool22c();	// 0x9bfe80
OpR5h_RegOwner *OpC_getPool230();	// 0x9bfe90
OpR5h_RegOwner *OpC_getPool234();	// 0x9bfea0
OpR5h_RegOwner *OpC_getPool238();	// 0x9c07d0
OpR5h_RegOwner *OpC_getPool23c();	// 0x9c07e0
OpR5h_RegOwner *OpC_getPool240();	// 0x9c07f0

struct OpC_Handle	// NOTE: placeholder name
{
	int ID;

	void *get224() const;	// 0x9b65b0
	void *get22c() const;	// 0x9b64f0
	void *get230() const;	// 0x9b7250
	void *get234() const;	// 0x9b73b0
	void *get238() const;	// 0x9b64d0
	void *get23c() const;	// 0x9b7910
	void *get240() const;	// 0x9b7cd0
};

void OpC_RegBase::unregister224()
{
	opR5h_global_d3c224 = 0;
}

void OpC_RegBase::unregister228()
{
	opR5h_global_d3c228 = 0;
}

void OpC_RegBase::unregister22c()
{
	opR5h_global_d3c22c = 0;
}

void OpC_RegBase::unregister230()
{
	opR5h_global_d3c230 = 0;
}

void OpC_RegBase::unregister234()
{
	opR5h_global_d3c234 = 0;
}

void OpC_RegBase::unregister238()
{
	opR5h_global_d3c238 = 0;
}

void OpC_RegBase::unregister23c()
{
	opR5h_global_d3c23c = 0;
}

void OpC_RegBase::unregister240()
{
	opR5h_global_d3c240 = 0;
}

OpR5h_RegOwner *OpC_getPool224()
{
	return opR5h_global_d3c224;
}

OpR5h_RegOwner *OpC_getPool22c()
{
	return opR5h_global_d3c22c;
}

OpR5h_RegOwner *OpC_getPool230()
{
	return opR5h_global_d3c230;
}

OpR5h_RegOwner *OpC_getPool234()
{
	return opR5h_global_d3c234;
}

OpR5h_RegOwner *OpC_getPool238()
{
	return opR5h_global_d3c238;
}

OpR5h_RegOwner *OpC_getPool23c()
{
	return opR5h_global_d3c23c;
}

OpR5h_RegOwner *OpC_getPool240()
{
	return opR5h_global_d3c240;
}

void *OpC_Handle::get224() const
{
	return ((OpC_Pool *)OpC_getPool224())->get(ID);
}

void *OpC_Handle::get22c() const
{
	return ((OpC_Pool *)OpC_getPool22c())->get(ID);
}

void *OpC_Handle::get230() const
{
	return ((OpC_Pool *)OpC_getPool230())->get(ID);
}

void *OpC_Handle::get234() const
{
	return ((OpC_Pool *)OpC_getPool234())->get(ID);
}

void *OpC_Handle::get238() const
{
	return ((OpC_Pool *)OpC_getPool238())->get(ID);
}

void *OpC_Handle::get23c() const
{
	return ((OpC_Pool *)OpC_getPool23c())->get(ID);
}

void *OpC_Handle::get240() const
{
	return ((OpC_Pool *)OpC_getPool240())->get(ID);
}
