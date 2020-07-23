#pragma once
#include<iostream>
#include"../Figuries/Figure.h"
#include "../OsHelper.h"

const int G_COORDINATE_X = 22;
const int G_COORDINATE_Y = 20;
const int G_CENTER_OF_MAP = ((G_COORDINATE_X/2)+ ((G_COORDINATE_X / 2)/4));/*(14)*/

class Map
{
public:

	Map();
	void addOnMap(Figure* pFigure);
	void Print_map();
	void saveFigureOnMap(Figure* pFigure);
	
	short getMap(int x, int y);
	short getFiguresMap(int x, int y);
	void setFiguresMap(int x, int y, short icon);

private:
	short icon;
	bool AddFigure;
	short mapFigures[G_COORDINATE_Y][G_COORDINATE_X];
	short map[G_COORDINATE_Y][G_COORDINATE_X];
};
