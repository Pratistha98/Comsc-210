//Programmar: Pratistha Maharjan
//Programmar ID: 1650717

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{
	cout << "Programmar's name: Pratistha Maharjan " << endl;
	cout << "Programmar's Id: 1650717" << endl;
	cout << "File: " << __FILE__ << endl;
	 
	//For integers
	cout << "Testing Integers " << endl;
	Stack<int> a;
	int data; 

	cout << "Stack Test: (int)" << endl;
	cout << "---------------------" << endl;

	//Test size

	cout << "Testing Stack :: size " << endl;
	cout << "Expected: 0" << endl;
	cout << "Actual: " << a.size() << endl;
	assert(a.size() == 0);
	cout << "Pass" << endl;
	cout << endl;

			   
	//Test push 
	cout << "Testing Stack::peek & Stack::push" << endl;
	a.push(1234);
	data = a.peek();
	cout << "Expected: 1234" << endl;
	cout << "Actual:" << data << endl;
	assert(data = 1234);


	a.push(5678);
	data = a.peek(); 
	cout << "Expected: 5678" << endl;
	cout << "Actual: " << data << endl;
	assert(data = 5678);


	a.push(1998);
	data = a.peek();
	cout << "Expected: 1998" << endl;
	cout << "Actual:" << data << endl;
	assert(data == 1998);
	cout << "Pass" << endl;
	cout << endl;
	   
	//Test pop
	cout << "Testing Stack:: pop" << endl;
	cout << "Before pop: " << a.peek() << endl;
	a.pop();
	data = a.peek(); 
	cout << "After pop: " << data << endl;
	assert(data == 5678);
	cout << "Pass" << endl;
	cout << endl;


	
	//Test copy constructor
	cout << "Testing copy constructor" << endl;
	Stack <int> b = a;
	data = b.peek(); 
	//cout << "Expected: 5678 for data" << endl;
	//cout << "Actual: " << data << endl;
	assert(data = 5678);
	b.push(1998); 
	data = b.peek(); 
	assert(data = 1998); 
	cout << "Pass" << endl;
	cout << endl;

	//Testing assignment operator 
	cout << "Testing assignment operator" << endl;
	Stack <int> c;
	c = a; 
	data = c.peek(); 
	//cout << "Expected 5678 for data" << endl;
	assert(data == 5678);
	c.push(2001); 
	data = c.peek(); 
	assert(data == 2001); 
	cout << "Pass" << endl;
	cout << endl;

	//Testing capacity
	cout << "Testing Stack: capcacity" << endl;
	cout << "Default capacity: " << a.size() << endl;
	a.push(2991);
	a.push(2002);
	a.push(6789); 
	cout << "After pushing 3 elements, size is: " << a.size() << endl;
	cout << "Capacity had doubled twice! " << endl;
	cout << "Pass" << endl;
	cout << endl;

	//Testing const Object
	cout << "Testing const object" << endl;
	const Stack<int> const d = a;	
	assert(d.size() == 5); 
	cout << "Pass" << endl;
	cout << "Its not empty!" << endl;
	cout << endl;

	//Testing clear and empty
	cout << "Testing Stack:: clear & empty" << endl;
	a.clear();
	assert(a.size() == 0);
	a.empty();
	assert(a.empty() == 1);
	cout << "Pass" << endl;

	cout << endl;
	cout << "Stack Test: (string)" << endl;
	cout << "---------------------" << endl;


	Stack<string> e;
	string value;

	//Test size
	cout << "Testint Stack:: size" << endl;
	cout <<  "Expected: 0" << endl;
	cout << "Actual: " << e.size() << endl;
	cout << "Pass" << endl;
	cout << endl;

	//Test push 
	cout << "Testing Stack::peek & Stack::push" << endl;
	e.push("Pratistha");
	value = e.peek();
	cout << "Expexted: Pratistha " << endl;
	cout << "Actual: " << value << endl;
	assert(value == "Pratistha");

	e.push("Maharjan");
	value = e.peek(); 
	cout << "Expected: Maharjan" << endl;
	cout << "Actual: " << value << endl;
	assert(value == "Maharjan");
	cout << "Pass!" << endl;
	cout << endl;

	//Test pop
	cout << "Testing Stack :: pop" << endl;
	cout << "Before pop:" << e.peek() << endl;
	e.pop();
	value = e.peek();
	cout << "After pop: " << e.peek() << endl;
	assert(value == "Pratistha");
	cout << "Pass" << endl;
	cout << endl;

	//Test copy contructor
	cout << "Testing copy constructor" << endl;
	Stack<string> m = e;
	value = e.peek(); 
	assert(value == "Pratistha");

	m.push("Uniglobe"); 
	value = m.peek(); 
	assert(value == "Uniglobe");
	cout << "Pass" << endl;
	cout << endl;


	//Testing assignment operator 
	cout << "Testing assignment operator" << endl;
	Stack <string> f;
	f = e;
	value = f.peek();
	assert(value == "Pratistha");

	f.push("Hi");
	value = f.peek();
	assert(value == "Hi");
	cout << "Pass" << endl;
	cout << endl;


	//Testing capcity
	cout << "Testing Stack::capacity" << endl;
	cout << "Default capacity: " << e.size() << endl;
	e.push("nice");
	e.push("Comsc210"); 
	e.push("DVC");
	e.push("College");

	cout << "After pushing 4 now element size is: " <<e.size() << endl;
	cout << "Capacity has doubled " << endl;
    assert(e.size() == 5);
	cout << "Pass" << endl;
	cout << endl;

	//Constant object test
	cout << "Constant object Test" << endl;
	Stack <string>const  h = e; 
	assert(h.size() == 5);
	cout << "Pass" << endl;
	cout << "size: " << h.size() << endl;
	cout << "It's not empty" << endl;

	
	system("Pause");
	return 0;
}