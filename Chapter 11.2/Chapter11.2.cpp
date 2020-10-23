// Adib Fazli
// 10/14/2020
/* Description: 
        Assuming that a year has 365 days, write a class named DayOfYear that takes an integer
        representing a day of the year and translates it to a string consisting of the month followed
        by day of the month. For example,
        Day 2 would be January 2
        Day 32 would be February 1
        Day 365 would be December 31.
        The constructor for the class should take as parameter an integer representing the day of
        the year, and the class should have a member function print() that prints the day in the
        month-day format. The class should have an integer member variable to represent the day
        and should have static member variables of type string to assist in the translation from
        the integer format to the month–day format.
        Test your class by inputting various integers representing days and printing out their
        representation in the month–day format. 
*/
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;

class DayOfYear {
  private:
    int day;
    int dayOfYear;
    int dayOfMonth;
    string nameOfMonth;
  public:
    // setting month names function
    string monthNames(int month_number) {
      string monthNames[] = {"January", "February", "March", 
                              "April", "May", "June", 
                              "July", "August", "September", 
                              "October", "November", "December"};
      return monthNames[month_number];
    }

    // setting month days function
    int monthDays(int month_number) {
      int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      return monthDays[month_number];
    }

    // Constructors
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

    DayOfYear(string month, int day) {
      for (int i = 0; i < 12; i++) {
        if (monthNames(i) == month) {
          if (day > 0 && day <= monthDays(i)) {
            nameOfMonth = month;
            dayOfMonth = day;
            dayOfYear = 0;
            for (int j = 0; j < i; j++)
              dayOfYear += monthDays(j);
            dayOfYear += day;
          } else {
            cout << "Incorrect date";
          }
        }
      }
    }

    // print method
    void print() {
      cout << dayOfYear << endl;
    }
  
    // increment operator
    DayOfYear& operator++ () {
      dayOfYear++;
      dayOfMonth++;

      for (int i = 0; i < 12; i++) {
        if (nameOfMonth == monthNames(i)) {
          if (dayOfMonth > monthDays(i)) {
            dayOfMonth = 1;
            nameOfMonth = monthNames((i+1) % 12);
            if (i == 11)
              dayOfYear = 1;
          }
          break;
        }
      }
      return *this;
    }

    // decrement operator
    DayOfYear& operator-- () {
      dayOfYear--;
      dayOfMonth--;
      for (int i = 11; i >= 0; i--) {
        if (nameOfMonth == monthNames(i)) {
          if (dayOfMonth <= 0 && nameOfMonth == monthNames(0)) {
            dayOfMonth = monthDays(11);
            nameOfMonth = monthNames(11);
            dayOfYear = 365;
          } else if (dayOfMonth >= monthDays(i)) {
            dayOfMonth = monthDays(i - 1);
            nameOfMonth = monthNames(i - 1);
          }
          break;
        }
      }
      return *this;
    }

    // getters
    int getDayOfYear() {
      return dayOfYear;
    }
    string getNameOfMonth() {
      return nameOfMonth;
    }
    int getDayOfMonth() {
      return dayOfMonth;
    }
};

int main() {
  int day;
  string month;
  cout << "This program converts a Month and day of month into a day of the year in the range 1..365" << endl;
  cout << "Enter month and day (Example: January 3): ";
  cin >> month;                                                             // getting the month input from user
  cin >> day;                                                               // getting the day input from user
  DayOfYear dof(month, day);                                                // creating the DayOfYear by calling the constructor
  dof.print();                                                              // printing  
  DayOfYear dayBefore(month, day);                                          
  --dayBefore;
  DayOfYear dayAfter(month, day);
  ++dayAfter;
  cout << "The day before is " << dayBefore.getNameOfMonth() << " " <<    
          dayBefore.getDayOfMonth() << endl;
  cout << "The day after is " << dayAfter.getNameOfMonth() << " " <<
          dayAfter.getDayOfMonth() << endl;
  return 0;
}