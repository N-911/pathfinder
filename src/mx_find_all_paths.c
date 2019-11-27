#include "lib_pathfinder.h"

static void init_stack(t_main *m_stct, t_stack **path_stack, int i, int j);
 
void mx_find_all_paths(t_main *m_stct, int st, int end) {
    t_stack *p_stack = NULL;

    init_stack(m_stct, &p_stack, st, end);
    mx_back_tracking(m_stct, p_stack);
    free(p_stack->path);
    free(p_stack);
}

static void init_stack(t_main *m_stct, t_stack **p_stack, int i, int j) {
    *p_stack = malloc(sizeof(t_stack));
    int n = m_stct->v_count;

    if ((*p_stack) == NULL)
        exit(1);
    (*p_stack)->path = malloc(sizeof(int) * n + 1);
    (*p_stack)->size = 1;
    (*p_stack)->path[0] = i;
    (*p_stack)->path[1] = j;
    (*p_stack)->n = n;
}

