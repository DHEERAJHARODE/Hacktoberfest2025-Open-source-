# furry gang

import random

num_turtles = 100
dead_turtles = 0
free_turtles = 0
max_time = 10

for time_step in range(0,max_time):

    for i in range(0,num_turtles):

        eaten = random.random()

        if eaten < 0.1:

            num_turtles = num_turtles - 1
            dead_turtles = dead_turtles + 1

        made_it_to_sea = random.random()

        if made_it_to_sea < time_step/max_time:

            num_turtles = num_turtles - 1
            free_turtles = free_turtles + 1

print('free turtles:', free_turtles)
print('eaten turtles:', dead_turtles)