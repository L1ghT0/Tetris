#pragma once
const int COORDINATE_F = 5;

class Figure 
{
public:
	Figure();

	virtual void push_figure() = 0;
	virtual void inverse(Figure* pFigure);
	void setColor(int color);
	int getColor();

	struct
	{
		short icon;
	}ThisFigure[COORDINATE_F][COORDINATE_F];
	struct 
	{
		int x;
		int y;
	}Coordinate[COORDINATE_F];

	int heightFigure;
	int widthFigure;

private:
	int color;
};

