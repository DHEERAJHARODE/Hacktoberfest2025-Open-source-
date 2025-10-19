from collections import Counter
import heapq

def maximizeDistinctElements(nums, k):
    freq = Counter(nums)
    
    # Count initial distinct elements
    distinct_count = 0
    
    # Min-heap to store number of extra occurrences of duplicates
    heap = []
    
    for num, count in freq.items():
        if count == 1:
            distinct_count += 1
        else:
            # Push extra occurrences to heap
            heapq.heappush(heap, count - 1)
    
    # Remove duplicates using k
    while heap and k > 0:
        extra = heapq.heappop(heap)
        if k >= extra:
            k -= extra
            distinct_count += 1  # This duplicate now becomes distinct
        else:
            # If k is smaller than extra, we can't make it distinct
            break
    
    # If k still left, remove distinct elements
    distinct_count -= min(k, distinct_count)
    
    return distinct_count
