#ifndef HELPER_HPP
#define HELPER_HPP

/*=================================================================================================
    Helper.hpp 
=================================================================================================*/

#include <iostream>
#include <cstring>
#include <limits>

/*=================================================================================================
    Functions
=================================================================================================*/

/*
Assign a character array 'str' to 'dest' with terminating character '\n' at the end of the array
-------------------------------------------------------------------------------------------------*/
void AssignString(
    char* dest,         // destination character array 
    const char* str,    // assigns the character array 'str' to the 'dest'
    size_t length       // the size of 'str' character array
);

/*
Pauses the system flow. Allow user to continue by pressing the enter key on their keyboard. 
-------------------------------------------------------------------------------------------------*/
void pause();

#endif