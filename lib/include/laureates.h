#ifndef __LAUREATES__
#define __LAUREATES__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

typedef struct laureate {
    int  id;
    char first_name[50];
    char last_name[50];
} laureate;

int read_laureate(laureate *buf, int loc);

#endif