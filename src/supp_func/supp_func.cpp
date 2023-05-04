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

void greeting()
{
    std::cout << "Hi! This is the testing program for Individual Assignment #5." << std::endl
              << "It presents the matrix editing function and binary inclusion sorting." << std::endl
              << std::endl
              << "Press Enter to continue";

    int pressButton;
    while (pressButton != ENTER)
        pressButton = _getch();
    system("cls");
}

void mainMenu(int &stage)
{
    std::cout << "Menu" << std::endl
              << std::endl
              << "  1). Create matrix" << std::endl
              << "  2). View matrix" << std::endl
              << "  3). Perform sorting" << std::endl
              << "  4). Edit matrix" << std::endl
              << "  5). Save matrix" << std::endl
              << "  6). Exit" << std::endl;

    stage = optionInput(6);
    system("cls");
}