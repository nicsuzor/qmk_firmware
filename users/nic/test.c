//
// Created by nicsu on 31/10/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "keycode.h"

#define ARRAY_CONCAT(TYPE, A, An, B, Bn) \
  (TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(TYPE));

void *array_concat(const void *a, size_t an,
                   const void *b, size_t bn, size_t s)
{
    char *p = malloc(s * (an + bn));
    memcpy(p, a, an*s);
    memcpy(p + an*s, b, bn*s);
    return p;
}

// testing
const int a[] = {KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5};
const int b[] = { KC_NO, KC_NO };

#define ARRAY1 "Hello "
#define ARRAY2 "world!\n"

const char array1[] = ARRAY1;
const char array2[] = ARRAY2;
const char array3[] = ARRAY1 ARRAY2;

int main(void)
{
    unsigned int i;

    int *c = ARRAY_CONCAT(int, a, 7, b, 2);

    for(i = 0; i < 10; i++)
        printf("%d\n", c[i]);

    printf("second string:\n\n");
    for(i = 0; i < 11; i++)
        printf("%d\n", array3[i]);

    free(c);
}