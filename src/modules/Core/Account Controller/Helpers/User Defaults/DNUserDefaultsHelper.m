//
//  DNUserDefaultsHelper.m
//  Donky COreSDK
//
//  Created by Donky Networks on 15/03/2015.
//  Copyright (c) 2015 Donky Networks Ltd. All rights reserved.
//

#if !__has_feature(objc_arc)
#error Donky SDK must be built with ARC.
// You can turn on ARC for only Donky Class files by adding -fobjc-arc to the build phase for each of its files.
#endif

#import "DNUserDefaultsHelper.h"
#import "DNLoggingController.h"

@implementation DNUserDefaultsHelper

+ (NSString *)domainName {
  return [[[NSBundle mainBundle] bundleIdentifier] stringByAppendingString:@"com.dynmark.donkyuserdefaults"];
}

+ (NSUserDefaults *)userDetails {
    return [[NSUserDefaults alloc] initWithSuiteName:[self domainName]];
}

+ (void)saveObject:(id)object withKey:(NSString *) key {
    [[DNUserDefaultsHelper userDetails] setObject:object forKey:key];
    [DNUserDefaultsHelper saveUserDefaults];
}

+ (id)objectForKey:(NSString *) key {
    @try {
          return [[DNUserDefaultsHelper userDetails] objectForKey:key];
    }
    @catch (NSException *exception) {
        DNErrorLog(@"%@", [exception description]);
    }
}

+ (void)resetUserDefaults {
    [[DNUserDefaultsHelper userDetails] removeSuiteNamed:[self domainName]];
}

+ (void)saveUserDefaults {
    [[DNUserDefaultsHelper userDetails] synchronize];
}

+ (void)deleteObjectForKey:(NSString *)key {
    [[DNUserDefaultsHelper userDetails] removeObjectForKey:key];
    [DNUserDefaultsHelper saveUserDefaults];
}

@end
