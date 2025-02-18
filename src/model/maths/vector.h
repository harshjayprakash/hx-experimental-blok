#ifndef _BLOK_VECTOR_H_
#define _BLOK_VECTOR_H_

typedef struct _VectorII {
    int x;
    int y;
} VectorII;

typedef struct _VectorVI {
    int x;
    int y;
    int z;
    int w;
} VectorIV;

void BlokVectorIICopy(VectorII *dest, const VectorII src);

VectorII BlokVectorIIAdd(const VectorII veca, const VectorII vecb);

VectorII BlokVectorIISubtract(const VectorII veca, const VectorII vecb);

VectorII BlokVectorIIMultiply(const VectorII veca, const VectorII vecb);

#endif // _BLOK_VECTOR_H_