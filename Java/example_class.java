public class example_class {

    
        int age=19;
        int weight=52;
        String colour="light";
        void eat()
        {
            System.out.println("i'm eating");
        }    
        void sleep()
        {
            System.out.println("i'm sleeping");
        }

        public static void main(String[] args)
        {
        example_class P=new example_class();
            System.out.println(P.age);
            System.out.println(P.weight);
            System.out.println(P.colour);  

            P.eat();    P.sleep();
        }
    
}
