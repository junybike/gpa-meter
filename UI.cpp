/*=================================================================================================
    UI.cpp
=================================================================================================*/

#include "UI.hpp"

using namespace std;

/*=================================================================================================
    Function Implementation
=================================================================================================*/

int Main_menu()
{
    int choice;
    cout << endl << "===GPA-meter===" << endl << endl;
    cout << "1) Calculate GPA" << endl;
    cout << "2) Aim GPA" << endl;
    cout << "3) Display transcript" << endl;
    cout << "4) Add/Edit transcript" << endl;
    cout << "0) Shutdown" << endl << endl;

    cout << "Choose an option (0-4): ";
    cin >> choice;
    cout << endl;

    return choice;
}

int ActivateUI()
{
    int choice;
    do
    {
        choice = Main_menu();
        switch(choice)
        {
            case 0:
                cout << "Shutting down GPA-meter..." << endl << endl;
                break;
            case 1:
                Scenario_control(1);
                break;
            case 2:
                Scenario_control(2);
                break;
            case 3:
                Scenario_control(3);
                break;
            case 4:
                Scenario_control(4);
                break;
            default:
                cout << "Error: Not an available option" << endl;
                break;
        } 
    } while (choice != 0);

    cin.ignore();
    return 1;
}

