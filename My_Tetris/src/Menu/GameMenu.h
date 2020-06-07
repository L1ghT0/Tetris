#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../Play/PlayTetris.h"
#include "../OsHelper.h"

class GameMenu : public PlayTetris
{
public:
	GameMenu();
	void mainMenu();

private:

	void print(std::vector<std::string> vec);
	void choice(std::vector<std::string> vec);
	void checkInput(std::vector<std::string> vec);
	void writeToFile(int score);
	void readFile();

	char input;
	int count;
	bool itMenu;

	std::string path;
	std::vector<std::string> vMenu;
	std::vector<std::string> vDifficulty;
};

