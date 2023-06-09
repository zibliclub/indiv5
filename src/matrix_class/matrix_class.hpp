#ifndef MATRIX_CLASS_HPP
#define MATRIX_CLASS_HPP

#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <limits>

#include "../indiv_func/indiv_func.hpp"

struct MatrixInfo
{
    int rows;
    int cols;
    int number = 0;
};

class Matrix
{
private:
    MatrixInfo matrixInfo;
    int **matrixElem;

public:
    Matrix();

    void Fill(int, int, int);
    void Show();
    void Sort();
    void Save(std::string);
    int Editor();

    ~Matrix();
};

#endif