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
#include <fstream>
using namespace std;

int main() {
  string buffer;
  char filename[80];
  int i;
  ofstream outputFile;
  ifstream inputFile;
  bool first = true;

  cout << "Enter name of your input file: ";
  cin >> filename;
  inputFile.open(filename);   

  if(inputFile.fail()) { 
    // print error message
    cout << "input file did not open please make sure you have the correct file name." << endl;
    system("pause");
    return 1;
  }

  cout << "Enter name of your output file: ";
  cin >> filename;
  outputFile.open(filename);          
  getline(inputFile,buffer);

  while(inputFile) {
    for(i = 0; buffer[i] != '\0' ; i++) { 
      if(isalpha(buffer[i]))
        // if the char is alphabet and first is true it means it's the first word of the line so change the first letter to uppercase
        if(first) {
          first=false;
          buffer[i] = toupper(buffer[i]);
        } else // else change everything to lower
          buffer[i] = tolower(buffer[i]);        
        else if( buffer[i] == '.' ) // else if the char is a period then change first boolean to true and get to next line
          first = true;
    }
      outputFile << buffer << endl;
      getline(inputFile,buffer);
  }

  // closing files
  outputFile.close();
  inputFile.close();
  return 0;
}