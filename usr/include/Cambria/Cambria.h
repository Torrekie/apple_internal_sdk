#ifndef _CAMBRIA_CAMBRIA_H_
#define _CAMBRIA_CAMBRIA_H_

#include <stdbool.h>
#include <mach/host_info.h>
//#include <machine/thread_status.h>
//#include <arm/cpu_x86_64_capabilities.h>

__BEGIN_DECLS

/* liboah */

cpu_type_t
oah_get_preferred_architecture_from_architectures(struct host_preferred_user_arch *user_arch, void *msg);

int
oah_get_rflags(int, int);

const char *
oah_get_runtime_location(void);

int
oah_get_runtime_version(void);

/*
int
oah_get_x86_thread_state(vm_map_t, x86_64_commpage_t, x86_saved_state64_t); // Not sure
*/

int
oah_invalidate_translation(void);

bool
oah_is_current_process_translated(void);

bool
oah_is_process_translated(pid_t pid);

bool
oah_is_translation_available(void);

void
oah_thread_create_running(void);

int
objc_thread_get_rip(thread_act_t, uint64_t *);

/* libRosetta */

int64_t
rosetta_convert_to_rosetta_absolute_time(int);

int64_t
rosetta_convert_to_system_absolute_time(int);

uint64_t
rosetta_get_expected_version(void);

cpu_type_t
rosetta_get_preferred_architecture_from_architectures(struct host_preferred_user_arch *user_arch, void *msg);

int
rosetta_get_rflags(int, int);

const char *
rosetta_get_runtime_location(void);

int
rosetta_get_runtime_version(void);

//rosetta_get_x86_thread_state

bool
rosetta_has_been_previously_installed(void);

bool
rosetta_has_been_previously_installed_on_volume(const char *volume);

int
rosetta_invalidate_translation(void);

bool
rosetta_is_current_process_translated(void);

bool
rosetta_is_process_translated(pid_t pid);

bool
rosetta_is_translation_available(void);

bool
rosetta_is_translation_available_on_volume(const char *volume);

void
rosetta_thread_create_running(void);

int
rosetta_thread_get_rip(thread_act_t, uint64_t *);

//rosetta_thread_get_state

//rosetta_translate_binaries

__END_DECLS

#endif
