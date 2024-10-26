/**
 * \file args.h
 * \date 18-08-2024
 * \brief Function prototypes for processing arguments.
 *
 * This file contains function prototypes for argument processing and retrieving stored 
 * arguments.
 */

#ifndef BLOK_ARGS_H
#define BLOK_ARGS_H

#include "result.h"

/**
 * \brief Processes the arguments provided on execution.
 *
 * \return Result containing if the operation was successful.
 */
BlokResult BlokProcessArguments(void);

/**
 * \brief Gets the block scaling.
 *
 * \return The block size scale.
 */
int BlokGetBlockScale(void);

#endif