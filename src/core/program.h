/**
 * \file program.h
 * \date 13-08-2024
 * \brief Function definitions of the program singleton module.
 *
 * This file contains function definitions for the program module for global use.
 */

#ifndef BLOK_PROGRAM_H
#define BLOK_PROGRAM_H

#define STRICT 1
#include "result.h"
#include <Windows.h>

/**
 * \brief Initialises the program.
 *
 * \param instanceHandle The program's instance handle.
 * \param showFlags How the program will be displayed.
 * \return Result containing if the operation was successful.
 */
BlokResult BlokInit(HINSTANCE instanceHandle, int showFlags);

/**
 * \brief Checks if the program has been initialised.
 *
 * @return If the program has been initialised.
 */
int BlokIsInit(void);

/**
 * \brief Start method for the program.
 *
 * \return Result containing if the operation was successful.
 */
BlokResult BlokStart(void);

/**
 * \brief Retrieves the program's instance handle.
 *
 * \return HINSTANCE The instance handle.
 */
HINSTANCE BlokGetHandle(void);

/**
 * \brief Retrieves the show flag.
 *
 * \return The show flag.
 */
int BlokGetShowFlag(void);

/**
 * \brief Cleans up resources used by the program module.
 *
 * \return Result containing if the operation was successful.
 */
BlokResult BlokFree(void);

#endif