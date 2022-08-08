#include "MergeSort.h"

#include <iostream>

using namespace std;

//Example of runMergeSort:
// 
//Given: numbers[ 5, 2, 8, 9, 1 ] 
// 
//   mSort[ 5, 2, 8 ]
//   mSort[ 5, 2]
//   mSort[ 5 ]
//   mSort[ 2, 8, 9, 1 ]
//   mSort[ 2, 8 ]
//   mSort[ 2 ]
//   mSort[ 8, 9, 1 ]
//   mSort[ 8, 9 ]
//   mSort[ 8 ]
//   mSort[ 9, 1 ]
//   mSort[ 9 ]
//   mSort[ 1 ]
void MergeSort::mergeSort(int startIdx, int endIdx)
{
	if (startIdx >= endIdx)
	{
		return;
	}

	int midIdx = (startIdx + endIdx) / 2;

	mergeSort(startIdx, midIdx);
	mergeSort(midIdx + 1, endIdx);
	merge(startIdx, midIdx, endIdx);
}


void MergeSort::merge(int startIdx, int midIdx, int endIdx)
{
	int leftArraySize = midIdx - startIdx + 1;
	int rightArraySize = endIdx - midIdx;

	int* leftArray = new int[leftArraySize];
	int* rightArray = new int[rightArraySize];

	//populate left array
	for (int i = 0; i < leftArraySize; i++)
	{
		leftArray[i] = numbers[startIdx + i];
	}

	//populate right array
	for (int i = 0; i < rightArraySize; i++)
	{
		rightArray[i] = numbers[midIdx + i + 1];
	}

	//only process the smaller value between the left and right array until one or both arrays have been processed.
	int tempLeftArrayIdx = 0;
	int tempRightArrayIdx = 0;
	int tempNumbersIdx = startIdx;

	while ( tempLeftArrayIdx < leftArraySize && tempRightArrayIdx < rightArraySize )
	{
		if (leftArray[tempLeftArrayIdx] < rightArray[tempRightArrayIdx])
		{
			numbers[tempNumbersIdx] = leftArray[tempLeftArrayIdx];
			tempLeftArrayIdx++;
		}
		else
		{
			numbers[tempNumbersIdx] = rightArray[tempRightArrayIdx];
			tempRightArrayIdx++;
		}

		tempNumbersIdx++;
	}

	// process any remaining values in the left or right array. Only one array will still contain unprocessed values if any
	if (tempLeftArrayIdx < leftArraySize)
	{
		while (tempLeftArrayIdx < leftArraySize)
		{
			numbers[tempNumbersIdx] = leftArray[tempLeftArrayIdx];
			tempNumbersIdx++;
			tempLeftArrayIdx++;
		}
	}
	else if (tempRightArrayIdx < rightArraySize)
	{
		while (tempRightArrayIdx < rightArraySize)
		{
			numbers[tempNumbersIdx] = rightArray[tempRightArrayIdx];
			tempNumbersIdx++;
			tempRightArrayIdx++;
		}
	}

	//memory cleanup
	delete[] leftArray;
	leftArray = nullptr;
	delete[] rightArray;
	rightArray = nullptr;
}

void MergeSort::run()
{
	mergeSort(0, size - 1);
}

void MergeSort::printArray()
{
	cout << "Sorted array is: { ";
	copy(numbers, numbers + size, ostream_iterator<int>(cout, " "));
	cout << " }" << endl;
}
