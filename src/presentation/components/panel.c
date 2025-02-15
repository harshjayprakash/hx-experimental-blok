#include "panel.h"

void BlokPanelUpdateEx(
    Panel *panel, const RECT *windowRegion, const VectorII *size, const VectorII *margin)
{
    if (!panel) { return; }
    if (!windowRegion) { return; }

    if (size != (VectorII *) 0)
    {
        BlokVectorIICopy(&panel->size, *size);
    }

    if (margin != (VectorII *) 0)
    {
        BlokVectorIICopy(&panel->margin, *margin);
    }

    panel->region.left = windowRegion->left + panel->margin.x;
    panel->region.top = (windowRegion->bottom - panel->size.y) - panel->margin.y;
    panel->region.right = (windowRegion->left + panel->size.x) - panel->margin.x;
    panel->region.bottom = windowRegion->bottom - panel->margin.y;
}

void BlokPanelUpdate(Panel *panel, const RECT *windowRegion)
{
    if (!panel) { return; }
    if (!windowRegion) { return; }

    BlokPanelUpdateEx(panel, windowRegion, NULL, NULL);
}