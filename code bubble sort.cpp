#include <iostream>
using namespace std;

// #include "solution.h"

void bubbleSort(int input[], int size)
{
    // Write your code here
    for (int i = 0; i < size - 1; i++)
    {
        int min = input[i], minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (input[j] < min)
            {
                min = input[j];
                minindex = j;
            }
        }
        // swap case
        int temp = input[i];
        input[i] = input[minindex];
        input[minindex] = temp;
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        bubbleSort(input, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }
}