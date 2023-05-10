#include <iostream>

#include "supp_func/supp_func.hpp"
#include "matrix_class/matrix_class.hpp"
#include "indiv_func/indiv_func.hpp"

int main(int argc, char *argv[])
{
    greeting();

    Matrix matrix;
    int programStage = MAIN_MENU;

    while (programStage != COMPLETE)
    {
        switch (programStage)
        {
        case MAIN_MENU:
            mainMenu(programStage);
            break;

        case CREATE_MATRIX:
            createMatrix(programStage, matrix);
            break;

        case VIEW_MATRIX:
            viewMatrix(programStage, matrix);
            break;

        case PERFORM_SORT:
            matrix.Sort();
            system("pause");
            programStage = MAIN_MENU;
            break;

        case EDIT_MATRIX:
            /* code */
            break;

        case SAVE_MATRIX:
            saveMatrix(programStage, matrix);
            break;

        case EXIT:
            exitProgram(programStage);
            break;

        default:
            std::cerr << "Unintended error" << std::endl;
            break;
        }
    }

    return 0;
}