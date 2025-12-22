// parameterised constructor means if in constructor we can pass more than one value then it is said to be parameterised constructor
class C
{
    int x,y;
    C(int a,int b)//parameterised
    {
        x=a;
        y=b;
    }
    C(int a,String b)//parameterised
    {
        System.out.println(a+" "+b);
    }
    void show()
    {
        System.out.println(x+" "+y);
    }
    public static void start() {
    }
    public static void stop() {
    }
}
class parameterised_constructor {

public static void main(String[] args)
 {
    C r=new C(100, 200);  
    C ref=new C(150,"yash");
    r.show();  
    ref.show();
 }  
}
