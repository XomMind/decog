// Discord comment queue operation, recovered from Beta 17.1 at 0x4f9f50.
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
void logError(string location, string message);
// NOTE: placeholder names for unrecovered global state and debug getter.
extern int sweepDiscordInitialized;
extern int sweepDiscordSuppressed;
class GameMetaData
{
public:
	bool sweepDebugMode();
};
extern GameMetaData sweepMetadata;
class DiscordWebhook
{
	char unknown00[0x20];
	HANDLE mutex;
	vector<string> comments;
public:
	void addComment(string comment);
};
void DiscordWebhook::addComment(string comment)
{
	if (!sweepDiscordInitialized)
	{
		logError("DiscordWebhook::postComment()","not yet initializd");
		return;
	}
	if (sweepMetadata.sweepDebugMode() || sweepDiscordSuppressed)
		return;
	if (comments.size() >= 100)
	{
		logError("DiscordWebhook::addComment()","comment queue reached cap, message discarded");
		return;
	}
	if (WaitForSingleObject(mutex,INFINITE) == WAIT_OBJECT_0)
		comments.push_back(comment);
	ReleaseMutex(mutex);
}

// Upload transport check, recovered from 0x449850. No network call is run by verification.
extern "C" int SDLNet_TCP_Send(void *socket, const void *data, int length);
class Upload
{
public:
	void sendString(void *socket, const string &text);
};
void Upload::sendString(void *socket, const string &text)
{
	if (SDLNet_TCP_Send(socket,text.c_str(),text.size()) != text.size())
		logError("Upload::sendString()",text.size() < 1000 ? "Bad write: " + text : string("Bad write"));
}
