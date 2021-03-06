#include "Figure.h"
#include "../Map/Map.h"
#include "../Factory/Factory.h"

Figure::Figure()
{
	heightFigure = 0;
	widthFigure = 0;
	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0; j < COORDINATE_F; j++)
            FigureElement[i][j].symbolFigure = 0;

	for (int i = 0; i < COORDINATE_F; i++)
	{
		Coordinate[i].x = 0;
		Coordinate[i].y = 0;
	}
	for (int i = 0; i < COORDINATE_F; i++)
	{
		Coordinate[i].x = (G_CENTER_LINE_OF_THE_MAP / 2) + i;
		Coordinate[i].y = i;
	}
}

Figure::~Figure() = default;

void Figure::inverse(Figure* pFigure)
{
	int count = 0;
	short tempMap[COORDINATE_F][COORDINATE_F];

	for (int i = 0; i < COORDINATE_F; i++)
		for (int j = 0, k = COORDINATE_F - 1; j < COORDINATE_F; j++, k--) {
            tempMap[i][j] = pFigure->FigureElement[k][i].symbolFigure;
            pFigure->FigureElement[k][i].symbolFigure = 0;
        }

	for (int i = 0; i < COORDINATE_F; i++)
	{
		for (int j = 0; j < COORDINATE_F; j++)
		{
			count = (COORDINATE_F - pFigure->heightFigure);
			if (tempMap[i][j])
			{
                pFigure->FigureElement[i][j-count].symbolFigure = tempMap[i][j-count] = getColor();//219 + 255*(getColor());
                pFigure->FigureElement[i][j].symbolFigure = 0;
			}
		}
	}
	int temp = pFigure->heightFigure;
	pFigure->heightFigure = pFigure->widthFigure;
	pFigure->widthFigure = temp;
}

void Figure::setColor(int color) {
	this->color = color;
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

