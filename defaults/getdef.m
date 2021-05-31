//
//  getdef.m
//  getdef
//
//  clang -framework Foundation getdef.m -o getdef
//  Created by 爱写代码的小马 on 2021/5/25.
//

#import <Foundation/Foundation.h>

extern NSDictionary* _CFPreferencesCopyApplicationMap(CFStringRef a, CFStringRef b);

int main(int argc, const char * argv[]) {

    NSDictionary *dd = _CFPreferencesCopyApplicationMap(kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    [dd enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        CFStringRef ID = (__bridge CFStringRef)key;
        NSDictionary *dInfo = (__bridge_transfer NSDictionary*)CFPreferencesCopyMultiple(
            NULL, ID, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
        printf("%s : %s\n", [(NSString *)key UTF8String], [[dInfo description] UTF8String]);

    }];
     
    return 0;
}
