#include"../inc/push_swap.h"
#include"../inc/checker.h"
#include<string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if(s1[i] != s2[i])
			return (s2[i] - s2[i]);
		i++;
	}
	return (0);
}

void conditions1(t_list *stack, t_list *stack_2, char *c)
{
	if (ft_strcmp(c, "pa\n") == 0)
		push(stack_2, stack);
	else if (ft_strcmp(c, "pb\n") == 0)
		push(stack, stack_2);
	else if (ft_strcmp(c, "sa\n") == 0)
		swap(stack);
	else if (ft_strcmp(c, "sb\n") == 0)
		swap(stack_2);
	else if (ft_strcmp(c, "ss\n") == 0)
	{
		swap(stack);
		swap(stack_2);
	}
}

void conditions2(t_list *stack, t_list *stack_2, char *c)
{
	if (ft_strcmp(c, "ra\n") == 0)
		rotate(stack);
	else if (ft_strcmp(c, "rb\n") == 0)
		rotate(stack_2);
	else if (ft_strcmp(c, "rr\n") == 0)
	{
		rotate(stack);
		rotate(stack_2);
	}
	else if (ft_strcmp(c, "rra\n") == 0)
		reverse_rotate(stack);
	else if (ft_strcmp(c, "rrb\n") == 0)
		reverse_rotate(stack_2);
	else if (ft_strcmp(c, "rrr\n") == 0)
	{
		reverse_rotate(stack);
		reverse_rotate(stack_2);
	}
}

int	check(t_list *stack)
{
	t_nodo	*ptr;
	int		i;

	ptr = stack->cabeza;
	i = 1;
	while (ptr != NULL)
	{
		if (ptr->pos != i)
			return (0);
		ptr = ptr->next;
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list *stack;
	t_list *stack_2;
	char *c;
 
//	int n = 
	push_swap(argc, argv);
//	if (n != 0)
//		return (0);
	stack = malloc(sizeof(t_list));
	printf("esta aqui\n");
	stack_2 = malloc(sizeof(t_list));
	makestack(stack, argc, argv);
	c = malloc(sizeof(char) * 5);
	c = get_next_line(1);
	printf("c = %s\n,", c); // BORRAR
/*	int i = 0;
	while (c != NULL)
	{
//		printf("%s", c); // BORRAR
		conditions1(stack, stack_2, c);
		conditions2(stack, stack_2, c);
		c = get_next_line(1);
		printf("%d ,", i); // BORRAR
		i++;
	}
//	print2stack(stack, stack_2);
	if (check(stack) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
*/	return (0);
}

/*
int main(int argc, char **argv)
{
	push_swap(argc, argv);
	checker(argc, argv);
	return (0);
}
*/
