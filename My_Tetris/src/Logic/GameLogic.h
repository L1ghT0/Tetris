#pragma once
#include "../Figuries/Figure.h"
#include "../Map/Map.h"
#include "../OsHelper.h"

class GameLogic
{
public:

	GameLogic();
	~GameLogic();
	 
	bool checkShiftFigure(Figure* pFigure, Map* pMap, const int& heightFigure, int shiftX, int shiftY);
	int lineRemovalAssembly(Map* pMap);

	void input(bool& GameOver, Figure* pFigure, Map* pMap);
	bool gameover(Map* pMap, Figure* pFigure);

private:
    bool shiftFigure(Figure*, Map*, bool, int, int);
	void lowerTheMap(Map* pMap, int numOfLine);
	int LineDeletion(Map* pMap, int& countLines);

	int increaseScore(int lines);
	bool checkNextLine;
	char ch;
};

