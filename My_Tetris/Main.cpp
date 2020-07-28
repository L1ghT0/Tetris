#include "GameMenu.h"
#include "PlayTetris.h"


int main()
{
	setlocale(LC_ALL, "C");
	srand(time(NULL));

	PlayTetris* tetris = new PlayTetris;
	GameMenu menuForGame;
    menuForGame.mainMenu(tetris);
    delete tetris;

    return 0;
}
