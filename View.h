#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&);
        void pause();
        Customer* addCustomer();
        Vehicle* addVehicle();
        int getUserID();
        void customerNonExistant();

    private:
        int readInt();
};

#endif
