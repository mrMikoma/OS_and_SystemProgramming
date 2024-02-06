#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = (int *)malloc(sizeof(int) * 100);
    free(data);
    printf("Value of element at index 0: %d\n", data[0]);
    return 0;
}
