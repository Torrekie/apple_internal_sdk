#ifndef _APFS_SYSCTL_H_
#define _APFS_SYSCTL_H_

#define APFS_FSTAB_SYSCTL "vfs.generic.apfs.edt_fstab"

struct edt_fstab {
	uint8_t stub[232];
} edt_fstab;

#endif
