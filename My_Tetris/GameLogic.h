#pragma once
#include "Figure.h"
#include "Map.h"
#include<conio.h>

class GameLogic
{
public:

	GameLogic();
	~GameLogic();
	 
	bool shiftFigure(Figure* pFigure, Map* pMap, const int& heightFigure, int shiftX, int shiftY);
	int lineRemovalAssembly(Map* pMap);

	void input(bool& GameOver, Figure* pFigure, Map* pMap);
	bool gameover(Map* pMap, Figure* pFigure);

private:
	void lowerTheMap(Map* pMap, int numOfLine);
	int LineDeletion(Map* pMap, int& countLines);

	int increaseScore(int lines);
	bool checkNextLine;
	char ch;
};

