#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class node{
    
    public:

        unsigned int value;
        vector<node*> neighbors;

        node::node(unsigned int v) {
            value = v;
        }

        void node::add(node* n) {
            neighbors.push_back(n);
        }

        node* node::copy(node* n) {
            node temp(n->value);
            for( unsigned int i = 0; i < n->neighbors.size(); i++) {
                temp.add(neighbors[i]);
            }
            return &temp;
        }

        void node::dec(node* n) {
            n->value--;
            for( unsigned int i = 0; i < n->neighbors.size(); i++) {
                n->neighbors[i]->value--;
            }
        }
};

int main() {
    
    // open file
    ifstream input;
    input.open("input/16.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }

    

    string line;
    unordered_map<string, vector<string>> pipes;
    unordered_map<string, unsigned int> rates;

    while ( getline(input, line) ) {
       vector<string> temp;
       string v = line.substr(6, 2);
       rates[v] = stoi(line.substr(23,line.find(';')-23));
       line = line.substr(line.find(";")+24);
       while ( line.find(', ') != string::npos ) {
        temp.push_back(line.substr(0,line.find(',')));
        line = line.substr(line.find(' ')+1);
       }
        temp.push_back(line);

        pipes[v] = temp;
    }

    
    unsigned int count = solve(pipes, rates, memo);

    cout << "Part 1: " << count << "\n";

    input.clear();
    input.seekg(0);

    input.close();

    return 0;
}