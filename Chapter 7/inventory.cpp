#include "Inventory.h"

        void Inventory::setItemNumber(int itemNumber){ this -> itemNumber = itemNumber; };
        void Inventory::setQuantity(int quantity){ this -> quantity = quantity; };
        void Inventory::setCost(double cost){ this -> cost = cost; };
        void Inventory::setTotalCost(){ totalCost = quantity * cost; };

        int Inventory::getItemNumber(){ return itemNumber; };
        int Inventory::getQuantity(){ return quantity; };
        double Inventory::getCost(){ return cost; };
        double Inventory::getTotalCost(){ return totalCost; };