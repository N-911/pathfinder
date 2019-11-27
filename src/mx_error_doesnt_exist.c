#include "lib_pathfinder.h"

void mx_error_doesnt_exist(char *argv[]) {
    char *file = argv[1];
    int f = open(file, O_RDONLY);

    if (f < 0) {
        close(f);
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist");
        close(f);
        exit(1);
    }
    close(f);
}

