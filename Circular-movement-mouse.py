import pyautogui
import time

# Move mouse smoothly to (x=500, y=300) over 2 seconds
pyautogui.moveTo(500, 300, duration=2)

# Move the mouse relative to its current position
pyautogui.move(100, 0, duration=1)

# Example: small circular movement
for i in range(10):
    pyautogui.move(10, 10, duration=0.1)
    pyautogui.move(-10, 10, duration=0.1)
    pyautogui.move(-10, -10, duration=0.1)
    pyautogui.move(10, -10, duration=0.1)
