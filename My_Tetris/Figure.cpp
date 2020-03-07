#include "Figure.h"
#include "Map.h"

Figure::Figure()
{
	heightFigure = 0;
	widthFigure = 0;
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0; j < COORDINATE_F; j++)
			ThisFigure[i][j].icon = 0;

	for (int k = 0; k < COORDINATE_F; k++)
	{
		Coordinate[k].x = 0;
		Coordinate[k].y = 0;
	}
	for (int i = 0; i < COORDINATE_F; i++)
	{
		Coordinate[i].x = (((COORDINATE_X / 2) + (COORDINATE_X / 2 / 4)) / 2) + i;
		Coordinate[i].y = i + 1;
	}
}

Figure::~Figure()
{
}

void Figure::inverse(Figure* figure)
{
	int count = 0;
	bool bar[COORDINATE_F][COORDINATE_F];
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0; j < COORDINATE_F; j++)
			bar[i][j] = figure->ThisFigure[i][j].icon;
	
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0, k = COORDINATE_F - 1; j < COORDINATE_F; j++, k--)
				figure->ThisFigure[i][j].icon = bar[k][i];

	for (int i = 0; i < COORDINATE_F; i++)
	{
		for (int j = 0; j < COORDINATE_F; j++)
		{
			count = (COORDINATE_F - figure->heightFigure);
			if (figure->ThisFigure[i][j].icon)
			{
				figure->ThisFigure[i][j-count].icon = 1;
				figure->ThisFigure[i][j].icon = 0;
			}
		}
	}
	int temp = figure->heightFigure;
	figure->heightFigure = figure->widthFigure;
	figure->widthFigure = temp;
}

void Figure::setColor(int color)
{
	color == 7 ? this->color = (color+3) : this->color = color;	// "7" - defaults color
}

int Figure::getColor()
{
	return this->color;
}
