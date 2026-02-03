# plug in the graphics library
from tkinter import *
# connect modules that are responsible for time and random numbers
import time
import random
# create a new object - a window with a game field. In our case, the window variable is called tk, and we made it from the class Tk() - it is in the graphical library. 
tk = Tk()
# make window title - Games using the title object property
tk.title('Game')
# don't change the size of the window, for this we use the resizable property 
tk.resizable(0, 0)
# place our game window above the other windows on your computer so that other windows cannot overshadow it. Try it :)
tk.wm_attributes('-topmost', 1)
# create a new canvas - 400 by 500 pixels, where we will draw the game
canvas = Canvas(tk, width=500, height=400, highlightthickness=0)
# tell the canvas that each visible element will have its own separate coordinates 
canvas.pack()
# update the canvas window
tk.update()
# Describe the Ball class that will be responsible for the ball 
class Ball:
    # constructor - it is called when a new object is created based on this class
    def __init__(self, canvas, paddle, score, color):
        # set the parameters of the object, which are passed to us in brackets at the moment of creation
        self.canvas = canvas
        self.paddle = paddle
        self.score = score
        # the color was needed for us to paint the whole ball with it
        # here appears a new id property, which stores the internal name of the ball
        # and with the command create_oval we create a circle with a radius of 15 pixels and paint it with the desired color.
        self.id = canvas.create_oval(10,10, 25, 25, fill=color)
        # place the ball in a point with coordinates 245,100
        self.canvas.move(self.id, 245, 100)
        # set a list of possible directions for the start
        starts = [-2, -1, 1, 2]
        # we mix it up 
        random.shuffle(starts)
        # select the first one of the mixed - it will be the ball motion vector
        self.x = starts[0]
        # at the very beginning it always falls down, so we reduce the value in the y axis.
        self.y = -2
        # the ball will know its height and width
        self.canvas_height = self.canvas.winfo_height()
        self.canvas_width = self.canvas.winfo_width()
        # a property that is responsible for whether or not the ball has reached the bottom. Until it has reached, the value is False
        self.hit_bottom = False
    # process the touch of the platform, for this we get 4 coordinates of the ball in the pos variable (left upper and right lower points)
    def hit_paddle(self, pos):
        # get platform encodings through paddle object (platform)
        paddle_pos = self.canvas.coords(self.paddle.id)
        # if the touch coordinates are the same as the platform coordinates
        if pos[2] >= paddle_pos[0] and pos[0] <= paddle_pos[2]:
            if pos[3] >= paddle_pos[1] and pos[3] <= paddle_pos[3]:
                # increase the count (the handler of this event will be described below)
                self.score.hit()
                # return the tag that we successfully touched
                return True
        # return False - there was no touch #
        return False
    # the method that is responsible for the ball movement
    def draw(self):
        # move the ball to a given vector x and y
        self.canvas.move(self.id, self.x, self.y)
        # memorize the new coordinates of the ball
        pos = self.canvas.coords(self.id)
        # if the ball falls from above  
        if pos[1] <= 0:
            # set the drop at the next step = 2
            self.y = 2
        # if the ball at the bottom right corner touched the bottom #
        if pos[3] >= self.canvas_height:
            # note this in a separate variable
            self.hit_bottom = True
            # display message and number of points
            canvas.create_text(250, 120, text='You lost', font=('Courier', 30), fill='red')
        # if there was a touch of the platform
        if self.hit_paddle(pos) == True:
            # send the ball upstairs
            self.y = -2
        # if you touched the left wall
        if pos[0] <= 0:
            # moving right
            self.x = 2
        # if you touched the right wall
        if pos[2] >= self.canvas_width:
            # moving to the left
            self.x = -2
# Describe the Paddle class that is responsible for the platforms
class Paddle:
    # constructor
    def __init__(self, canvas, color):
        # canvas means that the platform will be drawn on our original canvas
        self.canvas = canvas
        # create a rectangular platform 10 by 100 pixels, paint it with the selected color and get its internal name 
        self.id = canvas.create_rectangle(0, 0, 100, 10, fill=color)
        # specify a list of possible starting positions of the platform
        start_1 = [40, 60, 90, 120, 150, 180, 200]
        # we mix them up
        random.shuffle(start_1)
        # choose the first of the mixed
        self.starting_point_x = start_1[0]
        # move the platform to the starting position
        self.canvas.move(self.id, self.starting_point_x, 300)
        # as long as the platform does not move anywhere, so no changes in the x axis
        self.x = 0
        # the platform will know its width
        self.canvas_width = self.canvas.winfo_width()
        # we set a click handler
        # if right arrow is pressed - turn_right() method is executed.
        self.canvas.bind_all('<KeyPress-Right>', self.turn_right)
        # if the left arrow is turn_left()
        self.canvas.bind_all('<KeyPress-Left>', self.turn_left)
        # until the platform moves, so we wait
        self.started = False
        # as soon as the player presses Enter, everything starts
        self.canvas.bind_all('<KeyPress-Return>', self.start_game)
    # moving to the right 
    def turn_right(self, event):
        # let's shift to the right by 2 pixels in the x axis
        self.x = 2
    # moving to the left
    def turn_left(self, event):
        # we will move to the left by 2 pixels in the x axis
        self.x = -2
    # the game begins
    def start_game(self, event):
        # change the value of the variable that is responsible for starting the platform movement
        self.started = True
    # the method that is responsible for the platform movement
    def draw(self):
        # move our platform by a specified number of pixels
        self.canvas.move(self.id, self.x, 0)
        # we get the coordinates of the canvas
        pos = self.canvas.coords(self.id)
        # if we're stuck on the left border 
        if pos[0] <= 0:
            # we stop
            self.x = 0
        # if you're stuck on the right side 
        elif pos[2] >= self.canvas_width:
            # stop
            self.x = 0
# Describe the Score class that is responsible for displaying accounts
class Score:
    # constructor
    def __init__(self, canvas, color):
        # at the very beginning the score is zero
        self.score = 0
        # we'll use our canvas
        self.canvas = canvas
        # create an inscription that shows the current account, make it need colors and remember the internal name of this inscription
        self.id = canvas.create_text(450, 10, text=self.score, font=('Courier', 15), fill=color)
    # process the touch of the platform
    def hit(self):
        # we increase the account by one
        self.score += 1
        # writing a new count value 
        self.canvas.itemconfig(self.id, text=self.score)
# create an object - Black account 
score = Score(canvas, 'Black')
# create an object - Black platform
paddle = Paddle(canvas, 'Black')
# create an object - Red ball 
ball = Ball(canvas, paddle, score, 'Red')
# until the ball touched the bottom # 
while not ball.hit_bottom:
    # if the game starts and the platform can move
    if paddle.started == True:
        # move the ball
        ball.draw()
        # moving the platform
        paddle.draw()
    # update our playing field so that everything you need is finished drawing
    tk.update_idletasks()
    # update the playing field and make sure that everything that should have been done is done
    tk.update()
    # we stop for one hundredth of a second to make the movement of the elements look smoothly
    time.sleep(0.008)
# if the program has reached here, then the ball has touched the bottom. We wait 3 seconds for the player to read the final inscription, and we finish the game.
time.sleep(3)