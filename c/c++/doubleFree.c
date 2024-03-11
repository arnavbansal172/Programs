#include <stdlib.h>
#include <stdio.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int));

    // First free
    free(ptr);
    printf("Memory freed successfully.\n");

    // Second free (double free)
    free(ptr);
    printf("Second attempt to free memory.\n");

    return 0;
}
