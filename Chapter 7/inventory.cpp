#include "Inventory.h"
//           setter functions
void Inventory::setItemNumber(int itemNumber){ this -> itemNumber = itemNumber; }; // setter function which sets the (ITEM NUMBER) value in the class.
void Inventory::setQuantity(int quantity){ this -> quantity = quantity; };         // setter function which sets the (QUANTITY) value in the class.
void Inventory::setCost(double cost){ this -> cost = cost; };                      // setter function which sets the (COST) value in the class.
void Inventory::setTotalCost(){ totalCost = quantity * cost; };                    // setter function which sets the (TOTAL COST) value in the class.
//           getter functions
int Inventory::getItemNumber(){ return itemNumber; };  // getter function which gets the (ITEM NUMBER) value in the class.
int Inventory::getQuantity(){ return quantity; };      // getter function which gets the (QUANTITY) value in the class.
double Inventory::getCost(){ return cost; };           // getter function which gets the (COST) value in the class.
double Inventory::getTotalCost(){ return totalCost; }; // getter function which gets the (TOTAL COST) value in the class.