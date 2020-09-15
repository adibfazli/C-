/*
    ADIB FAZLI
    09/16/2020
    This program prompts the user to enter the cost of renting one room, 
    the number of rooms booked, the program outputs the cost of renting one room, 
    the discount on each room as a percent, the number of rooms booked, 
    the number of days the rooms are booked, the total cost of the rooms, 
    the sales tax, and the total billing  amount.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// A class that stores the variables and functions.
class InputValues{
    int roomCount , dayCount , salesTaxPercentage , loop , discount;
    float roomPrice , costOfARooom , costOfAllRooms , TotalSalesTax;
    void inputChecker(){
        // this function checks the data type of the user input.
        if (cin.fail()) {
            cin.clear();
            cin.ignore(200, '\n');
            loop = 1;
        }else loop = 0;
    }
    public:
        void userInputForm(){
            // user input form with a do while loop that will repeat if the use input and data type does not match.
            do{
                cout << "Enter Number of Rooms: " << endl;
                cin >> roomCount;
                inputChecker();
            }while(loop);
            do{
                cout << "Enter Number of days:  " << endl;
                cin >> dayCount;
                inputChecker();
            }while(loop);
            do{
                cout << "Enter Cost of a Room:  " << endl;
                cin >> roomPrice;
                inputChecker();
            }while(loop);
            do{
                cout << "Enter Sales Tax %:     " << endl;
                cin >> salesTaxPercentage;
                inputChecker();
            }while(loop);
        }
        void calculator(){
            // this function does all the calculation of data that we need to output for the user.
            roomCount >= 30 ? discount = 30 : roomCount >= 20 ? discount = 20 : roomCount >= 10 ? discount = 10 : discount = 0;
            dayCount >= 3 ? discount += 5 : 0;
            costOfARooom = roomPrice - (roomPrice / 100 * discount);
            costOfAllRooms = costOfARooom * roomCount;
            TotalSalesTax = costOfAllRooms / 100 * salesTaxPercentage;
        }
        void display(){ 
            // this function outputs all the calculated data.
            cout << "________________________________" <<endl << fixed << setprecision(2) <<
            "| Cost of a Room:        $" << costOfARooom <<endl <<
            "| Discount on each room:  " << discount << "%" <<endl <<
            "| Number of rooms booked: " << roomCount  <<endl <<
            "| Number of days booked:  " << dayCount  <<endl <<
            "| Total cost of rooms:    $" << costOfAllRooms <<endl <<
            "| Sales Tax:              $" << TotalSalesTax <<endl <<
            "| Total billing amount:   $" << costOfAllRooms + TotalSalesTax <<endl;
        }
};

// main function
int main(){
    InputValues userInput;
    userInput.userInputForm();
    userInput.calculator();
    userInput.display();
    return 0;
}