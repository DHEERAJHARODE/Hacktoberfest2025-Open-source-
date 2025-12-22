        // private constructor//

class A 
{
    int a; double b; String c;
   private A()
    {
        a=15;
        b=15.45;
        c="yash";
        System.out.println(a+" "+b+" "+c);
    }

public static void main(String[] args) //if we can write this main method in other class (like class b)then it eill not access the value or it will show error
{
        A c=new A();

}   

}