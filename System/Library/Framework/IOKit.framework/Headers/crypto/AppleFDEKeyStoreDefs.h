#ifndef _IOKIT_APPLEFDEKEYSTOREDEFS_H
#define _IOKIT_APPLEFDEKEYSTOREDEFS_H

#include <CoreFoundation/CoreFoundation.h>

#define kAppleFDEKeyStoreServiceName "AppleFDEKeyStore"

typedef CF_ENUM(UInt32, FDEAlgorithm)
{
	fDE_ALG_AESXTS = 2,
};

typedef struct createKeyGetUUID
{
	UInt32 keySizeInBytes;
	FDEAlgorithm algorithm;
} createKeyGetUUID_InStruct_t;

typedef struct
{
	uuid_t uuid;
} uuid_OutStruct_t;

#define V1_KEYSIZE sizeof(uuid_OutStruct_t);

#define XTS_TWEAK_BYTES 16

typedef struct xtsEncrypt
{
	uint64_t bufferAddress;
	uint64_t bufferLength;
	uint8_t tweak[XTS_TWEAK_BYTES]; /* 16-bit little-endian bytes */
	uuid_t key_uuid;
} xtsEncrypt_InStruct_t;

typedef CF_ENUM(UInt8, FDEIndex)
{
	kAppleFDEKeyStoreUserClientOpen,
	kAppleFDEKeyStoreUserClientClose,

	kAppleFDEKeyStore_createKeyGetUUID	= 27,
	kAppleFDEKeyStore_xtsEncrypt		= 29,
};

#endif
