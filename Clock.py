import pygame
import math
import time

# Initialize Pygame
pygame.init()

# Constants
WIDTH, HEIGHT = 400, 400
CLOCK_RADIUS = 150
CENTER = (WIDTH // 2, HEIGHT // 2)
SECOND_HAND_LENGTH = CLOCK_RADIUS - 20
MINUTE_HAND_LENGTH = CLOCK_RADIUS - 30
HOUR_HAND_LENGTH = CLOCK_RADIUS - 50

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Create the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Analog Clock")

# Main game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()

    # Get the current time
    current_time = time.localtime()
    seconds = current_time.tm_sec
    minutes = current_time.tm_min
    hours = current_time.tm_hour % 12

    # Clear the screen
    screen.fill(WHITE)

    # Draw clock face
    pygame.draw.circle(screen, BLACK, CENTER, CLOCK_RADIUS, 2)

    # Calculate angles for hour, minute, and second hands
    second_angle = math.radians(6 * seconds - 90)
    minute_angle = math.radians(6 * minutes - 90)
    hour_angle = math.radians(30 * hours - 90)

    # Draw second hand
    second_x = CENTER[0] + int(SECOND_HAND_LENGTH * math.cos(second_angle))
    second_y = CENTER[1] + int(SECOND_HAND_LENGTH * math.sin(second_angle))
    pygame.draw.line(screen, BLACK, CENTER, (second_x, second_y), 2)

    # Draw minute hand
    minute_x = CENTER[0] + int(MINUTE_HAND_LENGTH * math.cos(minute_angle))
    minute_y = CENTER[1] + int(MINUTE_HAND_LENGTH * math.sin(minute_angle))
    pygame.draw.line(screen, BLACK, CENTER, (minute_x, minute_y), 4)

    # Draw hour hand
    hour_x = CENTER[0] + int(HOUR_HAND_LENGTH * math.cos(hour_angle))
    hour_y = CENTER[1] + int(HOUR_HAND_LENGTH * math.sin(hour_angle))
    pygame.draw.line(screen, BLACK, CENTER, (hour_x, hour_y), 6)

    pygame.display.flip()
    pygame.time.delay(1000)  # Update the clock every second
