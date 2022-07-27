#include "CustomerObj.h"
#include "Windows.h"
#include <random>
#include <iostream>
using namespace std;

int CustomerObj::stamp = 0;

CustomerObj::CustomerObj()
{
	NO = ++stamp;
	serviceTime = rand() % 4 + 1;
	waitStartTime = GetTickCount64();
}

ostream& operator<<(ostream& out, const CustomerObj& CustomerObj)
{
	out << "CustomerObj NO " << CustomerObj.NO;
	return out;
}