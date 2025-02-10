#include "vector2.h"

Vector2 BlokVector2MultiplyByScalar(const Vector2 vec, int scalar)
{
    return (Vector2) {vec.x * scalar, vec.y * scalar};
}

Vector2 BlokVector2Add(const Vector2 veca, const Vector2 vecb)
{
    return (Vector2) {veca.x + vecb.x, veca.y + vecb.y};
}

void BlokVector2AddPtr(Vector2 *dest, const Vector2 change)
{
    if (!dest) { return; }

    dest->x += change.x;
    dest->y += change.y;
}

Vector2 BlokVector2Subtract(const Vector2 veca, const Vector2 vecb)
{
    return (Vector2) {veca.x - vecb.x, veca.y - vecb.y};
}

void BlokVector2SubtractPtr(Vector2 *dest, const Vector2 change)
{
    if (!dest) { return; }

    dest->x -= change.x;
    dest->y -= change.y;
}