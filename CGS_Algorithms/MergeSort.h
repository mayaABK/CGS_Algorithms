#pragma once
class MergeSort
{
public:
	MergeSort(int* numbers, int size) { this->numbers = numbers; this->size = size; }
	void run();
	void printArray();
private:
	int* numbers;
	int size;
	void mergeSort(int startIdx, int endIdx);
	void merge(int startIdx, int midIdx, int endIdx);
};

