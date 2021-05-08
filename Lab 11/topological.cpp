// Bikram Kohli (bsk4uaa)
// topological.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
void topsort(map<string, vector<string>> graph) {
	int counter = graph.size();
	// while graph isn't empty
	while (counter != 0) {
		// go through each element in the graph
		for (auto it : graph) {
			it.first() = first;
			it.second() = second;
			// if element has no indegrees
			if (second.size() == 0) {
				// print, get rid of vertex, and decrement counter
				cout << first << endl;
				graph.erase(first);
				counter--;

				// going through each element and seeing if they have connections from this vertex
				for (auto temp : graph) {
					temp.first() = first2;
					temp.second() = second2;
					// deleting connecting edges from this vertex
					if (find(second2.begin(), second2.end(), first) != second2.end())
						remove(second2.begin(), second2.end(), first);

				}
			}
		}
	}
}
*/

int main(int argc, char** argv) {
	if (argc != 2) {
		 cout << "Must supply the input file name as the one and only parameter" << endl;
		 return 1;
	}

	ifstream file(argv[1]);
	bool test = file.is_open();
	string initialVert;
	string connectedVert;
	map<string, vector<string>> graph;
	map<string, int> indegreeMap;

	if (test) {
		while (file >> initialVert) {
			file >> connectedVert;
			if (initialVert == "0" || connectedVert == "0") {
				break;
			}
			graph[initialVert].push_back(connectedVert);
			indegreeMap[connectedVert] += 1;
			// sets vertecies that don't have anything pointing to them to indegree 0
			if (indegreeMap.find(initialVert) == indegreeMap.end())
				indegreeMap[initialVert] = 0;
			// graph: vertex -> everything it connects to
			// indegreeMap: vertext -> how many indegrees
		}
	}

	queue<string> q;
	int size = graph.size();
	vector<string> sortedVec;

	for (auto it : indegreeMap) {
		if (it.second == 0) {
			sortedVec.push_back(it.first);
		}
	}

	while (!sortedVec.empty()) {
		sort(sortedVec.begin(), sortedVec.end());
		for (string elem : sortedVec) {
			q.push(elem);
		}
		sortedVec.clear();
		while (!q.empty()) {
			string first = q.front();
			cout << first << " ";
			q.pop();
			// for each adjacent vertext
			for (string w : graph[first]) {
				if (--indegreeMap[w] == 0) {
					sortedVec.push_back(w);
				}
			}
		}
	}
	cout << endl;
	return 0;
}