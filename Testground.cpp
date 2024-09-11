#include <iostream>
#include "Course.hpp"
#include "Helper.hpp"

using namespace std;

int main()
{

    float* list = CalculateGPA();
    cout << list[0] << " " << list[1] << " " << list[2] << endl;

    // /*=============================================================================================
    //     Constructing courses
    // =============================================================================================*/

    // Course course0 = Course("course0", "CMPT", "120", "2022", 3, A_NEUTRAL, FALL);
    // Course course1 = Course("course1", "CMPT", "225", "2023", 3, B_NEUTRAL, FALL);
    // Course course2 = Course("course2", "CMPT", "125", "2023", 3, A_MINUS, SPRING);
    // Course course3 = Course("course3", "CMPT", "125", "2023", 3, C_MINUS, SPRING);
    // Course course4 = Course("course4", "CMPT", "295", "2024", 4, B_NEUTRAL, SUMMER);

    // /*=============================================================================================
    //     Display info testing
    // =============================================================================================*/

    // cout << endl << "DISPLAY INFO TESTING" << endl << endl;

    // cout << left 
    //      << setw(3) << " "
    //      << setw(7) << "Grade"
    //      << setw(6) << "Course"
    //      << setw(6) << "Name"
    //      << setw(33) << " "
    //      << setw(5) << "Unit"
    //      << setw(7) << "Semester"
    //      << setw(5) << " "
    //      << endl;

    // course0.DisplayInfo(cout);
    // course1.DisplayInfo(cout);
    // course2.DisplayInfo(cout);
    // course3.DisplayInfo(cout);

    // /*=============================================================================================
    //     Overloading operator testing
    // =============================================================================================*/

    // cout << endl << "OVERLOADING OPERATOR TESTING" << endl << endl;

    // if (course1 <= course2)
    // {
    //     cout << "Course 1 was taken before or same time as course 2" << endl;
    // }
    // else
    // {
    //     cout << "Course 1 was taken after course 2" << endl;
    // }
    // if (course1 <= course0)
    // {
    //     cout << "Course 1 was taken before or same time as course 0" << endl;
    // }
    // else
    // {
    //     cout << "Course 1 was taken after course 0" << endl;
    // }

    // if (course1 == course2)
    // {
    //     cout << "Course 1 and Course 2 are the same course taken in the same year and semester" << endl;
    // }
    // else
    // {
    //     cout << "Course 1 and Course 2 are taken in the different time" << endl;
    // }
    // if (course2 == course3)
    // {
    //     cout << "Course 2 and Course 3 are the same course taken in the same year and semester" << endl;
    // }
    // else
    // {
    //     cout << "Course 2 and Course 3 are taken in the different time" << endl;
    // }

    // /*=============================================================================================
    //     Files initialization
    // =============================================================================================*/

    // if (Initialization())
    // {
    //     cout << "Course file created" << endl;
    // }
    // else
    // {
    //     cout << "Course file already exists" << endl;
    // }

    // /*=============================================================================================
    //     Writing on Files
    // =============================================================================================*/

    // if (WriteCourseOnFile(course0, COURSEFILEDESCRIPTOR))
    // {
    //     cout << "Writing successfull" << endl;
    // }
    // else
    // {
    //     cout << "Writing failed" << endl;
    // }

    // WriteCourseOnFile(course1, COURSEFILEDESCRIPTOR);
    // WriteCourseOnFile(course2, COURSEFILEDESCRIPTOR);
    // WriteCourseOnFile(course3, COURSEFILEDESCRIPTOR);
    // WriteCourseOnFile(course4, COURSEFILEDESCRIPTOR);

    // /*=============================================================================================
    //     Reading from Files
    // =============================================================================================*/

    // cout << endl << "READING FROM FILES TESTING" << endl << endl;

    // streampos pos = COURSEFILEDESCRIPTOR;
    // Course readcourse = Course();

    // for (int i = 0; i < 2; i++)
    // {
    //     readcourse = ReadCourseFromFile(COURSEFILEDESCRIPTOR);
    //     readcourse.DisplayInfo(cout);
    //     pos += sizeof(Course);
    // }
    
}