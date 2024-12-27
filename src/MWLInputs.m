#import <Cocoa/Cocoa.h>
#import "MWLInputs.h"

bool MWLPollEvents(void)
{
    @autoreleasepool
    {
        NSEvent *event;

        for (;;)
        {
            event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                       untilDate:[NSDate distantPast] 
                                          inMode:NSDefaultRunLoopMode 
                                         dequeue:YES
            ];

            if (!event)
                break;
            

            [NSApp sendEvent:event];
        }
    }

    return true;
} 
