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



void merge(int* original_array, int* array1, int* array2, int length1, int length2) {

	int count1 = 0;
	int count2 = 0;



	while ((count1 + count2) < (length1 + length2)) {
		if (count1 >= length1) {
			original_array[count1 + count2] = array2[count2];
			count2 += 1;
		}

		else if (count2 >= length2) {
			original_array[count1 + count2] = array1[count1];
			count1 += 1;
		}

		else if (array1[count1] < array2[count2]) {
			original_array[count1 + count2] = array1[count1];
			count1 += 1;
		}

		else {
			original_array[count1 + count2] = array2[count2];
			count2 += 1;
		}
	}
}


void mergesort(int *array, int length) {


	int middle = length / 2;

	if (length <= 1) {
		return;
	}

	int array1[middle];
	int array2[length - middle];

	for(int i = 0; i < middle; i++) {
		array1[i] = array[i];
	}
	for (int j = 0; j < length - middle; j++) {
		array2[j] = array[j + middle];
	}


	mergesort(array1, middle);
	mergesort(array2, length - middle);


	merge(array, array1, array2, middle, length - middle);


}






int main() {


	int array[SIZE];

	for (int k = 0; k < SIZE; k++) {
		array[k] = (rand() %RANGE);
	}

	clock_t start = clock();
	mergesort(array, SIZE);
	clock_t end = clock();
	clock_t ticks = end - start;
	double duration = ticks / (double) CLOCKS_PER_SEC;
	cout << duration << endl;
	return 0;
}