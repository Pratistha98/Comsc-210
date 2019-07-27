
/*
School : Diablo Valley College
Term : 2019 Spring
Course : ComSc - 210,
Programmar : Pratistha Maharjan
Programmar's ID: 1650717*/
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>


using namespace std;

#include <cctype>
#include "MyStaticArray.h"

vector<string> parseString(string);

int main()
{
	//Programmar's identification
	cout << " Programmar: Pratistha Maharjan" << endl;
	cout << " Programmar's ID: 1650717 " << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	string str;
	double index;
	double value;
	//	Array Val;
	//	Array Store;

	StaticArray <double, 100> Val;
	StaticArray <double, 100> Store;

	int Total = 0;

	while (true)
	{
		cout << endl;
		cout << "Input an index a value [Q to quit]:";
		getline(cin, str);
		vector<string> token = parseString(str);

		if (token[0] == "Q" || token[0] == "q" || token[1] == "Q" || token[1] == "q")
			break;

		index = atof(token[0].c_str());
		value = atof(token[1].c_str());

		if (index >= 0 && index < 100)
		{
			Store[index] = 1;
			Val[index] = value;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (Store[i] == 1)
			Total += 1;
	}

	cout << endl;
	cout << "You stored this many values: " << Total << endl;

	cout << "The index-value pairs are: " << endl;
	for (int i = 0; i < 100; i++)
	{
		if (Store[i] != 0)
		{
			cout << i << "=>" << Val[i] << endl;
		}
	}
	cout << endl;

	while (true)
	{
		cout << "Input an index to look up [Q to quit]: ";
		getline(cin, str);
		if (str == "Q" || str == "q" || str == "Q" || str == "q")
			break;
		index = atoi(str.c_str());

		if (Store[index] != 0)
		{
			cout << " Found it -- the value stored at " << str <<
				" is " << Val[index] << endl;
		}
		else
			cout << " I did not find it" << endl;

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
