//Programmer     : Pratistha Maharjna
//Programmer's ID: 1650717
#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>

//my .h file
#include "MyDynamicArray.h"

int main()
{
	srand(time(0)); rand();

	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	//Programmer customization
	int n = 1000;
	string bigOh = "O(n squared)";
	double temp = 0;

	cout.setf(ios::fixed);
	cout.precision(4);
	double elapsedSecondsNorm = 0;
	double expectedSeconds = 0;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		// problem setup goes here -- create a data structure of size n
		DynamicArray<double> a(n);
		for (int i = 0; i < n; i++) a[i] = rand();

		// assert that n is the size of the data structure if applicable
		assert(a.capacity() == n); // or something like that...

		// start the timer, do something, and stop the timer
		clock_t startTime = clock();
		// do something where n is the "size" of the problem

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}

		clock_t endTime = clock();

		//validation
		for (int i = 1; i < n; i++)
			assert(a[i - 1] <= a[i]);


		// compute timing results
		double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		double factor = pow(2.0, double(cycle));
		if (cycle == 0)
			elapsedSecondsNorm = elapsedSeconds;
		else if (bigOh == "O(n)")
			expectedSeconds = factor * elapsedSecondsNorm;
		else if (bigOh == "O(n log n)")
			expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
		else if (bigOh == "O(n squared)")
			expectedSeconds = factor * factor * elapsedSecondsNorm;

		// reporting block
		cout << elapsedSeconds;
		if (cycle == 0) cout << " (expected " << bigOh << ')';
		else cout << " (expected " << expectedSeconds << ')';
		cout << " for n=" << n << endl;
	}
	system("Pause"); 
	return 0;
}
