#include "Helper.hpp"

void AssignString(char* dest, const char* str, size_t length)
{
    std::strncpy(dest, str, length - 1);
    dest[length] = '\0';
}