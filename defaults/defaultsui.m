#import <Cocoa/Cocoa.h> 

// clang -framework Cocoa defaultsui.m -o dui
// clang -g -framework Cocoa defaultsui.m -o dui
// clang -gdwarf-2 -framework Cocoa defaultsui.m -o dui

NSString *getTitle()
{
    bool launched = [[NSUserDefaults standardUserDefaults] boolForKey:@"_t_first_launched"];
    NSString *dateString = @"";
    if (!launched) {
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        
        dateString = [dateFormatter stringFromDate:[NSDate date]];
        [[NSUserDefaults standardUserDefaults] setValue:dateString forKey:@"_t_first_launch_time"];
        [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"_t_first_launched"];
        [[NSUserDefaults standardUserDefaults] synchronize];
    } else {
        dateString = [[NSUserDefaults standardUserDefaults] valueForKey:@"_t_first_launch_time"];
    }
    
    NSString *title = [NSString stringWithFormat:@"注册时间:%@", dateString];
    return title;
}

int main(int argc, char *argv[])
{
    NSUInteger windowStyle = NSWindowStyleMaskTitled;
    NSRect windowRect = NSMakeRect(200, 300, 400, 184);
    NSWindow * window = [[NSWindow alloc] initWithContentRect:windowRect
        styleMask:windowStyle
        backing:NSBackingStoreBuffered
        defer:NO];

    [window setTitle:getTitle()];
    [window orderFrontRegardless];
    [NSApp run];
    return 0;
}