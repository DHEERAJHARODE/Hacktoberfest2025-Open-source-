import java.util.Scanner;

/**
 * Chef's Cauldron - Potion Mixing Game
 * Goal: Mix ingredients to make a stable potion
 * 
 * Game Rules:
 * - Start: stability = 50, toxicity = 0, steps = 0 
 * - Choose from 6 ingredients with unique codes
 * - Each ingredient affects stability and toxicity
 * - Some ingredient pairs have special effects
 * - Maximum 12 steps allowed
 * - Win: stability between 70-85 AND toxicity < 20
 * - Lose: toxicity ≥ 100 OR stability ≤ 0
 */
public class PotionMixingGame {
    
    // Game state variables
    private int stability;
    private int toxicity;
    private int steps;
    private int maxSteps;
    private String lastIngredient;
    private Scanner scanner;
    
    // Ingredient codes and their effects
    private static final String[][] INGREDIENTS = {
        {"DRG", "Dragon Scale", "+15 stability, +5 toxicity"},
        {"SLM", "Slime Mold", "+10 stability, +8 toxicity"},
        {"FTH", "Fairy Thistle", "+8 stability, -3 toxicity"},
        {"CRS", "Crystal Salt", "+12 stability, +2 toxicity"},
        {"MTL", "Moonlight", "-5 toxicity, +3 stability"},
        {"BRN", "Burning Root", "+20 stability, +15 toxicity"}
    };
    
    // Special ingredient pair effects
    private static final String[][] SPECIAL_PAIRS = {
        {"FTH", "SLM", "Special: Fairy's Blessing - +10 stability, -10 toxicity"},
        {"MTL", "DRG", "Special: Lunar Dragon - +25 stability, +5 toxicity"},
        {"CRS", "FTH", "Special: Crystal Garden - +15 stability, -5 toxicity"},
        {"BRN", "MTL", "Special: Cooled Fire - +30 stability, -8 toxicity"}
    };
    
    public PotionMixingGame() {
        this.stability = 50;
        this.toxicity = 0;
        this.steps = 0;
        this.maxSteps = 12;
        this.lastIngredient = "";
        this.scanner = new Scanner(System.in);
    }
    
    /**
     * Main game loop
     */
    public void play() {
        System.out.println("🧪 Welcome to Chef's Cauldron - Potion Mixing Game! 🧪");
        System.out.println("=================================================");
        System.out.println("Goal: Create a stable potion!");
        System.out.println("Win: stability 70-85 AND toxicity < 20");
        System.out.println("Lose: toxicity ≥ 100 OR stability ≤ 0");
        System.out.println("=================================================\n");
        
        while (steps < maxSteps && !isGameOver()) {
            displayStatus();
            displayMenu();
            String choice = getPlayerChoice();
            
            if (processIngredient(choice)) {
                steps++;
                displayStatus();
                displayGameMessage();
            }
        }
        
        endGame();
        scanner.close();
    }
    
    /**
     * Display current game status
     */
    private void displayStatus() {
        System.out.println("\n📊 Current Status:");
        System.out.println("Stability: " + stability + "/100");
        System.out.println("Toxicity: " + toxicity + "/100");
        System.out.println("Steps: " + steps + "/" + maxSteps);
        System.out.println("Last ingredient: " + (lastIngredient.isEmpty() ? "None" : lastIngredient));
    }
    
    /**
     * Display ingredient menu
     */
    private void displayMenu() {
        System.out.println("\n🧪 Available Ingredients:");
        System.out.println("========================");
        for (String[] ingredient : INGREDIENTS) {
            System.out.println(ingredient[0] + " - " + ingredient[1] + " (" + ingredient[2] + ")");
        }
        System.out.println("========================");
    }
    
    /**
     * Get player's ingredient choice
     */
    private String getPlayerChoice() {
        System.out.print("\nEnter ingredient code (or 'QUIT' to exit): ");
        return scanner.nextLine().trim().toUpperCase();
    }
    
    /**
     * Process the selected ingredient
     */
    private boolean processIngredient(String choice) {
        if (choice.equals("QUIT")) {
            System.out.println("👋 Thanks for playing! Goodbye!");
            System.exit(0);
        }
        
        // Validate ingredient code
        String ingredientName = getIngredientName(choice);
        if (ingredientName == null) {
            System.out.println("❌ Invalid ingredient code! Please try again.");
            return false;
        }
        
        // Apply regular ingredient effects first
        applyIngredientEffect(choice);
        
        // Check for special pair effects and apply bonus
        String specialEffect = checkSpecialPair(lastIngredient, choice);
        if (specialEffect != null) {
            System.out.println("✨ " + specialEffect);
            applySpecialEffectBonus(lastIngredient, choice);
        }
        
        lastIngredient = choice;
        return true;
    }
    
    /**
     * Get ingredient name from code
     */
    private String getIngredientName(String code) {
        for (String[] ingredient : INGREDIENTS) {
            if (ingredient[0].equals(code)) {
                return ingredient[1];
            }
        }
        return null;
    }
    
    /**
     * Check for special pair effects
     */
    private String checkSpecialPair(String first, String second) {
        if (first.isEmpty()) return null;
        
        for (String[] pair : SPECIAL_PAIRS) {
            if ((pair[0].equals(first) && pair[1].equals(second)) ||
                (pair[0].equals(second) && pair[1].equals(first))) {
                return pair[2];
            }
        }
        return null;
    }
    
    /**
     * Apply special pair effect bonuses
     */
    private void applySpecialEffectBonus(String first, String second) {
        if ((first.equals("FTH") && second.equals("SLM")) || 
            (first.equals("SLM") && second.equals("FTH"))) {
            stability += 10;
            toxicity -= 10;
        } else if ((first.equals("MTL") && second.equals("DRG")) || 
                   (first.equals("DRG") && second.equals("MTL"))) {
            stability += 25;
            toxicity += 5;
        } else if ((first.equals("CRS") && second.equals("FTH")) || 
                   (first.equals("FTH") && second.equals("CRS"))) {
            stability += 15;
            toxicity -= 5;
        } else if ((first.equals("BRN") && second.equals("MTL")) || 
                   (first.equals("MTL") && second.equals("BRN"))) {
            stability += 30;
            toxicity -= 8;
        }
        
        // Ensure values stay within bounds
        stability = Math.max(0, Math.min(100, stability));
        toxicity = Math.max(0, Math.min(100, toxicity));
    }
    
    /**
     * Apply regular ingredient effects
     */
    private void applyIngredientEffect(String code) {
        switch (code) {
            case "DRG":
                stability += 15;
                toxicity += 5;
                break;
            case "SLM":
                stability += 10;
                toxicity += 8;
                break;
            case "FTH":
                stability += 8;
                toxicity -= 3;
                break;
            case "CRS":
                stability += 12;
                toxicity += 2;
                break;
            case "MTL":
                toxicity -= 5;
                stability += 3;
                break;
            case "BRN":
                stability += 20;
                toxicity += 15;
                break;
        }
        
        // Ensure values stay within bounds
        stability = Math.max(0, Math.min(100, stability));
        toxicity = Math.max(0, Math.min(100, toxicity));
    }
    
    /**
     * Check if game is over (win or lose)
     */
    private boolean isGameOver() {
        return isWin() || isLose();
    }
    
    /**
     * Check win condition
     */
    private boolean isWin() {
        return stability >= 70 && stability <= 85 && toxicity < 20;
    }
    
    /**
     * Check lose condition
     */
    private boolean isLose() {
        return toxicity >= 100 || stability <= 0;
    }
    
    /**
     * Display game status message
     */
    private void displayGameMessage() {
        if (isWin()) {
            System.out.println("\n🎉 Congratulations! You've created the perfect potion!");
        } else if (isLose()) {
            if (toxicity >= 100) {
                System.out.println("\n💀 Your potion is too toxic! The cauldron explodes!");
            } else {
                System.out.println("\n💥 Your potion is too unstable! The cauldron shatters!");
            }
        } else {
            // Display status messages based on current values
            if (stability >= 60 && stability < 70) {
                System.out.println("\n🟡 Brewing... Getting close to stability!");
            } else if (stability >= 70 && stability <= 85) {
                System.out.println("\n🟢 Almost Stable! Keep the toxicity low!");
            } else if (stability > 85) {
                System.out.println("\n🔴 Too stable! Might be losing potency!");
            } else if (toxicity >= 50) {
                System.out.println("\n⚠️ Warning! Toxicity is getting dangerous!");
            } else if (toxicity >= 80) {
                System.out.println("\n🚨 Critical! Toxicity is extremely high!");
            } else {
                System.out.println("\n🟡 Brewing... Continue mixing ingredients!");
            }
        }
    }
    
    /**
     * End game and display final results
     */
    private void endGame() {
        System.out.println("\n🏁 Game Over!");
        System.out.println("=============");
        System.out.println("Final Stability: " + stability);
        System.out.println("Final Toxicity: " + toxicity);
        System.out.println("Steps Used: " + steps + "/" + maxSteps);
        
        if (isWin()) {
            System.out.println("\n🎉 VICTORY! You successfully created a stable potion!");
            System.out.println("The potion is perfect for magical use!");
        } else if (isLose()) {
            System.out.println("\n💀 DEFEAT! Your potion failed!");
            if (toxicity >= 100) {
                System.out.println("The potion was too toxic and dangerous!");
            } else if (stability <= 0) {
                System.out.println("The potion was too unstable and collapsed!");
            }
        } else {
            System.out.println("\n⏰ TIME'S UP! You ran out of steps!");
            System.out.println("Your potion is incomplete but not necessarily failed.");
            if (stability >= 60 && toxicity < 40) {
                System.out.println("It might still be usable with some adjustments!");
            }
        }
        
        System.out.println("\nThanks for playing Chef's Cauldron! 🧪");
    }
    
    /**
     * Main method to start the game
     */
    public static void main(String[] args) {
        PotionMixingGame game = new PotionMixingGame();
        game.play();
    }
}
