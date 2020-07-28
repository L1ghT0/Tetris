#include "Back_Z_Figure.h"

Back_Z_Figure::Back_Z_Figure()
{
	heightFigure = 3;
	widthFigure = 2;
}

void Back_Z_Figure::push_figure()
{
    FigureElement[0][0].symbolFigure = 219 + 255 * (getColor());
    FigureElement[1][0].symbolFigure = 219 + 255 * (getColor());
    FigureElement[1][1].symbolFigure = 219 + 255 * (getColor());
    FigureElement[2][1].symbolFigure = 219 + 255 * (getColor());
}
