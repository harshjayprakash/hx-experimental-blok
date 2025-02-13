#include "vector2.h"

Vector2 BlokVector2MultiplyByScalar(const Vector2 vec, int scalar)
{
    return (Vector2) {vec.x * scalar, vec.y * scalar};
}

Vector2 BlokVector2Add(const Vector2 veca, const Vector2 vecb)
{
    return (Vector2) {veca.x + vecb.x, veca.y + vecb.y};
}

Vector2 BlokVector2Subtract(const Vector2 veca, const Vector2 vecb)
{
    return (Vector2) {veca.x - vecb.x, veca.y - vecb.y};
}

void BlokVector2Copy(Vector2 *dest, const Vector2 src)
{
    if (!dest) { return; }

    dest->x = src.x;
    dest->y = src.y;
}