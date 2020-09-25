#include <iostream>
#include <string>
using namespace std;
#define NEGERROR "No negative numbers allowed"
#define LINE "________________________________"

class Hospital{
    int inputValidationBool; 
    char patient;
    double daysInHospital, HospitalServices , dailyRate , medicationCharges;
    public:
        void patientTypeInput ();
        void serviceInput( char patientType);
        void inputValidation (double);
        void InPatient (double, double, double, double);
        void outPatient (double, double);
};

int main (){
    Hospital storage;
    storage.patientTypeInput();
    return 0;
}

void Hospital::patientTypeInput(){
    cout << "Is the patient in-patient? Y/N" << endl;
    cin >> patient;
    Hospital::serviceInput ( patient );
}

void Hospital::serviceInput ( char patientType){
    switch (patientType){
    case 'Y': case 'y':
        do{
            cout << "Enter the number of days spent in the hospital: " << endl;
            cin >> daysInHospital;
            Hospital::inputValidation (daysInHospital);
        }while(inputValidationBool);
        do{
            cout << "Enter the daily rate: " << endl;
            cin >> dailyRate;
            Hospital::inputValidation (dailyRate);
        }while(inputValidationBool);
        do{
            cout << "Enter charges for hospital services: " << endl;
            cin >> HospitalServices;
            Hospital::inputValidation (HospitalServices);
        }while(inputValidationBool);
        do{
            cout << "Enter hospital medication charges: " << endl;
            cin >> medicationCharges;
            Hospital::inputValidation (medicationCharges);
        }while(inputValidationBool);
        Hospital::InPatient(daysInHospital, dailyRate, HospitalServices, medicationCharges);
        break;
    default:
        do{
            cout << "Enter charges for hospital services: " << endl;
            cin >> HospitalServices;
            Hospital::inputValidation (HospitalServices);
        }while(inputValidationBool);
        do{
            cout << "Enter hospital medication charges: " << endl;
            cin >> medicationCharges;
            Hospital::inputValidation (medicationCharges);
        }while(inputValidationBool);
        Hospital::outPatient(HospitalServices, medicationCharges);
        break;
    }
}

void Hospital::inputValidation (double evt){
    if ( cin.fail() || !(evt > 0) ) {
        cin.clear();
        cin.ignore(200, '\n');
        inputValidationBool = 1;
    }else inputValidationBool = 0;
}

void Hospital::InPatient(double daysInHospital, double dailyRate, double HospitalServices, double medicationCharges){
    cout << LINE << endl <<
        daysInHospital << " days in hospital: " << daysInHospital * dailyRate << endl <<
        "hospital service: " << HospitalServices << endl << 
        "medication charges: " << medicationCharges << endl <<
        "total: " << (daysInHospital * dailyRate) + HospitalServices + medicationCharges << endl <<
        LINE << endl;
}

void Hospital::outPatient(double HospitalServices, double medicationCharges){
    cout << "__________________________" << endl <<
        "hospital service: " << HospitalServices << endl << 
        "medication charges: " << medicationCharges << endl <<
        "Total: " << HospitalServices + medicationCharges << endl <<
        "__________________________" << endl;
}