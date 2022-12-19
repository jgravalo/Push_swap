#include<unistd.h>
#include<fcntl.h>

void ft_putnbr(int n, int fd)
{
	char c;
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr(n * -1, fd);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
	}
	c = n % 10 + 48;
	write(fd, &c, 1);
}

int main()
{
	int fd = open("problems2", O_WRONLY);
	int i;
	int j = 100;

	write(fd, "./a.out ", 8);
	for (i = 50; i > 0; i--)
	{
		j -= 5; 
		ft_putnbr(j, fd);
		write(fd, " ", 1);
		j += 2; 
		ft_putnbr(j, fd);
		write(fd, " ", 1);
	}
	return (0);
}
