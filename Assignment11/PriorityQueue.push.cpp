//Programmar: Pratistha Maharjan
//Programmar's ID: 1650717

#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include <cmath>
#include <ctime>

//my .h file
#include "PriorityQueue.h"

int main()
{
	srand(time(0)); rand();

	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	//Programmer customization
	int n = 1000000;
	const int reps = 1000;

	cout.setf(ios::fixed);
	cout.precision(4);
	double elapsedSecondsNorm = 0;
	double expectedSeconds = 0;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		// problem setup goes here -- create a data structure of size n
		PriorityQueue<int> a(n + reps);
		for (int i = 0; i < n; i++)
			a.push(n - 1);
		// assert that n is the size of the data structure if applicable
		assert(a.size() == n); // or something like that...

		// start the timer, do something, and stop the timer
		clock_t startTime = clock();
		// do something where n is the "size" of the problem

		for (int i = 0; i < reps; i++)
			a.push(rand());

		clock_t endTime = clock();

		//validation
		assert(a.size() == n + reps);

		for (int i = 0; i < a.size(); i++)
		{
			int x = a.top();
			a.pop();
			int y = a.top();
			a.pop();
			assert(x > y || x == y);
		}


		// compute timing results
		double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
		double factor = pow(2.0, double(cycle));
		if (cycle == 0)
			elapsedSecondsNorm = elapsedSeconds;

		expectedSeconds = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

		// reporting block
		cout << elapsedSeconds;
		if (cycle == 0) cout << "(expected)";
		else cout << " (expected " << elapsedSecondsNorm
			<< " to " << expectedSeconds << ')';
		cout << " for n=" << n << endl;
	}
	system("Pause");
	return 0;
}




