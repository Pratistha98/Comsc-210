#define _CRT_SECURE_NO_WARNINGS
//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717
#include <algorithm>
#include <fstream>
#include <iostream>
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

	map<string, set<int>> allClass;

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

		const string season(token = strtok(buf, " "));
		const string term((token = strtok(0, tab)) ? token : " ");
		const string section((token = strtok(0, tab)) ? token : " ");
		const string course((token = strtok(0, tab)) ? token : " ");
		const string instructor((token = strtok(0, tab)) ? token : " ");
		const string whenWhere((token = strtok(0, tab)) ? token : " ");
		if (course.find('-') == string::npos) continue;
		const string subjectCode(course.begin(), course.begin() + course.find('-'));

		int termNumber = atoi(term.c_str()) * 10;

		if (season == "Spring")
			termNumber += 1;
		else if (season == "Summer")
			termNumber += 2;
		else
			termNumber += 3;

		allClass[course].insert(termNumber);
	}

	fin.close();

	while (true)
	{
		string str;
		cout << "Enter course name (ex: COMSC-210) or X to quit: ";
		getline(cin, str);

		for (int i = 0; i < str.length(); i++)
			str[i] = toupper(str[i]);

		if (str == "X")
			break;

		if (!allClass[str].empty())
		{
			string bout, rbout;
			switch (*(allClass[str].begin()) % 10)
			{
			case 1: bout = "Spring " + to_string(*(allClass[str].begin()) / 10);
			case 2: bout = "Summer " + to_string(*(allClass[str].begin()) / 10);
			case 3: bout = "Fall " + to_string(*(allClass[str].begin()) / 10);
			}
			switch (*(allClass[str].rbegin()) % 10)
			{
			case 1: rbout = "Spring " + to_string(*(allClass[str].rbegin()) / 10);
			case 2: rbout = "Summer " + to_string(*(allClass[str].rbegin()) / 10);
			case 3: rbout = "Fall " + to_string(*(allClass[str].rbegin()) / 10);
			}

			cout << str << " was first offered in " << bout << endl;
			cout << str << " was last offered in " << rbout << ".\n";
			cout << endl;
		}
		else
			cout << str << " could not be found as far back as year 2000\n";

	}
}
