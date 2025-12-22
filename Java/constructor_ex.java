// constructor is use initialise the variable or value of property it is represent by class name e.g---constructor_ex
class constructor_ex
{
    int a;  String name;
    constructor_ex()    // if we comment this constructor part then program will also run because it will create default constructor 
    {
        a=0; name=null ;

    }
    void show()
    {
        System.out.println(a+" "+name);
    }
}
class b
{
    public static void main(String[] args) 
    {
        constructor_ex ref=new constructor_ex();
        ref.show();    
    }
}