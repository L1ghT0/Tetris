#pragma once
#include <iostream> // for "rand()"
#include <cstdlib>
#include <ctime>
#include "../Figuries/Figure.h"
#include "../Figuries/L_Figure.h"
#include "../Figuries/Back_L_Figure.h"
#include "../Figuries/Z_Figure.h"
#include "../Figuries/Back_Z_Figure.h"
#include "../Figuries/Line_Figure.h"
#include "../Figuries/Square_Figure.h"
#include "../Figuries/T_Figure.h"

class Factory
{
public:
	static Figure* figures();
};

