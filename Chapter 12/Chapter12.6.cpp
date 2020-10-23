// Adib Fazli
// 10/23/2020
// Description: Write a program that asks the user to enter a series of single-digit numbers with nothing separating them. 
//              Read the input as a C-strings or a strings object. The program should display the sum of all the single-digit 
//              numbers in the strings. For example, if the user enters 2514, the program should display 12, which is the sum 
//              of 2, 5, 1, and 4. The program should also display the highest and lowest digits in the strings.
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
  // Variable declaration
  char strings[15];
  int number, sum = 0, i, smallest, largest;
  cout << "Please enter series single-digit number with nothing seperating them: "<< endl;
  cin.getline( strings, 15, '\n');
  // Converting series of strings to Integer
  number = atoi(strings);
  i = number % 10;
  largest = i;
  smallest = i;
  //Logic in Loop for getting sum of digits and smallest and largest numbers
  while(number>0) {  
    i = number % 10;
    cout << "# :" << number << "   i: " << i << "   S: " << smallest<< "   L: " << largest << endl;
    if ( smallest > i) // If statement for getting smallest digit
      smallest = i;
    if ( largest < i) //If statement for getting largest digit
      largest = i; 

    sum = sum + i;
    number = number / 10;
  }
  // Outputting sum of Digits of a number
  cout << "Sum of digits is: " << sum << endl;
  // Outputting largestst and smallestest digits
  cout << "largestst number is : " << largest << endl;
  cout << "smallestest number is: " << smallest << endl;
  return 0;
}