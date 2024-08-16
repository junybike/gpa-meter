/*=================================================================================================
    Course.cpp
=================================================================================================*/

#include "Course.hpp"
using namespace std;

/*=================================================================================================
    Functions Implementation 
=================================================================================================*/

void PrintCourseInfo(Course course)
{
    cout << left 
         << setw(3) << " "
         << setw(7) << course.GetCourseGrade()
         << setw(6) << course.GetCourseMajor()
         << setw(6) << course.GetCourseNumber()
         << setw(33) << course.GetCourseName()
         << setw(7) << course.GetCourseYear()
         << setw(5) << course.GetCourseSeason()
         << endl;
}

/*=================================================================================================
    Course class: Public Functions Implementation 
=================================================================================================*/

Course::Course(const char* course_name, const char* course_major, const char* course_number,   
        const char* course_year, const grade course_grade, const season course_season)
{
    AssignString(this->course_name, course_name, sizeof(this->course_name));
    AssignString(this->course_major, course_major, sizeof(this->course_major));
    AssignString(this->course_number, course_number, sizeof(this->course_number));
    AssignString(this->course_year, course_year, sizeof(this->course_year));

    this->course_grade = course_grade;
    this->course_season = course_season;
}

/*=================================================================================================
    Course class: Private Functions Implementation
=================================================================================================*/