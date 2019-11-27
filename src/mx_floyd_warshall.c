#include "lib_pathfinder.h"

void mx_floyd_warshall(t_main *m_stct) {
    int new_dist;
    int n = m_stct->v_count;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                new_dist = m_stct->matr_d[i][k] + m_stct->matr_d[k][j];
                if (new_dist < m_stct->matr_d[i][j]) {
                    m_stct->matr_d[i][j] = new_dist;
                }
            }
        }
    }
}

