#include "GameMenu.h"
//#include <cstdio>
GameMenu::GameMenu()
{
	this->input = 0;
	this->count = 0;
	this->itMenu = true;
	path = "Story of the score.txt";
	vMenu.push_back("New Game");
	vMenu.push_back("Story of the score");
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
		input = OsHelper::m_getch();
		if (input == 's' || input == 'w' || input == OsHelper::enter)
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
    OsHelper::m_sysCLaer();
	for (int i = 0; i < vec.size(); i++)
	{
		if (count == i)
		{
		    OsHelper::change_color(7, 0);
			std::cout << vec[i] << " <--" << std::endl;
			OsHelper::change_color(0, 7);
		}
		else
			std::cout << vec[i] << std::endl;
	}
}

void GameMenu::choice(std::vector<std::string> vec)
{
	if (vec == vMenu || vec == vDifficulty)
		GameMenu::print(vec);
}

void GameMenu::checkInput(std::vector<std::string> vec)
{
	if (input == 's')
		this->count++;
	else if (input == 'w')
		this->count--;
	
	if (count == 0 && input == OsHelper::enter && itMenu)
	{
		count = 0;
		itMenu = false;
	}
	else if (count == 1 && input == OsHelper::enter && itMenu)
	{
		GameMenu::readFile();
		system("pause");
	}
	else if (count == (vec.size() - 1) && input == OsHelper::enter && itMenu)
	{
		this->input = '`';
	}
	else if (count != (vec.size() - 1) && input == OsHelper::enter && !itMenu)
	{
		int difficulty = count;
		PlayTetris tetris;
		int score = tetris.play(difficulty);
		GameMenu::writeToFile(score);
	}
	else if (count == (vec.size() - 1) && input == OsHelper::enter && !itMenu)
	{
		count = 0;
		itMenu = true;
	}

	if (count == vec.size())
		this->count = 0;
	else if (count < 0)
		this->count = (vec.size() - 1);
}

void GameMenu::writeToFile(int score)
{
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout.is_open())
	{
        OsHelper::m_sysCLaer();
        std::cout << "file open error" << std::endl;
		system("pause");
	}
	else
		fout << "Score: " << score << "\n";
	fout.close();
}

void GameMenu::readFile()
{
	OsHelper::m_sysCLaer();
	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
        OsHelper::m_sysCLaer();
		std::cout << "file open error" << std::endl;
		system("pause");
	}
	else
	{
		std::string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			std::cout << str << std::endl;
		}
	}
	fin.close();
}

