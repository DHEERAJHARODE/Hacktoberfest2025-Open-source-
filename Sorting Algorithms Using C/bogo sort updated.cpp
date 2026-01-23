#include <iostream>
#include <random>	
using namespace std;

void printVals(int arr[], int size){
	for(int x = 0; x < size; x++){
		cout << arr[x];
		if(x != size-1)
			cout << ", ";
	}
	cout << endl;
}

bool sorted(int arr[], int size){
	for(int x = 0; x < size-1; x++){
		if(arr[x] > arr[x+1])
			return false;
	}
	return true;
}

void shuffle(int arr[], int size){
	random_device random;
	for(int x = 0; x < size; x++){
		char r = random()%size;
		int temp = arr[x];
		arr[x] = arr[r];
		arr[r] = temp;
	}
}

void bogo(int arr[], int size){
	printVals(arr, size);
	int count = 1;
	while(!sorted(arr, size)){
		shuffle(arr, size);
		cout << count++ << " - ";
		printVals(arr, size);
	}
}

int main(){
	int arr[] = {8,6,7,5,3,0,9};
	bogo(arr, 7);
	return 0;
}
