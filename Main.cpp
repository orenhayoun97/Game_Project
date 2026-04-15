#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "Menu_Wrapper.h"
#include "Sim.h"
int main()
{
	Menu_Wrapper* main_menu = new Menu_Wrapper(3);
	main_menu->run();

	delete main_menu;


	_CrtDumpMemoryLeaks();
	
	return 0;
}
