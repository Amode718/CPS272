// Andrei Modiga
// CPS-272
// 07/08/2022
// Machine Problem 1
// see if a string is a palindrome

#include<iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    // Get the string from user
    while(1) {
        cout << "Input a string: ";
        getline(cin, str);

    // If empty end the program
    if (str == "") {
        break;
    }
    // Create a stack
    stack<char> stack;
    int i = 0;
    
    //check first part of string till #
    for (i = 0; i < str.size(); i++) {
        if (str[i] == '#') {
            break;
            }
            
    stack.push(str[i]);
    }
    //check second part of string
    bool compare = true;
    for (int j = i + 1; j < str.size(); j++) {
        char c = stack.top();
        stack.pop();
    
    // compare the top of stack with the current character
    if (c != str[j]) {
        compare = false;
        break;
    }
}   
    // Print the result
    if (compare) {
        cout << str << " matches the pattern" << endl;
    } else {
        cout << str << " does not match the pattern" << endl;
        }
    }
    return 0;

}