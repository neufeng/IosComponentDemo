//
//  HQCache.m
//  IosComponentDemo
//
//  Created by qz on 2019/4/26.
//  Copyright © 2019 steven. All rights reserved.
//

#import "HQCache.h"
#import <YYCache/YYCache.h>

@interface HQCache ()
@property (nonatomic, strong) YYCache *yyCache;

@end

@implementation HQCache

+ (nullable instancetype)cacheWithName:(NSString *)name
{
    return [[self alloc] initWithName:name];
}

+ (nullable instancetype)cacheWithPath:(NSString *)path
{
    return [[self alloc] initWithPath:path];
}

- (instancetype)initWithName:(NSString *)name
{
    self = [super init];
    if (self) {
        YYCache *yyCache = [[YYCache alloc] initWithName:name];
        _yyCache = yyCache;
    }
    
    return self;
}

- (instancetype)initWithPath:(NSString *)path
{
    self = [super init];
    if (self) {
        YYCache *yyCache = [[YYCache alloc] initWithPath:path];
        _yyCache = yyCache;
    }
    
    return self;
}

- (BOOL)containsObjectForKey:(NSString *)key
{
    return [_yyCache containsObjectForKey:key];
}

- (nullable id<NSCoding>)objectForKey:(NSString *)key
{
    return [_yyCache objectForKey:key];
}

- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key
{
    [_yyCache setObject:object forKey:key];
}

- (void)removeObjectForKey:(NSString *)key
{
    [_yyCache removeObjectForKey:key];
}

- (void)removeAllObjects
{
    [_yyCache removeAllObjects];
}

- (void)removeAllObjectsWithBlock:(void(^)(void))block
{
    [_yyCache removeAllObjectsWithBlock:block];
}

- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void(^)(BOOL error))end
{
    [_yyCache removeAllObjectsWithProgressBlock:progress endBlock:end];
}

@end
