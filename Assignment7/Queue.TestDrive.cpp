//Programmar: Pratistha Maharjan
//Programmar's Id: 1650717


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h"

int main()
{
	//Programmer's identification
	cout << "Programmar's name: Pratistha Maharjan" << endl; 
	cout << "Programmar's ID: 1650717" << endl;
	cout << " File: " << __FILE__ << endl;
	cout << endl;
	cout << "Queue test: (double)\n";
	cout << "-----------------\n";

	Queue<double> a;

	cout << "Testing Queue::size\n";
	cout << "EXPECTED: 0\n";
	cout << "ACTUAL  : " << a.size() << endl;
	assert(a.size() == 0);
	cout << "Pass!\n\n";

	cout << "Testing Queue::front & Queue::push\n";
	cout << "EXPECTED: 1.1\n";

	a.push(1.1);

	cout << "ACTUAL  : " << a.front() << endl;
	assert(a.front() == 1.1);
	cout << "Pass!\n\n";

	cout << "Testing Queue::pop\n";
	cout << "Before pop: 1.1\n";
	a.push(2.2);
	a.pop();
	cout << "After  pop: " << a.front() << endl;
	assert(a.front() == 2.2);
	cout << "Pass!\n\n";

	cout << "Testing Queue::back\n";
	cout << "EXPECTED: 2.2\n";
	cout << "ACTUAL: " << a.back() << endl;
	assert(a.back() == 2.2);
	cout << "Pass!\n\n";

	cout << "Testing copy constructor\n";
	Queue<double> b(a);
	assert(a.size() == b.size());
	assert(a.front() == b.front());
	assert(a.back() == b.back());
	cout << "Pass!\n\n";

	cout << "Testing assignment operator\n";
	Queue<double> c;
	c = a;
	assert(a.size() == c.size());
	assert(a.front() == c.front());
	assert(a.back() == c.back());
	cout << "Pass!\n\n";

	cout << "Testing Queue::capacity\n";
	cout << "Default capcity: 2\n";
	Queue<double> d;
	d.push(1.1);
	d.push(2.2);
	d.push(3.3);
	d.push(4.4);
	d.push(5.5);
	cout << "After pushing 5 elements, size is " << d.size() << endl;
	assert(d.size() == 5);
	cout << "Pass!\n\n";

	cout << "Testing Queue::clear & empty\n";
	a.clear();
	assert(a.empty());
	cout << "Pass!\n\n";

	cout << "Constant object test:\n";
	const Queue<double> e = d;
	cout << "Size: " << e.size() << endl;
	assert(e.size() == 5);
	if (!e.empty())
		cout << "It's NOT empty!\n\n";
	else
		assert(e.empty());

	cout << endl;
	cout << "Queue test: (string)\n";
	cout << "-----------------\n";

	Queue<string> sa;

	cout << "Testing Queue::size\n";
	cout << "EXPECTED: 0\n";
	cout << "ACTUAL  : " << sa.size() << endl;
	assert(sa.size() == 0);
	cout << "Pass!\n\n";

	cout << "Testing Queue::front & Queue::push\n";
	cout << "EXPECTED: ONE\n";

	sa.push("ONE");

	cout << "ACTUAL  : " << sa.front() << endl;
	assert(sa.front() == "ONE");
	cout << "Pass!\n\n";

	cout << "Testing Queue::pop\n";
	cout << "Before pop: 1.1\n";
	sa.push("2.2");
	sa.pop();
	cout << "After  pop: " << sa.front() << endl;
	assert(sa.front() == "2.2");
	cout << "Pass!\n\n";

	cout << "Testing Queue::back\n";
	cout << "EXPECTED: 2.2\n";
	cout << "ACTUAL: " << sa.back() << endl;
	assert(sa.back() == "2.2");
	cout << "Pass!\n\n";

	cout << "Testing copy constructor\n";
	Queue<string> sb(sa);
	assert(sa.size() == sb.size());
	assert(sa.front() == sb.front());
	assert(sa.back() == sb.back());
	cout << "Pass!\n\n";

	cout << "Testing assignment operator\n";
	Queue<string> sc;
	sc = sa;
	assert(sa.size() == sc.size());
	assert(sa.front() == sc.front());
	assert(sa.back() == sc.back());
	cout << "Pass!\n\n";

	cout << "Testing Queue::capacity\n";
	cout << "Default capcity: 2\n";
	Queue<string> sd;
	sd.push("ONE");
	sd.push("TWO");
	sd.push("THREE");
	sd.push("FOUR");
	sd.push("FIVE");
	cout << "After pushing 5 elements, size is " << sd.size() << endl;
	assert(sd.size() == 5);
	cout << "Pass!\n\n";

	cout << "Testing Queue::clear & empty\n";
	sa.clear();
	assert(sa.empty());
	cout << "Pass!\n\n";

	cout << "Constant object test:\n";
	const Queue<string> se = sd;
	cout << "Size: " << se.size() << endl;
	assert(se.size() == 5);
	if (!se.empty())
		cout << "It's NOT empty!\n\n";
	else
		assert(se.empty());
	system("pause"); 
	return 0;
}
