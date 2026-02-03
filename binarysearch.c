//to apply binary search, the array must be sorted
#include<stdio.h>
int binarysearch(int arr[],int,int,int);
int binarysearch_recursive(int arr[],int,int,int);

int main()
{
    int arr[]={2,4,5,6,7,8,9,10,78,98};
    int numb,index;
    int size =sizeof (arr)/sizeof(int);
    printf("Enter the integer to search:\n");
    scanf("%d",&numb);
    //get the locatiom of the number
    index=binarysearch(arr,0,size -1,numb);  //0=lower limit, size -1 = upper limit , numb= integer to find
    
   // index=binarysearch_recursive(arr,0,size -1,numb);   //recursive method of binary search
    //display the result
    if (index==-1)              
    {
        printf("The element you are searching for is not found");
    }else printf("\nGiven number %d is found at %d index",numb,index+1);
    

    return 0;
}


//code for recursive method
int binarysearch_recursive(int arr[],int lower,int upper,int number){
    int middle;
    while (lower<=upper)
    {
        //get the middle
        middle=(lower+upper)/2;
        //check if the number is at middle
        if (arr[middle]==number)
        {
            return middle;
        } else if (arr[middle]<number)
        {
            //ignore the left half of the array and middle+1-> lower and upper remains upper and new middle is found the same way
            return binarysearch_recursive(arr,middle+1,upper,number);
        } else 
        {
            return binarysearch_recursive(arr,lower,middle-1,number);
        }
        
    }
    return -1;
}

    //code for iterative method
    int binarysearch(int arr[],int lower,int upper,int number)
    {
        while (lower<=upper)
        {
            int mid=(lower+upper)/2;
            if (arr[mid]==number)
            {
                return mid;
            } else if (arr[mid]<number)
            {
                return lower=mid+1;
            }
            else 
            {
                return upper=mid-1;
            }
            
            
        }
        return -1;
        
    }
    

