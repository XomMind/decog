// physfsrwops.c (Ryan C. Gordon, zlib license) -- PhysicsFS <-> SDL 1.2 RWops glue,
// compiled into Cogmind as C++ (PHYSFSRWOPS_makeRWops is called with C++ linkage).
#include <stdio.h>
#include "thirdparty/physfs.h"

#ifndef SEEK_SET
#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2
#endif

struct SDL_RWops
{
	int (__cdecl *seek)(struct SDL_RWops *context, int offset, int whence);
	int (__cdecl *read)(struct SDL_RWops *context, void *ptr, int size, int maxnum);
	int (__cdecl *write)(struct SDL_RWops *context, const void *ptr, int size, int num);
	int (__cdecl *close)(struct SDL_RWops *context);
	unsigned int type;
	union
	{
		struct
		{
			void *data1;
		} unknown;
	} hidden;
};

extern "C" void __cdecl SDL_SetError(const char *fmt, ...);
extern "C" SDL_RWops * __cdecl SDL_AllocRW(void);
extern "C" void __cdecl SDL_FreeRW(SDL_RWops *area);

static int physfsrwops_seek(SDL_RWops *rw, int offset, int whence)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;
	int pos = 0;

	if (whence == SEEK_SET)
	{
		pos = offset;
	} /* if */

	else if (whence == SEEK_CUR)
	{
		PHYSFS_sint64 current = PHYSFS_tell(handle);
		if (current == -1)
		{
			SDL_SetError("Can't find position in file: %s",
						  PHYSFS_getLastError());
			return(-1);
		} /* if */

		pos = (int) current;
		if ( ((PHYSFS_sint64) pos) != current )
		{
			SDL_SetError("Can't fit current file position in an int!");
			return(-1);
		} /* if */

		if (offset == 0)  /* this is a "tell" call. We're done. */
			return(pos);

		pos += offset;
	} /* else if */

	else if (whence == SEEK_END)
	{
		PHYSFS_sint64 len = PHYSFS_fileLength(handle);
		if (len == -1)
		{
			SDL_SetError("Can't find end of file: %s", PHYSFS_getLastError());
			return(-1);
		} /* if */

		pos = (int) len;
		if ( ((PHYSFS_sint64) pos) != len )
		{
			SDL_SetError("Can't fit end-of-file position in an int!");
			return(-1);
		} /* if */

		pos += offset;
	} /* else if */

	else
	{
		SDL_SetError("Invalid 'whence' parameter.");
		return(-1);
	} /* else */

	if ( pos < 0 )
	{
		SDL_SetError("Attempt to seek past start of file.");
		return(-1);
	} /* if */

	if (!PHYSFS_seek(handle, (PHYSFS_uint64) pos))
	{
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
		return(-1);
	} /* if */

	return(pos);
} /* physfsrwops_seek */


static int physfsrwops_read(SDL_RWops *rw, void *ptr, int size, int maxnum)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;
	PHYSFS_sint64 rc = PHYSFS_read(handle, ptr, size, maxnum);
	if (rc != maxnum)
	{
		if (!PHYSFS_eof(handle)) /* not EOF? Must be an error. */
			SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
	} /* if */

	return((int) rc);
} /* physfsrwops_read */


static int physfsrwops_write(SDL_RWops *rw, const void *ptr, int size, int num)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;
	PHYSFS_sint64 rc = PHYSFS_write(handle, ptr, size, num);
	if (rc != num)
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());

	return((int) rc);
} /* physfsrwops_write */


static int physfsrwops_close(SDL_RWops *rw)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;
	if (!PHYSFS_close(handle))
	{
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
		return(-1);
	} /* if */

	SDL_FreeRW(rw);
	return(0);
} /* physfsrwops_close */


static SDL_RWops *create_rwops(PHYSFS_File *handle)
{
	SDL_RWops *retval = NULL;

	if (handle == NULL)
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
	else
	{
		retval = SDL_AllocRW();
		if (retval != NULL)
		{
			retval->seek  = physfsrwops_seek;
			retval->read  = physfsrwops_read;
			retval->write = physfsrwops_write;
			retval->close = physfsrwops_close;
			retval->hidden.unknown.data1 = handle;
		} /* if */
	} /* else */

	return(retval);
} /* create_rwops */


SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_File *handle)
{
	SDL_RWops *retval = NULL;
	if (handle == NULL)
		SDL_SetError("NULL pointer passed to PHYSFSRWOPS_makeRWops().");
	else
		retval = create_rwops(handle);

	return(retval);
} /* PHYSFSRWOPS_makeRWops */


SDL_RWops *PHYSFSRWOPS_openRead(const char *fname)
{
	return(create_rwops(PHYSFS_openRead(fname)));
} /* PHYSFSRWOPS_openRead */


SDL_RWops *PHYSFSRWOPS_openWrite(const char *fname)
{
	return(create_rwops(PHYSFS_openWrite(fname)));
} /* PHYSFSRWOPS_openWrite */


SDL_RWops *PHYSFSRWOPS_openAppend(const char *fname)
{
	return(create_rwops(PHYSFS_openAppend(fname)));
} /* PHYSFSRWOPS_openAppend */
