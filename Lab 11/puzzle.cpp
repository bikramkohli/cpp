// Bikram Kohli (bsk4uaa)
// puzzle.cpp

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int bfs(string unsolved);

int bfs(string unsolved) {
	map<string, int> visited;
	map<string, int> path;
	queue<string> q;
	q.push(unsolved);

	path[unsolved] = 0;

	while (!q.empty()) {
		string neighborNode;
		string parent = q.front();
		q.pop();

		if (parent.find('0') == 0) {
			neighbor = q.front();
			swap(neighbor[parent.find('0')], neighbor[parent.find('0') + 1]);
			if
		}

		if (parent.find('0') == 1) {

		}

		if (parent.find('0') == 2) {

		}

		if (parent.find('0') == 3) {
			
		}

		if (parent.find('0') == 4) {

		}

		if (parent.find('0') == 5) {
			
		}

		if (parent.find('0') == 6) {

		}

		if (parent.find('0') == 7) {
			
		}

		if (parent.find('0') == 8) {

		}
	}
}

int main() {
	// getting puzzle
	string inputPuzzle;
	cout << "Enter the puzzle to solve: " << endl;
	cin >> inputPuzzle;

	// checking if puzzle is solvable
	int invesrions = 0;
	for (int i = 0; i < inputPuzzle.size(); i++) {
		for int (j = 1; i < inputPuzzle.size(); j++) {
			if (i == '0' || j == '0')
				continue;
			if (inputPuzzle[i] > inputPuzzle[j])
				invesrions += 1;
		}
	}

	if (invesrions % 2 == 0)
		cout << bfs(inputPuzzle) << endl;
	else
		cout << "IMPOSSIBLE" << endl;

	return 0;
}