#include <iostream>
#include <conio.h>

#include "supp_func/supp_func.hpp"
#include "matrix_class/matrix_class.hpp"
#include "indiv_func/indiv_func.hpp"

// Program Stages:
// 0. Main menu
// 1. Creating a matrix
// 2. View matrix
// 3. Performing sorting
// 4. Editing a matrix
// 5. Saving a matrix

int main(int argc, char *argv[])
{
    greeting();

    Matrix matrix;
    int programStage = 0;
    while (programStage != -1)
    {
        switch (programStage)
        {
        case 0:
            mainMenu(programStage);
            break;

        case 1:
        {
            int rows = countOfRowsInput();
            int cols = countOfColsInput();

            std::cout << std::endl
                      << "Choose how you want to fill the matrix: " << std::endl
                      << "  1). With random values" << std::endl
                      << "  2). From a file" << std::endl
                      << "  3). Manually";
            int option = optionInput(3);

            matrix.Fill(rows, cols, option);
            system("cls");
            programStage = 0;
            break;
        }

        case 2:
        {
            matrix.Show();
            std::cout << std::endl
                      << "Press Enter to continue";
            int pressButton = 0;
            while (pressButton != ENTER)
                pressButton = _getch();
            system("cls");
            programStage = 0;
            break;
        }

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
            /* code */
            break;

        case 6:
            programStage = -1;
            break;

        default:
            std::cerr << "Unintended error" << std::endl;
            break;
        }
    }
    
    return 0;
}