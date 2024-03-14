#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for sufficient arguments
    if (argc < 3) {
        printf("Usage: ./calculate operand1 operand2 ...\n");
        return 1;
    }

    // Get the operator from the environment variable
    char *operator = getenv("OPERATOR");
    if (operator == NULL) {
        printf("Environment variable OPERATOR not found.\n");
        return 1;
    }

    // Initialize result
    int result = atoi(argv[1]); // Convert the first operand to an integer

    // Perform the calculation based on the operator
    for (int i = 2; i < argc; i++) {
        int operand = atoi(argv[i]);
        if (strcmp(operator, "add") == 0) {
            result += operand;
        } else if (strcmp(operator, "multiply") == 0) {
            result *= operand;
        } else {
            printf("Unsupported operator: %s\n", operator);
            return 1;
        }
    }

    printf("%d\n", result);
    return 0;
}
