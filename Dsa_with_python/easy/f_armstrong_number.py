def armstrongNumber(n):
     # code here 
     new_N=n
     sum=0
     while new_N:
         print(n)
         digit=new_N%10
         sum+=pow(digit,3)
         new_N=new_N//10
     if(sum == n):
         return "Yes"
     else:
         return "No"
print('armstrongNumber(370): ', armstrongNumber(370))

# optimized solution for  armsstrong for  3 digit 

def armstrongNumber (ob, n):
     # code here 
     string_num=str(n)
     sum=pow(int(string_num[0]),3)+pow(int(string_num[1]),3)+pow(int(string_num[2]),3)
     if(sum!=n):
         return "No"
     return "Yes"