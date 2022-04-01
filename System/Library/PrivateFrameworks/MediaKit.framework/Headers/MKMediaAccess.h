#ifndef __MEDIAKIT_MKMEDIAACCESS_H__
#define __MEDIAKIT_MKMEDIAACCESS_H__

#include <CoreFoundation/CoreFoundation.h>

#import <MediaKit/MKMedia.h>

CFMutableDictionaryRef MKCFCreateMedia(CFMutableArrayRef*, MKStatus*);
MKStatus MKCFWriteMedia(CFMutableDictionaryRef, CFMutableDictionaryRef, int, void *, MKMediaRef);
void MKCFDisposeMedia(CFMutableDictionaryRef);

#endif
