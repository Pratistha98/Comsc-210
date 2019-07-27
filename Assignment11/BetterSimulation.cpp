//Programmar: Pratistha Maharjan
//Programmar's ID: 1650717

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;


#include <cmath>
#include <cstdlib>
#include <cstring>

#include "PriorityQueue.h"
#include "DynamicArray.h"
#include "Queue.h"


struct Customer
{
	char id;
	int arrivalTime;
};

struct serverInfo
{
	Customer customer;
	bool status;
};

struct serviceEvent
{
	int serverNum;
	int endTime;
};

bool operator < (const serviceEvent& a, const serviceEvent& b)
{
	return a.endTime < b.endTime ? false : true;
}

int ranServiceTime(int time, int minStime, int maxStime)
{
	int ran = 0;
	ran = minStime + rand() % (maxStime - minStime);
	return time + ran;
}

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
	rand();
	cout << endl;
	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan\n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	ifstream fin;
	int serverNumber = 0;
	double cRatePerMins = 0.0;
	int cRateMins = 0;
	int maxQLen = 0;
	int MinStime = 0;
	int MaxStime = 0;
	int numOfArrivals;
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
	cRateMins = atoi(cRateMin.c_str());
	maxQLen = atoi(maxQL.c_str());
	MinStime = atoi(minStime.c_str());
	MaxStime = atoi(maxStime.c_str());

	cout << "Number of servers: " << serverNumber << endl;
	cout << "Customer arrival rate: " << cRatePerMins << " per minute, for ";
	cout << cRateMins << " minutes\n";
	cout << "Maximum queue length: " << maxQLen << endl;
	cout << "Minimum service time: " << MinStime << " minutes\n";
	cout << "Maximum service time: " << MaxStime << " minutes\n";
	cout << endl;

	Queue<Customer> waitLine;
	DynamicArray<serverInfo> servers;
	PriorityQueue<serviceEvent> eventList;

	char first = 'A';

	for (int time = 0;; time++)
	{
		while (!eventList.empty())
		{
			if (eventList.top().endTime == time)
			{
				servers[eventList.top().serverNum].status = false;
				eventList.pop();
			}
			else
				break;
		}

		if (time < cRateMins)
		{
			numOfArrivals = getRanNumOfArrivals(cRatePerMins);
			for (int i = 0; i < numOfArrivals; i++)
			{
				if (waitLine.size() < maxQLen)
				{
					Customer c;
					c.arrivalTime = time;
					if (first == 'Z')
					{
						c.id = first;
						first = 'A';
					}
					else
						c.id = first++;
					waitLine.push(c);
				}
			}
		}
		for (int i = 0; i < serverNumber; i++)
		{
			if (servers[i].status == false)
			{
				if (waitLine.size() != 0)
				{
					servers[i].customer = waitLine.front();
					waitLine.pop();
					eventList.push({ i, ranServiceTime(time, MinStime, MaxStime) });
					servers[i].status = true;
				}
			}
		}

		PriorityQueue<serviceEvent> copyEventList = eventList;


		cout << "server | time for end-of-service\n";
		cout << "------ + -----------------------\n";
		while (!copyEventList.empty())
		{
			const serviceEvent &top = copyEventList.top();
			cout << "   " << top.serverNum << "   |";
			cout << "           " << top.endTime << endl;
			copyEventList.pop();
		}

		cout << "Time: " << time << endl;
		cout << "----------------------------\n";
		cout << "server now serving wait line\n";
		cout << "------ ----------- ---------\n";
		for (int i = 0; i < serverNumber; i++)
		{
			cout << "  " << i;
			if (servers[i].status)
			{
				cout.width(12);
				cout << servers[i].customer.id;
			}
			if (i == 0 && !waitLine.empty())
			{
				cout << "      ";
				Queue<Customer> copy = waitLine;
				while (!copy.empty())
				{
					cout << copy.front().id;
					copy.pop();
				}
			}
			cout << endl;
		}

		int index = 0;
		for (int i = 0; i < serverNumber; i++)
		{
			if (servers[i].status == false)
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
