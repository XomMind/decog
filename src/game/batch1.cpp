// Batch 1 of small game methods matched against COGMIND.exe (Beta 17.1).
// NOTE: class layouts are partial; padding members and names are placeholders.
#include <string>
#include <vector>
#include <limits>
#include <ostream>
using namespace std;

void logError(string location, string message);	// NOTE: placeholder name

struct LoreEntry	// NOTE: placeholder name
{
	char pad[4];
	bool collected;	// NOTE: placeholder name
};

struct ArtData	// NOTE: placeholder name
{
	bool isEmpty();	// NOTE: placeholder name (0x9b81b0)
};

struct GalleryItem	// NOTE: placeholder name
{
	char pad0[8];
	string name;	// NOTE: placeholder name
	char pad1[0x7c - 8 - sizeof(string)];
	ArtData art;	// NOTE: placeholder name
	char pad2[0x94 - 0x7c - 1];
	int category;	// NOTE: placeholder name
};

extern vector<LoreEntry *> loreEntries;	// NOTE: placeholder name (0xd02cb4)
extern vector<GalleryItem *> galleryItems;	// NOTE: placeholder name (0xd2d1c4)

class GameMetaData
{
public:
	int getLoreCollectionPercent();
	int getGalleryCollectionPercent();

	char pad[0x168];
	vector<int> galleryCollected;	// NOTE: placeholder name
};

int GameMetaData::getLoreCollectionPercent()
{
	int collected = 0;
	{
		int percent;
		for (unsigned int i = 0; i < loreEntries.size(); i++)
		{
			if (loreEntries[i]->collected)
				collected++;
		}
		percent = collected * 100 / loreEntries.size();
		if (percent > 100)
		{
			logError("GameMetaData::getLoreCollectionPercent()","value exceeds 100");
			percent = 100;
		}
		return percent;
	}
}

int GameMetaData::getGalleryCollectionPercent()
{
	{
		int all = 0;		// NOTE: local names chosen to get the original stack slot order
		int owned = 0;
		int percent;
		for (unsigned int i = 0; i < galleryCollected.size(); i++)
		{
			if (!galleryItems[i]->art.isEmpty() && galleryItems[i]->category != 2)
				all++;
			if (galleryCollected[i])
				owned++;
		}
		percent = owned * 100 / all;
		if (percent > 100)
		{
			logError("GameMetaData::getGalleryCollectionPercent()","value exceeds 100");
			percent = 100;
		}
		return percent;
	}
}

class AttachState	// NOTE: placeholder name
{
public:
	bool unknown46dd90();	// NOTE: placeholder name
};
extern AttachState attachState;	// NOTE: placeholder name (0xcf45d8)

class GM
{
public:
	void addItemAttachCount(int itemID, int count, bool force);	// NOTE: placeholder parameter names

	char pad[0x168];
	vector<int> itemAttachCounts;	// NOTE: placeholder name
};

void GM::addItemAttachCount(int itemID, int count, bool force)
{
	if (attachState.unknown46dd90() && !force)
		return;
	if (galleryItems[itemID]->art.isEmpty())
	{
		logError("GM::addItemAttachCount()",galleryItems[itemID]->name + " has no art!");
		return;
	}
	if (itemAttachCounts[itemID] == -1)
		itemAttachCounts[itemID] = 0;
	if (itemAttachCounts[itemID] == numeric_limits<int>::max())
		return;
	itemAttachCounts[itemID] += count;
}

struct Point	// NOTE: placeholder layout
{
	int x;
	int y;
};
string pointToString(const Point &p);	// NOTE: placeholder name (0x40a4a0)

class Entity	// NOTE: placeholder layout
{
public:
	const string &getNameAt0c();	// NOTE: placeholder name (0x416f40 returns this+0xc, not Entity::getName)
};

class HEntity	// NOTE: placeholder layout
{
	int ID;
public:
	Entity *operator->() const;	// 0x9b6570
};

class HProp
{
	int ID;
public:
	HProp();
};

struct ItemType;
bool findItemType(vector<ItemType *> &v, const string &name, ItemType **out);	// NOTE: placeholder name (0x9d7a40)
extern vector<ItemType *> itemTypes;	// NOTE: placeholder name (0xd2d1c4)

class BS
{
public:
	HProp giveItem(const string &itemName, HEntity entity, bool a, bool b);	// NOTE: placeholder parameter names
	HProp placeItem(const string &itemName, const Point &p);	// NOTE: placeholder parameter names
	HProp unknown6c51d0(ItemType *type, HEntity entity, bool a, bool b);	// NOTE: placeholder name
	HProp unknown6c5400(ItemType *type, const Point &p);	// NOTE: placeholder name
};

HProp BS::giveItem(const string &itemName, HEntity entity, bool a, bool b)
{
	ItemType *type;
	findItemType(itemTypes,itemName,&type);
	if (type == NULL)
	{
		logError("BS::giveItem()","Item \"" + itemName + "\" not found for " + entity->getNameAt0c());
		return HProp();
	}
	return unknown6c51d0(type,entity,a,b);
}

HProp BS::placeItem(const string &itemName, const Point &p)
{
	ItemType *type;
	findItemType(itemTypes,itemName,&type);
	if (type == NULL)
	{
		logError("BS::placeItem()","Item \"" + itemName + "\" not found for " + pointToString(p));
		return HProp();
	}
	return unknown6c5400(type,p);
}

class ProtoMessage	// NOTE: placeholder name (protobuf MessageLite, library code)
{
public:
	bool SerializeToString(string *output) const;	// 0xa5ae30
};

void writeString(ostream &out, string s);	// NOTE: placeholder name (0x409650)

class UploadScoreData
{
public:
	void serialize(ostream &out);	// NOTE: placeholder parameter name

	ProtoMessage *data;	// NOTE: placeholder name
};

void UploadScoreData::serialize(ostream &out)
{
	string buffer;
	if (!data->SerializeToString(&buffer))
		logError("UploadScoreData::serialize()","Data serialization failed!");
	writeString(out,buffer);
}
