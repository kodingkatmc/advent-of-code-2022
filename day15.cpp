#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct sensor{
    int x;
    int y;
    int bX;
    int bY;
    int dist;
};

int main() {
    
    // open file
    ifstream input;
    input.open("15.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }

    vector<sensor> sensors;
    int minX = 0;
    int maxX = 0;

    string line;

    while ( getline(input, line) ) {
        sensor temp;
        line = line.substr(line.find("=")+1);
        temp.x = stoi(line.substr(0,line.find(',')));
        line = line.substr(line.find("=")+1);
        temp.y = stoi(line.substr(0,line.find(',')));
        line = line.substr(line.find("=")+1);
        temp.bX = stoi(line.substr(0,line.find(',')));
        line = line.substr(line.find("=")+1);
        temp.bY = stoi(line);

        temp.dist = abs(temp.bX - temp.x) + abs(temp.bY - temp.y);

        sensors.push_back(temp);

        minX = min(minX, temp.x-temp.dist);
        maxX = max(maxX, temp.x+temp.dist);
    }

    input.close();

    unsigned int count = 0;
    int y = 2000000;
    for ( int i = minX; i < maxX; i++ ) {
        bool c = false;
        for ( sensor s : sensors ) {
            int cell = abs(i - s.x) + abs(y - s.y);
            if ( cell <= s.dist && ( i != s.bX || y != s.bY ) ) {
                c = true;
                break;
            }
        }
        count = c ? count + 1 : count ;
    }

    cout << "Part 1: " << count << "\n";

    count = 0;
    for ( long long int y = 0; y < 4000001; y++ ) {
        for ( long long int x = 0; x < 4000001; x++ ) {
            bool noSensor = true;
            for ( sensor s : sensors ) {
                int cell = abs(x - s.x) + abs(y - s.y);
                if ( cell <= s.dist ) {
                    noSensor = false;
                    x += abs(cell - s.dist); 
                    break;
                }
            }
            if ( noSensor ) {
                cout << "Part 2: " << x << ", " << y << " - ";
                long long int out = x*4000000 + y;
                cout << out << "\n";
                return 0;
            }
        }
    }

    cout << "Part 2: No Location Found\n";

    return 0;
}