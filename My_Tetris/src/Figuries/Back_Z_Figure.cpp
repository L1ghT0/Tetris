#include "Back_Z_Figure.h"

Back_Z_Figure::Back_Z_Figure()
{
	heightFigure = 3;
	widthFigure = 2;
}

void Back_Z_Figure::push_figure()
{
	ThisFigure[0][0].icon = 219 + 255 * (getColor());
	ThisFigure[1][0].icon = 219 + 255 * (getColor());
	ThisFigure[1][1].icon = 219 + 255 * (getColor());
	ThisFigure[2][1].icon = 219 + 255 * (getColor());
}
