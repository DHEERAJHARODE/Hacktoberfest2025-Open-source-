public class randomnum
{
    public static void  main(String[] args) 
    {
        int min = 0;
        int max = 200;
        System.out.println("Random value of type double between"+min+" to "+max+":");
        double a = Math.random()*(max-min+1)+min;
        System.out.println(a);
        System.out.println("Random value of type double between"+min+" to "+max+":");
        int b = (int) (Math.random()*(max-min+1)+min);
       System.out.println(b);

    }
}

