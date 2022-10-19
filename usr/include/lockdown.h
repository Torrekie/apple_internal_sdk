#ifndef _LOCKDOWN_H_
#define _LOCKDOWN_H_

#include <TargetConditionals.h>

#if TARGET_OS_EMBEDDED
#include <CoreFoundation/CoreFoundation.h>

#define kLDESuccess 0

__BEGIN_DECLS

typedef struct _lockdown_connection *lockdown_connection;

int secure_lockdown_checkin(lockdown_connection *conn, int unknown, int unknown1);
lockdown_connection lockdown_connect();
void lockdown_disconnect(lockdown_connection conn);
int lockdown_send_message(lockdown_connection conn, CFPropertyListRef message, int flags);
int lockdown_receive_message(lockdown_connection conn, CFPropertyListRef* message);
int lockdown_get_socket(lockdown_connection conn);
void *lockdown_get_securecontext(lockdown_connection conn);

__END_DECLS

#else
#error Not available on macOS
#endif

#endif
