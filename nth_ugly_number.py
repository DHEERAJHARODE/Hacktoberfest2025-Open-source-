def nthugly(num):
    list=[None]*num
    list[0]=1
    i2,i3,i5=0,0,0
    second=2
    third=3
    fifth=5
    for i in range(1,num):
        list[i]=min(second,third,fifth)
        
        if(list[i]==second):
            i2=i2+1
            second=list[i2]*2
            
        if(list[i]==third):
            
            i3=i3+1
            third=list[i3]*3
        if(list[i]==fifth):
            i5=i5+1
            fifth=list[i5]*5
    print(list)
    print( list[-1])
            
num=int(input("Enter a number: "))
nthugly(num)
