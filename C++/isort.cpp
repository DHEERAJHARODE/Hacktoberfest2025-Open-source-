#include <bits/stdc++.h>
using namespace std;
void insertionsort(int arr[], int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cout << "enter the size of the arrray" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
}