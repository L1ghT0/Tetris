#include "Figure.h"
#include "Map.h"

Figure::Figure()
{
	heightFigure = 0;
	widthFigure = 0;
	for (int i = 0; i < BOOL_ICON; i++)
		for (int j = 0; j < BOOL_ICON; j++)
			ThisFigure[i][j].icon = 0;

	for (int k = 0; k < COORDINATE_F; k++)
	{
		coordinate[k].x = 0;
		coordinate[k].y = 0;
	}
	for (int i = 0; i < COORDINATE_F; i++)
	{
		coordinate[i].x = (((COORDINATE_X / 2) + (COORDINATE_X / 2 / 4)) / 2) + i;
		coordinate[i].y = i + 1;
	}
}

Figure::~Figure()
{
}


void Figure::inverse(Figure* figure)
{
	int count = 0;
	bool bar[BOOL_ICON][BOOL_ICON];
	for (int i = 0; i < BOOL_ICON; i++)
		for (int j = 0; j < BOOL_ICON; j++)
			bar[i][j] = figure->ThisFigure[i][j].icon;
	
	for (int i = 0; i < BOOL_ICON; i++)
		for (int j = 0, k = BOOL_ICON - 1; j < BOOL_ICON; j++, k--)
				figure->ThisFigure[i][j].icon = bar[k][i];

	for (int i = 0; i < BOOL_ICON; i++)	
	{
		for (int j = 0; j < BOOL_ICON; j++)
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

