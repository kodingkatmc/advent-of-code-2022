#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("input/3.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }

    unordered_map<string, unsigned int> score;

    {
    score.insert({"a", 1});
    score.insert({"b", 2});
    score.insert({"c", 3});
    score.insert({"d", 4});
    score.insert({"e", 5});
    score.insert({"f", 6});
    score.insert({"g", 7});
    score.insert({"h", 8});
    score.insert({"i", 9});
    score.insert({"j", 10});
    score.insert({"k", 11});
    score.insert({"l", 12});
    score.insert({"m", 13});
    score.insert({"n", 14});
    score.insert({"o", 15});
    score.insert({"p", 16});
    score.insert({"q", 17});
    score.insert({"r", 18});
    score.insert({"s", 19});
    score.insert({"t", 20});
    score.insert({"u", 21});
    score.insert({"v", 22});
    score.insert({"w", 23});
    score.insert({"x", 24});
    score.insert({"y", 25});
    score.insert({"z", 26});
    score.insert({"A", 27});
    score.insert({"B", 28});
    score.insert({"C", 29});
    score.insert({"D", 30});
    score.insert({"E", 31});
    score.insert({"F", 32});
    score.insert({"G", 33});
    score.insert({"H", 34});
    score.insert({"I", 35});
    score.insert({"J", 36});
    score.insert({"K", 37});
    score.insert({"L", 38});
    score.insert({"M", 39});
    score.insert({"N", 40});
    score.insert({"O", 41});
    score.insert({"P", 42});
    score.insert({"Q", 43});
    score.insert({"R", 44});
    score.insert({"S", 45});
    score.insert({"T", 46});
    score.insert({"U", 47});
    score.insert({"V", 48});
    score.insert({"W", 49});
    score.insert({"X", 50});
    score.insert({"Y", 51});
    score.insert({"Z", 52});
    }

    string line;
    unsigned int sum=0;

    while (getline(input, line)) {
        
        unsigned int length = line.length();

        unordered_set<string> comp;

        for(unsigned int i=0; i<length/2; i++){
            comp.insert(line.substr(i,1));
        }

        for(unsigned int i=length/2; i<length; i++){
            if(comp.count(line.substr(i,1))){
                sum += score[line.substr(i,1)];
                break;
            }
        }

    }

    cout << "Part 1: " << sum << "\n";

    input.clear();
    input.seekg(0);
    sum = 0;
    string line1, line2, line3;
    while (getline(input, line1)) {
        
        getline(input, line2);
        getline(input, line3);

        unordered_map<string, unsigned int> count;
        unordered_set<string> temp;

        for(unsigned int i=0; i<line1.length(); i++){
            string c = line1.substr(i,1);
            if(!temp.count(c)){
                count[c]++;
                temp.insert(c);
            }
        }
        temp.clear();
        for(unsigned int i=0; i<line2.length(); i++){
            string c = line2.substr(i,1);
            if(!temp.count(c)){
                count[c]++;
                temp.insert(c);
            }
        }
        temp.clear();
        for(unsigned int i=0; i<line3.length(); i++){
            string c = line3.substr(i,1);
            if(!temp.count(c)){
                count[c]++;
                temp.insert(c);
            }
        }

        for(auto i : count){
            if(i.second == 3){
                sum += score[i.first];
                break;
            }
        }


    }

    cout << "Part 2: " << sum << "\n";

    input.close();


    return 0;
}