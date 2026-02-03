#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n)
{
    int j, key, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the arrray" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionsort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\t';
}