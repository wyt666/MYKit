//
//  NSDate+Formatter.h
//  MYKitDemo
//
//  Created by sunjinshuai on 2017/9/8.
//  Copyright © 2017年 com.51fanxing. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (Formatter)

+ (NSDateFormatter *)formatter;
+ (NSDateFormatter *)formatterWithoutTime;
+ (NSDateFormatter *)formatterWithoutDate;

- (NSString *)formatWithUTCTimeZone;
- (NSString *)formatWithLocalTimeZone;
- (NSString *)formatWithTimeZoneOffset:(NSTimeInterval)offset;
- (NSString *)formatWithTimeZone:(NSTimeZone *)timezone;

- (NSString *)formatWithUTCTimeZoneWithoutTime;
- (NSString *)formatWithLocalTimeZoneWithoutTime;
- (NSString *)formatWithTimeZoneOffsetWithoutTime:(NSTimeInterval)offset;
- (NSString *)formatWithTimeZoneWithoutTime:(NSTimeZone *)timezone;

- (NSString *)formatWithUTCWithoutDate;
- (NSString *)formatWithLocalTimeWithoutDate;
- (NSString *)formatWithTimeZoneOffsetWithoutDate:(NSTimeInterval)offset;
- (NSString *)formatTimeWithTimeZone:(NSTimeZone *)timezone;


+ (NSString *)currentDateStringWithFormat:(NSString *)format;
+ (NSDate *)dateWithSecondsFromNow:(NSInteger)seconds;
+ (NSDate *)dateWithYear:(NSInteger)year month:(NSUInteger)month day:(NSUInteger)day;
- (NSString *)dateWithFormat:(NSString *)format;


@end

NS_ASSUME_NONNULL_END