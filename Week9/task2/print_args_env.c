#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int i;

    // Print command-line parameters
    printf("Command-line parameters:\n");
    for (i = 0; i < argc; i++) {
        printf("  argv[%d]: %s\n", i, argv[i]);
    }

    // Print environment variables
    printf("\nEnvironment variables:\n");
    for (i = 0; envp[i] != NULL; i++) {
        printf("  %s\n", envp[i]);
    }

    return 0;
}
