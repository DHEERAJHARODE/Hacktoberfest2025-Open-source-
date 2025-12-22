                                                       //simple inheritance
class student   // super class
{
    int roll,marks;
    String name;
    void input()
    {
        System.out.println("enter the roll name & marks");
    }
}
class yash extends student //sub class
{
    void disp()
    {
        roll=1; name="yash"; marks=89;
        System.out.println(roll+" "+name+" "+marks);
    }
    public static void main(String[] args) 
    {
        yash r=new yash();
        r.input(); r.disp();
    }
}

