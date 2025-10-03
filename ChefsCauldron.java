import java.util.*;

public class ChefsCauldron {
    private static int stability = 50;
    private static int toxicity = 0;
    private static int steps = 0;
    private static final int MAX_STEPS = 12;

    // track last ingredient for combo effects
    private static String lastIngredient = "";

    // Ingredient effects: stability, toxicity
    private static final Map<String, int[]> ingredients = new HashMap<>();

    static {
        // ingredientCode -> {stabilityChange, toxicityChange}
        ingredients.put("DRG", new int[]{+10, +5});   // Dragon Scale
        ingredients.put("SLM", new int[]{+8, +10});   // Slime Essence
        ingredients.put("FTH", new int[]{+5, -5});    // Phoenix Feather
        ingredients.put("BNS", new int[]{-12, +3});   // Bone Shard
        ingredients.put("HRB", new int[]{+6, +2});    // Healing Herb
        ingredients.put("SHD", new int[]{-8, +12});   // Shadow Dust
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("🔮 Welcome to Chef’s Cauldron – Potion Mixing Game!");
        System.out.println("Goal: Mix ingredients to brew a stable potion.");
        System.out.println("Win: Stability between 70–85 AND Toxicity < 20");
        System.out.println("Lose: Toxicity ≥ 100 OR Stability ≤ 0");
        System.out.println("Available ingredients: " + ingredients.keySet());
        System.out.println("--------------------------------------------------");

        while (steps < MAX_STEPS) {
            System.out.print("\nStep " + (steps + 1) + " – Choose an ingredient: ");
            String choice = sc.nextLine().trim().toUpperCase();

            if (!ingredients.containsKey(choice)) {
                System.out.println("❌ Invalid ingredient! Try again.");
                continue;
            }

            applyIngredient(choice);
            steps++;

            // show status
            System.out.println("Stability: " + stability + " | Toxicity: " + toxicity + " | Status: " + getStatus());

            // check for win/lose early
            if (toxicity >= 100 || stability <= 0) {
                System.out.println("\n💀 The potion exploded! You lose.");
                return;
            }
            if (stability >= 70 && stability <= 85 && toxicity < 20) {
                System.out.println("\n🎉 Congratulations! You brewed a stable potion!");
                return;
            }

            lastIngredient = choice;
        }

        // after max steps
        System.out.println("\n⚖️ Steps finished. Final Stability = " + stability + ", Toxicity = " + toxicity);
        if (stability >= 70 && stability <= 85 && toxicity < 20) {
            System.out.println("🎉 You win! The potion is perfectly stable.");
        } else {
            System.out.println("❌ You lose! Potion failed.");
        }

        sc.close();
    }

    private static void applyIngredient(String code) {
        int[] effect = ingredients.get(code);
        stability += effect[0];
        toxicity += effect[1];

        // Special combo: FTH after SLM
        if (lastIngredient.equals("SLM") && code.equals("FTH")) {
            System.out.println("✨ Special Combo! Slime + Feather stabilizes potion.");
            stability += 12;
        }
    }

    private static String getStatus() {
        if (stability <= 20) return "⚠️ Potion is unstable!";
        if (stability >= 65 && stability <= 85 && toxicity < 20) return "🌟 Almost Stable!";
        if (toxicity > 60) return "☠️ Potion is very toxic!";
        return "Brewing...";
    }
}
