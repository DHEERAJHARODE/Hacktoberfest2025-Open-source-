//here we are copy from simple constructor
class d {

    int b;
    String c;

    d() //this is constructor 
    {
        b = 200;
        c = "yash";
        System.out.println(b + " " + c);
    }

    d(d ref) // this is copy constructor by using this we can see that value of a constructor is copy by passing reference as parameter
    {
        b = ref.b;
        c = ref.c;
        System.out.println(b + " " + c);
    }

}

class copy_constructor {

    public static void main(String[] args) {

        d r = new d();
        d r2 = new d(r);

    }

}
