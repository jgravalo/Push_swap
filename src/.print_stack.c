#include"../inc/push_swap.h"

void    print_stack(t_list *stack)
{
    t_nodo  *ptr;
    ptr = stack->cabeza;
    while (ptr)
    {
        printf(", %d(%d)", ptr->num, ptr->pos);
        ptr = ptr->next;
    }
}

void    print_2stack(t_list *stack, t_list *stack_2)
{
    print_stack(stack);
    printf(" // ");
    print_stack(stack_2);
    printf("\n");
}

void    print_points(t_list *stack)
{
	int i;
	t_nodo *ptr = stack->cabeza;
	while (ptr)
	{
		printf("pos = %d  ", ptr->pos);
		if (ptr->pos < 10)
			printf(" ");
		for (i = 0; i < ptr->pos; i++)
			printf(".");
		printf("\n");
		ptr = ptr->next;
	}
}
