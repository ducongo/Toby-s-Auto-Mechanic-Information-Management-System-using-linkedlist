#include "VehicleList.h"
#include "Vehicle.h"
#include "defs.h"
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::ostringstream
#include <iomanip>
#include <cstring>

using namespace std;

VehicleList::VehicleList() { size = 0; }
VehicleList::~VehicleList() {
  Vehicle* temp = head->getNext();
  while (temp != NULL){
    delete head;
    head = temp;
    temp = head->getNext();
  }
}

int VehicleList::getSize(){
    int listSize = 0;

    if (head == NULL){

      return 0;
    }
    Vehicle* currentNode = head;

    while (true) {
      listSize += 1;
      currentNode = currentNode->getNext();
      if (currentNode == NULL){
        break;
      }
    }

    return listSize;
  }

void VehicleList::add(Vehicle* v){

    if (head == NULL){
      head = v;

    }else{

      Vehicle* currentNode = head;

      if (v->getYear() > head->getYear()){
        this->head = v;
        this->head->setNext(currentNode);

      }else{
        Vehicle* previousNode = head;
        Vehicle* tempNode = head;

        while (currentNode != NULL){

          if (v->getYear() == currentNode->getYear()){
            tempNode = currentNode->getNext();
            currentNode->setNext(v);
            v->setNext(tempNode);
            break;

          }else if (v->getYear() > currentNode->getYear()){
            previousNode->setNext(v);
            v->setNext(currentNode);
            break;
          }else{
            previousNode = currentNode;
            if (currentNode->getNext() == NULL){
              currentNode->setNext(v);
              break;
            }
            currentNode = currentNode->getNext();
          }
        }
      }
    }


}

Vehicle* VehicleList::get(int i){
    if ((i >= size) || (i < 0)) {
        return 0;
    }
    if (head == NULL){ return 0;}

    Vehicle* currentNode = head;
    int counter = 0;
    while(currentNode != NULL){
      if (i == counter){
        break;
      }else{
        currentNode = currentNode->getNext();
      }
    }

    return currentNode;
}

void VehicleList::toString(string& outStr){

  Vehicle* currentNode = head;
  int j = 0;
  while (true) {

    if (currentNode != NULL){
      std::ostringstream oss;
      oss << "\t" << j+1 << ") " << setw(7) << currentNode->getColour() << " "
           << currentNode->getYear() << " " << setw(17) << currentNode->getMake() << " " << currentNode->getModel()<< " ("
           << currentNode->getMilage() << "km)" << endl;
      std::string s = oss.str();
      outStr += s;
      j += 1;
      currentNode = currentNode->getNext();
    }else{
      break;
    }
  }
}
