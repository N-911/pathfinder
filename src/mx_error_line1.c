#include "lib_pathfinder.h"

void mx_error_line1(char *str, char *line) {
    if (!(mx_isdigit(str[0]))) {
        mx_printerr(MX_INVALID_LINE1);
        exit(1);
    }
    for (int i = 0; i < mx_strlen(line) - 1; i++) {
        if (!(mx_isdigit(line[i]))) {
            mx_printerr(MX_INVALID_LINE1);
            exit(1);
        }
    }
    if (mx_atoi(line) < 2 || mx_strlen(line) > 4) {
        mx_printerr(MX_INVALID_N_ISLANDS);
        exit(1);
    }
}

