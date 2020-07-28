#include "GameMenu.h"
#include "PlayTetris.h"

int main()
{
	setlocale(LC_ALL, "C");
    //setlocale(LC_CTYPE,"");
	srand(time(NULL));

    //char* x[5][5] = {};
//	x[0][0] = " ";
//	x[0][1] = "\u2586";
//    int b = 31;
//	//std::cout << "this is space:"<<x[0][0] <<"YeaH!"  << '\n' << x[0][1] << '\n';
//   // x[0][2] = "\033[1;30m\u2586\033[0m";
//    std::cout << "\033[1;31m\033[10m"<< x[0][1] << "123" << "\033[1;31m\033[0m" << "123";
//    std::cout << "\033[1;34m\033[10m";
//    std::cout << x[0][1];
//    std::cout << "\033[1;36m\033[10m";
//    std::cout << x[0][1];
//    std::cout <<"\033[1;31m\033[0m";
    //std::cout << x[0][1];


//  char* a = "\u2586";
//	std::cout << a << '\n'

	PlayTetris* tetris = new PlayTetris;
	GameMenu menuForGame;
    menuForGame.mainMenu(tetris);
    delete tetris;


    return 0;
}
