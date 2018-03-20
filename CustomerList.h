#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"

class CustomerList
{
    public:
        CustomerList();
        ~CustomerList();
        void add(Customer*);
        Customer* get(int) const;
        int getSize() const;
        void toString(string& outStr);
    private:
        Customer* head = NULL;
        int size;
};

#endif
