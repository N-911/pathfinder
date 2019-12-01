#include "lib_pathfinder.h"

static void print_err_line_n(int j);

static bool check_dist(char *s);

static bool check_name(char *s);

char **mx_parse_string(char *s, int j) {
    int a = mx_get_char_index(s, '-');
    int b = mx_get_char_index(s, ',');
    int len = mx_strlen(s);
    char **p_str = (char**)malloc((3 + 1) * sizeof(char *));

    if (a < 0 || b < 0 || len < 5)
        print_err_line_n(j + 1);
    p_str[0] = mx_strndup(s, a);
    p_str[1] = mx_strndup((s + a + 1) , (b - a - 1));
    p_str[2] = mx_strndup((s + b + 1), (len - b));
    p_str[3] = NULL;
    if (!(check_name(p_str[0])) || !(check_name(p_str[1])) ||
        !(check_dist(p_str[2])) || (mx_strcmp(p_str[0], p_str[1]) == 0))
    {
        mx_del_strarr(&p_str);
        print_err_line_n(j + 1);
    }
    return p_str;
}

static void print_err_line_n(int j) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(j));
    mx_printerr(" is not valid\n");
    exit(1);
}

static bool check_name(char *s) {
    int len_s = mx_strlen(s);

    if (len_s == 0)
        return 0;
    for (int i = 0; i < len_s - 1; i++) {
        if (!mx_isalpha(s[i]))
            return 0;
    }
    return 1;
}

static bool check_dist(char *s) {
    int len_s = mx_strlen(s);

    if (len_s == 0)
        return 0;
    for (int i = 0; i < len_s; i++) {
        if (!mx_isdigit(s[i]))
            return 0;
    }
    if (mx_atoi(s) > MX_MAX - 1)
        return 0;
    return 1;
}

