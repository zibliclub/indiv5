#include "matrix_class.hpp"

Matrix::Matrix(int rows, int cols)
{
    matrix.rows = rows;
    matrix.cols = cols;
    matrixElem = new float *[matrix.rows];
    for (int count = 0; count < 2; count++)
        matrixElem[count] = new float[matrix.cols];
}

void Matrix::Show()
{
    srand(time(0));
    for (int count_row = 0; count_row < matrix.rows; count_row++)
        for (int count_column = 0; count_column < matrix.cols; count_column++)
            matrixElem[count_row][count_column] = (rand() % 10 + 1) / float((rand() % 10 + 1));

    for (int count_row = 0; count_row < matrix.rows; count_row++)
    {
        for (int count_column = 0; count_column < matrix.cols; count_column++)
            std::cout << matrixElem[count_row][count_column] << "   ";
        std::cout << std::endl;
    }
}