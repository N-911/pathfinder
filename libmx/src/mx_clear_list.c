#include "libmx.h"

void mx_clear_list (t_list **list) {
    t_list *first;
    t_list *temp;

    if (list == NULL || *list == NULL)
        return;
    first = *list;
    if (!first)
        return;
    while (first != NULL) {
        temp = first->next;
        free(first);
        first = temp;
    }
    *list = NULL;
}

