class Stack{
	
	public int a[];
	public int capacity;
	public int top;
	
	Stack(int size){
		capacity = size;
		top=-1;
		a = new int[size];
	}
	
	public void push(int x) {
		if(isFull()) {
			System.out.println("OverFlow");
			}else {
				a[++top] = x;
				System.out.println(x+"is pushed in stack");
				}
	}
	
	public int pop() {
		if(isEmpty()) {
			System.out.println("UnderFlow");
			return 0;
		}else {
			System.out.println("Removing"+peek());
			return a[top--];
		}
	}
	public int peek()
    {
        if (!isEmpty()) {
            return a[top];
        }
        else {
            System.exit(1);
        }
 
        return -1;
    }
	public int size() {
        return top+1 ;
    }
	public boolean isEmpty() {
		return (top < 0);
	}
	
	public boolean isFull() {
		
		return (top == capacity-1);
			
		}
}

public class StackImpleArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Stack stack = new Stack(3);
		 
        stack.push(1);      // inserting 1 in the stack
        stack.push(2);      // inserting 2 in the stack
 
        stack.pop();        // removing the top element (2)
        stack.pop();        // removing the top element (1)
 
        stack.push(3);      // inserting 3 in the stack
 
        System.out.println("The top element is " + stack.peek());
        System.out.println("The stack size is " + stack.size());
 
        stack.pop();        // removing the top element (3)
 
        // check if the stack is empty
        if (stack.isEmpty()) {
            System.out.println("The stack is empty");
        }
        else {
            System.out.println("The stack is not empty");
        }

	}

}
