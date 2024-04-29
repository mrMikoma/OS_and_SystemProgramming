#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// References:
// - man: fread, fopen, fclose

int main(int argc, char *argv[]) {
    // Verify parameters
    if (argc == 1) { // If no file provided
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n"); // Print error message to stderr
        exit(1); // Exit with status 1 for no file provided
    }

    for (int i = 1; i < argc; i++) { // Loop through all files
        // Open file
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) { // If file not found
            fprintf(stderr, "my-unzip: cannot open file\n"); // Print error message to stderr
            exit(1); // Exit with status 1 for file not found
        }

        // Read file and uncompress
        int count;
        char c;
        while (fread(&count, sizeof(int), 1, file) == 1) { // Read 4 bytes from file
            fread(&c, sizeof(char), 1, file); // Read 1 byte from file
            for (int i = 0; i < count; i++) { // Loop through count
                printf("%c", c); // Print character
            }
        }
        printf("\n"); // Print newline

        // Close file
        fclose(file);
    }

    return 0;
}

