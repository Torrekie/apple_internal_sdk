#pragma once

#import <Foundation/Foundation.h>

enum {
	FBSOpenApplicationErrorCodeNone=0,
};

#ifdef __OBJC__

extern NSString* FBSActivateForEventOptionTypeBackgroundContentFetching;
extern NSString* FBSOpenApplicationOptionKeyActivateForEvent;
extern NSString* FBSDebugOptionKeyArguments;
extern NSString* FBSDebugOptionKeyEnvironment;
extern NSString* FBSDebugOptionKeyStandardOutPath;
extern NSString* FBSDebugOptionKeyStandardErrorPath;
extern NSString* FBSDebugOptionKeyWaitForDebugger;
extern NSString* FBSDebugOptionKeyDisableASLR;
extern NSString* FBSOpenApplicationOptionKeyDebuggingOptions;
extern NSString* FBSOpenApplicationOptionKeyUnlockDevice;
extern NSString* FBSDebugOptionKeyStandardOutPath;
extern NSString* FBSDebugOptionKeyStandardErrorPath;
extern NSString* FBSDebugOptionKeyWaitForDebugger;
extern NSString* FBSOpenApplicationOptionKeyDebuggingOptions;
extern NSString* FBSOpenApplicationOptionKeyLSSequenceNumber;
extern NSString* FBSOpenApplicationOptionKeyLSCacheGUID;
extern NSString* FBSDebugOptionKeyDebugOnNextLaunch;
extern NSString* FBSDebugOptionKeyCancelDebugOnNextLaunch;
extern NSString* FBSOpenApplicationOptionKeyActivateSuspended;

#endif
