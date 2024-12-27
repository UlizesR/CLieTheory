#import <Cocoa/Cocoa.h>
#import "MWLWindow.h"

@interface MWL_WindowDelegate : NSObject <NSWindowDelegate>
@end

@implementation MWL_WindowDelegate
- (void)windowWillClose:(NSNotification *)notification 
{
    if (self == nil) {
        return;
    }
}
@end

MWLWindow* MWLWindowCreate(size_t width, size_t height, const char *title)
{
    MWLWindow* window = (MWLWindow*)malloc(sizeof(MWLWindow));
    if (!window)
        return NULL;

    // Zero out the struct for safety
    window->width  = width;
    window->height = height;
    window->title  = title;
    window->flags  = 0;
    window->nswindow = nil;
    window->view   = nil;

    // Create our delegate
    MWL_WindowDelegate* windowDelegate = [[MWL_WindowDelegate alloc] init];
    // Create the NSWindow
    NSRect frame      = NSMakeRect(0, 0, width, height);
    NSUInteger style  = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable;
    NSWindow* nsWindow = [[NSWindow alloc] initWithContentRect:frame
                                                     styleMask:style
                                                       backing:NSBackingStoreBuffered
                                                         defer:NO];
    // Attach to our MWLWindow struct
    window->flags  = (uint32_t)style;
    // Create a content view
    NSView* nsView = [[NSView alloc] initWithFrame:frame];
    window->view   = nsView;
    [nsWindow setContentView:nsView];
    // Configure the window
    if (title)
    {
        [nsWindow setTitle:[NSString stringWithUTF8String:title]];
    }
    [nsWindow center];
    [nsWindow setLevel:NSNormalWindowLevel];
    [nsWindow setAcceptsMouseMovedEvents:YES];
    [nsWindow setRestorable:NO];
    [nsWindow setDelegate:windowDelegate];
    [nsWindow makeKeyAndOrderFront:nil];
    window->nswindow = nsWindow;

    return window;
}

void MWLWindowSetFlags(MWLWindow *window, MWL_WINDOW_STYLE_FLAGS flags)
{
    if (!window || !window->nswindow)
        return;

    NSUInteger style = (NSUInteger)flags;
    [window->nswindow setStyleMask:style];
}

void MWLWindowDestroy(MWLWindow *window)
{
    if (!window || !window->nswindow)
        return;

    // Close the window
    [window->nswindow close];
    [window->nswindow setDelegate:nil];
    [window->nswindow release];
    // Free the memory for the MWLWindow
    free(window);

}

bool MWLWindowShouldClose(MWLWindow *window)
{   
    if (!window || !window->nswindow)
        return false;

    return [window->nswindow isVisible] || [window->nswindow isMiniaturized];
}

void MWLCloseWindow(MWLWindow *window)
{
    if (!window || !window->nswindow)
        return;

    [window->nswindow close];
}