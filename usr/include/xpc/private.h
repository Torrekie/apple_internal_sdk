// modified from WTF/wtf/spi/darwin/XPCSPI.h
#ifndef __XPC_PRIVATE_H__
#define __XPC_PRIVATE_H__

#include <dispatch/dispatch.h>
#include <os/object.h>
#include <xpc/xpc.h>
#include <xpc/base.h>

#define XPC_ENV_SANDBOX_CONTAINER_ID "APP_SANDBOX_CONTAINER_ID"

#define XPC_PIPE_FLAG_PRIVILEGED (1 << 5)

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
typedef boolean_t (*xpc_pipe_mig_call_t)(mach_msg_header_t *request, mach_msg_header_t *reply);

XPC_ASSUME_NONNULL_BEGIN
__BEGIN_DECLS

#define XPC_TYPE_MACH_SEND (&_xpc_type_mach_send)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
XPC_EXPORT
XPC_TYPE(_xpc_type_mach_send);

#define XPC_TYPE_MACH_RECV (&_xpc_type_mach_recv)
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
XPC_EXPORT
XPC_TYPE(_xpc_type_mach_recv);

#define XPC_TYPE_POINTER (&_xpc_type_pointer)
__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT
XPC_TYPE(_xpc_type_pointer);

#define XPC_TYPE_PIPE (&_xpc_type_pipe)
__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT
XPC_TYPE(_xpc_type_pipe);
XPC_DECL(xpc_pipe);

XPC_EXPORT XPC_NONNULL_ALL
void
xpc_dictionary_get_audit_token(xpc_object_t xdict, audit_token_t *token);

XPC_EXPORT XPC_NONNULL_ALL
boolean_t
xpc_dictionary_expects_reply(xpc_object_t xdict);

__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
XPC_EXPORT XPC_MALLOC XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_object_t
xpc_mach_send_create(mach_port_t value);

XPC_EXPORT XPC_NONNULL_ALL
mach_port_t
xpc_mach_send_get_right(xpc_object_t xsend);

XPC_EXPORT XPC_NONNULL_ALL
mach_port_t
xpc_mach_send_copy_right(xpc_object_t xsend);

XPC_EXPORT XPC_NONNULL1 XPC_NONNULL2
void
xpc_dictionary_set_mach_send(xpc_object_t xdict, const char *key, mach_port_t value);

XPC_EXPORT XPC_NONNULL_ALL
mach_port_t
xpc_dictionary_copy_mach_send(xpc_object_t xdict, const char *key);

XPC_EXPORT XPC_NONNULL1
void
xpc_array_set_mach_send(xpc_object_t xarray, size_t index, mach_port_t value);

XPC_EXPORT XPC_NONNULL1
mach_port_t
xpc_array_copy_mach_send(xpc_object_t xarray, size_t index);

__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
XPC_EXPORT XPC_MALLOC XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_object_t
xpc_mach_recv_create(mach_port_t value);

XPC_EXPORT XPC_NONNULL_ALL
mach_port_t
xpc_mach_recv_extract_right(xpc_object_t xrecv);

XPC_EXPORT XPC_NONNULL1 XPC_NONNULL2
void
xpc_dictionary_set_mach_recv(xpc_object_t xdict, const char *key, mach_port_t value);

XPC_EXPORT XPC_NONNULL_ALL
mach_port_t
xpc_dictionary_extract_mach_recv(xpc_object_t xdict, const char *key);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_MALLOC XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_object_t
xpc_pointer_create(pointer_t value);

XPC_EXPORT
pointer_t
xpc_pointer_get_value(xpc_object_t xpointer);

XPC_EXPORT
void
xpc_dictionary_set_pointer(xpc_object_t xdict, const char *key, pointer_t value);

XPC_EXPORT
pointer_t
xpc_dictionary_get_pointer(xpc_object_t xdict, const char *key);

XPC_EXPORT
void
xpc_array_set_pointer(xpc_object_t xarray, size_t index, pointer_t value);

XPC_EXPORT
pointer_t
xpc_array_get_pointer(xpc_object_t xarray, size_t index);



void xpc_transaction_exit_clean(void);
void xpc_track_activity(void);

xpc_object_t xpc_connection_copy_entitlement_value(xpc_connection_t connection, const char *entitlement);
void xpc_connection_get_audit_token(xpc_connection_t, audit_token_t*);
void xpc_connection_kill(xpc_connection_t, int);
void xpc_connection_set_instance(xpc_connection_t, uuid_t);
void xpc_connection_set_target_uid(xpc_connection_t connection, uid_t uid);

void xpc_connection_set_bootstrap(xpc_connection_t, xpc_object_t);
xpc_object_t xpc_copy_bootstrap();
xpc_object_t xpc_copy_entitlement_for_token(const char*, audit_token_t*);
void xpc_connection_set_oneshot_instance(xpc_connection_t, uuid_t instance);

int _xpc_runtime_is_app_sandboxed();

xpc_object_t xpc_create_from_plist(void *data, size_t size);
xpc_object_t xpc_create_reply_with_format(xpc_object_t original, const char * format, ...);

int xpc_get_event_name(xpc_event_publisher_t, char *);
xpc_event_publisher_t xpc_event_publisher_create(const char*, dispatch_queue_t);
int xpc_event_publisher_fire(xpc_event_publisher_t, uint64_t, int);
int xpc_event_publisher_fire_noboost(xpc_event_publisher_t, uint64_t, xpc_object_t);
void xpc_event_publisher_set_handler(xpc_event_publisher_t, void (^)(xpc_event_publisher_action_t action, uint64_t event_token, xpc_object_t descriptor));
void xpc_event_publisher_set_error_handler(xpc_event_publisher_t, void (^)(int));

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_MALLOC XPC_RETURNS_RETAINED XPC_WARN_RESULT XPC_NONNULL1
xpc_pipe_t
xpc_pipe_create(const char *name, uint64_t flags);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_MALLOC XPC_RETURNS_RETAINED XPC_WARN_RESULT
xpc_pipe_t
xpc_pipe_create_from_port(mach_port_t port, uint64_t flags);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL_ALL
void
xpc_pipe_invalidate(xpc_pipe_t pipe);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL1 XPC_NONNULL2
kern_return_t
xpc_pipe_routine(xpc_pipe_t pipe, xpc_object_t request, xpc_object_t *reply);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL_ALL
kern_return_t
xpc_pipe_simpleroutine(xpc_pipe_t pipe, xpc_object_t request);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL_ALL
kern_return_t
xpc_pipe_routine_forward(xpc_pipe_t forward_to, xpc_object_t request);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL_ALL
kern_return_t
xpc_pipe_routine_async(xpc_pipe_t pipe, xpc_object_t request, mach_port_t reply_port);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL_ALL
kern_return_t
xpc_pipe_receive(mach_port_t port, xpc_object_t *request);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL_ALL
kern_return_t
xpc_pipe_routine_reply(xpc_object_t reply);

__OSX_AVAILABLE_STARTING(__MAC_10_9, __IPHONE_7_0)
XPC_EXPORT XPC_NONNULL1 XPC_NONNULL2 XPC_NONNULL3 XPC_NONNULL4
kern_return_t
xpc_pipe_try_receive(mach_port_t *port, xpc_object_t *request, mach_port_t *out_port, xpc_pipe_mig_call_t mig_handler, mach_msg_size_t mig_size, uint64_t flags);

__END_DECLS
XPC_ASSUME_NONNULL_END

#endif
