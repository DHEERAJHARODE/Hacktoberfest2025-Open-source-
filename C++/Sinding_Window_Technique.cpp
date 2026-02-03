#include<iostream>
using namespace std;

// Returns maximum sum in a subarray of size k
int max_sum(int arr[], int n, int k)
{
    // n must be greater
    if(n<k)
    {
        cout<<"Invalid!!";
        return -1;
    }

    //sum of first window of size k
    int win_sum=0;
    for(int i=0;i<k;i++)
    {
        win_sum+=arr[i];
    }

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int max_sum=win_sum;
    for(int i=k;i>n;i++)
    {
        win_sum+=(arr[i]-arr[i-k]);
        max_sum=max(max_sum,win_sum);
    }
    return max_sum;
}

int main()
{
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int win_size;
    cout<<"Enter the size of the window: ";
    cin>>win_size;
    cout<<"The max sum is : "<<max_sum(arr,size,win_size);
    return 0;
}
