#include <stdio.h>
#include <stdlib.h>
#include "math_func.h"

int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    // Convert the command line arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Call the add_numbers function
    int sum = add_numbers(num1, num2);

    // Print the result
    printf("The sum is: %d\n", sum);

    return 0;
}
