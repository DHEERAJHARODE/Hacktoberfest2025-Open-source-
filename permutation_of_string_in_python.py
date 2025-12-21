def toprint(l):
    return "".join(a)

def permute(a,l,r):
    if l==r:
        print(toprint(a))
    else:
        for i in xrange(l,r+1):
            a[l],a[i]=a[i],a[r]
            permute(a,l+1,r)
            a[l],a[i]=a[i],a[r]


            
            






string=input()
n=len(string)
a=list(string)
permute(a,0,n-1)
