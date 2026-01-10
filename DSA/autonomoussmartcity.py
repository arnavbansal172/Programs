#In a smart city, an autonomous emergency vehicle (AEV) is positioned in a grid-like city map represented as a 2D integer array grid of size m * n. Each cell in the grid has one of three values:
#• 0 represents a road,
#• 1 represents an area on fire,
#• 2 represents a building that neither the AEV nor the fire can pass through.
#The AEV starts at the top-left corner of the city grid at cell (0, 0), and its objective is to reach the safehouse located at the bottom-right corner of the grid at cell
#(m - 1, n - 1). Each minute, the AEV can move to an adjacent road cell. Simultaneously, fire spreads to all adjacent cells that are roads.
#Your task is to determine the maximum number of minutes the AEV can wait in its initial position before movina whilo etill haina ablata racinh the orifoharica


def max_wait_time(grid):
    m, n = len(grid), len(grid[0])
    visited = [[False] * n for _ in range(m)]
    q = [(0, 0, 0)]
    visited[0][0] = True
    wait_time = 0
    while q:
        x, y, t = q.pop(0)
        wait_time = max(wait_time, t)
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                visited[nx][ny] = True
                if grid[nx][ny] == 0:
                    q.append((nx, ny, t + 1))
    return wait_time

grid = [[0, 1, 2], [0, 0, 1], [1, 0, 0]]
print(max_wait_time(grid))  # 2
grid = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
print(max_wait_time(grid))  # 0
grid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
print(max_wait_time(grid))  # 1
grid = [[0, 0, 0], [0, 1, 0], [0, 0, 1]]
print(max_wait_time(grid))  # 2
grid = [[0, 0, 0], [0, 0, 0], [0, 0, 1]]
print(max_wait_time(grid))  # 3