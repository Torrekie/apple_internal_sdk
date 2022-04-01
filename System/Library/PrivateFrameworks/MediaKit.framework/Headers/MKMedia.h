#ifndef __MEDIAKIT_MKMEDIA_H__
#define __MEDIAKIT_MKMEDIA_H__

#include <CoreFoundation/CoreFoundation.h>

#define MK_PARTITIONS_KEY "Partitions"

#define kMKMediaPropertyWritableKey CFSTR("Writable")

typedef int MKStatus;
typedef struct __MKMedia * MKMediaRef;

MKMediaRef MKMediaCreateWithPath(CFAllocatorRef alloc, const char *device, void *a, int32_t *i32);
CFDictionaryRef MKCFBuildPartition(int, int, CFStringRef, CFStringRef, int, int, MKStatus*, void*);
CFMutableDictionaryRef MKCFCreateMap(int, CFMutableArrayRef, CFMutableDictionaryRef, uint, uint, uint, uint, uint, MKMediaRef, MKStatus*);

#endif
