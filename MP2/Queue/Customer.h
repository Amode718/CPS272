#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{

    private:
        int arrivalTime;
        int serviceTime;

    public:
        Customer* nextCustomer;
        Customer* previousCustomer;
        Customer();
        Customer(int at, int st);
        void setArrivalTime(int t);
        int getArrivalTime();
        void setServiceTime(int t);
        int getServiceTime();
};

#endif