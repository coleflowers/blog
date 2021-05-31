//
//  setdef.m
//  setdef
//
//  clang -framework Foundation setdef.m -o setdef
//  Created by 爱写代码的小马 on 2021/5/30.
//

#import <Foundation/Foundation.h>

extern void _CFPrefsSynchronizeForProcessTermination(CFStringRef a, CFStringRef b);
extern void _CFPreferencesFlushCachesForIdentifier(CFStringRef a, CFStringRef b);

int main(int argc, const char * argv[]) {

    NSDictionary *dic = @{@"a":@"ccc", @"_t_first_launch_time":@"1990-10-10 12:12:22"};
    NSString *app = @"dui";
    CFPreferencesSetMultiple((CFDictionaryRef)dic, NULL, (CFStringRef)app, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    CFPreferencesSynchronize((CFStringRef)app, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    _CFPrefsSynchronizeForProcessTermination((CFStringRef)app, kCFPreferencesCurrentUser);
    _CFPreferencesFlushCachesForIdentifier((CFStringRef)app, kCFPreferencesCurrentUser);
    return 0;
}
