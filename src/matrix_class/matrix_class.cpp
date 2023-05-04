#include "matrix_class.hpp"

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
    for (int count = 0; count < matrix.rows; count++)
        delete []matrixElem[count];
}

void Matrix::Fill(int rows, int cols, int option)
{
    matrix.rows = rows;
    matrix.cols = cols;
    matrixElem = new float *[matrix.rows];
    for (int count = 0; count < matrix.rows; count++)
        matrixElem[count] = new float[matrix.cols];

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