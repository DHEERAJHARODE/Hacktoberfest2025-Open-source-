class StackEmptyException(Exception):
    """A custom Stack Exception"""

class QueueEmptyException(Exception):
    """A custom Queue Exception"""

class Stack:
    def __init__(self) -> None:
        self.stack_contents = []
        self.stack_top = -1
    def view(self):
        print(self.stack_contents)
    def size(self):
        return self.stack_top + 1
    def is_empty(self):
        return self.stack_top == -1
    def push(self, obj):
        self.stack_top += 1
        self.stack_contents.insert(self.stack_top, obj)
    def pop(self):
        if self.is_empty():
            raise StackEmptyException("Stack is empty. Cannot pop from an empty stack.")
        ret = self.stack_contents.pop(self.stack_top)
        self.stack_top -= 1
        return ret
    def top(self):
        if self.is_empty():
            raise StackEmptyException("Stack is empty. Cannot access top of an empty stack.")
        return self.stack_contents[self.stack_top]

class Queue:
    def __init__(self) -> None:
        self.q = []
        self.r = -1
    def is_empty(self):
        return self.r == -1
    def size(self):
        return self.r + 1
    def view(self):
        print(*self.q)
    def enqueue(self,obj):
        self.r += 1
        self.q.insert(0, obj)
    def dequeue(self):
        if self.is_empty():
            raise QueueEmptyException("Queue is empty. Cannot dequeue from an empty queue.")
        else:
            self.r -= 1
            return self.q.pop(0)
    def front(self):
        if self.is_empty():
            raise QueueEmptyException("Queue is empty. Cannot access front of an empty queue.")
        else:
            return self.q[0]
