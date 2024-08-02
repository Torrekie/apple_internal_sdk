#ifndef _IOKIT_HID_IOHIDEVENTSYSTEMKEYS_H_
#define _IOKIT_HID_IOHIDEVENTSYSTEMKEYS_H_

/* Torrekie: All NotifyKeys is something ID like, which used by system notify.h calls */

/* kIOHIDEventSystemDisplayStatusNotifyKey first appears in PowerManagement/pmconfigd */
/* Then we can guess the format like: kIOHIDEventSystem => com.apple.iokit.hid, DisplayStatus => displayStatus
 * Key => (System)DisplayStatus, NotifyKey => com.apple.iokit.hid.displayStatus
 */
#define kIOHIDEventSystemDisplayStatusNotifyKey "com.apple.iokit.hid.displayStatus"

#endif
