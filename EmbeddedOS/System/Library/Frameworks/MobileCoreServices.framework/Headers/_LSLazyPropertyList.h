@interface _LSLazyPropertyList : NSObject <NSCopying, NSSecureCoding> {
    NSMutableDictionary * _individuallyLoadedValues;
    BOOL  _peeking;
    NSDictionary * _plist;
    NSObject<OS_dispatch_queue> * _queue;
}

@property (nonatomic, readonly) NSObject<OS_dispatch_queue> *_queue;
@property (getter=isPeeking) BOOL peeking;
@property (readonly) NSDictionary *propertyList;

+ (id)lazyPropertyListWithContext:(struct LSContext *)arg1 table:(unsigned int)arg2 unit:(unsigned int)arg3;
+ (id)lazyPropertyListWithLazyPropertyLists:(id)arg1;
+ (id)lazyPropertyListWithPropertyList:(id)arg1;
+ (id)lazyPropertyListWithPropertyListData:(id)arg1;
+ (BOOL)supportsSecureCoding;

- (id)_filterValueFromPropertyList:(id)arg1 ofClass:(Class)arg2 valuesOfClass:(Class)arg3;
- (BOOL)_getValue:(id*)arg1 forPropertyListKey:(id)arg2;
- (id)_initWithPropertyList:(id)arg1;
- (id)_loadPropertyListPeeking:(BOOL)arg1;
- (id)_loadPropertyListPeeking:(BOOL)arg1 forKey:(id)arg2 block:(id /* block */)arg3;
- (id)_queue;
- (id)copyWithZone:(NSZone*)arg1;
- (void)dealloc;
- (void)encodeWithCoder:(id)arg1;
- (id)init;
- (id)initWithCoder:(id)arg1;
- (BOOL)isPeeking;
- (id)objectForPropertyListKey:(id)arg1 ofClass:(Class)arg2;
- (id)objectForPropertyListKey:(id)arg1 ofClass:(Class)arg2 valuesOfClass:(Class)arg3;
- (id)propertyList;
- (void)setPeeking:(BOOL)arg1;

@end
