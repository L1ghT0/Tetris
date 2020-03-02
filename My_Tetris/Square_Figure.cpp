#include "Square_Figure.h"

Square_Figure::Square_Figure()
{
	heightFigure = 2;
	widthFigure = 2;
}

void Square_Figure::push_figure()
{
	for (int i = 0; i < heightFigure; i++)
		for (int j = 0; j < widthFigure; j++)
			ThisFigure[i][j].icon = 1;
}
