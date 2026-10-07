// team_d_14: definition record read from a binary stream (0x514690).
// NOTE: class layouts are partial; padding, member and method names are placeholders.
#include <vector>
#include <string>
#include <istream>
using namespace std;

template <class T> void readBinary(istream &stream, T *value);
void OpQ1_readString(istream &in, string *text);	// NOTE: placeholder name (0x4096f0)
void opR1f_465ea0(istream &stream, int *value);	// NOTE: placeholder name
template <class T> void OpQ5_readReference(istream &stream, T *&p, vector<T*> &list);	// NOTE: placeholder name
template <class T> void OpQ5_readReferences(istream &stream, vector<T*> &refs, vector<T*> &list);	// NOTE: placeholder name

struct OpD_Range	// NOTE: placeholder name (OpS1e_Range)
{
	int a;
	int b;

	OpD_Range();
	void read(istream &stream);	// 0x45f040
};

struct OpD_Ref84;	// NOTE: placeholder name
struct OpD_Ref88;	// NOTE: placeholder name
struct OpD_Ref98;	// NOTE: placeholder name
extern vector<OpD_Ref84 *> refs_cf67c0;	// NOTE: placeholder name
extern vector<OpD_Ref88 *> refs2_cf67c0;	// NOTE: placeholder name
extern vector<OpD_Ref98 *> refs_cfd2ec;	// NOTE: placeholder name

struct OpD_Def514690	// NOTE: placeholder name (read by OpQ5_readObjects<OpQ5_T9e0680>)
{
	OpD_Def514690(istream &stream);

	int		id;				// NOTE: placeholder name
	string	name;			// NOTE: placeholder name
	int		unknown20;		// NOTE: placeholder name
	int		unknown24;		// NOTE: placeholder name
	int		unknown28;		// NOTE: placeholder name
	int		unknown2c;		// NOTE: placeholder name
	int		unknown30;		// NOTE: placeholder name
	int		unknown34;		// NOTE: placeholder name
	int		unknown38;		// NOTE: placeholder name
	int		unknown3c;		// NOTE: placeholder name
	int		unknown40;		// NOTE: placeholder name
	OpD_Range	unknown44;	// NOTE: placeholder name
	OpD_Range	unknown4c;	// NOTE: placeholder name
	bool	unknown54;		// NOTE: placeholder name
	bool	unknown55;		// NOTE: placeholder name
	int		unknown58;		// NOTE: placeholder name
	int		unknown5c;		// NOTE: placeholder name
	int		unknown60;		// NOTE: placeholder name
	int		unknown64;		// NOTE: placeholder name
	int		unknown68;		// NOTE: placeholder name
	int		unknown6c;		// NOTE: placeholder name
	int		unknown70;		// NOTE: placeholder name
	bool	unknown74;		// NOTE: placeholder name
	int		unknown78;		// NOTE: placeholder name
	int		unknown7c;		// NOTE: placeholder name
	bool	unknown80;		// NOTE: placeholder name
	OpD_Ref84	*unknown84;	// NOTE: placeholder name
	vector<OpD_Ref88 *> unknown88;	// NOTE: placeholder name
	OpD_Ref98	*unknown98;	// NOTE: placeholder name
	vector<int>	unknown9c;	// NOTE: placeholder name
};

OpD_Def514690::OpD_Def514690(istream &stream)
{
	readBinary(stream,&id);
	OpQ1_readString(stream,&name);
	unknown20 = 0;
	unknown24 = 0;
	readBinary(stream,&unknown28);
	readBinary(stream,&unknown2c);
	opR1f_465ea0(stream,&unknown30);
	readBinary(stream,&unknown34);
	readBinary(stream,&unknown38);
	readBinary(stream,&unknown3c);
	readBinary(stream,&unknown40);
	unknown44.read(stream);
	unknown4c.read(stream);
	readBinary(stream,&unknown54);
	readBinary(stream,&unknown55);
	readBinary(stream,&unknown58);
	readBinary(stream,&unknown5c);
	readBinary(stream,&unknown60);
	readBinary(stream,&unknown64);
	readBinary(stream,&unknown68);
	readBinary(stream,&unknown6c);
	readBinary(stream,&unknown70);
	readBinary(stream,&unknown74);
	readBinary(stream,&unknown78);
	readBinary(stream,&unknown7c);
	readBinary(stream,&unknown80);
	OpQ5_readReference(stream,unknown84,refs_cf67c0);
	OpQ5_readReferences(stream,unknown88,refs2_cf67c0);
	OpQ5_readReference(stream,unknown98,refs_cfd2ec);
}
