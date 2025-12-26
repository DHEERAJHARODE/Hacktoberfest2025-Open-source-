class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
def length(head):
    count=0
    while head is not None:
        count=count+1
        head=head.next
    return count    

def floydCycleLoop(head):
    if(head==None):
        return None
    fast=head
    slow= head
    while(slow is not None and fast is not None):
        fast=fast.next
        if(fast is not None):
            fast=fast.next
        slow=slow.next
        if(slow==fast):
            return slow
    return None    


def printLL(head):
    while head is not None:
        print(str(head.data)+" -> ",end="")
        head=head.next
    print("None")
    return         
def takeInput():
            inputList= [int(ele) for ele in input().split()]
            head= None
            tail=None
            for currData in inputList:
                if currData==-1:
                    break
                newNode=Node(currData)
                if head is None:
                    head=newNode
                    tail=newNode
                else:
                    tail.next=newNode
                    tail=newNode    
            tail.next=head.next 
            if(floydCycleLoop(head)):
               print("loop Found")
            else:
               print("Loop not found")

            return 
               

head=takeInput()  
printLL(head) 
