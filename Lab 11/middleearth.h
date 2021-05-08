/*! \file middleearth.h
    \brief A documented file

    Details.
*/

/*! \fn void print()
    \brief prints out info about made up world
*/

/*! \fn void printTable()
    \brief prints out table of distances between cities
*/

/*! \fn float getDistance(const string& city1, const string& city2)
    \brief finds the distance between the two passed cities.
    \param city1, first city in computing distance
    \param city2, second city in computing distance
*/

/*! \fn vector<string> getItinerary(unsigned int length)
    \brief gets list of travel cities
    \param length number of cities to travel to
*/

/*! \var int num_city_names
    \brief the number of cities
*/

/*! \var int xsize
    \brief size of Middle-Earth's x axis
*/

/*! \var int ysize
    \brief size of Middle-Earth's y axis
*/

/*! \var unordered_map<string, float> xpos
    \brief x-position of city
*/

/*! \var unordered_map<string, float> ypos
    \brief y-position of city
*/

/*! \var vector<string> cities
    \brief vector of cities
*/

/*! \var unordered_map<string, unordered_map<string, float>> distances
    \brief distances between cities
*/

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);
    void print();
    void printTable();
    float getDistance(const string& city1, const string& city2);
    vector<string> getItinerary(unsigned int length);

private:
    int num_city_names, xsize, ysize;
    unordered_map<string, float> xpos, ypos;
    vector<string> cities;
    unordered_map<string, unordered_map<string, float>> distances;

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif