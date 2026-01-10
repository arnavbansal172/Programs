#include <stdio.h>

int main() {
    char buffer[5] = "Hello";
    char underflow = buffer[-1];
    
    printf("Buffer underflow: %c\n", underflow);
    printf("Program completed\n");
    
    return 0;
}
