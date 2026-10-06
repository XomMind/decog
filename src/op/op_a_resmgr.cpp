// XResourceMgr: thin layer over PhysfsWrapper (0x414ef0-0x415760).
#include <string>
#include <vector>
using namespace std;

void logNote(string location, string message);	// NOTE: placeholder name (0x404fd0)
void logMessage(string message);	// NOTE: placeholder name (0x404cb0)
void initColorTables();	// NOTE: placeholder name (0x413990)

struct PhysfsDirectory;	// NOTE: placeholder name

class PhysfsWrapper	// NOTE: placeholder name
{
public:
	string archiveExt;	// NOTE: placeholder name
	string baseDir;	// NOTE: placeholder name

	PhysfsWrapper();
	string init(int argc, char *argv[], string organization, string appName);	// NOTE: placeholder name
	void setArchiveExt(string ext);	// NOTE: placeholder name
	bool archiveIsValid(string path, bool append);	// NOTE: placeholder name
	bool exists(string path);	// NOTE: placeholder name
	void getFileList(string dir, vector<string> *files, string ext, bool includeDirectories);	// NOTE: placeholder name
	void getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext);	// NOTE: placeholder name
};

class XResourceMgr
{
public:
	PhysfsWrapper *physfs;	// NOTE: placeholder name

	XResourceMgr(int argc, char *argv[], string organization, string appName);
	void setArchiveExt(string ext);	// NOTE: placeholder name
	bool archiveIsValid(string path, bool append);	// NOTE: placeholder name
	bool fileExists(string path);	// NOTE: placeholder name
	void getFileList(string dir, vector<string> *files, string ext);	// NOTE: placeholder name
	void getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext);	// NOTE: placeholder name
};

XResourceMgr::XResourceMgr(int argc, char *argv[], string organization, string appName)
{
	physfs = new PhysfsWrapper();
	string error = physfs->init(argc,argv,organization,appName);
	if (!error.empty())
		logNote("XResourceMgr()","PhysFS::init() returned error: " + error);

	logMessage("Loading colors");
	initColorTables();
}

void XResourceMgr::setArchiveExt(string ext)
{
	physfs->setArchiveExt(ext);
}

bool XResourceMgr::archiveIsValid(string path, bool append)
{
	return physfs->archiveIsValid(path,append);
}

bool XResourceMgr::fileExists(string path)
{
	return physfs->exists(path);
}

void XResourceMgr::getFileList(string dir, vector<string> *files, string ext)
{
	physfs->getFileList(dir,files,ext,false);
}

void XResourceMgr::getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext)
{
	physfs->getFileTree(dir,directories,ext);
}
