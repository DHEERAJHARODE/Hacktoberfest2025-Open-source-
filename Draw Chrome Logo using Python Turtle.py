from turtle import *

radius=120
#heading position -150 is opposite of 150 degree angle
setheading(-150)
penup()
#-Red shape of the Chrome Logo
color("red")
begin_fill()
forward(radius)
pendown()
right(90) #set the angle to 90
circle(-radius, 120)
#forward distance is equal to 180
forward(radius*3**.5)
left(120)
#draw the circle angle 120 and radius of 240
circle(2*radius, 120)
left(60)
forward(radius*3**.5)
end_fill()

#-------------Green -------------

left(180)
color("green")
begin_fill()
forward(radius*3**.5)
left(120)
circle(2*radius, 120)
left(60)
forward(radius*3**.5)
left(180)
circle(-radius, 120)
end_fill()

#-------------Yellow -------------

left(180)
circle(radius,120)
color("yellow")
begin_fill()
circle(radius, 120)
right(180)
forward(radius*3**.5)
right(60)
circle(-2*radius, 120)
right(120)
forward(radius*3**.5)
end_fill()

#-------------Blue Circle-------------

penup()
left(98)
forward(radius/20)
setheading(60)
color("blue")
pendown()
begin_fill()
circle(distance(0,0))
end_fill()
hideturtle()

done()