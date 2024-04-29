#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verify parameters
    if (argc < 2) { // If no search term provided
        fprintf(stderr, "my-grep: searchterm [file ...]\n"); // Print error message to stderr
        exit(1); // Exit with status 1 as for no search term
    } else if (argc < 3) { // If no files provided, print from stdin using getline
        // Read line from stdin and match
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, stdin)) != -1) {
            if (strstr(line, argv[1]) != NULL) { // If search term found in line using strstr
                printf("%s", line); // Print line to stdout
            }
        }
        return 0;
    }

    // Loop through all files
    for (int i = 2; i < argc; i++) {
        // Open file using fopen
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "my-grep: cannot open file\n"); // Print error message to stderr
            exit(1); // Exit with status 1 as for file not found
        }

        // Read file line by line and print using getline
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, file)) != -1) {
            if (strstr(line, argv[1]) != NULL) { // If search term found in line using strstr
                printf("%s", line); // Print line to stdout
            }
        }

        // Free memory using free
        free(line);

        // Close file using fclose
        fclose(file);
    }

  return 0;
}
