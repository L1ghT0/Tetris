#include "Map.h"


Map::Map()
{
	icon = 220;
	AddFigure = false;
	
	for (int i = 0; i < G_COORDINATE_Y; i++)
		for (int j = 0; j < G_COORDINATE_X; j++)
            mapForStoppedFigures[i][j] = 0;
}

void Map::addOnMap(Figure* pFigure)
{
	for (int i = 0; i < G_COORDINATE_Y; i++)
	{
		for (int j = 0; j < G_COORDINATE_X; j++)
		{
			if (mapForStoppedFigures[i][j] > 0)
			{
				map[i][j].symbol = "\u2588";
				AddFigure = true;
			}
			if (i == 0)
				map[i][j].symbol = "\u2583";
            else if(i == (G_COORDINATE_Y-1))
                map[i][j].symbol = "\u2580";
            else if (j == 0 || j == G_CENTER_LINE_OF_THE_MAP || j == (G_COORDINATE_X-1))
				map[i][j].symbol = "\u2588";
			else
			{
				for (int k = 0; k < COORDINATE_F; k++)
				{
					for (int l = 0; l < COORDINATE_F; l++)
					{
						if (i == pFigure->Coordinate[k].y && j == pFigure->Coordinate[l].x && pFigure->FigureElement[k][l].symbolFigure > 0)
						{
							map[i][j].symbol = "\u2588";
							map[i][j].color = pFigure->getColor();
							AddFigure = true;
						}
					}
				}
				if (!AddFigure)
				{
					map[i][j].symbol = ' ';
				}
				AddFigure = false;
			}
		}
	}
}

void Map::Print_map()
{
	OsHelper::m_sysCLaer();
	for (int i = 0; i < G_COORDINATE_Y; i++)
	{
		for (int j = 0; j < G_COORDINATE_X; j++)
		{
			if (map[i][j].color > 0)
			{
			        OsHelper::change_color(0, map[i][j].color);
				    std::cout << map[i][j].symbol;
				    OsHelper::reset_color();
            }
			else
				std::cout << map[i][j].symbol;
		}
		std::cout << std::endl;
	}
	//std::cout << score << std::endl;
}

void Map::saveFigureOnMap(Figure* pFigure)
{
	for (int i = pFigure->Coordinate[0].y; i < G_COORDINATE_Y; i++)
	{
		for (int j = pFigure->Coordinate[0].x; j < G_COORDINATE_X; j++)
		{
			for (int k = 0; k < COORDINATE_F; k++)
			{
				for (int l = 0; l < COORDINATE_F; l++)
				{
					if (i == pFigure->Coordinate[k].y && j == pFigure->Coordinate[l].x && pFigure->FigureElement[k][l].symbolFigure > 0)
					{
                        mapForStoppedFigures[i][j] = true;
					}
				}
			}
		}
	}
}

std::string Map::getMap(const int y, const int x)
{
	return this->map[y][x].symbol;
}

short Map::getFiguresMap(const int y, const int x)
{
	return this->mapForStoppedFigures[y][x];
}

void Map::setFiguresMap(const int y, const int x, const short icon)
{
	this->mapForStoppedFigures[y][x] = icon;
}

