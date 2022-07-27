// Andrei Modiga
// CPS-272
// 07/28/2022
// Machine Problem 6
// Implimantation of the complex numbers

#include<iostream>
using namespace std;
#include"complex.h"

//take the user input and store it and return the complex number
int main()
{
	Complex c1,c2;

	cin >> c1;
	cin >> c2;
	cout<<"("<<c1<<")"<<"+"<<"("<<c2<<")=" << c1+c2;
	cout<<"\n("<<c1<<")"<<"-"<<"("<<c2<<")=" << c1-c2;
	cout<<"\n("<<c1<<")"<<"*"<<"("<<c2<<")=" << c1*c2;
	cout<<"\n("<<c1<<")"<<"/"<<"("<<c2<<")=" << c1/c2<<endl;
	
}