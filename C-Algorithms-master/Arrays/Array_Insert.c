#include<stdio.h>
#define MAX 100

void insert(int arr[], int n, int item, int index);
void display(int arr[], int n);

main(){
    int arr[MAX], i, n, item, pos;

    // Input
    printf("Enter size of array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter number to insert: ");
    scanf("%d", &item);
    printf("\nEnter position at which to insert: ");
    scanf("%d", &pos);
    if(pos <= n){
        insert(arr, n, item, pos-1);
        n++;
        printf("\nNew Array: ");
        display(arr, n);
    }
    else{
        printf("\nINVALID INPUT! Position more than size of array.");
    } 
}

void insert(int arr[], int n, int item, int index){
    int i;
    for(i = n; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = item;
}

void display(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
