// op_x1: SDL/Win32 clipboard payload copying.
// NOTE: function and local names are placeholders (0x41aad0).
// TEXT (0x54455854) drops CR and converts LF to CR; size includes the NUL.
// A NULL destination measures the same output without writing. Other formats
// carry a native 32-bit payload-size prefix; explicit length includes that prefix.
// Codegen: nested if/else tests re-read signed chars; a switch adds temporaries.
#include <cstring>

using namespace std;

int opX1CopyClipboardData(unsigned int format, char *destination, const char *source, int length)
{
	int size = 0;
	switch (format)
	{
	case 0x54455854:
		if (length == 0)
			length = strlen(source);
		if (destination)
		{
			while (--length >= 0)
			{
				if (*source == '\r')
				{
					// CR bytes are omitted.
				}
				else if (*source == '\n')
				{
					*destination = '\r';
					destination++;
					size++;
				}
				else
				{
					*destination = *source;
					destination++;
					size++;
				}
				source++;
			}
			*destination = 0;
			size++;
		}
		else
		{
			while (--length >= 0)
			{
				if (*source == '\r')
				{
					// CR bytes are omitted.
				}
				else
				{
					size++;
				}
				source++;
			}
			size++;
		}
		break;
	default:
		size = *(const int *)source;
		if (destination)
		{
			if (length == 0)
				memcpy(destination,source + 4,size);
			else
				memcpy(destination,source + 4,length - 4);
		}
		break;
	}
	return size;
}
