#include <iostream>
#include <iomanip>
#include <string>
#define SIZE 5

using namespace std;

struct drink{
    string name;
    float price;
    int quantity;
}drinks[SIZE] = { 
    {"Cola          ", 1.00, 20}, 
    {"Root beer     ", 1.00, 20},
    {"Orange soda   ", 1.00, 20},
    {"Grape soda    ", 1.50, 20},
    {"Bottled water ", 1.50, 20}
};

class Machine {
    // float total;
    // float change;
    public:
    void moneyInput();
    void drinkMenu();
};

int main (){
    Machine machine;
    machine.drinkMenu();
    return 0;
}

void Machine::moneyInput(){

};
void Machine::drinkMenu(){
    cout << "\n\tDrink Menu\n" ;
    for (int i = 0 ; i < SIZE ; i++){
        cout << i+1 << ". " << drinks[i].name << " $" << fixed << setprecision(2) << drinks[i].price << endl;
    }
    cout << "6. " << "Exit" << endl << 
    "Select your drink: ";
}