// Adib Fazli
// Date: 10/31/2020
//  The letter e is the most frequently used letter in English prose, 
//  and the letter z is the least frequently used. A friend of yours doing a 
//  sociology experiment believes that this may not necessarily be true of the 
//  writings of first-year college students. To test his theory, he asks you to 
//  write a program that will take a text  file and print, for each letter of the 
//  English alphabet, the number of times the letter appears in the  file. Hint: 
//  Use an integer array of size 128, and use the ASCII values of letters to index 
//  into the array to store and retrieve counts for the letters.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string fileName;
  int a[128];
  char ch;
  char alphabets[26] = {'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o',
                        'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y', 
                        'z'};
  fstream inputFile;

  cout << "Please enter your file name: ";
  cin >> fileName;
  inputFile.open(fileName, ios::in);

  for (int i = 0; i < 128; i++) 
    // placing numbers in their correct position in array a
    a[i] = 0;
  

  while (!inputFile.eof()) {
    inputFile.get(ch);
    // converting each char to an ASCII number and increment the number of that specific ASCII number index in the array of a
    a[int(ch)] = a[(int)ch] + 1;
  }

  for (int i = 97, j=0; i <= 122; i++, j++)
    cout << "Frequency of the letter " << alphabets[j] << ": " << a[i] << endl;
  
  return 0;
}