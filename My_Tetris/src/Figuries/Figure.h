#pragma once
const int COORDINATE_F = 5;

class Figure 
{
public:
	Figure();
	virtual ~Figure();
	virtual void push_figure() = 0;
	void inverse(Figure* pFigure);
	void setColor(int color);
	int getColor();
	int getHeightFigure();
    int getWidthFigure() ;

    static Figure* createFigure();

    struct     // Move to Protected
    {
        short symbolFigure; // symbol
    }FigureElement[COORDINATE_F][COORDINATE_F]; // FigureElement
    struct     // Move to Protected
    {
        int x;
        int y;
    }Coordinate[COORDINATE_F];


private:
    int color;
protected:
    int widthFigure;
    int heightFigure;
};

