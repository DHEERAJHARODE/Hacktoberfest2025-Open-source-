import java.util.Stack;

public class Main {
    public static void pushAtBottom(int a, Stack<Integer> st){
        if(st.isEmpty()){
            st.push(a);
            return;
        }
        int popping=st.pop();
        pushAtBottom(a,st);
        st.push(popping);
    }
    public static void main(String[] args) {
        Stack<Integer> st=new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        pushAtBottom(5,st);
        System.out.println(st);
    }
}
