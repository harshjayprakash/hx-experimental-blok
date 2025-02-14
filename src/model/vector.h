#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _VectorII {
    int x;
    int y;
} VectorII;

void BlokVectorIICopy(VectorII *dest, const VectorII src);

VectorII BlokVectorIIAdd(const VectorII veca, const VectorII vecb);

VectorII BloKVectorIISubtract(const VectorII veca, const VectorII vecb);

VectorII BloKVectorIIMultiply(const VectorII veca, const VectorII vecb);

#endif // _BLOK_VECTOR_H_