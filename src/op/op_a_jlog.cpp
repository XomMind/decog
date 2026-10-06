// JLog: the engine's run.log logger (0x410710-0x4112d0), and the global log helpers (0x404b10-0x4051b0).
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include "util/stringutil.h"
using namespace std;

extern "C" unsigned int __cdecl SDL_GetTicks(void);

extern string gameStrings_d2ad60[];	// log level tags: "V=", "I=", "N=", "W=", "E=", "F="
extern string gameStrings_d32e10[];	// log level names: "VERBOSE" .. "FATAL ERROR"
extern string gameStrings_cf6ed8[];	// section end tags: "DONE"

string &padLeft(string &str, unsigned int width, char c);	// NOTE: placeholder name (0x408090)

enum logLevelType	// NOTE: placeholder name
{
	LOG_VERBOSE,
	LOG_INFO,
	LOG_NOTICE,
	LOG_WARNING,
	LOG_ERROR,
	LOG_FATAL,
};

struct LogMsg	// NOTE: placeholder name
{
	string text;
	unsigned int time;
	int type;
	int level;
	int indent;

	LogMsg() throw();
};

class JLog
{
public:
	string filename;
	ofstream *file;
	int indent;
	int minLevel;
	string header;	// NOTE: placeholder name
	vector<LogMsg*> messages;
	void (*callback)(int level);	// NOTE: placeholder name
	bool unknown58;
	HANDLE mutex;

	void setHeader(string header_);	// NOTE: placeholder name
	void setUnknown58(bool value);	// NOTE: placeholder name
	bool lastMessageFatal();	// NOTE: placeholder name

	void init();	// NOTE: placeholder name
	int log(int level, int type, int indentChange, string message);	// NOTE: placeholder name
	int begin(string message);	// NOTE: placeholder name
	int end(int type);	// NOTE: placeholder name
	int info(string message);	// NOTE: placeholder name
	int notice(string message);	// NOTE: placeholder name
	int warning(string message);	// NOTE: placeholder name
	int error(string message);	// NOTE: placeholder name
	int fatal(string message);	// NOTE: placeholder name
	string get(int index);
};

extern JLog *jlog;	// NOTE: placeholder name (0xcefa64)

void JLog::setHeader(string header_)
{
	header = header_;
}

void JLog::setUnknown58(bool value)
{
	unknown58 = value;
}

bool JLog::lastMessageFatal()
{
	return messages.empty() ? false : messages.back()->level == LOG_FATAL;
}

//==================================================================
// global log helpers
//==================================================================

void logDebug(string message)	// NOTE: placeholder name
{
}

void logMessage(string location, string message)	// NOTE: placeholder name
{
	jlog->info(location + " | " + message);
}

void logMessage(string message)	// NOTE: placeholder name
{
	jlog->info(message);
}

void logNotice(string location, string message)	// NOTE: placeholder name
{
	jlog->notice(location + " | " + message);
}

void logNotice(string message)	// NOTE: placeholder name
{
	jlog->notice(message);
}

void logWarning(string location, string message)	// NOTE: placeholder name
{
	jlog->warning(location + " | " + message);
}

void logError(string location, string message)	// NOTE: placeholder name
{
	jlog->error(location + " | " + message);
}

void logFatal(string location, string message)	// NOTE: placeholder name
{
	jlog->fatal(location + " | " + message);
}

void logInfo(string location, string message)	// NOTE: placeholder name
{
	jlog->begin(location + " | " + message);
}

void logInfo(string message)	// NOTE: placeholder name
{
	jlog->begin(message);
}

//==================================================================
// JLog
//==================================================================

void JLog::init()
{
	filename = "run.log";
	file = new ofstream(filename.c_str());
	indent = 0;
	minLevel = LOG_ERROR;
	callback = NULL;
	unknown58 = false;
	mutex = CreateMutexW(NULL,FALSE,NULL);
	*file << header << "\n";
}

int JLog::log(int level, int type, int indentChange, string message)
{
	if (minLevel > level)
		return 0;

	DWORD waitResult = WaitForSingleObject(mutex,INFINITE);
	switch (waitResult)
	{
		case WAIT_OBJECT_0:
		{
			LogMsg *msg = new LogMsg();
			msg->text = message;
			msg->time = SDL_GetTicks();
			msg->type = type;
			msg->level = level;
			msg->indent = indent;

			string prefix;
			for (int i = 0; i < indent; i++)
			{
				if (i < indent - 1)
					prefix += "|   ";
				else if (type >= 0)
					prefix += "\\---";
				else
					prefix += "|   ";
			}

			if (type < 0)
			{
				string time = intToString(msg->time);
				string thread = intToString(GetCurrentThreadId());
				*file << "\n[" << padLeft(thread,6,' ') << "] " << gameStrings_d2ad60[msg->level] << padLeft(time,7,'0') << " " << prefix << msg->text;
			}
			else
			{
				string time = intToString(msg->time);
				string thread = intToString(GetCurrentThreadId());
				*file << "\n[" << padLeft(thread,6,' ') << "] " << gameStrings_d2ad60[msg->level] << padLeft(time,7,'0') << " " << prefix << gameStrings_cf6ed8[msg->type];
			}

			indent += indentChange;
			messages.push_back(msg);
			file->flush();
			if (callback != NULL)
				callback(level);

			if (!ReleaseMutex(mutex))
			{
				string thread = intToString(GetCurrentThreadId());
				*file << "\n[" << padLeft(thread,6,' ') << "] HANDLE ERROR";
			}
			return messages.size() - 1;
		}
		default: return 0;
	}
}

int JLog::begin(string message)
{
	return log(LOG_INFO,-1,1,message);
}

int JLog::end(int type)
{
	return log(LOG_INFO,type,-1,"");
}

int JLog::info(string message)
{
	return log(LOG_INFO,-1,0,message);
}

int JLog::notice(string message)
{
	return log(LOG_NOTICE,-1,0,message);
}

int JLog::warning(string message)
{
	return log(LOG_WARNING,-1,0,message);
}

int JLog::error(string message)
{
	return log(LOG_ERROR,-1,0,message);
}

int JLog::fatal(string message)
{
	return log(LOG_FATAL,-1,0,message);
}

string JLog::get(int index)
{
	LogMsg *msg;
	if (index == -1)
	{
		if (messages.size() > 0)
			msg = messages.back();
		else
			return "No messages logged.";
	}
	else if (index < -1 || index >= messages.size())
	{
		error("JLog::get | Tried to retrieve a message with index " + intToString(index) + ", but index does not exist.");
		msg = messages.back();
	}
	else
		msg = messages[index];

	string text = gameStrings_d32e10[msg->level];
	text += ": ";
	text += msg->text;
	return text;
}
