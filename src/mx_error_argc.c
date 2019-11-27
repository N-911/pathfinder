#include "lib_pathfinder.h"

void mx_error_invalid_argc(int argc) {
    if (argc != 2) {
        mx_printerr(MX_INVALID_ARGC);
        exit(1);
    }
}

