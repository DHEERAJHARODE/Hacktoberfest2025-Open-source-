#include <bits/stdc++.h>

using namespace std;

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void bubble_sort(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
        cout << "runs\n";
    }
}

void InsertionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int j = i;
        while (a[j - 1] > a[j] && j >= 0)
        {
            int temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;

            j--;
        }
        a[j + 1] = a[i];
    }
}

void mergeSort(vector<int> &a, int l, int h)
{
    if (l >= h)
        return;
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void MS(vector<int> &a, int n)
{
    mergeSort(a, 0, n - 1);
}

void merge(vector <int>&a,int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        a[i] = temp[i-low];
    }
}



int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // selection_sort(a, n);
    // bubble_sort(a,n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
