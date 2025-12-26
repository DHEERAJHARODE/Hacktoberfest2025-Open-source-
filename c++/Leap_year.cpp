
// C++ program to check if a given
// year is a leap year or not
#include <iostream>
using namespace std;
 
// Function to check leap year
bool checkYear(int year)
{
    if (year % 400 == 0) {
        return true;
    }
 
    // not a leap year if divisible by 100
    // but not divisible by 400
    else if (year % 100 == 0) {
        return false;
    }
 
    // leap year if not divisible by 100
    // but divisible by 4
    else if (year % 4 == 0) {
        return true;
    }
 
    // all other years are not leap years
    else {
        return false;
    }
}
 
// Driver code
int main()
{
    int year = 2000;
 
    checkYear(year) ? cout << "Leap Year"
                    : cout << "Not a Leap Year";
 
    return 0;
}
