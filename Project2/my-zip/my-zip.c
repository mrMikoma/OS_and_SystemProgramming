#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// References:
// - man: getline, fwrite, fopen, fclose, free

int main(int argc, char *argv[]) {
    // Verify parameters
    if (argc < 2) { // If no files
        fprintf(stderr, "my-zip: file1 [file2 ...]\n"); // Print error message to stderr
        exit(1); // Exit with status 1 as for no files
    }

    // Loop through all files
    for (int i = 1; i < argc; i++) {
        // Open file using fopen
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) { // If file not found
            fprintf(stderr, "my-zip: cannot open file\n"); // Print error message to stderr
            exit(1); // Exit with status 1 as for file not found
        }

        // Read file line by line using getline
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, file)) != -1) {
            // Loop through each character in line
            for (int j = 0; j < strlen(line); j++) {
                // Count consecutive characters
                int count = 1;
                while (line[j] == line[j + 1]) {
                    count++;
                    j++;
                }

                // Write count and character to stdout
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&line[j], sizeof(char), 1, stdout);

            }
            
        }

        // Free memory using free
        free(line);

        // Close file using fclose
        fclose(file);
    }

  return 0;
}
