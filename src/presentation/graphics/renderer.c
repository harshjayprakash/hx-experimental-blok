#include "renderer.h"

#define ___BLOK_VALID_THEME(n) \
    (n >= BLOK_THEME_MIN_BOUND && n <= BLOK_THEME_MAX_BOUND)

#define ___BLOK_DISREGARD_THEME(disregardTheme) \
    (disregardTheme) ? BLOK_THEME_UNSET : theme

void BlokRendererInit(Renderer *renderer, const Theme theme)
{
    if (!renderer) { return; }

    if (!___BLOK_VALID_THEME(theme))
    {
        renderer->theme = ___BLOK_DISREGARD_THEME(TRUE);
    }

    BlokThemeSet(&renderer->colours, renderer->theme);
    BlokDrawingInit(&renderer->drawing, &renderer->colours);
}

void BlokRendererFree(Renderer *renderer)
{
    if (!renderer) { return; }

    BlokDrawingFree(&renderer->drawing);
}