
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char buffer[8];  // Small buffer size

    // Vulnerability: Out-of-bounds write
    strcpy(buffer, argv[1]);

    printf("Buffer contents: %s\n", buffer);

    return 0;
}