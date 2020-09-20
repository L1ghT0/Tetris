#pragma once
#include <mutex>
#include "../Figuries/Figure.h"
#include "../Map/Map.h"
#include "../OsHelper.h"

class GameLogic
{
public:

	GameLogic();
	~GameLogic();
	 
    bool shiftFigure(Figure*, Map*, int, int);
	int lineRemovalAssembly(Map* pMap);

    void input(bool& GameOver, Figure* pFigure, Map* pMap);
	bool gameover(Map* pMap, Figure* pFigure);

private:
    bool checkShiftFigure(Figure* pFigure, Map* pMap, const int& heightFigure, int shiftX, int shiftY);
    void lowerTheMap(Map* pMap, int numOfLine);
	int LineDeletion(Map* pMap, int& countLines);

	std::mutex mtx;
	int increaseScore(int lines);
	bool checkNextLine;
	char ch;
};

