#include "T_Figure.h"

T_Figure::T_Figure()
{
	heightFigure = 2;
	widthFigure = 3;
}

void T_Figure::push_figure()
{
	for (int i = 0; i < widthFigure; i++)
		ThisFigure[0][i].icon = 219 + 255 * (getColor());
	ThisFigure[1][1].icon = 219 + 255 * (getColor());
}
