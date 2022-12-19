#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("input/day.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    unsigned int count = 0;

    while ( getline(input, line) ) {
       
    }

    cout << "Part 1: " << count << "\n";

    input.clear();
    input.seekg(0);

    input.close();

    return 0;
}