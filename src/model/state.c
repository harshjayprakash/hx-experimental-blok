#include "state.h"
#include "maths/vector.h"

void BlokStateInit(State *state)
{
    if (!state) { return; }

    VectorII defaultBoxState = {0, 0};
    VectorII defaultBoxSize = {15, 15};
    BlokVectorIICopy(&state->box.size, defaultBoxSize);
    BlokVectorIICopy(&state->box.position, defaultBoxState);

    BlokDynListInit(&state->obstructives, 10);
}

void BlokStateFree(State *state)
{
    if (!state) { return; }

    BlokDynListFree(&state->obstructives);
}

void BlokStateMoveBox(State *state, const Direction direction)
{
    if (!state) { return; }

    VectorII vector = BlokDirectionToVector(direction);
    VectorII scaled = BlokVectorIIMultiply(vector, state->box.size);
    VectorII newpos = BlokVectorIIAdd(state->box.position, scaled);
    BlokVectorIICopy(&state->box.position, newpos);
}