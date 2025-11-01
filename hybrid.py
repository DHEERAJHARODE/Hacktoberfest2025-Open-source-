import heapq
from collections import deque

# Manhattan distance heuristic
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

# A* + BFS Hybrid Algorithm
def hybrid_a_star_bfs(grid, start, goal, bfs_interval=5):
    rows, cols = len(grid), len(grid[0])
    open_set = []
    heapq.heappush(open_set, (0, start))  # (f_score, node)
    
    g_score = {start: 0}
    came_from = {}
    steps = 0

    while open_set:
        # Every 'bfs_interval' steps, do a small BFS burst for local optimization
        if steps % bfs_interval == 0 and steps != 0:
            bfs_expand(grid, open_set, g_score, came_from, goal)
        
        _, current = heapq.heappop(open_set)
        steps += 1

        if current == goal:
            return reconstruct_path(came_from, current)
        
        for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            neighbor = (current[0] + dx, current[1] + dy)
            if 0 <= neighbor[0] < rows and 0 <= neighbor[1] < cols and grid[neighbor[0]][neighbor[1]] == 0:
                tentative_g = g_score[current] + 1
                if neighbor not in g_score or tentative_g < g_score[neighbor]:
                    g_score[neighbor] = tentative_g
                    f = tentative_g + heuristic(neighbor, goal)
                    heapq.heappush(open_set, (f, neighbor))
                    came_from[neighbor] = current
    return None

# BFS burst to enhance exploration
def bfs_expand(grid, open_set, g_score, came_from, goal, radius=2):
    local_nodes = [n for _, n in open_set[:]]
    new_nodes = deque()
    for node in local_nodes:
        for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            neighbor = (node[0] + dx, node[1] + dy)
            if (0 <= neighbor[0] < len(grid) and 0 <= neighbor[1] < len(grid[0]) 
                and grid[neighbor[0]][neighbor[1]] == 0):
                if neighbor not in g_score:
                    g_score[neighbor] = g_score[node] + 1
                    came_from[neighbor] = node
                    f = g_score[neighbor] + heuristic(neighbor, goal)
                    heapq.heappush(open_set, (f, neighbor))

def reconstruct_path(came_from, current):
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.append(current)
    return path[::-1]

# Example usage
if __name__ == "__main__":
    grid = [
        [0,0,0,0,0],
        [1,1,0,1,0],
        [0,0,0,1,0],
        [0,1,1,0,0],
        [0,0,0,0,0]
    ]
    start = (0,0)
    goal = (4,4)
    path = hybrid_a_star_bfs(grid, start, goal)
    print("Hybrid A* + BFS Path:", path)
