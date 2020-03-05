#pragma once
#include <iostream> // for "rand()"
#include "Figure.h"
#include "L_Figure.h"
#include "Back_L_Figure.h"
#include "Z_Figure.h"
#include "Back_Z_Figure.h"
#include "Line_Figure.h"
#include "Square_Figure.h"
#include "T_Figure.h"

class Factory
{
public:
	static Figure* figures();
};

