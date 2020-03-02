#pragma once
#include "Figure.h"
#include "Map.h"
#include<conio.h>
#include<thread>

class GameLogic
{
public:

	GameLogic();
	~GameLogic();
	 
	bool shiftFigure(Figure* figure, Map* map, const int& heightFigure, int shiftX, int shiftY);
	void lineDeletion(Map* map);
	void input(bool& GameOver, Figure* figure, Map* map);


private:
	bool checkNextLine;
	char ch;
};

