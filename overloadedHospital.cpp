/*
    ADIB FAZLI
    09/25/2020
    This program computes and displays the charges for a patient’s hospital stay. 
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define LINEdefined "________________________________"

class Hospital{
    // private members of the class
    int inputValidationBool; 
    char patient;
    double daysInHospital, HospitalServices , dailyRate , medicationCharges;
    public: // public members of the class
        void patientTypeInput ();
        void serviceInput( char patientType);
        void inputValidation (double);
        void patientExpenseCalculator (double, double, double, double);
        void patientExpenseCalculator (double, double);
};

int main (){
    Hospital storage;
    storage.patientTypeInput();
    return 0;
}

void Hospital::patientTypeInput(){ // asking the user to especify if the user is in-patient.
    cout << "Is the patient in-patient? Y/N" << endl;
    cin >> patient;
    Hospital::serviceInput ( patient );
}

void Hospital::serviceInput ( char patientType){ //  taking the inputs based on uer inputs (in-patient or out-patient) by using switch.
    switch (patientType){
        // inn Y or y condition the program will take in-patient inputs
    case 'Y': case 'y':
        do{ 
            cout << "Enter the number of days spent in the hospital: " << endl;
            cin >> daysInHospital;
            Hospital::inputValidation (daysInHospital);
        }while(inputValidationBool);
        do{ // DO WHILE gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter the daily rate: " << endl;
            cin >> dailyRate;
            Hospital::inputValidation (dailyRate);
        }while(inputValidationBool);
        do{ // DO WHILE gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter charges for hospital services: " << endl;
            cin >> HospitalServices;
            Hospital::inputValidation (HospitalServices);
        }while(inputValidationBool);
        do{ // DO WHILE gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter hospital medication charges: " << endl;
            cin >> medicationCharges;
            Hospital::inputValidation (medicationCharges);
        }while(inputValidationBool);
        Hospital::patientExpenseCalculator(daysInHospital, dailyRate, HospitalServices, medicationCharges);
        break;
    default: // in any other condition than Y or y, the program will consider the patient out-patient.
        do{ // DO WHILE gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter charges for hospital services: " << endl;
            cin >> HospitalServices;
            Hospital::inputValidation (HospitalServices);
        }while(inputValidationBool);
        do{ // DO WHILE gets > 0 input from use. if the condition is not satisfied, will ask again for input.
            cout << "Enter hospital medication charges: " << endl;
            cin >> medicationCharges;
            Hospital::inputValidation (medicationCharges);
        }while(inputValidationBool);
        Hospital::patientExpenseCalculator(HospitalServices, medicationCharges);
        break;
    }
}

void Hospital::inputValidation (double evt){ // this function validates the input (input can not be (-)).
    if ( cin.fail() || !(evt > 0) ) {
        cin.clear();
        cin.ignore(200, '\n');
        inputValidationBool = 1;
    }else inputValidationBool = 0;
}
// overloaded function which calculates the user input
void Hospital::patientExpenseCalculator(double daysInHospital, double dailyRate, double HospitalServices, double medicationCharges){
    cout << LINEdefined << endl <<
        daysInHospital << " days in hospital cost: $" << fixed << setprecision(2) << daysInHospital * dailyRate << endl <<
        "hospital service (lab tests, etc.): $" << HospitalServices << endl << 
        "medication charges: $" << medicationCharges << endl <<
        "total: $" << (daysInHospital * dailyRate) + HospitalServices + medicationCharges << endl <<
        LINEdefined << endl;
}
// overloaded function which calculates the user input
void Hospital::patientExpenseCalculator(double HospitalServices, double medicationCharges){
    cout << LINEdefined << endl <<
        "hospital service (lab tests, etc.): $"<< fixed << setprecision(2) << HospitalServices << endl << 
        "medication charges: $" << medicationCharges << endl <<
        "Total: $" << HospitalServices + medicationCharges << endl <<
        LINEdefined << endl;
}