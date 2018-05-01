#include "utilities.h"

int main()
{
	int i = 0;
	void *addr[100];

	while (i < 100)
	{
		addr[i] = malloc(1024);
		i++;
	}
	while (i > 50)
	{
		free(addr[i]);
		i--;
	}
	show_alloc_mem();
	desalocator_useless_mem();
	desalocator_useless_mem();
	while (i < 100)
	{
		addr[i] = malloc(1024);
		i++;
        }
	desalocator_useless_mem();
        while (i > 50)
        {
                free(addr[i]);
                i--;
        }
        while (i < 100)
        {
                addr[i] = malloc(100);
                i++;
        }
	desalocator_useless_mem();
	desalocator_useless_mem();
	show_alloc_mem();
	return (0);
}
