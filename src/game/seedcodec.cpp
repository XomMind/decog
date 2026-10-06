#include "seedcodec.h"
#include <ctype.h>

void rotateSeedText(std::string &text)
{
	for (unsigned int i = 0; i < text.size(); ++i)
	{
		if (isalpha(text[i]))
		{
			if (text[i] >= 'a')
			{
				text[i] -= 13;
				if (text[i] < 'a') text[i] = 'z' - ('a' - text[i]) + 1;
			}
			else
			{
				text[i] -= 13;
				if (text[i] < 'A') text[i] = 'Z' - ('A' - text[i]) + 1;
			}
		}
		else if (isdigit(text[i]))
		{
			switch (text[i])
			{
				case '0': text[i] = '5'; break;
				case '1': text[i] = '6'; break;
				case '2': text[i] = '7'; break;
				case '3': text[i] = '8'; break;
				case '4': text[i] = '9'; break;
				case '5': text[i] = '0'; break;
				case '6': text[i] = '1'; break;
				case '7': text[i] = '2'; break;
				case '8': text[i] = '3'; break;
				case '9': text[i] = '4'; break;
			}
		}
	}
}
