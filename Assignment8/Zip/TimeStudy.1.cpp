#define _CRT_SECURE_NO_WARNINGS
//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>


int main()
{
	srand(time(0)); rand();

	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan \n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	//Programmer customization
	int n = 8000;
	string bigOh = "O(n)";
	ifstream fin;
	char* token;
	char buf[1000];
	const char* const tab = "\t";

	cout.setf(ios::fixed);
	cout.precision(4);
	double elapsedSecondsNorm = 0;
	double expectedSeconds = 0;
	for (int cycle = 0; cycle < 4; cycle++, n *= 2)
	{
		// start the timer, do something, and stop the timer
		clock_t startTime = clock();
		// do something where n is the "size" of the problem
		fin.open("dvc-schedule.txt");
		for (int i = 0; i < n; i++)
		{

			string line;
			getline(fin, line);
			strcpy(buf, line.c_str());

			if (buf[0] == 0) continue;

			const string term(token = strtok(buf, tab));
			const string section((token = strtok(0, tab)) ? token : " ");
			const string course((token = strtok(0, tab)) ? token : " ");
			const string instructor((token = strtok(0, tab)) ? token : " ");
			const string whenWhere((token = strtok(0, tab)) ? token : " ");
			if (course.find('-') == string::npos) continue;
			const string subjectCode(course.begin(), course.begin() + course.find('-'));

		}

		fin.close();
		clock_t endTime = clock();


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
