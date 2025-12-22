interface vehical
{
    // String Name="TVS";  //public + static + final
    // int speed=100;     //public + static + final

    void start();
    void stop();
    default void colour()
    {
        System.out.println("tvs colour is red");
    }
    static void speed()
    {
        System.out.println("tvs speed is 100 km/hr");
    }
}
class  cust implements vehical
{

     @Override
    public void start()
    {
        System.out.println("start(): insert key & press start button");
    }
    @Override
    public void stop()
    {
        System.out.println("stop(): exit key");
    }
    public static void main(String[] args) {
        cust c=new cust();
        c.start(); c.stop(); c.colour();   
        vehical.speed();
    }
   
}