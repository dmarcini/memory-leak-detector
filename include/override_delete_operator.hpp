#ifndef OVERRIDE_DELETE_OPERATOR_HPP_
#define OVERRIDE_DELETE_OPERATOR_HPP_


void operator delete(void *ptr) noexcept;
void operator delete[](void *ptr) noexcept;

void delete_memory(void *ptr, bool is_array);

#endif // OVERRIDE_DELETE_OPERATOR_HPP_