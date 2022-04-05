#ifndef _SANDBOX_ROOTLESS_H_
#define _SANDBOX_ROOTLESS_H_

#include <os/base.h>
#include <stdbool.h>
#include <sys/types.h>

__BEGIN_DECLS

int rootless_allows_task_for_pid(pid_t pid);

int rootless_apply(char * const *path_argv, const char *path);

int rootless_restricted_environment();

bool rootless_check_datavault_flag(const char *path, const char *storage_class);
bool rootless_check_restricted_flag(const char *path, const char *storage_class);
bool rootless_check_trusted(const char *path);
bool rootless_check_trusted_class(const char *path, const char *storage_class);
bool rootless_check_trusted_fd(int fd);

int rootless_convert_to_datavault(char * const *path_argv);

int rootless_mkdir_datavault(const char *path, mode_t mode, const char *storage_class);
int rootless_mkdir_nounlink(const char *path, mode_t mode, const char *storage_class);
int rootless_mkdir_restricted(const char *path, mode_t mode, const char *storage_class);

bool rootless_protected_volume(const char *path);

int rootless_restricted_environment(void);

int rootless_suspend(void);

__END_DECLS

#endif
