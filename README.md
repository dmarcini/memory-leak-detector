# Memory leak detector
Memory leak detection tool using overloaded new and delete operators.

To use this tool is needed to include 'memory_leak_detector.hpp' in every
file where memory leak is expected.

Memory leak information format:\
TYPE OF LEAKAGE -> ADDRESS IN MEMORY -> SIZE -> [FILE LOCATION -> FILE INFORMATION]

## Technology
* C++11
* cmake
* make
---

## Requirements
* Operation system: Windows, Linux, macOS
* C++11 compiler
* cmake tool installed
* make tool installed
---

## Building
Example for Linux system
```
mkdir build
cd build
cmake ..
make
```
---

## Sources
This application was inspired by a tool created in the tutorial at:\
https://labex.io/courses/implementing-memory-leak-detector-with-cpp
