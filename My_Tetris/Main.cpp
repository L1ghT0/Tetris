#include "GameMenu.h"
int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));

	GameMenu gameTetris;
	gameTetris.mainMenu();

    return 0;
    /* NEED to Add(Fix):
     * 1. Fix inverse                in Figure
     * 2. Destructor Figure          in Figure
     * 3. Method createFigure        in Figure
     * 4. new Method                 in GameLogic
     * 5. Change name of struct      in Figure
     * 6. Change method and logic    in GameMenu
     */
}
