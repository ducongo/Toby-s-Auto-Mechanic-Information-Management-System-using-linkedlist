#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <string>
#include "Vehicle.h"
using namespace std;

class VehicleList {

public:
    VehicleList();
    ~VehicleList();
    void add(Vehicle*);
    Vehicle* get(int);
    int getSize();
    void toString(string& outStr);
private:
    int size;
    Vehicle* head = NULL;
};

#endif
