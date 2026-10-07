// team_d_62: MessageLog::outputStream (0x513bb0, append recent combat log lines to the stream file).
// NOTE: class layouts are partial; member and global names are placeholders unless stated otherwise.
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct LogSource62	// NOTE: placeholder name and layout
{
	char	pad00[0x44];
	bool	unknown44;	// NOTE: placeholder name
};

struct LogLine62	// NOTE: placeholder name and layout
{
	LogSource62	*source;	// +0x00
	string		text;		// +0x04
};

extern string gameString_cfd42c;	// CUSTOM_FILE_PATH
extern string gameString_d21928;	// NOTE: placeholder name (0xd21928)
extern string configOptionNames[];	// 0xd35e18 (global_string_arrays.cpp)
extern bool streamLog62_d28eb1;		// NOTE: placeholder name (option)
extern ofstream combatStream62_d28eb8;	// NOTE: placeholder name

void logError(string location, string message);	// NOTE: placeholder name (0x404f10)

class MessageLog
{
public:
	vector<LogLine62 *>	lines;		// +0x00
	char				pad10[0x30 - 0x10];
	bool				streaming;	// +0x30, NOTE: placeholder name

	void outputStream(int count);
};

void MessageLog::outputStream(int count)
{
	if (!streaming || !streamLog62_d28eb1)
		return;
	if (!combatStream62_d28eb8.is_open())
	{
		combatStream62_d28eb8.open((gameString_cfd42c + "user/" + "combat_log_stream.txt").c_str(),ios::out | ios::app);
		if (!combatStream62_d28eb8.is_open())
		{
			logError("MessageLog::outputStream()","Unable to open " + (gameString_cfd42c + "user/" + "combat_log_stream.txt") + " for writing, no streaming and resetting " + configOptionNames[195]);
			streamLog62_d28eb1 = false;
		}
		else
			combatStream62_d28eb8 << ">>>>> Cogmind Combat Log (Stream) - " << gameString_d21928 << "\n";
	}
	if (count == 0)
		combatStream62_d28eb8 << "  [repeat]\n";
	else
	{
		for (unsigned int i = lines.size() - count; i < lines.size(); i++)
		{
			if (lines[i]->source && lines[i]->source->unknown44 && lines[i]->text != " ")
				combatStream62_d28eb8 << lines[i]->text << "\n";
		}
	}
	combatStream62_d28eb8.flush();
}
