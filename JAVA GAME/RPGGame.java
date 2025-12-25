import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

// Base Character class that both players and enemies can inherit from
abstract class Character {
    protected String name;
    protected int maxHp;
    protected int currentHp;
    protected int attack;
    protected int defense;

    public Character(String name, int maxHp, int attack, int defense) {
        this.name = name;
        this.maxHp = maxHp;
        this.currentHp = maxHp;
        this.attack = attack;
        this.defense = defense;
    }

    public boolean isAlive() {
        return currentHp > 0;
    }

    public void takeDamage(int damage) {
        int actualDamage = Math.max(1, damage - defense);
        currentHp = Math.max(0, currentHp - actualDamage);
        System.out.println(name + " takes " + actualDamage + " damage!");
    }

    public abstract int calculateDamage();

    public String getStatus() {
        return name + " HP: " + currentHp + "/" + maxHp;
    }
}

// Player class with special abilities
class Player extends Character {
    private List<String> abilities;
    private int mana;
    private int maxMana;

    public Player(String name) {
        super(name, 100, 15, 5);
        this.abilities = new ArrayList<>();
        this.maxMana = 50;
        this.mana = maxMana;
        abilities.add("1. Normal Attack");
        abilities.add("2. Power Strike (10 mana)");
        abilities.add("3. Heal (15 mana)");
    }

    public void showAbilities() {
        System.out.println("\nAvailable Actions:");
        for (String ability : abilities) {
            System.out.println(ability);
        }
        System.out.println("Mana: " + mana + "/" + maxMana);
    }

    public void heal(int amount) {
        currentHp = Math.min(maxHp, currentHp + amount);
        System.out.println(name + " heals for " + amount + " HP!");
    }

    @Override
    public int calculateDamage() {
        return attack;
    }

    public boolean useMana(int cost) {
        if (mana >= cost) {
            mana -= cost;
            return true;
        }
        return false;
    }

    public void regenerateMana(int amount) {
        mana = Math.min(maxMana, mana + amount);
    }
}

// Enemy class with different types
class Enemy extends Character {
    private String type;
    private Random random;

    public Enemy(String type) {
        super(getEnemyName(type), 
            getEnemyStat(type, "hp"), 
            getEnemyStat(type, "attack"), 
            getEnemyStat(type, "defense"));
        this.type = type;
        this.random = new Random();
    }

    private static String getEnemyName(String type) {
        return switch (type) {
            case "goblin" -> "Goblin";
            case "orc" -> "Orc Warrior";
            case "dragon" -> "Ancient Dragon";
            default -> "Unknown Enemy";
        };
    }

    private static int getEnemyStat(String type, String stat) {
        return switch (type) {
            case "goblin" -> switch (stat) {
                case "hp" -> 50;
                case "attack" -> 10;
                case "defense" -> 3;
                default -> 0;
            };
            case "orc" -> switch (stat) {
                case "hp" -> 80;
                case "attack" -> 15;
                case "defense" -> 5;
                default -> 0;
            };
            case "dragon" -> switch (stat) {
                case "hp" -> 150;
                case "attack" -> 25;
                case "defense" -> 8;
                default -> 0;
            };
            default -> 0;
        };
    }

    @Override
    public int calculateDamage() {
        // Enemies have a chance to do critical damage
        return random.nextDouble() < 0.2 ? 
            (int)(attack * 1.5) : attack;
    }
}

// Main game class
public class RPGGame {
    private static final Scanner scanner = new Scanner(System.in);
    private static final Random random = new Random();

    public static void main(String[] args) {
        System.out.println("Welcome to the RPG Battle System!");
        System.out.print("Enter your character's name: ");
        String playerName = scanner.nextLine();
        
        Player player = new Player(playerName);
        List<String> enemyTypes = List.of("goblin", "orc", "dragon");
        int battlesWon = 0;

        while (player.isAlive()) {
            // Create a random enemy
            Enemy enemy = new Enemy(enemyTypes.get(random.nextInt(enemyTypes.size())));
            System.out.println("\nA " + enemy.name + " appears!");
            
            // Battle loop
            while (enemy.isAlive() && player.isAlive()) {
                System.out.println("\n" + player.getStatus());
                System.out.println(enemy.getStatus());
                
                // Player turn
                player.showAbilities();
                int choice = getPlayerChoice();
                
                // Process player action
                switch (choice) {
                    case 1 -> { // Normal attack
                        int damage = player.calculateDamage();
                        enemy.takeDamage(damage);
                    }
                    case 2 -> { // Power Strike
                        if (player.useMana(10)) {
                            int damage = (int)(player.calculateDamage() * 1.5);
                            enemy.takeDamage(damage);
                        } else {
                            System.out.println("Not enough mana!");
                        }
                    }
                    case 3 -> { // Heal
                        if (player.useMana(15)) {
                            player.heal(30);
                        } else {
                            System.out.println("Not enough mana!");
                        }
                    }
                }
                
                // Enemy turn
                if (enemy.isAlive()) {
                    int enemyDamage = enemy.calculateDamage();
                    player.takeDamage(enemyDamage);
                }
                
                // Regenerate some mana after each turn
                player.regenerateMana(5);
            }
            
            if (player.isAlive()) {
                battlesWon++;
                System.out.println("\nVictory! You've won " + battlesWon + " battles!");
                player.heal(20); // Heal some HP after victory
            }
        }
        
        System.out.println("\nGame Over! You won " + battlesWon + " battles!");
    }

    private static int getPlayerChoice() {
        while (true) {
            System.out.print("Choose your action (1-3): ");
            try {
                int choice = Integer.parseInt(scanner.nextLine());
                if (choice >= 1 && choice <= 3) {
                    return choice;
                }
            } catch (NumberFormatException e) {
                // Handle invalid input
            }
            System.out.println("Invalid choice. Please enter a number between 1 and 3.");
        }
    }
}
