//Programmer: Pratistha Maharjan 
//Programmer's ID: 1650717
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
	string name;

	bool isVisited;
	list<pair<int, double> > neighbors;
	int prev;
	double cost;
};

struct Terminus //the path to a node and the cost of that path
{
	int index;    //the node's index in the database array
	int prev;     //the index of the preceding node in the path
	double cost;  //the cost of getting to index's node from prev's node
};

bool operator < (const Terminus& a, const Terminus& b)
{
	return b.cost < a.cost; //reverse logic for lo-to-hi
}

queue<int> BFS(int startNodeIndex, vector<Node>& database);

queue<int> DFS(int startNodeIndex, vector<Node>& database);

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
	pair<stack<int>, double> result;
	list<pair<int, double> >::iterator it; // to iterate over neighbors
	// TO DO -- write this function
	for (int i = 0; i < database.size(); i++)
	{
		database[i].cost = 0;
		database[i].prev = -1;
		database[i].isVisited = false;
	}
	priority_queue<Terminus> toDoList;
	Terminus t = { iStart, -1, 0 };
	toDoList.push(t);

	while (!toDoList.empty())
	{
		Terminus temp = toDoList.top();
		toDoList.pop();

		if (database[temp.index].isVisited) continue;

		database[temp.index].isVisited = true;
		database[temp.index].cost = temp.cost;
		database[temp.index].prev = temp.prev;

		if (temp.index == iEnd) break;

		for (it = database[temp.index].neighbors.begin(); it != database[temp.index].neighbors.end(); it++)
		{
			Terminus tempe;
			tempe.index = it->first;
			tempe.cost = it->second + temp.cost;
			tempe.prev = temp.index;
			toDoList.push(tempe);
		}
	}

	result.second = database[iEnd].cost;

	for (int i = iEnd; i >= 0; i = database[i].prev) //Travesing from iEnd back to iStart
		result.first.push(i);
	return result;
}


int main()
{
	//Programmer's identification
	cout << "Programmer     : Pratistha Maharjan \n";
	cout << "Prgorammer's ID: 1650717\n";
	cout << "File: " << __FILE__ << endl << endl;

	ifstream fin;
	fin.open("cities.txt");
	if (!fin.good()) throw "I/O error";

	// process the input file
	vector<Node> database;
	while (fin.good()) // EOF loop
	{
		string fromCity, toCity, cost;

		// read one edge
		getline(fin, fromCity);
		getline(fin, toCity);
		getline(fin, cost);
		fin.ignore(1000, 10); // skip the separator

		// add nodes for new cities included in the edge
		int iToNode = -1, iFromNode = -1, i;
		for (i = 0; i < database.size(); i++) // seek "to" city
			if (database[i].name == fromCity)
				break;
		if (i == database.size()) // not in database yet
		{
			// store the node if it is new
			Node fromNode = { fromCity };
			database.push_back(fromNode);
		}
		iFromNode = i;

		for (i = 0; i < database.size(); i++) // seek "from" city
			if (database[i].name == toCity)
				break;
		if (i == database.size()) // not in vector yet
		{
			// store the node if it is new
			Node toNode = { toCity };
			database.push_back(toNode);
		}
		iToNode = i;

		// store bi-directional edges
		double edgeCost = atof(cost.c_str());
		database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
		database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
	}
	fin.close();
	cout << "Input file processed\n\n";

	while (true)
	{
		string fromCity, toCity;
		cout << "\nEnter the source city [blank to exit]: ";
		getline(cin, fromCity);
		if (fromCity.length() == 0) break;

		// find the from city
		int iFrom;
		for (iFrom = 0; iFrom < database.size(); iFrom++)
			if (database[iFrom].name == fromCity)
				break;

		cout << "Enter the destination city [blank to exit]: ";
		getline(cin, toCity);
		if (toCity.length() == 0) break;

		// find the destination city
		int iTo;
		for (iTo = 0; iTo < database.size(); iTo++)
			if (database[iTo].name == toCity)
				break;

		cout << "Route";
		pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
		for (; !result.first.empty(); result.first.pop())
			cout << '-' << database[result.first.top()].name;
		cout << endl;
		cout << "Miles: " << result.second;
		cout << endl;
	}
	system("Pause"); 
	return 0;
}
