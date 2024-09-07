/*=================================================================================================
    ScenarioControl.cpp
=================================================================================================*/

#include "ScenarioControl.hpp"

/*=================================================================================================
    Funtion Implementation
=================================================================================================*/

int Scenario_control(int choice)
{
    switch(choice)
    {
        case 0:
            break;
        case 1:
            Calculate_gpa();
            break;
        case 2:
            Aim_gpa();
            break;
        case 3:
            Display_transcript();
            break;
        case 4:
            Edit_transcript();
            break;
        default:
            cout << "Error: Not an available option" << endl;
            return 0;
    }
    return 1;
}

int Calculate_gpa()
{
    cout << "Need to be implemented" << endl;
    return 1;
}

int Aim_gpa()
{
    cout << "Need to be implemented" << endl;
    return 1;
}

int Display_transcript()
{
    cout << "Current transcript:" << endl << endl;

    cout << left 
         << setw(3) << " "
         << setw(7) << "Grade"
         << setw(6) << "Course"
         << setw(6) << "Name"
         << setw(33) << " "
         << setw(7) << "Semester"
         << setw(5) << " "
         << endl;

    int count = DisplayAllCourses();

    if (count != 0)
    {
        cout << endl << "Total courses displayed: " << count << endl;
    } 
    
    pause();
    return 1;
}

int Edit_transcript()
{
    cout << "Need to be implemented" << endl;
    return 1;
}