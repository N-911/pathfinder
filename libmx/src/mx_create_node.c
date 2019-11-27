#include "libmx.h"

t_list *mx_create_node(int distance, char *point_name) {
    t_list *new_node = NULL;

    new_node = (t_list*)malloc(sizeof(t_list));
    new_node->distance = distance;
    new_node->point_name = point_name;
    new_node->next = NULL;
    return new_node;
}

