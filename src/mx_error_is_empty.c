#include "lib_pathfinder.h"

void mx_error_is_empty(char *argv[]) {
    char buf;
    int f = open(argv[1], O_RDONLY);
    int r = read(f, &buf, 1);

    close(f);
    if (r <= 0 ) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
}

