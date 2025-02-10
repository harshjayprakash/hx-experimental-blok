#ifndef __BLOK_STATE_H_
#define __BLOK_STATE_H_

#include "direction.h"
#include "square.h"

typedef struct ObjectState__ {
    Square box;
} ObjectState;

void BlokObjectStateInit(
    ObjectState *objstate, const Vector2 boxPosition, const int scaleSize);

void BlokObjectStateMoveBox(ObjectState *objstate, const Direction direction);

void BlokObjectStateFree(ObjectState *objstate);

#endif // !__BLOK_STATE_H_