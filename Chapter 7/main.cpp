// Adib Fazli
#include <iostream>
using namespace std;
#include <iomanip>
#include "Inventory.h"
#define NEGERROR "No negative numbers allowed"
#define LINE "________________________________"

bool isNeg(int);
bool isNeg(double);

int main(){
    Inventory invItem;
    char again = 'y';
    double doubleInput;
    int intInput;
    do {
        do {
            cout << "Enter item number: ";
            cin >> intInput;
            if (isNeg(intInput)) cout << NEGERROR << endl;
        }while (isNeg(intInput));
        invItem.setItemNumber(intInput);
        do {
            cout << "Enter item quantity: ";
            cin >> intInput;
            if (isNeg(intInput)) cout << NEGERROR << endl;
        }while (isNeg(intInput));
        invItem.setQuantity(intInput);
        do {
            cout << "Enter item price: ";
            cin >> doubleInput;
            if (isNeg(doubleInput)) cout << NEGERROR << endl;
        }while (isNeg(doubleInput));
        invItem.setCost(doubleInput);
        invItem.setTotalCost();
        cout << LINE << endl;
        cout << " Item Number:\t" << invItem.getItemNumber() << endl;
        cout << " Item Quantity:\t"  << invItem.getQuantity()<< endl;
        cout << " Item Price:\t" << fixed << setprecision(2) <<  invItem.getCost()<< endl;
        cout << " Total Cost:\t" << fixed << setprecision(2) << invItem.getTotalCost()<< endl;
        cout << LINE << endl;
        cout << "Another one? Y or N" << endl;
        cin.ignore();
        cin >> again;
    }
    while (again == 'y' || again == 'Y' );
    return 0;
}

bool isNeg(int input) { return (input < 0); }
bool isNeg(double input) { return (input < 0); }