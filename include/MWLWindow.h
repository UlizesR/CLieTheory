#ifndef MWL_WINDOW_H
#define MWL_WINDOW_H

#include <objc/objc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct MWLWindow
{
    size_t      width;
    size_t      height;
    const char* title;
    uint32_t    flags;
    id       nswindow;
    id       view; 
} MWLWindow;

typedef uint32_t MWL_WINDOW_STYLE_FLAGS;
enum : uint32_t {
    MWL_WINDOW_MASK_BORDERLESS = 0,
    MWL_WINDOW_MASK_TITLED = 1 << 0,
    MWL_WINDOW_MASK_CLOSABLE = 1 << 1,
    MWL_WINDOW_MASK_MINITARIZABLE = 1 << 2,
    MWL_WINDOW_MASK_RESIZABLE = 1 << 3,
    MWL_WINDOW_MASK_UTILITY_WINDOW = 1 << 4,
    MWL_WINDOW_MASK_DOC_MODAL_WINDOW = 1 << 6,
    MWL_WINDOW_MASK_NONACTIVATING_PANEL = 1 << 7,
    MWL_WINDOW_MASK_UNIFIED_TITLE_AND_TOOLBAR = 1 << 12,
    MWL_WINDOW_MASK_HUD_WINDOW = 1 << 13,
    MWL_WINDOW_MASK_FULSCREEN = 1 << 14,
    MWL_WINDOW_MASK_FULL_SIZE_CONTENT_VIEW = 1 << 15,
    MWL_WINDOW_MASK_DEFAULT = 15
};

MWLWindow* MWLWindowCreate(size_t width, size_t height, const char *title);

void MWLWindowSetFlags(MWLWindow *window, MWL_WINDOW_STYLE_FLAGS flags);

void MWLWindowDestroy(MWLWindow *window);

bool MWLWindowShouldClose(MWLWindow *window);

void MWLCloseWindow(MWLWindow *window);

#endif // MWL_WINDOW_H

