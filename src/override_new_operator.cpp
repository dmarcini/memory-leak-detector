#include "override_new_operator.hpp"

#include <cstdlib>
#include <cstring>

#include "memory_list.hpp"


void* operator new(size_t size)
{
    return allocate_memory(size, false, nullptr, 0);
}


void* operator new(size_t size, char *file, uint line)
{
    return allocate_memory(size, false, file, line);
}


void* operator new[](size_t size)
{
    return allocate_memory(size, true, nullptr, 0);
}


void* operator new[](size_t size, char *file, uint line)
{
    return allocate_memory(size, true, file, line);
}


void* allocate_memory(size_t size, bool is_array, char *file, uint line)
{
    size_t new_size {sizeof(MemoryList) + size};

    MemoryList *new_element {(MemoryList*)malloc(new_size)};

    new_element->next = root.next;
    new_element->prev = &root;
    new_element->size = size;
    new_element->is_array = is_array;
    new_element->file = nullptr;

    if (file) {
        new_element->file = (char*)malloc(strlen(file) + 1);

        strcpy(new_element->file, file);
    }

    new_element->line = line;

    root.next->prev = new_element;
    root.next = new_element;

    memory_allocated += size;

    return (char*)new_element + sizeof(MemoryList);
}
