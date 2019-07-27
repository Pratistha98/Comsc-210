
/*
School : Diablo Valley College
Term : 2019 Spring
Course : ComSc - 210,
Programmar : Pratistha Maharjan
Programmar's ID: 1650717*/
#include <iostream>
#include <cassert>
#include <string>

#include "MyStaticArray.h"
#include "MyStaticArray.h"
using namespace std;

int main()
{
	//Programmar's identification
	cout << " Programmar: Pratistha Maharjan" << endl;
	cout << " Programmar's ID: 1650717 " << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	StaticArray <double, 100 > a;
	//	const StaticArray <double, 100> b;

	cout << "Double StaticArray test: " << endl;
	cout << "-------------------------" << endl;

	// Array::capacity
	cout << "\nTesting Array::capacity\n";
	cout << "EXPECTED: 100\n";
	cout << "ACTUAL: " << a.capacity() << endl;
	assert(100 == a.capacity());
	cout << "Pass" << endl;

	// Array::Array
	cout << "\nTesting Array::Array\n";
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == 0);
	cout << "Pass" << endl;

	// Array::operator[ ] getter
	cout << "\nTesting the Array::operator[ ] getter\n";
	const StaticArray <double, 100> b = a;
	for (int i = 0; i < 100; i++)
		assert(a[i] == b[i]);
	cout << "Pass" << endl;

	// Array::operator[ ] setter
	cout << "\nTesting the Array::operator[ ] setter\n";
	a[6] = 6.6;
	a[7] = 7.7;

	cout << "EXPECTED: 6.6 for a[6]\n";
	cout << "ACTUAL: " << a[6] << endl;
	assert(6.6 == a[6]);
	cout << "EXPECTED: 7.7 for a[7]\n";
	cout << "ACTUAL: " << a[7] << endl;
	assert(7.7 == a[7]);
	a[-1000] = 666.6;
	cout << "EXPECTED: 666.6 for a[-1000] (dummy)\n";
	cout << "ACTUAL: " << a[-1000] << endl;
	assert(666.6 == a[-1000]);
	cout << "Pass" << endl;

	// const object test
	cout << "\nConst object test\n";
	const StaticArray<double, 100> c;
	assert(c.capacity());
	assert(c[0] == c[0]);
	assert(c[-1] == c[-1]);
	cout << "Pass" << endl;


	//For string
	StaticArray <string, 100 > as;

	cout << endl;
	cout << "String StaticArray test: " << endl;
	cout << "-------------------------" << endl;

	// Array::capacity
	cout << "\nTesting Array::capacity\n";
	cout << "EXPECTED: 100\n";
	cout << "ACTUAL: " << as.capacity() << endl;
	assert(100 == as.capacity());
	cout << "Pass" << endl;

	// Array::Array
	cout << "\nTesting Array::Array\n";
	for (int i = 0; i < as.capacity(); i++)
		assert(as[i] == "");
	cout << "Pass" << endl;

	// Array::operator[ ] getter
	cout << "\nTesting the Array::operator[ ] getter\n";
	const StaticArray <string, 100> bs = as;
	for (int i = 0; i < 100; i++)
		assert(as[i] == bs[i]);
	cout << "Pass" << endl;

	// Array::operator[ ] setter
	cout << "\nTesting the Array::operator[ ] setter\n";
	as[6] = "six";


	cout << "EXPECTED: 'six' for as[6]\n";
	cout << "ACTUAL: " << as[6] << endl;
	assert("six" == as[6]);

	as[-1000] = "dummy";
	cout << "EXPECTED: 'dummy' for a[-1000] (dummy)\n";
	cout << "ACTUAL: " << as[-1000] << endl;
	assert("dummy" == as[-1000]);
	cout << "Pass" << endl;

	// const object test
	cout << "\nConst object test\n";
	const StaticArray<string, 100> ac;
	assert(ac.capacity());
	assert(ac[0] == ac[0]);
	assert(ac[-1] == ac[-1]);
	cout << "Pass" << endl;
	cout << endl;

	system("Pause");
	return 0;
}

