#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Queue.h"
#include "DynamicArray.h"

using namespace std;

#include <cmath>
#include <cstdlib>
#include <cstring>

struct customer
{
	char IDtag;
	int arrivalTime;
	int serviceEndTime;
};

int getRanNumOfArrivals(double avgArrivalRate)
{
	int arrivals = 0;
	double probOfnArrivals = exp(-avgArrivalRate);
	for (double randomValue = (double)rand() / RAND_MAX;
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= avgArrivalRate / static_cast<double>(++arrivals));
	return arrivals;
}

int main()
{
	srand(time(0));
	cout << endl;
	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	ifstream fin;
	int serverNumber = 0;
	double cRatePerMins = 0.0;
	double cRateMins = 0;
	double maxQLen = 0;
	double MinStime = 0;
	double MaxStime = 0;
	int numOfArrivals;
	char first = 'A';
	string serverNum;
	string cRatePerMin;
	string cRateMin;
	string maxQL;
	string minStime;
	string maxStime;
	string str;

	fin.open("simulation.txt");
	if (!fin.good()) throw "I/O error";

	for (int i = 0; fin.good(); i++)
	{
		getline(fin, str);
		if (i == 0)
			serverNum = str;
		else if (i == 2)
			cRatePerMin = str;
		else if (i == 4)
			maxQL = str;
		else if (i == 6)
			minStime = str;
		else if (i == 8)
			maxStime = str;
		else if (i == 10)
			cRateMin = str;

		i++;
	}

	serverNumber = atoi(serverNum.c_str());
	cRatePerMins = atof(cRatePerMin.c_str());
	cRateMins = atof(cRateMin.c_str());
	maxQLen = atof(maxQL.c_str());
	MinStime = atof(minStime.c_str());
	MaxStime = atof(maxStime.c_str());

	cout << "Number of servers: " << serverNumber << endl;
	cout << "Customer arrival rate: " << cRatePerMins << " per minute, for ";
	cout << cRateMins << " minutes\n";
	cout << "Maximum queue length: " << maxQLen << endl;
	cout << "Minimum service time: " << MinStime << " minutes\n";
	cout << "Maximum service time: " << MaxStime << " minutes\n";
	cout << endl;


	Queue<customer> wait;
	DynamicArray<customer> nowServing;
	DynamicArray<bool> busy;

	for (int time = 0;; time++)
	{
		for (int i = 0; i < serverNumber; i++)
		{
			if (busy[i] == true)
			{
				if (time == nowServing[i].serviceEndTime)
				{
					busy[i] = false;
				}
			}
		}
		if (time < cRateMins)
		{
			numOfArrivals = getRanNumOfArrivals(cRateMins);
			for (int i = 0; i < numOfArrivals; i++)
			{
				if (wait.size() < maxQLen)
				{
					customer c;
					c.arrivalTime = time;
					if (first == 'Z')
					{
						c.IDtag = first;
						first = 'A';
					}
					else
						c.IDtag = first++;
					wait.push(c);
				}
			}
		}
		for (int i = 0; i < serverNumber; i++)
		{
			if (busy[i] == false)
			{
				if (wait.size() != 0)
				{
					nowServing[i] = wait.front();
					wait.pop();
					nowServing[i].serviceEndTime = time + (3 + rand() % 8);
					busy[i] = true;
				}
			}

		}

		cout << "Time: " << time << endl;
		cout << "----------------------------\n";
		cout << "server now serving wait line\n";
		cout << "------ ----------- ---------\n";
		for (int i = 0; i < serverNumber; i++)
		{
			cout << "  " << i + 1;
			if (busy[i])
				cout << "          " << nowServing[i].IDtag;
			if (i == 0 && wait.size() != 0)
			{
				cout << "      ";
				Queue<customer> copy(wait);
				for (int j = 0; j < copy.size(); j++)
				{
					cout << copy.front().IDtag;
					copy.pop();
				}
			}
			cout << endl;
		}


		int index = 0;
		for (int i = 0; i < serverNumber; i++)
		{
			if (busy[i] == false)
				index++;
		}
		if (index == serverNumber)
			break;
		cout << "Press enter to continue....";
		cin.get();
	}
	system("Pause"); 
	return 0;
}