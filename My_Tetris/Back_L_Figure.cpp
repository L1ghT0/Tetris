#include "Back_L_Figure.h"

Back_L_Figure::Back_L_Figure()
{
	heightFigure = 3;
	widthFigure = 2;

}

void Back_L_Figure::push_figure()
{
	for (int i = 0; i < heightFigure; i++)
		ThisFigure[i][1].icon = 1;
	ThisFigure[2][0].icon = 1;
}
