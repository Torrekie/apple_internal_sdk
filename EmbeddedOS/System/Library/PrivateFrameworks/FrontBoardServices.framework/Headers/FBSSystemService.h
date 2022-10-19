@class FBSSystemAppProxy;

@interface FBSSystemService : NSObject {
    FBSSystemAppProxy * _systemAppProxy;
}

+ (id)clientCallbackQueue;
+ (id)sharedService;

- (void)_openApplication:(id)arg1 withOptions:(id)arg2 clientHandle:(id)arg3 completion:(id /* block */)arg4;
- (BOOL)canOpenApplication:(id)arg1 reason:(int*)arg2;
- (void)cleanupClientPort:(unsigned int)arg1;
- (unsigned int)createClientPort;
- (void)dataResetWithRequest:(id)arg1 completion:(id /* block */)arg2;
- (void)deleteAllSnapshotsForApplication:(id)arg1;
- (id)init;
- (BOOL)isPasscodeLockedOrBlocked;
- (void)openApplication:(id)arg1 options:(id)arg2 clientPort:(unsigned int)arg3 withResult:(id /* block */)arg4;
- (void)openApplication:(id)arg1 options:(id)arg2 withResult:(id /* block */)arg3;
- (void)openURL:(id)arg1 application:(id)arg2 options:(id)arg3 clientPort:(unsigned int)arg4 withResult:(id /* block */)arg5;
- (int)pidForApplication:(id)arg1;
- (id)processHandleForApplication:(id)arg1;
- (void)reboot;
- (void)sendActions:(id)arg1 withResult:(id /* block */)arg2;
- (void)setBadgeValue:(id)arg1 forBundleID:(id)arg2;
- (void)setKeyboardFocusApplicationWithBundleID:(id)arg1 pid:(int)arg2 completion:(id /* block */)arg3;
- (void)shutdown;
- (id)systemApplicationBundleIdentifier;
- (void)terminateApplication:(id)arg1 forReason:(int)arg2 andReport:(BOOL)arg3 withDescription:(id)arg4;
- (void)terminateApplication:(id)arg1 forReason:(int)arg2 andReport:(BOOL)arg3 withDescription:(id)arg4 completion:(id /* block */)arg5;
- (void)terminateApplicationGroup:(int)arg1 forReason:(int)arg2 andReport:(BOOL)arg3 withDescription:(id)arg4;
- (void)terminateApplicationGroup:(int)arg1 forReason:(int)arg2 andReport:(BOOL)arg3 withDescription:(id)arg4 completion:(id /* block */)arg5;

@end
