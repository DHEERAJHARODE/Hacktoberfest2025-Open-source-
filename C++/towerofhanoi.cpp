#include <iostream>
using namespace std;
// recursive function for tower of hanoi
void towerofhanoi(int n, char source, char aux, char destination)
{
    if (n == 0) // base case
    {
        return;
    }
    towerofhanoi(n - 1, source, destination, aux); // Call to move n-1 disks from source to aux peg
    cout << "Move disk " << n << " From peg " << source << " to peg " << destination << endl;
    towerofhanoi(n - 1, aux, source, destination); // Call to move n-1 aux peg to destination peg
}
int main()
{
    int n = 4;                     // number of disks
    towerofhanoi(n, 'A', 'B', 'C'); // function call
    return 0;
}
