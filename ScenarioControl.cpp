/*=================================================================================================
    ScenarioControl.cpp
=================================================================================================*/

#include "ScenarioControl.hpp"

/*=================================================================================================
    Funtion Implementation
=================================================================================================*/

int Scenario_control(int choice, int subchoice)
{
    switch(choice)
    {
        case 0:
            break;

        case 1:
            return Calculate_gpa();
            break;

        case 2:
            return Aim_gpa();
            break;
            
        case 3:
            return Display_transcript();
            break;

        case 4:
            if (subchoice == 1) return AddCourse();
            if (subchoice == 2) return EditCourse();
            if (subchoice == 3) return DeleteCourse(); 
            break;

        default:
            cout << "Error: Not an available option" << endl;
            return 0;
    }
    return 1;
}

int Calculate_gpa()
{
    cout << "===Calculate GPA===" << endl << endl;
    
    float* gpa_list = CalculateGPA();

    if (gpa_list[0] != gpa_list[0]) 
    {
        cout << "Empty transcript" << endl << endl;
        return 0;
    }
    
    cout << "Cumulative GPA: " << gpa_list[0] << endl;
    
    if (gpa_list[1] != gpa_list[1])
    {
        cout << "No lower level division courses taken" << endl;    
    }
    else cout << "Upper level division GPA: " << gpa_list[1] << endl;

    if (gpa_list[2] != gpa_list[2])
    {
        cout << "No upper level division courses taken" << endl;    
    }
    else cout << "Lower level division GPA: " << gpa_list[2] << endl << endl;

    delete[] gpa_list;

    pause();

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
         << setw(5) << "Unit"
         << setw(7) << "Semester"
         << setw(5) << " "
         << endl;

    int count = DisplayAllCourses();

    if (count != 0)
    {
        cout << endl << "Total courses displayed: " << count << endl << endl;
    } 
    
    pause();
    return 1;
}

int AddCourse()
{
    cout << "Need to be implemented" << endl;
    return 1;
}

int EditCourse()
{
    cout << "Need to be implemented" << endl;
    return 1;    
}

int DeleteCourse()
{
    cout << "Need to be implemented" << endl;
    return 1;
}