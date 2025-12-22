    // instance block vs staic block    
class o 
{
    int a=10; static int b=30;
    o()
    {
        System.out.println("default constructor");
    }
    {   // instance block and it will run before constructor
        System.out.println("yashpatel");
            System.out.println(a+" "+b);// instance block will allow both static variable and non- static variable
   
    }
   static{  // for static block we need to use static keyword and it does not require any object
        System.out.println("hii");
        System.out.println(b);// static block will only allow the static variable it will not allow [a] 
    }
    public static void main(String[] args) 
    {
        o r=new o();

    }

}