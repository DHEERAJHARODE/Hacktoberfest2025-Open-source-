def towerHanoi(n,a,b,c):
    if n==1:
        print("Move 1st disk from ",a,"to ",c)
        return
    towerHanoi(n-1,a,c,b)
    print("move ",n,"th disk from ",a,"to ",c)
    towerHanoi(n-1,b,a,c)    



print(towerHanoi(5,"s","a","d"))
