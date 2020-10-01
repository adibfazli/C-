#include<iostream>
using namespace std;

class inventory {
  // Private members of the class
  private:
    int itemNumber;      // int that holds the items number
    int quantity;        // int that holds the quantity of the item on hand
    double cost;         // double that holds the wholesale per-unit cost of the item
    double totalCost;

  // public members of the class
  public:
    //********************************************************//
    //                     Constructors                       //
    //********************************************************//
    inventory() {                  // default constructor that sets the values to 0
      itemNumber = 0;
      quantity = 0;
      cost = 0.0;
      totalCost= 0.0;
    }

    inventory(int itemNumber, int quantity, double cost) {
      setItemNumber(itemNumber);  // custom constructor that sets the given values Accepts an item’s number, quantity, and cost as arguments. 
      setQuantity(quantity);      //Callsother class functions to copy these values into the appropriate member variables. Then calls the setTotalCost function.
      setCost(cost);
      setTotalCost();
    }

    //********************************************************//
    //                GETTERS AND SETTERS                     //
    //********************************************************//
    int getItemNumber(){            // returns the value in ItemNumber
      return itemNumber;
    }
    void setItemNumber(int itemNumber) {    // sets the value of itemNumber
      this->itemNumber = itemNumber;
    }
    
    int getQuantity() {             // returns the value in quantity
      return quantity;
    }
    void setQuantity(int quantity) {       // sets the value of quantity
      this->quantity = quantity;
    }

    double getCost() {               // returns the value in cost
      return cost;
    }
    void setCost(double cost) {          // sets the value of cost
      this->cost = cost;
    }

    double getTotalCost() {           // computes and returns the totalCost
      return cost*quantity;
    }
    void setTotalCost() {             // sets the value of totalCost
      totalCost = cost*quantity;
    }
};