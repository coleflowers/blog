//
//  deldef.m
//  deldef
//
//  clang -framework Foundation deldef.m -o deldef
//  Created by 爱写代码的小马 on 2021/5/30.
//

#import <Foundation/Foundation.h>

extern void _CFPrefsSynchronizeForProcessTermination(CFStringRef a, CFStringRef b);
extern void _CFPreferencesFlushCachesForIdentifier(CFStringRef a, CFStringRef b);

int main(int argc, const char * argv[]) {
    NSString *app = @"dui";
    NSString *delKey = @"a";
    CFPreferencesSetValue((CFStringRef)delKey, NULL, (CFStringRef)app, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    CFPreferencesSynchronize((CFStringRef)app, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    _CFPrefsSynchronizeForProcessTermination((CFStringRef)app, kCFPreferencesCurrentUser);
    _CFPreferencesFlushCachesForIdentifier((CFStringRef)app, kCFPreferencesCurrentUser);
    return 0;
}
