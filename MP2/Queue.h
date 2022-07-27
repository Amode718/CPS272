#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "Windows.h"
#include "CustomerObj.h"
#include <queue>
#include <string>
class Queue
{
	friend std::ostream& operator<<(std::ostream&, Queue&);
public:
	int nextArrivalTime;
	int recordQueueLength;
	int CustomerObjsServed;
	int minuteLength;
	double maxWaitTime;
	Queue(int);
	const CustomerObj& enqueue();
	CustomerObj& dequeue();
	bool isEmpty();
	const int lineLength();
	CustomerObj& front();
	queue <CustomerObj> serviceLine;

};
#endif // !__QUEUE_H__