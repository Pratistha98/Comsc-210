#define _CRT_SECURE_NO_WARNINGS
//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <set>
#include <string>

using namespace std;

#include <cstring>
#include <cctype>

int main()
{
	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	map<string, set<string>> allKeys;

	char* token;
	char buf[1000];
	const char* const tab = "\t";

	ifstream fin;
	fin.open("dvc-schedule.txt");
	if (!fin.good()) throw "I/O error";

	while (fin.good())
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

		const string termSection = term + "-" + section;

		allKeys[termSection].insert(course);

	}

	fin.close();

	map<string, set<string>>::iterator it;
	set<string>::iterator ite;

	for (it = allKeys.begin(); it != allKeys.end(); it++)
	{
		if (it->second.size() > 1)
		{
			cout << "Multiple courses found for key (term-section) - " << it->first << ":\n";
			for (ite = it->second.begin(); ite != it->second.end(); ite++)
				cout << *(ite) << endl;
		}

	}

	system("Pause"); 
	return 0;
}
