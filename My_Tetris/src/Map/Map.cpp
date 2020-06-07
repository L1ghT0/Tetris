#include "Map.h"


Map::Map()
{
	icon = 220;
	AddFigure = false;
	
	for (int i = 0; i < G_COORDINATE_Y; i++)
		for (int j = 0; j < G_COORDINATE_X; j++)
			mapFigures[i][j] = 0;
}

void Map::addOnMap(Figure* pFigure)
{
	for (int i = 0; i < G_COORDINATE_Y; i++)
	{
		for (int j = 0; j < G_COORDINATE_X; j++)
		{
			if (mapFigures[i][j] > 0)
			{
				map[i][j] = this->icon = 219 + 255 * mapFigures[i][j];
				AddFigure = true;
			}
			if (i == 0)
				map[i][j] = this->icon = 220;
			else if (j == 0 || j == G_CENTER_OF_MAP || j == (G_COORDINATE_X-1) || i == (G_COORDINATE_Y-1))
				map[i][j] = this->icon = 219;
			else
			{
				for (int k = 0; k < COORDINATE_F; k++)
				{
					for (int l = 0; l < COORDINATE_F; l++)
					{
						if (i == pFigure->Coordinate[k].y && j == pFigure->Coordinate[l].x && pFigure->ThisFigure[k][l].icon > 0)
						{
							map[i][j] = this->icon = 219 + 255*(pFigure->getColor());
							AddFigure = true;
						}
					}
				}
				if (!AddFigure)
				{
					map[i][j] = ' ';
				}
				AddFigure = false;
			}
		}
	}
}

void Map::Print_map(int score)
{
	OsHelper::m_sysCLaer();
	for (int i = 0; i < G_COORDINATE_Y; i++)
	{
		for (int j = 0; j < G_COORDINATE_X; j++)
		{
			if (map[i][j] > 255 || mapFigures[i][j] > 0)
			{
			        int colorNum = map[i][j] / 255;
			        OsHelper::change_color(0, colorNum);
				    std::cout << (char)(map[i][j] % 255);
				    OsHelper::reset_color();
            }
			else
				std::cout << (char)map[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << score << std::endl;
}

void Map::saveFigureOnMap(Figure* pFigure)
{
	for (int i = 0; i < G_COORDINATE_Y; i++)
	{
		for (int j = 0; j < G_COORDINATE_X; j++)
		{
			for (int k = 0; k < COORDINATE_F; k++)
			{
				for (int l = 0; l < COORDINATE_F; l++)
				{
					if (i == pFigure->Coordinate[k].y && j == pFigure->Coordinate[l].x && pFigure->ThisFigure[k][l].icon > 0)
					{
						mapFigures[i][j] = pFigure->getColor();
					}
				}
			}
		}
	}
}

short Map::getMap(const int y, const int x)
{
	return this->map[y][x];
}

short Map::getFiguresMap(const int y, const int x)
{
	return this->mapFigures[y][x];
}

void Map::setFiguresMap(const int y, const int x, const short icon)
{
	this->mapFigures[y][x] = icon;
}

