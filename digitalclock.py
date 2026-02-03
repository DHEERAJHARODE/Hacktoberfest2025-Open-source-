"""
Created on Wed Oct 12 19:45:45 2022
@author: Mona-1818
""" 

from tkinter import Tk, Label  
import time 

def presenttime():
    t = time.strftime("%I:%M:%S %p") 
    clock.config(text = t) 
    clock.after(100, presenttime)  
    
root = Tk()
root.title("Digital Clock") 
clock = Label(root, font=('Sans-Serif', 100), bg = "black", fg = "grey") 
clock.pack()  
presenttime() 
root.mainloop() 
