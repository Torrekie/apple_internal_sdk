#import <Foundation/Foundation.h>

enum {
    BKSProcessAssertionNone = 0,
    BKSProcessAssertionPreventTaskSuspend  = 1 << 0,
    BKSProcessAssertionPreventTaskThrottleDown = 1 << 1,
    BKSProcessAssertionAllowIdleSleep = 1 << 2,
    BKSProcessAssertionWantsForegroundResourcePriority = 1 << 3,
    BKSProcessAssertionAllowSuspendOnSleep = 1 << 4,
};
typedef uint32_t BKSProcessAssertionFlags;

enum {
    BKSProcessAssertionReasonExtension = 13,
};
typedef uint32_t BKSProcessAssertionReason;

typedef void (^BKSProcessAssertionInvalidationHandler)(void);
typedef void (^BKSProcessAssertionAcquisitionHandler)(BOOL acquired);

@interface BKSProcessAssertion : NSObject
@end

@interface BKSProcessAssertion ()
@property (nonatomic, assign) BKSProcessAssertionFlags flags;
- (id)initWithPID:(pid_t)pid flags:(BKSProcessAssertionFlags)flags reason:(BKSProcessAssertionReason)reason name:(NSString *)name withHandler:(BKSProcessAssertionAcquisitionHandler)handler;

@property (nonatomic, copy) BKSProcessAssertionInvalidationHandler invalidationHandler;
- (void)invalidate;
@end
