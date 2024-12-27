#include "MWL.h"
#include <stdio.h>

int main(int argc, char** argv)
{

    // Create an app state
    MWLAppState appState = {0};

    // Initialize the application
    if (!MWLInitApplication(&appState))
    {
        fprintf(stderr, "Failed to initialize application.\n");
        return -1;
    }

    appState.appName = "MWL Test App";

    // Optionally create a main window
    MWLWindow* mainWindow = MWLWindowCreate(800, 600, appState.appName);
    if (!mainWindow)
    {
        fprintf(stderr, "Failed to create main window.\n");
    }

    // Main loop (poll for events, do rendering, etc.)
    while (MWLWindowShouldClose(mainWindow))
    {
        MWLPollEvents();
        // ... do something ...
    }
    // Cleanup
    MWLWindowDestroy(mainWindow);
    MWLShutdownApplication(&appState);

    return 0;
}