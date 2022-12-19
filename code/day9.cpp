#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

// This code is terrible. Bad day

using namespace std;

void updateKnot(pair<int, int> &knot, pair<int, int> prev) {
    
    // Update Tail
    if ( knot.first - prev.first >= 2 && knot.second - prev.second >= 2 ) {
        knot.first = prev.first + 1;
        knot.second = prev.second + 1;
    } else if ( knot.first - prev.first <= -2 && knot.second - prev.second <= -2 ) {
        knot.first = prev.first - 1;
        knot.second = prev.second - 1;
    } else if ( knot.second - prev.second >= 2 &&  knot.first - prev.first <= -2) {
        knot.first = prev.first - 1;
        knot.second = prev.second + 1;
    } else if ( knot.second - prev.second <= -2 && knot.first - prev.first >= 2 ) {
        knot.first = prev.first + 1;
        knot.second = prev.second - 1;
    } else if ( knot.first - prev.first >= 2 ) {
        knot.first = prev.first + 1;
        knot.second = prev.second;
    } else if ( knot.first - prev.first <= -2 ) {
        knot.first = prev.first - 1;
        knot.second = prev.second;
    } else if ( knot.second - prev.second >= 2 ) {
        knot.first = prev.first;
        knot.second = prev.second + 1;
    } else if ( knot.second - prev.second <= -2 ) {
        knot.first = prev.first;
        knot.second = prev.second - 1;
    }
}

int main() {
    
    // open file
    ifstream input;
    input.open("input/9.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }

    string line;
    vector<pair<int, int>> headPos;
    vector<pair<int, int>> tailPos;
    headPos.push_back({0, 0});
    tailPos.push_back({0, 0});

    while (getline(input, line)) {
        char c = line.at(0);
        unsigned int count = stoi(line.substr(2));

        for ( unsigned int i = 0; i < count; i++ ) {
            auto lastHead = headPos[headPos.size()-1];
            auto tail = tailPos[tailPos.size()-1];
            // Update Head
            switch ( c ) {
                case 82:
                    lastHead.first++;
                    headPos.push_back(lastHead);
                    break;
                case 76:
                    lastHead.first--;
                    headPos.push_back(lastHead);
                    break;
                case 85:
                    lastHead.second++;
                    headPos.push_back(lastHead);
                    break;
                case 68:
                    lastHead.second--;
                    headPos.push_back(lastHead);
                    break;
            }
            auto head = headPos[headPos.size()-1];
            pair<int, int> newTail = {0, 0};

            // Update Tail
            if ( tail.first - head.first >= 2 ) {
                newTail.first = head.first + 1;
                newTail.second = head.second;
                tailPos.push_back(newTail);
            }
            if ( tail.first - head.first <= -2 ) {
                newTail.first = head.first - 1;
                newTail.second = head.second;
                tailPos.push_back(newTail);
            }
            if ( tail.second - head.second >= 2 ) {
                newTail.first = head.first;
                newTail.second = head.second + 1;
                tailPos.push_back(newTail);
            }
            if ( tail.second - head.second <= -2 ) {
                newTail.first = head.first;
                newTail.second = head.second - 1;
                tailPos.push_back(newTail);
            }
        }
    }

    set<pair<int, int>> dup;
    
    for ( auto item : tailPos ) {
        dup.emplace(item);
    }

    cout << "Part 1: " << dup.size() << "\n";

    input.clear();
    input.seekg(0);

    dup.clear();

    vector<pair<int, int>> knots;
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});
    knots.push_back({0, 0});

    while (getline(input, line)) {
        char c = line.at(0);
        unsigned int count = stoi(line.substr(2));

        for ( unsigned int i = 0; i < count; i++ ) {
            // Update Head
            switch ( c ) {
                case 82:
                    knots[0].first++;
                    break;
                case 76:
                    knots[0].first--;
                    break;
                case 85:
                    knots[0].second++;
                    break;
                case 68:
                    knots[0].second--;
                    break;
            }

            for ( unsigned int i = 1; i < knots.size(); i++ ) {
                updateKnot(knots[i], knots[i-1]);
            }
            dup.emplace(knots[9]);
        }
    }

    cout << "Part 2: " << dup.size() << "\n";

    input.close();


    return 0;
}