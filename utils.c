#include "monty.h"

int isDigit(char *str) {
    if (*str == '\0') {
        return 0;
    }

    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }

    return 1;
}