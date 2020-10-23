// Adib Fazli
// 10/14/2020
/* Description: 
        Modify the DayOfYear class, written in an earlier Programming Challenge, to add a
        constructor that takes two parameters: a string representing a month and an integer in the
        range 0 through 31 representing the day of the month. The constructor should then initialize
        the integer member of the class to represent the day speciﬁed by the month and day of month
        parameters. The constructor should terminate the program with an appropriate error
        message if the number entered for a day is outside the range of days for the month given.
        Add the following overloaded operators:
        ++ preﬁx and postﬁx increment operators. These operators should modify the DayOfYear
        object so that it represents the next day. If the day is already the end of the year, the
        new value of the object will represent the ﬁrst day of the year.
        --  preﬁx and postﬁx decrement operators. These operators should modify the DayOfYear
        object so that it represents the previous day. If the day is already the ﬁrst day of the
        year, the new value of the object will represent the last day of the year. 
*/
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;

// creating the class DayOf Year
class DayOfYear {
  // private members of the class
  private:
    int day;
    int dayOfYear;
    int dayOfMonth;
    string nameOfMonth;
  public:
    // setting month names helper function
    string monthNames(int month_number) {
      string monthNames[] = {"January", "February", "March", 
                              "April", "May", "June", 
                              "July", "August", "September", 
                              "October", "November", "December"};
      return monthNames[month_number];
    }

    // setting month days helper function
    int monthDays(int month_number) {
      int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      return monthDays[month_number];
    }

    // Constructor
    DayOfYear(int day) {
      dayOfYear = day;
      dayOfMonth = dayOfYear;
      int i = 0;
      while (1) {
        if (dayOfMonth <= monthDays(i)) {
          nameOfMonth = monthNames(i);
          break;
        } else {
          dayOfMonth = dayOfMonth - monthDays(i++);
          i = i % 12;
        }
      }
    }

    // print function
    void print() { 
      cout << nameOfMonth << " " << dayOfMonth << endl;
    } 
};

int main() {
  int day;
  cout << "This program converts a day given by a number 1 through 365 \ninto a month and a day." << endl;
  cout << "Enter a number: ";
  cin >> day;
  DayOfYear dayOfYear = DayOfYear(day);
  dayOfYear.print();
  return 0;
}