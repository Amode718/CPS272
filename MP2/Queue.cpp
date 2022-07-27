#include "Queue.h"
#include "Windows.h"
#include <queue>
#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;


Queue::Queue(int minute)
{
	recordQueueLength = 0;
	CustomerObjsServed = 0;
	maxWaitTime = 0;
	nextArrivalTime = rand() % 3 + 1;
	minuteLength = minute;
}
const CustomerObj& Queue::enqueue()
{
	serviceLine.push(CustomerObj());
	if (serviceLine.size() > recordQueueLength)
	{
		recordQueueLength = serviceLine.size();
	}
	cout << serviceLine.back() << " has joined the queue.\n";
	return serviceLine.back();
}
CustomerObj& Queue::dequeue()
{
	if ((GetTickCount64() - serviceLine.front().waitStartTime) > maxWaitTime)
	{
		maxWaitTime = static_cast <double> ((GetTickCount64() - serviceLine.front().waitStartTime)) / minuteLength;
	}
	CustomerObj CustomerObj = serviceLine.front();
	serviceLine.pop();
	cout << CustomerObj << " has left the queue.\n";
	CustomerObjsServed++;
	return CustomerObj;
}
bool Queue::isEmpty()
{
	return serviceLine.empty();
}
CustomerObj& Queue::front()
{
	return serviceLine.front();
}
const int Queue::lineLength()
{
	return serviceLine.size();
}
ostream& operator<<(ostream& out, Queue& serviceQueue)
{
	out << "Total CustomerObjs Served Today: " + to_string(serviceQueue.CustomerObjsServed) <<
		"\n\nLongest Line Length : " + to_string(serviceQueue.recordQueueLength) <<
		"\n\nMaximum Wait Time: " + to_string(serviceQueue.maxWaitTime) + " minutes";
	return out;
}