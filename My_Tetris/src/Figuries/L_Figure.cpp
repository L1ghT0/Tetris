#include "L_Figure.h"

L_Figure::L_Figure()
{
	heightFigure = 3;
	widthFigure = 2;

}

void L_Figure::push_figure()
{
	for (int i = 0; i < heightFigure; i++)
        FigureElement[i][0].symbolFigure = 219 + 255 * (getColor());
    FigureElement[2][1].symbolFigure = 219 + 255 * (getColor());
}

