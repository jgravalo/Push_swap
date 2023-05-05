#include"../inc/push_swap.h"
#include"../inc/checker.h"
#include<string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
//	printf("s1 = %ss2 = %s", s1, s2); // BORRAR
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
	{
//		printf("s1 = %c[%d]s2 = %c[%d]\n", s1[i], i, s2[i], i); // BORRAR
//		printf("aqui\n");
		i++;
	}
//	printf("s1 = %c[%d]s2 = %c[%d]\n", s1[i], i, s2[i], i); // BORRAR
//	printf("res = %d\n\n", s1[i] - s2[i]); // BORRAR
//	if (s1[i] - s2[i] == 0)
//		printf("s1 = %ss2 = %s", s1, s2); // BORRAR
	return (s2[i] - s1[i]);
}
void conditions1(t_list *stack, t_list *stack_2, char *c)
{
//	printf("c = %s\n", c); // BORRAR
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
//	printf("c = %s\n", c); // BORRAR
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
		{
			write(1, "KO\n", 3);
			exit(-1);
		}
		ptr = ptr->next;
		i++;
	}
	write(1, "OK\n", 3);
	exit(0);
}

int main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*stack_2;
	t_move	*ptr;
 
	stack = malloc(sizeof(t_list));
	stack_2 = malloc(sizeof(t_list));
	makestack(stack, argc, argv);
	stack->cadena = push_swap(argc, argv);
//	print_2stack(stack, stack_2);// BORRAR
//	print_moves(stack->cadena);
	ptr = stack->cadena;
	while (ptr != NULL)
	{
//		printf("\nc = %s", ptr->move); // BORRAR
		conditions1(stack, stack_2, ptr->move);
		conditions2(stack, stack_2, ptr->move);
//		print_2stack(stack, stack_2);// BORRAR
		ptr = ptr->next;
	}
//	print_2stack(stack, stack_2);// BORRAR
	check(stack);
	return (0);
}
