#pragma once
#include <stdlib.h>
class Generators
{
public:
	int* RandomGen(int n, int seed = 0)
	{
		auto arr = new int[n];
		srand(seed);
		for (size_t i = 0; i < n; i++)
		{
			arr[i] = rand();
		}
		return arr;
	}

	int* DesksortedGen(int n)
	{
		auto arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
		return arr;
	}

	int* AcsSortedGen(int n)
	{
		auto arr = new int[n];
		for (int i = n; i > 0; i--)
		{
			arr[i] = i;
		}
		return arr;
	}
};

