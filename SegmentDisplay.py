#Controlling a 7-segment display using Python
import RPi.GPIO as GPIO
import time

# Define the GPIO pins for the segments (a - g) and the common cathode/anode
segments = [17, 27, 22, 10, 9, 11, 5]
common = 6

# Set up GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(segments, GPIO.OUT)
GPIO.setup(common, GPIO.OUT)

# Define the mapping for each digit (0 - 9)
numbers = {
    0: [1, 1, 1, 1, 1, 1, 0],
    1: [0, 1, 1, 0, 0, 0, 0],
    2: [1, 1, 0, 1, 1, 0, 1],
    3: [1, 1, 1, 1, 0, 0, 1],
    4: [0, 1, 1, 0, 0, 1, 1],
    5: [1, 0, 1, 1, 0, 1, 1],
    6: [1, 0, 1, 1, 1, 1, 1],
    7: [1, 1, 1, 0, 0, 0, 0],
    8: [1, 1, 1, 1, 1, 1, 1],
    9: [1, 1, 1, 1, 0, 1, 1]
}

try:
    while True:
        for digit in range(10):
            # Activate the common cathode/anode
            GPIO.output(common, GPIO.HIGH)
            # Set the segments based on the number
            for i in range(7):
                GPIO.output(segments[i], numbers[digit][i])
            # Display for a short period of time
            time.sleep(1)
            # Deactivate the common cathode/anode
            GPIO.output(common, GPIO.LOW)
            # Clear segments
            for i in range(7):
                GPIO.output(segments[i], GPIO.LOW)

except KeyboardInterrupt:
    GPIO.cleanup()
