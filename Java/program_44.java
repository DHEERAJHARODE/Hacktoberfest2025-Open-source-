
class K
{
   K()
   {
    System.out.println("hello");
   }
    K(int a)
    {
        this();// it will call same class constructor
        System.out.println(a);
    }
   
    public static void main(String[] args) 
    {
        K r=new K(100);
   
    }
}
