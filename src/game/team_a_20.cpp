// team_a_20: string/parse helpers from the 600-2500 byte band (0x400000-0x4fffff) matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names; local names follow docs/local-name-buckets.txt.
#include <string>
#include <vector>
using namespace std;

void opw8_eraseLastChar(string &s);	// NOTE: placeholder name (0x407840)

// splits text at separator characters, keeping quoted runs together (0x408860)
void OpW7_split_408860(string &text, char separator, char quote, vector<string> &out, bool escapes)	// NOTE: placeholder name
{
	if (text.empty())
		return;
	unsigned int start = *text.begin() == separator ? text.find_first_not_of(separator,0) : 0;
	unsigned int end = *(((const string &)text).end() - 1) == separator ? text.find_last_not_of(separator) : text.size() - 1;
	out.push_back(string());
	string *part = &out.back();
	bool quoted = false;
	for (int i = start; i <= end; i++)	// unsigned compare as in the original
	{
		if (text[i] == quote)
		{
			if (escapes && i > 0 && text[i - 1] == '\\')
			{
				opw8_eraseLastChar(*part);
				*part += text[i];
			}
			else
				quoted = !quoted;
		}
		else if (text[i] == separator && !quoted)
		{
			out.push_back(string());
			part = &out.back();
			while (text[i + 1] == separator)
				i++;
		}
		else
			*part += text[i];
	}
}

// splits text into lines of at most width characters, breaking at newlines or spaces (0x408e60)
int opr5e_wrapText_408e60(string text, int width, vector<string> *out)	// NOTE: placeholder name
{
	while (true)
	{
		if (text.size() <= width)
		{
			out->push_back(text);
			break;
		}
		int end = width - 1;
		int index = -1;
		for (int i = 0; i <= end; i++)
		{
			if (text[i] == '\n')
			{
				index = i;
				goto cut;
			}
		}
		for (int j = end; j >= 0; j--)
		{
			if (text[j] == ' ')
			{
				index = j;
				break;
			}
		}
		if (index == -1)
			index = end;
		else
		{
			for (int k = index; k < text.size(); k++)
			{
				if (text[k] == ' ')
					text.erase(k,1);
				else
					break;
			}
			for (int m = index - 1; m >= 0; m--)
			{
				if (text[m] == ' ')
					text.erase(m,1);
				else
					break;
			}
		}
cut:
		if (!text.empty())
		{
			out->push_back(string(text.begin(),text.begin() + index));
			text.erase(text.begin(),text.begin() + index);
		}
		if (text.empty())
			break;
	}
	return out->size();
}
