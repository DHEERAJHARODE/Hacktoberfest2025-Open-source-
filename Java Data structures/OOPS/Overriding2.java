class Plane {// instead of this we can create an abstract class....................
    void takeoff() {
        System.out.println("Plane took off.....");
    }

    void fly() {
        System.out.println("Plane is flying......");
    }

    void land() {
        System.out.println("Plane is landed.........");
    }
}

class PassengerPlane extends Plane {
    void takeoff() {
        System.out.println("PassengerPlane took off.....");
    }

    void fly() {
        System.out.println("PassengerPlane is flying......");
    }

    void land() {
        System.out.println("PassengerPlane is landed.........");
    }
}

class CargoPlane extends Plane {
    void takeoff() {
        System.out.println("CargoPlane took off.....");
    }

    void fly() {
        System.out.println("CargoPlane is flying......");
    }

    void land() {
        System.out.println("CargoPlane is landed.........");
    }
}

class FighterPlane extends Plane {
    void takeoff() {
        System.out.println("FighterPlane took off.....");
    }

    void fly() {
        System.out.println("FighterPlane is flying......");
    }

    void land() {
        System.out.println("FighterPlane is landed.........");
    }
}

class Airport {
    void AllowPlane(Plane p) {
        p.takeoff();
        p.fly();
        p.land();
    }
}

public class Overriding2 {
    public static void main(String[] args) {
        PassengerPlane p = new PassengerPlane();
        CargoPlane c = new CargoPlane();
        FighterPlane f = new FighterPlane();
        Airport a = new Airport();
        a.AllowPlane(p);
        System.out.println();
        a.AllowPlane(c);
        System.out.println();
        a.AllowPlane(f);
        System.out.println();
        Plane p1 = new CargoPlane();// runtime object will be considered instead of reference type.......
        a.AllowPlane(p1);
    }
}
