class m
{
   m()
   {
    this(10);// it will call it's parametric constructor
   }
    m(int a)
    {
        System.out.println(a);
    }
   
    public static void main(String[] args) 
    {
        m r=new m();
       
        
    }
}