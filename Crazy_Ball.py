# Smriti Kshatriya

**Course / Year:** TE IT, KBT College of Engineering  
**About me:** I love building web apps and learning full-stack development.  
**Skills:** HTML, CSS, JavaScript, Python, Git, GitHub  
**My Contribution:** Adding a small Crazy ball code of python.  
**GitHub:** https://github.com/SmritiKshatriya
**LinkedIn:** https://www.linkedin.com/in/smriti-kshatriya-80b521289?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app 


import os
import time
import random

# Terminal size (approx for most systems)
WIDTH = 40
HEIGHT = 10

# Ball position and velocity
x, y = random.randint(1, WIDTH-2), random.randint(1, HEIGHT-2)
vx, vy = 1, 1  # velocity

def clear():
    # Clears terminal screen
    os.system('cls' if os.name == 'nt' else 'clear')

while True:
    clear()

    # Draw the frame
    for row in range(HEIGHT):
        for col in range(WIDTH):
            if row == y and col == x:
                print("⚽", end="")   # Ball emoji
            else:
                print(" ", end="")
        print()

    # Update ball position
    x += vx
    y += vy

    # Bounce off walls
    if x <= 0 or x >= WIDTH-1:
        vx *= -1
    if y <= 0 or y >= HEIGHT-1:
        vy *= -1

    time.sleep(0.1)  # control speed
