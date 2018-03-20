#include "Shop.h"
#include "defs.h"

void Shop::addCustomer(Customer* c) { customers.add(c); }

Customer* Shop::getCustomer(int id)  const { return (customers.get(id)); }

CustomerList& Shop::getCustomers() { return customers; }
