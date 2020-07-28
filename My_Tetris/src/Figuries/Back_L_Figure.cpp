#include "Back_L_Figure.h"

Back_L_Figure::Back_L_Figure()
{
	heightFigure = 3;
	widthFigure = 2;

}

void Back_L_Figure::push_figure()
{
	for (int i = 0; i < heightFigure; i++)
		FigureElement[i][1].symbolFigure = 219 + 255 * (getColor());
    FigureElement[2][0].symbolFigure = 219 + 255 * (getColor());
}
