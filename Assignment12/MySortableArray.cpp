//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include <cctype>
#include "SortableArray.h"

vector<string> parseString(string);

int main()
{
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Programmer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl;

	SortableArray<double> a;
	SortableArray<double> i;
	string str;
	int x = 0;
	int index = 0;
	double value = 0;

	while (true)
	{
		cout << endl;
		cout << "Input an index value and a value [Q to quit]: ";
		getline(cin, str);
		vector<string> token = parseString(str);
		if (token[0] == "Q" || token[0] == "q" || token[1] == "Q" || token[1] == "q")
			break;
		index = atof(token[0].c_str());
		value = atof(token[1].c_str());
		i[index] = 1;
		a[index] = value;
	}

	for (int j = 0; j < i.capacity(); j++)
	{
		if (i[j] == 1)
			x += 1;
	}

	cout << endl;
	cout << "You stored this many values: " << x << endl;
	cout << "The index-value pairs are:\n";
	for (int b = 0; b <= a.capacity(); b++)
	{
		if (i[b] != 0)
			cout << b << " => " << a[b] << endl;
	}

	cout << endl;
	cout << "Input the size to be sort [Q to quit]: ";
	getline(cin, str);
	if (str == "Q" || str == "q" || str == "Q" || str == "q")
		return 0;
	index = atoi(str.c_str());
	a.sort(index);
	cout << endl;
	cout << "Sorted till " << index << ":\n";
	for (int b = 0; b <= a.capacity(); b++)
	{
		if (i[b] != 0)
			cout << b << " => " << a[b] << endl;
	}



	while (true)
	{
		cout << "Input an index for me to look up [Q to quit]: ";
		getline(cin, str);
		if (str == "Q" || str == "q" || str == "Q" || str == "q")
			break;
		index = atoi(str.c_str());

		if (i[index] != 0)
		{
			cout << "Found it -- the value stored at " << str;
			cout << " is " << a[index] << endl;
		}
		else
			cout << "I couldn't find it.\n";

	}
	system("Pause"); 
	return 0; 
}

vector<string> parseString(string str)
{
	stringstream s(str);
	istream_iterator<string> begin(s), end;
	return vector<string>(begin, end);
}

