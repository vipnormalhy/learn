#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *p[5];
	size_t size;
	int i;

	size = sizeof(p) / sizeof(char *);
	memset(&p[0], 0, size);

	printf("size = %zu\n", size);
	for (i = 0; i < size; i++)
	{
		printf("%s\n", *(p+i));
	}

	sleep(30);
	printf("malloc once\n");
	for (i = 0; i < size; i++)
	{
		*(p+i) = (char *)malloc(sizeof(char*) * 100000);
	}
	sleep(10);

	printf("malloc twice without free\n");
	for (i = 0; i < size; i++)
	{
		*(p+i) = (char *)malloc(sizeof(char*) * 100000);
	}
	sleep(20);

	return 1;
}
