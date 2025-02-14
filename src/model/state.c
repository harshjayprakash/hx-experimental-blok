#include "state.h"
#include "maths/vector.h"

void BlokStateInit(State *state)
{
    if (!state) { return; }

    VectorII defaultBoxState = {0, 0};
    VectorII defaultBoxSize = {15, 15};
    BlokVectorIICopy(&state->box.size, defaultBoxSize);
    BlokVectorIICopy(&state->box.position, defaultBoxState);
}

void BlokStateFree(State *state)
{
    if (!state) { return; }
}

void BlokStateMoveBox(State *state, const Direction direction)
{
    if (!state) { return; }

    VectorII vector = BlokDirectionToVector(direction);
    VectorII scaled = BloKVectorIIMultiply(vector, state->box.size);
    VectorII newpos = BlokVectorIIAdd(state->box.position, scaled);
    BlokVectorIICopy(&state->box.position, newpos);
}