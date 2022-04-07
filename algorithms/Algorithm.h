#pragma once
#include <stdlib.h>
#include "omp.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <ostream>
#include <chrono>

using namespace std;

class Algorithm abstract // обстрактный класс, который не может иметь реализации
{
protected:
	int iter_count, comparison_count; // количество итераций и сравненей
	long long elapsed; // время затраченное на работу алгоритма
	string name;
	string delimiter = "----------------------\n";

	virtual int* Alg(int* arr, int n) = 0; // 
public:
	void Run(int* arr, int n)
	{
		iter_count = 0; comparison_count = 0;

		std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
		start = std::chrono::high_resolution_clock::now();
		Alg(arr, n);
		stop = std::chrono::high_resolution_clock::now();

		elapsed = std::chrono::duration_cast<chrono::nanoseconds> (stop - start).count();
	}
	//virtual void Print() = 0;

	virtual void Print() = 0;
};

