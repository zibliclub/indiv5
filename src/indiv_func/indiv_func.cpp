#include "indiv_func.hpp"

void sortBinInsert(int *a, int n) // Сортировка бинарными вставками
{
    int left, right, sred;
    float x;

    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            x = a[i]; // x – включаемый элемент
            left = 0; // левая граница отсортированной части массива
            right = i - 1; // правая граница отсортированной части массива
            do
            {
                sred = (left + right) / 2; // sred – новая "середина" последовательности
                if (a[sred] < x)
                    left = sred + 1;
                else
                    right = sred - 1;
            } while (left <= right); // поиск ведется до тех пор, пока левая граница не окажется правее правой границы
            for (int j = i - 1; j >= left; j--)
                a[j + 1] = a[j];
            a[left] = x;
        }
    }
}