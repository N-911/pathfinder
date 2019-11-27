#include "libmx.h"

void mx_push_front(t_list **list, int distance, char *point_name) {
    t_list *first = mx_create_node(distance, point_name);
    first->next = (*list);
    (*list) = first;
}

