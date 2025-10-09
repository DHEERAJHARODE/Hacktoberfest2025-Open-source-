// Chef’s Cauldron (Potion Mixing)
// Goal: Mix ingredients to make a stable potion.
// How it works
// Start: stability = 50, toxicity = 0, steps = 0.
// Show a menu of 6 ingredients (give each a short code like DRG, SLM, etc.).
// Player enters an ingredient code each step. 
// Each ingredient changes stability/toxicity (some good, some bad).
// Some pairs have special effects (e.g., using FTH after SLM gives a bonus).
// Limit total steps (12).
// Win / Lose
// Win: stability between 70–85 and toxicity < 20.
// Lose: toxicity ≥ 100 or stability ≤ 0.
// What to display
// After each step, show current stability, toxicity, and a short status like “Brewing…” or “Almost Stable!”.




import java.util.Scanner;

class LabItem {
    protected String name;

    public LabItem(String name) {
        this.name = name;
    }

    public void showName() {
        System.out.println("Item: " + name);
    }
}

public class Potion extends LabItem {
    private int stability;
    private int toxicity;
    public static final String labName = "arkenColdren";

    public Potion() {
        this("Unnamed Potion", 50, 0);
    }

    public Potion(String name, int stability, int toxicity) {
        super(name);
        this.stability = stability;
        this.toxicity = toxicity;
    }

    public int getStability() { return stability; }

    public void setStability(int s) {
        if (s >= 0 && s < 100) this.stability = s;
    }

    public int getToxicity() { return toxicity; }

    public void setToxicity(int t) {
        if (t >= 0 && t < 100) this.toxicity = t;
    }

    public void showStatus() {
        System.out.println("Potion [" + name + "]");
        System.out.println("Stability: " + stability + " Toxicity: " + toxicity);
    }

    public static String gradeOf(Potion p) {
        if (p.stability >= 70 && p.toxicity < 20) return "Stable";
        else if (p.stability < 30) return "Unstable";
        else return "Experimental";
    }

    public static void main(String[] args) {
        System.out.println("Welcome");

        Potion p1 = new Potion();
        p1.showStatus();

        Potion p2 = new Potion("Jin", 70, 10);
        p2.showStatus();

        p1.setStability(75);
        p1.setToxicity(5);

        System.out.println("After Improvement:");
        p1.showStatus();

        System.out.println("Potion 1 Grade: " + Potion.gradeOf(p1));
        System.out.println("Potion 2 Grade: " + Potion.gradeOf(p2));

        Scanner sc = new Scanner(System.in);
        String customName = sc.nextLine();

        Potion p3 = new Potion(customName, 60, 15);
        p3.showStatus();

        System.out.println("Potion 3 Grade: " + Potion.gradeOf(p3));
    }
}
