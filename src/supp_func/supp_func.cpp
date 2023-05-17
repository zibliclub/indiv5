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

int intInput()
{
    int N;
    for (;;)
    {
        if ((std::cin >> N).good())
            return N;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Incorrect input, try again" << std::endl;
        }
        else
            std::cout << "The number is out of the valid value range. Repeat the entry" << std::endl;
        std::cin.ignore(100, '\n');
    }
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

void createMatrix(int &stage, Matrix &matrix)
{
    int rows = countOfRowsInput();
    int cols = countOfColsInput();

    std::cout << std::endl
              << "Choose how you want to fill the matrix: " << std::endl
              << std::endl
              << "  1). With random values" << std::endl
              << "  2). From a file" << std::endl
              << "  3). Manually" << std::endl;
    int option = optionInput(3);

    matrix.Fill(rows, cols, option);
    system("cls");
    stage = 0;
}

void viewMatrix(int &stage, Matrix &matrix)
{
    matrix.Show();
    std::cout << std::endl
              << "Press Enter to continue";
    int pressButton = 0;
    while (pressButton != ENTER)
        pressButton = _getch();
    system("cls");
    stage = 0;
}

void saveMatrix(int &stage, Matrix &matrix)
{
    std::cout << "The matrix will be saved in a binary file in the 'files' directory." << std::endl
              << std::endl
              << "Specify the file name (without .txt): ";
    std::string fileName, name;
    std::cin >> name;
    fileName = "../../files/" + name + ".txt";

    matrix.Save(fileName);

    system("cls");
    stage = 0;
}

void exitProgram(int &stage)
{
    std::cout << "Are you sure you want to complete the program?" << std::endl
              << "All unsaved data will be lost." << std::endl
              << std::endl
              << "  1). Exit" << std::endl
              << "  2). Return" << std::endl;

    int option = optionInput(2);
    if (option == 2)
    {
        stage = 0;
        system("cls");
    }
    else
        stage = -1;
}