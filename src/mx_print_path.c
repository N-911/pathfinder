#include "lib_pathfinder.h"

static void print_distance(t_main *m_stct, t_stack *p_stack);

void mx_print_path(t_main *m_stct, t_stack *p_stack) {
    int i = p_stack->path[1];
    int j = p_stack->path[0];
    int n = p_stack->size;

    mx_printstr("========================================");
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(m_stct->arr_v[i]);
    mx_printstr(" -> ");
    mx_printstr(m_stct->arr_v[j]);
    mx_printstr("\nRoute: ");
    for (int i = 1; i <= n; i++) {
        mx_printstr(m_stct->arr_v[p_stack->path[i]]);
        (i < n) ? mx_printstr(" -> ") : mx_printstr("");
    }
    print_distance(m_stct, p_stack);
    mx_printstr("\n");
    mx_printstr("========================================\n");
}

static void print_distance(t_main *m_stct, t_stack *p_stack) {
    int sum = 0;
    int n = p_stack->size;

    mx_printstr("\nDistance: ");
    if (n == 2)
        mx_printint(m_stct->matr_d[p_stack->path[n]][p_stack->path[n - 1]]);
    else {
        for (int i = 1; i < n; i++) {
            mx_pr_int(m_stct->matr_d[p_stack->path[i]][p_stack->path[i + 1]]);
            sum += m_stct->matr_d[p_stack->path[i]][p_stack->path[i + 1]];
            (i + 1 < n) ? mx_printstr(" + ") : mx_printstr("");
        }
        mx_printstr(" = ");
        mx_printint(sum);
    }
}

