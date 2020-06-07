#include "GameMenu.h"
int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));

	GameMenu gameTetris;
	gameTetris.mainMenu();

    return 0;
    /* NEED Add(Fix):
     * 1. Fix inverse                in Figure
     * 2. Destructor Figure          in Figure
     * 3. Getter widthFigure         in Figure
     * 4. Getter heightFigure        in Figure
     * 5. Method createFigure        in Figure
     * 6. new Method                 in GameLogic
     * 7. Change name of struct      in Figure
     * 8. Change method and logic    in GameMenu
     */
}
