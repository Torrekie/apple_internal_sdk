#ifndef _LIBSMC_SMCNOTIFICATION_H_
#define _LIBSMC_SMCNOTIFICATION_H_

#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CFBase.h>

/* SMC Notify, for use with SMCRegisterForNotification() */
#define kSMCNotifySystemState   "system-state-notify"
#define kSMCNotifyPowerState    "power-state-notify"
#define kSMCNotifyHIDEvent      "hid-event-notify"

/* Accepted by AppleSMC.kext but not libSMC.dylib */
// battauth-event-notify
// gg-fw-update-event-notify

__BEGIN_DECLS

// gSMCClientList // Probably uint64_t[4]
// getSMCQueue
// _unregisterForNotification
io_object_t gNotification;
IONotificationPortRef gNotifyPort;
IOServiceInterestCallback _smcNotificationCallback;

#pragma SMC IONotification
/*
 _SMCRegisterForNotification
 _SMCRegisterForSubTypeNotification
 _SMCUnregisterForNotification
 */

__END_DECLS

#endif /* _LIBSMC_SMCNOTIFICATION_H_ */
