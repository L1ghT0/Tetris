#include "GameMenu.h"
//#include <cstdio>
GameMenu::GameMenu()
{
	this->input = 0;
	this->lineCount = 0;
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

void GameMenu::mainMenu(IGame* game)
{
	GameMenu::print(vMenu);
	while (input != '`')
	{
		input = OsHelper::m_getch();
		if (input == 's' || input == 'w' || input == OsHelper::enter)
		{
			if (itMenu) {
                GameMenu::checkInput(vMenu, game);
            } else {
                GameMenu::checkInput(vDifficulty, game);
            }
            if (itMenu)
                print(vMenu);
            else
                print(vDifficulty);
        }
    }
}

void GameMenu::print(std::vector<std::string> vec)
{
    OsHelper::m_sysCLaer();
	for (int i = 0; i < vec.size(); i++)
	{
		if (lineCount == i)
		{
		    OsHelper::change_color(7, 0);
			std::cout << vec[i] << " <--" << std::endl;
			OsHelper::change_color(0, 7);
		}
		else
			std::cout << vec[i] << std::endl;
	}
}

void GameMenu::checkInput(std::vector<std::string> vec, IGame* game)
{
    if (input == OsHelper::enter){
        GameMenu::enterClick(vec, game);
    } else {
        if (input == 's')
            this->lineCount++;
        else if (input == 'w')
            this->lineCount--;
        if (lineCount == vec.size())
            this->lineCount = 0;
        else if (lineCount < 0)
            this->lineCount = (vec.size() - 1);
    }
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

void GameMenu::enterClick(std::vector<std::string> vec, IGame* game)
{
    if (lineCount == 0 && itMenu)
    {
        lineCount = 0;
        itMenu = false;
    }
    else if (lineCount == 1 && itMenu)
    {
        GameMenu::readFile();
        system("pause");
    }
    else if (lineCount == (vec.size() - 1) && itMenu)
    {
        this->input = '`';
    }
    else if (lineCount != (vec.size() - 1) && !itMenu)
    {
        startGame(game, lineCount);
    }
    else if (lineCount == (vec.size() - 1) && !itMenu)
    {
        lineCount = 0;
        itMenu = true;
    }
}

void GameMenu::startGame(IGame *game, int difficulty) {
    int score = game->play(difficulty);
    GameMenu::writeToFile(score);
}

