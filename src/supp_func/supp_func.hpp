#ifndef SUPP_FUNC_HPP
#define SUPP_FUNC_HPP

#include <iostream>
#include <limits>
#include <conio.h>

#include "../constant.hpp"
#include "../matrix_class/matrix_class.hpp"

int countOfRowsInput();
int countOfColsInput();
int optionInput(int);
int intInput();
void greeting();
void mainMenu(int &);
void createMatrix(int &, Matrix &);
void viewMatrix(int &, Matrix &);
void exitProgram(int &);
void saveMatrix(int &, Matrix &);

#endif