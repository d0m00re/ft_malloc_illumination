#include "utilities.h"
#include <unistd.h>

#define M (1024*1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr;

	addr = (char *)malloc(16);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Yo man\n");
	return (0);
}
