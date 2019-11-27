#include "lib_pathfinder.h"

static int count_lines(const char *str, char c);

char **mx_split(const char *s, char c) {
    if (!s)
        return NULL;
    int count_l = count_lines(s, c);
    char **arr_words = malloc((count_l + 1) * sizeof(char*));
    int lw = 0;
    int arr_c = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            lw++;
            if (s[i + 1] == '\0') {
                arr_words[arr_c] = strncpy(mx_strnew(lw), 
                (s + i - lw + 1), lw);
                break;
            }
        }
        else if (s[i] == c) {
            if (lw == 0) {
                if (s[i + 1] == '\0') {
                    arr_words[arr_c] = NULL;
                    break;
                }
                else {
                    arr_words[arr_c] = strncpy(mx_strnew(1), 
                    (s + i - lw), 1);
                    lw = 0;
                    arr_c++;
                }
            }
            else if (lw != 0) {
                arr_words[arr_c] = strncpy(mx_strnew(lw), (s + i - lw), lw);
                lw = 0;
                arr_c++;
            }
        }
    }
    arr_words[count_l] = NULL;
    return (arr_words) ? arr_words : NULL;
}

static int count_lines(const char *str, char c) {
    int count = 0;
    int len = mx_strlen(str);

    if (str && c) {
        for (int i = 0; i < len; i++) {
            if (str[i] == c)
                count++;
        }
    }
    return count;
}

