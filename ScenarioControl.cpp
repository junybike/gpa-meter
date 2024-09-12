/*=================================================================================================
    ScenarioControl.cpp
=================================================================================================*/

#include "ScenarioControl.hpp"

using namespace std;

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
    string course_major, course_number, course_name, course_year;
    int course_unit, course_season, course_grade;
    
    cout << "===Add a Course===" << endl << endl;
    cin.ignore();

    cout << "(1/7) Enter the course major: ";
    getline(cin, course_major);
    cout << "(2/7) Enter the course number: ";
    getline(cin, course_number);
    cout << "(3/7) Enter the course name: ";
    getline(cin, course_name);
    cout << "(4/7) Enter the course year: ";
    getline(cin, course_year);

    cout << "(5/7) Enter the course season (1-3)" << endl
         << "      Options:" << endl
         << "       1) Spring, 2) Summer, 3) Fall" << endl 
         << "      The season: ";
    cin >> course_season;   

    cout << endl << "(6/7) Enter the course grade" << endl
         << "      Options:" << endl
         << "       1) A+, 2) A, 3) A-" << endl
         << "       4) B+, 5) B, 6) B-" << endl
         << "       7) C+, 8) C, 9) C-" << endl
         << "       10) D,     11) F" << endl
         << "       12) PASS,  13) WITHDRAWN" << endl
         << "      The grade: ";
    cin >> course_grade;

    cout << endl << "(7/7) Enter the course unit: ";
    cin >> course_unit;

    if (int(course_season) > 4 || int(course_season) < 1) 
    {
        cout << "Season: Invalid choice" << endl;
        return 0;
    }
    if (int(course_grade) > 13 || int(course_grade) < 1)
    {
        cout << "Grade: Invalid choice" << endl;
        return 0;
    }

    Course course = Course(course_name.data(), course_major.data(), course_number.data(), course_year.data(),
                           int(course_unit), Grade(int(course_grade) - 1), Season(int(course_season) - 1));

    if (!WriteCourseOnFile(course, COURSEFILEDESCRIPTOR))
    {
        cout << "CREATE EXCEPTION: Invalid course" << endl;
        return 0;
    }
    else cout << endl << "Course added successfully" << endl << endl;

    pause();
    cout << endl;

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