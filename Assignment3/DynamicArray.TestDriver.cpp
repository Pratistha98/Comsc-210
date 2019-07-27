
/*
School : Diablo Valley College
Term : 2019 Spring
Course : ComSc - 210,
Programmar : Pratistha Maharjan
Programmar's ID: 1650717*/
#include <iostream>
#include <cassert>
#include <string>

#include "DynamicArray.h"
#include "DynamicArray.h"
using namespace std;

int main()
{
	//Programmar's identification
	cout << " Programmar: Pratistha Maharjan" << endl;
	cout << " Programmar's ID: 1650717 " << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	DynamicArray <double> a(100);
	//	const StaticArray <double, 100> b;

	cout << "Double DynamicArray test: " << endl;
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

	//a.capacity(200);
	a[200] = 100;
	cout << "Actual: " << a.capacity() << endl;

	cout << "Expected: the new capacity for a is: 200*2" << endl;
	assert(a.capacity() == 400);
	cout << "Pass" << endl;

	// Array::operator[ ] getter
	cout << "\nTesting the Array::operator[ ] getter\n";
	const DynamicArray <double> b = a;
	for (int i = 0; i < 100; i++)
		assert(a[i] == b[i]);
	cout << "Pass" << endl;


	// const object test
	cout << "\nConst object test\n";
	const DynamicArray<double> c;
	assert(c.capacity());
	assert(c[0] == c[0]);
	assert(c[-1] == c[-1]);
	cout << "Pass" << endl;

	// object copy test
	cout << "\nObject copy test\n";
	DynamicArray<double> d = a; // making a copy
	assert(a.capacity() == d.capacity());
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == d[i]); // uses the setter version for both a and d
	cout << "Pass" << endl;

	// object assignment test
	cout << "\nObject assignment test\n";
	DynamicArray<double> e; e = a;
	assert(a.capacity() == e.capacity());
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == e[i]);
	cout << "Pass" << endl;



	
	//For string
	DynamicArray <string> as;

	cout << endl;
	cout << "String DynamicArray test: " << endl;
	cout << "-------------------------" << endl;

	// Array::capacity
	cout << "\nTesting Array::capacity\n";
	cout << "EXPECTED: 2\n";
	cout << "ACTUAL: " << as.capacity() << endl;
	assert(2 == as.capacity());
	cout << "Pass" << endl;

	// Array::Array
	cout << "\nTesting Array::Array\n";
	for (int i = 0; i < as.capacity(); i++)
		assert(as[i] == "");
	cout << "Pass" << endl;

	// Array::operator[ ] getter
	cout << "\nTesting the Array::operator[ ] getter\n";
	const DynamicArray <string> bs = as;
	for (int i = 0; i < 2; i++)
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

	//a.capacity(200);
	as[200] = 100;
	cout << "Actual: " << as.capacity() << endl;

	cout << "Expected: the new capacity for a is: 200*2" << endl;
	assert(as.capacity() == 400);
	cout << "Pass" << endl;

	// const object test
	cout << "\nConst object test\n";
	const DynamicArray<string> ac;
	assert(ac.capacity());
	assert(ac[0] == ac[0]);
	assert(ac[-1] == ac[-1]);
	cout << "Pass" << endl;
	cout << endl;
	
	// object copy test
	cout << "\nObject copy test\n";
	DynamicArray<string> dc = ac; // making a copy
	assert(a.capacity() == d.capacity());
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == d[i]); // uses the setter version for both a and d
	cout << "Pass" << endl;

	// object assignment test
	cout << "\nObject assignment test\n";
	DynamicArray<string> ec; ec = ac;
	assert(a.capacity() == e.capacity());
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == e[i]);
	cout << "Pass" << endl;

	system("Pause");
	return 0;
}

