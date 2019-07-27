//Programmar: Pratistha Maharjan
//Programmar ID: 1650717

#include<iostream>
#include <string>
using namespace std;

#include <cstring>

#include "Stack.h";

int main()
{
	//Identification
	cout << "Programmar: Pratistha Maharjan" << endl;
	cout << "Programmar's Id: 1650717" << endl;
	cout << "File: " << __FILE__ << endl;

	string input; 
	double one, two, three;
	double calculate = 0;
	Stack <double> store;


	while (true)
	{
		Stack <double> copy(store);
		cout << "Enter: "; 
		
		if (copy.size() != 0)
		{
			for (copy.peek(); copy.size() != 0;)
			{
				cout << copy.peek() << " ";
				copy.pop();
			}
		}
		
		getline(cin, input);

		if (input == "q" || input == "Q")
		{
			break;
		}
		else if (input == "+")
		{
			if (store.size() < 2)
			{
				cout << "Invalid" << endl;
				continue;
			}
		    one = store.peek();
		 	store.pop();
			two = store.peek();
			store.pop();
			three = one + two;
			store.push(three);
		}

		else if (input == "-")
		{
			if (store.size() < 2)
			{
				cout << "Invalid" << endl;
				continue;
			}
			one = store.peek();
			store.pop();
			two = store.peek();
			store.pop();
			three = two - one;
			store.push(three);
		}
		else if (input == "*")
		{
			if (store.size() < 2)
			{
				cout << "Invalid" << endl;
				continue;
			}
			one = store.peek();
			store.pop();
			two = store.peek();
			store.pop();
			three = one * two;
			store.push(three);
		}
		else if (input == "/")
		{
			if (store.size() < 2)
			{
				cout << "Invalid" << endl;
				continue;
			}
			one = store.peek();
			store.pop();
			two = store.peek();
			store.pop();
			three = two / one;
			store.push(three);
		}
		
		else
		{
			store.push(atof(input.c_str()));
		}
	}


	system("Pause"); 
	return 0;
}