#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add a Customer to the Database\n\n";
    cout<< "        3. Add a vehicle to the Database\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 3) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}


void View::printCustomers(CustomerList& list) {
    cout << endl << "CUSTOMERS: " << endl << endl;
    string outStr;
    list.toString(outStr);
    cout << outStr<<endl;
    cout << endl << endl;

}

void View::pause() {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

Customer* View::addCustomer(){
  string fname; string lname; string add; string pnum;
  cout << "Please enter the customers first name:";
  getline(cin, fname);
  //cout<<"\n";
  cout << "Please enter the customers last name:";
  getline(cin, lname);
  //cout<<"\n";
  cout << "Please enter the customers address:";
  getline(cin, add);
  //cout<<"\n";
  cout << "Please enter the customers phone number:";
  getline(cin, pnum);
  //cout<<"\n";
  Customer* newCustomer = new Customer(fname, lname, add,pnum);

  return newCustomer;
}

Vehicle* View::addVehicle(){
  string ma; string mo; string col; int y; int m; string year; string mileage;

  cout << "Please enter the make:";
  getline(cin, ma);
  cout << "Please enter the model:";
  getline(cin, mo);
  cout << "Please enter the colour:";
  getline(cin, col);

  cout << "Please enter the year:";
  getline(cin, year);
  cout << "Please enter the mileage:";
  getline(cin, mileage);

  stringstream ss(year);
  ss >> y;
  stringstream ss2(mileage);
  ss2 >> m;

  Vehicle* newVehicle = new Vehicle(ma, mo, col, y, m);

  return newVehicle;

}

int View::getUserID(){
  string id; int uniqueID;
  cout << "Please enter a valid customer ID:";
  getline(cin, id);
  stringstream ss(id);
  ss >> uniqueID;

//  cout<<"\n";
  return uniqueID;
}

void View::customerNonExistant(){
  cout<<"The customer ID is invalid"<<endl;

}

int View::readInt() {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}
