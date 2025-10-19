class A
{
    int a;
    
    public A(int x)
    {
        a = x;
    }

    public A()
    {
        System.out.println("it is default constructor");
    }
    {
        System.out.println("it is funny");
    }

    public void display()
    {
        System.out.println("a="+a);
    }

    public static void main(String arg[])
    {
        A x = new A();
        x.display();
        A y = new A(10);
        y.display();
    }
}
