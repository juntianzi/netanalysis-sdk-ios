//
//  UTracertModel.h
//  UNetAnalysisSDK
//
//  Created by ethan on 2018/12/17.
//  Copyright © 2018 ucloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UNetAnalysisConst.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum Enum_Traceroute_Status
{
    Enum_Traceroute_Status_doing = 0,
    Enum_Traceroute_Status_finish
}Enum_Traceroute_Status;


@interface UCTracerRouteResModel : NSObject

@property (readonly) NSInteger hop;
@property NSString* ip;
@property NSTimeInterval* durations; //ms
@property (readonly) NSInteger count; //ms
@property (nonatomic,assign) Enum_Traceroute_Status status;
@property (nonatomic,copy) NSString *dstIp;


- (instancetype)init:(NSInteger)hop
               count:(NSInteger)count;
@end


@interface UReportTracertModel : NSObject
@property (nonatomic,copy) NSString *src_ip;
@property (nonatomic,copy) NSString *dst_ip;
@property (nonatomic,strong) NSMutableArray *routeReplyArray;


+ (instancetype)uReportTracertModel:(NSDictionary *)dict;
- (NSDictionary *)objConvertToReportDict;
@end


@interface URouteReplyModel : NSObject
@property (nonatomic,copy) NSString *route_ip;
@property (nonatomic,assign) float   avgDelay;

+ (instancetype)uRouteReplayModelWithDict:(NSDictionary *)dict;
- (NSDictionary *)objConvertToDict;
@end


@interface UCTracertUCHostsRecord : NSObject<NSCoding>
@property (nonatomic,assign) int currentDays;        // days form 1970.1.1
@property (nonatomic,copy) NSString *currentTracertIp;   // default is 127.0.0.1
@property (nonatomic,assign) Enum_Tracert_UC_Hosts_State tracertUCHostsState;

+ (instancetype)ucTracertUCHostsRecordWithDict:(NSDictionary *)dict;
@end


NS_ASSUME_NONNULL_END
