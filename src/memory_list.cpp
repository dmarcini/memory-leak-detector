#include "memory_list.hpp"


MemoryList root {
    &root,
    &root,
    0,
    false,
    nullptr,
    0
};

ulong memory_allocated {0};
