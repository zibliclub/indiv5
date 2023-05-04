#include "supp_func.hpp"

int countOfRowsInput()
{
    int *num = new int;
    while (true)
    {
        std::cout << "Enter number of matrix rows: ";
        std::cin >> *num;
        if (std::cin.good() and *num > 0)
            break;
        else if (std::cin.fail() or *num < 1)
        {
            std::cerr << "The entered value is invalid." << std::endl
                      << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            continue;
        }
    }
    return *num;
    delete num;
}

int countOfColsInput()
{
    int *num = new int;
    while (true)
    {
        std::cout << "Enter number of matrix columns: ";
        std::cin >> *num;
        if (std::cin.good() and *num > 0)
            break;
        else if (std::cin.fail() or *num < 1)
        {
            std::cerr << "The entered value is invalid." << std::endl
                      << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            continue;
        }
    }
    return *num;
    delete num;
}

int optionInput(int max)
{
    int *option = new int(0);
    while (*option <= 0 or *option > max)
    {
        std::cout << std::endl
                  << "Enter a value: ";
        std::cin >> *option;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (*option <= 0 or *option > max)
            std::cerr << "The entered value is invalid." << std::endl;
    }
    return *option;
    delete option;
}