/*=================================================================================================
    main.cpp
=================================================================================================*/

#include <iostream>
#include "UI.hpp"
#include "Course.hpp"

int main()
{
    if (!Initialization())
    {
        cout << "Failed to load file" << endl;
        return 0;
    }
    if (!ActivateUI())
    {
        cout << "Failed to bring UI" << endl;
        return 0;
    }   
}