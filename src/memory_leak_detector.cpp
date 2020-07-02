#include "memory_leak_detector.hpp"

#include <cstdlib>
#include <iostream>

#include "memory_list.hpp"


uint MemoryLeakDetector::call_counter {0};


MemoryLeakDetector::MemoryLeakDetector() noexcept {
    ++call_counter;
}


MemoryLeakDetector::~MemoryLeakDetector() noexcept {
    if (!(--call_counter)) {
        detect_memory_leak();
    }
}


MemoryLeakDetector& MemoryLeakDetector::get_instance()
{
    static MemoryLeakDetector memory_leak_detector;

    return memory_leak_detector;
}


uint MemoryLeakDetector::detect_memory_leak() noexcept
{
    uint counter {0};
    MemoryList *ptr {root.next};

    while (ptr && ptr != &root) {
        if (ptr->is_array) {
            std::cout << "Leaking [] memory -> ";
        } else {
            std::cout << "Leaking memory -> ";
        }

        std::cout << "address: " << ptr << " -> size: " << ptr->size << "B";

        if (ptr->file) {
            std::cout << " -> located in " << ptr->file << ", line  "
                      << ptr->line << '\n';
        } else {
            std::cout << " -> no file info\n";
        }

        ++counter;

        ptr = ptr->next;
    }

    if (counter) {
        std::cout << "\nExisting " << counter << " memory leaking behavior, "
                  << memory_allocated << "B in total.\n\n";
    }

    return counter;
}
