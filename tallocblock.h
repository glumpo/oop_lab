#ifndef TALLOCBLOCK_H
#define TALLOCBLOCK_H

#include <cstdlib>
#include <iostream>
#include "tbintree.h"

template <class T>
class TAllocBlock
{
private:
    unsigned int size;
    unsigned int count;
    unsigned int max_key_free;
    unsigned int max_key_used;
    TBinTree<int, T*> free_blocks;
    TBinTree<int, T*> used_blocks;
    T *base_memory;
public:
    TAllocBlock(unsigned int count) {
        this->size = sizeof(T);
        this->count = count;

        this->base_memory = (T*) malloc(this->size * this->count);
        for (unsigned int i = 0; i < count; ++i) {
            this->free_blocks.add(i, this->base_memory+i);
        }
        this->max_key_free = this->free_blocks.max_key();
        this->max_key_used = 0;
    }
    virtual ~TAllocBlock() {
        free(this->base_memory);
    }

    T *alloc() {
        std::cout << "ALLOCATING...\n";
        if (this->free_blocks.is_empty())
            return nullptr;

        auto res_p = this->free_blocks.pop(this->max_key_free);
        this->max_key_free = this->free_blocks.max_key();

        this->max_key_used += 1;
        this->used_blocks.add(this->max_key_used, res_p);
        return res_p;
    }

    void dealloc(T *ptr) {
        int key_of_ptr;
        if (!this->used_blocks.find_first_key_by_value(ptr, &key_of_ptr))
            return;

        this->used_blocks.pop(key_of_ptr);
        this->free_blocks.add(this->max_key_free + 1, ptr);
        this->max_key_free += 1;
    }

    bool has_free_blocks() {
        return this->max_key_free == 0;
    }
};

#endif // TALLOCBLOCK_H
