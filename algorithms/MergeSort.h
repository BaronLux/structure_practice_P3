#pragma once
#include "Algorithm.h"
class MergeSort :
    public Algorithm
{
    string name = "merge";

    int* Alg(int* a, int n) final
    {
        int mid = n / 2; // находим середину сортируемой последовательности
        if (n % 2 == 1)
            mid++;
        int h = 1; // шаг
        // выделяем память под формируемую последовательность
        int* c = new int[n];
        int step;
        while (h < n)
        {
            step = h;
            int i = 0;   // индекс первого пути
            int j = mid; // индекс второго пути
            int k = 0;   // индекс элемента в результирующей последовательности
            while (step <= mid)
            {
                while ((i < step) && (j < n) && (j < (mid + step)))
                { // пока не дошли до конца пути
                  // заполняем следующий элемент формируемой последовательности
                  // меньшим из двух просматриваемых
                    this->iter_count++;
                    this->comparison_count++;
                    if (a[i] < a[j])
                    {
                        c[k] = a[i];
                        i++; k++;
                    }
                    else {
                        c[k] = a[j];
                        j++; k++;
                    }
                }
                while (i < step)
                { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                    this->iter_count++;
                    c[k] = a[i];
                    i++; k++;
                }
                while ((j < (mid + step)) && (j < n))
                {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                    this->iter_count++;
                    c[k] = a[j];
                    j++; k++;
                }
                step = step + h; // переходим к следующему этапу
            }
            h = h * 2;
            // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
            for (i = 0; i < n; i++)
            {
                this->iter_count++;
                a[i] = c[i];
            }
        }
        return a;
    }
public:
    MergeSort() :Algorithm()
    {
        name = "merge";
    }

    void Print() final
    {
        //string name = typeid(*this).name() + '\n';
        cout << delimiter + name << endl;
        cout << "iter_count=" << iter_count << endl;
        cout << "comparison_count=" << comparison_count << endl;
        cout << "elapsed[ns]=" << elapsed << endl;
        cout << delimiter;
    }
    //void Print()
    //{
    //    //string name = typeid(*this).name() + '\n';
    //    string delimiter = "-------------------------------------------------------------\n";
    //    cout << delimiter + name << endl;
    //    cout << "iter_count=" << iter_count << endl;
    //    cout << "comparison_count=" << comparison_count << endl;
    //    cout << "elapsed[ms]=" << elapsed << endl;
    //}
};

