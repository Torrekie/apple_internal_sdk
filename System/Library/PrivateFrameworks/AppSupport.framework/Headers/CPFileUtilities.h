#ifndef _APPSUPPORT_CPFILEUTILITIES_H
#define _APPSUPPORT_CPFILEUTILITIES_H

#include <CoreFoundation/CoreFoundation.h>

__BEGIN_DECLS

// Get basename of a path, write out to a buffer with specific size
void CPBasename(const char *path, char *outBuf, CFIndex bufLen);

// Same as unlink()
bool CPDeleteFile(const char *path);

// Delete a filetree, when secure, CPSecureDeleteFile() is called
bool CPDeleteTree(const char *path, int secure);

bool CPFileBuildDirectoriesToPath(CFStringRef file, mode_t mode);

// Wrapper of zlib deflateInit2()
int CPFileCompressionZDeflate(FILE *in, FILE *out, int level);

// Returns an open file‑descriptor for a new temp file in the same directory
// as `path`, with name “.<basename>.XXXXXX”.  The actual filename is
// written into `outBuf` (size `bufLen`).  Caller must close(fd) when done.
int CPOpenTemporaryFile(const char *path, char *outBuf, size_t bufLen);

bool CPSecureDeleteFile(const char *path);

// Just "/"
CFStringRef CPSystemRootDirectory(void);

// Wrapper of NSTemporaryDirectory() + CPOpenTemporaryFile()
CFURLRef CPTemporaryFileWithUniqueName(const char *path, int *ret);

// Create a useable tmp path by NSTemporaryDirectory() + path, if buf is
// NULL, only NSLogs will be generated
void CPTemporaryPath(const char *path, char *buf, size_t bufLen);

__END_DECLS

#endif
