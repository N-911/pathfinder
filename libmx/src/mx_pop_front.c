#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *temp;

    if (head && *head) {
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

