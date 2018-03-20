#include "CustomerList.h"
#include "Customer.h"
#include "defs.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream
#include <iomanip>
#include <cstring>

using namespace std;

CustomerList::CustomerList() { size = 0; }
CustomerList::~CustomerList() {
  Customer* temp = head->getNext();
  while (temp != NULL){
    delete head;
    head = temp;
    temp = head->getNext();
  }
}

int CustomerList::getSize() const{

  int listSize = 0;

  if (head == NULL){
    return 0;
  }
  Customer* currentNode = head;

  while (true) {
    listSize += 1;
    currentNode = currentNode->getNext();
    if (currentNode == NULL){
      break;
    }
  }

  return listSize;
}

void CustomerList::add(Customer* c) {

    if (head == NULL){

      head = c;

    }else{

      Customer* currentNode = head;

      if (strcmp(c->getLname().c_str(), currentNode->getLname().c_str()) < 0){
        this->head = c;
        this->head->setNext(currentNode);

      }else{
        Customer* previousNode = head;
        Customer* tempNode = head;
        while (currentNode != NULL){

          int comparison = strcmp(c->getLname().c_str(), currentNode->getLname().c_str());
          if (comparison == 0){

            tempNode = currentNode->getNext();
            currentNode->setNext(c);
            c->setNext(tempNode);
            break;

          }else if (comparison < 0){

            previousNode->setNext(c);
            c->setNext(currentNode);
            break;
          }else{

            previousNode = currentNode;
            if (currentNode->getNext() == NULL){
              currentNode->setNext(c);

              break;
            }
            currentNode = currentNode->getNext();
          }
        }
      }
    }

}

Customer* CustomerList::get(int id)  const{

    if (head == NULL){ return 0;}

    Customer* currentNode = head;

    while(currentNode != NULL){
      if (id == currentNode->getId()){
        return currentNode;
      }else{
        currentNode = currentNode->getNext();
      }
    }

    return 0;
}

void CustomerList::toString(string& outStr){

  Customer* currentNode = head;
  int j = 1;
  while (true) {


    if (currentNode != NULL){

      ostringstream name;
      ostringstream oss;
      name << currentNode->getFname() << " " << currentNode->getLname();

      oss << "Customer ID " << currentNode->getId() << endl << endl
           << "    Name: " << setw(40) << name.str() << endl
           << "    Address: " << setw(37) << currentNode->getAddress() << endl
           << "    Phone Number: " << setw(32) <<  currentNode->getPhoneNumber() << endl;
      std::string s = oss.str();
      outStr += s;
      if (currentNode->getNumVehicles() < 0) {

           ostringstream noVehicle;
           noVehicle << endl << "    " << currentNode->getNumVehicles()
                << " vehicle(s): " << endl << endl;
          s = noVehicle.str();
          outStr += s;
      }else{

        currentNode->getVehicles().toString(outStr);
      }

      currentNode = currentNode->getNext();
      j++;
    }else{
      break;
    }


  }
}
