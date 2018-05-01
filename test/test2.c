#include "utilities.h"
#include "ft_display.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		//show_alloc_mem();
		//ft_putstr("\nTurn ");
		//ft_putnbr(i);
		addr = (char *)malloc(1024);
		//show_alloc_mem();
		addr[0] = 42;
		//ft_putstr("Before free\n");
		free(addr);
		//show_alloc_mem();
		i++;
	}
	//show_alloc_mem();
	return (0);
}
