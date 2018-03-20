#include <iostream>
using namespace std;
#include "Customer.h"


int Customer::nextId = 1000;
Customer::Customer():id(nextId){
  Customer::nextId++;
}

Customer::Customer(string fname, string lname, string add, string pnum): id(nextId){
    Customer::nextId++;
    firstName   = fname;
    lastName    = lname;
    address     = add;
    phoneNumber = pnum;
}

int           Customer::getId()                 const  { return id; }
string        Customer::getFname()              const  { return firstName; }
string        Customer::getLname()              const  { return lastName; }
string        Customer::getAddress()            const  { return address; }
string        Customer::getPhoneNumber()        const  { return phoneNumber; }
int           Customer::getNumVehicles()               { return vehicles.getSize(); }
VehicleList& Customer::getVehicles()                   { return vehicles; }
void           Customer::addVehicle(Vehicle* v)         { vehicles.add(v); }
Customer*     Customer::getNext()               const  { return next; }
void          Customer::setNext(Customer* next)        { this->next = next; }
