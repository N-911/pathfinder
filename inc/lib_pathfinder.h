#ifndef LIB_PATHFINDER_H
#define LIB_PATHFINDER_H

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdio.h>

#include "libmx/inc/libmx.h"
#define MX_INVALID_ARGC "usage: ./pathfinder [filename]\n"
#define MX_INVALID_LINE1 "error: line 1 is not valid\n"
#define MX_INVALID_N_ISLANDS "error: invalid number of islands\n"
#define MX_MAX 21474836

typedef struct		s_stack
{
    int			size;
    int*		path;
    int 		n;
}				t_stack;

typedef struct      s_main
{
    char**          arr_v;
    int             arr_v_count;
    int**           matr_d;
    int**           matr_a;
    int             v_count;
}                   t_main;

// struct
void mx_fill_struct(t_main *m_stct, char *argv[]);
void mx_init_m_d(t_main *m_stct);
void mx_fill_m_a_struct(t_main *m_stct);

// My pack
char **mx_parse_string(char *s, int j);
int mx_ind_v(t_main *m_stct, char *temp);
void mx_floyd_warshall(t_main *m_stct);
void mx_find_all_paths(t_main *m_stct, int st, int end);
void mx_back_tracking(t_main *m_stct, t_stack *p_stack);
void mx_print_path(t_main *m_stct, t_stack *p_stack);
void mx_pr_int(int n);
char **mx_split(const char *s, char c);

//errors
void mx_check_errors(int argc, char *argv[]);
void mx_error_invalid_argc(int argc);
void mx_error_doesnt_exist(char *argv[]);
void mx_error_is_empty(char *argv[]);
void mx_error_line1(char *str, char *line);

#endif

