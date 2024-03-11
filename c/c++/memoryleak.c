#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    // Use the allocated memory
    *ptr = 42;
    printf("Value stored in allocated memory: %d\n", *ptr);

    // Free the allocated memory
    free(ptr);
    printf("Memory freed.\n");

    // Check pointer after free
    if (ptr == NULL) {
        printf("Pointer is NULL after free.\n");
    } else {
        printf("Pointer is not NULL after free. Dangling pointer!\n");
    }

    return 0;
}
