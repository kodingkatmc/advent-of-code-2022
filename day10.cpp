#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("10.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    int sum = 0;
    int X=1;
    unsigned int cycle = 0;


    while ( getline(input, line) ) {

        cycle++;
        
        // Intersting Values
        if ( cycle%40 == 20 ) {
            sum += X*cycle;
            // cout << cycle << " - cycle #: " << X*cycle << " " << X << "\n";
        }
        
        if ( line.at(0) == 'a' ) {
            cycle ++;
            
            // Intersting Values
            if ( cycle%40 == 20 ) {
                sum += X*cycle;
                // cout << cycle << " - cycle #: " << X*cycle << " " << X << "\n";
            }

            X += stoi(line.substr(5));
        }
    }

    cout << "Part 1: " << sum << "\n";

    input.clear();
    input.seekg(0);

    X=1;
    cycle = 0;
    cout << "Part 2:\n\n";

    string temp = "";

    while ( getline(input, line) ) {

        cycle++;

        // Draw Pixel
        if ( X == (cycle%40) || X+1 == (cycle%40) || X+2 == (cycle%40) ) {
            cout << "#";
            temp += "#";
        } else {
            cout << ".";
            temp += ".";
        }
        if ( cycle%40 == 0 ) {
            cout << "\n";
            temp = "";
        }
        
        if ( line.at(0) == 'a' ) {
            cycle ++;
            
            // Draw Pixel
            if ( X == (cycle%40) || X+1 == (cycle%40) || X+2 == (cycle%40) ) {
                cout << "#";
                temp += "#";
            } else {
                cout << ".";
                temp += ".";
            }
            if ( cycle%40 == 0 ) {
                cout << "\n";
                temp = "";
            }

            X += stoi(line.substr(5));
        }
    }


    input.close();

    return 0;
}