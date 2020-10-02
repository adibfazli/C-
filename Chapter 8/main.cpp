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
    {"Cola          ", 1.00, 0}, 
    {"Root beer     ", 1.00, 20},
    {"Orange soda   ", 1.00, 20},
    {"Grape soda    ", 1.50, 20},
    {"Bottled water ", 1.50, 20}
};

class Machine {
    float total , change , balance , addToBalance , totalSale;
    int choice;
    char purchaseConfirmation;
    public:
    void moneyInput();
    void drinkMenu();
    void transaction();
    void dailyReport();
    bool choiceValidation();
    bool moneyInputValidation();
    bool quantityCheck();
    ~Machine() { 
      dailyReport();
    }
};

int main (){
    Machine machine;
    machine.drinkMenu();
    return 0;
}

void Machine::drinkMenu(){
    cout << "\n\tDrink Menu\n";
    for (int i = 0 ; i < SIZE ; i++){
        cout << i+1 << ". " << drinks[i].name << " $" << fixed << setprecision(2) << drinks[i].price << endl;
    }
    cout << "6. " << "Exit" << endl << "Select your drink: ";
    cin >> choice;
    choice -= 1;
    while (!(choice == 5) && (choiceValidation() || quantityCheck())){
        if (choiceValidation()) cout << "Please make a valid selection."<< endl;
        else cout << "\nSorry! we are out of " << drinks[choice].name << endl <<
        "Please make another selection or select 6 for exit. Thank you" << endl;
        cin >> choice;
        choice -= 1;
    };
    if (!(choice == 5)) moneyInput();
    else cout << "have a good day!" << endl;
}

void Machine::moneyInput(){
    cout << "Enter the amount of money you wish to insert: ";
    cin >> balance;
    while (balance < drinks[choice].price){
        cout << "Not enough balance for " << drinks[choice].name << endl<<
            "Atleast add $"<< fixed << setprecision(2) << drinks[choice].price - balance << " to Your balance." << endl;
            cin >> addToBalance;
            balance += addToBalance;
    }
    transaction();
};

void Machine::transaction(){
    cout << "do you wish to complete your transaction? (Y / N)" << endl;
    cin >>  purchaseConfirmation;
    switch (purchaseConfirmation){
    case 'Y': case 'y':
    totalSale += drinks[choice].price;
        drinks[choice].quantity--;
        change = balance - drinks[choice].price;
        cout << "Enjoy your " << drinks[choice].name << endl<< "your change is: " << change << endl;
        break;
    case 'N': case 'n':
        cout << "Thank you for nothing, and here is your money: " << balance << endl;
        break;
    default:
        cout << "\n invalid Input! " << endl;
        Machine::transaction();
        break;
    }
}

void Machine::dailyReport(){
    cout << "\nDrink Machine Daily Report\n";
    for(int i = 0; i < 5; i++)
        cout << drinks[i].name <<": " << drinks[i].quantity<<endl;
}

bool Machine::quantityCheck(){ return (drinks[choice].quantity < 1); }
bool Machine::choiceValidation(){ return (choice > 5 || choice < 0); }
bool Machine::moneyInputValidation(){ return (balance < 1); }