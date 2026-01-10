def infix_to_postfix(expression):
    # Remove any spaces from the expression
    expression = expression.replace(" ", "")
    
    # Define operator precedence
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    
    # Initialize empty lists for postfix expression and operator stack
    postfix = []
    stack = []

    # Iterate over each character in the expression
    for char in expression:
        if char.isalnum():  # If the character is an operand, add it to the postfix list
            postfix.append(char)
        elif char == '(':  # If the character is '(', push it onto the stack
            stack.append(char)
        elif char == ')':  # If the character is ')', pop from the stack to the postfix list until '(' is found
            while stack and stack[-1] != '(':
                postfix.append(stack.pop())
            stack.pop()  # Pop the '(' from the stack
        else:  # If the character is an operator
            while stack and precedence[char] <= precedence.get(stack[-1], 0):
                postfix.append(stack.pop())  # Pop operators from the stack to the postfix list based on precedence
            stack.append(char)  # Push the current operator onto the stack

    # Pop all remaining operators from the stack to the postfix list
    while stack:
        postfix.append(stack.pop())

    # Return the postfix expression as a string
    return ''.join(postfix)

# Example usage
infix_expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2"
postfix_expression = infix_to_postfix(infix_expression)
print(postfix_expression)  # Output: "342*15-2^/+"