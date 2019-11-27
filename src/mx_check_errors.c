#include "lib_pathfinder.h"

void mx_check_errors(int argc, char *argv[]) {
    mx_error_invalid_argc(argc);
    mx_error_doesnt_exist(argv);
    mx_error_is_empty(argv);
}

