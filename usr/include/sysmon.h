#ifndef _SYSMON_H
#define _SYSMON_H

#include <xpc/xpc.h>

typedef struct _sysmon_request *sysmon_request_t;
typedef struct _sysmon_row *sysmon_row_t;
typedef struct _sysmon_table *sysmon_table_t;

enum sysmon_attr {
//	0,
	SYSMON_ATTR_PROC_FLAGS		= 1,
//	2,
//	3,
	SYSMON_ATTR_PROC_PID		= 4,
	SYSMON_ATTR_PROC_PPID,
	SYSMON_ATTR_PROC_UID,
//	7,
	SYSMON_ATTR_PROC_RUID		= 8,
	SYSMON_ATTR_PROC_RGID,
//	10,
//	11,
	SYSMON_ATTR_PROC_COMM		= 12,
//	13,
//	14,
	SYSMON_ATTR_PROC_PGID		= 15,
//	16,
	SYSMON_ATTR_PROC_TDEV		= 17,
//	18,
//	19,
	SYSMON_ATTR_PROC_START		= 20,
//	...
	SYSMON_ATTR_PROC_ARGUMENTS	= 44
};

#define SYSMON_REQUEST_TYPE_PROCESS	1

#ifdef __cplusplus
extern "C" {
#endif

extern const char* SYSMON_XPC_SERVICE_NAME;

extern const char* SYSMON_XPC_KEY_ATTRIBUTES;
extern const char* SYSMON_XPC_KEY_FLAGS;
extern const char* SYSMON_XPC_KEY_TYPE;

extern const char* SYSMON_XPC_REPLY_KEY_HEADER;
extern const char* SYSMON_XPC_REPLY_KEY_TABLE;
extern const char* SYSMON_XPC_REPLY_KEY_TIMESTAMP;

// _os_object_t sysmon_request_alloc();
void sysmon_request_add_attribute(sysmon_request_t request, const int attr);
void sysmon_request_add_attributes(sysmon_request_t request, ...);
void sysmon_request_cancel(sysmon_request_t request);
sysmon_request_t sysmon_request_create(const int type, void (^)(sysmon_table_t table));
sysmon_request_t sysmon_request_create_with_error(const int type, void (^)(sysmon_table_t table, const char *error_str));
void sysmon_request_execute(sysmon_request_t request);
sysmon_request_t sysmon_request_set_flags(sysmon_request_t request, const int attr);
sysmon_request_t sysmon_request_set_interval(sysmon_request_t request, const int attr);

sysmon_table_t sysmon_retain(sysmon_table_t table); // return _os_object_retain which should be void
void sysmon_release(sysmon_request_t request);

// _os_object_t sysmon_row_alloc();
// sysmon_row_apply
xpc_object_t sysmon_row_get_value(sysmon_row_t row, const int attr);

// _os_object_t sysmon_table_alloc();
// sysmon_table_apply
// sysmon_table_t system_table_copy_row
int sysmon_table_get_count(sysmon_table_t table);
sysmon_row_t sysmon_table_get_row(sysmon_table_t table, int num);
int sysmon_table_get_timestamp(sysmon_table_t table);

#ifdef __cplusplus
}
#endif

#endif
