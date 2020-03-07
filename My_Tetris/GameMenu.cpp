#include "GameMenu.h"

GameMenu::GameMenu()
{
	this->input = 0;
	this->count = 0;
	this->itMenu = true;
	vMenu.push_back("New Game");
	vMenu.push_back("The best");
	vMenu.push_back("Exit");
	vDifficulty.push_back("Easy");
	vDifficulty.push_back("Normal");
	vDifficulty.push_back("Hard");
	vDifficulty.push_back("Back");
}

void GameMenu::mainMenu()
{
	GameMenu::print(vMenu);
	while (input != '`')
	{
		input = _getch();
		if (input == 's' || input == 'w' || input == 13) 
		{
			if (itMenu)
				GameMenu::checkInput(vMenu);
			else
				GameMenu::checkInput(vDifficulty);
			if (itMenu)
				GameMenu::choice(vMenu);
			else
				GameMenu::choice(vDifficulty);
		}
	}
}

void GameMenu::print(std::vector<std::string> vec)
{
	system("cls");
	for (int i = 0; i < vec.size(); i++)
	{
		if (count == i)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((7 << 4) | 0));
			std::cout << vec[i] << std::endl;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
		}
		else
			std::cout << vec[i] << std::endl;
	}
}

void GameMenu::choice(std::vector<std::string> vec)
{
	if (vec == vMenu)
		GameMenu::print(vec);
	else if (vec == vDifficulty)
		GameMenu::print(vec);
}

void GameMenu::checkInput(std::vector<std::string> vec)
{
	if (input == 's')
		this->count++;
	else if (input == 'w')
		this->count--;
	
	if (count == 0 && input == 13 && itMenu)
	{
		count = 0;
		itMenu = false;
	}
	else if (count == 1 && input == 13 && itMenu)
	{
		std::cout << "its menu, count = 1" << std::endl;
		system("pause");
	}
	else if (count == (vec.size() - 1) && input == 13 && itMenu)
		this->input = '`';
	else if (count != (vec.size() - 1) && input == 13 && !itMenu)
	{
		int difficulty = count;
		PlayTetris::play(difficulty);
	}
	else if (count == (vec.size() - 1) && input == 13 && !itMenu)
	{
		count = 0;
		itMenu = true;
	}

	if (count == vec.size())
		this->count = 0;
	else if (count < 0)
		this->count = (vec.size() - 1);
}

