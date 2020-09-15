/*
    ADIB FAZLI
    09/08/2020
    This is program that calculates user expenditure based on predefined costs.
    User can enter the hours worked and rate of pay, and the program generates:
        Income before tax, Income after tax, cost of clothes & accessories,
        school Supply, and Saving bonds
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This class contains all the functions 
// in which all the calculation happens,
// and limits the access of it's components to it's sub components only ( other than public ones )
class Calculator{
    float
        incomeBeforeTax,
        incomeAfterTax,
        clothesAndAcc,
        schoolSup,
        savingBonds,
        parentSavingBonds;
    void incomeCalculator (float rate , float hours){
        incomeBeforeTax = rate * hours;
        incomeAfterTax = incomeBeforeTax - (incomeBeforeTax * 0.14);
    }
    void clothesAndAccCalculator (){
        clothesAndAcc = incomeBeforeTax * 0.10;
    }
    void schoolSupCalculator (){
        schoolSup = incomeBeforeTax * 0.01;
    }
    void savingBondsCalculator (){
        savingBonds = (incomeAfterTax - (clothesAndAcc + schoolSup)) * 0.25 ;
        parentSavingBonds = savingBonds / 2;
    }
    //public components
    public:
        void RateAndHours(){
            float rate , hours;
            // performing a small debugging with do while loop
            // to make sure user enters positive numbers
            do{
                cout << "How much is your hourly rate? ";
                cin >> rate;
                cout << "How many hours you worked? ";
                cin >> hours;
                if ( cin.fail() ) {
                    cin.clear();
                    cin.ignore(200, '\n');
                }else if(rate > 0 && hours > 0) break;
                cout << endl << "invalid input, Try again!" << endl
                << "( input must be # and greater than 0 )" << endl << endl;
                rate = hours = 0;
            } while(1);
            // calling the functions one by one to calculate outputs based on the input
            incomeCalculator(rate , hours);
            clothesAndAccCalculator();
            schoolSupCalculator ();
            savingBondsCalculator ();
        }
        // out put function, displays the calculated information with 2 decimal places
        void getOutput(){
            cout << "____________________________________________" <<endl << fixed << setprecision(2) <<
                "Income Before Tax:            " << setw(7) << "$" << incomeBeforeTax   << endl <<
                "Income After Tax:             " << setw(7) << "$" << incomeAfterTax    << endl <<
                "Spend on Clothes:             " << setw(7) << "$" << clothesAndAcc     << endl <<
                "School Sup:                   " << setw(7) << "$" << schoolSup         << endl << 
                "spend on Saving Bonds:        " << setw(7) << "$" << savingBonds       << endl <<
                "Parents spend on Saving bonds:" << setw(7) << "$" << parentSavingBonds << endl << 
                "____________________________________________"<< endl;
        }
};

int main(){
    Calculator calculation;
    // initiating the calculation process
    cout << "*** Welcome to Summer Job Calculator ***" << endl;
    calculation.RateAndHours();
    // calling the display function
    calculation.getOutput();
    return 0;
}