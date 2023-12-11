# Function to convert decimal number to scientific notation
def to_scientific_notation(number):
    num_str = '{:e}'.format(number)
    coefficient, exponent = num_str.split('e')
    coefficient = coefficient.split('.')[0] + '.' + str(sum(int(digit) for digit in coefficient.split('.')[1]) % 9)
    exponent = str(sum(int(digit) for digit in exponent) % 9)
    return coefficient, exponent

# Function to generate S1 and S2 strings
def generate_password(coefficient, exponent, name):
    s1 = ''.join([word[:3] if word != 'e' else 'e' for word in str(coefficient + 'e' + exponent)])
    if int(exponent) % 2 == 0:
        s2 = ''.join([name[i] for i in range(0, len(name), 2)])
    else:
        s2 = ''.join([name[i] for i in range(1, len(name), 2)])
    return s1, s2

# Main function to solve the problem
def solve_captcha(t, test_cases):
    for i in range(t):
        number, name = test_cases[i].split()
        try:
            number = float(number)
            coefficient, exponent = to_scientific_notation(number)
            s1, s2 = generate_password(coefficient, exponent, name)
            password = f"{s1}@{s2}"
            print(password)
        except:
            print("Invalid input")
            
# Function to take n as input and get test cases as input
def main():
    t = int(input("Enter the number of test cases (1 to 10): "))
    if t < 1 or t > 10:
        print("Number of test cases should be between 1 and 10")
        return
    test_cases = []
    for _ in range(t):
        test_case = input("Enter number and name separated by space: ")
        test_cases.append(test_case)
    solve_captcha(t, test_cases)

# Get input and solve the problem
main()
