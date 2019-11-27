#include "lib_pathfinder.h"

void mx_fill_m_a_struct(t_main *m_stct) {
    int n = m_stct->v_count;

    m_stct->matr_a = NULL;
    m_stct->matr_a = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        m_stct->matr_a[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            m_stct->matr_a[i][j] = m_stct->matr_d[i][j];
        }
    }
}

