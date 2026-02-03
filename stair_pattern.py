def draw_stair_pattern(rows):
    for i in range(1, rows + 1):
        for j in range(1, i + 1):
            print("*", end=" ")
        print()

try:
    num_rows = int(input("Enter the number of rows for the staircase: "))
    draw_stair_pattern(num_rows)
except ValueError:
    print("Invalid input. Please enter a valid integer.")
