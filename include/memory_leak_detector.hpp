#ifndef MEMORY_LEAK_DETECTOR_HPP_
#define MEMORY_LEAK_DETECTOR_HPP_

#include <cstdlib>


class MemoryLeakDetector
{
public:
    MemoryLeakDetector(const MemoryLeakDetector&) = delete;
    MemoryLeakDetector& operator=(const MemoryLeakDetector&) = delete;
    MemoryLeakDetector(MemoryLeakDetector&&) = delete;
    MemoryLeakDetector& operator=(MemoryLeakDetector&&) = delete;

    ~MemoryLeakDetector() noexcept;

    static MemoryLeakDetector& get_instance();
private:
    MemoryLeakDetector() noexcept;

    static uint detect_memory_leak() noexcept;

    static uint call_counter;
};

//static auto &memory_leak_detector = MemoryLeakDetector::get_instance();

#endif // MEMORY_LEAK_DETECTOR_HPP_
