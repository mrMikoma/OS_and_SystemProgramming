#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector* create_vector() {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    return vec;
}

void push_back(Vector *vec, int value) {
    if (vec->size >= vec->capacity) {
        vec->capacity = (vec->capacity == 0) ? 1 : vec->capacity * 2;
        vec->data = (int *)realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size++] = value;
}

void free_vector(Vector *vec) {
    free(vec->data);
    free(vec);
}

int main() {
    Vector *vec = create_vector();
    for (int i = 0; i < 1000; ++i) {
        push_back(vec, i);
    }
    free_vector(vec);
    return 0;
}
