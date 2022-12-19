#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct monkey{
    queue<unsigned long long int> items;
    char oper;
    unsigned int operNum;
    int divisNum;
    unsigned int diT;
    unsigned int diF;
};

int main() {
    
    // open file
    ifstream input;
    input.open("input/11.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line;
    vector<monkey> monkeys;
    vector<unsigned int> counts;

    while ( getline(input, line) ) {

        monkey temp;

        getline(input, line);
        queue<unsigned long long int> sItems;
        line = line.substr(18);
        while ( line.find(',') != string::npos ) {
            sItems.push(stoi(line.substr(0,line.find(',')+2)));
            line = line.substr(line.find(',')+2);
        }
        sItems.push(stoi(line));
        temp.items = sItems;

        getline(input, line);
        temp.oper = line.at(23);
        if ( line.substr(25) == "old" ) {
            temp.oper = '^';
            temp.operNum = 2;
        }else {
            temp.operNum = stoi(line.substr(25));
        }

        getline(input, line);
        temp.divisNum = stoi(line.substr(21));

        getline(input, line);
        temp.diT = stoi(line.substr(29));

        getline(input, line);
        temp.diF = stoi(line.substr(30));

        monkeys.push_back(temp);

        getline(input, line);

    }

    for (unsigned int i = 0; i < monkeys.size(); i++ ) {
        counts.push_back(0);
    }

    for ( unsigned int i = 0; i < 20; i++ ) {
        for (unsigned int j = 0; j < monkeys.size(); j++ ) {
            // For each monkey
            while ( monkeys[j].items.size() > 0 ) {
                unsigned long long int item = monkeys[j].items.front();
                monkeys[j].items.pop();
                counts[j]++;
                switch (monkeys[j].oper) {
                    case 42:
                        item *= monkeys[j].operNum;
                        break;
                    case 43:
                        item += monkeys[j].operNum;
                        break;
                    case 94:
                        item = item*item;
                        break;
                }
                item /= 3;
                
                if ( item % monkeys[j].divisNum == 0 ) {
                    monkeys[monkeys[j].diT].items.push(item);
                } else {
                    monkeys[monkeys[j].diF].items.push(item);
                }
            }
        }
    }
    sort(counts.begin(), counts.end());
    cout << "Part 1: " << counts[counts.size()-1] << "*" << counts[counts.size()-2] << " = ";
    cout << counts[counts.size()-1] * counts[counts.size()-2] << "\n";

    input.clear();
    input.seekg(0);

    monkeys.clear();
    counts.clear();
    unsigned int modEverything = 1;

    while ( getline(input, line) ) {

        monkey temp;

        getline(input, line);
        queue<unsigned long long int> sItems;
        line = line.substr(18);
        while ( line.find(',') != string::npos ) {
            sItems.push(stoi(line.substr(0,line.find(',')+2)));
            line = line.substr(line.find(',')+2);
        }
        sItems.push(stoi(line));
        temp.items = sItems;

        getline(input, line);
        temp.oper = line.at(23);
        if ( line.substr(25) == "old" ) {
            temp.oper = '^';
            temp.operNum = 2;
        }else {
            temp.operNum = stoi(line.substr(25));
        }

        getline(input, line);
        temp.divisNum = stoi(line.substr(21));

        getline(input, line);
        temp.diT = stoi(line.substr(29));

        getline(input, line);
        temp.diF = stoi(line.substr(30));

        monkeys.push_back(temp);

        getline(input, line);

    }

    for (unsigned int i = 0; i < monkeys.size(); i++ ) {
        counts.push_back(0);
        modEverything *= monkeys[i].divisNum;
    }

    for ( unsigned int i = 0; i < 10000; i++ ) {
        for (unsigned int j = 0; j < monkeys.size(); j++ ) {
            // For each monkey
            while ( monkeys[j].items.size() > 0 ) {
                unsigned long long int item = monkeys[j].items.front();
                monkeys[j].items.pop();
                counts[j]++;
                switch (monkeys[j].oper) {
                    case 42:
                        item *= monkeys[j].operNum;
                        break;
                    case 43:
                        item += monkeys[j].operNum;
                        break;
                    case 94:
                        item = item*item;
                        break;
                }
                item %= modEverything;
                
                if ( item % monkeys[j].divisNum == 0 ) {
                    monkeys[monkeys[j].diT].items.push(item);
                } else {
                    monkeys[monkeys[j].diF].items.push(item);
                }
            }
        }
    }
    
    sort(counts.begin(), counts.end());
    cout << "Part 2: " << counts[counts.size()-1] << "*" << counts[counts.size()-2] << " = ";
    unsigned long long int f = counts[counts.size()-1];
    unsigned long long int s = counts[counts.size()-2];
    
    unsigned long long int ans = f * s;
    cout << ans << "\n";

    input.close();

    return 0;
}