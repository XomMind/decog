// PhysicsFS wrapper used by XResourceMgr (0x403940-0x404ae0).
#include <string>
#include <vector>
#include "thirdparty/physfs.h"
using namespace std;

extern string gameString_cfd42c;	// CUSTOM_FILE_PATH
extern string gameString_cf11ac;	// ".x", default archive extension
#define CUSTOM_FILE_PATH	gameString_cfd42c

struct PhysfsDirectory	// NOTE: placeholder name
{
	string name;
	vector<string> files;
	vector<PhysfsDirectory*> subdirectories;

	PhysfsDirectory(const string &name_);
};

PhysfsDirectory::PhysfsDirectory(const string &name_)
	: name	(name_)
{
}

class PhysfsWrapper	// NOTE: placeholder name
{
public:
	string archiveExt;	// NOTE: placeholder name
	string baseDir;	// NOTE: placeholder name

	PhysfsWrapper();
	string init(int argc, char *argv[], string organization, string appName);	// NOTE: placeholder name
	string getBaseDir();	// NOTE: placeholder name (actually returns archiveExt)
	void setArchiveExt(string ext);	// NOTE: placeholder name
	bool addToSearchPath(string path, bool append);
	bool addArchive(string path, bool append);
	bool archiveIsValid(string path, bool append);	// NOTE: placeholder name
	bool exists(string path);	// NOTE: placeholder name
	void getFileList(string dir, vector<string> *files, string ext, bool includeDirectories);	// NOTE: placeholder name
	void getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext);	// NOTE: placeholder name
};

PhysfsWrapper::PhysfsWrapper()
	: archiveExt	(gameString_cf11ac)
{
}

string PhysfsWrapper::init(int argc, char *argv[], string organization, string appName)
{
	string error;
	PHYSFS_init(argc ? argv[0] : NULL);
	bool customPathSet = false;
	for (int i = 0; i < argc; i++)
	{
		string arg(argv[i]);
		if (arg == "-nonportable" && !customPathSet)
		{
			if (!PHYSFS_setSaneConfig(organization.c_str(),appName.c_str(),NULL,0,0))
			{
				error = "PHYSFS_setSaneConfig() failed: " + string(PHYSFS_getLastError());
				return error;
			}
			CUSTOM_FILE_PATH = PHYSFS_getWriteDir();
			CUSTOM_FILE_PATH += "/";
			customPathSet = true;
		}
		else if (arg.find("-customFilePath:") != string::npos && !customPathSet)
		{
			size_t pos = arg.find(':');
			CUSTOM_FILE_PATH.assign(arg.begin() + pos + 1,arg.end());
			if (CUSTOM_FILE_PATH.back() != '/' && CUSTOM_FILE_PATH.back() != '\\')
				CUSTOM_FILE_PATH += "/";
			if (!PHYSFS_addToSearchPath(CUSTOM_FILE_PATH.c_str(),1))
			{
				error = "PHYSFS_addToSearchPath() failed to add CUSTOM_FILE_PATH search path \"" + CUSTOM_FILE_PATH + "\", " + string(PHYSFS_getLastError());
				return error;
			}
			customPathSet = true;
		}
		if (arg.find("-basedir:") != string::npos)
		{
			size_t pos = arg.find(':');
			baseDir.assign(arg.begin() + pos + 1,arg.end());
		}
		if (arg.find("-ext:") != string::npos)
		{
			size_t pos = arg.find(':');
			archiveExt.assign(arg.begin() + pos + 1,arg.end());
			archiveExt.insert(0,".");
		}
	}

	if (baseDir.empty())
		baseDir = PHYSFS_getBaseDir();
	if (!PHYSFS_addToSearchPath(baseDir.c_str(),1))
	{
		error = "PHYSFS_addToSearchPath() failed to add base directory search path \"" + baseDir + "\", " + string(PHYSFS_getLastError());
		return error;
	}
	if (baseDir.back() != '/')
		baseDir += "/";

	return error;
}

string PhysfsWrapper::getBaseDir()
{
	return archiveExt;
}

void PhysfsWrapper::setArchiveExt(string ext)
{
	archiveExt = ext;
}

bool PhysfsWrapper::addToSearchPath(string path, bool append)
{
	if (append)
		path.insert(0,baseDir);
	return PHYSFS_addToSearchPath(path.c_str(),1);
}

bool PhysfsWrapper::addArchive(string path, bool append)
{
	if (append)
		path.insert(0,baseDir);
	path += archiveExt;
	return PHYSFS_addToSearchPath(path.c_str(),1);
}

bool PhysfsWrapper::archiveIsValid(string path, bool append)
{
	if (append)
		path.insert(0,baseDir);
	path += archiveExt;
	if (PHYSFS_addToSearchPath(path.c_str(),1))
	{
		PHYSFS_removeFromSearchPath(path.c_str());
		return true;
	}
	else
		return false;
}

bool PhysfsWrapper::exists(string path)
{
	return PHYSFS_exists(path.c_str());
}

void PhysfsWrapper::getFileList(string dir, vector<string> *files, string ext, bool includeDirectories)
{
	bool checkExt = !ext.empty();
	if (checkExt)
		ext = "." + ext;
	const char *extC = ext.c_str();
	char **rc = PHYSFS_enumerateFiles(dir.c_str());
	for (char **i = rc; *i != NULL; i++)
	{
		string file(*i);
		bool add = !checkExt ||
			(file.find(ext) != string::npos && file.size() > ext.size() && string(file.begin() + (file.size() - ext.size()),file.end()) == ext) ||
			(includeDirectories && PHYSFS_isDirectory((dir + "/" + file).c_str()));
		if (add)
			files->push_back(*i);
	}
	PHYSFS_freeList(rc);
}

void PhysfsWrapper::getFileTree(string dir, vector<PhysfsDirectory*> *directories, string ext)
{
	vector<string> files;
	getFileList(dir,&files,ext,true);
	directories->push_back(new PhysfsDirectory(dir));
	PhysfsDirectory *directory = directories->back();
	for (unsigned int i = 0; i < files.size(); i++)
	{
		if (PHYSFS_isDirectory((dir + "/" + files[i]).c_str()))
			getFileTree(dir + "/" + files[i],&directory->subdirectories,ext);
		else
			directory->files.push_back(files[i]);
	}
}
