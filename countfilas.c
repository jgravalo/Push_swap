#include"push_swap.h"
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	char *buff;
	int i, count;

	push_swap(argc, argv);
	buff = malloc(sizeof(char) * 100);
	read(1, buff, 100);
	count = 0;
	for (i = 0; buff[i]; i++)
		if (buff[i] == '\n')
			count++;
	printf("count = %d", count);
	return (0);
}
