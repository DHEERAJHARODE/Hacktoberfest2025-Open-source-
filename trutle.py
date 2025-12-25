import turtle
from turtle import Turtle,Screen
import random



screen_time=Screen()
screen_time.bgcolor("black")



timmy_turtle=Turtle()
turtle.colormode(255)



color=["blue","pink","yellow","orange"]
directions=[0,90,180,270]

#
#
def random_1():
    r=random.randint(0,255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    color= (r,g,b)
    return color

#
# for i in range (500):
#     timmy_turtle.pensize(15)
#     timmy_turtle.forward(40)
#     timmy_turtle.setheading(random.choice(directions))
#     timmy_turtle.pencolor(random_1())




def how_much(param):



    for i in range(int(360/param)):
        timmy_turtle.color(random_1())
        timmy_turtle.speed(100)
        timmy_turtle.circle(50)
        a=timmy_turtle.heading()

        timmy_turtle.setheading(a+param)

how_much(5)





#
# var1=forward()
# var2=backward()
# var3=left()
# var4=right()
#
# waduu=[var1,var2,var3,var4]
#
#
# end=False
# while end==False:
#     random.choice(waduu)
#     end=False

screen_time.exitonclick()
