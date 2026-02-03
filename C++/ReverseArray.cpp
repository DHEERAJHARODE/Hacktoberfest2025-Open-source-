#include <iostream>

using namespace std;

void reverse(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void printarray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){

    int arr[7] = {6, 8, 9, -6, 12, 2, 89};
    int brr[6] = {5, 8, 3, 34, 67, 69};

    reverse(arr, 7);
    reverse(brr, 6);

    printarray(arr, 7);
    printarray(brr, 6);

    return 0;
}
