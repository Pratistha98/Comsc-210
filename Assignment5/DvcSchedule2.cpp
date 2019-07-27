#define _CRT_SECURE_NO_WARNINGS

/*
School : Diablo Valley College
Term : 2019 Spring
Course : ComSc - 210,
Programmar : Pratistha Maharjan
Programmar's ID: 1650717

*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "StaticArray.h"

using namespace std;

#include <cstring>

struct SectionsForTerm
{
	string term;
	int numberOfSectionsSeen;
	DynamicArray<string> seenSectionNumber;
};

struct subject
{
	string subjectCode;
	int count;
};

int checkTerm(const string, const StaticArray<SectionsForTerm, 200>&, int);
bool checkSection(const string, const SectionsForTerm&);

int main()
{
	//Programmar's identification
	cout << "Programmar: Pratistha Maharjan" << endl;
	cout << "Programmar's ID: 1650717 " << endl;
	cout << "File: " << __FILE__ << endl;
	cout << endl;

	DynamicArray<subject> subjectCount(100);
	StaticArray<SectionsForTerm, 200> alreadySeen;

	char* token;
	char buf[1000];
	const char* const tab = "\t";
	int count = 0; //read line count
	int duplicates = 0;
	int numberOfTermsSeen = 0;
	int subjectIndex = 0;

	ifstream fin;
	fin.open("dvc-schedule.txt");
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

		bool found = false;

		int termIndex = checkTerm(term, alreadySeen, numberOfTermsSeen);

		if (termIndex != -1)
		{
			found = checkSection(section, alreadySeen[termIndex]);
			if (!found)
			{
				alreadySeen[termIndex].
					seenSectionNumber[alreadySeen[termIndex].numberOfSectionsSeen++]
					= section;
			}
		}
		else // add the new term and section
		{
			alreadySeen[numberOfTermsSeen].term = term;
			alreadySeen[numberOfTermsSeen].numberOfSectionsSeen = 1;
			alreadySeen[numberOfTermsSeen].seenSectionNumber[0] = section;
			numberOfTermsSeen++;
		}

		if (!found)
		{
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

		cout << setw(5) << left << subjectCount[i].subjectCode << ", ";
		cout << setw(4) << right << subjectCount[i].count << " sections";
	}
	cout << endl;
	cout << "Total duplication: " << duplicates << endl;

	fin.close();

	system("Pause");
	return 0;
}

int checkTerm(const string term, const StaticArray<SectionsForTerm, 200>& classArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (classArray[i].term == term)
			return i;
	}
	return -1;
}

bool checkSection(const string section, const  SectionsForTerm& termArray)
{
	for (int i = 0; i < termArray.numberOfSectionsSeen; i++)
	{
		if (termArray.seenSectionNumber[i] == section)
			return true;
	}
	return false;
}
