// C program to check if a given year is leap year or not 
#include <stdbool.h> 
#include <stdio.h> 

bool checkYear(int year) 
{ 
	// If a year is multiple of 400, 
	// then it is a leap year 
	if (year % 400 == 0) 
		return true; 

	// Else If a year is multiple of 100, 
	// then it is not a leap year 
	else if (year % 100 == 0) 
		return false; 

	// Else If a year is multiple of 4, 
	// then it is a leap year 
	else if (year % 4 == 0) 
		return true; 
	// if no above condition is satisfied, then it is not 
	// a leap year 
	return false; 
} 

// Driver code 
int main() 
{ 
	int year = 2000; 

	if (checkYear(year)) { 
		printf("Leap Year"); 
	} 
	else { 
		printf("Not a Leap Year"); 
	} 
	return 0; 
}
