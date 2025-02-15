#include "dynlist.h"
#include <stdlib.h>
#include <memory.h>

void BlokDynListInit(DynList *list, const long long size)
{
    if (!list) { return; }

    list->arr = calloc(size, sizeof(Node));

    if (!list->arr) { return; }

    list->head = -1;
    list->max = size;
    list->size = 0;
}

int BlokDynListIsFull(const DynList *list)
{
    if (!list) { return -1; }
    if (!list->arr) { return -1; }

    return (list->head == list->max);
}

int BlokDynListIsEmpty(const DynList *list)
{
    if (!list) { return -1; }
    if (!list->arr) { return -1; }

    return (list->head == -1);
}

int BlokDynListAdd(DynList *list, const Node *node)
{
    if (!list) { return -1; }
    if (!node) { return -1; }
    if (BlokDynListIsFull(list)) { return -1; }

    ++list->head;
    ++list->size;

    BlokVectorIICopy(&(list->arr + list->head)->data, node->data);

    return list->head;
}

void BlokDynListFree(DynList *list)
{
    if (!list) { return; }

    if (list->arr != NULL)
    {
        free(list->arr);
    }
}