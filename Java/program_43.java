// it is a program for differeniate the instance variable and local variable
class F
{
    int a;// instance variable
    F(int a)//local variable
    {
        this.a=a;// this keyword is used then it is said as instance variable 
    }
    void show()
    {
        System.out.println(a);
    }
    public static void main(String[] args) 
    {
        F r=new F(100);
        r.show();
        
    }
}
