#include"../inc/push_swap.h"

void	free_list_nodo(t_nodo *lst)
{
	t_nodo	*ptr;

	while (lst)
	{
		ptr = lst;
		lst = ptr->next;
		free(ptr);
	}
}

void	free_list_move(t_move *lst)
{
	t_move	*ptr;

	while (lst)
	{
		ptr = lst;
		lst = ptr->next;
		free(ptr);
	}
}

void	free_stack(t_list *lst)
{
	if (lst->cabeza)
		free_list_nodo(lst->cabeza);
	if (lst->cadena)
		free_list_move(lst->cadena);
	free(lst);
}
