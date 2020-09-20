#include "src/Menu/GameMenu.h"
#include "src/Play/PlayTetris.h"

int main()
{
	PlayTetris* tetris = new PlayTetris;
	GameMenu menu;
    menu.mainMenu(tetris);
    delete tetris;

    return 0;
}
