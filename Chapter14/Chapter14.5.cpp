/*
    description: Recursive Multiplication
    Write a recursive function that accepts two arguments into the parameters x and y. The
    function should return the value of x times y. Remember, multiplication can be performed
    as repeated addition:
    7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4
*/
#include <iostream>
using namespace std;

int multiplication(int x, int y);

int main() {
	int x, y;
	cout << "Please enter two number separated by a space:" << endl;
	cin  >> x >> y;
	cout << x << " * " << y << " = " << multiplication(x, y) << endl;
  
	return 0;
}

int multiplication(int x, int y) {
	if (x > 1) 	
		return y + multiplication(--x, y);
	else
		return y;
}