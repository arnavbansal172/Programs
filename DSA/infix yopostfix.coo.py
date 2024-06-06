def infix_to_postfix(expression):
    precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
    postfix = []
    stack = []

    for char in expression:
        if char.isalnum():
            postfix.append(char)
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                postfix.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence[char] <= precedence.get(stack[-1], 0):
                postfix.append(stack.pop())
            stack.append(char)

    while stack:
        postfix.append(stack.pop())

    return ''.join(postfix)

# Example usage
infix_expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2"
postfix_expression = infix_to_postfix(infix_expression)
print(postfix_expression)