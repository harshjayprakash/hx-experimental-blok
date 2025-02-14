#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

typedef struct _Viewport {
    int unused;
} Viewport;

void BlokViewportInit(Viewport *viewport);

void BlokViewportFree(Viewport *viewport);

#endif // _BLOK_VIEWPORT_H_