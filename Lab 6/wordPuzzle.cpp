// Bikram Kohli (bsk4uaa)
// wordPuzzle.cpp

#include <fstream>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main(int argc, char** argv) {
    // reading in dictionary
    timer time;
    int numLines = 0;
    int numWords = 0;
    string str;
    string fileName = argv[1];

    ifstream file(fileName);
    while (getline(file, str)) {
        if (str.length() > 2) {
            numLines++;
        }
    }

    hashTable dict(numLines);

    ifstream abc(fileName);
    while (getline(abc, str)) {
        if (str.length() > 2)
            dict.insert(str);
    }
    
    // reading in grids
    int rows, cols;
    readInGrid(argv[2], rows, cols);

    time.start();
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            for (int d = 0; d < 8; d++) {
                for (int l = 3; l < 22; l++) {

                    string direction = "";
                    if (d == 0)
                        direction = "N ";
                    else if (d == 1)
                        direction = "NE";
                    else if (d == 2)
                        direction = "E ";
                    else if (d == 3)
                        direction = "SE";
                    else if (d == 4)
                        direction = "S ";
                    else if (d == 5)
                        direction = "SW";
                    else if (d == 6)
                        direction = "W ";
                    else if (d == 7)
                        direction = "NW";

                    if (!(l > rows) || !(l > cols)) {
                        string foundWord;
                        foundWord = getWordInGrid(r, c, d, l, rows, cols);
                        if (dict.find(foundWord)) {
                            if (!(foundWord.length() < l)) {
                                numWords++;
                                cout << direction + "(" << r << ", " << c << + "): \t" + foundWord << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    time.stop();
    cout << numWords << " words found" << endl;
    // cout << 1000 * (int)time.getTime() << endl;

    return 0;
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}