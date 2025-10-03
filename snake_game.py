import turtle
import time
import random
from dataclasses import dataclass
from typing import List, Tuple

@dataclass
class GameConfig:
    """Configuration class for game settings"""
    WINDOW_WIDTH: int = 800
    WINDOW_HEIGHT: int = 800
    GRID_SIZE: int = 20
    INITIAL_DELAY: float = 0.1
    SPEED_INCREMENT: float = 0.001
    SCORE_INCREMENT: int = 10
    BORDER_BUFFER: int = 20

class SnakeGame:
    def __init__(self):
        self.config = GameConfig()
        self.score = 0
        self.high_score = 0
        self.delay = self.config.INITIAL_DELAY
        self.running = True
        self.segments: List[turtle.Turtle] = []
        
        self.setup_window()
        self.setup_snake()
        self.setup_food()
        self.setup_ui()
        self.setup_controls()
    
    def setup_window(self):
        """Initialize the game window"""
        self.wn = turtle.Screen()
        self.wn.title("🐍 Modern Snake Game")
        self.wn.bgcolor("black")
        self.wn.setup(
            width=self.config.WINDOW_WIDTH, 
            height=self.config.WINDOW_HEIGHT
        )
        self.wn.tracer(0)
        
        # Calculate game boundaries
        self.boundary_x = (self.config.WINDOW_WIDTH // 2) - self.config.BORDER_BUFFER
        self.boundary_y = (self.config.WINDOW_HEIGHT // 2) - self.config.BORDER_BUFFER
    
    def setup_snake(self):
        """Initialize the snake head"""
        self.head = turtle.Turtle()
        self.head.shape("square")
        self.head.color("#00ff00")  # Bright green
        self.head.penup()
        self.head.goto(0, 0)
        self.head.direction = "stop"
        
        # Add initial segments
        for _ in range(2):
            self.add_segment()
    
    def setup_food(self):
        """Initialize the food"""
        self.food = turtle.Turtle()
        self.food.shape("circle")
        self.food.color("#ff4444")  # Bright red
        self.food.penup()
        self.food.goto(0, 100)
    
    def setup_ui(self):
        """Initialize the score display"""
        self.pen = turtle.Turtle()
        self.pen.speed(0)
        self.pen.color("white")
        self.pen.penup()
        self.pen.hideturtle()
        self.pen.goto(0, self.config.WINDOW_HEIGHT // 2 - 50)
        self.update_display()
    
    def setup_controls(self):
        """Set up keyboard controls"""
        self.wn.listen()
        # Arrow keys
        self.wn.onkeypress(self.go_up, "Up")
        self.wn.onkeypress(self.go_down, "Down")
        self.wn.onkeypress(self.go_left, "Left")
        self.wn.onkeypress(self.go_right, "Right")
        # WASD keys
        self.wn.onkeypress(self.go_up, "w")
        self.wn.onkeypress(self.go_down, "s")
        self.wn.onkeypress(self.go_left, "a")
        self.wn.onkeypress(self.go_right, "d")
        # Game controls
        self.wn.onkeypress(self.toggle_pause, "p")
        self.wn.onkeypress(self.restart_game, "r")
        self.wn.onkeypress(self.quit_game, "Escape")
    
    def go_up(self):
        if self.head.direction != "down":
            self.head.direction = "up"
    
    def go_down(self):
        if self.head.direction != "up":
            self.head.direction = "down"
    
    def go_left(self):
        if self.head.direction != "right":
            self.head.direction = "left"
    
    def go_right(self):
        if self.head.direction != "left":
            self.head.direction = "right"
    
    def toggle_pause(self):
        """Toggle game pause state"""
        if self.head.direction == "pause":
            self.head.direction = "right"  # Resume with right direction
        else:
            self.head.direction = "pause"
    
    def restart_game(self):
        """Restart the game"""
        self.score = 0
        self.delay = self.config.INITIAL_DELAY
        self.reset_snake()
        self.update_display()
    
    def quit_game(self):
        """Exit the game"""
        self.running = False
    
    def move(self):
        """Move the snake in the current direction"""
        if self.head.direction == "pause":
            return
            
        # Move body segments
        for i in range(len(self.segments)-1, 0, -1):
            x = self.segments[i-1].xcor()
            y = self.segments[i-1].ycor()
            self.segments[i].goto(x, y)
        
        # Move first segment to head position
        if len(self.segments) > 0:
            x = self.head.xcor()
            y = self.head.ycor()
            self.segments[0].goto(x, y)
        
        # Move head based on direction
        if self.head.direction == "up":
            self.head.sety(self.head.ycor() + self.config.GRID_SIZE)
        elif self.head.direction == "down":
            self.head.sety(self.head.ycor() - self.config.GRID_SIZE)
        elif self.head.direction == "left":
            self.head.setx(self.head.xcor() - self.config.GRID_SIZE)
        elif self.head.direction == "right":
            self.head.setx(self.head.xcor() + self.config.GRID_SIZE)
    
    def add_segment(self):
        """Add a new segment to the snake"""
        new_segment = turtle.Turtle()
        new_segment.shape("square")
        # Gradient color from head to tail
        color_intensity = max(50, 255 - len(self.segments) * 15)
        new_segment.color(f"#00{color_intensity:02x}00")
        new_segment.penup()
        self.segments.append(new_segment)
    
    def check_collision(self) -> bool:
        """Check for collisions with walls or self"""
        # Wall collision
        if (abs(self.head.xcor()) > self.boundary_x or 
            abs(self.head.ycor()) > self.boundary_y):
            return True
        
        # Self collision
        for segment in self.segments:
            if self.head.distance(segment) < self.config.GRID_SIZE - 5:
                return True
        
        return False
    
    def check_food_collision(self) -> bool:
        """Check if snake head collides with food"""
        return self.head.distance(self.food) < self.config.GRID_SIZE
    
    def spawn_food(self):
        """Spawn food at a random position"""
        x = random.randint(
            -self.boundary_x + self.config.GRID_SIZE, 
            self.boundary_x - self.config.GRID_SIZE
        )
        y = random.randint(
            -self.boundary_y + self.config.GRID_SIZE,
            self.boundary_y - self.config.GRID_SIZE
        )
        # Round to grid
        x = round(x / self.config.GRID_SIZE) * self.config.GRID_SIZE
        y = round(y / self.config.GRID_SIZE) * self.config.GRID_SIZE
        self.food.goto(x, y)
    
    def reset_snake(self):
        """Reset snake to initial state"""
        self.head.goto(0, 0)
        self.head.direction = "stop"
        
        # Remove existing segments
        for segment in self.segments:
            segment.hideturtle()
        self.segments.clear()
        
        # Add initial segments
        for _ in range(2):
            self.add_segment()
    
    def update_display(self):
        """Update the score display"""
        self.pen.clear()
        self.pen.write(
            f"Score: {self.score}  High Score: {self.high_score}  Speed: {1/self.delay:.1f}x",
            align="center", 
            font=("Arial", 16, "bold")
        )
    
    def game_over(self):
        """Handle game over state"""
        self.pen.goto(0, 0)
        self.pen.write(
            "GAME OVER\nPress R to restart\nESC to quit",
            align="center", 
            font=("Arial", 24, "bold")
        )
        time.sleep(1)
        
        if self.score > self.high_score:
            self.high_score = self.score
        
        self.restart_game()
        self.pen.goto(0, self.config.WINDOW_HEIGHT // 2 - 50)
    
    def run(self):
        """Main game loop"""
        try:
            while self.running:
                self.wn.update()
                
                if self.check_collision():
                    self.game_over()
                    continue
                
                if self.check_food_collision():
                    self.spawn_food()
                    self.add_segment()
                    self.score += self.config.SCORE_INCREMENT
                    self.delay = max(0.05, self.delay - self.config.SPEED_INCREMENT)
                    self.update_display()
                
                self.move()
                time.sleep(self.delay)
                
        except turtle.Terminator:
            pass
        finally:
            self.wn.bye()

def main():
    """Main function to start the game"""
    game = SnakeGame()
    game.run()

if __name__ == "__main__":
    main()
