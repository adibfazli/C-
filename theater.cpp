/*
    ADIB FAZLI
    09/08/2020
    This program calculates a theater’s gross and net box ofﬁce proﬁt for a night.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Pre defining 2 function to the program.
void inputFunc(string & , int & , int &);
void calculator ( int , int , float & , float & , float &);

int main (){
    // Declaring all the variables with data types.
    string movieName;
    int adultTicket, childTicket;
    float grossProfit, netProfit, distrubutorCut;

    // Calling the functions and giving them the needed variables and values to perform the input action or calculation.
    inputFunc(movieName , adultTicket , childTicket);
    calculator(adultTicket , childTicket , grossProfit , netProfit , distrubutorCut);
    // A simple output for the user with all the calculated variables.
    cout << fixed << setprecision(2) << 
        "Movie Name:                " << setw(7) << "\""<< movieName << "\"" << endl << 
        "Adult Tickets Sold:        " << setw(9) << adultTicket << endl <<  
        "Child Tickets Sold:        " << setw(9) << childTicket << endl << 
        "Gross Box Ofﬁce Proﬁt:     " << setw(7) << "$"   << grossProfit << endl << 
        "Amount Paid to Distributor:" << setw(7) << "- $" << distrubutorCut   << endl << 
        "Net Box Ofﬁce Proﬁt:       " << setw(7) << "$"   << netProfit << endl;
    return 0;
}

// this void function gets the empty variables and updates the their value without returning anything.
void inputFunc(string & movieName , int & adultTicket , int & childTicket){
    cout << "enter the name of the movie: "<< endl;
    getline(cin , movieName);
    cout << "enter adult ticket count: "<< endl;
    cin >> adultTicket;
    cout << "enter kids ticket count: "<< endl;
    cin >> childTicket;
}

// this function will do all the calculation and updates the variables without a return.
void calculator (int adultTicket , int childTicket , float & grossProfit , float & netprofit , float & distrubutorCut){
    grossProfit = (adultTicket * 6) + (childTicket * 3);
    distrubutorCut = grossProfit * 0.8;
    netprofit = grossProfit - distrubutorCut;
}