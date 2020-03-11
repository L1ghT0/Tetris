#pragma once
#include<iostream>
#include"Figure.h"
#include<Windows.h>

const int COORDINATE_X = 22;
const int COORDINATE_Y = 20;

class Map
{
public:

	Map();
	~Map();
	void addOnMap(Figure* pFigure);
	void Print_map(int score);
	void saveFigureOnMap(Figure* pFigure);
	
	short getMap(int x, int y);
	short getFeguresMap(int x, int y);
	void setFeguresMap(int x, int y, short icon);

private:
	short icon;
	bool AddFigure;
	short mapFigures[COORDINATE_Y][COORDINATE_X];
	short map[COORDINATE_Y][COORDINATE_X];
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};
