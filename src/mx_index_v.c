#include "lib_pathfinder.h"

int mx_ind_v(t_main *m_stct, char *temp) {
    for (int i = 0; m_stct->arr_v[i]; i++) {
        if (mx_strcmp(m_stct->arr_v[i], temp) == 0)
            return i;
    }
    return -1;
}

