# Time Complexity O(log N)
# Space Complexity O(1)

#As per Doc

def condition(cards,query, mid):
    mid_num = cards[mid]
    if mid_num == query:
        if mid_num-1>=0 and cards[mid-1] == query:
            return 'left'
        else:
            return 'right'
    elif mid_num<query:
        return 'left' 
    else:
        return 'right'

def binary_search(lo,hi,condition):
    while lo<=hi:
        mid =(lo+hi)//2
        result = condition(mid)
        if result=='found':
            return mid
        elif result == 'left':
            return mid-1
        else:
            lo = mid+1
    return -1
