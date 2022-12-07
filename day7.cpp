#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("7.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    unsigned int sum=0;
    unordered_map<unsigned int, unsigned int> sizes;
    vector<unsigned int> stk;

    unsigned int unique = 0;

    while ( getline(input, line) ) {
        if ( line.at(0) == '$' ) {
            // command
            if ( line.at(2) == 'c' && line.at(5) == '.' ) {
                stk.pop_back();
            } else if ( line.at(2) == 'c' ) {
                stk.push_back(unique);
                sizes.emplace(unique,0);
            }
        } else {
            if ( line.at(0) == 'd' ) {
                continue;
            }
            for ( auto item : stk ) {
                sizes[item] += stoi(line.substr(0,line.find(" ")));
            }
        }
        unique++;
    }

    for ( auto item : sizes ) {
        if ( item.second <= 100000 ) {
            sum += item.second;
        }
    }
    cout << "Part 1: " << sum << "\n";

    unsigned int remaining = 70000000 - sizes[0];
    unsigned int required = 30000000 - remaining;

    unsigned int smallest = -1;
    for( auto item : sizes ) {
        if ( item.second < smallest && item.second >= required ) {
            smallest = item.second;
        }
    }

    cout << "Part 2: " << smallest << "\n";

    input.close();


    return 0;
}