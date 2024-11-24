#include <iostream>
#include "Menu_Wrapper.h"
#include <cstdlib>//for system("cls") which clears the console screen. NOTE - might not be cross-Platform compatible
using namespace std;

const char* Menu_Wrapper::info = "***** !Error! ***** ";
const char* Menu_Wrapper::actions[] = { "eat","sleep","age up","practice","receive award","Buy item"};
const char* Menu_Wrapper::menu = "1) Add sim"
"\n2) Print status"
"\n3) Pass game time"
"\n4) Perform action on Sim"
"\n-1) Exit...";

void Menu_Wrapper::printMenu() const
{
	cout << Menu_Wrapper::menu;
}

void Menu_Wrapper::run()
{
	std::srand((long)std::time(nullptr));//in cpp we should use objects from <random> instead

	int userChoice = 0;
	int action = 0;
	char nameBuffer[100] = { 0 };//temp char array for name input

	while (userChoice != -1)//while !EXIT_CASE
	{
		cout << mainGameObject;
		printMenu();
		userChoice = basicValidateInteger();//input until a valid integer
		system("cls");//clear screen, might not be portable

		switch (userChoice)//this switch should use enum classes but some students did not learn this feature.
		{
			//case EXIT
		case -1:
			break;
			//case ADD_SIM
		case 1:
			Menu_Wrapper::cleanBuffer();
			cout << "Enter new Sim name: ";
			cin.getline(nameBuffer, 100);
			if (mainGameObject.addSim(nameBuffer))//if add operation is successful
				cout << "Sim \"" << nameBuffer << "\" added\n";
			else//add operation failed
				cout << Menu_Wrapper::info << "Sim \"" << nameBuffer << "\" was not added\n";
			break;
			//case PRINT_STATE
		case 2:
			break;
			//case PASS_TIME
		case 3:
			cout << " Time passes...\n";
			mainGameObject.passTime();
			break;
			//case PERFORM_ACTION
		case 4:
			cout << mainGameObject;
			Menu_Wrapper::cleanBuffer();
			cout << "Choose Sim by name: ";
			cin.getline(nameBuffer, 100);
			for (int i = 0; i < sizeof(Menu_Wrapper::actions) / sizeof(Menu_Wrapper::actions[0]); i++)
			{
				cout << Menu_Wrapper::actions[i] << " -> " << i << endl;
			}
			cin >> action;
			if (!mainGameObject.performAction(nameBuffer, action))
				cout << Menu_Wrapper::info << "\nAction not performed...\n";
			else
				cout << "\nAction performed successfully.\n";
			break;
		default:
			cout << Menu_Wrapper::info << "No such menu choice...\n";
			break;
		}

	}
}

void Menu_Wrapper::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

/// <summary>
/// Note that this method will accept inputs such as "1abc" as valid integer 1
///		and discard remaining "abc" part of input
/// </summary>
/// <returns></returns>
int Menu_Wrapper::basicValidateInteger() const
{
	int choice;

	cout << "\nEnter a number:";
	cin >> choice;
	while (cin.fail())//if cin failed in inputting an integer
	{
		cout << Menu_Wrapper::info << "Not a number...\nEnter a number:";
		cin.clear();//resets some cin internal error state flag so that cin.fail returns false 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//ignore all remaining standard input.
		cin >> choice;//re-input the user choice
	}

	return choice;//when this line reached, cin successfully input an integer.
}