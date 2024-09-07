/*=================================================================================================
    ScenarioControl.hpp
=================================================================================================*/

#include "Course.hpp"

/*=================================================================================================
    Functions
=================================================================================================*/

/*
Controls which scenario to run by taking an input parameter of 'choice'
-------------------------------------------------------------------------------------------------*/
int Scenario_control(
    int choice          // decides which scenario to run
);

/*
Calculate lower division, upper division, overall GPA from the courses recorded in the file 
-------------------------------------------------------------------------------------------------*/
int Calculate_gpa();

/*
Take a user input of their desired GPA and calculate multiple ways to achieve that GPA
-------------------------------------------------------------------------------------------------*/
int Aim_gpa();

/*
Display all courses stored in the file
-------------------------------------------------------------------------------------------------*/
int Display_transcript();

/*
Load or edit the courses in the file
-------------------------------------------------------------------------------------------------*/
int Edit_transcript();