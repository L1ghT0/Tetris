#pragma once
#include<iostream>
#include <string>
#include"../Figuries/Figure.h"
#include "../OsHelper.h"

const int G_COORDINATE_X = 22;
const int G_COORDINATE_Y = 20;
const int G_CENTER_LINE_OF_THE_MAP = ((G_COORDINATE_X/2)+ ((G_COORDINATE_X / 2)/4)); // == 14

class Map
{
public:

	Map();
	void addOnMap(Figure* pFigure);
	void Print_map();
	void saveFigureOnMap(Figure* pFigure);
	
	std::string getMap(int x, int y);
	short getFiguresMap(int x, int y);
	void setFiguresMap(int x, int y, short icon);

    struct MapElement{
        int color = 0;
        std::string symbol;
    };
private:
	short icon;
	bool AddFigure;
    bool mapForStoppedFigures[G_COORDINATE_Y][G_COORDINATE_X];
    MapElement map[G_COORDINATE_Y][G_COORDINATE_X];
};
