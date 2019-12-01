#include "libmx.h"

void mx_str_reverse(char *s) {
    char *pa;
    int len;

    if (!s || !*s)
        return;
    pa = s;
    len = mx_strlen(s);
    for (int i = 0; i < (len / 2); i++)
        mx_swap_char((pa + i), (pa + len - 1 - i));
}

