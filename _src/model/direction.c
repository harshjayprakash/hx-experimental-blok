#include "direction.h"

Vector2 BlokCompassToVector2(const Direction direction)
{
    switch (direction)
    {
    case BLOK_COMPASS_NORTH: return (Vector2){0,-1};
    case BLOK_COMPASS_EAST: return (Vector2){1, 0};
    case BLOK_COMPASS_SOUTH: return (Vector2){0, 1};
    case BLOK_COMPASS_WEST: return (Vector2){-1, 0};
    default: return (Vector2){0, 0};
    }
}