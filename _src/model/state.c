#include "state.h"

void BlokObjectStateInit(
    ObjectState *objstate, const Vector2 boxPosition, const int scaleSize)
{
    if (!objstate) { return; }

    objstate->box.position = boxPosition;
    objstate->box.size = (Vector2) {scaleSize, scaleSize};
}

void BlokObjectStateMoveBox(ObjectState *objstate, const Direction direction)
{
    if (!objstate) { return; }

    Vector2 vector = BlokCompassToVector2(direction);
    Vector2 scaled = BlokVector2MultiplyByScalar(vector, objstate->box.size.x);
    Vector2 newpos = BlokVector2Add(objstate->box.position, scaled);

    BlokVector2Copy(&objstate->box.position, newpos);
}

void BlokObjectStateFree(ObjectState *objstate)
{
    if (!objstate) { return; }
}