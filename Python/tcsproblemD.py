from collections import defaultdict

def dfs(city, visited, graph, goods, taxes, route, total_tax):
    visited[city] = True
    route.append(city)

    # Sort the neighbors based on the number of goods, entry tax, and lexicographical order
    neighbors = sorted(graph[city], key=lambda x: (goods[x], taxes[x], x))

    for neighbor in neighbors:
        if not visited[neighbor]:
            total_tax += taxes[neighbor]
            total_tax += dfs(neighbor, visited, graph, goods, taxes, route, 0)
            route.append(city)  # Backtrack to the current city after visiting the neighbor

    return total_tax

def min_tax_route(N, city_info):
    graph = defaultdict(list)
    goods, taxes = {}, {}

    for info in city_info:
        city1, city2, num_goods, entry_tax = info
        graph[city1].append(city2)
        graph[city2].append(city1)
        goods[city2] = num_goods
        taxes[city2] = entry_tax

    visited = {city: False for city in graph}
    starting_city = list(graph.keys())[0]  
    route = []

    total_tax = dfs(starting_city, visited, graph, goods, taxes, route, 0)

    return '-'.join(map(str, route)), total_tax

try:
    N = int(input("Enter the total number of cities: "))
    city_info = []

    for _ in range(N - 1):
        city1, city2, num_goods, entry_tax = map(str, input().split())
        city_info.append((city1, city2, int(num_goods), int(entry_tax)))

    route_map, min_tax = min_tax_route(N, city_info)
    print("Route Map:", route_map)
    print("Minimum Tax:", min_tax)
from collections import defaultdict

def dfs(city, visited, graph, goods, taxes, route, total_tax):
    visited[city] = True
    route.append(city)

    # Sort the neighbors based on the number of goods, entry tax, and lexicographical order
    neighbors = sorted(graph[city], key=lambda x: (goods[x], taxes[x], x))

    for neighbor in neighbors:
        if not visited[neighbor]:
            total_tax += taxes[neighbor]
            total_tax += dfs(neighbor, visited, graph, goods, taxes, route, 0)
            route.append(city)  # Backtrack to the current city after visiting the neighbor

    return total_tax

def min_tax_route(N, city_info):
    graph = defaultdict(list)
    goods, taxes = {}, {}

    for info in city_info:
        city1, city2, num_goods, entry_tax = info
        graph[city1].append(city2)
        graph[city2].append(city1)
        goods[city2] = num_goods
        taxes[city2] = entry_tax

    visited = {city: False for city in graph}
    starting_city = list(graph.keys())[0]  # Assuming city A is the starting city

    # Find a connected component
    for city in visited:
        if not visited[city]:
            starting_city = city
            break

    route = []
    total_tax = dfs(starting_city, visited, graph, goods, taxes, route, 0)

    return '-'.join(map(str, route)), total_tax

# Example usage:
try:
    N = int(input("Enter the total number of cities: "))
    city_info = []

    for _ in range(N - 1):
        city1, city2, num_goods, entry_tax = map(str, input().split())
        city_info.append((city1, city2, int(num_goods), int(entry_tax)))

    route_map, min_tax = min_tax_route(N, city_info)
    print("Route Map:", route_map)
    print("Minimum Tax:", min_tax)

except ValueError as ve:
    print(f"Error: {ve}")

except ValueError as ve:
    print(f"Error: {ve}")
