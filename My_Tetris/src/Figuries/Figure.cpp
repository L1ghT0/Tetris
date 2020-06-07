#include "Figure.h"
#include "../Map/Map.h"
#include "../Factory/Factory.h"

Figure::Figure()
{
	heightFigure = 0;
	widthFigure = 0;
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0; j < COORDINATE_F; j++)
			ThisFigure[i][j].icon = 0;

	for (int i = 0; i < COORDINATE_F; i++)
	{
		Coordinate[i].x = 0;
		Coordinate[i].y = 0;
	}
	for (int i = 0; i < COORDINATE_F; i++)
	{
		Coordinate[i].x = (((G_COORDINATE_X / 2) + (G_COORDINATE_X / 2 / 4)) / 2) + i;
		Coordinate[i].y = i + 1;
	}
}

Figure::~Figure() = default;

void Figure::inverse(Figure* pFigure)
{   // Fix inverse
	int count = 0;
	short bar[COORDINATE_F][COORDINATE_F];
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0; j < COORDINATE_F; j++)
			bar[i][j] = pFigure->ThisFigure[i][j].icon;

	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0, k = COORDINATE_F - 1; j < COORDINATE_F; j++, k--)
			pFigure->ThisFigure[i][j].icon = bar[k][i];

	for (int i = 0; i < COORDINATE_F; i++)
	{
		for (int j = 0; j < COORDINATE_F; j++)
		{
			count = (COORDINATE_F - pFigure->heightFigure);
			if (pFigure->ThisFigure[i][j].icon)
			{
				pFigure->ThisFigure[i][j-count].icon = 219 + 255 * (getColor());
				pFigure->ThisFigure[i][j].icon = 0;
			}
		}
	}
	int temp = pFigure->heightFigure;
	pFigure->heightFigure = pFigure->widthFigure;
	pFigure->widthFigure = temp;
}

void Figure::setColor(int color) {
	color == 7 ? this->color = (color+3) : this->color = color;	// "7" - defaults color
}

int Figure::getColor() {
	return this->color;
}

int Figure::getHeightFigure() {
    return this->heightFigure;
}

int Figure::getWidthFigure() {
    return this->widthFigure;
}

Figure *Figure::createFigure() {
    Figure* figure = Factory::figures();
    figure->push_figure();
    return figure;
}

