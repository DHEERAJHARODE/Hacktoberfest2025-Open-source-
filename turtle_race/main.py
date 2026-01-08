from turtle import Turtle, Screen
import random

r = False
s = Screen()
s.setup(width=500 , height=500)
bet = s.textinput(title="make your bet" , prompt="which colour turtle you want:")
c=["blue","red","orange","yellow","green","purple"]
y1= [-70 , -40 , -10 , 20, 50 , 80 ]
b=[]
for x in range(0,6):
    t = Turtle(shape="turtle")
    t.color(c[x])
    t.penup()
    t.goto(x=-230, y=y1[x])
    b.append(t)
if bet:
    r = True
while r:

    for v in b:
         if v.xcor()> 230:
             r=False
             c1 = v.pencolor()
             if c1 == bet:
                 print("Won")
             else:
                 print(f"lost , winner is{c1}")
         d = random.randint(0,15)
         v.forward(d)








s.exitonclick()