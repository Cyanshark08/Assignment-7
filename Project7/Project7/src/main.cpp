#include <algorithm>
#include "CalculationManager.h"

/*
* 
* Collaborators:
*  - Andrew Nguyen
*  - Jaime Gutierrez
*  - Landon Mendoza
* 
* Date: 10/17/2025
* 
* 
*/

#include "Application.h"

int main()
{
	CalculationManager manager;
	manager.TranslateToPostfix("1 + 2 - 3");


	Application app;

	app.Run();

	app.Clean();
}