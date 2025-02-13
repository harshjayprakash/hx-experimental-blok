#ifndef __BLOK_DYNLIST_H_
#define __BLOK_DYNLIST_H_

#include "vector2.h"

typedef struct ListNode__ {
    Vector2 data;
} ListNode;

typedef struct DynamicList__ {
    ListNode *arr;
    long long head;
    long long size;
    long long max;
} DynamicList;

void BlokDynListInit(DynamicList *dynList, const long long allocateSize);

long long BlokDynListPush(DynamicList *dynList, const ListNode *node);

void BlokDynListGetNode(DynamicList *dynList, const long long index);

long long BlokDynListGetIndex(DynamicList *dynList, const ListNode *node);

void BlokDynListFree(DynamicList *dynList);

#endif // !__BLOK_DYNLIST_H_