#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;


string getFirst(string line) {

    // Single Value
    if ( line.find(',') == string::npos ) {
        if ( line.find('[') == string::npos ) {
            return line;
        }
        return line.substr(1,line.length()-2);
    }

    // List of Values/Arrays
    stack<char> s;
    if ( line.at(0) == '[' ) {
        unsigned int i=0;
        s.push('[');
        while ( s.size() > 0 ) {
            i++;
            if ( line.at(i) == '[' ) {
                s.push('[');
            } else if ( line.at(i) == ']' ) {
                s.pop();
            }
        }
        return line.substr(1, i-1);
    } else {
        return line.substr(0, line.find(','));
    }
}

string getSecondOn(string line) {

    if ( line.find(',') == string::npos ) {
        return "";
    }

    stack<char> s;
    if ( line.at(0) == '[' ) {
        unsigned int i=0;
        s.push('[');
        while ( s.size() > 0 ) {
            i++;
            if ( line.at(i) == '[' ) {
                s.push('[');
            } else if ( line.at(i) == ']' ) {
                s.pop();
            }
        }
        if ( i+2 > line.length() ) {
            return "";
        }
        return line.substr(i+2);
    } else if ( line.find(',') != string::npos ) {
        return line.substr(line.find(',')+1);
    } else {
        return "";
    }
}

// 0 Same, 1 First Smaller, 2 Second Smaller
unsigned int compare(string l1, string l2) {
    if ( l1.length() == 0 && l2.length() == 0 ) {
        return 0;
    } else if ( l1.length() == 0 ) {
        return 1;
    } else if ( l2.length() == 0 ) {
        return 2;
    }
    // Both Integers
    if ( l1.find(',') == string::npos && l2.find(',') == string::npos ) {
        
        while ( l1.find('[') != string::npos || l2.find('[') != string::npos ) {
            if ( l1.find('[') != string::npos ) {
                l1 = l1.substr(1, l1.length()-2);
            }
            if ( l2.find('[') != string::npos ) {
                l2 = l2.substr(1, l2.length()-2);
            }
            if ( l1.length() == 0 && l2.length() == 0 ) {
                return 0;
            } else if ( l1.length() == 0 ) {
                return 1;
            } else if ( l2.length() == 0 ) {
                return 2;
            }
        }

        if ( l1.length() == 0 && l2.length() == 0 ) {
            return 0;
        } else if ( l1.length() == 0 ) {
            return 1;
        } else if ( l2.length() == 0 ) {
            return 2;
        }

        if ( stoi(l1) == stoi(l2) ) {
            return 0;
        }
        return stoi(l1) < stoi(l2) ? 1 : 2;
    }

    string first = getFirst(l1);
    string second = getFirst(l2);

    // Both Lists
    unsigned int v = compare(first, second);
    while ( v == 0 ) {
        // Compare second item
        l1 = getSecondOn(l1);
        l2 = getSecondOn(l2);

        if ( l1.length() == 0 && l2.length() == 0 ) {
            return 0;
        } else if ( l1.length() == 0 ) {
            return 1;
        } else if ( l2.length() == 0 ) {
            return 2;
        }

        first = getFirst(l1);
        second = getFirst(l2);

        v = compare(first, second);

    }
    return v;
}

bool sortComp(string l1, string l2) {
    unsigned int i = compare(l1, l2);
    if ( i == 0 ) {
        // cout << "error\n";
        return false;
    }
    return i == 1 ? true : false;
}

int main() {
    
    // open file
    ifstream input;
    input.open("input/13.in");
    if (!input.is_open()) {
        cerr << "Error Opening File\n";
        return -1;
    }


    string line1, line2;
    unsigned int count = 0;
    unsigned int i = 1;

    while ( getline(input, line1) ) {
        getline(input, line2);

        if ( compare(line1, line2) == 1 ) {
            count += i;
        }

        i++;

        // Trash line
        getline(input, line2);
    }

    cout << "Part 1: " << count << "\n";

    input.clear();
    input.seekg(0);

    vector<string> inputStrings;

    inputStrings.push_back("[[2]]");
    inputStrings.push_back("[[6]]");

    while ( getline(input, line1) ) {
        if ( line1 != "" ) {
            inputStrings.push_back(line1);
        }
    }

    sort(inputStrings.begin(), inputStrings.end(), sortComp);
    
    int f = -1;
    int s = -1;
    for ( unsigned int i = 0; i < inputStrings.size(); i++ ) {
        if ( inputStrings[i] == "[[2]]" ) {
            f = i + 1;
            if ( s != -1 ) {
                break;
            }
        }
        if ( inputStrings[i] == "[[6]]" ) {
            s = i + 1;
            if ( s != -1 ) {
                break;
            }
        }
    }

    cout << "Part 2: " << f*s << "\n";

    input.close();

    return 0;
}