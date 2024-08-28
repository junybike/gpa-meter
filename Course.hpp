#ifndef COURSE_HPP
#define COURSE_HPP

/*=================================================================================================
    Course.hpp 
=================================================================================================*/

#include <iostream>
#include <iomanip>
#include <filesystem>
#include "Helper.hpp"
#include "Files.hpp"

/*=================================================================================================
    enum: grade, season
=================================================================================================*/

enum Grade
{
    A_PLUS, A_NEUTRAL, A_MINUS,
    B_PLUS, B_NEUTRAL, B_MINUS,
    C_PLUS, C_NEUTRAL, C_MINUS,
    D_NEUTRAL, F_NEUTRAL,
    PASS, WITHDRAWN
};

enum Season 
{
    SPRING, SUMMER, FALL
};

/*=================================================================================================
    class: Course
=================================================================================================*/

class Course
{
    public:

        /*
        The default constructor of Course class 
        -----------------------------------------------------------------------------------------*/
        Course();

        /*
        The parameterized constructor of Course class.
        Required parameters are course name, major, level, grade, year, and season.
        -----------------------------------------------------------------------------------------*/
        Course(
            const char* course_name,    // The name of the course.
            const char* course_major,   // The major of the course. Example: The "CMPT" in CMPT 120
            const char* course_number,  // The course number. Example: The "120" in CMPT 120
            const char* course_year,    // The course was taken in this year
            const Grade course_grade,   // The letter grade received in this course.
            const Season course_season  // The course was taken in this season
        );
        /*---------------------------------------------------------------------------------------*/

        /*
        Assignment overloader operator function. 
        Assigns the course with the given course in the parameter.
        -----------------------------------------------------------------------------------------*/
        Course &operator=(
            const Course &course
        );

        /*
        Equality overloader operator function. 
        Checks by comparing their course name, major, year, and semester.
        -----------------------------------------------------------------------------------------*/
        bool operator==(
            const Course& course
        ) const;

        /*
        Comparison overloader operator function.
        Checks with course was taken first by comparing their year and semester
        -----------------------------------------------------------------------------------------*/
        bool operator<=(
            const Course& course
        ) const;

        /*
        Prints all attributes of a course
        -----------------------------------------------------------------------------------------*/
        void DisplayInfo(
            std::ostream &out
        ) const;
        
        const char* GetCourseName() const { return course_name; }       // Course name getter 
        const char* GetCourseMajor() const { return course_major; }     // Course major getter 
        const char* GetCourseNumber() const { return course_number; }   // Course number getter 
        const char* GetCourseYear() const { return course_year; }       // Course year getter 
        const Grade GetCourseGrade() const { return course_grade; }     // Course grade getter
        const Season GetCourseSeason() const {return course_season; }   // Course season getter

    private:

        char course_name[31];     // The name of the course.
        char course_major[6];     // The major of the course. Example: The "CMPT" in CMPT 120
        char course_number[6];    // The course number. Example: The "120" in CMPT 120
        char course_year[6];      // The course was taken in this year
        Grade course_grade;       // The letter grade received in this course.
        Season course_season;     // The course was taken in this season
};

/*=================================================================================================
    Functions
=================================================================================================*/

/*

-------------------------------------------------------------------------------------------------*/
int Initialization();


int WriteCourseOnFile(const Course &course, streampos &fd);

Course ReadCourseFromFile(streampos &fd);

/*
Prints the Grade in string with the given enumeration of the Grade
-------------------------------------------------------------------------------------------------*/
void PrintGrade(
    Grade grade         // this grade will be printed in a string format
);
/*
Prints the Season in string with the given enumeration of the Season
-------------------------------------------------------------------------------------------------*/
void PrintSeason(
    Season season       // this season will be printed in a string format
);

#endif