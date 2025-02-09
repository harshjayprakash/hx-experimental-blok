#ifndef __BLOK_RENDERER_H_
#define __BLOK_RENDERER_H_

#include "drawing.h"
#include "theme.h"

typedef struct Renderer {
    Theme theme;
    SelectColours colours;
    Drawing drawing;
} Renderer;

void BlokRendererInit(Renderer *renderer, const Theme theme);

void BlokRendererFree(Renderer *renderer);

#endif // !__BLOK_RENDERER_H_