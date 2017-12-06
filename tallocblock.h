#ifndef TALLOCBLOCK_H
#define TALLOCBLOCK_H

#include <cstdlib>
#include "tbintree_real.h"

template <class T>
class TAllocBlock
{
private:
    unsigned int size;
    unsigned int count;
    TBinTree<int, T*> free_blocks;
    TBinTree<int, T*> used_blocks;
public:
    TAllocBlock(unsigned int count) {
        this->size = sizeof(T);
        this->count = count;

        T* memory = malloc(this->size * this->count);
        for (int i = 0; i < count; ++i) {
            this->free_blocks.add(i, memory+i);
        }
    }
    virtual ~TAllocBlock();

    T *alloc();
    void dealloc(T *ptr);
    bool has_free_blocks();
};

#endif // TALLOCBLOCK_H
