#define _CRT_SECURE_NO_WARNINGS
//Programmer     : Pratistha Maharjan
//Programmer's ID: 1650717

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <cstring>
#include <queue>

#include "DynamicArray.h"
#include "AssociativeArray.h"

void sortArray(DynamicArray<string>&, int);

int main()
{
	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	AssociativeArray<string, AssociativeArray<string, bool>> alreadySeen;
	AssociativeArray<string, AssociativeArray<string, int >> count;

	char* token;
	char buf[1000];
	const char* const tab = "\t";
	int duplicates = 0;


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

		if (alreadySeen[term][section])
		{
			duplicates++;
			continue;
		}
		else
		{
			alreadySeen[term][section] = true;
			count[subjectCode][course]++;
		}
	}
	fin.close();

	queue<string> subjectKeys = count.keys();

	DynamicArray<string> subjectArray(subjectKeys.size());

	//copy from queue to dynamic array
	for (int i = 0; i < subjectKeys.size(); i++)
	{
		subjectArray[i] = subjectKeys.front();
		subjectKeys.pop();
	}

	//sort dynamic array
	sortArray(subjectArray, subjectKeys.size());

	cout << "Duplication: " << duplicates << endl;

	for (int i = 0; i < subjectKeys.size(); i++)
	{
		string subject = subjectArray[i];

		queue<string> courseKeys = count[subjectArray[i]].keys();

		int courseCount = courseKeys.size();
		DynamicArray<string> courseArray(courseCount);

		for (int k = 0; k < courseCount; k++)
		{
			courseArray[k] = courseKeys.front();
			courseKeys.pop();
		}

		sortArray(courseArray, courseCount);

		cout << subject << ", " << count[subjectArray[i]].size() << " course(s)\n";

		for (int j = 0; j < count[subjectArray[i]].size(); j++)
		{
			cout << tab << courseArray[j] << ", " << count[subjectArray[i]][courseArray[j]] << " section(s)\n";
		}
	}
	system("pause"); 
	return 0;
}

void sortArray(DynamicArray<string>& array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				string temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
