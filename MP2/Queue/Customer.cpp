#include "Customer.h"
#include<iostream>

using namespace std;

// Customer Constructor
Customer::Customer(){
    nextCustomer = NULL;
}

Customer::Customer(int at, int st){
    nextCustomer = NULL;
    arrivalTime = at;
    serviceTime = st;
}

void Customer::setArrivalTime(int t){
    arrivalTime = t;
}

int Customer::getArrivalTime(){
    return arrivalTime;
}

void Customer::setServiceTime(int t){
    serviceTime = t;
}

int Customer::getServiceTime(){
    return serviceTime;
}


