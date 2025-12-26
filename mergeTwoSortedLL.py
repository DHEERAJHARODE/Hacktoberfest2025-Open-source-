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
            return head
def mergeTwoList(first,second):
    if first is None:
        return second
    if second is None:
        return first
    if(first.data<=second.data):
        return solve(first,second)
    else:
        return solve(second,first)        

def solve(first,second):
    if(first.next is None):
        first.next=second
        return first
    curr1=first
    curr2=second
    next1=curr1.next
    next2=curr2.next

    while((next1!=None) and (curr2 !=None)):
        if((curr2.data>=curr1.data) and (curr2.data <= next1.data)):
            curr1.next=curr2
            next2=curr2.next
            curr2.next=next1

            curr1=curr2
            curr2=next2
        else:
            curr1=next1
            next1=next1.next

            if(next1 is None):
                curr1.next=curr2
                return first    
                
first=takeInput()  
printLL(first) 
second=takeInput()  
printLL(second) 
mergedLL=mergeTwoList(first,second)
printLL(mergedLL)
