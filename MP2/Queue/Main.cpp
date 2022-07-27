// Andrei Modiga
// CPS-272
// 07/12/2022
// Machine Problem 2
// Queue and Deque market


#include "Customer.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

#define MINUTE 60

Customer *front = NULL;
Customer *back = NULL;

int getRandomTime();
void enqueue(Customer *customer);
Customer *dequeue();
int getCustomersInQueue(int timeElapsed);
void scheduleNext(int timeElapsed);

int main()
{

    int count = 0;
    int currentCount = 0;
    int timeElapsed = 0;

    int longestWaitingTime = 0;
    int maxNumofCustomers = 0;

    int firstCustomerArrival;

    srand(time(0)); // Set random number seed

    // Determine first Customer arrival time
    firstCustomerArrival = getRandomTime();
    cout << "\nFirst customer arrives in " << firstCustomerArrival << " minutes" << endl;

    sleep(firstCustomerArrival * MINUTE);

    timeElapsed += firstCustomerArrival;
    count++;
    cout << "Time elapsed : " << timeElapsed << " minutes" << endl;

    Customer firstCustomer(firstCustomerArrival, getRandomTime());

    cout << "Servicing will take " << firstCustomer.getServiceTime() << " minutes" << endl;

    Customer secondCustomer(timeElapsed + getRandomTime(), getRandomTime());
    enqueue(&secondCustomer);

    sleep(firstCustomer.getServiceTime() * MINUTE);
    timeElapsed += firstCustomer.getServiceTime();
    cout << "Time elapsed : " << timeElapsed << " minutes" << endl;

    while (timeElapsed < 7200)
    {
        scheduleNext(timeElapsed);
        Customer *nextCustomer = front;

        if (nextCustomer != NULL)
        {

            if (nextCustomer->getArrivalTime() <= timeElapsed)
            {
                int customersInQueue = getCustomersInQueue(timeElapsed);
                if (maxNumofCustomers < customersInQueue)
                    maxNumofCustomers = customersInQueue;
                // cout << "\n" << nextCustomer->getArrivalTime() << endl;
                cout << "\nServicing next customer. Service will take " << nextCustomer->getServiceTime() << " minutes." << endl;

                // Customer* newCustomer = new Customer(timeElapsed + getRandomTime(), getRandomTime());
                // enqueue(newCustomer);

                // cout << "Next customer arrives in " << newCustomer->getArrivalTime() << " minute" << endl;
                // cout.flush();

                sleep(nextCustomer->getServiceTime() * MINUTE);
                timeElapsed += (nextCustomer->getServiceTime());
                dequeue();
                cout << "Service finished." << endl;

                int waitingTime = timeElapsed - nextCustomer->getArrivalTime();
                //  cout << timeElapsed << " - " << nextCustomer->getArrivalTime() << endl;
                if (longestWaitingTime < waitingTime)
                    longestWaitingTime = waitingTime;
                cout << "Waiting time : " << waitingTime << " minutes" << endl;
            }
            else
            {
                cout << "\nNo customers in the queue." << endl;
                sleep(MINUTE);
                timeElapsed++;
            }
        }
        else
        {
            cout << "\nNo customers in the queue." << endl;
            sleep(MINUTE);
            timeElapsed++;
        }

        cout << "Time elapsed : " << timeElapsed << " minutes" << endl;
    }

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Longest waiting time = " << longestWaitingTime << " minutes" << endl;
    cout << "Maximum number of customers in queue = " << maxNumofCustomers << endl;

    return 0;
}

// Functions

int getRandomTime()
{
    return rand() % 4 + 1;
}

void enqueue(Customer *customer)
{
    if (front == NULL)
    {
        front = customer;
    }
    else if (back == NULL)
    {
        back = customer;
        front->nextCustomer = back;
    }
    else
    {
        back->nextCustomer = customer;
        back = customer;
    }
}

Customer *dequeue()
{
    Customer *customer = front;
    front = front->nextCustomer;

    return customer;
}

int getCustomersInQueue(int timeElapsed)
{
    Customer *customer = front;
    int count = 0;

    while (customer != NULL)
    {
        if (customer->getArrivalTime() <= timeElapsed)
        {
            count++;
        }
        else
        {
            break;
        }
        customer = customer->nextCustomer;
    }

    return count;
}

void scheduleNext(int timeElapsed)
{
    Customer *customer = front;

    while (customer != NULL)
    {
        if (customer->getArrivalTime() <= timeElapsed)
        {
            Customer *newCustomer = new Customer(timeElapsed + getRandomTime(), getRandomTime());
            enqueue(newCustomer);

            cout << "\nNext customer arrives in " << newCustomer->getArrivalTime() << " minute" << endl;
            cout.flush();
        }
        else
        {
            break;
        }
        customer = customer->nextCustomer;
    }
}