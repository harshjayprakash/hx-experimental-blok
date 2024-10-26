/**
 * \file direction.h
 * \date 01-09-2024
 * \brief Enumeration for denoting direction.
 * 
 * This file contains an enumeration that represents direction via the compass rose.
 */

#ifndef BLOK_DIRECTION_H
#define BLOK_DIRECTION_H

/**
 * \brief Models a compass rose.
 */
typedef enum __BlokDirection
{
    BlokNorth = 12, ///< The North Direction (Up)
    BlokEast = 3,   ///< The East Direction (Right)
    BlokSouth = 6,  ///< The South Direction (Down)
    BlokWest = 9,   ///< The West Direction (Left)
} BlokDirection;

#endif