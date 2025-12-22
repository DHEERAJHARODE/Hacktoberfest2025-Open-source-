class x    // super class
{
    int a,b,c;
    void add()
    {
        a=10;   b=20;
        c=a+b;
        System.out.println("Sum of two numbers: "+c);
    }
    void sub()
    {
        a=200; b=100;
        c=a-b;
        System.out.println("Sub of two numbers: "+c);
    }
}
class y extends x  // 1 sub class
{
    void multi()
    {
        a=40; b=5;
        c=a*b;
        System.out.println("Multiplication of two numbers: "+c);

    }
    void div()
    {
        a=40; b=2;
        c=a/b;
        System.out.println("Division of two numbers: "+c);
    }
}
class z extends y //2 sub class 
{
    void rem()
    {
         a = 10; b=3;
        c=a%b;
        System.out.println("Remainder of two numbers: "+c);
    }
}
class test
{ 
public static void main(String[] args) {
    
    z r=new z();
    r.add();    r.sub();    r.multi();    r.div();    r.rem();
    }
}