#pragma once

#import <Foundation/Foundation.h>

typedef long FBSOpenApplicationErrorCode;

#ifdef __OBJC__
NSString* FBSOpenApplicationErrorCodeToString(FBSOpenApplicationErrorCode code);
#endif
