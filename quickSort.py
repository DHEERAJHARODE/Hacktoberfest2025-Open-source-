def partition(a,s,e):
    pivot=a[s]
    c=0
    for i in range(s,e+1):
        if a[i]<pivot:
            c=c+1
    a[s+c],a[s]=a[s],a[s+c] 
    pivot_index=s+c
    i=s
    j=e
    while i<j:
        if a[i]<pivot:
            i=i+1
        elif a[j]>=pivot:
            j=j-1
        else:
            a[i],a[j]=a[j],a[i]
            i=i+1
            j=j-1
    return pivot_index                


def quickSort(a,s,e):
    if s>=e:
        return 
    pivot_index=partition(a,s,e)
    quickSort(a,pivot_index+1,e) 
    quickSort(a,s,pivot_index-1)

a=[5,6,9,2,7,8,7,4,5,7,5]
quickSort(a,0,len(a)-1) 
print(a)          