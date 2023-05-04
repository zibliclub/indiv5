#ifndef MATRIX_CLASS_HPP
#define MATRIX_CLASS_HPP

#include <iostream>
#include <ctime>
#include <iomanip>

#include "../supp_func/supp_func.hpp"

class Matrix
{
private:
    MatrixInfo matrix;
    float **matrixElem;

public:
    Matrix(int, int);
    void Show();
};

#endif