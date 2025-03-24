#include "ft_list.h"
#include <stdlib.h> // malloc, free

t_list  *ft_lstnew(void *data)
{
    t_list  *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

void    ft_lstadd_back(t_list **begin_list, t_list *new)
{
    t_list  *current;

    if (!begin_list || !new)
        return ;
    if (*begin_list == NULL)
    {
        *begin_list = new;
        return ;
    }
    current = *begin_list;
    while (current->next)
        current = current->next;
    current->next = new;
}

void    ft_lstadd_front(t_list **begin_list, t_list *new)
{
    if (!begin_list || !new)
        return ;
    new->next = *begin_list;
    *begin_list = new;
}

void    ft_lstclear(t_list **begin_list, void (*del)(void *))
{
    t_list  *tmp;

    if (!begin_list || !*begin_list || !del)
        return ;
    while (*begin_list)
    {
        tmp = (*begin_list)->next;
        del((*begin_list)->data); // free data
        free(*begin_list);        // free node
        *begin_list = tmp;
    }
}

// Optional: A function to apply f to each node's data
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list  *current;

    current = begin_list;
    while (current)
    {
        f(current->data);
        current = current->next;
    }
}


typedef struct s_cool
{
    int number;
    int index;
}   t_cool;

// Freed by ft_lstclear's "del" function
static void free_cool(void *data)
{
    free(data);
}

// Just prints the `number` and `index` of a t_cool
static void print_cool(void *data)
{
    t_cool *cool = (t_cool *)data;
    printf("cool -> number: %d, index: %d\n", cool->number, cool->index);
}

int main(void)
{
    t_list  *list = NULL; 
    t_list  *node;
    t_cool  *element;
    int     i;

    // Build the list
    for (i = 0; i < 3; i++)
    {
        element = malloc(sizeof(t_cool));
        if (!element)
            return (1);
        element->number = 42;
        element->index = i;
        node = ft_lstnew(element);
        if (!node)
            return (free(element), 1);
        ft_lstadd_back(&list, node);
    }

    // Apply a function to each list item
    ft_list_foreach(list, &print_cool);

    // Clear the list
    ft_lstclear(&list, &free_cool);

    // Prove it's cleared
    if (list == NULL)
        printf("List cleared.\n");

    return (0);
}
