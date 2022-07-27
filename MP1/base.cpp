// Andrei Modiga
// CPS-272
// 07/08/2022
// Machine Problem 1
// Find the base of a number

#include <iostream>
#include <string.h>
using namespace std;

// reverse a string
void strev(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// To return char for a value. 
char reVal(int num) {
    if (num >= 0 && num <= 9) {
    return (char)(num + '0');
    } else {
    return (char)(num - 10 + 'A');
    }
}


// convert a given decimal number to base
char* fromDeci(char res[], int base, int inputNum) {
    int index = 0; 
    while (inputNum > 0) {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    
    res[index] = '\0';
    // Reverse the result
    strev(res);
    return res;
}


int main() {
    int Num,base;
    char res[100];
    do {
        cout<<"Enter a non-negative decimal number and base (2 <= B <= 16) or 0 0 to terminate : ";
        cin >> Num >> base;
        cout << Num <<" base " << base << " is " << fromDeci(res, base, Num) << endl;
    }
    while(Num!=0 && base!=0);
    return 0;
} 