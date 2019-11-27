#include "lib_pathfinder.h"

static void push_to_stack(t_stack *path_stack, int elem);

static int pop_from_stack(t_stack *path_stack);

static int get_from_stack(t_stack *path_stack);

static bool check_next_v(t_main *m_stct, t_stack *p_stack, int next_v);

void mx_back_tracking(t_main *m_stct, t_stack *p_stack) {
    int n = p_stack->n;

    if (get_from_stack(p_stack) == p_stack->path[0]) {
         mx_print_path(m_stct, p_stack);
        return;
    }
    else {
        for (int j = n - 1 ; j >= 0; j--) {
            if (check_next_v(m_stct, p_stack, j)) {
                push_to_stack(p_stack, j);
                mx_back_tracking(m_stct, p_stack);
                pop_from_stack(p_stack);
            }
        }
    }
}

static void push_to_stack(t_stack *p_stack, int elem) {
    if (p_stack->size < p_stack->n) {
        p_stack->size++;
        p_stack->path[p_stack->size] = elem;
    }
}

static int pop_from_stack(t_stack *p_stack) {
    if (p_stack->size > 1) {
        p_stack->size--;
        return p_stack->path[p_stack->size + 1];
    }
    return p_stack->path[1];
}

static int get_from_stack(t_stack *p_stack) {
    return p_stack->path[p_stack->size];
}

static bool check_next_v(t_main *m_stct, t_stack *p_stack, int next_v) {
    int k = get_from_stack(p_stack);
    int i = p_stack->path[0];

    if (k != next_v) {
        if (m_stct->matr_d[i][k] - m_stct->matr_a[k][next_v]
            == m_stct->matr_d[i][next_v])
            return true;
    }
    return false;
}

