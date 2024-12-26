#ifndef _IOKIT_APPLEFDEKEYSTOREDEFS_H
#define _IOKIT_APPLEFDEKEYSTOREDEFS_H

#include <CoreFoundation/CoreFoundation.h>

#define kAppleFDEKeyStoreServiceName "AppleFDEKeyStore"

typedef CF_ENUM(UInt32, FDEAlgorithm)
{
	fDE_ALG_AESXTS = 2,
};

typedef struct createKeyGetUUID_InStruct
{
	UInt32 keySizeInBytes;
	FDEAlgorithm algorithm;
} createKeyGetUUID_InStruct_t;

typedef struct uuid_OutStruct
{
	uuid_t uuid;
} uuid_OutStruct_t;

typedef CF_ENUM(UInt8, FDEIndex)
{
	kAppleFDEKeyStoreUserClientOpen,
	kAppleFDEKeyStoreUserClientClose,

	kAppleFDEKeyStore_createKeyGetUUID = 27,
};

#define V1_KEYSIZE sizeof(uuid_OutStruct_t);

#endif
