#include <iostream> 
using namespace std; 

int main(){ 

    int arr[4]={10,20,30,40}; 
    int m = 2; 
    int s = 0; 
    int e = 0; 
    int ans = -1;  
    int len = sizeof(arr)/4; 
    for(int i = 0 ; i<len ; i++){ 
        e = e + arr[i];  
       
    }   
    
    int mid = (s+e)/2; 
    
    while(s<=e){  
        int coun = 0 ; 
        int cumm = 0 ; 
         
       for( int j = 0 ; j < len ;j++){ 
           cumm = cumm +arr[j];
           if(cumm <= mid){ 
            
           } 
           else{ 
            coun = coun+1; 
            cumm = arr[j];
           }
       }  
       cout <<coun <<" "<<mid<<endl;
       if(coun>=m){ 
        s = mid+ 1;
       } 
       else {  
        ans = mid;
        e = mid-1;
       } 
       mid = (s+e)/2;
    } 
    cout<< ans ;

}