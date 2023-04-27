#include"../inc/push_swap.h"

/*argc = 8*/

int count_moves(int argc)
{
	int		i;
	int		res;

	i = argc / 2; // i = 4
	res = 0;
	if (argc % 2 == 1)
		res = i + 1; // res = 5
//	printf("res = %d\n", res);
	while (i > 0)
	{
		res = res + i * 2; // res = 5 + 4 * 2 + 3 * 2 + 2 * 2 + 1 * 2
//	printf("res = %d\n", res);
		// res = 5 + 8 + 6 + 4 + 2 = 25
		i--;
	}
	res = res + argc; // res = 25 + 9 = 34
//	printf("res = %d\n", res);
	return (res);
}

int main(int argc, char **argv)
{
	push_swap(argc, argv);
//	int argc = 500;
//	printf("moves = %d\n", count_moves(argc - 1));
	return (0);
}
