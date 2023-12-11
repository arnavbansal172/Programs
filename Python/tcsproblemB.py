def min_vehicles(weights, max_limit):
    weights.sort()  # Sort the array in ascending order
    left_pointer, right_pointer = 0, len(weights) - 1
    vehicles_needed = 0

    while left_pointer <= right_pointer:
        if weights[left_pointer] + weights[right_pointer] <= max_limit:
            left_pointer += 1
        right_pointer -= 1
        vehicles_needed += 1

    return vehicles_needed

# Example usage:
try:
    # Taking the first input as a sequence of numbers (weights) separated by space
    weights_input = input("Enter weights of bananas separated by space: ")
    weights_list = list(map(int, weights_input.split()))

    # Taking the second input as a single integer greater than or equal to 1
    limit = int(input("Enter the maximum weight limit of the vehicle in tons: "))

    if limit < 0:
        raise ValueError("Maximum weight limit should be greater than or equal to 0.")

    result = min_vehicles(weights_list, limit)
    print(f"Minimum number of vehicles needed: {result}")
except ValueError as ve:
    print(f"Error: {ve}")
