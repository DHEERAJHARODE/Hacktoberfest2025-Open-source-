
# StopWatch Using Python⌚
Here's a breakdown of the Python stopwatch program implemented using tkinter for the graphical interface. The program includes Start, Stop, and Reset functionalities tocontrol the stopwatch.

## 🕹️Overview

This Python application is a stopwatch built using Tkinter, the standard GUI library for Python. The stopwatch displays time in the format HH:MM:SS, where:

Start begins counting the time.
Stop halts the counting.
Reset resets the counter to zero or an initial state.

## 🔗Code Breakdown
**Importing Libraries**

```python
import tkinter as Tkinter 
from datetime import datetime

```
➡️**tkinter:** Used for creating the graphical interface.\
➡️**datetime:** Used to format the time in HH:MM:SS using timestamps.

### 🌐Global Variables
```python
counter = 66600
running = False
```

➡️**counter:** Stores the current time in seconds, starting at 66600 (equivalent to 18:30:00).\
➡️**running:** A flag to indicate if the stopwatch is active or stopped.

### ⚙️Counter Function

```python
def counter_label(label): 
	def count(): 
		if running: 
			global counter 
			if counter==66600:			 
				display="Starting..."
			else:
				tt = datetime.fromtimestamp(counter)
				string = tt.strftime("%H:%M:%S")
				display=string 

			label['text']=display 
			label.after(1000, count) 
			counter += 1
	count()	 

```
\
➡️The **counter_label()** function defines an internal **count()** function that updates the label text every second.\
➡️If the counter equals 66600 (start state), it displays "Starting...".\
➡️Otherwise, it converts the counter into a timestamp and formats it into **HH:MM:SS** using **strftime()**.\
➡️**label.after(1000, count)** updates the label every 1000 milliseconds (1 second) and recursively calls itself to simulate a stopwatch.\

### 📌Start Function
```python
def Start(label): 
	global running 
	running=True
	counter_label(label) 
	start['state']='disabled'
	stop['state']='normal'
	reset['state']='normal'
```
➡️The **Start()** function changes the **running** state to**True** and calls **counter_label()** tostart the counter.\
➡️It disables the Start button and enables the Stop and Reset buttons toavoid multiple Start clicks.

### 🧭Stop Function

```python
def Stop(): 
	global running 
	start['state']='normal'
	stop['state']='disabled'
	reset['state']='normal'
	running = False
```
➡️The **Stop()** function halts the stopwatch by setting **running** to**False**.\
➡️The Stop button is disabled, while Start and Reset buttons are enabled.

### ⚙️Reset Function

```python
def Reset(label): 
	global counter 
	counter=66600
	if running==False:	 
		reset['state']='disabled'
		label['text']='Welcome!'
	else:			 
		label['text']='Starting...'
```

➡️The **Reset()** function resets the counter back to66600, which represents the initial time state.\
➡️If the stopwatch is stopped **(running==False)**, it disables the Reset button and displays "Welcome!".\
➡️If the stopwatch is running, it displays "Starting..." and resets the counter.

## 😎Creating GUI

```python
root = Tkinter.Tk() 
root.title("Stopwatch") 

root.minsize(width=250, height=70) 
label = Tkinter.Label(root, text="Welcome!", fg="black", font="Verdana 30 bold") 
label.pack() 
f = Tkinter.Frame(root)
start = Tkinter.Button(f, text='Start', width=6, command=lambda:Start(label)) 
stop = Tkinter.Button(f, text='Stop',width=6,state='disabled', command=Stop) 
reset = Tkinter.Button(f, text='Reset',width=6, state='disabled', command=lambda:Reset(label)) 
f.pack(anchor = 'center',pady=5)
start.pack(side="left") 
stop.pack(side ="left") 
reset.pack(side="left") 
root.mainloop()
```

➡️A **Tk()** root window is created and titled "Stopwatch".\
➡️The label is initialized with "Welcome!" and displays the time.\
➡️Three buttons (Start, Stop, Reset) are created, each bound to their respective functions. Initially, Stop and Reset are disabled.\
➡️The buttons are packed into a frame and displayed in the center of the window.\

## 📺Running the Program
T➡️run the stopwatch, simply execute the script. The GUI will open with the label "Welcome!" and three buttons:

➡️Start: Begins counting the time.\
➡️Stop: Pauses the stopwatch at the current time.\
➡️Reset: Resets the stopwatch to the initial state ("Welcome!" when stopped or "Starting..." when running).\

# 🤔Possible Enhancements:
➡️**Lap Functionality:** Add a button to record lap times.\
➡️**Save/Load:** Add the ability to save time to a file.\
➡️ **Customization:** Allow the user to set the initial time or countdown instead of a stopwatch.\

## 🤖Authors

- [@SuvamDas](https://www.github.com/vamus092)


## 🏛️Badges

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)



## 🫱🏼‍🫲🏼Contributing

Contributions are always welcome!

See `contributing.md` for ways to get started.
Please adhere to this project's `code of conduct`.\
You can visit my profile and other projects at https://github.com/vamus092


## 🚫License

[MIT](https://choosealicense.com/licenses/mit/)


## CODE
```PYTHON
# Python program to illustrate a stopwatch 
# using Tkinter 
# importing the required libraries 
import tkinter as Tkinter 
from datetime import datetime
counter = 66600
running = False
def counter_label(label): 
	def count(): 
		if running: 
			global counter 

			# To manage the initial delay. 
			if counter==66600:			 
				display="Starting..."
			else:
				tt = datetime.fromtimestamp(counter)
				string = tt.strftime("%H:%M:%S")
				display=string 

			label['text']=display # Or label.config(text=display) 

			# label.after(arg1, arg2) delays by 
			# first argument given in milliseconds 
			# and then calls the function given as second argument. 
			# Generally like here we need to call the 
			# function in which it is present repeatedly. 
			# Delays by 1000ms=1 seconds and call count again. 
			label.after(1000, count) 
			counter += 1

	# Triggering the start of the counter. 
	count()	 

# start function of the stopwatch 
def Start(label): 
	global running 
	running=True
	counter_label(label) 
	start['state']='disabled'
	stop['state']='normal'
	reset['state']='normal'

# Stop function of the stopwatch 
def Stop(): 
	global running 
	start['state']='normal'
	stop['state']='disabled'
	reset['state']='normal'
	running = False

# Reset function of the stopwatch 
def Reset(label): 
	global counter 
	counter=66600

	# If rest is pressed after pressing stop. 
	if running==False:	 
		reset['state']='disabled'
		label['text']='Welcome!'

	# If reset is pressed while the stopwatch is running. 
	else:			 
		label['text']='Starting...'

root = Tkinter.Tk() 
root.title("Stopwatch") 

# Fixing the window size. 
root.minsize(width=250, height=70) 
label = Tkinter.Label(root, text="Welcome!", fg="black", font="Verdana 30 bold") 
label.pack() 
f = Tkinter.Frame(root)
start = Tkinter.Button(f, text='Start', width=6, command=lambda:Start(label)) 
stop = Tkinter.Button(f, text='Stop',width=6,state='disabled', command=Stop) 
reset = Tkinter.Button(f, text='Reset',width=6, state='disabled', command=lambda:Reset(label)) 
f.pack(anchor = 'center',pady=5)
start.pack(side="left") 
stop.pack(side ="left") 
reset.pack(side="left") 
root.mainloop()

```
