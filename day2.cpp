#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    // open file
    ifstream input;
    input.open("2.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }

    string line;
    unsigned int sum=0;

    while (getline(input, line)) {
        
        // cout << line << "\n";
        string O = line.substr(0,1);
        string A = line.substr(2,1);

        unsigned int score = 0;

        if(A == "X"){
            score += 1;
            A = "A";
        }else if(A == "Y"){
            score += 2;
            A = "B";
        }else if(A == "Z"){
            score += 3;
            A = "C";
        }

        if(O==A){
            score += 3;
        }else if((O=="A" && A=="B") || (O=="B" && A=="C") || (O=="C" && A=="A")){
            score += 6;
        }

        sum += score;

    }


    cout << "Part 1: " << sum << "\n";


    sum=0;
    input.clear();
    input.seekg(0);

    while (getline(input, line)) {
        
        // cout << line << "\n";
        string O = line.substr(0,1);
        string A = line.substr(2,1);

        unsigned int score = 0;

        if(A == "X") {
            // Loss
            if(O == "A"){
                score += 3;
            }else if(O == "B"){
                score += 1;
            }else{
                score += 2;
            }
        }else if(A == "Y"){
            // Draw
            score += 3;
            if(O == "A"){
                score += 1;
            }else if(O == "B"){
                score += 2;
            }else{
                score += 3;
            }
        }else{
            // Win
            score += 6;

            if(O == "A"){
                score += 2;
            }else if(O == "B"){
                score += 3;
            }else{
                score += 1;
            }
        }
        

        sum += score;

    }

    cout << "Part 2: " << sum << "\n";


    input.close();


    return 0;
}