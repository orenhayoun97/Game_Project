#pragma once
#include "Game.h"

/// <summary>
/// a menu class to handle all game operations and user input
/// </summary>
class Menu_Wrapper
{
private:
	static const char* info;//used in some cout prints
	static const char* menu;//used in some cout prints
	static const char* actions[];//used in some cout prints
	Game mainGameObject;
	void printMenu() const ;
	int basicValidateInteger() const;//very basic use of cin object methods to disallow character inputs
public:
	static void cleanBuffer();//empties the standard input. use before cin.getline
	explicit Menu_Wrapper(int numPlayers) : mainGameObject(numPlayers) {}
	void run();
};

