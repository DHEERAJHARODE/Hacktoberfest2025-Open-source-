#include <bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
public:
   vector <int> dq;
   ProductOfNumbers() {
      dq.push_back(1);
   }
   void add(int num) {
      if(num == 0){
         dq.clear();
         dq.push_back(1);
      }
      else{
         dq.push_back(dq.back() * num);
      }
   }
   int getProduct(int k) {
      int n = (int)dq.size();
      return k > n - 1? 0 : dq[n - 1] / dq[n - k - 1];
   }
};
main(){
   ProductOfNumbers ob;
   (ob.add(3));
   (ob.add(0));
   (ob.add(2));
   (ob.add(5));
   (ob.add(4));
   cout << (ob.getProduct(2)) << endl;
   cout << (ob.getProduct(3)) << endl;
   cout << (ob.getProduct(4)) << endl;
   (ob.add(8));
   cout << (ob.getProduct(2)) << endl;
}
