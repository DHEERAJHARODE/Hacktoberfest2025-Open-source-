class MyLinkedList:
    def __init__(self):
        self.st = []

    def get(self, index: int) -> int:
        return -1 if index>=len(self.st) else self.st[index]

    def addAtHead(self, val: int) -> None:
        self.st.insert(0, val)

    def addAtTail(self, val: int) -> None:
        self.st.append(val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index<=len(self.st):
            self.st.insert(index, val)

    def deleteAtIndex(self, index: int) -> None:
        if len(self.st)>index:
            self.st.pop(index)
#This is an way to create linked list acc to the problem given in LeetCode
