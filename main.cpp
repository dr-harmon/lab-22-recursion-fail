#include "linear_sum.h"

#include <cstdlib>
#include <iostream>

#include <algorithm>

using namespace std;

int main()
{
	const int HIGH  = 1000000;
	const int LOW   =  100000;
	int delta = HIGH - LOW;
	int size  = LOW;

	delta /= 2;
	size += delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size -= delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size += delta;

	delta /= 2;
	size -= delta;

	cout << delta << endl;

	vector<int> A(size);
	fill(A.begin(), A.end(), 1);

	cout << "Iterative: " << iterativeLinearSum(A, size) << endl;
	cout << "Recursive: " << recursiveLinearSum(A, size) << endl;

	return EXIT_SUCCESS;
}
