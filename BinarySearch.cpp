
#include <iostream>
int binarySearch(int arr[], int p, int r, int num) {
    if (p <= r) {
        int mid = (p + r) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] > num)
            return binarySearch(arr, p, mid - 1, num);
        if (arr[mid] < num)
            return binarySearch(arr, mid + 1, r, num);
    }
    return -1;
}
int main() {
    int arr[] = { 1, 3, 7, 15, 18, 20, 25, 33, 36, 40 };//hardcoding the array
    int n = sizeof(arr) / sizeof(arr[0]);//size of entered array
    int num;
    std::cout << "Enter the number to search: \n";
    std::cin >> num;
    int index = binarySearch(arr, 0, n - 1, num);//function call
    if (index == -1) {
        std::cout << num << " doesn't exist in the array";
    }
    else {
        std::cout << num << " is at index " << index << " in the array";
    }
    return 0;
}