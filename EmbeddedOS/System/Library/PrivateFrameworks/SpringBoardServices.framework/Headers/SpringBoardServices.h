#ifndef _SPRINGBOARDSERVICES_SPRINGBOARDSERVICES_H_
#define _SPRINGBOARDSERVICES_SPRINGBOARDSERVICES_H_

#include <CoreFoundation/CoreFoundation.h>

__BEGIN_DECLS

mach_port_t SBSSpringBoardServerPort();
void SBSetSystemVolumeHUDEnabled(mach_port_t springBoardPort, const char *audioCategory, Boolean enabled);

void SBGetScreenLockStatus(mach_port_t port, bool *lockStatus, bool *passcodeEnabled);

void SBSOpenNewsstand();
void SBSSuspendFrontmostApplication();

CFArrayRef SBSCopyApplicationDisplayIdentifiers(bool onlyActive, bool debuggable);
CFStringRef SBSCopyStatusBarOperatorName();

CFStringRef SBSCopyBundlePathForDisplayIdentifier(CFStringRef displayIdentifier);
CFStringRef SBSCopyExecutablePathForDisplayIdentifier(CFStringRef displayIdentifier);
CFStringRef SBSCopyIconImagePathForDisplayIdentifier(CFStringRef identifier);
CFDataRef SBSCopyIconImagePNGDataForDisplayIdentifier(CFStringRef displayIdentifier);

CFStringRef SBSCopyNowPlayingAppBundleIdentifier();

CFSetRef SBSCopyDisplayIdentifiers();
CFStringRef SBSCopyLocalizedApplicationNameForDisplayIdentifier(CFStringRef identifier);

CFStringRef SBSCopyFrontmostApplicationDisplayIdentifier();
CFStringRef SBSCopyDisplayIdentifierForProcessID(pid_t PID);
CFDictionaryRef SBSCopyInfoForApplicationWithProcessID(pid_t PID);

CFArrayRef SBSCopyDisplayIdentifiersForProcessID(pid_t PID);
bool SBSProcessIDForDisplayIdentifier(CFStringRef identifier, pid_t *pid);

// The following need com.apple.backboardd.launchapplications entitlement
int SBSLaunchApplicationWithIdentifier(CFStringRef identifier, Boolean suspended);
int SBSLaunchApplicationWithIdentifierAndLaunchOptions(CFStringRef identifier, CFDictionaryRef launchOptions, bool suspended);
CFStringRef SBSApplicationLaunchingErrorString(int error);

int SBSOpenSensitiveURLAndUnlock(CFURLRef url, char flags); // need com.apple.springboard.opensensitiveurl entitlement

__END_DECLS

#endif
