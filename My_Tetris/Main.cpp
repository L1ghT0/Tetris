#include "src/Menu/GameMenu.h"
#include "src/Play/Tetris.h"

int main()
{
	Tetris* tetris = new Tetris;
	GameMenu menu;
    menu.mainMenu(tetris);
    delete tetris;

    return 0;
}
