#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int const SIZE = 10000;
int const RANGE = 10000;


void print(int array[], int size) {

	for(int i = 0; i < size; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}



int partition(int* array, int start, int stop) {

	int index = start;
	int partitionVal = array[stop];

	for(int i = start; i < stop; i++) {

		if (array[i] < partitionVal) {
			int temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			index += 1;
		}

	}

	array[stop] = array[index];
	array[index] = partitionVal;
	return index;

}


void quicksort(int* array, int start, int stop) {


	if (start > stop) {
		return;
	}

	int i = partition(array, start, stop);
	quicksort(array, start, i - 1);
	quicksort(array, i + 1, stop);


}

int main() {

	int array[SIZE];

	for (int k = 0; k < SIZE; k++) {
		array[k] = (rand() %RANGE);
	}

	clock_t start = clock();
	quicksort(array, 0, SIZE - 1);
	clock_t end = clock();
	clock_t ticks = end - start;
	double duration = ticks / (double) CLOCKS_PER_SEC;

	cout << duration << endl;



	return 0;
}