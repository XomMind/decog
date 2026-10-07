// team_d_24: stream constructor of a pooled timer record (0x6720a0).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
// The value-holder constructors are defined here with placeholder bodies so that LTCG can prove they
// cannot throw, as in the exe (no exception states; the new-expression temporaries remain).
#include <istream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);

struct IntValue	// NOTE: placeholder name (4 bytes, constructor 0x45e510)
{
	int value;

	IntValue();
};

IntValue::IntValue()	// NOTE: placeholder body
{
	value = 0;
}

struct IntBox	// NOTE: placeholder name (4 bytes; constructor folded with a vector iterator operator++)
{
	int value;

	IntBox();
	void read(istream &stream);	// NOTE: placeholder name (OpC_IntBox::read)
};

IntBox::IntBox()	// NOTE: placeholder body
{
	value = 0;
}

class HProp
{
	int ID;
public:
	HProp();
	void read(istream &stream);	// NOTE: placeholder name (OpC_IntBox::read)
};

class OpD_Pooled6720a0	// NOTE: placeholder name (read by OpY9_Pool4::unserialize)
{
public:
	OpD_Pooled6720a0(istream &stream);

	HProp	handle;		// NOTE: placeholder name
	int		unknown04;	// NOTE: placeholder name
	int		type;		// NOTE: placeholder name
	void	*data;		// NOTE: placeholder name
};

OpD_Pooled6720a0::OpD_Pooled6720a0(istream &stream)
{
	handle.read(stream);
	readBinary(stream,&unknown04);
	readBinary(stream,&type);
	switch (type)
	{
		case 0:
			data = new IntValue;
			readBinary(stream,&((IntValue *)data)->value);
			break;
		case 1:
			data = new IntBox;
			((IntBox *)data)->read(stream);
			break;
		case 2:
			data = new IntBox;
			((IntBox *)data)->read(stream);
			break;
	}
}
