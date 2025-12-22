abstract class animal
{
    void legs()
    {
        System.out.println("all animals have four legs");
    }
   abstract void sound();   
   abstract void eat();
}
class dog extends animal
{
    @Override
    void sound()
    {
        System.out.println("bow bow...");
    }
    void eat()
    {
        System.out.println("it eats meat");
    }
}
class cow extends animal
{
    @Override
    void sound()
    {
        System.out.println("ooo ooo...");
    }
    void eat()
    {
        System.out.println("it eats grass");
    }
}
class absclass
{
    public static void main(String[] args) 
    {
        dog d=new dog();
        cow c=new cow();
        
        d.sound(); d.eat(); d.legs();
        c.sound(); c.eat(); c.legs();
    }
}
