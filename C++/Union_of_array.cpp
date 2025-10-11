#include<bits/stdc++.h>
using namespace std;


int main(){
     vector <int >a(6) , b(6);
    int n1 = a.size();
    int n2 = b.size();
    for(int i =0;i<n1 ; i++){
        cin >> a[i];
    }
    for(int i =0;i<n2 ; i++){
        cin >> b[i];
    }
    int i =0, j=0;
    vector<int >unionArr;
    while (i<n1 && j< n2){
        if(a[i] <= b[j]){
            if(unionArr.size() == 0  || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
            }
        i++;
        }
        else{
            
            if(unionArr.size() == 0  || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
            }
        j++;
        }
    }

    while(j<n2){
         
            if(unionArr.size() == 0  || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
            }
        j++;
    }

    while(i<n1){
         if(unionArr.size() == 0  || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
            }
        i++;
    }

    int n3 = unionArr.size();
   for(int k = 0 ;k<n3;k++){
        cout << unionArr[k]<< " ";
    }
}