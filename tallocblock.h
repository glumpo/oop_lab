#ifndef TALLOCBLOCK_H
#define TALLOCBLOCK_H


class TAllocBlock
{
private:
    unsigned int size;
    unsigned int count;
public:
    TAllocBlock(unsigned int size, unsigned int count);
    virtual ~TAllocBlock();

    void *alloc();
    void dealloc(void *ptr);
    bool has_free_blocks();
};

#endif // TALLOCBLOCK_H
