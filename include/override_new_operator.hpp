#ifndef OVERRIDE_NEW_OPERATOR_HPP_
#define OVERRIDE_NEW_OPERATOR_HPP_

#include <cstdlib>


void* operator new(size_t size);
void* operator new(size_t size, char *file, uint line);
void* operator new[](size_t size);
void* operator new[](size_t size, char *file, uint line);

void* allocate_memory(size_t size, bool is_array, char *file, uint line);

#endif // OVERRIDE_NEW_OPERATOR_HPP_
