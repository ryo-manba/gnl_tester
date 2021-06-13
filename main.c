#include "get_next_line.h"
#include <stdio.h>

#define TXT1 "a1.txt"
#define TXT2 "a2.txt"
#define TXT3 "a3.txt"
#define TXT4 "a4.txt"

int main(int ac, char **av)
{
	int		fd;
	int		return_value;
	char	*line;

	if (ac == 1)
	{
		printf("Please select number! (1 ~ 5)\n");
		return (0);
	}

	if (*av[1] == '1')
		fd = open(TXT1, O_RDONLY);
	if (*av[1] == '2')
		fd = open(TXT2, O_RDONLY);
	if (*av[1] == '3')
		fd = open(TXT3, O_RDONLY);
	if (*av[1] == '4')
		fd = open(TXT4, O_RDONLY);
	if (*av[1] == '5')
		fd = -1;

	return_value = get_next_line(fd, &line);
	while (return_value == 1)
	{
		printf("line = %s\n", line);
		printf("return_value = %d\n\n", return_value);
		free(line);
		return_value = get_next_line(fd, &line);
	}
	printf("line = %s\n", line);
	printf("return_value = %d\n", return_value);
	system("leaks a.out");
	close(fd);
	return (0);
}
