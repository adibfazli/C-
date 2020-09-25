#include <iostream>
#include <string>
using namespace std;

class Hospital{
    int daysInHospital; 
    string patient;
    double HospitalServices , dailyRate , medicationCharges;
    public:
        void patientTypeInput ();
        void serviceInput();
        void inputValidation ();
        void InPatient ();
        void outPatient ();
};

int main (){
    Hospital storage;
    storage.patientTypeInput();
    return 0;
}
    
void Hospital::serviceInput (){

}
void Hospital::inputValidation (){

}

void Hospital::patientTypeInput(){
    cout << "Is the patient in-patient? Y/N";
    cin >> patient;
}
void Hospital::InPatient(){

}
void Hospital::outPatient(){

}