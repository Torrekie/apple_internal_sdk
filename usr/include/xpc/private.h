// modified from WTF/wtf/spi/darwin/XPCSPI.h
#ifndef __XPC_PRIVATE_H__
#define __XPC_PRIVATE_H__

#include <dispatch/dispatch.h>
#include <os/object.h>
#include <xpc/xpc.h>

#define XPC_ENV_SANDBOX_CONTAINER_ID "APP_SANDBOX_CONTAINER_ID"

enum {
    DISPATCH_MACH_SEND_POSSIBLE = 0x8,
};

#if !defined(XPC_NOESCAPE)
#define XPC_NOESCAPE
#endif

typedef struct {
	char *stream;
	uint64_t token;
} xpc_event_publisher_t;

typedef int xpc_event_publisher_action_t;

__BEGIN_DECLS

void xpc_transaction_exit_clean(void);
void xpc_track_activity(void);

xpc_object_t xpc_connection_copy_entitlement_value(xpc_connection_t connection, const char *entitlement);
void xpc_connection_get_audit_token(xpc_connection_t, audit_token_t*);
void xpc_connection_kill(xpc_connection_t, int);
void xpc_connection_set_instance(xpc_connection_t, uuid_t);
void xpc_connection_set_target_uid(xpc_connection_t connection, uid_t uid);
mach_port_t xpc_dictionary_copy_mach_send(xpc_object_t, const char*);
void xpc_dictionary_set_mach_send(xpc_object_t, const char*, mach_port_t);

void xpc_connection_set_bootstrap(xpc_connection_t, xpc_object_t);
xpc_object_t xpc_copy_bootstrap();
xpc_object_t xpc_copy_entitlement_for_token(const char*, audit_token_t*);
void xpc_connection_set_oneshot_instance(xpc_connection_t, uuid_t instance);

int _xpc_runtime_is_app_sandboxed();

xpc_object_t xpc_create_from_plist(void *data, size_t size);

int xpc_get_event_name(xpc_event_publisher_t, char *);
xpc_event_publisher_t xpc_event_publisher_create(const char*, dispatch_queue_t);
int xpc_event_publisher_fire(xpc_event_publisher_t, uint64_t, int);
int xpc_event_publisher_fire_noboost(xpc_event_publisher_t, uint64_t, xpc_object_t);
void xpc_event_publisher_set_handler(xpc_event_publisher_t, void (^)(xpc_event_publisher_action_t action, uint64_t event_token, xpc_object_t descriptor));
void xpc_event_publisher_set_error_handler(xpc_event_publisher_t, void (^)(int));
__END_DECLS

#endif
