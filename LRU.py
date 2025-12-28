class Node:
    def __init__(self,key,val):
        #DLL
        self.prev = None
        self.next = None

        self.val = val
        self.key = key #Need this for o(1) deletions.


        
class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity

        #dummy MRU and LRU.
        self.head = Node(0,0)
        self.tail = Node(0,0)

        self.di = {} #key : Node

        #MISSING CONNECTION!! head and tail are not connected!!
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def removeDLL(self,node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def addFrontDLL(self,node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def get(self, key: int) -> int:
        #check if it exists
        if self.di.get(key,None):
            node = self.di[key]

            #remove the node from DLL
            self.removeDLL(node)
            #add it to front in DLL
            self.addFrontDLL(node)

            #return it's value
            return node.val

        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        #Its either present in the map - then just overwrite node value 
        # and put it at the front of the head.
        if self.di.get(key,None):
            #present
            node = self.di[key]
            node.val = value

            #remove and add to front.
            self.removeDLL(node)
            self.addFrontDLL(node)
        else:
            #1)update the map
            self.di[key] = Node(key,value)
            #ERROR
            node = self.di[key]
            #2) add to front of the DLL
            self.addFrontDLL(node)
            
            #3) Remove the LRU if its too big.
            if len(self.di)>self.capacity:
                lru = self.tail.prev
                del self.di[lru.key]
                self.removeDLL(lru)
        

