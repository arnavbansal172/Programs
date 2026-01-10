class EquilibriumIndex:
    def equilibrium(self, arr, n):
        sum = 0
        leftsum = 0
        for i in range(n):
            sum += arr[i]
        for i in range(n):
            sum -= arr[i]
            if leftsum == sum:
                return i
            leftsum += arr[i]
        return -1

def main():
    equi = EquilibriumIndex()
    arr = [-7, 1, 5, 2, -4, 3, 0]
    arr_size = len(arr)
    print("First equilibrium index is ", equi.equilibrium(arr, arr_size))

if __name__ == "__main__":
    main()
