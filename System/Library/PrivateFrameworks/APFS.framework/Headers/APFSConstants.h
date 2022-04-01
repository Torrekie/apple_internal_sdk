#ifndef _APFSCONSTANTS_H_
#define _APFSCONSTANTS_H_

#import <CoreFoundation/CoreFoundation.h>

#define apple_apfs 0x1200

#define APFS_BUNDLE_ID "com.apple.filesystems.apfs"

#define APFS_VOL_ROLE_DATA 64

#define EDT_OS_ENV_MAIN 1
#define EDT_OS_ENV_OTHER 2
#define EDT_OS_ENV_DIAGS 3

#define EDTVolumeFSType			"apfs"
#define EDTVolumePropertySize		(2 << 4)
#define EDTVolumePropertyMaxSize	(2 << 7) // Guessed

#define kEDTFilesystemEntry "IODeviceTree:/filesystems/fstab"
#define kEDTOSEnvironment CFSTR("os_env_type")
/*
kAPFSContainerBlocksizeKey
kAPFSContainerExtentAddressKey
kAPFSContainerExtentLengthKey
kAPFSContainerExtentsListKey
kAPFSContainerFSTypeKey
kAPFSContainerSizeKey
kAPFSContainerTidemarkKey
kAPFSStreamCreateEmbedCRC
kAPFSStreamCreateReadAlignment
kAPFSVolumeCaseSensitiveKey
kAPFSVolumeEffaceableKey
kAPFSVolumeEncryptedACMKey
kAPFSVolumeEncryptedKey
kAPFSVolumeFSIndexKey
kAPFSVolumeGroupSiblingFSIndexKey
kAPFSVolumeNameKey
kAPFSVolumeNoAutomountAtCreateKey
kAPFSVolumeQuotaSizeKey
kAPFSVolumeReserveSizeKey
kAPFSVolumeRoleKey
*/

#endif
