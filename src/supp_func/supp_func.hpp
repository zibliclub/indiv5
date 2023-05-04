#ifndef SUPP_FUNC_HPP
#define SUPP_FUNC_HPP

#include <iostream>
#include <limits>
#include <conio.h>

#include "../constant.hpp"

struct MatrixInfo
{
    int rows;
    int cols;
};

int countOfRowsInput();
int countOfColsInput();
int optionInput(int);
void greeting();
void mainMenu(int &);

#endif