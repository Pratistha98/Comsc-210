#define _CRT_SECURE_NO_WARNINGS 
//Programmer     : Pratistha Maharjan 
//Programmer's ID: 1650717

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>

#include "HashTable.h"

//hashing function for subject
int hashCode(const string& key)
{
	int result = 0;
	for (int i = 0; i < key.length(); i++)
		result += key.at(i);
	return result;
}

//hashing function for duplicate check
int d_hashCode(const string& key)
{
	int result = 0;
	int i;

	for (i = 0; i < key.length() - 4; i++)
		result += key.at(i);

	for (int j = 0; j < 4; j++)
		result += (int)(key.at(i + j)) * pow(10, j);

	return result;
}

int main()
{
	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan \n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	HashTable<string, bool, 75000>record(d_hashCode);
	HashTable<string, int, 100>subClass(hashCode);

	char* token;
	char buf[1000];
	const char* const tab = "\t";
	int duplicates = 0;

	clock_t startTime = clock();

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

		string classCode = term + section;

		if (record[classCode])
		{
			duplicates++;
		}
		else
		{
			record[classCode] = true;
			subClass[subjectCode]++;
		}
	}
	fin.close();

	clock_t endTime = clock();

	double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

	cout << "Finish!\n";
	cout << "hashTable size = " << record.size() << "/" << subClass.size() << ", ";
	cout << "runtime: " << elapsedSeconds << "second(s)\n";
	cout << "The load factor for the duplication check: " << record.loadFactor() << endl;
	cout << "The node load factor for the duplication check: " << record.node_loadFactor() << endl;
	cout << "The average list size for the duplication check: " << record.node_loadFactor() / record.loadFactor() << endl;
	cout << "The load factor for the subject code:" << subClass.loadFactor() << endl;
	cout << "Total duplication: " << duplicates << endl;

	queue<string> q = subClass.keys();
	set<string> s;

	while (!q.empty())
	{
		s.insert(q.front());
		q.pop();
	}

	for (auto& i : s)
		cout << i << ", " << subClass[i] << "  section\n";

	system("Pause"); 
	return 0;
}

