import random

# Define possible ingredients and effects
ingredients = ["Mandrake Root", "Unicorn Hair", "Dragon Scale", "Phoenix Feather", "Moonstone"]
effects = {
    "Healing": ["Mandrake Root", "Moonstone"],
    "Strength": ["Dragon Scale", "Unicorn Hair"],
    "Fire Resistance": ["Dragon Scale", "Phoenix Feather"],
    "Mana Boost": ["Moonstone", "Phoenix Feather"]
}

# Player inventory
inventory = {
    "Mandrake Root": 3,
    "Unicorn Hair": 2,
    "Dragon Scale": 1,
    "Phoenix Feather": 1,
    "Moonstone": 2
}

# Function to mix ingredients
def mix_potion():
    print("\nYour Inventory:")
    for item, count in inventory.items():
        print(f"{item}: {count}")

    ing1 = input("\nChoose first ingredient: ").strip()
    ing2 = input("Choose second ingredient: ").strip()

    if ing1 not in ingredients or ing2 not in ingredients:
        print("Invalid ingredient! Try again.")
        return
    if inventory.get(ing1, 0) <= 0 or inventory.get(ing2, 0) <= 0:
        print("You don't have enough of that ingredient!")
        return

    # Reduce inventory
    inventory[ing1] -= 1
    inventory[ing2] -= 1

    # Determine potion effect
    possible_effects = []
    for effect, ing_list in effects.items():
        if ing1 in ing_list and ing2 in ing_list:
            possible_effects.append(effect)

    if possible_effects:
        potion = random.choice(possible_effects)
        print(f"\nYou brewed a potion of {potion}! 🧪")
    else:
        print("\nThe potion fizzled... Nothing happened 😢")

# Game loop
def game():
    print("Welcome to Python Potion Mixing Game! 🧙‍♂️")
    while True:
        action = input("\nWhat do you want to do? (mix/exit): ").strip().lower()
        if action == "mix":
            mix_potion()
        elif action == "exit":
            print("Thanks for playing! Goodbye.")
            break
        else:
            print("Invalid action. Type 'mix' to brew or 'exit' to quit.")

# Start the game
game()
