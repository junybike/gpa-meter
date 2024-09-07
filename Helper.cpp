/*=================================================================================================
    Helper.cpp
=================================================================================================*/

#include "Helper.hpp"

using namespace std;

/*=================================================================================================
    Function Implementation
=================================================================================================*/

void AssignString(char* dest, const char* str, size_t length)
{
    std::strncpy(dest, str, length - 1);
    dest[length] = '\0';
}

void pause()
{
    cin.ignore();
    cout << "Press [Enter] to continue..." << flush;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
}