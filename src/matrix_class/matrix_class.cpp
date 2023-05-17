#include "matrix_class.hpp"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
    for (int count = 0; count < matrixInfo.rows; count++)
        delete[] matrixElem[count];
}

void Matrix::Fill(int rows, int cols, int option)
{
    matrixInfo.rows = rows;
    matrixInfo.cols = cols;
    matrixInfo.number = rows * cols;
    matrixElem = new int *[matrixInfo.rows];
    for (int count = 0; count < matrixInfo.rows; count++)
        matrixElem[count] = new int[matrixInfo.cols];

    switch (option)
    {
    case 1:
        srand(time(0));
        for (int count_row = 0; count_row < matrixInfo.rows; count_row++)
            for (int count_column = 0; count_column < matrixInfo.cols; count_column++)
                matrixElem[count_row][count_column] = rand() % 10 + 1;
        break;
    case 2:
    {
        std::cout << std::endl
                  << "The file must be in the 'files' directory." << std::endl
                  << std::endl
                  << "Enter the file name (without .txt): ";
        std::string fileName, name;
        std::cin >> name;
        fileName = "../../files/" + name + ".txt";

        std::fstream file(fileName, std::ios::in | std::ios::binary);
        for (int count_row = 0; count_row < matrixInfo.rows; count_row++)
            for (int count_column = 0; count_column < matrixInfo.cols; count_column++)
                file.read((char *)&matrixElem[count_row][count_column], sizeof(matrixElem));
        file.close();
        break;
    }

    case 3:
        std::cout << std::endl
                  << "Enter n whole numbers (where n=" << matrixInfo.number << "):" << std::endl
                  << std::endl;
        for (int count_row = 0; count_row < matrixInfo.rows; count_row++)
            for (int count_column = 0; count_column < matrixInfo.cols; count_column++)
            {
                int num;
                while (!(std::cin >> num))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Not an integer was entered, try again" << std::endl
                              << std::endl;
                };
                matrixElem[count_row][count_column] = num;
            }
        break;

    default:
        std::cerr << "Unforeseeable error" << std::endl;
        break;
    }
}

void Matrix::Show()
{
    if (matrixInfo.number == 0)
        std::cout << "The matrix is not created" << std::endl;
    else
    {
        for (int count_row = 0; count_row < matrixInfo.rows; count_row++)
        {
            for (int count_column = 0; count_column < matrixInfo.cols; count_column++)
                std::cout << std::setw(5) << std::setprecision(2) << matrixElem[count_row][count_column] << "   ";
            std::cout << std::endl;
        }
    }
}

void Matrix::Sort()
{
    struct element
    {
        int value;
        int num;
    };

    element absValOfTheSumsOfMatrixRowElem[matrixInfo.rows];
    for (int count_row = 0; count_row < matrixInfo.rows; count_row++)
    {
        absValOfTheSumsOfMatrixRowElem[count_row].value = 0;
        absValOfTheSumsOfMatrixRowElem[count_row].num = count_row;
        for (int count_column = 0; count_column < matrixInfo.cols; count_column++)
            absValOfTheSumsOfMatrixRowElem[count_row].value += matrixElem[count_row][count_column];
        absValOfTheSumsOfMatrixRowElem[count_row].value = abs(absValOfTheSumsOfMatrixRowElem[count_row].value);
    }
    for (int i = 0; i < matrixInfo.rows; i++)
        std::cout << absValOfTheSumsOfMatrixRowElem[i].value << " " << absValOfTheSumsOfMatrixRowElem[i].num << std::endl;

    int left, right, middle;
    element x;

    for (int i = 1; i < matrixInfo.rows; i++)
    {
        if (absValOfTheSumsOfMatrixRowElem[i - 1].value > absValOfTheSumsOfMatrixRowElem[i].value)
        {
            x = absValOfTheSumsOfMatrixRowElem[i];
            left = 0;
            right = i - 1;
            do
            {
                middle = (left + right) / 2;
                if (absValOfTheSumsOfMatrixRowElem[middle].value < x.value)
                    left = middle + 1;
                else
                    right = middle - 1;
            } while (left <= right);
            for (int j = i - 1; j >= left; j--)
                absValOfTheSumsOfMatrixRowElem[j + 1] = absValOfTheSumsOfMatrixRowElem[j];
            absValOfTheSumsOfMatrixRowElem[left] = x;
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < matrixInfo.rows; i++)
        std::cout << absValOfTheSumsOfMatrixRowElem[i].value << " " << absValOfTheSumsOfMatrixRowElem[i].num << std::endl;

    int changingRows[matrixInfo.cols];
    for (int i = 0; i < matrixInfo.rows; i++)
    {
        if (absValOfTheSumsOfMatrixRowElem[i].num != i)
        {
            int c = absValOfTheSumsOfMatrixRowElem[i].num;

            for (int j = 0; j < matrixInfo.rows; j++)
            {
                if (absValOfTheSumsOfMatrixRowElem[j].num == i)
                {
                    for (int j = 0; j < matrixInfo.cols; j++)
                        changingRows[j] = matrixElem[i][j];
                    for (int j = 0; j < matrixInfo.cols; j++)
                        matrixElem[i][j] = matrixElem[absValOfTheSumsOfMatrixRowElem[i].num][j];
                    for (int j = 0; j < matrixInfo.cols; j++)
                        matrixElem[absValOfTheSumsOfMatrixRowElem[i].num][j] = changingRows[j];
                }
            }
        }
    }
}

void Matrix::Save(std::string fileName)
{
    std::fstream file(fileName, std::ios::out | std::ios::binary);
    for (int count_row = 0; count_row < matrixInfo.rows; count_row++)
        for (int count_column = 0; count_column < matrixInfo.cols; count_column++)
            file.write((const char *)&matrixElem[count_row][count_column], sizeof(matrixElem));
    file.close();
}

// int Matrix::Editor() {
//     char prev = cout.fill(border2);

//     if (array == NULL ) return -1;

//     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//     // координаты пользователя
//     int x = 0, y = 0;

//     // высота и ширина видимой части матрицы
//     int startHeight = 0, stopHeight = 5, startWidth = 0, stopWidth = 5;
//     if (stopHeight > rows) stopHeight = rows;
//     if (stopWidth > cols) stopWidth = cols;

//     // счетчик нажатия клавиш
//     int tap = 0;

//     while (tap != 27) {
//         system("cls");

//         // вывод матрицы
//         for (int i = startHeight; i < stopHeight; i++) {
//             for (int j = startWidth; j < stopWidth; j++) {
//                 if (i == x && j == y) {
//                     SetConsoleTextAttribute(h, 240);
//                     cout << setw(5) << array[j][i];
//                 }
//                 else {
//                     SetConsoleTextAttribute(h, 8);
//                     cout << setw(5) << array[j][i];
//                 }
//             }
//             cout << endl;
//         }
//         SetConsoleTextAttribute(h, 7);
//         cout << endl;

//         cout << " - " << " для перемещения используйте стрелки" << endl;

//         cout << "Enter - редактировать данный элемент" << endl;
//         cout << "f - перейти к элементу" << endl;
//         cout << "Esc - вернуться в меню" << endl << endl;
//         cout << "|" << x << "||" << y << "|: " << array[y][x];

//         tap = _getch();
//         // редактировать элемент
//         if (tap == 13) {
//             int ok, tmp;
//             system("cls");
//             cout << "старое значение |" << x << "||" << y << "|: " << array[y][x] << endl;
//             cout << "новое значение |" << x << "||" << y << "|: ";
//             cin >> tmp;
//             cout << endl;
//             cout << "Данные будут безвовратно изменены. Вы уверены, что хотите продолжить?" << endl;
//             cout << "Enter - продолжить" << endl;
//             cout << "Esc - вернуться к редактору" << endl;
//             do {
//                 ok = _getch();
//             } while (ok != 13 && ok != 27);
//             if (ok == 13) array[y][x] = tmp;
//         }

//         // переход к элементу
//         if (tap == 102) {
//             int x1, y1;
//             do {
//                 system("cls");
//                 cout << "индекс строки: ";
//                 cin >> x1;
//                 cout << "индекс столбца: ";
//                 cin >> y1;
//             } while (x1 < 0 || y1 < 0 || x1 >= rows || y1 >= cols);
//             while (x > x1) {
//                 x--;
//                 if (x == startHeight - 1) {
//                     startHeight--;
//                     stopHeight--;
//                 }
//             }
//             while (x < x1) {
//                 x++;
//                 if (x == stopHeight) {
//                     startHeight++;
//                     stopHeight++;
//                 }
//             }
//             while (y < y1) {
//                 y++;
//                 if (y == stopWidth) {
//                     startWidth++;
//                     stopWidth++;
//                 }
//             }
//             while (y > y1) {
//                 y--;
//                 if (y == startWidth - 1) {
//                     startWidth--;
//                     stopWidth--;
//                 }
//             }
//         }

//         // стрелка вверх
//         if (tap == 72 && x != 0) {
//             x--;
//             if (x == startHeight - 1) {
//                 startHeight--;
//                 stopHeight--;
//             }
//         }

//         // стрелка вниз
//         if (tap == 80 && x != rows - 1) {
//             x++;
//             if (x == stopHeight) {
//                 startHeight++;
//                 stopHeight++;
//             }
//         }

//         // стрелка вправо
//         if (tap == 77 && y != cols - 1) {
//             y++;
//             if (y == stopWidth) {
//                 startWidth++;
//                 stopWidth++;
//             }
//         }

//         // стрелка влево
//         if (tap == 75 && y != 0) {
//             y--;
//             if (y == startWidth - 1) {
//                 startWidth--;
//                 stopWidth--;
//             }
//         }

//     }

//     return 0;
// }