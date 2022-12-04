#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("4.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    unsigned int sum=0;

    while (getline(input, line)) {
        unsigned int beg = stoi(line.substr(0,line.find("-")));
        line = line.substr(line.find("-")+1);
        unsigned int end = stoi(line.substr(0,line.find(",")));
        line = line.substr(line.find(",")+1);
        unsigned int beg2 = stoi(line.substr(0,line.find("-")));
        line = line.substr(line.find("-")+1);
        unsigned int end2 = stoi(line.substr(0,line.find(",")));

        if ( (beg <= beg2 && end2 <= end) || (beg2 <= beg && end <= end2) ) {
            sum ++;
        }
    }

    cout << "Part 1: " << sum << "\n";

    input.clear();
    input.seekg(0);

    sum=0;

    while (getline(input, line)) {
        unsigned int beg = stoi(line.substr(0,line.find("-")));
        line = line.substr(line.find("-")+1);
        unsigned int end = stoi(line.substr(0,line.find(",")));
        line = line.substr(line.find(",")+1);
        unsigned int beg2 = stoi(line.substr(0,line.find("-")));
        line = line.substr(line.find("-")+1);
        unsigned int end2 = stoi(line.substr(0,line.find(",")));

        if ( (beg <= beg2 && beg2 <= end) || (beg <= end2 && end2 <= end) ) {
            sum ++;
        } else if ( (beg2 <= beg && beg <= end2) || (beg2 <= end && end <= end2) ) {
            sum ++;
        }
    }

    cout << "Part 2: " << sum << "\n";

    input.close();


    return 0;
}