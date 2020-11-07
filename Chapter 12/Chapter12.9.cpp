// Adib fazli
// 10/23/2020
// Description: Write a program with three functions: upper, lower, and flip. The upper function should accept a C-string as an argument. 
//              It should step through all the characters in the string, converting each to uppercase. The lower function, too, should accept
//              a pointer to a C-string as an argument. It should step through all the characters in the string, converting each to lowercase. 
//              Like upper and lower, flip should also accept a C-string. As it steps through the string, it should test each character to 
//              determine whether it is upper- or lowercase. If a character is uppercase, it should be converted to lowercase. If a character is
//              lowercase, it should be converted to uppercase. Test the functions by asking for a string in function main, then passing it to 
//              them in the following order: flip, lower, and upper.

#include <iostream>
using namespace std;

#include <iostream>
#include <string>
#include <cctype>
#include <string.h>
using namespace std;
#define SIZE 80

// Function prototypes
void upper(char[]);
void lower(char[]);
void flip(char[]);

int main() {
  // Three character arrays
  char upperCaseArr[SIZE], lowerCaseArr[SIZE], flippedArr[SIZE];
  // Get a string
  cout << "Enter a string: ";
  cin.getline(upperCaseArr, SIZE);

  // Copy the string to lowerCaseArr and flippedArr.
  strcpy_s(lowerCaseArr, upperCaseArr);
  strcpy_s(flippedArr, upperCaseArr);

  // flip the case in flippedArr.
  cout << '\n' << "Flip  : ";
  flip(flippedArr);
  cout << flippedArr << endl;

  // Change lowerCaseArr to lowercase.
  cout << "Lower : ";
  lower(lowerCaseArr);
  cout << lowerCaseArr << endl;

  // Change upperCaseArr to uppercase.
  cout << "Upper : ";
  upper(upperCaseArr);
  cout << upperCaseArr << '\n' << endl;

  return 0;
}
// Function reverse 
// This function steps through each character in the str parameter array, converting each 
// uppercase character to lowercase, and each lowercase character to uppercase. 
void flip (char str[]){
  for (int i = 0 ; i < strlen(str) ; i++)
    islower(str[i]) ? str[i] = toupper(str[i]) : str[i] = tolower(str[i]); 
}
// Function upper *
// this function converts each character in the str parameter array to uppercase. 
void upper (char str[]){
  for (int i = 0 ; i < strlen(str) ; i++) str[i] = toupper(str[i]);
}
// Function lower *
// this function converts each character in the str parameter array to lowercase.
void lower (char str[]){
  for (int i = 0 ; i < strlen(str) ; i++) str[i] = tolower(str[i]);
}