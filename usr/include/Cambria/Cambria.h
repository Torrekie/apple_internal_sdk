#ifndef _CAMBRIA_CAMBRIA_H_
#define _CAMBRIA_CAMBRIA_H_

#include <stdbool.h>
#include <mach/host_info.h>
#include <Availability.h>
//#include <machine/thread_status.h>
//#include <arm/cpu_x86_64_capabilities.h>

__BEGIN_DECLS

/* liboah */

cpu_type_t
oah_get_preferred_architecture_from_architectures(struct host_preferred_user_arch *user_arch, void *msg) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
oah_get_rflags(int, int) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

const char *
oah_get_runtime_location(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
oah_get_runtime_version(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

/*
int
oah_get_x86_thread_state(vm_map_t, x86_64_commpage_t, x86_saved_state64_t) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA); // Not sure
*/

int
oah_invalidate_translation(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
oah_is_current_process_translated(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
oah_is_process_translated(pid_t pid) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
oah_is_translation_available(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

void
oah_thread_create_running(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
objc_thread_get_rip(thread_act_t, uint64_t *) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

/* libRosetta */

int64_t
rosetta_convert_to_rosetta_absolute_time(int) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int64_t
rosetta_convert_to_system_absolute_time(int) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

uint64_t
rosetta_get_expected_version(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

cpu_type_t
rosetta_get_preferred_architecture_from_architectures(struct host_preferred_user_arch *user_arch, void *msg) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
rosetta_get_rflags(int, int) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

const char *
rosetta_get_runtime_location(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
rosetta_get_runtime_version(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

//rosetta_get_x86_thread_state

bool
rosetta_has_been_previously_installed(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
rosetta_has_been_previously_installed_on_volume(const char *volume) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
rosetta_invalidate_translation(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
rosetta_is_current_process_translated(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
rosetta_is_process_translated(pid_t pid) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
rosetta_is_translation_available(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

bool
rosetta_is_translation_available_on_volume(const char *volume) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

void
rosetta_thread_create_running(void) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

int
rosetta_thread_get_rip(thread_act_t, uint64_t *) __API_UNAVAILABLE(ios, tvos, watchos) __OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_NA);

//rosetta_thread_get_state

//rosetta_translate_binaries

__END_DECLS

#endif
