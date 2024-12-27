#import "MWLApp.h"
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

@interface MWL_AppDelegate : NSObject <NSApplicationDelegate>
@end

@implementation MWL_AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)notification 
{
    @autoreleasepool
    {
        NSEvent *event = [NSEvent otherEventWithType:NSEventTypeApplicationDefined
                                            location:NSMakePoint(0, 0)
                                       modifierFlags:0
                                           timestamp:0
                                        windowNumber:0
                                             context:nil
                                             subtype:0
                                               data1:0
                                               data2:0
        ];
        
        [NSApp postEvent:event atStart:YES];
    }
    [NSApp stop:nil];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}


- (void)applicationWillTerminate:(NSNotification *)aNotification 
{
    if (self == nil) {
        return;
    }
}
@end

bool MWLInitApplication(MWLAppState* appState)
{
    if (!appState) return false;
    // Create the shared NSApplication instance
    [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    // Allocate and init our custom delegate
    MWL_AppDelegate* delegate = [[MWL_AppDelegate alloc] init];
    // Store references in our MWLApplication struct
    appState->application.app      = NSApp;
    appState->application.delegate = delegate;
    // Assign the delegate to NSApp
    [NSApp setDelegate:delegate];
    // Finish launching, then run the event loop
    [NSApp finishLaunching];
    appState->isRunning = true;
    [NSApp activateIgnoringOtherApps:YES];
    // [NSApp run];

    return true;
}

void MWLShutdownApplication(MWLAppState* appState)
{
    if (!appState) return;

    // In a typical Cocoa app, you might call [NSApp terminate:nil].
    // If you want to do a custom teardown:
    if (appState->application.delegate)
    {
        [appState->application.delegate release];
        [NSApp setDelegate:nil];
    }

    appState->application.app      = nil;
    appState->application.delegate = nil;
    appState->isRunning            = false;
}
