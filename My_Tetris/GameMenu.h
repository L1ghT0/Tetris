#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include "PlayTetris.h"

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<std::string> vMenu;
	std::vector<std::string> vDifficulty;
};

