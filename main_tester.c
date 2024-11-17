#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int	fd = open("alphabet.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	int fd1 = open("test.txt", O_RDONLY);
	char *str1 = get_next_line(fd1);
	printf("%s", str1);
	char *str2 = get_next_line(fd);
	printf("%s", str2);
	char *str3 = get_next_line(fd1);
	printf("%s", str3);
	free(str);
	free(str1);
	free(str2);
	free(str3);
	close(fd);
	close(fd1);
}

