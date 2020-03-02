#pragma once
const int BOOL_ICON = 5;
const int COORDINATE_F = 5;

class Figure 
{
public:
	Figure();
	~Figure();

	virtual void push_figure() = 0;
	//virtual void addFigureCoordinates();
	virtual void inverse(Figure* figure);

	struct
	{
		bool icon;
	} ThisFigure[BOOL_ICON][BOOL_ICON];
	struct 
	{
		int x;
		int y;
	}coordinate[COORDINATE_F];

	int heightFigure;
	int widthFigure;
};

