/*
    ADIB FAZLI
    09/25/2020
    This program is a Inventory class that can hold information for an item in a retail store’s inventory.
*/
#include <iostream>
using namespace std;
#include <iomanip>
#include "Inventory.h"
#define NEGmessageDefined "No negative numbers allowed"
#define LINEdefined "________________________________"

bool negativeTestBool(int);
bool negativeTestBool(double);

int main(){
    Inventory invItem; // defining a class object
    char again = 'y';
    double doubleInput;
    int intInput;
    
    do { // main DO WHILE that resets the program upon request
        do { // gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter item number: ";
            cin >> intInput;
            if (negativeTestBool(intInput)) cout << NEGmessageDefined << endl;
        }while (negativeTestBool(intInput));
        invItem.setItemNumber(intInput);
        do { // gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter item quantity: ";
            cin >> intInput;
            if (negativeTestBool(intInput)) cout << NEGmessageDefined << endl;
        }while (negativeTestBool(intInput));
        invItem.setQuantity(intInput);
        do { // gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter item price: ";
            cin >> doubleInput;
            if (negativeTestBool(doubleInput)) cout << NEGmessageDefined << endl;
        }while (negativeTestBool(doubleInput));
        invItem.setCost(doubleInput);
        invItem.setTotalCost();
        // displaying the collected and calculated inputs to the user.
        cout << LINEdefined << endl;
        cout << " Item Number:\t" << invItem.getItemNumber() << endl;
        cout << " Item Quantity:\t"  << invItem.getQuantity()<< endl;
        cout << " Item Price:\t" << fixed << setprecision(2) <<  invItem.getCost()<< endl;
        cout << " Total Cost:\t" << fixed << setprecision(2) << invItem.getTotalCost()<< endl;
        cout << LINEdefined << endl;
        cout << "Another one? Y or N" << endl;
        cin.ignore();
        cin >> again;
    }
    while (again == 'y' || again == 'Y' ); // in case of Y or y input, will repreat the program.
    return 0;
}

// boolian function that returns true or false, by testing if the input was negative or not.
bool negativeTestBool(int input) { return (input < 0); }
bool negativeTestBool(double input) { return (input < 0); }