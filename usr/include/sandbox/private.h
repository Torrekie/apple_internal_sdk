#ifndef _SANDBOX_PRIVATE_H_
#define _SANDBOX_PRIVATE_H_

#include <sandbox.h>

__BEGIN_DECLS


/* The following flags are reserved for Mac OS X.  Developers should not
 * depend on their availability.
 */

/*
 * @define SANDBOX_NAMED_BUILTIN   The `profile' argument specifies the
 * name of a builtin profile that is statically compiled into the
 * system.
 */
#define SANDBOX_NAMED_BUILTIN	0x0002

/*
 * @define SANDBOX_NAMED_EXTERNAL   The `profile' argument specifies the
 * pathname of a Sandbox profile.  The pathname may be abbreviated: If
 * the name does not start with a `/' it is treated as relative to
 * /usr/share/sandbox and a `.sb' suffix is appended.
 */
#define SANDBOX_NAMED_EXTERNAL	0x0003

/*
 * @define SANDBOX_NAMED_MASK   Mask for name types: 4 bits, 15 possible
 * name types, 3 currently defined.
 */
#define SANDBOX_NAMED_MASK	0x000f

enum sandbox_filter_type {
	SANDBOX_FILTER_NONE,
	SANDBOX_FILTER_PATH,
	SANDBOX_FILTER_GLOBAL_NAME,
	SANDBOX_FILTER_LOCAL_NAME,
	SANDBOX_FILTER_APPLEEVENT_DESTINATION,
	SANDBOX_FILTER_RIGHT_NAME,
	SANDBOX_FILTER_PREFERENCE_DOMAIN,
	SANDBOX_FILTER_KEXT_BUNDLE_ID,
	SANDBOX_FILTER_INFO_TYPE,
	SANDBOX_FILTER_NOTIFICATION,
	// SANDBOX_FILTER_IPC?
	// ?
	SANDBOX_FILTER_XPC_SERVICE_NAME = 12,
	SANDBOX_FILTER_IOKIT_CONNECTION,
};

enum sandbox_extension_flags {
	FS_EXT_DEFAULTS =              0,
	FS_EXT_FOR_PATH =       (1 << 0),
	FS_EXT_FOR_FILE =       (1 << 1),
	FS_EXT_READ =           (1 << 2),
	FS_EXT_WRITE =          (1 << 3),
	FS_EXT_PREFER_FILEID =  (1 << 4),
};

typedef struct {
    char* builtin;
    unsigned char* data;
    size_t size;
} *sandbox_profile_t;

typedef struct {
    const char **params;
    size_t size;
    size_t available;
} *sandbox_params_t;

extern const char * APP_SANDBOX_IOKIT_CLIENT;
extern const char * APP_SANDBOX_MACH;
extern const char * APP_SANDBOX_READ;
extern const char * APP_SANDBOX_READ_WRITE;

extern const char * IOS_SANDBOX_APPLICATION_GROUP;
extern const char * IOS_SANDBOX_CONTAINER;

extern const enum sandbox_filter_type SANDBOX_CHECK_ALLOW_APPROVAL;
extern const enum sandbox_filter_type SANDBOX_CHECK_CANONICAL;
extern const enum sandbox_filter_type SANDBOX_CHECK_NOFOLLOW;
extern const enum sandbox_filter_type SANDBOX_CHECK_NO_APPROVAL;
extern const enum sandbox_filter_type SANDBOX_CHECK_NO_REPORT;

extern const uint32_t SANDBOX_EXTENSION_CANONICAL;
extern const uint32_t SANDBOX_EXTENSION_DEFAULT;
extern const uint32_t SANDBOX_EXTENSION_MAGIC;
extern const uint32_t SANDBOX_EXTENSION_NOFOLLOW;
extern const uint32_t SANDBOX_EXTENSION_NO_REPORT;
extern const uint32_t SANDBOX_EXTENSION_NO_STORAGE_CLASS;
extern const uint32_t SANDBOX_EXTENSION_PREFIXMATCH;
extern const uint32_t SANDBOX_EXTENSION_UNRESOLVED;

int sandbox_apply(sandbox_profile_t);

int sandbox_check(pid_t, const char *operation, enum sandbox_filter_type, ...);
int sandbox_check_by_audit_token(audit_token_t, const char *operation, enum sandbox_filter_type, ...);

sandbox_profile_t sandbox_compile_file(const char *path, sandbox_params_t, char **error);
sandbox_profile_t sandbox_compile_string(const char *data, sandbox_params_t, char **error);

int sandbox_consume_extension(const char *path, const char *ext_token);
int sandbox_consume_fs_extension(const char *ext_token, char **path);
int sandbox_consume_mach_extension(const char *ext_token, char **name);

int sandbox_container_path_for_pid(pid_t, char *buffer, size_t bufsize);

sandbox_params_t sandbox_create_params(void);

void sandbox_free_params(sandbox_params_t);
void sandbox_free_profile(sandbox_profile_t);

int64_t sandbox_extension_consume(const char *extension_token);
char *sandbox_extension_issue_file(const char *extension_class, const char *path, uint32_t flags);
char *sandbox_extension_issue_file_to_process(const char *extension_class, const char *path, uint32_t flags, audit_token_t);
char *sandbox_extension_issue_generic(const char *extension_class, uint32_t flags);
char *sandbox_extension_issue_iokit_registry_entry_class_to_process(const char *extension_class, const char *registry_entry_class, uint32_t flags, audit_token_t);
char *sandbox_extension_issue_iokit_registry_entry_class(const char *extension_class, const char *registry_entry_class, uint32_t flags);
char *sandbox_extension_issue_mach_to_process(const char *extension_class, const char *name, uint32_t flags, audit_token_t);
char *sandbox_extension_issue_mach(const char *extension_class, const char *name, uint32_t flags);
int sandbox_extension_release(int64_t extension_handle);

int sandbox_init_with_parameters(const char *profile, uint64_t flags, const char *const parameters[], char **errorbuf);
int sandbox_init_with_extensions(const char *profile, uint64_t flags, const char *const extensions[], char **errorbuf);

int sandbox_issue_extension(const char *path, char **ext_token);
int sandbox_issue_fs_extension(const char *path, uint64_t flags, char **ext_token);
int sandbox_issue_fs_rw_extension(const char *path, char **ext_token);
int sandbox_issue_mach_extension(const char *name, char **ext_token);

int sandbox_note(const char *note);

int sandbox_release_fs_extension(const char *ext_token);

int sandbox_set_param(sandbox_params_t, const char *key, const char *value);

int sandbox_suspend(pid_t pid);

int sandbox_unsuspend(void);

int sandbox_wakeup_daemon(char **errorbuf);

const char *_amkrtemp(const char *);

__END_DECLS

#endif /* _SANDBOX_H_ */
