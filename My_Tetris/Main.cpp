#include "GameMenu.h"
int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));

	GameMenu gameTetris;
	gameTetris.mainMenu();

    return 0;
    /* NEED to Add(Fix):
     * 1. Change name of struct      in Figure
     * 2. Change method and logic    in GameMenu
     */
}
