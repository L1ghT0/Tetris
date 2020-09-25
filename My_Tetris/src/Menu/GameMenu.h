#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../Play/Tetris.h"
#include "../Play/IGame.h"
#include "../OsHelper.h"

class GameMenu : public Tetris
{
public:
	GameMenu();
	void mainMenu(IGame* game);

private:
	void print(std::vector<std::string> vec);
	void checkInput(std::vector<std::string> vec, IGame* game);
	void writeToFile(int score);
	void readFile();
    void enterClick(std::vector<std::string>, IGame* game);
    void startGame(IGame *game, int difficulty);

	char input;
	int lineCount;
	bool itMenu;

	std::string path;
	std::vector<std::string> vMenu;
	std::vector<std::string> vDifficulty;
};

