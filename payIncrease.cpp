/*
    ADIB FAZLI
    09/16/2020
    This program reads employee data from the specified file,
    and calculates their raise based on the given data, 
    and stores the output in a new file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Declaration of the structure
struct employee{
    string familyName;
    string givenName;
    float salary;
    float raise;
}employees[100] , updatedEmployees[100];

// pre defining the functions.
void readFile(int &);
void storeNewData(int);
void writeFile(int);

// main function.
int main (){
    int size = 0;
    readFile(size);
    storeNewData(size);
    writeFile(size);
    return 0;
}

// reading all the content from the given file and storing it in an array.
void readFile(int &size){
    ifstream infile;
    infile.open("employeeSalary.txt");
    if (!infile){ 
        cout<< "Cannot open the file.";
        cout<< " Terminating the program!" << endl;
        exit(0);
    }else{
        cout << "\nFile found!" << endl;
    }
    int i = 0;
    // Iterating over the given file and storing it in an array.
    while (!infile.eof()){
        infile >> employees[i].familyName;
        infile >> employees[i].givenName;
        infile >> employees[i].salary;
        infile >> employees[i].raise;
        i++;
    }
    infile.close();
    size = i;
}

// storing the updated information in a brand new array in order to have access to old and new info.
void storeNewData(int size){
    // Iterating over the array that stores the info and storing the updated info in a new array.
    for (int i=0 ; i < size ; i++){
        updatedEmployees[i].familyName = employees[i].familyName;
        updatedEmployees[i].givenName = employees[i].givenName;
        updatedEmployees[i].salary = employees[i].salary + (employees[i].salary / 100 * employees[i].raise);
    }
}

// writing the updated information into a .txt file, out of the compiler.
void writeFile(int size){
    ofstream outfile;
    outfile.open("employeeOutSalary.txt");
    for ( int i = 0 ; i < size ; i++){
        outfile << "\n" ;
        outfile << updatedEmployees[i].givenName << "\t" << updatedEmployees[i].familyName << "\t" << updatedEmployees[i].salary << endl;
    }
    cout << "\n Successfully updated! " << endl;
}