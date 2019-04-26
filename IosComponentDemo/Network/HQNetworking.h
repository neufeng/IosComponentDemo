//
//  HQNetworking.h
//  Hardware-platform-retail
//
//  Created by qz on 2019/4/23.
//  Copyright © 2019 Zlead. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSURLSessionTask HQURLSessionTask;

/**
 回调

 @param response 回调数据
 */
typedef void (^HQResponseBlock)(id response);

/**
 下载进度

 @param bytesDone 已完成的大小
 @param totalBytes 总大小
 */
typedef void (^HQProgressBlock)(int64_t bytesDone, int64_t totalBytes);


/**
 回调集合

 @param responses 回调数据集合
 */
typedef void (^HQMultiResponseBlock)(NSArray *responses);

@interface HQNetworking : NSObject


/**
 取消请求任务

 @param sessionTask 请求任务
 */
+ (void)cancelSessionTask:(HQURLSessionTask *)sessionTask;

/**
 GET请求
 
 @param url 请求url
 @param params 请求参数
 @param responseBlock 回调
 
 @return 返回请求任务
 */
+ (HQURLSessionTask *)getWithUrl:(NSString *)url params:(NSDictionary *)params responseBlock:(HQResponseBlock)responseBlock;

/**
 GET请求

 @param url 请求url
 @param params 请求参数
 @param headers 请求头
 @param responseBlock 回调
 
 @return 返回请求任务
 */
+ (HQURLSessionTask *)getWithUrl:(NSString *)url params:(NSDictionary *)params headers:(NSDictionary *)headers responseBlock:(HQResponseBlock)responseBlock;

/**
 POST请求
 
 @param url 请求url
 @param params 请求参数
 @param responseBlock 回调
 @return 返回请求任务
 */
+ (HQURLSessionTask *)postWithUrl:(NSString *)url params:(NSDictionary *)params responseBlock:(HQResponseBlock)responseBlock;

/**
 POST请求

 @param url 请求url
 @param params 请求参数
 @param headers 请求头
 @param responseBlock 回调
 @return 返回请求任务
 */
+ (HQURLSessionTask *)postWithUrl:(NSString *)url params:(NSDictionary *)params headers:(NSDictionary *)headers responseBlock:(HQResponseBlock)responseBlock;


/**
 文件上传

 @param url 上传文件url
 @param data 文件数据
 @param type 文件类型
 @param name 文件名
 @param mimeType mimeType
 @param progressBlock 进度回调
 @param responseBlock 结果回调
 @return 返回请求任务
 */
+ (HQURLSessionTask *)uploadFileWithUrl:(NSString *)url fileData:(NSData *)data type:(NSString *)type name:(NSString *)name mimeType:(NSString *)mimeType progressBlock:(HQProgressBlock)progressBlock responseBlock:(HQResponseBlock)responseBlock;


/**
 文件下载

 @param url 下载文件url
 @param progressBlock 进度回调
 @param responseBlock 结果回调
 @return 返回请求任务
 */
+ (HQURLSessionTask *)downloadWithUrl:(NSString *)url progressBlock:(HQProgressBlock)progressBlock responseBlock:(HQResponseBlock)responseBlock;


/**
 多文件上传

 @param url 上传文件url
 @param datas 数据集合
 @param type 类型
 @param name 文件夹名
 @param mimeType mimeType
 @param progressBlock 进度回调
 @param multiResponseBlock 结果回调
 @return 任务集合
 */
+ (NSArray *)uploadMultiFileWithUrl:(NSString *)url fileDatas:(NSArray *)datas type:(NSString *)type name:(NSString *)name mimeType:(NSString *)mimeType progressBlock:(HQProgressBlock)progressBlock multiResponseBlock:(HQMultiResponseBlock)multiResponseBlock;

@end
