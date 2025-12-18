// This program is to calculate number of set bits(i.e. 1) in any binary number using renowned n &(n-1) method

#include<iostream>
using namespace std;
int main()
{
    int num,count=0;
    cout<<"Enter the Decimal number: "; // Here we take decimal number as input
    cin>>num;
    int original=num; // to store the original value to use it later when num get modified
    while(num>0)
    {
        num=num & (num-1); 
        count++; // count is increased by 1 after each iteration
    }
    cout<<"Number of set bits in "<<original<<" is: "<<count;
}

// Explanation
// let us assume number to be 13
// so binary representation of it will be 1101, so clearly it has 3 bits as 1
// So our aim is to calculate this using n & n-1 method

// Step 1:
// 13:  1101
// 12: 1100
// 13&12=1100

// Step 2:
// 12: 1100
// 11: 1011
// 12&11= 1000

// Step 3:
// 1000 is 8
// and 7 is 0111
// 8 & 7 = 0000

// At each iteration we increase the count value by 1
// Therefore, in three steps only we get the total set bits in 13
// Basically, time complexity of this algorithm depends on total no. of set bits in binary representation of that number