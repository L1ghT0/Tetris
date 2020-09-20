#include "Factory.h"

Figure* Factory::figures()
{
	srand(time(NULL));
	Figure* figure = nullptr;
	int random = rand() % 7;
	int color = (random+1);
	switch (random)
	{
	case(0):
		figure = new L_Figure();
		break;
	case(1):
		figure = new Back_L_Figure();
		break;
	case(2):
		figure = new Z_Figure();
		break;
	case(3):
		figure = new Back_Z_Figure();
		break;
	case(4):
		figure = new T_Figure();
		break;
	case(5):
		figure = new Square_Figure();
		break;
	case(6):
		figure = new Line_Figure();
		break;
	}
	figure->setColor(color);
	return figure;
}
