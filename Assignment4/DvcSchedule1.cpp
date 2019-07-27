#define _CRT_SECURE_NO_WARNINGS

/*
School : Diablo Valley College
Term : 2019 Spring
Course : ComSc - 210,
Programmar : Pratistha Maharjan
Programmar's ID: 1650717

*/
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>

#include"DynamicArray.h"
using namespace std;
#include<cstring> //for strtok and strcpy

struct subject
{
	string subjectCode; 
	int count; 
};

bool checkDuplicate(string, const DynamicArray<string>&, int);

int main()
{

	//Programmar's identification
	cout << "Programmar: Pratistha Maharjan" << endl;
	cout << "Programmar's ID: 1650717 " << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;


	DynamicArray<string> nonDuplicateClass(100);
	DynamicArray<subject> subjectCount(100);

	char* token;
	char buf[1000];
	const char* const tab = "\t";
	int count = 0; //read line count
	int duplicates = 0;
	int classIndex = 0;
	int subjectIndex = 0;


	ifstream fin;
	fin.open("dvc-schedule2.txt");
	if (!fin.good()) throw "I/O error";

	while (fin.good())
	{
		string line;
		getline(fin, line);
		strcpy(buf, line.c_str());

		if (buf[0] == 0) continue;

		if (count != 0 && count % 1000 == 0)
			cout << '.'; cout.flush();

		const string term(token = strtok(buf, tab));
		const string section((token = strtok(0, tab)) ? token : " ");
		const string course((token = strtok(0, tab)) ? token : " ");
		const string instructor((token = strtok(0, tab)) ? token : " ");
		const string whenWhere((token = strtok(0, tab)) ? token : " ");
		if (course.find('-') == string::npos) continue;
		const string subjectCode(course.begin(), course.begin() + course.find('-'));

		const string classCode = term + section;

		bool found = checkDuplicate(classCode, nonDuplicateClass, classIndex);

		if (!found)
		{
			nonDuplicateClass[classIndex++] = classCode;
			for (int i = 0; i < subjectIndex; i++)
			{
				if (subjectCount[i].subjectCode.compare(subjectCode) == 0)
				{
					found = true;
					subjectCount[i].count++;
					break;
				}
			}
		}
		else
			duplicates++;

		if (!found)
		{
			subjectCount[subjectIndex].subjectCode = subjectCode;
			subjectCount[subjectIndex].count = 1;
			subjectIndex++;
		}

		count++;
	}

	//sort subjectCount array
	for (int i = 0; i < subjectIndex; i++)
	{
		for (int j = i + 1; j < subjectIndex; j++)
		{
			if (subjectCount[i].subjectCode > subjectCount[j].subjectCode)
			{
				swap(subjectCount[i], subjectCount[j]);
			}
		}
	}

	//print out the content in subject Count array in a for-loop
	for (int i = 0; i < subjectIndex; i++)
	{
		cout << endl;

		cout << setw(3) << left << subjectCount[i].subjectCode << ", ";
		cout << setw(3) << right << subjectCount[i].count << " sections";
	}
	cout << endl;
	cout << "Total duplication: " << duplicates << endl;

	fin.close();

	system("Pause"); 
	return 0;
}

bool checkDuplicate(const string classCode, const DynamicArray<string>& classArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (classArray[i] == classCode)
			return true;
	}
	return false;

}

