#include "utilities.h"
#include "ft_display.h"

int main()
{
	int i;
	char *addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char *)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	view_area();
	//show_alloc_mem();
	desalocator_useless_mem();
	return (0);
}
