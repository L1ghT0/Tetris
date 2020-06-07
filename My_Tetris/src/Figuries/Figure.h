#pragma once
const int COORDINATE_F = 5;

class Figure 
{
public:
	Figure();
    // add Destructor for deleted figure
	virtual void push_figure() = 0;
	void inverse(Figure* pFigure);
	void setColor(int color);
	int getColor();
	// need new method: Figure* createFigure();
	struct
	{
		short icon;
	}ThisFigure[COORDINATE_F][COORDINATE_F];
	struct 
	{
		int x;
		int y;
	}Coordinate[COORDINATE_F];

	int heightFigure;   // add getter
	int widthFigure;    // add getter

private:
	int color;
};

