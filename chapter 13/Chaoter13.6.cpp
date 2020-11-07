// Adib Fazli
// Date: 10/31/2020
//  A program that processes an input file and produces an output file is called 
//      a filter. Write a program that asks the user for two file names. The first file will be 
//      opened for input and the second file will be opened for output. (It will be assumed that 
//      the first file contains sentences that end with a period.) The program will read the contents 
//      of the first file and change all the letters other than the first letter of sentences to lowercase. 
//      First letter of sentences should be made uppercase. The revised contents should be stored in the second file.
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string temp;
    char fileName[100];
    ifstream inFile;
    ofstream outFile;
    bool firstWord = true;
    // using while loop to make sure the input file is valid, if not reenter.
    while (1 && fileName[0] !='Q' && fileName[0] !='q'){
        cout << "Enter a file name OR \"Q\" for quit: "; cin >> fileName;
        inFile.open(fileName);
        if (fileName[0] =='Q' || fileName[0] =='q') system("pause");
        else if(inFile.fail()) cout << "Invalid file name, try again OR enter \"Q\" for quit. "<< endl;
        else break;
    }
    // using while loop to make sure the output file is valid, if not reenter.
    while (1 && fileName[0] !='Q' && fileName[0] !='q'){
        cout << "Enter a output file name OR \"Q\" for quit: "; cin >> fileName;
        outFile.open(fileName);
        if (fileName[0] =='Q' || fileName[0] =='q') system("pause");
        else if(outFile.fail()) cout << "Invalid file name, try again OR enter \"Q\" for quit. "<< endl;
        else break;
    }
    getline(inFile,temp); // getting the entire line.
    while(inFile) {
        for(int i = 0; temp[i] != '\0' ; i++) { 
            if(isalpha(temp[i])){ // ( if ) the char is alphabet.
                if(firstWord) { // ( if ) first is true it means it's the first word of the line so change the first letter to uppercase
                firstWord=false;
                temp[i] = toupper(temp[i]);
                } else temp[i] = tolower(temp[i]); // ( else ) change everything to lower
            }else if( temp[i] == '.' ) firstWord = true; // ( else if ) the char is a period then change first boolean to true and get to next line
        }
        outFile << temp << endl;
        getline(inFile,temp);
  }
  outFile.close(); // closing outFile file
  inFile.close(); // closing inFile file
  return 0;
}