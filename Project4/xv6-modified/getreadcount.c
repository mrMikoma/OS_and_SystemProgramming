#include "types.h"
#include "stat.h"
#include "user.h"

// This program tests the getreadcount system call
int main(void) 
{
    printf(1, "Read count: %d\n", getreadcount()); // Print the read count
    exit(); // Exit the program
} 