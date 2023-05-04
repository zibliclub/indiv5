#include <iostream>

#include "supp_func/supp_func.hpp"
#include "matrix_class/matrix_class.hpp"
#include "indiv_func/indiv_func.hpp"

int main(int argc, char* argv[])
{
    int rows = countOfRowsInput();
    int cols = countOfColsInput();

    Matrix matrix(rows, cols);

    std::cout << "Choose how you want to fill the matrix: " << std::endl
              << "  1). With random values" << std::endl
              << "  2). From a file" << std::endl
              << "  3). Manually";
    int option = optionInput(3);

    matrix.Fill(option);

    matrix.Show();

    system("pause");
    return 0;
}