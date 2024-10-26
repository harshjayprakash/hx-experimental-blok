/**
 * \file vector.h
 * \date 13-08-2024
 * \brief Functions definitions and structures for the vector.
 *
 * This file contains the structures for the vector, a dynamically expanding linked list
 * and another structure for the nodes stored in the list. There are function definitions
 * to conduct operations on the vector.
 */

#ifndef BLOK_VECTOR_H
#define BLOK_VECTOR_H

#include "../../core/log.h"
#include "../../core/result.h"
#include "position.h"
#include <stdlib.h>

/**
 * \brief Models a node in the vector.
 */
typedef struct __BlokNode
{
    BlokPosition position; ///< Stored Position
    int indexed;           ///< Indexed Position
} BlokNode;

/**
 * \brief Models a vector (linked list).
 */
typedef struct __BlokVector
{
    BlokNode *array; ///< The Linked List
    size_t max;      ///< The Maximum Size
    size_t size;     ///< The Current Size
    long long head;  ///< The Pointer Position
} BlokVector;

/**
 * \brief Creates a new vector.
 *
 * \param size The size of the vector array.
 * \return A new stack allocated vector.
 *
 * \warning Though stack allocated, the array has been heap allocated memory and must be
 *          freed through the `BlokDestroyVector` function when exiting the program.
 */
BlokVector BlokCreateVector(size_t size);

/**
 * \brief Generates a new size based on the input.
 *
 * \param size The current size.
 * \return The new recommended size.
 */
size_t BlokGenerateNewVectorSize(size_t size);

/**
 * \brief Re-sizes the vector array.
 *
 * \param vector The vector to be re-sized.
 * \param newSize The new size.
 * \return A result object denoting if the operation was successful.
 */
BlokResult BlokReSizeVector(BlokVector *vector, size_t newSize);

/**
 * \brief Checks if the vector is full.
 *
 * \param vector The vector to be checked.
 * \return If the vector is full.
 *
 * \retval 0: Not Full.
 * \retval 1: Full.
 * \retval -1: Error Occured.
 */
int BlokIsVectorFull(const BlokVector *vector);

/**
 * \brief Checks if the vector is empty.
 *
 * \param vector The vector to be checked.
 * \return If the vector is full.
 *
 * \retval 0: Not Empty.
 * \retval 1: Empty.
 * \retval -1: Error Occured.
 */
int BlokIsVectorEmpty(const BlokVector *vector);

/**
 * \brief Add a node to the vector.
 *
 * \param vector The vector to be added to.
 * \param node The node to be added.
 * \return A result object denoting if the operation was successful.
 */
BlokResult BlokPushNode(BlokVector *vector, const BlokNode node);

/**
 * \brief Get the node as a pointer.
 *
 * \param vector The vector to be checked.
 * \param index The index of the node.
 * \return The pointer to the node.
 *
 * \warning You must not free the memory returned.
 */
BlokNode *BlokGetNodeAsPointer(const BlokVector *vector, const int index);

/**
 * \brief Clears all the nodes in the vector.
 *
 * \param vector The vector to be cleared
 * \return A result denoting if the operation was successful.
 */
BlokResult BlokClearVector(BlokVector *vector);

/**
 * \brief Checks if the node provided exists.
 *
 * \param vector The vector to be checked.
 * \param node The node to check for.
 * \return If the node exists.
 *
 * \retval 0: Does Not Exist or Error Occured.
 * \retval 1: Node Exists.
 */
int BlokNodeExists(const BlokVector *vector, const BlokNode node);

/**
 * \brief Prints the vector to the console.
 *
 * \param vector The vector to the printed.
 */
void BlokPrintVector(const BlokVector *vector);

/**
 * \brief Cleans up resources used by the vector.
 *
 * \param vector The vector to be destroyed.
 *
 * \warning This must be used to free the memory allocated for the array.
 */
void BlokDestroyVector(BlokVector *vector);

#endif