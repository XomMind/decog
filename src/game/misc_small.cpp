// Small game methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include "../consoles/console.h"

struct ItemType	// NOTE: placeholder name
{
	char pad[0x90];
	bool autoActivate;	// NOTE: placeholder name
};

class Item
{
public:
	void setActivateOkayTurn(int turn);

	int pad0;
	int pad4;
	ItemType *type;
	char pad0c[0x20];
	int activateOkayTurn;	// NOTE: placeholder name
};

void Item::setActivateOkayTurn(int turn)
{
	if (turn < 0 && type->autoActivate)
	{
		logError("Item::setActivateOkayTurn()","cannot set an auto-activate item to a negative/broken value");
		return;
	}
	activateOkayTurn = turn;
}

class SoundMgr	// NOTE: placeholder name
{
public:
	void updatePropMute(int propID);	// 0x454520
	void unknown4544c0(int value);	// NOTE: placeholder name
	void unknown4544e0();	// NOTE: placeholder name
	void unknown454540();	// NOTE: placeholder name
	void unknown500010();	// NOTE: placeholder name
	void unknown500260(int value);	// NOTE: placeholder name
	void unknown5003b0();	// NOTE: placeholder name
};
extern SoundMgr soundMgr;	// NOTE: placeholder name

class Prop
{
public:
	void setSoundMute(bool mute);

	int ID;
	char pad4[0x3d];
	bool soundOrigin;	// NOTE: placeholder name
	bool soundMute;	// NOTE: placeholder name
};

void Prop::setSoundMute(bool mute)
{
	if (!soundOrigin)
	{
		logError("Prop::setSoundMute()","attempting to set muteAmbient for non-soundOrigin");
		return;
	}
	if (mute == soundMute)
		return;
	soundMute = mute;
	soundMgr.updatePropMute(ID);
}

class CMap : public Console
{
public:
	void endAudioLogs();
	XConsole *getAudioLog() { return audioLog; };	// 0x49abd0
	void unknown819900();	// NOTE: placeholder name

	char pad[0x36c - sizeof(Console)];
	XConsole *audioLog;	// NOTE: placeholder name
};

void CMap::endAudioLogs()
{
	if (audioLog == NULL)
	{
		logError("CMap::endAudioLogs()","no audio log found");
		return;
	}
	if (audioLog != NULL)
	{
		removeSubconsole(audioLog);
		audioLog = NULL;
	}
}

class AudioMixer	// NOTE: placeholder name
{
public:
	void setVolume(int volume);	// 0x419580
	void haltAll();	// 0x419c50
};
extern AudioMixer *audioMixer;	// NOTE: placeholder name
extern bool noAudio;	// NOTE: placeholder name
extern bool unmuteRestoreAmbient;	// NOTE: placeholder name
extern int musicVolume;	// NOTE: placeholder name
extern CMap *cmap;	// NOTE: placeholder name

struct SoundRef { int value; };	// NOTE: placeholder, returned by value

class SoundSource	// NOTE: placeholder name
{
public:
	SoundRef unknown4630f0();	// NOTE: placeholder name
};
extern SoundSource *soundSource;	// NOTE: placeholder name

class CMission
{
public:
	void muteAudio();
	void unmuteAudio(bool keepSounds);	// NOTE: placeholder parameter name
};

void CMission::muteAudio()
{
	if (noAudio)
	{
		logError("CMission::muteAudio()","attempting to mute w/noAudio setting");
		return;
	}
	audioMixer->setVolume(0);
	audioMixer->haltAll();
	soundMgr.unknown4544e0();
	soundMgr.unknown5003b0();
	if (cmap != NULL && cmap->getAudioLog())
		cmap->endAudioLogs();
}

void CMission::unmuteAudio(bool keepSounds)
{
	if (noAudio)
	{
		logError("CMission::unmuteAudio()","attempting to unmute w/noAudio setting");
		return;
	}
	audioMixer->setVolume(musicVolume);
	if (soundSource != NULL)
	{
		soundMgr.unknown4544c0(soundSource->unknown4630f0().value);
	}
	if (cmap != NULL && unmuteRestoreAmbient)
	{
		soundMgr.unknown454540();
		cmap->unknown819900();
	}
	if (!keepSounds)
	{
		soundMgr.unknown500260(0);
		soundMgr.unknown500010();
	}
}
