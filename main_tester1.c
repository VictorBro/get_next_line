#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd = open("alphabet.txt", O_RDONLY);
	char *str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	printf("\n");
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	printf("\n");
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
}

