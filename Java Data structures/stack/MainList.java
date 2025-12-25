public class CustomStackFromLinkedList {

    class Node{
        private int data ;
        private Node next = null;

        Node(int value){
            this.data = value;
        }

        public String toSting(){
            return String.valueOf(data);
        }
    }
    private Node head;
    private int top = 0;


    CustomStackFromLinkedList(){
        this.head = null;
    }

    public void customPush(int value){
        Node node = new Node(value);
        node.next = this.head;
        this.head = node;
        this.top++;
    }

    public int size(){
        return this.top;
    }

    public int customPop(){
        if(isEmpty()) return -1;
        int Data = this.head.data;
        this.head = this.head.next;
        this.top--;
        return Data;
    }

    public int customPeek(){
        if(isEmpty()) return -1;
        return this.head.data;
    }

    public boolean isEmpty(){
        if(this.head == null){
            System.out.println("StackOverflow");
            return true;
        }
        else return false;
    }

    public String toString(){
        StringBuilder stack = new StringBuilder();
        stack.append("[");
        Node current = this.head;
        while(current != null){
            stack.append(current.data);
            if(current.next != null) stack.append(",");
            current = current.next;
        }
        stack.append("]");
        return stack.toString();
    }

}


public class MainList {
    public static void main(String[] args) {
        CustomStackFromLinkedList stack = new CustomStackFromLinkedList();
        System.out.println("----------------------");
        System.out.println(stack.customPop());
        stack.customPush(1);
        stack.customPush(2);
        stack.customPush(3);
        stack.customPush(4);
        stack.customPush(5);
        stack.customPush(6);
        System.out.println(stack);
        System.out.println(stack.customPop());
        System.out.println(stack);
        System.out.println(stack.size());
    }
}

