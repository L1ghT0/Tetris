#include "T_Figure.h"

T_Figure::T_Figure()
{
	heightFigure = 2;
	widthFigure = 3;
}

void T_Figure::push_figure()
{
	for (int i = 0; i < widthFigure; i++)
        FigureElement[0][i].symbolFigure = 219 + 255 * (getColor());
    FigureElement[1][1].symbolFigure = 219 + 255 * (getColor());
}
