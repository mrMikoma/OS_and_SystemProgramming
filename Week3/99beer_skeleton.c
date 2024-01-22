#include <stdio.h>

int main(int argc, char* argv[]) {
    for (int i = 99; i > 94; i--) {
        printf("%d bottles of beer on the wall, %d bottles of beer. take one down, pass it around, %d bottles of beer on the wall.\n", i, i, (i-1));
    }
    return 0;
}