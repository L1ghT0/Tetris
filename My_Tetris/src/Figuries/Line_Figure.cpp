#include "Line_Figure.h"

Line_Figure::Line_Figure()
{
	heightFigure = 4;
	widthFigure = 1;
}

void Line_Figure::push_figure()
{
	for (int i = 0; i < heightFigure; i++)
        FigureElement[i][0].symbolFigure = 219 + 255 * (getColor());
}
