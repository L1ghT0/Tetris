#include "Z_Figure.h"

Z_Figure::Z_Figure() 
{
	heightFigure = 3;
	widthFigure = 2;
}

void Z_Figure::push_figure()
{
	ThisFigure[0][1].icon = 1;
	ThisFigure[1][0].icon = 1;
	ThisFigure[1][1].icon = 1;
	ThisFigure[2][0].icon = 1;
}
