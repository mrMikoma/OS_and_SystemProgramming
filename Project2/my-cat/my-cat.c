#include <stdio.h>
#include <stdlib.h>

// NOTE: 
// There is almost full example code if you search for
// man getline and see EXAMPLES section

int main(int argc, char *argv[]) {
    // Verify parameters
    if (argc < 2) {
        fprintf(stderr, "my-cat: file not provided\n"); // Print error message to stderr
        exit(0); // Exit with status 0 as for no files
    }

    // Loop through all files
    for (int i = 1; i < argc; i++) {
        // Open file using fopen
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "my-cat: cannot open file\n"); // Print error message to stderr
            exit(1); // Exit with status 1 as for file not found
        }

        // Read file line by line and print using getline
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, file)) != -1) {
            printf("%s", line); // Print line to stdout
        }

        // Free memory using free
        free(line);

        // Close file using fclose
        fclose(file);
    }

  return 0;
}
