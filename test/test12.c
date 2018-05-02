#include "utilities.h"

int main()
{
	int i = 0;
	void *addr[1000];

	while (i < 1000)
	{
		addr[i] = malloc((i + 1) * 10 * 10);
		i++;
	}
	//i = 800;
	view_area();
	while (i > -1)
	{
		ft_putstr("turn ....\n");
		free(addr[i]);
		i--;
	}
	show_alloc_mem();
	return (0);
}
