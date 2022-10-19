#import <Foundation/Foundation.h>

enum {
    BKSApplicationStateUnknown                      = 0,
    BKSApplicationStateTerminated                   = (1 << 0),
    BKSApplicationStateBackgroundTaskSuspended      = (1 << 1),
    BKSApplicationStateBackgroundRunning            = (1 << 2),
    BKSApplicationStateForegroundRunning            = (1 << 3),
    BKSApplicationStateProcessServer                = (1 << 4),
    BKSApplicationStateForegroundRunningObscured    = (1 << 5),
};
typedef uint32_t BKSApplicationState;

extern NSString * const BKSApplicationStateMostElevatedStateForProcessIDKey;
extern NSString * const BKSApplicationStateProcessIDKey;

typedef void(^BKSApplicationStateChangedHandler)(NSDictionary *userInfo);

@interface BKSApplicationStateMonitor : NSObject

@property (nonatomic, copy) BKSApplicationStateChangedHandler handler;

- (BKSApplicationState)mostElevatedApplicationStateForPID:(pid_t)pid;
- (void)invalidate;

@end

