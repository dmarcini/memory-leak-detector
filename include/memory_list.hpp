#ifndef MEMORY_LIST_HPP_
#define MEMORY_LIST_HPP_

#include <cstdlib>


struct MemoryList
{
    struct MemoryList *next;
    struct MemoryList *prev;
    size_t size;
    bool is_array;
    char *file;
    uint line;
};

extern MemoryList root;
extern ulong memory_allocated;

#endif // MEMORY_LIST_HPP_