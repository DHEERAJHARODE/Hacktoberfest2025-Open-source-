import random
from termcolor import colored

# Welcome and user input
print(colored("*" * 31, "green"))
print(colored("************HANGMAN************", "blue"))
print(colored("*" * 31, "green"))

name = input(colored("ENTER YOUR NAME TO PLAY HANGMAN: ", 'blue'))
print(colored(f"Hi {name}, welcome to HANGMAN!", 'red'))

# Choose difficulty level
while True:
    print(colored("Enter 1 for Easy Level", "yellow"))
    print(colored("Enter 2 for Hard Level", "yellow"))
    choice = input(colored("Enter your choice: ", 'blue'))
    if choice in ['1', '2']:
        break
    print(colored("Invalid input! Please enter 1 or 2.", "red"))

# Categories
categories = ['MOVIE', 'FRUIT', 'PROGRAMMING_LANGUAGE']
random.shuffle(categories)

category = categories[0]
if category == 'FRUIT':
    word_list = ['APPLE', 'MANGO', 'GUAVA', 'LITCHI', 'BANANA', 'ORANGE', 'COCONUT', 'BLACKPLUM', 'JACKFRUIT', 'PINEAPPLE', 'BERRY']
    print(colored("Guess the name of a fruit:", "green"))
elif category == 'MOVIE':
    word_list = ['RACE3', 'BAGHI2', 'RAID', 'PARI', 'PARMANU', 'PADMAN', 'PADMAVAT']
    print(colored("Guess the name of a movie (release 2018):", "magenta"))
else:
    word_list = ['ANDROID', 'C++', 'JAVA', 'PYTHON', 'SHIFT', 'JAVASCRIPT', 'PHP', 'HTML', 'KOTLIN', 'JSON', 'AJAX', 'JQUERY']
    print(colored("Guess the name of a programming language:", "blue"))

random.shuffle(word_list)
answer = word_list[0].upper()
display = ["_" for _ in answer]
length = len(answer)
max_chances = 12 if choice == '1' else 8  # Easy: 12 chances, Hard: 8 chances
used_letters = set()

print(colored(" ".join(display), "blue"))
print("\n")

# Game loop
chances = 0
while "_" in display and chances < max_chances:
    print(colored(f"Chances left: {max_chances - chances}", "yellow"))
    guess = input(colored("Guess a letter: ", "yellow")).upper()

    if len(guess) != 1 or not guess.isalpha():
        print(colored("Please enter a single alphabetic character.", "red"))
        continue

    if guess in used_letters:
        print(colored(f"You already guessed '{guess}'. Try another letter.", "red"))
        continue

    used_letters.add(guess)

    if guess in answer:
        for idx, char in enumerate(answer):
            if char == guess:
                display[idx] = guess
        print(colored("Correct guess!", "green"))
    else:
        print(colored("Wrong guess!", "red"))
        chances += 1

    print(colored(" ".join(display), "blue"))
    print("\n")

# Game result
if "_" not in display:
    print(colored(f"Congratulations {name}! You guessed the word successfully.", "green"))
else:
    print(colored(f"Sorry {name}, you lost. The word was: {answer}", "red"))
