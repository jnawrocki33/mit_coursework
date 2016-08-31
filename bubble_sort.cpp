#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int const SIZE = 1000;
int const RANGE = 1000;
int main()
{
	int array[SIZE];

	for (int k = 0; k < SIZE; k++) {
		array[k] = (rand() %RANGE);
	}

	for(int i = 0; i < SIZE; i++) {
		for (int j = i; j < SIZE; j++) {
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	for(int i = 0; i < SIZE; i++) {
		cout << array[i] << ", ";
	}

	return 0;
}