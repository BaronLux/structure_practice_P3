#pragma once
#include "Algorithm.h"
class MergeSort :
    public Algorithm
{
    string name = "merge";

    int* Alg(int* a, int n) final
    {
        int mid = n / 2; // ������� �������� ����������� ������������������
        if (n % 2 == 1)
            mid++;
        int h = 1; // ���
        // �������� ������ ��� ����������� ������������������
        int* c = new int[n];
        int step;
        while (h < n)
        {
            step = h;
            int i = 0;   // ������ ������� ����
            int j = mid; // ������ ������� ����
            int k = 0;   // ������ �������� � �������������� ������������������
            while (step <= mid)
            {
                while ((i < step) && (j < n) && (j < (mid + step)))
                { // ���� �� ����� �� ����� ����
                  // ��������� ��������� ������� ����������� ������������������
                  // ������� �� ���� ���������������
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
                { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                    this->iter_count++;
                    c[k] = a[i];
                    i++; k++;
                }
                while ((j < (mid + step)) && (j < n))
                {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                    this->iter_count++;
                    c[k] = a[j];
                    j++; k++;
                }
                step = step + h; // ��������� � ���������� �����
            }
            h = h * 2;
            // ��������� ������������� ������������������ (������������� �������) � �������� ������
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

