#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

void solve(vector<vector<char>> &map, vector<vector<unsigned int>> &values, unsigned int x, unsigned int y, unsigned int sX, unsigned int sY, unsigned int steps, unsigned int prevH) {
    
    if ( x < 0 || y < 0 || x > map[0].size()-1 || y > map.size()-1 ) {
        return;
    }
    if ( map[y][x] < prevH - 1 ) {
        return;
    }
    if ( y == sY && x == sX ) {
        values[y][x] = min(steps, values[y][x]);
        return;
    }

    if ( values[y][x] > steps ) {
        values[y][x] = steps;
        solve(map, values, x+1, y, sX, sY, steps+1, map[y][x]);
        solve(map, values, x-1, y, sX, sY, steps+1, map[y][x]);
        solve(map, values, x, y-1, sX, sY, steps+1, map[y][x]);
        solve(map, values, x, y+1, sX, sY, steps+1, map[y][x]);
    }
}

int main() {
    
    // open file
    ifstream input;
    input.open("input/12.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    vector<vector<char>> map;
    vector<vector<unsigned int>> values;
    unsigned int sX, sY, eX, eY;

    while ( getline(input, line) ) {
        vector<char> temp;
        vector<unsigned int> temp2;
        for ( char c : line ) {
            if ( c == 'S' ) {
                sX = temp.size();
                sY = map.size();
                temp.push_back('a');
            } else if ( c == 'E' ) {
                eX = temp.size();
                eY = map.size();
                temp.push_back('z');
            } else {
                temp.push_back(c);
            }
            temp2.push_back(UINT_MAX);
        }
        map.push_back(temp);
        values.push_back(temp2);
    }
    
    solve(map, values, eX, eY, sX, sY, 0, 'z');

    cout << "Part 1: " << values[sY][sX] << "\n";

    unsigned int m = UINT_MAX;

    for ( unsigned int y = 0; y < map.size(); y++ ) {
        for ( unsigned int x = 0; x < map[0].size(); x++ ) {
            if ( map[y][x] == 'a' ) {
                m = min(m, values[y][x]);
            }
        }
    }

    cout << "Part 2: " << m << "\n";

    input.close();

    return 0;
}