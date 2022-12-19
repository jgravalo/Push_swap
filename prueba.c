#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void ft_putnbr(int n, int fd)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}

/*n = 100*/

void	print_num(char *num, int par, int fd)
{
	int i;

	i = atoi(num);//i = 100
	if (i % 2 == par)// if 100%2 = 0
		i--;//i == 99
	while (i > 0)
	{
		ft_putnbr(i, fd); 
		write(fd, " ", 1);
		i -= 2;
	}
}

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (0);
//	fd = 1;
	fd = open("test", O_WRONLY);
	write(fd, "./a.out ", 8);
	print_num(argv[1], 0, fd);
	print_num(argv[1], 1, fd);
	return (0);
}
