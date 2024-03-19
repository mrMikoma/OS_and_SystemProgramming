#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc >= 4) {
        fprintf(stderr,"usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    // Handle cases 
    if (argc == 1) {
        // Read from stdin and print to stdout
        stdin_stdout();
        return 1;
    } else if (argc == 2) {
        // Read from input file and print to stdout
        file_stdout(argv[1]);
        return 1;
    } else if (argc == 3) {
        // Check if the input and output files are the same
        if (strcmp(argv[1], argv[2]) == 0) {
            fprintf(stderr, "Input and output files must differ\n");
            return 1;
        }
        // Copy the input file to the output file
        file_file(argv[1], argv[2]);
        return 1;
    }

    return 0;
}