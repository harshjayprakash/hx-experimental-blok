#include "vector.h"

void BlokVectorIICopy(VectorII *dest, const VectorII src)
{
    if (!dest) { return; }

    dest->x = src.x;
    dest->y = src.y;
}

VectorII BlokVectorIIAdd(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x+vecb.x, veca.y+vecb.y};
}

VectorII BloKVectorIISubtract(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x-vecb.x, veca.y-vecb.y};
}

VectorII BloKVectorIIMultiply(const VectorII veca, const VectorII vecb)
{
    return (VectorII) {veca.x*vecb.x, veca.y*vecb.y};
}