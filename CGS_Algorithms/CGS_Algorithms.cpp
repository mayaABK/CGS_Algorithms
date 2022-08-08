#include "MergeSort.h"

#include <iostream>
#include <iterator>
#include <time.h>

using namespace std;

void runMergeSort();

int main()
{
	runMergeSort();
}

void populateRandomArray(int* numbers, int size)
{

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand();
	}
}

void runMergeSort()
{
	cout << "Enter the size of your randomly generated array: ";
	int size;
	cin >> size;
	int* numbers = new int[size];

	srand(time(0));
	populateRandomArray(numbers, size);

	cout << endl << "Your randomly generated array is: {";
	copy(numbers, numbers + size, ostream_iterator<int>(cout, " "));
	cout << " }" << endl;

	MergeSort mergesort(numbers, size);

	mergesort.run();
	mergesort.printArray();

	delete[] numbers;
	numbers = nullptr;
}