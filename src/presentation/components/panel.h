#ifndef _BLOK_PANEL_H_
#define _BLOK_PANEL_H_

#include "../../model/maths/vector.h"
#include <Windows.h>

typedef struct _Panel {
    RECT region;
    VectorII margin;
    VectorII position;
    VectorII size;
} Panel;

void BlokPanelUpdateEx(
    Panel *panel, const RECT *windowRegion, const VectorII *size, const VectorII *margin);

void BlokPanelUpdate(Panel *panel, const RECT *windowRegion);

#endif // _BLOK_PANEL_H_