#include "Z_Figure.h"

Z_Figure::Z_Figure() 
{
	heightFigure = 3;
	widthFigure = 2;
}

void Z_Figure::push_figure()
{
    FigureElement[0][1].symbolFigure = 219 + 255 * (getColor());
    FigureElement[1][0].symbolFigure = 219 + 255 * (getColor());
    FigureElement[1][1].symbolFigure = 219 + 255 * (getColor());
    FigureElement[2][0].symbolFigure = 219 + 255 * (getColor());
}
