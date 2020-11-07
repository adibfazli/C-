/* 
   description: Convert the following function to one that uses recursion.
    void sign (int n) {
      while (n > 0)
      cout << “No Parking\n”;
      n--;
    }
   Demonstrate the function with a driver program. */

#include<iostream>
using namespace std;

void sign( int n );

int main(){
  int num;
  cout << "Enter number: ";
  cin >> num;
  sign( num );
  
  return 0;
}


void sign(int n) {
  if ( n > 0 ) {
      cout << "No Parking" << endl;
      sign( n - 1 );
  }
}