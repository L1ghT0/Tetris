#include "GameMenu.h"

int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));

	GameMenu gameTetris;
	gameTetris.mainMenu();

	return 0;
}
