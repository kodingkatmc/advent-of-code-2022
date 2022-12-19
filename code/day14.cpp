#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("input/14.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    pair<unsigned int, unsigned int> dim = {680,180};
    unsigned int cave[dim.second][dim.first] = {};
    unsigned int cave2[dim.second][dim.first] = {};
    pair<unsigned int, unsigned int> start = {500,0};
    unsigned int lY = 0;
    
    while ( getline(input, line) ) {
        unsigned int sX = stoi(line.substr(0,line.find(',')));
        line = line.substr(line.find(',')+1);
        unsigned int sY = stoi(line.substr(0,line.find(',')));
        line = line.substr(line.find('>')+2);

        unsigned int eX, eY;
        while ( true ) {
            
            eX = stoi(line.substr(0,line.find(',')));
            line = line.substr(line.find(',')+1);
            eY = stoi(line.substr(0,line.find(',')));

            if ( sY >= dim.second ) {
                cout << sY << endl;
            }
            if ( sX >= dim.first ) {
                cout << sX << endl;
            }
            if ( eY >= dim.second ) {
                cout << eY << endl;
            }
            if ( eX >= dim.first ) {
                cout << eX << endl;
            }

            lY = max(sY, max(eY, lY));

            // cout << sX << sY << eX << eY << endl;
            if ( sY == eY ) {
                for ( unsigned int i = min(sX, eX); i < max(sX, eX)+1; i++ ) {
                    cave[sY][i] = 1;
                    cave2[sY][i] = 1;
                }
            } else if ( sX == eX ) {
                for ( unsigned int i = min(sY, eY); i < max(sY, eY)+1; i++ ) {
                    cave[i][sX] = 1;
                    cave2[i][sX] = 1;
                }
            }
            
            sX = eX;
            sY = eY;
            if ( line.find('>') == string::npos ) {
                break;
            }
            line = line.substr(line.find('>')+2);
        }

    }
    for ( unsigned int i = 0; i < dim.first; i++ ) {
        cave2[lY+2][i] = 1;
    }

    unsigned int c = 0;
    int x = start.first;
    int y = start.second;
    while ( x < dim.first && x > -1 && y+1 < dim.second ) {
        x = start.first;
        y = start.second;
        while( true ) {
            if ( y+1 < dim.second && cave[y+1][x] == 0 ) {
                y++;
            } else if ( x-1 >= 0 && cave[y+1][x-1] == 0 ) {
                y++;
                x--;
            } else if ( x < dim.first && cave[y+1][x+1] == 0 ) {
                y++;
                x++;
            } else if ( x < dim.first && x-1 >= 0 && y+1 < dim.second ) {
                cave[y][x] = 2;
                break;
            } else {
                break;
            }
        }
        c++;
    }
    
    cout << "Part 1: " << c-1 << "\n";

    c = 0;
    x = start.first;
    y = start.second;
    while ( cave2[start.second][start.first] != 2 ) {
        x = start.first;
        y = start.second;
        while( true ) {
            if ( y+1 < dim.second && cave2[y+1][x] == 0 ) {
                y++;
            } else if ( x-1 >= 0 && cave2[y+1][x-1] == 0 ) {
                y++;
                x--;
            } else if ( x < dim.first && cave2[y+1][x+1] == 0 ) {
                y++;
                x++;
            } else if ( x < dim.first && x > -1 && y+1 < dim.second ) {
                cave2[y][x] = 2;
                break;
            } else {
                break;
            }
        }
        c++;
    }
    
    cout << "Part 2: " << c << "\n";

    input.close();

    return 0;
}