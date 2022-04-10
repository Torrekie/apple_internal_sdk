#ifndef _OS_FEATURE_PRIVATE_H_
#define _OS_FEATURE_PRIVATE_H_

#include <stdbool.h>
#include <os/base.h>
#include <Availability.h>


#pragma clang assume_nonnull begin

/**
 * While calling os_feature_enabled(domain, feature),
 * /usr/lib/system/libsystem_featureflags.dylib searches
 * plist files under /System/Library/FeatureFlags/Domain
 * and /Library/Preferences/FeatureFlags/Domain with name
 * defined by 'domain'.
 * (e.g. domain = objc4 goes objc4.plist)
 * 'feature' refers to a Dictionary value containing a bool
 * value in domain plist file.
 */

#define os_feature_enabled(d, f) _os_feature_enabled_impl(#d, #f)
#define os_feature_enabled_simple(d, f, s) _os_feature_enabled_simple_impl(#d, #f, #s)

__BEGIN_DECLS

bool _os_feature_enabled_impl(const char *domain, const char *feature)
__OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_14_0);

bool _os_feature_enabled_simple_impl(const char *domain, const char *feature, bool status)
__OSX_AVAILABLE_STARTING(__MAC_11_0, __IPHONE_14_0);

__END_DECLS

#pragma clang assume_nonnull end

#endif
