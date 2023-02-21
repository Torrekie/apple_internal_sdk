#ifndef LocalAuthentication_LAPrivateDefines_h
#define LocalAuthentication_LAPrivateDefines_h

#include <LocalAuthentication/LAPublicDefines.h>

/* Tue Feb 21 19:39:04 CST 2023
 * Reversed from /usr/lib/pam/libtid.so.2 in macOS 11.2.3
 */

#define kLAOptionNotInteractive					1000
#define kLAOptionUserId						1019

// Not sure which header these func should be at
CFTypeRef LACreateNewContextWithACMContext(CFDataRef acm_context, CFErrorRef *error);
bool LAEvaluatePolicy(CFTypeRef context, const int policy, CFMutableDictionaryRef options, CFErrorRef *error);

#endif
