#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"
using namespace std;

class Customer {

    public:

        Customer(string="", string="", string="", string="");
        Customer();
        int getId() const;
        string getFname() const;
        string getLname() const;
        string getAddress() const;
        string getPhoneNumber() const;
        int getNumVehicles();
        VehicleList& getVehicles();
        Customer* getNext() const;
        void setNext(Customer*);

        void addVehicle(Vehicle*);

    private:

        static int nextId;

        const int id;
        Customer* next = NULL;
        string firstName;
        string lastName;
        string address;
        string phoneNumber;
        VehicleList vehicles;
};

#endif
