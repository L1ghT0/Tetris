#pragma once
const int COORDINATE_F = 5;

class Figure 
{
public:
	Figure();
	~Figure();

	virtual void push_figure() = 0;
	virtual void inverse(Figure* figure);
	void setColor(int color);
	int getColor();

	struct
	{
		bool icon;
	} ThisFigure[COORDINATE_F][COORDINATE_F];
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

