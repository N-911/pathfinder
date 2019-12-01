#include "lib_pathfinder.h"

int main(int argc, char *argv[]) {
    int n;
    t_main m_stct;

    mx_check_errors(argc, argv);
    mx_fill_struct(&m_stct, argv);
    n = m_stct.v_count;
    mx_floyd_warshall(&m_stct);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j)
                mx_find_all_paths(&m_stct, i, j);
        }
    }
 //   system ("leaks -q pathfinder");
    return 0;
}

