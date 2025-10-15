import random
import time

# Define potions and their ingredient combinations
potions = {
    "Healing Potion": {"red herb", "blue herb", "water"},
    "Mana Potion": {"blue herb", "crystal shard", "water"},
    "Strength Potion": {"yellow herb", "bear claw", "water"},
    "Invisibility Potion": {"ghost mushroom", "shadow dust", "mist"},
    "Speed Potion": {"quickroot", "windleaf", "water"}
}

ingredients = set()
for vals in potions.values():
    ingredients |= vals

def play_potion_game():
    print("Welcome to the Potion Mixing Game!")
    print("Available ingredients:")
    for ing in sorted(ingredients):
        print(f"- {ing}")

    potion_name, correct_mix = random.choice(list(potions.items()))
    print(f"\nYour task: **Create a {potion_name}**")
    print("Mix the correct 3 ingredients for this potion.")

    tries = 3
    while tries > 0:
        print(f"\nAttempts remaining: {tries}")
        user_mix = set()
        for i in range(1, 4):
            chosen = input(f"Enter ingredient #{i}: ").strip().lower()
            user_mix.add(chosen)
        time.sleep(1)
        if user_mix == set(map(str.lower, correct_mix)):
            print("Congratulations! You created the correct potion!")
            break
        else:
            print("That mix didn’t create the correct potion.")
            missed = correct_mix - user_mix
            print("Ingredients you missed:", ", ".join(missed))
        tries -= 1
    else:
        print("\nOut of attempts! The correct mix was:", ", ".join(correct_mix))

play_potion_game()
