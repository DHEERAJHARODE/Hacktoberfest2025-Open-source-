import random
i=0

#producing a random number between 0 and 100 , excluding 100
b=random.randint(0,100)

#initiating game with welcome message
print("Welcome to my game, here you have to guess a given number in maximum of 10 tries.\n")

#giving 10 chances to guess the randomly generated number
while(i<=10):
    
    #taking guess of user and comparing it with the number generated
    a=int(input("Enter your guess here: "))
    i=i+1
    
    # guess is correct
    if a==b:
        print("Congratulations you've won the game.")
        print("No. of guesses used: ",i)
        break
    
    # guessed number is greater than the number generated
    elif a>b:
        print("Your entered number is greater than the number. Try again")
        print("No. of guesses used: ",i)
        continue
    
    # guessed number is smaller than the number generated
    elif a<b:
        print("Your entered number is smaller than the number. Try again")
        print("No. of guesses used: ",i)
        continue

#number of guesses has exceeded 10 guesses    
else:
    print("GAME OVER the number was 21")




