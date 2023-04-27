#include"push_swap.h"

void	instructions(t_stack *stack, int argc, char **argv)
{
	int i;
	i = 0;
	argc--;
	while (argc > 0)
	{
		stack[i] = ft_atoi(argv[argc]);
		i++;
		argc-;
	}
}

void	push(t_stack *stack, t_stack *stack_2)
{
	int i;
	int j;

	i = last_num(stack);
	j = last_num(stack_2);
	stack_2[j + 1]->n = stack[i]->n;
	stack_2[j + 1]->o = stack[i]->o;
	stack[i]->n = 0;
	stack[i]->o = 0;
}

void	swap(t_stack *stack)
{
	int i;
	int tmp_n;
	int tmp_o;

	i = last_num(stack);
	tmp_n = stack[i]->n;
	tmp_o = stack[i]->o;
	stack[i]->n = stack[i - 1]->n;
	stack[i]->o = stack[i - 1]->o;
	stack[i - 1]->n = tmp_n;
	stack[i - 1]->o = tmp_o;
}

void	rotate(t_stack *stack)
{
	int i;
	int tmp_n;
	int tmp_o;

	i = last_num(stack);
	tmp_n = stack[i]->n;
	tmp_o = stack[i]->o;
	while (stack[i - 1]->n)
	{
		stack[i]->n = stack[i - 1]->n;
		stack[i]->o = stack[i - 1]->o;
		i--;
	}
	stack[1]->n = tmp_n;
	stack[1]->o = tmp_o;
}

void	reverse_rotate(t_stack *stack)
{
	int i;
	int tmp_n;
	int tmp_o;

	i = 0;
	tmp_n = stack[1]->n;
	tmp_o = stack[1]->o;
	while (stack[i + 1]->n)
	{
		stack[i]->n = stack[i + 1]->n;
		stack[i]->o = stack[i + 1]->o;
		i++;
	}
	stack[i + 1]->n = tmp_n;
	stack[i + 1]->o = tmp_o;
}

int		last_num(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack[i]->n)
		i++;
	i--;
	return (i);
}
