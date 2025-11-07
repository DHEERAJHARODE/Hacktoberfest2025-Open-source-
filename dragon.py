#import modules
import random
import time

#create varibles
try_again = ""
cave_list = ["1","2","3","4"]
#process and display
def display_intro():
    print("""You are in the Kingdom of Dragons. In front of you,
            you see four caves. In cave 1, the dragon is friendly
            and will share his treasure with you. The dragon in cave 2
            is hungry and will eat you on sight.
            The dragon in cave 3 is friendly but doesn't have any treasure. And dragon in cave 4 is hungry and he got no treasure.""")

def choose_cave():
    cave = ""
    while cave not in cave_list:
        cave = input("Which cave will you go into(1/2/3/4) : ")
    return cave

def check_cave(choosen_cave):
    caves = ["Gobbles you down!","Smiles, but no treasure","Gobbles you since he even doesn't even have any treasure"]
    print("You approach the cave...")
    time.sleep(2)
    print("A large dragon jumps out in front of you! ")
    print("He opens his jaws and ...")
    time.sleep(2)
    friendly_cave = random.randint(1,4)
    if choosen_cave == str(friendly_cave):
        print("Gives you his treasure!")
    else:
        random_cave = random.choice(caves)
        print(str(random_cave))

while True:        
    display_intro()
    cave_number = choose_cave()
    check_cave(cave_number)
    try_again = input("Do you want to try again ? (Y for yes / N for no) : ")
    if try_again.lower() == "n":
        break
