#ifndef _BLOK_STATE_H_
#define _BLOK_STATE_H_

#include "maths/direction.h"
#include "objects/square.h"
#include "maths/dynlist.h"

typedef struct _State {
    Square box;
    DynList obstructives;
} State;

void BlokStateInit(State *state);

void BlokStateFree(State *state);

void BlokStateMoveBox(State *state, const Direction direction);

#endif // _BLOK_STATE_H_