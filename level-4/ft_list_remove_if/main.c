#include "ft_list.h"
#include <stdlib.h>


// create a list of t_list (each data is a 'number')
t_list *create_list(int size)
{
    t_list *head = NULL;
    t_list *current = NULL;
    t_list *new = NULL;
    int number = 42;

    for (int i = 0; i < size; i++)
    {
        number = number * 2;
        new = malloc(sizeof(t_list));
        new->data = &number;
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            current = new;
        }
        else
        {
            current->next = new;
            current = new;
        }
    }
    return head;
}

// función que toma dos *void y devuelve 1 si son iguales, 0 si no
int compare(void *data, void *data_ref)
{
    return (*(int *)data == *(int *)data_ref);
}



// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	t_list *previous;
// 	t_list *current;

// 	if (!begin_list || !*begin_list)
// 		return ;

// 	previous = *begin_list;
// 	current = previous->next;
// 	while (current)
// 	{
// 		if (cmp(current->data, data_ref) == 0) {
// 			previous->next = current->next;
// 			free(current);
// 		} else {
// 			previous = current;
// 		}
// 		current = previous->next;
// 	}
// 	if (cmp((*begin_list)->data, data_ref) == 0) {
// 		current = *begin_list;
// 		(*begin_list) = (*begin_list)->next;
// 		free(current);
// 	}
// }
 


