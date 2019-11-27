#include "lib_pathfinder.h"

static void write_to_struct(t_main *m_stct, char **s_str); 

static void add_v_to_arr(t_main *m_stct, char *temp);

static void add_d_to_m_d(t_main *m_stct, char **temp);

static void check_count_v(t_main *m_stct);

void mx_fill_struct(t_main *m_stct, char *argv[]) {
    char *str = mx_file_to_str(argv[1]);
    char **s_str = mx_split(str, '\n');

    mx_error_line1(&str[0], s_str[0]);
    m_stct->v_count = mx_atoi(s_str[0]);
    mx_init_m_d(m_stct);
    m_stct->arr_v = (char**)malloc((m_stct->v_count + 1) * sizeof(char *));
    m_stct->arr_v_count = 0;
    write_to_struct(m_stct, s_str);
    if (m_stct->arr_v_count != m_stct->v_count) {
        mx_printerr(MX_INVALID_N_ISLANDS);
        mx_strdel(&str);
        mx_del_strarr(&s_str);
        exit(1);
    }
    mx_fill_m_a_struct(m_stct);
    mx_strdel(&str);
    mx_del_strarr(&s_str);
}

static void write_to_struct(t_main *m_stct, char **s_str) {
    char **temp;
    m_stct->arr_v_count = 0;

    for (int i = 0; i < m_stct->v_count; i++)
        m_stct->arr_v[i] = NULL;
    for (int j = 1; s_str[j]; j++) {
        temp = mx_parse_string(s_str[j], j);
        add_v_to_arr(m_stct, temp[0]);
        add_v_to_arr(m_stct, temp[1]);
        add_d_to_m_d(m_stct, temp);
    }
}

static void check_count_v(t_main *m_stct) {
    if (m_stct->arr_v_count >= m_stct->v_count) {
        mx_printerr(MX_INVALID_N_ISLANDS);
        exit(1);
    }
}

static void add_v_to_arr(t_main *m_stct, char *temp) {
    int add = 0;

    for (int j = 0; m_stct->arr_v[j] && j < m_stct->arr_v_count; j++) {
        if (mx_strcmp(m_stct->arr_v[j], temp) == 0)
        add = -1;
    }
    if (add == 0) {
        check_count_v(m_stct);
        m_stct->arr_v[m_stct->arr_v_count] = mx_strdup(temp);
        m_stct->arr_v_count += 1;
    }
}

static void add_d_to_m_d(t_main *m_stct, char **temp) {
    int w = mx_atoi(temp[2]);
    int n = m_stct->v_count;

    m_stct->matr_d[mx_ind_v(m_stct, temp[0])] [mx_ind_v(m_stct, temp[1])] = w;
    m_stct->matr_d[mx_ind_v(m_stct, temp[1])] [mx_ind_v(m_stct, temp[0])] = w;
    mx_del_strarr(&temp);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if ((i != j) && (m_stct->matr_d[i][j] == 0))
                m_stct->matr_d[i][j] = MX_MAX;
       }
    }
}

