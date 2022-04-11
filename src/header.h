#ifndef header
#define header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct struct_args {
    char *words;
    char *matrix;
    int numWords;
    int xmax;
    int ymax;
    int zmax;
} struct_args;

void *search_x(void *args);
void *search_y(void *args);
void *search_z(void *args);
void *search_xy(void *args);
void *search_xz(void *args);
void *search_yz(void *args);
void print_grid(char *matrix, int xmax, int ymax, int zmax);

#endif