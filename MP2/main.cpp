// Andrei Modiga
// CPS-272
// 07/12/2022
// Machine Problem 2
// Queue and Deque market



#include "Queue.h"
#include "Windows.h"
#include <queue>
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>


using namespace std;
int main(int argc, char* argv[])
{
	srand((time(0)));
	const int MINUTE_LENGTH = 10;
	Queue CustomerObjsQueue(MINUTE_LENGTH);
	// TTR = Total Time Reference
	// NATF = Next Arrival Time Reference;
	// NSTF = Next Service Time Reference 
	int TTR, NATF, NSTF = 0;
	TTR = NATF = GetTickCount64();
	while ((GetTickCount64() - TTR) <= (120 * MINUTE_LENGTH))
	{
		if ((GetTickCount64() - NATF) >= (CustomerObjsQueue.nextArrivalTime * MINUTE_LENGTH))
		{
			if (CustomerObjsQueue.isEmpty())
			{
				NATF = NSTF = GetTickCount64();
				CustomerObjsQueue.enqueue();
				cout << " Current Amount Of CustomerObjs In Line: " <<
					CustomerObjsQueue.lineLength() << endl << endl;
			}
			else
			{
				NATF = GetTickCount64();
				CustomerObjsQueue.enqueue();
				cout << " Current Amount Of CustomerObjs In Line: " <<
					CustomerObjsQueue.lineLength() << endl << endl;
			}
			CustomerObjsQueue.nextArrivalTime = rand() % 3 + 1;
		}
		if (!CustomerObjsQueue.isEmpty() && ((GetTickCount64() - NSTF) >= (CustomerObjsQueue.front().serviceTime * MINUTE_LENGTH)))
		{
			CustomerObjsQueue.dequeue();
			cout << " Current Amount Of CustomerObjs In Line: " <<
				CustomerObjsQueue.lineLength() << endl << endl;
			NSTF = GetTickCount64();
		}
	}
	while (!CustomerObjsQueue.isEmpty())
	{
		if ((GetTickCount64() - NSTF) >= (CustomerObjsQueue.front().serviceTime * MINUTE_LENGTH))
		{
			CustomerObjsQueue.dequeue();
			cout << " Current Amount Of CustomerObjs In Line: " << CustomerObjsQueue.lineLength() << endl << endl;
			NSTF = GetTickCount64();
		}
	}

	cout << "SIMULATION ENDED\n\n";

	cout << CustomerObjsQueue << "\n\n" << endl;
	return 0;
}