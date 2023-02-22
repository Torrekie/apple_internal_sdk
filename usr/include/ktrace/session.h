#ifndef _KTRACE_SESSION_H_
#define _KTRACE_SESSION_H_

#include <inttypes.h>
#include <os/base.h>
#include <sys/types.h>
#include <sys/cdefs.h>
#include <sys/kdebug.h>
#include <dispatch/dispatch.h>

// Possibly missing arg5 or somesort
struct trace_point {
	uint64_t timestamp;
	uint64_t arg1;
	uint64_t arg2;
	uint64_t arg3;
	uint64_t arg4;
	uint64_t threadid;
	int debugid;
	struct timeval walltime;
	char *command;
	char *debugname;
	int cpuid;
};
typedef struct trace_point *ktrace_event_t;

typedef int *ktrace_session_t;

__BEGIN_DECLS

// Not full ktrace.framework APIs

ktrace_session_t ktrace_session_create(void);
ktrace_session_t ktrace_session_destroy(ktrace_session_t s);
int ktrace_end(ktrace_session_t s, int mode);
int ktrace_start(ktrace_session_t s, dispatch_queue_main_t queue);
int ktrace_filter_process(ktrace_session_t s, const char *name);
int ktrace_filter_pid(ktrace_session_t s, pid_t pid);
int ktrace_exclude_process(ktrace_session_t s, const char *name);
int ktrace_exclude_pid(ktrace_session_t s, pid_t pid);
int ktrace_set_file(ktrace_session_t s, const char *name);
int ktrace_set_completion_handler(ktrace_session_t s, void (^)(void));
int ktrace_set_dropped_events_handler(ktrace_session_t s, void (^)(void));
int ktrace_convert_timestamp_to_nanoseconds(ktrace_session_t s, int64_t mach_time, uint64_t *nanoseconds);
int ktrace_ignore_process_filter_for_event(ktrace_session_t s, int diskio_mode);
int ktrace_set_thread_exit_handler(ktrace_session_t s, void (^)(uint64_t, const char*));
void ktrace_set_signal_handler(ktrace_session_t s);
void ktrace_set_default_event_names_enabled(int mode);
void ktrace_set_execnames_enabled(ktrace_session_t s, int mode);
void ktrace_set_uuid_map_enabled(ktrace_session_t s, int mode);
void ktrace_set_vnode_paths_enabled(ktrace_session_t s, int mode);
void ktrace_events_range(ktrace_session_t s, int eventid, int compareid, void (^)(ktrace_event_t));
void ktrace_events_single(ktrace_session_t s, int eventid, void (^)(ktrace_event_t));
void ktrace_session_set_default_event_names_enabled(ktrace_session_t s, int mode);
const char *ktrace_get_execname_for_thread(ktrace_session_t s, int64_t threadid);
const char *ktrace_get_path_for_vp(ktrace_session_t s, int64_t threadid); // In doubt, return might be void* / CFDictionaryRef
pid_t ktrace_get_pid_for_thread(ktrace_session_t s, int64_t threadid);

__END_DECLS

#define KTRACE_FEATURE_LAZY 2
#define KTRACE_FEATURE_ENABLED 1
#define KTRACE_FEATURE_DISABLED 0
#define ktrace_events_subclass(s, dbg_class, dbg_subclass, block) \
	ktrace_events_range(s, (dbg_class << KDBG_CLASS_OFFSET | dbg_subclass << KDBG_SUBCLASS_OFFSET), \
	(dbg_class << KDBG_CLASS_OFFSET | (dbg_subclass + 0x01) << KDBG_SUBCLASS_OFFSET), \
	block)

#endif
