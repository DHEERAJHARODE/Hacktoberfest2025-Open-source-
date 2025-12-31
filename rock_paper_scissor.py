import random


def start():
    play = input("Do you wanna play game :").lower()
    if play != "yes":
        exit()


def logic():
    play = int(input("How many time you want to play :"))
    i = 1
    computer_score=0
    your_score=0
    while i <= play:
        list1 = ['rock', 'paper', 'scissor']
        choice = random.choice(list1)
        option = input("Enter your option :").lower()
        computer_option = choice
        
        if(computer_option == option):
            print("Draw")
        elif (computer_option == 'rock' and option == 'paper'):
            print("You win")
            your_score+=1
        elif(computer_option == 'rock' and option == 'scissor'):
            print("computer wins")
            computer_score+=1
        elif(computer_option == 'paper' and option == 'scissor'):
            print("You win")
            your_score+=1
        elif(computer_option == 'paper' and option == 'rock'):
            print("Computer win")
            computer_score+=1
        elif(computer_option == 'scissor' and option == 'paper'):
            print("computer wins")
            computer_score+=1
        elif(computer_option == 'scissor' and option == 'rock'):
            print("You wins")
            your_score+=1
        print(computer_option)
        i+=1
    print("=================Final-score-Board======================")
    if(computer_score==your_score):
        print("Drawwwww")
    elif(computer_score>your_score):
        print(f"Computer wins in {play} round")
    else:
        print(f"You wins in {play} round")

start()
logic()
