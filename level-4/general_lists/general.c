#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_cool
{
	int				number;
	int				index;
}					t_cool;

/*lists.h

typedef struct    s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

*/

void	free_cool(void *data)
{
	free(data);
}

// alloc t_cool struct and return pointer to it
t_cool	*new_cool(int number, int index)
{
	t_cool	*new;

	new = (t_cool *)malloc(1 * sizeof(t_cool));
	if (!new)
		return (NULL);
	new->index = index;
	new->number = number;
	return (new);
}

// creates new element for the list
t_list	*lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = content;
	new->next = NULL;
	return (new);
}

// adds new element to the BACK of the list
void	lst_addback(t_list **begin_list, t_list *new)
{
	t_list	*current;

	if (!new || !begin_list)
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

// TODO: adds new element to the FRONT of the list
void	lst_addfront(t_list **begin_list, t_list *new)
{
	if (!new || !begin_list)
		return ;
	new->next = *begin_list;
	*begin_list = new;
}

// prints the list

// clear the list by using function passing to it
void	lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*head;

	head = *lst;
	if (!lst || !head || !del)
		return ;
	while (head->next) // 
	{
		current = head->next;
		del(head->data);
        free(head);
		head = current;
	}
    del(head->data);
    free(head);
}

// this function compares two elements cmp takes two void* and returns 0 when both parameters are equal.

void ft_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		f(current->data);
		current = current->next;
	}
}

// populate list
t_list	*get_populated_list()
{
	int	i;
	int number;
	t_cool *element;
	t_list	*node;
	t_list	*head;

	number=42;
	i = 0;
	head = NULL;
	while (i < 5)
	{
		element = malloc(sizeof(t_cool));
		if (!element)
			return(NULL);
		element->index = i;
		element->number = number + i;
		node = lstnew(element);
		if (!node)
			return(free(element), NULL);
		lst_addfront(&head, node);
		i++;
	}

	return head;
}

void	print_cool(void *data)
{
	t_cool *element;
	element = (t_cool *) data;
	printf("Numa %d, index %d\n", element->number, element->index);
}

// main function for testing
int	main(void)
{
	t_list *list;

	list = get_populated_list();
	ft_foreach(list, &print_cool);
	lst_clear(&list, &free_cool);
	return (0);
}
