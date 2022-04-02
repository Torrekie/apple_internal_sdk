#ifndef _APFS_FSCTL_H_
#define _APFS_FSCTL_H_

struct xdstream_obj_id {
	char *xdi_name;
	int xdi_xdtream_obj_id;
};

#define APFS_NAME_MAX_BYTES (255*3)

typedef struct {
	char synth_link_name[APFS_NAME_MAX_BYTES];
	char synth_target_path[MAXPATHLEN];
} apfs_create_synth_symlink_t;

#define APFSIOC_FIRMLINK_CTL	0xc4084a3c
#define APFSIOC_XDSTREAM_OBJ_ID	0xc0104a35

#define APFSIOC_CREATE_SYNTHETIC_SYMLINK _IOW('J', 75, apfs_create_synth_symlink_t)
#define APFSIOC_CREATE_HIDDEN_SYNTHETIC_SYMLINK _IOW('J', 78, apfs_create_synth_symlink_t)

#endif
