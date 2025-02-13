#ifndef __BLOK_VECTOR2_H_
#define __BLOK_VECTOR2_H_

typedef struct Vector2__ {
    int x;
    int y;
} Vector2;

Vector2 BlokVector2MultiplyByScalar(const Vector2 vec, int scalar);

Vector2 BlokVector2Add(const Vector2 veca, const Vector2 vecb);

Vector2 BlokVector2Subtract(const Vector2 veca, const Vector2 vecb);

void BlokVector2Copy(Vector2 *dest, const Vector2 src);

#endif // !__BLOK_VECTOR2_H_
