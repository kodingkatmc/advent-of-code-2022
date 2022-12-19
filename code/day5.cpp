#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("input/5.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    string* levels = new string[8];

    getline(input, levels[0]);
    getline(input, levels[1]);
    getline(input, levels[2]);
    getline(input, levels[3]);
    getline(input, levels[4]);
    getline(input, levels[5]);
    getline(input, levels[6]);
    getline(input, levels[7]);

    stack<char>* stacks = new stack<char>[9];

    for (unsigned int i = 8; i > 0; i-- ) {
        for (unsigned int j = 0; j < 9; j++ ) {
            char data = levels[i-1][1+4*j];
            if ( data != 32 ) {
                stacks[j].push(data);
            }
        }
    }

    getline(input, line);
    getline(input, line);

    while (getline(input, line)) {
        line = line.substr(5);
        unsigned int count = stoi(line.substr(0,line.find(" ")));
        line = line.substr(line.find(" ")+6);
        unsigned int start = stoi(line.substr(0,line.find(" ")))-1;
        line = line.substr(line.find(" ")+4);
        unsigned int end = stoi(line)-1;

        while ( count > 0 ) {
            count--;
            char data = stacks[start].top();
            stacks[end].push(data);
            stacks[start].pop();
        }
    }

    cout << "Part 1: ";
    for ( unsigned int i = 0; i < 9; i++ ) {
        cout  << stacks[i].top();
    }
    cout << "\n";


    delete[] stacks;

    input.clear();
    input.seekg(0);

    
    getline(input, levels[0]);
    getline(input, levels[1]);
    getline(input, levels[2]);
    getline(input, levels[3]);
    getline(input, levels[4]);
    getline(input, levels[5]);
    getline(input, levels[6]);
    getline(input, levels[7]);

    stacks = new stack<char>[9];

    for (unsigned int i = 8; i > 0; i-- ) {
        for (unsigned int j = 0; j < 9; j++ ) {
            char data = levels[i-1][1+4*j];
            if ( data != 32 ) {
                stacks[j].push(data);
            }
        }
    }

    getline(input, line);
    getline(input, line);

    while (getline(input, line)) {
        line = line.substr(5);
        unsigned int count = stoi(line.substr(0,line.find(" ")));
        line = line.substr(line.find(" ")+6);
        unsigned int start = stoi(line.substr(0,line.find(" ")))-1;
        line = line.substr(line.find(" ")+4);
        unsigned int end = stoi(line)-1;

        stack<char> temp;
        while ( count > 0 ) {
            count--;
            char data = stacks[start].top();
            temp.push(data);
            stacks[start].pop();
        }
        while ( temp.size() > 0 ) {
            char data = temp.top();
            stacks[end].push(data);
            temp.pop();
        }
    }

    cout << "Part 2: ";
    for ( unsigned int i = 0; i < 9; i++ ) {
        cout  << stacks[i].top();
    }
    cout << "\n";

    input.close();

    delete[] levels;
    delete[] stacks;

    return 0;
}