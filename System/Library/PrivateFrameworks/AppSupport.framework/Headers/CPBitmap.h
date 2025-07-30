#ifndef _APPSUPPORT_CPBITMAP_H
#define _APPSUPPORT_CPBITMAP_H

#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>

// For use with CPBitmapCreate
enum {
	kCPBitmapAlpha = 1,
	kCPBitmapRetain,
};

typedef enum {
	kCPBitmapFormat_RGBA,	// Guessed
	kCPBitmapFormat_RGB_CondAlpha, // Guessed
	kCPBitmapFormat_RGB565,	// Guessed
	kCPBitmapFormat_Gray,	// Guessed
	kCPBitmapFormatKTX_4x4,
	kCPBitmapFormat_GrayAlpha,	// Guessed
	kCPBitmapFormatATX_4x4_PreTwiddled,
	kCPBitmapFormatATX_4x4_AlphaOnly// Guessed
} CPBitmapFormat;

typedef const struct CF_BRIDGED_TYPE(id) __CPBitmapWriter * CPBitmapWriterRef;

__BEGIN_DECLS

CFDataRef CPBitmapCreateMappedDataFromPath(CFStringRef path, CFErrorRef *error);
CFArrayRef CPBitmapCreateImagesFromData(CFDataRef data, CFPropertyListRef *list, UInt8 flags, CFErrorRef *error);

// This is typically the combination of CPBitmapCreateMappedDataFromPath & CPBitmapCreateImagesFromData
CFArrayRef CPBitmapCreateImagesFromPath(CFStringRef path, CFPropertyListRef *list, UInt8 flags, CFErrorRef *error);


#pragma mark -- Writer

// Quick shortcut to CPBitmapWriterCreateWithPath + CPBitmapWriterAddImage + CPBitmapWriterFinalize
bool CPBitmapWriteImagesToPath(CFArrayRef images, CPBitmapFormat bitmapFormat, CFPropertyListRef list, CFStringRef path, bool retainColorSpace, CFErrorRef *error);

CFTypeID CPBitmapWriterGetTypeID(void);

CPBitmapWriterRef CPBitmapWriterCreate(CPBitmapFormat bitmapFormat, CFPropertyListRef list, CFStringRef path, bool retainColorSpace, CFErrorRef *error);
CPBitmapWriterRef CPBitmapWriterCreateWithFileDescriptor(int fd, CPBitmapFormat bitmapFormat, bool retainColorSpace, uint64_t count, CFPropertyListRef list, CFErrorRef *error);
CPBitmapWriterRef CPBitmapWriterCreateWithPath(CFStringRef path, CPBitmapFormat bitmapFormat, bool retainColorSpace, uint64_t count, CFPropertyListRef list, CFErrorRef *error);

bool CPBitmapWriterAddImage(CPBitmapWriterRef writer, CGImageRef img, CFErrorRef *error);

bool CPBitmapWriterFinalize(CPBitmapWriterRef writer, CFErrorRef *error);

__END_DECLS

#endif
