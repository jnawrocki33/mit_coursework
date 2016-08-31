#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int const SIZE = 100000000;


// int distance(double x, double y) {
// 	return (x*x + y*y)
// }


int main() {

	int count = 0;
	for(int i = 0; i < SIZE; i++) {

		double x = rand() / (double)RAND_MAX;
		double y = rand() / (double)RAND_MAX;

		//cout << "(" << x << ", " << y << ") - distance: " << sqrt(x*x + y*y) << endl;

		if (sqrt(x*x + y*y) < 1) {
			count += 1;
		}


	}	
	int area_square = 2 * 2;
	double area_circle = count / (double) SIZE * area_square;

	int radius = 1;
	double pi = area_circle / (radius * radius);
	cout << "pi = " << pi;

	return 0;
}