// Andrei Modiga
// CPS-272
// 07/08/2022
// Machine Problem 1
// find balance of curly braces, parentheses and square brackets.


#include "bits/stdc++.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// compare to stack
bool isTrue(string s) { 
    stack<char> paren;

    // Switch Case
    for (char& c : s) { 
        switch (c) {
        case '(':
        case '{':
        case '[':
        paren.push(c); break;
        case ')':
        
        if (paren.empty() || paren.top()!='(') return false;
        else paren.pop(); break;
        case '}':
        if (paren.empty() || paren.top()!='{') return false;
        else paren.pop(); break;
        case ']':
        if (paren.empty() || paren.top()!='[') return false;
        else paren.pop(); break;
        default: ;
        }
    }
    return paren.empty() ;
}

int main() {
    // Import file
    fstream newfile;
    bool result=true;
    string filename;
    cout << "Enter the file name : ";

    //Read the file name
    cin >> filename;
    newfile.open(filename,ios::in);
    if (newfile.is_open()) {
        string one;
        while(getline(newfile, one)) {
            result=result && isTrue(one);
        }
        newfile.close();
    }
    // compare above and now print the result
    if(result == true) {
        cout<<"The symbols in " << filename << " are balanced.";
    } else {
        cout << "The symbols in " << filename << " are not balanced.";
    }
}