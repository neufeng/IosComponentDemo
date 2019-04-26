//
//  HQCache.h
//  IosComponentDemo
//
//  Created by qz on 2019/4/26.
//  Copyright © 2019 steven. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HQCache : NSObject

/**
 通过名称初始化缓存实例
 具有相同名称的多个实例将使缓存不稳定

 @param name 缓存名称
 @return 缓存实例
 */
+ (nullable instancetype)cacheWithName:(NSString *)name;

/**
 通过路径初始化缓存实例
 
 @param path  完整路径
 @result 缓存实例
 */
+ (nullable instancetype)cacheWithPath:(NSString *)path;

#pragma mark - Access Methods

/**
 是否包含缓存
 
 @param key 缓存key
 @return bool
 */
- (BOOL)containsObjectForKey:(NSString *)key;

/**
 获取缓存
 
 @param key A string identifying the value. If nil, just return nil.
 @return The value associated with key, or nil if no value is associated with key.
 */
- (nullable id<NSCoding>)objectForKey:(NSString *)key;

/**
 设置缓存
 
 @param object The object to be stored in the cache. If nil, it calls `removeObjectForKey:`.
 @param key    The key with which to associate the value. If nil, this method has no effect.
 */
- (void)setObject:(nullable id<NSCoding>)object forKey:(NSString *)key;

/**
 移除缓存
 
 @param key The key identifying the value to be removed. If nil, this method has no effect.
 */
- (void)removeObjectForKey:(NSString *)key;

/**
 清空缓存
 */
- (void)removeAllObjects;

/**
 异步清空缓存
 
 @param block  A block which will be invoked in background queue when finished.
 */
- (void)removeAllObjectsWithBlock:(void(^)(void))block;

/**
 异步清空缓存并反馈进度
 
 @warning You should not send message to this instance in these blocks.
 @param progress This block will be invoked during removing, pass nil to ignore.
 @param end      This block will be invoked at the end, pass nil to ignore.
 */
- (void)removeAllObjectsWithProgressBlock:(nullable void(^)(int removedCount, int totalCount))progress
                                 endBlock:(nullable void(^)(BOOL error))end;

@end

NS_ASSUME_NONNULL_END
