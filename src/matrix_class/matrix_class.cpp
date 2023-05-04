#include "matrix_class.hpp"

Matrix::Matrix(int rows, int cols)
{
    matrix.rows = rows;
    matrix.cols = cols;
    matrixElem = new float *[matrix.rows];
    for (int count = 0; count < matrix.rows; count++)
        matrixElem[count] = new float[matrix.cols];
}

Matrix::~Matrix()
{
    for (int count = 0; count < matrix.rows; count++)
        delete []matrixElem[count];
}

void Matrix::Fill(int option)
{
    switch (option)
    {
    case 1:
        srand(time(0));
        for (int count_row = 0; count_row < matrix.rows; count_row++)    
            for (int count_column = 0; count_column < matrix.cols; count_column++)
                matrixElem[count_row][count_column] = (rand() % 10 + 1) / float((rand() % 10 + 1));
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    
    default:
        std::cerr << "Unforeseeable error" << std::endl;
        break;
    }
}

void Matrix::Show()
{
    for (int count_row = 0; count_row < matrix.rows; count_row++)
    {
        for (int count_column = 0; count_column < matrix.cols; count_column++)
            std::cout << std::setw(5) << std::setprecision(2) << matrixElem[count_row][count_column] << "   ";
        std::cout << std::endl;
    }
}