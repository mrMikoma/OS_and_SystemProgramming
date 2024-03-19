# Project documentation

## Input/Output Utility Library
This tool provides a C program for reverse outputting inputs.

##  Included Functions

### stdin_stdout()

Reads lines from standard input (stdin) using getline.
Prints each line directly to standard output (stdout).

### file_stdout(char *inputFileName)

Reads lines from a specified file using getline.
Stores lines in a doubly linked list.
Prints the lines in reverse order to standard output (stdout).

### file_file(char *inputFileName, char *outputFileName)

Reads lines from a specified file using getline.
Stores lines in a doubly linked list.
Writes the lines in reverse order to a specified output file.

## Usage

### Compiling

Make sure you have .c-files main.c, lib.c and lib.h header file included. Run `make` to compile.

## Running 

```
./reverse inputfile outputfile
```

### Dependencies

Standard C libraries: (stdio.h, string.h, stdlib.h) These provide functions like fprintf, getline, and memory management.