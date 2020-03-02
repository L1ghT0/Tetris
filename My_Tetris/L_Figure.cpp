#include "L_Figure.h"

L_Figure::L_Figure()
{
	heightFigure = 3;
	widthFigure = 2;
}

void L_Figure::push_figure()
{
	for (int i = 0; i < heightFigure; i++)
		ThisFigure[i][0].icon = 1;
	ThisFigure[2][1].icon = 1;
}

