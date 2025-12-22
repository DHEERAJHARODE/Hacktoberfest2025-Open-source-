//default constructor
class A
{
    int a; String b; boolean c;
    A()// if we comment out this constructor then all value will be given by compiler and it will be default value because it will create a default constructor
    {
        a=100; b="yash"; c=true;
    }
    void Disp()
    {
        System.out.println(a+" "+b+" "+c);
    }
}
class B
{
    public static void main(String[] args) {
       
        A r=new A();
         
    r.Disp();

    }
    
}
