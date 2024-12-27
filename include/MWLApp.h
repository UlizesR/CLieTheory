#ifndef MWL_APP_H
#define MWL_APP_H

#include <objc/objc.h>
#include <stdbool.h>

typedef struct MWLApplication
{
    id app;
    id delegate;
} MWLApplication;

typedef struct MWLAppState
{
    MWLApplication application;
    bool           isRunning;
    const char*    appName;
    
    // MWLWindow*     mainWindow;
} MWLAppState;

bool MWLInitApplication(MWLAppState* appState);

void MWLShutdownApplication(MWLAppState* appState);

#endif // MWL_APP_H

