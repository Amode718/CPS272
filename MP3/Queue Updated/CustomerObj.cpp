#include "CustomerObj.h"
#include <random>
#include <chrono>
#include <iostream>
using namespace std;

int CustomerObj::stamp = 0;

int getTimeElapsed() {
	return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

CustomerObj::CustomerObj()
{
	NO = ++stamp;
	serviceTime = rand() % 4 + 1;
	waitStartTime = getTimeElapsed() ;
}

ostream& operator<<(ostream& out, const CustomerObj& CustomerObj)
{
	out << "CustomerObj NO " << CustomerObj.NO;
	return out;
}