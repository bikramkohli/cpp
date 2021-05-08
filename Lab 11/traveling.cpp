#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    sort(dests.begin() + 1, dests.end());
    float currDist = computeDistance(me, dests[0], dests);

    vector<string> temp = dests;

    while(next_permutation(dests.begin() + 1, dests.end())) {
        if (computeDistance(me, dests[0], dests) < currDist) {
            currDist = computeDistance(me, dests[0], dests);
            temp = dests;
        }
    }

    cout << "Minimum path has distance " << currDist << ": ";
    printRoute(dests[0], temp);

    // TODO: YOUR CODE HERE
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/**
 * @brief method to get compute distance of cycle that starts at "start" and goes through all desired cities
 * @param me world
 * @param start starting point
 * @param dests list of cities to go through
 * @return 
*/
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    float totalDist = 0.0;
    for (int i = 1; i < dests.size(); i++) {
        totalDist += me.getDistance(dests[i - 1], dests[i]);
    }
    totalDist += me.getDistance(dests.back(), start);
    return totalDist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
 * @brief prints the route starting at "start" and going through all the cities
 * @param start starting point
 * @param dests list of cities to go through
*/
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    for (int i = 0; i < dests.size(); i++) {
        cout << dests[i] << " -> ";
    }
    cout << start << endl;
}