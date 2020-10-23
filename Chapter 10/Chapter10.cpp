// Adib Fazli
// 10/14/2020
/* 
  Description: 
        Write a program that dynamically allocates an array large enough to hold a user-defined number of test scores. 
        Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. 
        Another function should be called that calculates the average score. The program should display the sorted list of 
        scores and averages wtih appropiate headings. Use pointer notation rather than array notation whenever possible. 
        Input validation: Do not accept negative numbers for test scores. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

void selectionSortAsc(double *, int);
double arrayAverage(double *, int);

int main(){
  // Define variables
  double *TestScores, total = 0.0, average;
  int numTest, count;

  //Get the number of test scores from user
  cout << "How many test scores do you wish to enter? ";
  cin >> numTest;

  // allocate an array
  TestScores = new double[numTest];

  //Get the test scores
  cout << "Enter the test scores below.\n";
  for (count = 0; count < numTest; count++) {
    cout << "Test Score " << (count + 1) << ": ";
    cin >> TestScores[count];

    // Input validation to get the numbers between 0 to 100
    while (TestScores[count] < 0 || TestScores[count] > 100) {
      cout << "You must enter a scores that non-negative" << endl;
      cout << "Please enter again: ";
      cin >> TestScores[count];
    }
  }

  //Dsiplay the results
  selectionSortAsc(TestScores, numTest);
  average = arrayAverage(TestScores, numTest);
  cout << fixed << showpoint << setprecision(2);
  cout << "The test scores, sorted in ascending order, are: \n";
  for (count = 0; count < numTest; count++) {
    cout << TestScores[count] << " ";
  }
  cout << endl;
  cout << "The average of all the test score is " << average << endl;

  //Free dynamically allocated memory & make TestScores point to null
  delete [] TestScores;
  TestScores = 0;
  system ("pause");
  return 0;
}

// Ascending order selection sort
void selectionSortAsc(double *arr, int size) {
  int startScan;
  int minIndex;
  double minElem;
  for(startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minElem = arr[startScan];
    for(int index = startScan; index < size; index++) {
      if (arr[index] < minElem) {
        minElem = arr[index];
        minIndex = index;
      }
    }
    if(minIndex!=startScan) {
      double temp = arr[minIndex];
      arr[minIndex] = arr[startScan];
      arr[startScan] = temp;
    }
  }
}

// getting average of the values of the array
double arrayAverage (double *arr, int size) {
  double total = 0, average;
  int numTest;
  for (int count = 0; count < size; count++) {
    total += arr[count];
  }
  average = total / size;
  return average;
}