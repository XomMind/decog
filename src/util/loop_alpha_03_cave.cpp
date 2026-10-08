// NOTE: partial cave-generator layout and exact-role private callee aliases.
struct LA3Range { int min,max; bool contains_40c190(int) throw(); };
struct LA3Settings { char pad[0x1c]; int unknown1C; char pad20[0x44-0x20]; int unknown44; char pad48[0x90-0x48]; LA3Range unknown90; int unknown98,unknown9C,unknownA0; };
extern LA3Settings *la3_cefb54;
struct LA3Area { char pad[0x40]; int unknown40; bool unknown44; char tail[15]; };
struct LA3Areas { unsigned size() const throw(); const LA3Area &operator[](unsigned) const throw(); };
extern LA3Areas la3_cf126c;
struct LA3Grid { int getWidth() throw(); int getHeight() throw(); int &at(int,int) throw(); };
extern LA3Grid la3_cf1964;
extern bool la3_bb856d,la3_bb856e,la3_bb8570,la3_bb8571;
extern int la3_ced22c,la3_ced224,la3_ced1c4,la3_ced16c;
extern int la3_ced1c8[],la3_ced170[],la3_ced230[];
void la3_fill9e2be0(int*,int,int) throw();
struct LA3Cave {
 char pad[0x54]; int unknown54; char pad58[0x7c-0x58]; int connectTries,bridgeFailures; bool finished,failed;
 void seed() throw(); void fillPass() throw(); void clearPass() throw(); int findAreas() throw(); bool connectAreas(int) throw(); void boxCaves() throw(); bool placeBridges() throw(); void sprout() throw(); void computeLinks() throw(); bool step4cbcd0(bool);
};
bool LA3Cave::step4cbcd0(bool singleStep)
{
	if (finished)
		return true;
	int failure = 9;
	switch (unknown54)
	{
		case 0:
			unknown54++;
			seed();
			if (singleStep)
				break;
		case 1:
			unknown54++;
			if (la3_bb856d)
			{
				fillPass();
				if (singleStep)
					break;
			}
		case 2:
			unknown54++;
			if (la3_bb856e)
			{
				clearPass();
				if (singleStep)
					break;
			}
		case 3:
			unknown54++;
			if (findAreas() == 0)
			{
				failure = 1;
				goto end;
			}
			if (singleStep)
				break;
		case 4:
			if (connectTries == 0 || !la3_bb8570)
				unknown54++;
			else
			{
				while (connectTries != 0)
				{
					connectTries--;
					if (!connectAreas(la3_cefb54->unknown1C - connectTries) && connectTries == la3_cefb54->unknown1C - 1)
					{
						failure = 2;
						goto end;
					}
					if (singleStep)
						return false;
				}
				unknown54++;
			}
		case 5:
			unknown54++;
			if (la3_bb8571)
			{
				boxCaves();
				if (singleStep)
					break;
			}
		case 6:
			unknown54++;
			if (!placeBridges())
			{
				bridgeFailures++;
				failure = 3;
				goto end;
			}
			else
			{
				if (false) {}
				bridgeFailures = 0;
			}
			if (singleStep)
				break;
		case 7:
			unknown54++;
			if (la3_cefb54->unknown44 != 0 && la3_bb8571)
				sprout();
	}
	if (false) {}
	if (unknown54 == 8)
	{
		la3_ced22c = 0;
		for (int i = 0; i < la3_cf126c.size(); i++)
		{
			if (la3_cf126c[i].unknown44)
				la3_ced22c++;
		}
		la3_ced224 = 0;
		computeLinks();
		for (int i = 0; i < la3_cf126c.size(); i++)
		{
			if (la3_cf126c[i].unknown40 > la3_ced224)
				la3_ced224 = la3_cf126c[i].unknown40;
		}
		la3_fill9e2be0(la3_ced1c8,21,0);
		la3_fill9e2be0(la3_ced170,21,0);
		la3_fill9e2be0(la3_ced230,21,0);
		for (int x = 0; x < la3_cf1964.getWidth(); x++)
		{
			for (int y = 0; y < la3_cf1964.getHeight(); y++)
				la3_ced1c8[la3_cf1964.at(x,y)]++;
		}
		int total = la3_cf1964.getWidth() * la3_cf1964.getHeight();
		int count = 0;
		for (int t = 4; t < 21; t++)
			count += la3_ced1c8[t];
		la3_ced1c4 = count * 100 / total;
		for (int t = 0; t < 21; t++)
		{
			la3_ced170[t] = la3_ced1c8[t] * 100 / total;
			la3_ced230[t] = la3_ced1c8[t] * 100 / count;
		}
		if (!la3_cefb54->unknown90.contains_40c190(la3_ced1c4))
		{
			failure = (la3_ced1c4 < la3_cefb54->unknown90.min ? 0 : 1) + 4;
			goto end;
		}
		if (la3_cf126c.size() < la3_cefb54->unknown98)
		{
			failure = 6;
			goto end;
		}
		if (la3_cefb54->unknown9C != 0 && la3_ced16c > la3_cefb54->unknown9C)
		{
			failure = 7;
			goto end;
		}
		if (la3_ced22c < la3_cefb54->unknownA0)
			failure = 8;
end:
		if (failure != 9)
		{
			failed = true;
			return true;
		}
		else
		{
			finished = true;
			failed = false;
			return true;
		}
	}
	else
		return false;
}
