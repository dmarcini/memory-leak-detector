#include "override_delete_operator.hpp"

#include <cstdlib>

#include "memory_list.hpp"


void operator delete(void *ptr) noexcept
{
    delete_memory(ptr, false);
}


void operator delete[](void *ptr) noexcept
{
    delete_memory(ptr, true);
}


void delete_memory(void *ptr, bool is_array)
{
    MemoryList *cur_element {(MemoryList*)((char*)ptr - sizeof(MemoryList))};

    if (cur_element->is_array != is_array) {
        return;
    }

    cur_element->prev->next = cur_element->next;
    cur_element->next->prev = cur_element->prev;

    memory_allocated -= cur_element->size;

    if (cur_element->file) {
        free(cur_element->file);
    }

    free(cur_element);
}
