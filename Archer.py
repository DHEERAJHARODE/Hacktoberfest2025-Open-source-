class Archer:
	# init function to set the object variables and load the image
	def __init__(self, width, height, speed):
		self.width = width
		self.height = height
		self.speed = speed

		self.archer = pygame.transform.scale(
			pygame.image.load(archerPath), (self.width, self.height))
		self.archerRect = self.archer.get_rect()

		# Default position
		self.archerRect.x, self.archerRect.y = 100, HEIGHT//2

	# Method to render the archer on the screen
	def display(self):
		screen.blit(self.archer, self.archerRect)

	# Method to update the archer position
	def update(self, xFac, yFac):
		self.archerRect.x += xFac*self.speed
		self.archerRect.y += yFac*self.speed

		# Constraints to maintain the archer in the left half of the screen
		if self.archerRect.x <= 0:
			self.archerRect.x = 0
		elif self.archerRect.x >= WIDTH//2 - self.archerRect.w:
			self.archerRect.x = WIDTH//2 - self.archerRect.w
		if self.archerRect.y <= 0:
			self.archerRect.y = 0
		elif self.archerRect.y >= HEIGHT-self.archerRect.h:
			self.archerRect.y = HEIGHT - self.archerRect.h
