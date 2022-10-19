#import <Foundation/NSObject.h>

@interface BSSignal : NSObject
{
    BOOL _signalled;
}

- (void)reset;
- (BOOL)hasBeenSignalled;
- (void)signal;
- (id)init;

@end
