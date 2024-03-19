#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define LineNode struct for linked list
struct LineNode {
    char *line;            // Pointer to the line
    struct LineNode *next; // Pointer to the next node
    struct LineNode *prev; // Pointer to the previous node
};

// Function gets input from stdin and prints it to stdout
int stdin_stdout() {
    // Initialize variables for getline
    char *line = NULL;
    size_t len = 0; 
    ssize_t read; 

    // Read from stdin and print to stdout
    while ((read = getline(&line, &len, stdin)) != -1) {
        fprintf(stdout, "%s", line); // Print line
    }

    // Release memory allocated by getline
    if (line) {
        free(line);
    }

    return 0;
}

// Function reads from inputfile and print to stdout
int file_stdout(char *inputFileName) {
    // Open the input file
    FILE *input = fopen(inputFileName, "r");
    if (input == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", inputFileName);
        exit(1);
    }

    // Initialize head and tail of the linked list
    struct LineNode *head = NULL;
    struct LineNode *tail = NULL;

    // Initialize variables for getline
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Build the doubly linked list 
    while ((read = getline(&line, &len, input)) != -1) {
        // Allocate memory for a new node
        struct LineNode *new_node = (struct LineNode *)malloc(sizeof(struct LineNode));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            // Free any previously allocated nodes
            while (head != NULL) {
                struct LineNode *temp = head;
                head = head->next;
                free(temp->line);
                free(temp);
            }
            fclose(input);
            exit(1);
        }

        // Allocate memory for the line and copy the line
        new_node->line = (char *)malloc(read + 1);
        if (new_node->line == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(new_node); // Free the node itself 
            // Free any previously allocated nodes
            while (head != NULL) {
                struct LineNode *temp = head;
                head = head->next;
                free(temp->line);
                free(temp);
            }
            fclose(input);
            exit(1);
        }

        // Copy the line to the new node
        strncpy(new_node->line, line, read); 
        new_node->line[read - 1] = '\0';

        // Link the new node at the end of the list
        new_node->prev = NULL;
        new_node->next = NULL;
        if (head == NULL) { // First node
            head = new_node;
        } else { // Not the first node
            tail->next = new_node;
            new_node->prev = tail;
        }
        tail = new_node; // Update tail to the newly added node
    }

    // Print lines in reverse order
    struct LineNode *current = tail;
    while (current != NULL) {
        fprintf(stdout, "%s\n", current->line); // Print the line
        current = current->prev; // Move to the previous node
    }

    // Free the linked list 
    while (head != NULL) {
        struct LineNode *temp = head;
        head = head->next;
        free(temp->line); // Free the line string
        free(temp);       // Free the node
    }

    // Free the line buffer
    if (line) {
        free(line); // Free the line buffer
    }

    // Close the input file
    fclose(input);
    return 0;
}

// Function reads from inputfile and writes to outputfile
int file_file(char *inputFileName, char *outputFileName) {
    // Open the input file
    FILE *input = fopen(inputFileName, "r");
    if (input == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", inputFileName);
        exit(1);
    }

    // Initialize head and tail of the linked list
    struct LineNode *head = NULL;
    struct LineNode *tail = NULL;

    // Initialize variables for getline
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Build the doubly linked list 
    while ((read = getline(&line, &len, input)) != -1) {
        // Allocate memory for a new node
        struct LineNode *new_node = (struct LineNode *)malloc(sizeof(struct LineNode));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            // Free any previously allocated nodes
            while (head != NULL) {
                struct LineNode *temp = head;
                head = head->next;
                free(temp->line);
                free(temp);
            }
            fclose(input);
            exit(1);
        }

        // Allocate memory for the line and copy the line
        new_node->line = (char *)malloc(read + 1);
        if (new_node->line == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(new_node); // Free the node itself 
            // Free any previously allocated nodes
            while (head != NULL) {
                struct LineNode *temp = head;
                head = head->next;
                free(temp->line);
                free(temp);
            }
            fclose(input);
            exit(1);
        }

        // Copy the line to the new node
        strncpy(new_node->line, line, read); 
        new_node->line[read - 1] = '\0';

        // Link the new node at the end of the list
        new_node->prev = NULL;
        new_node->next = NULL;
        if (head == NULL) { // First node
            head = new_node;
        } else { // Not the first node
            tail->next = new_node;
            new_node->prev = tail;
        }
        tail = new_node; // Update tail to the newly added node
    }


    // Open the output file
    FILE *output = fopen(outputFileName, "w");
    if (output == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", outputFileName);
        // Free the linked list 
        while (head != NULL) {
            struct LineNode *temp = head;
            head = head->next;
            free(temp->line); // Free the line string
            free(temp);       // Free the node
        }
        fclose(input);
        exit(1);
    }

    // Print lines in reverse order
    struct LineNode *current = tail;
    while (current != NULL) {
        fprintf(output, "%s\n", current->line); // Write to the output file
        current = current->prev; // Move to the previous node
    }

    // Free the linked list 
    while (head != NULL) {
        struct LineNode *temp = head;
        head = head->next;
        free(temp->line); // Free the line string
        free(temp);       // Free the node
    }

    // Free the line buffer
    if (line) {
        free(line); // Free the line buffer
    }

    // Close the files
    fclose(input);
    fclose(output);
    return 0;
}