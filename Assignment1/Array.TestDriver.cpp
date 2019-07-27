
/*
School : Diablo Valley College
Term : 2019 Spring
Course : ComSc - 210,
Programmar : Pratistha Maharjan
Programmar's ID: 1650717*/
#include <iostream>
#include <cassert>

using namespace std;

class Array
{
	int values[100];
	int dummy = 0;
public:
	Array(); //Constructor
	int capacity() const { return 100; }
	int operator[] (int) const;
	int& operator[] (int);

};



int main()
{
	//Programmar's identification
	cout << " Programmar: Pratistha Maharjan" << endl;
	cout << " Programmar's ID: 1650717 " << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	Array a;

	// Array::capacity
	cout << "\nTesting Array::capacity\n";
	cout << "EXPECTED: 100\n";
	cout << "ACTUAL: " << a.capacity() << endl;
	assert(100 == a.capacity());

	// Array::Array
	cout << "\nTesting Array::Array\n";
	for (int i = 0; i < a.capacity(); i++)
		assert(a[i] == 0);

	// Array::operator[ ] getter
	cout << "\nTesting the Array::operator[ ] getter\n";
	const Array b = a;
	for (int i = 0; i < 100; i++)
		assert(a[i] == b[i]);

	// Array::operator[ ] setter
	cout << "\nTesting the Array::operator[ ] setter\n";
	a[6] = 123;
	a[7] = 765;
	cout << "\nTesting Array::operator[ ] setter\n";
	cout << "EXPECTED: 123 for a[6]\n";
	cout << "ACTUAL: " << a[6] << endl;
	assert(123 == a[6]);
	cout << "EXPECTED: 765 for a[7]\n";
	cout << "ACTUAL: " << a[7] << endl;
	assert(765 == a[7]);
	a[-1000] = 1231;
	cout << "EXPECTED: 1231 for a[-1000]\n";
	cout << "ACTUAL: " << a[-1000] << endl;
	assert(1231 == a[-1000]);

	system("Pause");
	return 0;
}

Array::Array()
{
	for (int index = 0; index < 100; index++)
		values[index] = 0;
}

int Array::operator[] (int index) const
{
	if (index < 0 || index >= 100)
		return 0;
	return values[index];
}

int& Array::operator[](int index)
{
	if (index < 0 || index >= 100)
		return dummy;
	return values[index];
}

