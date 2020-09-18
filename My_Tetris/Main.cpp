#include "src/Menu/GameMenu.h"
#include "src/Play/PlayTetris.h"

int main()
{
	PlayTetris* tetris = new PlayTetris;
	GameMenu menuForGame;
    menuForGame.mainMenu(tetris);
    delete tetris;

    return 0;
}
