#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("input/6.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    getline(input, line);

    for ( unsigned int i = 3; i < line.length(); i++ ) {
        unordered_set<char> m;
        m.emplace(line.at(i-3));
        m.emplace(line.at(i-2));
        m.emplace(line.at(i-1));
        m.emplace(line.at(i));
        
        if ( m.size() == 4 ) {
            cout << "Part 1: " << i+1 << "\n";
            break;
        }
    }

    for ( unsigned int i = 13; i < line.length(); i++ ) {
        unordered_set<char> m;
        m.emplace(line.at(i-13));
        m.emplace(line.at(i-12));
        m.emplace(line.at(i-11));
        m.emplace(line.at(i-10));
        m.emplace(line.at(i-9));
        m.emplace(line.at(i-8));
        m.emplace(line.at(i-7));
        m.emplace(line.at(i-6));
        m.emplace(line.at(i-5));
        m.emplace(line.at(i-4));
        m.emplace(line.at(i-3));
        m.emplace(line.at(i-2));
        m.emplace(line.at(i-1));
        m.emplace(line.at(i));
        
        if ( m.size() == 14 ) {
            cout << "Part 2: " << i+1 << "\n";
            break;
        }
    }

    input.close();

    return 0;
}