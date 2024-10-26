/**
 * \file vector.c
 * \date 13-08-2024
 * \brief Implementation of vector related functions.
 *
 * This file contains the vector function operations as defined in the header file.
 */

#include "vector.h"
#include "position.h"
#include <memory.h>

BlokVector BlokCreateVector(size_t size)
{
    BlokLog(BlokInformation, BlokCreateResult(BlokNone, L"Initialising Vector."));

    BlokVector vector = (BlokVector){NULL, size, 0, (-1)};

    vector.array = calloc(vector.max, sizeof(BlokNode));

    if (!vector.array)
    {
        BlokLog(BlokError,
                BlokCreateResult(BlokNullPtr, L"Vector Initialisation Failed"));
    }

    return vector;
}

size_t BlokGenerateNewVectorSize(size_t size)
{
    return size + (size * 2);
}

BlokResult BlokReSizeVector(BlokVector *vector, size_t newSize)
{
    BlokLog(BlokInformation,
            BlokCreateResult(BlokNone, L"Attempting to Re-sizing Vector."));

    if (!vector)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokNullPtr, L"Vector Re-size Failed: Null Pointer Error."));
    }

    if (!vector->array)
    {
        return BlokLogAndReturn(
            BlokError, BlokCreateResult(BlokNullPtr,
                                        L"Vector Re-size Failed: Vector Array is Null."));
    }

    if (newSize + 1 < vector->max)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokOutOfRange, L"Vector Re-size Failed: Invalid Size."));
    }

    BlokNode *newMemory = realloc(vector->array, newSize * sizeof(BlokNode));

    if (!newMemory)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokOutOfRange,
                             L"Vector Re-size Failed: Memory Allocation Error."));
    }

    vector->array = newMemory;
    vector->max = newSize;

    return BlokLogAndReturn(BlokInformation,
                            BlokCreateResult(BlokNone, L"Re-sized Vector."));
}

int BlokIsVectorFull(const BlokVector *vector)
{
    if (!vector)
    {
        BlokLog(BlokError,
                BlokCreateResult(BlokNullPtr,
                                 L"Vector Full Check Failed: Null Pointer Error."));
        return -1;
    }

    if (vector->head == vector->max - 1)
    {
        return 1;
    }

    return 0;
}

int BlokIsVectorEmpty(const BlokVector *vector)
{
    if (!vector)
    {
        BlokLog(BlokError,
                BlokCreateResult(BlokNullPtr,
                                 L"Vector Empty Check Failed: Null Pointer Error."));
        return -1;
    }

    if (vector->head == -1)
    {
        return 1;
    }

    return 0;
}

BlokResult BlokPushNode(BlokVector *vector, const BlokNode node)
{
    if (!vector)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokNullPtr, L"Node Push Failed: Null Pointer Error."));
    }

    if (!vector->array)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokNullPtr, L"Node Push Failed: Vectory Array is Null."));
    }

    if (BlokIsVectorFull(vector) == 1)
    {
        BlokReSizeVector(vector, BlokGenerateNewVectorSize(vector->max));
    }

    vector->head++;
    vector->size++;
    (vector->array + vector->head)->indexed = 1;
    BlokCopyPosition(&((vector->array + vector->head)->position), node.position);

    return BlokLogAndReturn(BlokInformation, BlokCreateResult(BlokNone, L"Node Pushed."));
}

BlokNode *BlokGetNodeAsPointer(const BlokVector *vector, const int index)
{
    if (!vector)
    {
        BlokLog(
            BlokError,
            BlokCreateResult(BlokNullPtr, L"Node via Index Failed: Null Pointer Error."));
        return NULL;
    }

    if (!vector->array)
    {
        BlokLog(BlokError,
                BlokCreateResult(BlokNullPtr,
                                 L"Node via Index Failed: Vectory Array is Null."));
        return NULL;
    }

    if (index > vector->max - 1 || index < 0)
    {
        BlokLog(BlokError, BlokCreateResult(BlokOutOfRange,
                                            L"Node via Index Failed: Out of Range."));
        return NULL;
    }

    return (vector->array + index);
}

BlokResult BlokClearVector(BlokVector *vector)
{
    if (!vector)
    {
        return BlokLogAndReturn(
            BlokError, BlokCreateResult(BlokNullPtr,
                                        L"Clearing Vector Failed: Null Pointer Error."));
    }

    if (!vector->array)
    {
        return BlokLogAndReturn(
            BlokError,
            BlokCreateResult(BlokNullPtr,
                             L"Clearing Vector Failed: Vector Array is Null."));
    }

    for (int index = 0; index < vector->max; index++)
    {
        BlokNode *nodePtr = BlokGetNodeAsPointer(vector, index);

        if (!nodePtr)
        {
            continue;
        }

        nodePtr->indexed = 0;
        BlokSetPosition(&(nodePtr->position), -1, -1);
    }

    vector->size = 0;
    vector->head = -1;

    return BlokLogAndReturn(BlokInformation,
                            BlokCreateResult(BlokNone, L"Vector Cleared."));
}

int BlokNodeExists(const BlokVector *vector, const BlokNode node)
{
    if (!vector)
    {
        BlokLog(BlokError,
                BlokCreateResult(BlokNullPtr,
                                 L"Node Exists Check Failed: Null Pointer Error."));
        return 0;
    }

    if (!vector->array)
    {
        BlokLog(BlokError,
                BlokCreateResult(BlokNullPtr,
                                 L"Node Exists Check Failed: Vector Array is Null."));
        return 0;
    }

    for (int index = 0; index < vector->size; index++)
    {
        BlokNode *nodePtr = BlokGetNodeAsPointer(vector, index);

        if (node.position.x == nodePtr->position.x &&
            node.position.y == nodePtr->position.y)
        {
            return 1;
        }
    }

    return 0;
}

void BlokPrintVector(const BlokVector *vector)
{
    if (!vector)
    {
        BlokLog(BlokError, BlokCreateResult(BlokNullPtr,
                                            L"Vector Print Failed: Null Pointer Error."));
        return;
    }

    if (!vector->array)
    {
        BlokLog(
            BlokError,
            BlokCreateResult(BlokNullPtr, L"Vector Print Failed: Vector Array is Null."));
        return;
    }

    (void)wprintf(L"Vector: { Max: %llu, Size: %llu, Head: %d\n", vector->max,
                  vector->size, vector->head);

    for (int index = 0; index < vector->max; index++)
    {
        BlokNode *nodePtr = BlokGetNodeAsPointer(vector, index);

        if (!nodePtr)
        {
            continue;
        }

        (void)wprintf(L"{ { X: %d, Y: %d }, Indexed: %d }\n", nodePtr->position.x,
                      nodePtr->position.y, nodePtr->indexed);
    }
}

void BlokDestroyVector(BlokVector *vector)
{
    if (!vector)
    {
        BlokLog(BlokError, BlokCreateResult(BlokNullPtr, L"Vector Destruction Failure."));
        return;
    }

    free(vector->array);
    BlokLog(BlokInformation, BlokCreateResult(BlokNone, L"Cleaned Up Vector Resources."));
}