#include <iostream>
#include "Course.hpp"
#include "Helper.hpp"

using namespace std;

int main()
{
    Course newcourse = Course("intro to cp", "CMPT", "120", "2022", A_NEUTRAL, FALL);

    cout << left 
         << setw(3) << " "
         << setw(7) << "Grade"
         << setw(6) << "Course"
         << setw(6) << "Name"
         << setw(33) << " "
         << setw(7) << "Semester"
         << setw(5) << " "
         << endl;

    PrintCourseInfo(newcourse);
}