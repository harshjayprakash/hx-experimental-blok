#ifndef __BLOK_DIRECTION_H_
#define __BLOK_DIRECTION_H_

#include "vector2.h"

typedef enum Direction__ {
    BLOK_COMPASS_NORTH = 12,
    BLOK_COMPASS_EAST = 3,
    BLOK_COMPASS_SOUTH = 6,
    BLOK_COMPASS_WEST = 9,
} Direction;

Vector2 BlokCompassToVector2(const Direction direction);

#endif // !__BLOK_DIRECTION_H_