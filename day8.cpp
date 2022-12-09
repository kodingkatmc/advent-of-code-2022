#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unsigned int calcScore(unsigned int i, unsigned int j, vector<vector<char>> forest) {
    
    unsigned int left, right, up, down;
    left = 0;
    right = 0;
    down = 0;
    up = 0;
    int x, y;
    x = j-1;
    y = i;
    while ( x >=0 ) {
        left++;
        if ( forest[y][x] >= forest[i][j] ) {
            break;
        }
        x--;
    }
    x = j;
    y = i-1;
    while ( y >=0 ) {
        up++;
        if ( forest[y][x] >= forest[i][j] ) {
            break;
        }
        y--;
    }
    x = j+1;
    y = i;
    while ( x < forest[0].size() ) {
        right++;
        if ( forest[y][x] >= forest[i][j] ) {
            break;
        }
        x++;
    }
    x = j;
    y = i+1;
    while ( y < forest.size() ) {
        down++;
        if ( forest[y][x] >= forest[i][j] ) {
            break;
        }
        y++;
    }
    
    int out = left*right*up*down;
    return out;
}

int main() {
    
    // open file
    ifstream input;
    input.open("8.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    unsigned int sum=0;
    vector<vector<char>> forest;
    vector<vector<bool>> visible;
    vector<vector<unsigned int>> scores;

    while ( getline(input, line) ) {
        vector<char> temp;
        vector<bool> temp2;
        vector<unsigned int> temp3;
        for ( char c : line ) {
            temp.push_back(c);
            temp2.push_back(false);
            temp3.push_back(0);
        }
        forest.push_back(temp);
        visible.push_back(temp2);
        scores.push_back(temp3);
    }

    char tallest = 0;

    for ( unsigned int i = 0; i < forest.size(); i++ ) {
        for ( unsigned int j = 0; j < forest[0].size(); j++ ) {
            if ( forest[i][j] > tallest ) {
                if ( !visible[i][j] ) {
                    visible[i][j] = true;
                    sum++;
                }
                tallest = forest[i][j];
            }
        }
        tallest = 0;
        for ( unsigned int j = forest[0].size(); j > 0; j-- ) {
            if ( forest[i][j-1] > tallest ) {
                if ( !visible[i][j-1] ) {
                    visible[i][j-1] = true;
                    sum++;
                }
                tallest = forest[i][j-1];
            }
        }
        tallest = 0;
    }

    for ( unsigned int i = 0; i < forest[0].size(); i++ ) {
        for ( unsigned int j = 0; j < forest.size(); j++ ) {
            if ( forest[j][i] > tallest ) {
                if ( !visible[j][i] ) {
                    visible[j][i] = true;
                    sum++;
                }
                tallest = forest[j][i];
            }
        }
        tallest = 0;
        for ( unsigned int j = forest.size(); j > 0; j-- ) {
            if ( forest[j-1][i] > tallest ) {
                if ( !visible[j-1][i] ) {
                    visible[j-1][i] = true;
                    sum++;
                }
                tallest = forest[j-1][i];
            }
        }
        tallest = 0;
    }

    cout << "Part 1: " << sum << "\n";

    for ( unsigned int i = 1; i < forest.size()-1; i++ ) {
        tallest = 0;
        for ( unsigned int j = 1; j < forest[0].size()-1; j++ ) {
            scores[i][j] = calcScore(i, j, forest);
        }
    }
    
    sum = 0;
    for ( auto row : scores ) {
        for ( auto cell : row ) {
            sum = max( cell, sum );
        }
    }

    cout << "Part 2: " << sum << "\n";

    input.close();


    return 0;
}