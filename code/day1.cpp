#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    // open file
    ifstream input;
    input.open("input/1.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }

    vector<unsigned int> sums;
    string line;
    unsigned int sum=0;

    while (getline(input, line)) {
        
        if(line.length() == 0){
            // cout << line << "\n";
            // cout << sum << "\n";
            sums.push_back(sum);
            sum = 0;
        }else{
            sum += stoi(line);
        }

    }

    sort(sums.begin(), sums.end());

    cout << "Part 1: " << sums[sums.size()-1] << "\n";

    unsigned int total = sums[sums.size()-1]+sums[sums.size()-2]+sums[sums.size()-3];
    cout << "Part 2: " << total << "\n";


    input.close();


    return 0;
}