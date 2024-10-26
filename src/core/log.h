/**
 * \file log.h
 * \date 13-08-2024
 * \brief Function definitions and types for logging.
 *
 * This file contains the functions and types for logging functionality.
 */

#ifndef BLOK_LOG_H
#define BLOK_LOG_H

#include "result.h"

/**
 * \brief Enumeration to indicate a log level.
 */
typedef enum __BlokLogLevel
{
    BlokInformation = 0x0000001, ///< Informative Log Level
    BlokWarning = 0x0000002,     ///< Warning Log Level
    BlokError = 0x0000003,       ///< Error Log Level
    BlokUnknown = 0x0000000,     ///< Unknown Log Level
} BlokLogLevel;

/**
 * \brief Enumeration of the method of logging.
 */
typedef enum __BlokLogTechnique
{
    BlokFile = 0x0000001,    ///< Logging to a file
    BlokConsole = 0x0000010, ///< Logging to the console
} BlokLogTechnique;

/**
 * \brief Initialises the logger.
 *
 * \param technique The method of logging.
 */
void BlokInitLogger(const BlokLogTechnique technique);

/**
 * \brief Log a message.
 *
 * \param level The log level.
 * \param information The result containing the message.
 */
void BlokLog(const BlokLogLevel level, const BlokResult information);

/**
 * \brief Log a message then return the result.
 *
 * \param level The log level.
 * \param information The result containing the message.
 * \return The result containing the message.
 */
BlokResult BlokLogAndReturn(const BlokLogLevel level, const BlokResult information);

/**
 * \brief Cleans up resources used by the logger.
 */
void BlokFreeLogger(void);

#endif