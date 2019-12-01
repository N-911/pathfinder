#include "lib_pathfinder.h"

static int get_char_index(char *str, char c);

static int count_lines(const char *s, char c);

char **mx_split(const char *s, char c) {
    int count_l = count_lines(s, c);
    char **arr_words = malloc((count_l + 1) * sizeof(char*));
    int p = 0;
    char *t;
  
    for (int i = 0; i < count_l; i++) {
        t = mx_strdup(s + ((i > 0) ? 1 : 0));
        p = get_char_index(t, c);
        if (p == 0 && (t[1] != '\0'))
            arr_words[i] = mx_strncpy(mx_strnew(p + 1), t, 1);
        else if (t[1] == '\0')
            arr_words[i] = NULL;
        else  
            arr_words[i] = mx_strncpy(mx_strnew(p), t, p);
        mx_strdel(&t);
        s = (s + p + ((i > 0) ? 1 : 0));
    }
    arr_words[count_l] = NULL;
    return (arr_words) ? arr_words : NULL;
}

static int count_lines(const char *s, char c) {
    int count = 0;
    int len = mx_strlen(s);

    if (s && c) {
        for (int i = 0; i < len; i++) {
            if (s[i] == c)
                count++;
        }
    }
    return count;
}

static int get_char_index(char *str, char c) {
    if ((!str))
        return -2;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

