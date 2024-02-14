def calculate_num(registration_number):
    last_digit = int(registration_number[-1])

    if last_digit == 0:
        num = int(registration_number[-2:])
    elif registration_number[-2:] == '00':
        num = sum(int(digit) for digit in registration_number if digit.isdigit()) % 10
    else:
        num = last_digit

    return num

def convert_name(full_name, num):
    new_name = ''
    for char in full_name:
        if char.isalpha():
            new_char = chr((ord(char) - ord('a' if char.islower() else 'A') + num) % 26 + ord('a' if char.islower() else 'A'))
            new_name += new_char
        else:
            new_name += char

    return new_name

# Example usage
registration_number = "21BCY10026"
full_name = "ArnavBansal"
num = calculate_num(registration_number)
new_name = convert_name(full_name, num)

# Output
print("Registration Number:", registration_number)
print("NUM:", num)
print("Full Name:", full_name)
print("New Name:", new_name)
