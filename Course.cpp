/*=================================================================================================
    Course.cpp
=================================================================================================*/

#include "Course.hpp"

using namespace std;

/*=================================================================================================
    Course class: Public Functions Implementation 
=================================================================================================*/

Course::Course() : course_grade(PASS), course_season(FALL)
{
    memset(course_name, 0, sizeof(course_name));
    memset(course_major, 0, sizeof(course_major));
    memset(course_number, 0, sizeof(course_number));
    memset(course_year, 0, sizeof(course_year));
}

Course::Course(const char* course_name, const char* course_major, const char* course_number,   
        const char* course_year, const int course_unit, const Grade course_grade, const Season course_season)
{
    AssignString(this->course_name, course_name, sizeof(this->course_name));
    AssignString(this->course_major, course_major, sizeof(this->course_major));
    AssignString(this->course_number, course_number, sizeof(this->course_number));
    AssignString(this->course_year, course_year, sizeof(this->course_year));

    this->course_unit = course_unit;
    this->course_grade = course_grade;
    this->course_season = course_season;
}

Course& Course::operator=(const Course& course)
{
    AssignString(this->course_name, course.course_name, sizeof(course_name));
    AssignString(this->course_major, course.course_major, sizeof(course_major));
    AssignString(this->course_number, course.course_number, sizeof(course_number));
    AssignString(this->course_year, course.course_year, sizeof(course_year));
    
    this->course_unit = course.course_unit;
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
         << setw(5) << course_unit
         << setw(7) << course_year
         << setw(5);
    PrintSeason(GetCourseSeason());
    out << endl;
} 

/*=================================================================================================
    Course class: Private Functions Implementation
=================================================================================================*/

/*=================================================================================================
    Function Implementation 
=================================================================================================*/

int WriteCourseOnFile(const Course &course, streampos &fd)
{
    if (!ValidateCourse(course))
    {
        cout << "CREATE EXCEPTION: Not a valid course" << endl;
        return 0;
    }

    ofstream file(COURSEFILE, ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "CREATE EXCEPTION: Failed to open course file" << endl;
        return 0;
    }

    file.seekp(0, ios::end);
    fd = file.tellp();
    file.write(reinterpret_cast<const char*>(&course), sizeof(Course));
    fd = file.tellp();

    return 1;
}
/*-----------------------------------------------------------------------------------------------*/
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

    //course.DisplayInfo(cout);

    return course;
}
/*-----------------------------------------------------------------------------------------------*/
int ValidateCourse(const Course &course)
{
    if (strlen(course.GetCourseMajor()) > 5)
    {
        cout << "CREATE EXCEPTION: Major input size limit (5) exceeded" << endl;
        return 0;
    }
    if (strlen(course.GetCourseNumber()) > 5)
    {
        cout << "CREATE EXCEPTION: Number input size limit (5) exceeded" << endl;
        return 0;
    }
    if (strlen(course.GetCourseName()) > 30)
    {
        cout << "CREATE EXCEPTION: Name input size limit (30) exceeded" << endl;
        return 0;
    }
    if (strlen(course.GetCourseYear()) > 5)
    {
        cout << "CREATE EXCEPTION: Year input size limit (5) exceeded" << endl;
        return 0;
    }
    if (course.GetCourseUnit() != 3 && course.GetCourseUnit() != 4)
    {
        cout << "CREATE EXCEPTION: Unit must be 3 or 4" << endl;
        return 0;
    }

    ifstream file(COURSEFILE, ios::binary);
    if (!file)
    {
        cout << "CREATE EXCEPTION: Failed to open file" << endl;
    }

    Course course_in_file;

    while (file.read(reinterpret_cast<char *>(&course_in_file), sizeof(course_in_file)))
    {
        if (course_in_file == course)
        {
            cout << "CREATE EXCEPTION: Course already exists in the semester" << endl;
            return 0;
        }
    }

    if (file.eof()) 
    {
        file.clear();
    }
    else if (file.fail()) 
    {
        cout << "CREATE EXCEPTION: Failed to read file" << endl;
    } 
    file.close();

    return 1;
}
/*-----------------------------------------------------------------------------------------------*/
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
    return 1;
}
/*-----------------------------------------------------------------------------------------------*/
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
/*-----------------------------------------------------------------------------------------------*/
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
/*-----------------------------------------------------------------------------------------------*/
int DisplayAllCourses()
{
    ifstream file(COURSEFILE, ios::binary);
    if (!file)
    {
        cout << "CREATE EXCEPTION: Failed to open file" << endl;
    }

    Course course;
    int count = 0;

    while (file.read(reinterpret_cast<char *>(&course), sizeof(course)))
    {
        course.DisplayInfo(cout);
        count++;
    }

    if (file.eof()) 
    {
        file.clear();
    }
    else if (file.fail()) 
    {
        cout << "CREATE EXCEPTION: Failed to read file" << endl;
    } 
    file.close();
    
    if (count == 0)
    {
        cout << endl << "Transcript is empty" << endl << endl;
    }

    return count;
}
/*-----------------------------------------------------------------------------------------------*/
float* CalculateGPA()
{
    float C_GradePoint = 0, U_GradePoint = 0, L_GradePoint = 0;
    float C_Unit = 0, U_Unit = 0, L_Unit = 0;

    float* gpa_list = new float[3];
    for (int i = 0; i < 3; i++) gpa_list[i] = 0;

    float max_gpa = 4 + 1/3;

    if (gpa_list == NULL)
    {
        cout << "CREATE EXCEPTION: Failed to allocate memory for GPA list" << endl;
    }

    ifstream file(COURSEFILE, ios::binary);
    if (!file)
    {
        cout << "CREATE EXCEPTION: Failed to open file" << endl;
    }

    Course course;

    while (file.read(reinterpret_cast<char *>(&course), sizeof(course)))
    {
        Grade grade = course.GetCourseGrade();

        if (grade == PASS || grade == WITHDRAWN)
        {
            continue;
        }

        if ((course.GetCourseNumber())[0] == '3' || (course.GetCourseNumber())[0] == '4')
        {
            U_GradePoint += (max_gpa - course.GetCourseGrade() * 1/3) * course.GetCourseUnit();
            U_Unit += course.GetCourseUnit();
        }
        else
        {
            L_GradePoint += (max_gpa - course.GetCourseGrade() * 1/3) * course.GetCourseUnit();
            L_Unit += course.GetCourseUnit();
        }

        C_GradePoint += (max_gpa - course.GetCourseGrade() * 1/3) * course.GetCourseUnit();
        C_Unit += course.GetCourseUnit();
    }
    
    gpa_list[0] = C_GradePoint / C_Unit;
    gpa_list[1] = U_GradePoint / U_Unit;
    gpa_list[2] = L_GradePoint / L_Unit;

    return gpa_list;
}