class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        from collections import Counter
        freq = Counter(tasks)
        #max heap
        heap: list[int] = [-val for val in freq.values()]
        heapq.heapify(heap)
        
        time=0
        while heap:
            cycle=[] # store tasks we execute in cycle
            for _ in range(n+1): #we can execute up to n+1 tasks in one cycle
                if heap:
                    cnt = heapq.heappop(heap)
                    cycle.append(cnt)
            for cnt in cycle: #process the tasks: reduce their remaining count
                if cnt + 1 < 0: #still tasks left
                    heapq.heappush(heap,cnt+1)

            #increment time
            if heap:
                time += n+1 # if taks is left we needed a full cycle(n+1)
            else:
                time += len(cycle) #last cycle ,only add how many tasks we actually executed
        return time
