#pragma once
#include<iostream>
#include"Figure.h"
#include<Windows.h>

const int COORDINATE_X = 22;
const int COORDINATE_Y = 20;


class Map
{
public:
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 1));    <- ��������� �����
	//SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));    <- ������� � �������� ���� 

	Map();
	~Map();
	void addOnMap(Figure* FigureOnMap);
	void Print_map();
	void saveFigureForMap(Figure* figure);
	
	char getMap(int x, int y);
	bool getBoolMap(int x, int y);
	void setBoolMap(int x, int y, bool icon);

private:
	unsigned char icon;
	bool AddFigure;
	bool mapBool[COORDINATE_Y][COORDINATE_X];
	char map[COORDINATE_Y][COORDINATE_X];

};
