#include <iostream>

#include "supp_func/supp_func.hpp"
#include "matrix_class/matrix_class.hpp"
#include "indiv_func/indiv_func.hpp"

int main(int argc, char* argv[])
{
    std::cout << "MAMA" << std::endl;

    Matrix matrix(10, 15);
    matrix.Show();

    return 0;
}