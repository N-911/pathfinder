#include "lib_pathfinder.h"

void mx_init_m_d(t_main *m_stct) {
    int n = m_stct->v_count;

    m_stct->matr_d = NULL;
    m_stct->matr_d = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        m_stct->matr_d[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            m_stct->matr_d[i][j] = 0;
        }
    }
}

