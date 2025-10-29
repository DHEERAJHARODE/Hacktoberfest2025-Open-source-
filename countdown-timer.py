import time

seconds = int(input("Enter countdown time in seconds: "))
for i in range(seconds, 0, -1):
    print(i, end="\r")
    time.sleep(1)
print("Time’s up!")
