/*
    ADIB FAZLI
    09/25/2020
    This program is a Inventory class that can hold information for an item in a retail store’s inventory.
*/
#include <iostream>
#include <iomanip>
#include "Inventory.cpp"
using namespace std;

int main() {
  // defining variables
  int itemNumber, quantity;
  double cost;

  // getting the input from the user for itemNumbers and making sure the input is greater than 0
  do {
    cout << "Please enter item Number: ";
    cin >> itemNumber;
    cout << endl;
    if ( itemNumber <= 0 ) cout << "Invalid input..." << endl;
  } while( itemNumber <= 0 );

  // getting the input from the user for quantity of items and making sure the input is greater than 0
  do {
    cout << "Please enter quantity: ";
    cin >> quantity;
    cout << endl;
    if ( quantity <= 0 ) cout << "Invalid input... \n";
  } while( quantity <= 0 );

  // getting the input from the user for cost of each item and making sure the input is greater than 0
  do {
    cout << "Please enter cost of each item: ";
    cin >> cost;
    cout << endl;
    if ( cost <= 0 ) cout << "Invalid input...\n";
  } while( cost <= 0 ); 

  // defining a class variable
  inventory inv(itemNumber,quantity,cost);
  // printing the results of total cost of the items
  cout << right << fixed << showpoint << setprecision(2);
  cout << "\n\n**************************************\n" 
       << "The total cost of item #" 
       << inv.getItemNumber() 
       << " is $"
       << inv.getTotalCost() 
       << "\nThe net price of each item is: $" 
       << inv.getCost()
       << "\nThe quantity of the items are: "
       << inv.getQuantity()
       << endl;

  return 0;
}