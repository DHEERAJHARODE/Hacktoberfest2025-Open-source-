// Given two arrays of sizes m and n, we need to print the intersection of the two arrays(elements common to both the arrays)
#include <iostream>
#include<unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> output;
  
    for(int i=0;i<n;i++)
    {
        output[arr1[i]]++;
    }

    for(int j=0;j<m;j++)
    {
        if(output[arr2[j]]>0) // Condition to check whether the number exists or not
        {
            cout<<arr2[j]<<endl;
            output[arr2[j]]--;
        } 
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}