#pragma once

#include "_LSQueryResult.h"
#include "_LSLazyPropertyList.h"

#import <CoreGraphics/CoreGraphics.h>

@class LSApplicationProxy;

@interface LSResourceProxy : _LSQueryResult <NSCopying, NSSecureCoding> {
    _LSLazyPropertyList * __boundIconsDictionary;
    NSString * _boundApplicationIdentifier;
    NSURL * _boundContainerURL;
    NSURL * _boundDataContainerURL;
    NSString * _boundIconCacheKey;
    NSArray * _boundIconFileNames;
    BOOL  _boundIconIsBadge;
    BOOL  _boundIconIsPrerendered;
    NSURL * _boundResourcesDirectoryURL;
    NSString * _localizedName;
    BOOL  _privateDocumentIconAllowOverride;
    unsigned int  _propertyListCachingStrategy;
    LSApplicationProxy * _typeOwner;
}

@property (setter=_setBoundIconsDictionary:, nonatomic, copy) _LSLazyPropertyList *_boundIconsDictionary;
@property (nonatomic, copy) NSString *boundApplicationIdentifier;
@property (nonatomic, copy) NSURL *boundContainerURL;
@property (nonatomic, copy) NSURL *boundDataContainerURL;
@property (nonatomic, copy) NSString *boundIconCacheKey;
@property (nonatomic, copy) NSArray *boundIconFileNames;
@property (nonatomic) BOOL boundIconIsBadge;
@property (nonatomic) BOOL boundIconIsPrerendered;
@property (nonatomic, readonly) NSDictionary *boundIconsDictionary;
@property (nonatomic, copy) NSURL *boundResourcesDirectoryURL;
@property (nonatomic, readonly) NSDictionary *iconsDictionary;
@property (nonatomic, copy) NSString *localizedName;
@property (nonatomic) BOOL privateDocumentIconAllowOverride;
@property (nonatomic) unsigned int propertyListCachingStrategy;
@property (nonatomic, copy) LSApplicationProxy *typeOwner;

// Image: /System/Library/Frameworks/MobileCoreServices.framework/MobileCoreServices

+ (BOOL)supportsSecureCoding;

- (id)_boundIconsDictionary;
- (id)_initWithLocalizedName:(id)arg1;
- (id)_initWithLocalizedName:(id)arg1 boundApplicationIdentifier:(id)arg2 boundContainerURL:(id)arg3 dataContainerURL:(id)arg4 boundResourcesDirectoryURL:(id)arg5 boundIconsDictionary:(id)arg6 boundIconCacheKey:(id)arg7 boundIconFileNames:(id)arg8 typeOwner:(id)arg9 boundIconIsPrerendered:(BOOL)arg10 boundIconIsBadge:(BOOL)arg11;
- (void)_setBoundIconsDictionary:(_LSLazyPropertyList*)arg1;
- (id)boundApplicationIdentifier;
- (id)boundContainerURL;
- (id)boundDataContainerURL;
- (id)boundIconCacheKey;
- (id)boundIconFileNames;
- (BOOL)boundIconIsBadge;
- (BOOL)boundIconIsPrerendered;
- (id)boundIconsDictionary;
- (id)boundResourcesDirectoryURL;
- (id)copyWithZone:(NSZone *)arg1;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (id)iconDataForStyle:(id)arg1 width:(int)arg2 height:(int)arg3 options:(unsigned int)arg4;
- (id)iconDataForVariant:(int)arg1;
- (id)iconStyleDomain;
- (id)iconsDictionary;
- (id)initWithCoder:(id)arg1;
- (id)localizedName;
- (BOOL)privateDocumentIconAllowOverride;
- (unsigned int)propertyListCachingStrategy;
- (void)setBoundApplicationIdentifier:(NSString*)arg1;
- (void)setBoundContainerURL:(NSURL*)arg1;
- (void)setBoundDataContainerURL:(NSURL*)arg1;
- (void)setBoundIconCacheKey:(NSString*)arg1;
- (void)setBoundIconFileNames:(NSArray*)arg1;
- (void)setBoundIconIsBadge:(BOOL)arg1;
- (void)setBoundIconIsPrerendered:(BOOL)arg1;
- (void)setBoundResourcesDirectoryURL:(NSURL*)arg1;
- (void)setLocalizedName:(NSString*)arg1;
- (void)setPrivateDocumentIconAllowOverride:(BOOL)arg1;
- (void)setPropertyListCachingStrategy:(unsigned int)arg1;
- (void)setTypeOwner:(LSApplicationProxy*)arg1;
- (id)typeOwner;
- (id)uniqueIdentifier;

// Image: /System/Library/Frameworks/UIKit.framework/UIKit

+ (CGSize)_applicationIconCanvasSize;
+ (int)_compareApplicationIconCanvasSize:(CGSize)arg1 withSize:(CGSize)arg2;

- (CGSize)_defaultStyleSize:(id)arg1;
- (void*)_iconDefinitionForSize:(CGSize)arg1 style:(id)arg2;
- (id)_iconForStyle:(id)arg1;
- (id)_iconForStyle:(id)arg1 size:(CGSize)arg2;
- (void*)_iconVariantDefinitions:(id)arg1;
- (CGSize)_largestImageSize:(id)arg1;

@end


#include "LSBundleProxy.h"
#include "LSApplicationProxy.h"
