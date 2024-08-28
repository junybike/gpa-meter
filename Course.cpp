/*=================================================================================================
    Course.cpp
=================================================================================================*/

#include "Course.hpp"

using namespace std;

/*=================================================================================================
    Course class: Public Functions Implementation 
=================================================================================================*/

Course::Course()
{

}

Course::Course(const char* course_name, const char* course_major, const char* course_number,   
        const char* course_year, const Grade course_grade, const Season course_season)
{
    AssignString(this->course_name, course_name, sizeof(this->course_name));
    AssignString(this->course_major, course_major, sizeof(this->course_major));
    AssignString(this->course_number, course_number, sizeof(this->course_number));
    AssignString(this->course_year, course_year, sizeof(this->course_year));

    this->course_grade = course_grade;
    this->course_season = course_season;
}

Course& Course::operator=(const Course& course)
{
    AssignString(this->course_major, course.course_major, sizeof(course_major));
    AssignString(this->course_number, course.course_number, sizeof(course_number));
    AssignString(this->course_name, course.course_name, sizeof(course_name));
    AssignString(this->course_year, course.course_year, sizeof(course_year));
    this->course_grade = course.course_grade;
    this->course_season = course.course_season;

    return *this;
}

bool Course::operator==(const Course& course) const
{
    if (strcmp(course_major, course.course_major) == 0 && 
        strcmp(course_number, course.course_number) == 0 &&
        strcmp(course_year, course.course_year) == 0 && 
        course_season == course.course_season) 
    {
        return true;
    }
    return false;
}

bool Course::operator<=(const Course& course) const
{
    if (strcmp(course_year, course.course_year) == 0)
    {
        if (course_season <= course.course_season)
        {
            return true;
        }
    }
    else if (course_year > course.course_year)
    {
        return false;
    } 
    return false;
}

void Course::DisplayInfo(std::ostream &out) const
{
    out << left 
         << setw(3) << " "
         << setw(7);
    PrintGrade(GetCourseGrade());
    out << setw(6) << course_major
         << setw(6) << course_number
         << setw(33) << course_name
         << setw(7) << course_year
         << setw(5);
    PrintSeason(GetCourseSeason());
    out << endl;
} 

/*=================================================================================================
    Course class: Private Functions Implementation
=================================================================================================*/

/*=================================================================================================
    Functions Implementation 
=================================================================================================*/

int WriteCourseOnFile(const Course &course, streampos &fd)
{
    ofstream file(COURSEFILE, ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Failed to open course file" << endl;
        return 0;
    }

    file.seekp(0, ios::end);
    fd = file.tellp();
    file.write(reinterpret_cast<const char*>(&course), sizeof(Course));
    fd = file.tellp();

    return 1;
}

Course ReadCourseFromFile(streampos &fd)
{
    ifstream file(COURSEFILE, ios::binary);
    if (!file)
    {
        cout << "Failed to open course file" << endl;
    }

    file.seekg(fd);
    Course course;
    file.read(reinterpret_cast<char *>(&course), sizeof(Course));
    fd = file.tellg();

    return course;
}

int Initialization()
{
    filesystem::create_directory(DIRECTORY);
    if (!filesystem::exists(COURSEFILE))
    {
        ofstream file(COURSEFILE, ios::binary);
        if (!file)
        {
            cout << "Failed to create course file";
            return 0;
        }
        file.close();
        return 1;
    }
    return 0;
}

/*
-------------------------------------------------------------------------------------------------*/
void PrintGrade(Grade grade)
{
    switch(grade)
    {
        case A_PLUS:
            cout << "A+";
            break;
        case A_NEUTRAL:
            cout << "A";
            break;
        case A_MINUS:
            cout << "A-";
            break;
        case B_PLUS:
            cout << "B+";
            break;
        case B_NEUTRAL:
            cout << "B";
            break;
        case B_MINUS:
            cout << "B-";
            break;
        case C_PLUS:
            cout << "C+";
            break;
        case C_NEUTRAL:
            cout << "C";
            break;
        case C_MINUS:
            cout << "C-";
            break;
        case D_NEUTRAL:
            cout << "D";
            break;
        case PASS:
            cout << "P";
            break;
        case WITHDRAWN:
            cout << "W";
            break;
        default:
            cout << "N/A";
            break;
    }
}
/*
-------------------------------------------------------------------------------------------------*/
void PrintSeason(Season season)
{
    switch(season)
    {
        case SPRING:
            cout << "Spring";
            break;
        case SUMMER:
            cout << "Summer";
            break;
        case FALL:
            cout << "Fall";
            break;
        default:
            cout << "N/A";
            break;
    }
}