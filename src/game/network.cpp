// Network (SDL_net) setup/teardown, matched against COGMIND.exe (Beta 17.1).
// NOTE: placeholder names throughout.
#include <string>
#include <vector>
using namespace std;

extern "C" int SDLNet_Init(void);
extern "C" void SDLNet_Quit(void);
extern "C" void SDL_Delay(unsigned int ms);

void logError(string location, string message);	// NOTE: placeholder name
void logWarning(string location, string message);	// NOTE: placeholder name (0x404e50)

extern bool networkAvailable;	// NOTE: placeholder name (0xcefb3f)
extern vector<void *> networkThreads;	// NOTE: placeholder name (0xd16178)

class Network
{
public:
	static void init();
	static void deinit();
};

void Network::init()
{
	if (SDLNet_Init() == -1)
	{
		logError("Network::init()","SDLNet_Init() failed, some network features unavailable");
		return;
	}
	networkAvailable = true;
}

void Network::deinit()
{
	unsigned int waited;
	const unsigned int timeout = 5000;
	waited = 0;
	while (!networkThreads.empty())
	{
		SDL_Delay(10);
		waited += 10;
		if (waited >= timeout)
		{
			logWarning("Network::deinit()","Quitting while network threads still active due to suspected timeout");
			break;
		}
	}
	SDLNet_Quit();
}
