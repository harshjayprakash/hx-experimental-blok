#ifndef _BLOK_DYNLIST_H_
#define _BLOK_DYNLIST_H_
#include "vector.h"

typedef struct _Node Node;

typedef struct _Node {
    VectorII data;
} Node;

typedef struct _DynList {
    Node *arr;
    long long head;
    long long size;
    long long max;
} DynList;

#endif // _BLOK_DYNLIST_H_