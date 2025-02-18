#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_

#include "vector.h"

typedef struct _Node Node;

typedef struct _Node {
    VectorII data;
} Node;

typedef struct _DynList {
    Node *arr;
    long head;
    long size;
    long max;
} DynList;

void BlokDynListInit(DynList *list, const long size);

int BlokDynListIsFull(const DynList *list);

int BlokDynListIsEmpty(const DynList *list);

long BlokDynListAdd(DynList *list, const Node *node);

void BlokDynListFree(DynList *list);

#endif // _BLOK_DYNLIST_H_