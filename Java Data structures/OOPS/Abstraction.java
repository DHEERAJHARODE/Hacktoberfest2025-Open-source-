//Exposing the set of services but hiding the internal implementation
abstract class Bird {
    public abstract void fly();

    public abstract void eat();
}

class Sparrow extends Bird {
    public void fly() {
        System.out.println("Sparrow fly @short height");
    }

    public void eat() {
        System.out.println("Sparrow eat grains...");
    }
}

// abstract class can contain concrete and abstract methods
// concrete methods : A method with implementation
// abstract methods : A method without implementation
abstract class Eagle extends Bird {
    public void fly() {// concrete method.....
        System.out.println("Eagel fly @very very height");
    }

    public abstract void eat();// abstract method..........
}// eat method for eagle is abstract because there could be two eagles 1. which
 // eats snake 2. which catches and eats the prey over the ocean.......

class SerpentEagle extends Eagle {
    public void eat() {
        System.out.println("Serpent eagel eats snakes...");
    }
}

class GoldenEagle extends Eagle {
    public void eat() {
        System.out.println("Golden eagel catches prey over the ocean...");
    }
}

class Crow extends Bird {
    public void fly() {
        System.out.println("Crow fly @medium height...");
    }

    public void eat() {
        System.out.println("Crow eat grains...");
    }
}

class Sky {
    public void allowBird(Bird ref) {
        ref.fly();
        ref.eat();
        System.out.println();
    }
}

public class Abstraction {
    public static void main(String[] args) {
        Sky sky = new Sky();
        sky.allowBird(new Sparrow());
        sky.allowBird(new SerpentEagle());
        sky.allowBird(new GoldenEagle());
        sky.allowBird(new Crow());
    }
}
